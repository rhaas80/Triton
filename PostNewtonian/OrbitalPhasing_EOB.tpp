/// The following template is the general structure containing the EOB Hamilton equations
/// y[0] = r
/// y[1] = Phi
/// y[2] = prstar
/// y[3] = pPhi
template <class Metric, class Hamiltonian, class Torque>
class EOBHamiltonEquations {
private:
  const Metric& g;
  const Hamiltonian& H;
  const Torque& T;
public:
  EOBHamiltonEquations(const Metric& ig, const Hamiltonian& iH, const Torque& iT) : g(ig), H(iH), T(iT) { }
  void operator()(const double t, const std::vector<double>& y, std::vector<double>& dydt) const {
    /// Refresh the Metric, Hamiltonian, and Torque objects
    g(y[0]);
    H(y[0], y[2], y[3]);
    T(H.v, y[0], y[2], y[3]); /// (v, r, prstar, pPhi)
    
    /// Eqs. (10) of Pan et al., 2011:
    dydt[0] = g.drdrstar * H.dHdprstar;
    dydt[1] = H.dHdpPhi;
    dydt[2] = -g.drdrstar * H.dHdr + (T.Torque * y[2] / y[3]);
    dydt[3] = T.Torque;
  }
  bool ContinueIntegratingEarly(const double& t, const std::vector<double>& y, const std::vector<double>& dydt) const {
    return (y[0]>15.0); /// Ensures that r>15
  }
  bool ContinueIntegrating(const double& t, const std::vector<double>& y, const std::vector<double>& dydt) const {
    return (y[0]>1.5 && y[2]<0.0); /// Ensures that r>1.5 and prstar<0
  }
};


template <class Metric, class Hamiltonian, class HamiltonEquations>
std::vector<double> ReduceEccentricity(const Metric& g, const Hamiltonian& H, const HamiltonEquations& d,
				  const std::vector<double>& ystartGuess, const double AcceptableEcc, const double& v0);


template <class Hamiltonian, class HamiltonEquations>
void EOBIntegration(const Hamiltonian& H, HamiltonEquations& d, std::vector<double>& y0,
		    const double tLength, const double rtol, const double h1, const int nsave, const bool denseish,
		    std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
		    std::vector<double>& r, std::vector<double>& prstar, std::vector<double>& pPhi);


template <class Metric, class Hamiltonian, class Torque>
void EOB(const Metric& g, const Hamiltonian& H, const Torque& T,
	 const double delta, const double chis, const double chia, const double v0,
	 std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
	 std::vector<double>& r, std::vector<double>& prstar, std::vector<double>& pPhi,
	 const int nsave, const bool denseish, const double rtol)
{
  clock_t start,end;
  
  /// Construct the physics object
  EOBHamiltonEquations<Metric, Hamiltonian, Torque> d(g, H, T);
  
  /// Guess some parameters
  const double nu = (1.0-delta*delta)/4.0;
  const double GuessedLength = 1.1 * 5.0/(256.0*nu*pow(v0,8));
  const double AcceptableEcc=1e-12;
  const double r0 = 1.0/(v0*v0);
  const double h1=10*(2.0*M_PI/(v0*v0*v0))/4.0;
  
  /// Set up initial conditions
  std::vector<double> ystart(4, 0.0);
  g(r0);
  ystart[0] = r0;
  ystart[1] = 0.0;
  ystart[3] = r0*sqrt((r0*g.dDtdr - 2*g.Dt)/(-r0*g.dDtdr + 4*g.Dt));
  H(r0, 0.0, ystart[3]);
  T(v0, r0, 0.0, ystart[3]);
  const double dpPhi0dr = (-8*pow(g.Dt,2) + 7*g.dDtdr*g.Dt*r0 - 2*pow(g.dDtdr,2)*pow(r0,2))/(pow(4*g.Dt - g.dDtdr*r0,1.5)*sqrt(-2*g.Dt + g.dDtdr*r0));
  ystart[2] = nu * g.drstardr * T.Torque / dpPhi0dr;
  if(ystart[2]>0.0) ystart[2] *= -1;
  
  //// If spin is too large, build up to the goal gradually, reducing eccentricity at each step
  std::vector<double> chisMax(10);
  chisMax[0] = 0.1; chisMax[1] = 0.2; chisMax[2] = 0.3; chisMax[3] = 0.4; chisMax[4] = 0.45; chisMax[5] = 0.5; chisMax[6] = 0.6; chisMax[7] = 0.7; chisMax[8] = 0.8; chisMax[9] = 0.9;
  for(unsigned int i=0; i<chisMax.size(); ++i) {
    const double chismax = chisMax[i];
    if(fabs(chis)>chismax) {
      double chisloc = (chis>0 ? chismax : -chismax);
      //std::cout << "Reducing eccentricity with chis=" << chisloc << " ... " << std::flush;
      Metric g(delta, chisloc, chia);
      Hamiltonian H(delta, chisloc, chia, g);
      Hamiltonian Hcirc(delta, chisloc, chia, g);
      typename Torque::FluxType F(delta, chisloc); /// TODO: Fix this line to work with general Flux types
      Torque T(delta, chisloc, F, Hcirc);
      EOBHamiltonEquations<Metric, Hamiltonian, Torque> d(g, H, T);
      ystart = ReduceEccentricity(g, H, d, ystart, 1.e-8, v0);
    }
  }
  
  //// Now reduce eccentricity with the real parameters
  //std::cout << "Reducing eccentricity ... " << std::flush;
  start = clock();
  ystart = ReduceEccentricity(g, H, d, ystart, AcceptableEcc, v0);
  end = clock();
  std::cout << "\nEccentricity reduction took " << std::setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds." << std::flush;
  
  start = clock();
  EOBIntegration(H, d, ystart, GuessedLength, rtol, h1, nsave, denseish, t, v, Phi, r, prstar, pPhi);
  end = clock();
  std::cout << "\tEOBIntegration took " << std::setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds." << std::endl;
  
  return;
}


