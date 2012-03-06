%feature("docstring") WaveformObjects::Waveforms::~Waveforms """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    ~Waveforms
    

"""

%feature("docstring") WaveformObjects::Waveforms::operator[] """


  Parameters
  ----------
    const int i
  
  Returns
  -------
    const Waveform&
    




  Parameters
  ----------
    const int i
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::RRef """


  Parameters
  ----------
    const unsigned int Time
  
  Returns
  -------
    double&
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    vector<double>&
    

"""

%feature("docstring") WaveformObjects::Waveform::NSamplesPerCycle22 """


  Parameters
  ----------
    const unsigned int N = 20
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformAtAPoint::WaveformAtAPoint """


  Parameters
  ----------
    const Waveform& W
    const double dt
    const double Vartheta
    const double Varphi
  
  Returns
  -------
    WaveformAtAPoint
    

"""

%feature("docstring") WaveformObjects::Waveform::M """


  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    const int
    

"""

%feature("docstring") Waveforms::SetCommonTime """


  Parameters
  ----------
    const double& MinStep = 0.005
    const double& MinTime = 0.0
  
  Returns
  -------
    void
    

"""

%feature("docstring") WaveformObjects::Waveform::TypeIndexRef """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    unsigned int&
    

"""

%feature("docstring") WaveformObjects::Waveform::LMRef """


  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    vector<int>&
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    Matrix<int>&
    

"""

%feature("docstring") WaveformObjects::Waveform::FrameRef """


  Parameters
  ----------
    const unsigned int Time
  
  Returns
  -------
    Quaternion&
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    vector<Quaternion>&
    

"""

%feature("docstring") Waveforms::AlignPhases """


  Parameters
  ----------
    const double& AlignmentPoint = 0.5
  
  Returns
  -------
    void
    

"""

%feature("docstring") WaveformObjects::Waveform::T """


  Parameters
  ----------
    const unsigned int Time
  
  Returns
  -------
    const double
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    const vector<double>&
    

"""

%feature("docstring") WaveformObjects::Waveform::R """


  Parameters
  ----------
    const unsigned int Time
  
  Returns
  -------
    const double
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    const vector<double>&
    

"""

%feature("docstring") WaveformObjects::Waveform::Peak22Time """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    double
    

"""

%feature("docstring") WaveformObjects::Waveform::swap """
Efficiently swaps data between two Waveform objects.
====================================================
  Parameters
  ----------
    Waveform& b
  
  Returns
  -------
    void
    
  Description
  -----------
    This function uses the std::vector method swap, which simply swaps pointers
    to data for efficiency  

"""

%feature("docstring") WaveformAtAPointFT::ZeroAbove """


  Parameters
  ----------
    const double Frequency
  
  Returns
  -------
    WaveformAtAPointFT&
    

"""

%feature("docstring") Waveforms::Extrapolate """


  Parameters
  ----------
    const int ExtrapolationOrder = 5
  
  Returns
  -------
    Waveform
    

"""

%feature("docstring") WaveformObjects::Waveform::TypeIndex """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    const unsigned int
    

"""

%feature("docstring") WaveformObjects::Waveform::DropLMode """


  Parameters
  ----------
    const int L
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::L """


  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    const int
    

"""

%feature("docstring") WaveformObjects::Waveform::clear """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    void
    

"""

%feature("docstring") WaveformObjects::Waveform::DropZeroMModes """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::operator[] """


  Parameters
  ----------
    const unsigned int mode
  
  Returns
  -------
    Waveform
    

"""

%feature("docstring") WaveformObjects::Waveform::HackOddLPlusM """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::DropLMMode """


  Parameters
  ----------
    const int L
    const int M
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::Mag """


  Parameters
  ----------
    const unsigned int Mode
    const unsigned int Time
  
  Returns
  -------
    const double
    




  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    const vector<double>&
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    const Matrix<double>&
    

"""

%feature("docstring") WaveformObjects::Waveform::FixNonOscillatingData """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") DoubleSidedF """


  Parameters
  ----------
    const unsigned int i
    const unsigned int N
    const double df
  
  Returns
  -------
    double
    

"""

%feature("docstring") WaveformUtilities """
namespace WaveformUtilities
===========================

