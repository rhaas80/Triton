#include "NumericalRecipes.hpp"

#include "Waveforms.hpp"

#include <ctime>
#include <unistd.h>
#include <sys/param.h>

//#include <fstream>
//using std::ofstream;

#include "VectorFunctions.hpp"
#include "EasyParser.hpp"
#include "Fit.hpp"
#include "Interpolate.hpp"

using namespace WaveformUtilities;
using namespace WaveformObjects;
using std::string;
using std::vector;
using std::setprecision;
using std::cerr;
using std::cout;
using std::endl;
using std::ios_base;


// Constructors

/// Basic copy constructor.
WaveformObjects::Waveforms::Waveforms(const Waveforms& In) :
  history(In.history.str()), Ws(In.Ws), CommonTimeSet(In.CommonTimeSet), PhasesAligned(In.PhasesAligned)
{
  history.seekp(0, ios_base::end);
}

/// Nearly-empty constructor of N empty objects.
WaveformObjects::Waveforms::Waveforms(const int N) :
  history("### Waveforms(); // empty constructor\n"),
  Ws(N), CommonTimeSet(false), PhasesAligned(false)
{
  history.seekp(0, ios_base::end);
}

/// Construct from a vector of radii and corresponding data file names.
WaveformObjects::Waveforms::Waveforms(const std::vector<double>& Radii, const std::string& DataFile,
				      const std::string& AreaFile, const std::string& LapseFile,
				      const double& ADMMass, const double& ChMass, const bool ZeroEnds) :
  history(""), Ws(Radii.size()), CommonTimeSet(false), PhasesAligned(false)
{
  /// This constructor is used for extrapolation, primarily.  The
  /// various file names are expected to be printf-formatted strings,
  /// where each radius is the quantity used in the printf statement.
  /// Thus, for example, '(100, 110, ...)' and
  /// 'rPsi4_R%04.0fm_U8+.dat' may be input, where the file names are
  /// 'rPsi4_R0100m_U8+.dat', 'rPsi4_R0110m_U8+.dat', etc.  The input
  /// AreaFile and LapseFile are treated similarly.
  
  //cout << "Calling Waveforms(Radii, ...)" << endl;
  
  // Record the construction of this object
  {
    char path[MAXPATHLEN];
    getcwd(path, MAXPATHLEN);
    string pwd = path;
    char host[MAXHOSTNAMELEN];
    gethostname(host, MAXHOSTNAMELEN);
    string hostname = host;
    time_t rawtime;
    time ( &rawtime );
    string date = asctime ( localtime ( &rawtime ) );
    history << "### Code revision `git rev-parse HEAD` = " << GitRevision << endl
	    << "### pwd = " << pwd << endl
	    << "### hostname = " << hostname << endl
	    << "### date = " << date // comes with a newline
	    << "### Waveforms(" << RowFormat(Radii) << ", "
	    << DataFile << ", "
	    << AreaFile << ", "
	    << LapseFile << ", "
	    << ADMMass << ", "
	    << ChMass << ", "
	    << ZeroEnds << ");" << endl;
  }
  
  // Read the data into the Waveform objects, and adjust the time appropriately
  int BufferSize = 5000;
  for(unsigned int i=0; i<Radii.size(); ++i) { // Loop over Radii
    char DataFileName[BufferSize], AreaFileName[BufferSize], LapseFileName[BufferSize];
    sprintf(DataFileName,  DataFile.c_str(),  Radii[i]);
    sprintf(AreaFileName,  AreaFile.c_str(),  Radii[i]);
    sprintf(LapseFileName, LapseFile.c_str(), Radii[i]);
    cout << "Reading " << DataFileName << ", " << AreaFileName << ", and " << LapseFileName << "." << endl;
    Ws[i] = Waveform(DataFileName, "ReIm", ZeroEnds);
    Ws[i].SetArealRadius(AreaFileName);
    Ws[i].RescaleMagForRadius(Radii[i]*ChMass);
    Ws[i].SetTimeFromLapseSurfaceIntegral(LapseFileName, ADMMass);
    Ws[i].TortoiseRetard(ADMMass);
    if(ChMass != 1.0) { Ws[i].SetTotalMassToOne(ChMass); }
    cout << "\tRead " << Ws[i].NModes() << " components and " << Ws[i].NTimes() << " time steps." << endl;
  }
}