template <class Hamiltonian, class HamiltonEquations>
void EOBIntegration(const Hamiltonian& H, HamiltonEquations& d,
		    std::vector<double>& y0, const double tLength, const double rtol, const double h1, const int nsave, const bool denseish,
		    std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
		    std::vector<double>& r, std::vector<double>& prstar, std::vector<double>& pPhi)
{
  const double atol = 0.0;
  const double t0 = 0.0, t1 = tLength;
  const double hmin=1.0e-2;
  Output out(nsave);
  
  /// First pass, integrating until tLength or the 'Early' integration test fails
  Odeint<StepperBS<HamiltonEquations> > odeA(y0, t0, t1, atol, rtol, h1, hmin, out, d, denseish, &HamiltonEquations::ContinueIntegratingEarly);
  try {
    odeA.integrate();
  } catch(NRerror err) { }
  
  /// Second pass, only if 'Early' integration test failed
  {
    const double t0B = out.xsave[out.count-1];
    std::vector<double> dydt(out.ysave.nrows());
    d(t0B, y0, dydt);
    if(! d.ContinueIntegratingEarly(t0B, y0, dydt) ) {
      --out.count;
      const double h1 = MIN(nsave*(out.xsave[out.count-1]-out.xsave[out.count-2])/1.0, (t1-t0B)/100.0);
      Odeint<StepperDopr853<HamiltonEquations> > odeB(y0, t0B, t1, atol, rtol, h1, hmin, out, d, denseish, &HamiltonEquations::ContinueIntegrating);
      try {
	odeB.integrate();
      } catch(NRerror err) { }
    }
  }
  
  /// Save the results
  out.xsave.resize(out.count);
  t.swap(out.xsave);
  out.ysave.resize(out.ysave.nrows(), out.count);
  r.swap(out.ysave[0]);
  Phi.swap(out.ysave[1]);
  prstar.swap(out.ysave[2]);
  pPhi.swap(out.ysave[3]);
  v.resize(out.count);
  for (int i=0;i<out.count;i++) {
    H(r[i], prstar[i], pPhi[i]);
    v[i] = H.v;
  }
  t -= t.back();
  
  return;
}