"""

%feature("docstring") RadiationAxis """


  Parameters
  ----------
    const Waveform& W
    vector<double>& alpha
    vector<double>& beta
    const double alphaGuess = 0.0
    const double betaGuess = 0.0
  
  Returns
  -------
    void
    

"""

%feature("docstring") operator<< """


  Parameters
  ----------
    ostream& os
    const WaveformObjects::Waveform& a
  
  Returns
  -------
    ostream&
    




  Parameters
  ----------
    ostream& os
    const Waveform& a
  
  Returns
  -------
    ostream&
    




  Parameters
  ----------
    ostream& os
    const WaveformAtAPoint& a
  
  Returns
  -------
    ostream&
    




  Parameters
  ----------
    ostream& os
    const WaveformObjects::WaveformAtAPoint& a
  
  Returns
  -------
    ostream&
    




  Parameters
  ----------
    ostream& os
    const WaveformAtAPointFT& a
  
  Returns
  -------
    ostream&
    




  Parameters
  ----------
    ostream& os
    const WaveformObjects::WaveformAtAPointFT& a
  
  Returns
  -------
    ostream&
    

"""

%feature("docstring") WaveformObjects::Waveform::DropOddMModes """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") Waveforms::FixNonOscillatingData """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    void
    

"""

%feature("docstring") WaveformObjects::Waveform::AlignPhasesToTwoPi """


  Parameters
  ----------
    const Waveform& a
    const double t
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::Omega2m2 """


  Parameters
  ----------
    const double t1 = -1e300
    const double t2 = 1e300
  
  Returns
  -------
    vector<double>
    

"""

%feature("docstring") WaveformObjects::Waveform::TransformToSchmidtFrame """


  Parameters
  ----------
    const double alpha0Guess = 0.0
    const double beta0Guess = 0.0
  
  Returns
  -------
    Waveform&
    




  Parameters
  ----------
    vector<double>& alpha
    vector<double>& beta
    const double alpha0Guess = 0.0
    const double beta0Guess = 0.0
  
  Returns
  -------
    Waveform&
    




  Parameters
  ----------
    vector<double>& alpha
    vector<double>& beta
    vector<double>& gamma
    const double alpha0Guess = 0.0
    const double beta0Guess = 0.0
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::WaveformAtAPoint """
class WaveformObjects::WaveformAtAPoint
=======================================
  This class defines a derived class of a Waveform evaluated at a point. A
  separate class is needed because a Waveform evaluated at a point need not
  have a well defined (smooth, simple) amplitude and phase, and thus must be
  stored as (Re,Im) data rather than (Amp,Phi) data. The second constructor is
  provided because the memory requirements are prohibitive when interpolating
  an entire Waveform to a uniform time grid of sufficient resolution to obtain
  a good FT of the data. This constructor, then, constructs a uniform time grid
  sized to the next power of two, using the input timestep and the time grid of
  the input Waveform, and progressively interpolates each mode and evaluates it
  at the desired point.
  
  Member variables
  ----------------
    double vartheta
    double varphi
  

"""

%feature("docstring") SetWaveformTypes """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    void
    
  Description
  -----------
    Note on Waveform Types: In any system, h -- being strain -- should be
    dimensionless. When G=c=1, the dimensionless quantities are rMPsi4, rhdot,
    and rhOverM; as are rOverM and tOverM. When G and c are dimensionful, the
    dimensionless quantities are
(r/c) * (M*G/c^3) * Psi4
    
    (r/c) * hdot
    
    (r/c) * h / (M*G/c^3)
    
    (r/c) / (M*G/c^3)
    
    t / (M*G/c^3) To regain the dimensionful quantities, we simply need to
    remove the relevant dimensionful elements.  

"""

%feature("docstring") sign """


  Parameters
  ----------
    const double x
  
  Returns
  -------
    double
    

"""

%feature("docstring") WaveformObjects::Waveform::Arg """


  Parameters
  ----------
    const unsigned int Mode
    const unsigned int Time
  
  Returns
  -------
    const double
    




  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    const vector<double>&
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    const Matrix<double>&
    

"""

%feature("docstring") WaveformObjects::Waveforms::clear """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    void
    