/// Construct Waveforms from multiple [*-data] .bbh sections.
WaveformObjects::Waveforms::Waveforms(const std::string& BBHFileName,
				      const WaveformUtilities::Matrix<int> LM) :
  history(""), Ws(0), CommonTimeSet(false), PhasesAligned(false)
{
  //cout << "Calling Waveforms(const std::string& BBHFileName, ...)" << endl;
  
  // Record the construction of this object
  {
    char path[MAXPATHLEN];
    getcwd(path, MAXPATHLEN);
    string pwd = path;
    char host[MAXHOSTNAMELEN];
    gethostname(host, MAXHOSTNAMELEN);
    string hostname = host;
    time_t rawtime;
    time ( &rawtime );
    string date = asctime ( localtime ( &rawtime ) );
    history << "### Code revision `git rev-parse HEAD` = " << GitRevision << endl
	    << "### pwd = " << pwd << endl
	    << "### hostname = " << hostname << endl
	    << "### date = " << date // comes with a newline
	    << "### Waveforms(" << BBHFileName << ", " << RowFormat(LM) << ");" << endl;
  }
  
  // Loop through the .bbh file getting the various DataSections
  vector<vector<string> > BBHDataSections;
  vector<string> Dirs;
  
  
  // Construct the vector, and read data into each element
  Ws = vector<Waveform>(BBHDataSections.size());
  for(unsigned int i=0; i<Ws.size(); ++i) {
    Ws[i] = Waveform(BBHDataSections[i], Dirs[i], LM.RawData());
  }
}