//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//// Eccentricity measurement and removal
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
class Eccentricity_rDotFit {
public:
  Eccentricity_rDotFit() { }
  void operator()(const Doub x, VecDoub_I &a, Doub &y, VecDoub_O &dyda) const {
    //// Model: y(x) =  a0 + a1*x + a2*cos(a3*x+a4);
    y = a[0] + a[1]*x + a[2]*cos(a[3]*x+a[4]);
    dyda[0] = 1.0;
    dyda[1] = x;
    dyda[2] = cos(a[3]*x+a[4]);
    dyda[3] = -a[2]*sin(a[3]*x+a[4])*x;
    dyda[4] = -a[2]*sin(a[3]*x+a[4]);
    return;
  }
};
class Eccentricity_rDotDotFit {
public:
  Eccentricity_rDotDotFit() { }
  void operator()(const double x, const std::vector<double> &a, double &y, std::vector<double> &dyda) const {
    //// Model: y(x) =  -a0*sin(a1*x+a2);
    y = -a[0]*sin(a[1]*x+a[2]);
    dyda[0] = -sin(a[1]*x+a[2]);
    dyda[1] = -a[0]*cos(a[1]*x+a[2])*x;
    dyda[2] = -a[0]*cos(a[1]*x+a[2]);
    return;
  }
};
double Eccentricity_rDot(const std::vector<double>& t, const std::vector<double>& rDot, const double r0, const double Omega0, double& DeltarDot, double& DeltaPhiDot) {
  //// Do the fit to the model:
  ////   rDot(t) = vbar0 + arbar0*t + Br*cos(omegar*t+phir)
  
  //// First fit to rDotDot to find phase, frequency, and amplitude
  std::vector<double> rDotDot = dydx(rDot, t);
  std::vector<double> aDotDotGuesses(3);
  aDotDotGuesses[0] = 0.5*(max(rDotDot)-min(rDotDot));
  aDotDotGuesses[1] = Omega0;
  aDotDotGuesses[2] = 0.0;
  std::vector<double> rDotDotMinusAvg = rDotDot-avg(rDotDot);
  std::vector<double> TrivialSigmas(t.size(), 1.0);
  Eccentricity_rDotDotFit e_dd;
  FitNonlinear<Eccentricity_rDotDotFit> rDotDotFit(t, rDotDotMinusAvg, TrivialSigmas, aDotDotGuesses, e_dd, 1.e-8);
  rDotDotFit.hold(0, aDotDotGuesses[0]);
  rDotDotFit.hold(1, aDotDotGuesses[1]);
  rDotDotFit.fit();
  rDotDotFit.free(1);
  rDotDotFit.fit();
  rDotDotFit.free(0);
  rDotDotFit.fit();
  
  //// Next fit to rDot to find all parameters
  std::vector<double> aDotGuesses(5);
  aDotGuesses[0] = avg(rDot);
  aDotGuesses[1] = avg(rDotDot);
  aDotGuesses[2] = rDotDotFit.a[0] / rDotDotFit.a[1];
  aDotGuesses[3] = rDotDotFit.a[1];
  aDotGuesses[4] = rDotDotFit.a[2];
  Eccentricity_rDotFit e_d;
  FitNonlinear<Eccentricity_rDotFit> rDotFit(t, rDot, TrivialSigmas, aDotGuesses, e_d, 1.e-8);
  rDotFit.fit();
  
  //// Adjust the parameters
  //double& vbar0 = rDotFit.a[0];
  //double& arbar0 = rDotFit.a[1];
  double& Br = rDotFit.a[2];
  double& omegar = rDotFit.a[3];
  double& phir = rDotFit.a[4];
  DeltarDot = -Br * cos(phir); // Eq. (71) of arXiv:1012.1549
  DeltaPhiDot = Br * omegar * sin(phir) / (2* r0 * Omega0);  // Eq. (73) of arXiv:1012.1549
  
  //// Return the measured eccentricity
  return -Br / (r0 * omegar);
}
template <class Metric, class Hamiltonian, class HamiltonEquations>
std::vector<double> ReduceEccentricity(const Metric& g, const Hamiltonian& H, const HamiltonEquations& d,
				  const std::vector<double>& ystartGuess, const double AcceptableEcc, const double& v0)
{
  const unsigned int NMaxIterations=1000;
  const double Omega0 = v0*v0*v0;
  const double r0 = 1.0/(v0*v0);
  const double rtol=1.0e-11, GuessedLength=2*(2.0*M_PI/Omega0);
  const int nsave=1000;
  const bool denseish=false;
  const double h1=2*(2.0*M_PI/Omega0)/double(nsave);
  std::vector<double> ystart(ystartGuess);
  std::vector<double> ystartinitial(ystart);
  std::vector<double> Bestystart(ystart);
  std::vector<double> t, Phi, v, r, prstar, pPhi;
  
  //// Reduce eccentricity
  double BestEcc=1.e100;
  //// Iterations of arXiv:1012.1549's method
  for(unsigned int i=0; i<NMaxIterations; ++i) {
    double DeltarDot=666, DeltaPhiDot=-666;
    EOBIntegration(H, d, ystart, GuessedLength, rtol, h1, nsave, denseish, t, v, Phi, r, prstar, pPhi);
    g(ystartinitial[0]);
    H(ystartinitial[0], ystartinitial[2], ystartinitial[3]);
    double Ecc = Eccentricity_rDot(t, prstar, ystartinitial[0], H.dHdpPhi, DeltarDot, DeltaPhiDot);
    
    if(i==0) {
      BestEcc = Ecc;
    } else {
      if(fabs(Ecc)<fabs(BestEcc)) {
	BestEcc = Ecc;
	Bestystart = ystartinitial;
      }
    }
    if(fabs(BestEcc)<AcceptableEcc) {
      //std::cout << "Achieved acceptable eccentricity of e=" << std::setprecision(14) << BestEcc << " in " << i << " iterations." << std::endl;
      return Bestystart;
    }
    ystart = ystartinitial;
    double Multiplier(0.95);
    if(fabs(Ecc)<1e-10) { Multiplier = 0.05; }
    if(fabs(Ecc)<1e-12) { Multiplier = 0.01; }
    ystart[2] += Multiplier*g.drdrstar * DeltarDot;
    ystart[3] += Multiplier*r0*r0 * DeltaPhiDot;
    ystartinitial = ystart;
    //std::cout << "i: " << i << "\tEcc: " << Ecc << std::endl;
  }
  std::cerr << "!!! Did not achieve acceptable eccentricity reduction !!!" << std::endl
	    << "Proceeding anyway, with e=" << BestEcc << "." << std::endl;
  
  return Bestystart;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