"""

%feature("docstring") ScaleMag """


  Parameters
  ----------
    const double S
    const unsigned int typeIndex
  
  Returns
  -------
    double
    

"""

%feature("docstring") GetFileFormat """


  Parameters
  ----------
    const vector<string>& Header
  
  Returns
  -------
    string
    




  Parameters
  ----------
    const vector<string>& Header
  
  Returns
  -------
    string
    

"""

%feature("docstring") WaveformObjects::Waveform::OutputToNINJAFormat """


  Parameters
  ----------
    const string& MetadataFileName
    const string ExtractionRadiusString = ''
    const string WaveformIdentifier = ''
  
  Returns
  -------
    void
    

"""

%feature("docstring") WaveformObjects::Waveform::AttachQNMs """


  Parameters
  ----------
    const double delta
    const double chiKerr
    double dt = 0.0
    const double TLength = 500.0
  
  Returns
  -------
    Waveform&
    
  Description
  -----------
    Add the new times, and resize everything as appropriate  

"""

%feature("docstring") WaveformObjects::Waveform::AppendHistory """


  Parameters
  ----------
    const string& Hist
  
  Returns
  -------
    void
    

"""

%feature("docstring") WaveformObjects::Waveform::DropBefore """


  Parameters
  ----------
    const double t
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::WaveformAtAPoint::ReRef """


  Parameters
  ----------
    const unsigned int i
  
  Returns
  -------
    double&
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    vector<double>&
    

"""

%feature("docstring") WaveformObjects::Waveform::Flux """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    vector<double>
    

"""

%feature("docstring") MinimalRotation """


  Parameters
  ----------
    const vector<double>& alpha
    const vector<double>& beta
    vector<double>& gamma
    const vector<double>& t
  
  Returns
  -------
    void
    

"""

%feature("docstring") WaveformObjects::Waveform::UniformTime """


  Parameters
  ----------
    const unsigned int N = 200
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::DropAfter """


  Parameters
  ----------
    const double t
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") OutputSingleMode """


  Parameters
  ----------
    ostream& os
    const WaveformObjects::Waveform& a
    const unsigned int Mode
  
  Returns
  -------
    void
    




  Parameters
  ----------
    const string& FileName
    const WaveformObjects::Waveform& a
    const unsigned int Mode
    const unsigned int precision = 14
  
  Returns
  -------
    void
    




  Parameters
  ----------
    ostream& os
    const Waveform& a
    const unsigned int Mode
  
  Returns
  -------
    void
    




  Parameters
  ----------
    const string& FileName
    const Waveform& a
    const unsigned int Mode
    const unsigned int precision
  
  Returns
  -------
    void
    

"""

%feature("docstring") WaveformObjects::Waveform::SetTimeFromLapseSurfaceIntegral """


  Parameters
  ----------
    const string& LapseFileName
    const double ADMMass
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::History """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    stringstream&
    

"""

%feature("docstring") WaveformObjects::WaveformAtAPoint::Vartheta """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    const double
    

"""

%feature("docstring") WaveformObjects::WaveformAtAPointFT """
class WaveformObjects::WaveformAtAPointFT
=========================================
  The WaveformAtAPointFT class is a derived class, constructed from waveforms
  evaluated at a point, using the given complex detector response (F+ + i*Fx)
  -- or more particularly, its amplitude and phase.
  
  Member variables
  ----------------
    bool Normalized
  

"""

%feature("docstring") WaveformObjects::Waveform::AlignTo """


  Parameters
  ----------
    const Waveform& a
    const double t1
    const double t2
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::WaveformAtAPoint::VarthetaRef """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    double&
    

"""

%feature("docstring") WaveformObjects::Waveform::AlignWithIntermediate """


  Parameters
  ----------
    const Waveform& a
    Waveform Intermediate
    const double t1
    const double t2
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::DropNegativeMModes """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformAtAPointFT::operator- """


  Parameters
  ----------
    const WaveformAtAPointFT& b
  
  Returns
  -------
    WaveformAtAPointFT
    