/// Construct Waveforms from a single [*-data] .bbh section.
WaveformObjects::Waveforms::Waveforms(const std::vector<std::string>& BBHDataSection,
				      const std::string Dir,
				      const WaveformUtilities::Matrix<int> LM) :
  history(""), Ws(0), CommonTimeSet(false), PhasesAligned(false)
{
  //cout << "Calling Waveforms(const std::vector<std::string>& BBHDataSection, ...)" << endl;
  
  /// The resulting set of Waveforms really represents just one
  /// Waveform, but each mode can have different times.  The modes can
  /// be re-assembled into a single Waveform by calling the Merge()
  /// method.  That is probably the most useful format.  This
  /// constructor and Merge() are called by the Waveform::Waveform
  /// constructor having the same arguments as this function.
  
  // Record the construction of this object
  {
    char path[MAXPATHLEN];
    getcwd(path, MAXPATHLEN);
    string pwd = path;
    char host[MAXHOSTNAMELEN];
    gethostname(host, MAXHOSTNAMELEN);
    string hostname = host;
    time_t rawtime;
    time ( &rawtime );
    string date = asctime ( localtime ( &rawtime ) );
    history << "### Code revision `git rev-parse HEAD` = " << GitRevision << endl
	    << "### pwd = " << pwd << endl
	    << "### hostname = " << hostname << endl
	    << "### date = " << date // comes with a newline
	    << "### Waveforms(\"\"\"" << endl;
    for(unsigned int i=0; i<BBHDataSection.size(); ++i) {
      history << "###              " << BBHDataSection[i] << endl;
    }
    history << "###           \"\"\"," << endl
	    << "###           " << Dir << ", " << RowFormat(LM) << ");" << endl;
  }
  
  // Figure out the format and data type
  unsigned int WaveformTypeIndex = 11;
  std::vector<std::vector<int> > WaveformLMs(0, std::vector<int>(2));
  std::vector<std::string> FileNames(0);
  unsigned int i=0;
  std::string Format;
  while(i<BBHDataSection.size()) {
    string TrimmedLine = TrimWhiteSpace(StripComments(BBHDataSection[i]));
    if(TrimmedLine.compare("[ht-data]") == 0) {
      WaveformTypeIndex = 11;
      Format = "ReIm";
      break;
    } else if(TrimmedLine.compare("[psi4t-data]") == 0) {
      WaveformTypeIndex = 9;
      Format = "ReIm";
      break;
    } else if(TrimmedLine.compare("[ht-ampphi-data]") == 0) {
      WaveformTypeIndex = 11;
      Format = "MagArg";
      break;
    } else if(TrimmedLine.compare("[psi4t-ampphi-data]") == 0) {
      WaveformTypeIndex = 9;
      Format = "MagArg";
      break;
    }
    ++i;
  }
  ++i;
  
  // Loop through following lines getting data
  string DataFileName = "";
  std::vector<std::vector<double> > Times(0);
  std::vector<std::vector<double> > Re(0);
  std::vector<std::vector<double> > Im(0);
  std::vector<int> LandM(2);
  std::vector<string> Pair(2,"");
  std::vector<string> LandMString(2,"");
  string Line="";
  while(i<BBHDataSection.size()) {
    // Parse this line
    string LineCharsStripped = TrimWhiteSpace(StripComments(BBHDataSection[i]));
    if(LineCharsStripped.length()==0) { ++i; continue; } // skip empty lines
    if(LineCharsStripped.find("-data]")!=string::npos) { break; } // end if we've reached another [*-data] section
    Pair = split(Line.assign(LineCharsStripped), '=');
    if(Pair[0].find("extraction-radius")!=string::npos) { ++i; continue; } // ignore extraction-radius line
    LandMString = split(Pair[0], ',');
    DataFileName = TrimWhiteSpace(Pair[1]);
    LandM[0] = atoi(LandMString[0].c_str());
    LandM[1] = atoi(LandMString[1].c_str());
    if(LM.nrows()==0) {
      WaveformLMs.push_back(LandM);
      FileNames.push_back(Dir+DataFileName);
    } else {
      for(unsigned int j=0; j<LM.nrows(); ++j) {
	if(LandM[0] == LM[j][0] && LandM[1] == LM[j][1]) {
	  WaveformLMs.push_back(LandM);
	  FileNames.push_back(Dir+DataFileName);
	  break;
	}
      }
    }
    ++i;
  }
  
  Ws = std::vector<Waveform>(WaveformLMs.size());
  for(unsigned int j=0; j<Ws.size(); ++j) {
    Ws[j] = Waveform(FileNames[j], Format);
    //Ws[j].TypeIndexRef() = WaveformTypeIndex;
    Ws[j].LMRef(0) = WaveformLMs[j];
  }
}


// Member functions

void WaveformObjects::Waveforms::SetCommonTime(const double& MinStep, const double& MinTime) {
  history << "### this->SetCommonTime(" << MinStep << ", " << MinTime << ");" << endl;
  std::vector<double> Time(Ws[0].T());
  // Get the intersection of all the time data
  for(unsigned int i=1; i<Ws.size(); ++i) {
    Time = Intersection(Time, Ws[i].T(), MinStep, MinTime);
  }
  // Interpolate each Waveform to the common time series
  for(unsigned int i=0; i<Ws.size(); ++i) {
    Ws[i].Interpolate(Time);
  }
  CommonTimeSet = true;
  return;
}

void WaveformObjects::Waveforms::FixNonOscillatingData() {
  history << "### this->FixNonOscillatingData();" << endl;
  // Step through each Waveform doing the work
  for(unsigned int i=0; i<Ws.size(); ++i) {
    Ws[i].FixNonOscillatingData();
  }
  return;
}

void WaveformObjects::Waveforms::AlignPhases(const double& AlignmentPoint) {
  history << "### this->AlignPhases(" << AlignmentPoint << ");" << endl;
  if(!CommonTimeSet) { SetCommonTime(); }
  int I = int(floor(AlignmentPoint * Ws[0].NTimes()));
  for(unsigned int i=1; i<Ws.size(); ++i) { // Loop over Waveforms
    for(unsigned int j=0; j<Ws[i].NModes(); ++j) { // Loop over components
      Ws[i].ArgRef(j) = Ws[i].Arg(j) + (2.0 * M_PI * round((Ws[i-1].Arg(j,I)-Ws[i].Arg(j,I))/(2.0*M_PI)));
    }
  }
  PhasesAligned = true;
  return;
}

void WaveformObjects::Waveforms::TortoiseAdvance(const double ADMMass, const bool ResetCommonTime) {
  history << "### this->TortoiseAdvance(" << ResetCommonTime << ");" << endl;
  for(unsigned int i=0; i<Ws.size(); ++i) {
    Ws[i].TortoiseAdvance(ADMMass);
  }
  CommonTimeSet = false;
  if(ResetCommonTime) {
    SetCommonTime();
  }
  return;
}

Waveform WaveformObjects::Waveforms::Extrapolate(const int ExtrapolationOrder, const bool UseSVD) {
  history << "### this->Extrapolate(" << ExtrapolationOrder << ", " << UseSVD << ");" << endl;
  
  if(!PhasesAligned) { AlignPhases(); }
  if(ExtrapolationOrder<0) { return Ws[Ws.size() + ExtrapolationOrder]; }
  Waveform Extrap = Ws[0];
  Extrap.SetHistory(history.str());
  Extrap.History() << "#### NOTE: This object is now a single Waveform (extrapolated from a 'Waveforms' object)." << endl;
  
  // Set up the important variables
  vector<double> oor(Ws.size(), 0.0);  // one over radii
  vector<double> amp(Ws.size(), 0.0);
  vector<double> phi(Ws.size(), 0.0);
  const vector<double> sig(Ws.size(), 1.0);  // These sigmas should never be less than 3e-6.
  PolynomialBasisFunctions Poly(ExtrapolationOrder);
  FitSVD<PolynomialBasisFunctions> ampFitSVD(oor, amp, sig, Poly);
  FitSVD<PolynomialBasisFunctions> phiFitSVD(oor, phi, sig, Poly);
  Fit<PolynomialBasisFunctions> ampFit(oor, amp, sig, Poly);
  Fit<PolynomialBasisFunctions> phiFit(oor, phi, sig, Poly);
  
  // Loop over time
  for(unsigned int i=0; i<Extrap.NTimes(); ++i) {
    if(i % 1000 == 0) {
      cout << "Time = " << setprecision(5) << Extrap.T(i) << "\tStep " << i << " of " << Extrap.NTimes() << endl;
    }
    
    //// Set the radii at this time
    for(unsigned int k=0; k<Ws.size(); ++k) {
      oor[k] = 1.0 / Ws[k].R(i);
    }
    
    //// Loop over components
    for(unsigned int j=0; j<Extrap.NModes(); ++j) {
      //// Fill vectors with data from various radii
      for(unsigned int k=0; k<Ws.size(); ++k) {
	amp[k] = Ws[k].Mag(j,i);
	phi[k] = Ws[k].Arg(j,i);
      }
      
      if(!UseSVD) {
	//// Fit to polynomial in 1/R
	ampFit.fit();
	phiFit.fit();
	
	//// Evaluate at 0 and set the relevant component of Extrap
	Extrap.MagRef(j,i) = ampFit.a[0];
	Extrap.ArgRef(j,i) = phiFit.a[0];
      } else {
	//// FitSVD to polynomial in 1/R
	ampFitSVD.fit();
	phiFitSVD.fit();
	
	//// Evaluate at 0 and set the relevant component of Extrap
	Extrap.MagRef(j,i) = ampFitSVD.a[0];
	Extrap.ArgRef(j,i) = phiFitSVD.a[0];
      }
    }
  }
  Extrap.RRef() = vector<double>(1, numeric_limits<double>::infinity( ) );
  
  Extrap.History() << "#### Extrapolation finished." << endl;
  
  return Extrap;
}