"""

%feature("docstring") MinimalGrid_Hunt """


  Parameters
  ----------
    const vector<double>& t
    const vector<double>& arg
    const double argTol
    const int I0
    const int I1
  
  Returns
  -------
    int
    
  Description
  -----------
    Given data (t,arg), some initial index I0, and a guess for I1, this
    function outputs the optimal index I1 so that (t,arg) can be interpolated
    between I0 and I1 to just within argTol of the full input data set. Compare
    Numerical Recipes's 'hunt' function; this is basically a hunt for that
    optimal index.  

"""

%feature("docstring") WaveformObjects::Waveform::TransformToMinimalRotationFrame """


  Parameters
  ----------
    const double alpha0Guess = 0.0
    const double beta0Guess = 0.0
  
  Returns
  -------
    Waveform&
    




  Parameters
  ----------
    vector<double>& alpha
    vector<double>& beta
    vector<double>& gamma
    const double alpha0Guess = 0.0
    const double beta0Guess = 0.0
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::AddToTime """


  Parameters
  ----------
    const double t
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformAtAPointFT::WaveformAtAPointFT """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    WaveformAtAPointFT
    




  Parameters
  ----------
    const WaveformAtAPoint& W
    const unsigned int WindowNCycles = 1
    const double DetectorResponseAmp = 1.0
    const double DetectorResponsePhase = 0.0
  
  Returns
  -------
    WaveformAtAPointFT
    

"""

%feature("docstring") WaveformObjects::WaveformAtAPoint::WaveformAtAPoint """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    WaveformAtAPoint
    

"""

%feature("docstring") WaveformObjects::WaveformAtAPoint::~WaveformAtAPoint """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    ~WaveformAtAPoint
    

"""

%feature("docstring") WaveformObjects::Waveform::Interpolate """
Interpolate Waveform to a new time vector.
==========================================
  Parameters
  ----------
    const vector<double>& Time
  
  Returns
  -------
    Waveform&
    


Interpolate Waveform to a new time vector, returning ExtrapVal when out of range.
=================================================================================
  Parameters
  ----------
    const vector<double>& Time
    const double ExtrapVal
  
  Returns
  -------
    Waveform&
    


Interpolate Waveform to a single time.
======================================
  Parameters
  ----------
    const double Time
  
  Returns
  -------
    Waveform&
    


Interpolate Waveform to the time axis of another Waveform.
==========================================================
  Parameters
  ----------
    const Waveform& b
  
  Returns
  -------
    Waveform&
    


Interpolate Waveform to the time axis of another Waveform, returning ExtrapVal when out of range.
=================================================================================================
  Parameters
  ----------
    const Waveform& b
    const double ExtrapVal
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::operator/ """


  Parameters
  ----------
    const Waveform& b
  
  Returns
  -------
    Waveform
    

"""

%feature("docstring") WaveformObjects::Waveform::FindModeIndex """
Find index of mode with given (l,m) data.
=========================================
  Parameters
  ----------
    const int L
    const int M
      Some other description
  
  Returns
  -------
    unsigned int
    

"""

%feature("docstring") WaveformObjects::Waveform::HybridizeWith_F """


  Parameters
  ----------
    const Waveform& a
    const double omega
    const double omegat1 = -1e300
    const double omegat2 = 1e300
    const double DeltaT = 10.0
    const double MinStep = 0.005
  
  Returns
  -------
    Waveform
    

"""

%feature("docstring") WaveformObjects::Waveform::HybridizeWith """


  Parameters
  ----------
    const Waveform& b
    const double t1
    const double t2
    const double MinStep = 0.005
  
  Returns
  -------
    Waveform
    

"""

%feature("docstring") WaveformObjects::Waveform """
class WaveformObjects::Waveform
===============================
  Fundamental object encapsulating waveform data, such as time, amplitude, and
  phase information.
  
  This object provides the main user interface for this collection of code. The
  various methods for this class are intended to provide all manipulations that
  might be necessary in the course of waveform analysis.
  
  Member variables
  ----------------
    stringstream history
    unsigned int typeIndex
    string timeScale
    vector<double> t
    vector<double> r
    vector<Quaternion> frame
    Matrix<int> lm
    Matrix<double> mag
    Matrix<double> arg
    vector<string> Types
  

"""