Waveform WaveformObjects::Waveforms::Extrapolate(Waveform& Sigmas, const int ExtrapolationOrder, const bool UseSVD) {
  history << "### this->Extrapolate(Sigmas, " << ExtrapolationOrder << ", " << UseSVD << ");" << endl;
  
  if(!PhasesAligned) { AlignPhases(); }
  if(ExtrapolationOrder<0) { return Ws[Ws.size() + ExtrapolationOrder]; }
  Waveform Extrap = Ws[0];
  Extrap.SetHistory(history.str());
  Sigmas = Extrap;
  Extrap.History() << "#### NOTE: This object is now a single Waveform (extrapolated from a 'Waveforms' object)." << endl;
  Sigmas.History() << "#### NOTE: This object contains the uncertainties in each part of each mode of the extrapolated object." << endl;
  
  // Set up the important variables
  vector<double> oor(Ws.size(), 0.0);  // one over radii
  vector<double> amp(Ws.size(), 0.0);
  vector<double> phi(Ws.size(), 0.0);
  vector<double> sig(Ws.size(), 1.0);  // These sigmas should never be less than 3e-6.
  PolynomialBasisFunctions Poly(ExtrapolationOrder);
  FitSVD<PolynomialBasisFunctions> ampFitSVD(oor, amp, sig, Poly);
  FitSVD<PolynomialBasisFunctions> phiFitSVD(oor, phi, sig, Poly);
  Fit<PolynomialBasisFunctions> ampFit(oor, amp, sig, Poly);
  Fit<PolynomialBasisFunctions> phiFit(oor, phi, sig, Poly);
  double DOF = Ws.size() - (ExtrapolationOrder+1);

// ofstream myfile ((Extrap.Type()+"_chisquared_N"+DoubleToString(ExtrapolationOrder)+".dat").c_str(), std::ios::out);
// myfile << "# [1] = (t-r*)/M\n# [2] = chi^2(amp)\n# [3] = chi^2(phi)" << endl;
  
  // Loop over time
  for(unsigned int i=0; i<Extrap.NTimes(); ++i) {
// myfile << Extrap.T(i);
    if(i % 1000 == 0) {
      cout << "Time = " << setprecision(5) << Extrap.T(i) << "\tStep " << i << " of " << Extrap.NTimes() << endl;
    }
    
    //// Set the radii and input sigmas at this time
    const double MinRadius = Ws[0].R(i);
    for(unsigned int k=0; k<Ws.size(); ++k) {
      const double Radius = Ws[k].R(i);
      oor[k] = 1.0 / Radius;
      sig[k] = Radius/MinRadius;
    }
    
    //// Loop over components
    for(unsigned int j=0; j<Extrap.NModes(); ++j) {
      //// Fill vectors with data from various radii
      for(unsigned int k=0; k<Ws.size(); ++k) {
	amp[k] = Ws[k].Mag(j,i);
	phi[k] = Ws[k].Arg(j,i);
      }
      
      if(!UseSVD) {
	//// Fit to polynomial in 1/R
	ampFit.fit();
	phiFit.fit();
	
	//// Evaluate at 0 and set the relevant component of Extrap
	Extrap.MagRef(j,i) = ampFit.a[0];
	Extrap.ArgRef(j,i) = phiFit.a[0];
	Sigmas.MagRef(j,i) = sqrt(ampFit.covar[0][0] * ampFit.chisq/DOF);
	Sigmas.ArgRef(j,i) = sqrt(phiFit.covar[0][0] * phiFit.chisq/DOF);

// myfile << " " << ampFit.chisq << " " << phiFit.chisq;
      } else {
	//// FitSVD to polynomial in 1/R
	ampFitSVD.fit();
	phiFitSVD.fit();
	
	//// Evaluate at 0 and set the relevant component of Extrap
	Extrap.MagRef(j,i) = ampFitSVD.a[0];
	Extrap.ArgRef(j,i) = phiFitSVD.a[0];
	Sigmas.MagRef(j,i) = sqrt(ampFitSVD.covar[0][0] * ampFitSVD.chisq/DOF);
	Sigmas.ArgRef(j,i) = sqrt(phiFitSVD.covar[0][0] * phiFitSVD.chisq/DOF);
// myfile << " " << ampFitSVD.chisq << " " << phiFitSVD.chisq;
      }
    }
// myfile << endl;
  }
// myfile.close();
  Extrap.RRef() = vector<double>(1, numeric_limits<double>::infinity( ) );
  Sigmas.RRef() = vector<double>(1, 0.0 );
  
  Extrap.History() << "#### Extrapolation finished." << endl;
  Sigmas.History() << "#### Extrapolation finished." << endl;
  
  return Extrap;
}

Waveform WaveformObjects::Waveforms::ExtrapolateAndPreserveResiduals(Waveform& Sigmas, const int ExtrapolationOrder, const bool UseSVD) {
  history << "### this->ExtrapolateAndPreserveResiduals(Sigmas, " << ExtrapolationOrder << ", " << UseSVD << ");" << endl;
  
  if(!PhasesAligned) { AlignPhases(); }
  if(ExtrapolationOrder<0) { return Ws[Ws.size() + ExtrapolationOrder]; }
  Waveform Extrap = Ws[0];
  Extrap.SetHistory(history.str());
  Sigmas = Extrap;
  Extrap.History() << "#### NOTE: This object is now a single Waveform (extrapolated from a 'Waveforms' object)." << endl;
  Sigmas.History() << "#### NOTE: This object contains the uncertainties in each part of each mode of the extrapolated object." << endl;
  
  // Set up the important variables
  vector<double> oor(Ws.size(), 0.0);  // one over radii
  vector<double> amp(Ws.size(), 0.0);
  vector<double> phi(Ws.size(), 0.0);
  vector<double> sig(Ws.size(), 1.0);  // These sigmas should never be less than 3e-6.
  PolynomialBasisFunctions Poly(ExtrapolationOrder);
  FitSVD<PolynomialBasisFunctions> ampFitSVD(oor, amp, sig, Poly);
  FitSVD<PolynomialBasisFunctions> phiFitSVD(oor, phi, sig, Poly);
  Fit<PolynomialBasisFunctions> ampFit(oor, amp, sig, Poly);
  Fit<PolynomialBasisFunctions> phiFit(oor, phi, sig, Poly);
  double DOF = Ws.size() - (ExtrapolationOrder+1);

  // Loop over time
  for(unsigned int i=0; i<Extrap.NTimes(); ++i) {
    if(i % 1000 == 0) {
      cout << "Time = " << setprecision(5) << Extrap.T(i) << "\tStep " << i << " of " << Extrap.NTimes() << endl;
    }
    
    //// Set the radii and input sigmas at this time
    const double MinRadius = Ws[0].R(i);
    for(unsigned int k=0; k<Ws.size(); ++k) {
      const double Radius = Ws[k].R(i);
      oor[k] = 1.0 / Radius;
      sig[k] = Radius/MinRadius;
    }
    
    //// Loop over components
    for(unsigned int j=0; j<Extrap.NModes(); ++j) {
      //// Fill vectors with data from various radii
      for(unsigned int k=0; k<Ws.size(); ++k) {
	amp[k] = Ws[k].Mag(j,i);
	phi[k] = Ws[k].Arg(j,i);
      }
      
      if(!UseSVD) {
	//// Fit to polynomial in 1/R
	ampFit.fit();
	phiFit.fit();
	
	//// Evaluate at 0 and set the relevant component of Extrap
	Extrap.MagRef(j,i) = ampFit.a[0];
	Extrap.ArgRef(j,i) = phiFit.a[0];
	Sigmas.MagRef(j,i) = sqrt(ampFit.covar[0][0] * ampFit.chisq/DOF);
	Sigmas.ArgRef(j,i) = sqrt(phiFit.covar[0][0] * phiFit.chisq/DOF);
	
	//// Loop over input Waveforms, evaluating residual of fit
	for(unsigned int k=0; k<Ws.size(); ++k) {
	  const double Mag = Ws[k].Mag(j,i);
	  Ws[k].MagRef(j,i) = (Mag - Poly(ampFit.a, oor[k]))/Mag;
	  Ws[k].ArgRef(j,i) = Ws[k].Arg(j,i) - Poly(phiFit.a, oor[k]);
	}
	
      } else {
	//// FitSVD to polynomial in 1/R
	ampFitSVD.fit();
	phiFitSVD.fit();
	
	//// Evaluate at 0 and set the relevant component of Extrap
	Extrap.MagRef(j,i) = ampFitSVD.a[0];
	Extrap.ArgRef(j,i) = phiFitSVD.a[0];
	Sigmas.MagRef(j,i) = sqrt(ampFitSVD.covar[0][0] * ampFitSVD.chisq/DOF);
	Sigmas.ArgRef(j,i) = sqrt(phiFitSVD.covar[0][0] * phiFitSVD.chisq/DOF);
	
	//// Loop over input Waveforms, evaluating residual of fit
	for(unsigned int k=0; k<Ws.size(); ++k) {
	  const double Mag = Ws[k].Mag(j,i);
	  Ws[k].MagRef(j,i) = (Mag - Poly(ampFitSVD.a, oor[k]))/Mag;
	  Ws[k].ArgRef(j,i) = Ws[k].Arg(j,i) - Poly(phiFitSVD.a, oor[k]);
	}
      }
    }
  }
  Extrap.RRef() = vector<double>(1, numeric_limits<double>::infinity( ) );
  Sigmas.RRef() = vector<double>(1, 0.0 );
  
  Extrap.History() << "#### Extrapolation finished." << endl;
  Sigmas.History() << "#### Extrapolation finished." << endl;
  
  return Extrap;
}