%feature("docstring") WaveformObjects::Waveform::MinimalGrid """


  Parameters
  ----------
    const double MagTol = 1.e-5
    const double ArgTol = 1.e-5
  
  Returns
  -------
    Waveform&
    
  Description
  -----------
    The objective here will be to create a vector of bool's, the same length as
    t. The truth value will correspond to whether or not that time step should
    be kept in the final data. We begin by assuming that the very first and
    last steps should obviously be kept. Then, there are two stages. First is a
    coarse stage, which steps through the data making intervals small enough to
    reproduce the arg data at the interval's midpoint to within argTol, but no
    smaller. Second is the finer stage, which goes through each interval,
    checking that every single point in the input data can be reproduced to
    within argTol and magTol. If that's not true, the interval is split evenly
    into two, and the algorithm proceeds with the earlier interval. Finally,
    the input t, mag, and arg vectors are replaced by the smaller vectors given
    by our vector of bool's.  

"""

%feature("docstring") WaveformObjects::Waveform::operator= """


  Parameters
  ----------
    const Waveform& b
  
  Returns
  -------
    Waveform&
    
  Description
  -----------
    This call should not be recorded in the history  

"""

%feature("docstring") BumpFunction """


  Parameters
  ----------
    const double x
    const double x0
    const double x1
  
  Returns
  -------
    double
    

"""

%feature("docstring") WaveformObjects::Waveform::HistoryStr """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    const string
    

"""

%feature("docstring") WaveformObjects::WaveformAtAPoint::ImRef """


  Parameters
  ----------
    const unsigned int i
  
  Returns
  -------
    double&
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    vector<double>&
    

"""

%feature("docstring") WaveformObjects::Waveform::ArgRef """


  Parameters
  ----------
    const unsigned int Mode
    const unsigned int Time
  
  Returns
  -------
    double&
    




  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    vector<double>&
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    Matrix<double>&
    

"""

%feature("docstring") WaveformObjects::Waveform::Differentiate """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::Conjugate """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::WaveformAtAPoint::Re """


  Parameters
  ----------
    const unsigned int i
  
  Returns
  -------
    const double
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    const vector<double>&
    

"""

%feature("docstring") WaveformObjects::WaveformAtAPoint::Varphi """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    const double
    

"""

%feature("docstring") WaveformObjects::Waveform::AlignTo_F """


  Parameters
  ----------
    const Waveform& a
    const double omega
    const double omegat1 = -1e300
    const double omegat2 = 1e300
    const double DeltaT = 1e300
    const double MinStep = 0.005
  
  Returns
  -------
    Waveform&
    
  Description
  -----------
    Make sure A only includes data before T2
    
    Make sure A only includes data after T1
    
    Make sure NewOmegaA gets up to abs(omega), but is strictly monotonically
    increasing before it
    
    Make sure NewOmegaA gets past abs(omega), and is strictly monotonically
    increasing afterward
    
    Make sure B only includes data before T2
    
    Make sure B only includes data after T1
    
    Make sure NewOmegaB gets up to fabs(omega), but is strictly monotonically
    increasing before it
    
    Make sure NewOmegaB gets past fabs(omega), and is strictly monotonically
    increasing afterward  

"""

%feature("docstring") WaveformObjects::Waveforms """
class WaveformObjects::Waveforms
================================
  Member variables
  ----------------
    vector<Waveform> Ws
    bool CommonTimeSet
    bool PhasesAligned
  

"""

%feature("docstring") WaveformObjects::WaveformAtAPoint::Im """


  Parameters
  ----------
    const unsigned int i
  
  Returns
  -------
    const double
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    const vector<double>&
    

"""

%feature("docstring") WaveformObjects::Waveform::~Waveform """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    ~Waveform
    

"""

%feature("docstring") WaveformObjects::Waveform::SetHistory """


  Parameters
  ----------
    const string& Hist
  
  Returns
  -------
    void
    

"""

%feature("docstring") WaveformAtAPointFT::operator* """


  Parameters
  ----------
    const double b
  
  Returns
  -------
    WaveformAtAPointFT
    

"""

%feature("docstring") MinimalGrid_Check """


  Parameters
  ----------
    const vector<double>& x
    const vector<double>& y
    const int I0
    const int I1
    const double Tol
  
  Returns
  -------
    bool
    
  Description
  -----------
    Returns true if the input (x,y) data can be interpolated between indices I0
    and I1 to within a tolerance of Tol at the midpoint between I0 and I1.  

"""