Waveform WaveformObjects::Waveforms::ExtrapolateAndPreserveResiduals(Waveform& Sigmas, const vector<double>& Times, const vector<double>& Omegas,
								     const int ExtrapolationOrder, const bool UseSVD) {
  history << "### this->ExtrapolateAndPreserveResiduals(Sigmas, Times, Omegas, " << ExtrapolationOrder << ", " << UseSVD << ");" << endl;
  
  if(!PhasesAligned) { AlignPhases(); }
  if(ExtrapolationOrder<0) { return Ws[Ws.size() + ExtrapolationOrder]; }
  const vector<double> Omega = Interpolate(Times, Omegas, Ws[0].T());
  Waveform Extrap = Ws[0];
  Extrap.SetHistory(history.str());
  Sigmas = Extrap;
  Extrap.History() << "#### NOTE: This object is now a single Waveform (extrapolated from a 'Waveforms' object)." << endl;
  Sigmas.History() << "#### NOTE: This object contains the uncertainties in each part of each mode of the extrapolated object." << endl;
  
  // Set up the important variables
  vector<double> oor(Ws.size(), 0.0);  // one over radii
  vector<double> amp(Ws.size(), 0.0);
  vector<double> phi(Ws.size(), 0.0);
  vector<double> sig(Ws.size(), 1.0);  // These sigmas should never be less than 3e-6.
  PolynomialBasisFunctions Poly(ExtrapolationOrder);
  FitSVD<PolynomialBasisFunctions> ampFitSVD(oor, amp, sig, Poly);
  FitSVD<PolynomialBasisFunctions> phiFitSVD(oor, phi, sig, Poly);
  Fit<PolynomialBasisFunctions> ampFit(oor, amp, sig, Poly);
  Fit<PolynomialBasisFunctions> phiFit(oor, phi, sig, Poly);
  double DOF = Ws.size() - (ExtrapolationOrder+1);

  // Loop over time
  for(unsigned int i=0; i<Extrap.NTimes(); ++i) {
    if(i % 1000 == 0) {
      cout << "Time = " << setprecision(5) << Extrap.T(i) << "\tStep " << i << " of " << Extrap.NTimes() << endl;
    }
    
    //// Set the radii and input sigmas at this time
    const double lambdabar = 1.0 / Omega[i];
    const double MinRadius = Ws[0].R(i);
    
    //// Loop over components
    for(unsigned int j=0; j<Extrap.NModes(); ++j) {
      //// Do this in here, so that lambdabar may be adjusted correctly
      const int M = Ws[0].M(j);
      for(unsigned int k=0; k<Ws.size(); ++k) {
	const double Radius = Ws[k].R(i);
	oor[k] = (M*lambdabar) / Radius;
	sig[k] = Radius/MinRadius;
      }
    
      //// Fill vectors with data from various radii
      for(unsigned int k=0; k<Ws.size(); ++k) {
	amp[k] = Ws[k].Mag(j,i);
	phi[k] = Ws[k].Arg(j,i);
      }
      
      if(!UseSVD) {
	//// Fit to polynomial in 1/R
	ampFit.fit();
	phiFit.fit();
	
	//// Evaluate at 0 and set the relevant component of Extrap
	Extrap.MagRef(j,i) = ampFit.a[0];
	Extrap.ArgRef(j,i) = phiFit.a[0];
	Sigmas.MagRef(j,i) = sqrt(ampFit.covar[0][0] * ampFit.chisq/DOF);
	Sigmas.ArgRef(j,i) = sqrt(phiFit.covar[0][0] * phiFit.chisq/DOF);
	
	//// Loop over input Waveforms, evaluating residual of fit
	for(unsigned int k=0; k<Ws.size(); ++k) {
	  const double Mag = Ws[k].Mag(j,i);
	  Ws[k].MagRef(j,i) = (Mag - Poly(ampFit.a, oor[k]))/Mag;
	  Ws[k].ArgRef(j,i) = Ws[k].Arg(j,i) - Poly(phiFit.a, oor[k]);
	}
	
      } else {
	//// FitSVD to polynomial in 1/R
	ampFitSVD.fit();
	phiFitSVD.fit();
	
	//// Evaluate at 0 and set the relevant component of Extrap
	Extrap.MagRef(j,i) = ampFitSVD.a[0];
	Extrap.ArgRef(j,i) = phiFitSVD.a[0];
	Sigmas.MagRef(j,i) = sqrt(ampFitSVD.covar[0][0] * ampFitSVD.chisq/DOF);
	Sigmas.ArgRef(j,i) = sqrt(phiFitSVD.covar[0][0] * phiFitSVD.chisq/DOF);
	
	//// Loop over input Waveforms, evaluating residual of fit
	for(unsigned int k=0; k<Ws.size(); ++k) {
	  const double Mag = Ws[k].Mag(j,i);
	  Ws[k].MagRef(j,i) = (Mag - Poly(ampFitSVD.a, oor[k]))/Mag;
	  Ws[k].ArgRef(j,i) = Ws[k].Arg(j,i) - Poly(phiFitSVD.a, oor[k]);
	}
      }
    }
  }
  Extrap.RRef() = vector<double>(1, numeric_limits<double>::infinity( ) );
  Sigmas.RRef() = vector<double>(1, 0.0 );
  
  Extrap.History() << "#### Extrapolation finished." << endl;
  Sigmas.History() << "#### Extrapolation finished." << endl;
  
  return Extrap;
}