%feature("docstring") GetWaveformTimeScaleAndLM """


  Parameters
  ----------
    const string& FullPath
    const vector<string>& Header
    string& Scale
    Matrix<int>& lm
  
  Returns
  -------
    void
    




  Parameters
  ----------
    const string& FullPath
    const vector<string>& Header
    string& Scale
    Matrix<int>& lm
  
  Returns
  -------
    void
    

"""

%feature("docstring") WaveformObjects::Waveform::Type """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    const string
    

"""

%feature("docstring") WaveformObjects::Waveform::Frame """


  Parameters
  ----------
    const unsigned int Time
  
  Returns
  -------
    const Quaternion&
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    const vector<Quaternion>&
    

"""

%feature("docstring") GetWaveformType """


  Parameters
  ----------
    const string& FullPath
    const vector<string>& Header
  
  Returns
  -------
    int
    




  Parameters
  ----------
    const string& FullPath
    const vector<string>& Header
  
  Returns
  -------
    int
    

"""

%feature("docstring") WaveformObjects::Waveform::RotateCoordinates """


  Parameters
  ----------
    const double alpha
    const double beta
    const double gamma
  
  Returns
  -------
    Waveform&
    




  Parameters
  ----------
    const vector<double>& alpha
    const vector<double>& beta
    const vector<double>& gamma
  
  Returns
  -------
    Waveform&
    




  Parameters
  ----------
    const vector<Quaternion>& Q
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::SetPhysicalMassAndDistance """


  Parameters
  ----------
    const double TotalMassInSolarMasses
    const double DistanceInMegaparsecs
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::LM """


  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    const vector<int>&
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    const Matrix<int>&
    

"""

%feature("docstring") WaveformObjects::Waveform::MRef """


  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    int&
    

"""

%feature("docstring") WaveformObjects::Waveform::NTimes """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    const unsigned int
    

"""

%feature("docstring") WaveformObjects::Waveform::TRef """


  Parameters
  ----------
    const unsigned int Time
  
  Returns
  -------
    double&
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    vector<double>&
    

"""

%feature("docstring") WaveformObjects::Waveform::Waveform """
Default constructor for an empty object.
========================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform
    


Copy constructor.
=================
  Parameters
  ----------
    const Waveform& W
  
  Returns
  -------
    Waveform
    
  Description
  -----------
    Simply copies all fields in the input object to the constructed object,
    including history  


Constructor from data file.
===========================
  Parameters
  ----------
    const string& DataFileName
      String containing absolute or relative path to file
    const string& Format
      String of either 'MagArg' (for data in magnitude-argument format) or
      'ReIm'
    const bool ZeroEnds = false
  
  Returns
  -------
    Waveform
    
  Description
  -----------
    This is the main Waveform constructor, which reads either a .dat file or a
    metadata file with associated data files. For path names ending in .bbh or
    .minimal, the file is assumed to be a NINJA2-type metadata file, containing
    exactly one section entitled either '[ht-ampphi-data]' or '[ht-data]'. (In
    this case, the data type is deduced from the section title, and Format is
    ignored.) The following lines then point to files containing the (l,m)
    data, where the first column is the time, and the following two lines
    contain either the real-imaginary or magnitude-argument data.
    
    For all other path names, the file is assumed to be a single data file
    containing all necessary (l,m) modes. The first column is assumed to be
    time, and consecutive pairs of columns are assumed to contain either
    real-imaginary or magnitude-argument data. The Waveform type is deduced
    from the file name. For example, 'rhOverM_ExtrapolatedN5.dat' will be
    automatically assigned a type of 'rhOverM'. Similarly, the time scale and
    (l,m) values for the pairs of columns are deduced from the header, assuming
    standard SpEC output. That is, the header is assumed to contain lines like 
     # [1] = (t-r*)/M 
 # [2] = Mag{rMPsi4(2,-2)} 
 # [3] = Arg{rMPsi4(2,-2)} 

    Finally, the data format is also deduced from the header, and a warning is
    issued if it mismatches the input parameter to this function.  


Simple PN/EOB constructor for non-precessing systems.
=====================================================
  Parameters
  ----------
    const string& Approximant
      ('TaylorT1'|'TaylorT2'|'TaylorT3'|'TaylorT4'|'EOB')
    const double delta
      $\delta = (M_1 - M_2) / (M_2 + M_2)$
    const double chis
      $\chi_s = (\chi_1+\chi_2)/2$
    const double chia
      $\chi_a = (\chi_1-\chi_2)/2$
    const double v0
      Initial Newtonian velocity: $v = \left( \frac{G\, M\, \Omega}{c^3}
      \right)^{1/3}$
    const Matrix<int> LM = Matrix<int>(0, 0)
      Desired set of (l,m) modes for the output; if empty, output all modes up
      to $L = 8$
    const int nsave = -1
      Number of points to output; note denseish
    const bool denseish = true
      If true, output nsave points per time step taken by the integrator
    const double PNPhaseOrder = 3.5
      Unused parameter
    const double PNAmplitudeOrder = 3.0
      Unused parameter
  
  Returns
  -------
    Waveform
    
  Description
  -----------
    Constructs a PN/EOB inspiral for simple non-precessing systems. Note that
    in all cases, only the inspiral is returned -- EOB included. To attach a
    ringdown (though a hackish technique) see also the AttachQNMs function.
    
    The total number of modes required for $L$ is given by \begin{align}
    N_{\text{modes}}&= \sum_{l=2}^{L} (2l+1) \\&= 2\left[L\, (L-1)/2-1\right] +
    (L-2) \\&= (L+3)\, (L-1) \end{align}
    
    AttachQNMs  


PN/EOB constructor for precessing systems.
==========================================
  Parameters
  ----------
    const string& Approximant
      ('TaylorT4Spin')
    const double delta
      $\delta = (M_1 - M_2) / (M_2 + M_2)$
    const vector<double>& chi1
      $\vec{\chi}_1 = \vec{S}_1 / M_1^2$
    const vector<double>& chi2
      $\vec{\chi}_2 = \vec{S}_2 / M_2^2$
    const double v0
      Initial Newtonian velocity: $v = \left( \frac{G\, M\, \Omega}{c^3}
      \right)^{1/3}$
    vector<double>& alpha
      Returns vector containing $\alpha$ coordinates of frame rotation
    vector<double>& beta
      Returns vector containing $\beta$ coordinates of frame rotation
    vector<double>& gamma
      Returns vector containing $\gamma$ coordinates of frame rotation
    const Matrix<int> LM = Matrix<int>(0, 0)
      Desired set of (l,m) modes for the output; if empty, output all modes up
      to $L = 8$
    const int nsave = -1
      Number of points to output; note denseish
    const bool denseish = true
      If true, output nsave points per time step taken by the integrator
    const double PNPhaseOrder = 3.5
      Unused parameter
    const double PNAmplitudeOrder = 3.0
      Unused parameter
  
  Returns
  -------
    Waveform
    
  Description
  -----------
    Constructs a PN inspiral for precessing systems using the method described
    in [Phys. Rev. D 84, 124011
    (2011)](http://link.aps.org/doi/10.1103/PhysRevD.84.124011)  

"""

%feature("docstring") WaveformObjects::Waveform::UniformTimeToPowerOfTwo """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::SetTotalMassToOne """


  Parameters
  ----------
    const double TotalMassInCurrentUnits
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::WaveformAtAPointFT::F """


  Parameters
  ----------
    const unsigned int i
  
  Returns
  -------
    const double
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    const vector<double>&
    

"""

%feature("docstring") WaveformObjects::Waveform::HasNaNs """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    bool
    

"""

%feature("docstring") WaveformObjects::Waveform::MagRef """


  Parameters
  ----------
    const unsigned int Mode
    const unsigned int Time
  
  Returns
  -------
    double&
    




  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    vector<double>&
    




  Parameters
  ----------
    (none)
  
  Returns
  -------
    Matrix<double>&
    

"""

%feature("docstring") WaveformAtAPointFT::InnerProduct """


  Parameters
  ----------
    const WaveformAtAPointFT& B
    const vector<double>& InversePSD
  
  Returns
  -------
    double
    

"""