Waveform WaveformObjects::Waveforms::Merge(const double& MinStep, const double& MinTime) {
  //cout << "Calling Merge(...)" << endl;
  
  history << "### this->Merge(" << MinStep << ", " << MinTime << ");" << endl;
  
  if(Ws.size()<2) {
    cerr << "Ws.size()=" << Ws.size() << endl;
    throw("Cant' Merge fewer than 2 Waveforms");
  }
  SetCommonTime(MinStep, MinTime);
  Waveform Merged = Ws[0];
  Merged.SetHistory(history.str());
  Merged.History() << "#### NOTE: This object is now a single Waveform (merged from a 'Waveforms' object)." << endl;
  Merged.History() << "#" << history;
  Merged.LMRef().resize(Ws.size(), 2);
  Merged.MagRef().resize(Ws.size(), Ws[0].NTimes());
  Merged.ArgRef().resize(Ws.size(), Ws[0].NTimes());
  for(unsigned int i=1; i<Ws.size(); ++i) {
    Merged.LRef(i) = Ws[i].L(0);
    Merged.MRef(i) = Ws[i].M(0);
    Merged.MagRef(i) = Ws[i].Mag(0);
    Merged.ArgRef(i) = Ws[i].Arg(0);
  }
  Merged.History() << "#### Merge finished." << endl;
  return Merged;
}