%feature("docstring") Waveforms::Waveforms """


  Parameters
  ----------
    const Waveforms& In
  
  Returns
  -------
    Waveforms
    




  Parameters
  ----------
    const int N = 0
  
  Returns
  -------
    Waveforms
    




  Parameters
  ----------
    const vector<double>& Radii
    const string& DataFile
    const string& AreaFile
    const string& LapseFile
    const double& ADMMass
    const double& ChMass
    const bool ZeroEnds = false
  
  Returns
  -------
    Waveforms
    

"""

%feature("docstring") WaveformObjects::Waveform::UnfixNonOscillatingData """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::TortoiseOffset """


  Parameters
  ----------
    const double ADMMass
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::ZeroBefore """


  Parameters
  ----------
    const double t
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") tolower """


  Parameters
  ----------
    const string& A
  
  Returns
  -------
    string
    




  Parameters
  ----------
    const string& A
  
  Returns
  -------
    string
    

"""

%feature("docstring") WaveformObjects::Waveform::LRef """


  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    int&
    

"""

%feature("docstring") WaveformObjects::Waveform::RotatePhysicalSystem """


  Parameters
  ----------
    const double alpha
    const double beta
    const double gamma
  
  Returns
  -------
    Waveform&
    




  Parameters
  ----------
    const vector<double>& alpha
    const vector<double>& beta
    const vector<double>& gamma
  
  Returns
  -------
    Waveform&
    




  Parameters
  ----------
    const vector<Quaternion>& Q
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformAtAPointFT::Normalize """


  Parameters
  ----------
    const vector<double>& InversePSD
  
  Returns
  -------
    WaveformAtAPointFT&
    

"""

%feature("docstring") WaveformObjects::Waveform::SetArealRadius """


  Parameters
  ----------
    const string& AreaFileName
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::Waveform::TimeScale """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    const string
    

"""

%feature("docstring") WaveformObjects::Waveform::Peak22TimeIndex """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    unsigned int
    

"""

%feature("docstring") Output """


  Parameters
  ----------
    const string& FileName
    const WaveformObjects::Waveform& a
    const unsigned int precision = 14
  
  Returns
  -------
    void
    




  Parameters
  ----------
    const string& FileName
    const Waveform& a
    const unsigned int precision
  
  Returns
  -------
    void
    

"""

%feature("docstring") WaveformObjects::Waveform::RescaleMagForRadius """


  Parameters
  ----------
    const double OldRadius
  
  Returns
  -------
    Waveform&
    

"""

%feature("docstring") WaveformObjects::WaveformAtAPointFT::~WaveformAtAPointFT """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    ~WaveformAtAPointFT
    

"""

%feature("docstring") WaveformAtAPointFT::SNR """


  Parameters
  ----------
    const vector<double>& InversePSD
  
  Returns
  -------
    double
    

"""

%feature("docstring") WaveformObjects """
namespace WaveformObjects
=========================
  The collection of objects that define encapsulated Waveform-type objects.
  This includes Waveform, WaveformAtAPoint, WaveformFT, and Waveforms.
  

"""

%feature("docstring") WaveformObjects::Waveform::NModes """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    const unsigned int
    

"""

%feature("docstring") WaveformObjects::WaveformAtAPoint::VarphiRef """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    double&
    

"""

%feature("docstring") WaveformObjects::Waveform::TimeScaleRef """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    string&
    

"""

%feature("docstring") WaveformAtAPointFT::Match """


  Parameters
  ----------
    const WaveformAtAPointFT& B
    const vector<double>& InversePSD
  
  Returns
  -------
    double
    
  Description
  -----------
    The return from ifft is just the bare FFT sum, so we multiply by df to get
    the continuum-analog FT. This is correct because the input data (re,im) are
    the continuum-analog data, rather than just the return from the bare FFT
    sum. See, e.g., Eq. (A.33) [rather than Eq. (A.35)] of
    http://etd.caltech.edu/etd/available/etd-01122009-143851/  




  Parameters
  ----------
    const WaveformAtAPointFT& B
    const string& Detector = 'AdvLIGO_ZeroDet_HighP'
  
  Returns
  -------
    double
    

"""

