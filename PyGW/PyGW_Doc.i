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
Return a reference to the radius at time index 'Time'.
======================================================
  Parameters
  ----------
    const unsigned int Time
  
  Returns
  -------
    double&
  
  Description
  -----------
    Note that this may return a reference to the sole element of the vector of
    radii, in the case that the radius is constant. Thus, setting the radius at
    different instants of time may simply overwrite that sole value. It would
    be better to use 'RRef()' for that application.
    
    This function is not available via SWIG (e.g., in python).
  

Return a reference to the vector of radii of the measured data.
===============================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    vector<double>&
  
  Description
  -----------
    Note that this vector may contain 0, 1, or NTimes() elements. If 1, the
    radius is assumed to be constant.
    
    This function is not available via SWIG (e.g., in python).
  
"""

%feature("docstring") WaveformObjects::Waveform::NSamplesPerCycle22 """
Resample data such that there are N samples per cycle of the (2,2) mode.
========================================================================
  Parameters
  ----------
    const unsigned int N = 20
  
  Returns
  -------
    Waveform&
  
"""

%feature("docstring") WaveformObjects::Waveform::L """
Return the 'l' (azimuthal) index of mode 'Mode'.
================================================
  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    const int
  
"""

%feature("docstring") WaveformObjects::Waveform::M """
Return the 'm' (magnetic) index of mode 'Mode'.
===============================================
  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    const int
  
"""

%feature("docstring") WaveformObjects::Waveform::TypeIndexRef """
Return a reference to the index for the Type of the data.
=========================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    unsigned int&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  
"""

%feature("docstring") WaveformObjects::Waveform::LMRef """
Return a reference to the (l,m) data of mode 'Mode'.
====================================================
  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    vector<int>&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  

Return a reference to the (l,m) data for all modes.
===================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    Matrix<int>&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  
"""

%feature("docstring") WaveformObjects::Waveform::FrameRef """
Return a reference to the frames in which the data are decomposed at time index 'Time'.
=======================================================================================
  Parameters
  ----------
    const unsigned int Time
  
  Returns
  -------
    Quaternion&
  
  Description
  -----------
    Note that this may return a reference to the sole element of the vector of
    frames, in the case that the frame is constant. Thus, setting the frame at
    different instants of time may simply overwrite that sole value. It would
    be better to use 'FrameRef()' for that application.
    
    This function is not available via SWIG (e.g., in python).
  

Return a reference to the vector of frames in which the data are decomposed.
============================================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    vector<Quaternion>&
  
  Description
  -----------
    Note that this vector may contain 0, 1, or NTimes() elements. If 1, the
    frame is assumed to be constant. If 0, it is constant, and equal to the
    standard frame.
    
    This function is not available via SWIG (e.g., in python).
  
"""

%feature("docstring") WaveformObjects::Waveform::T """
Return the time value at time index 'Time'.
===========================================
  Parameters
  ----------
    const unsigned int Time
  
  Returns
  -------
    const double
  

Return the entire vector of times in the data.
==============================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    const vector<double>&
  
"""

%feature("docstring") WaveformObjects::Waveform::R """
Return the radius of the measured data at time index 'Time'.
============================================================
  Parameters
  ----------
    const unsigned int Time
  
  Returns
  -------
    const double
  

Return the vector of radii of the measured data.
================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    const vector<double>&
  
  Description
  -----------
    Note that this vector may contain 0, 1, or NTimes() elements. If 1, the
    radius is assumed to be constant.
  
"""

%feature("docstring") WaveformObjects::Waveforms::AlignPhases """


  Parameters
  ----------
    const double& AlignmentPoint = 0.5
  
  Returns
  -------
    void
  
"""

%feature("docstring") WaveformObjects::Waveform::Peak22Time """
Return the time at which the (2,2) mode peaks.
==============================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    double
  
"""

%feature("docstring") WaveformObjects::Waveform::SetArg """
Set the argument (phase) of mode 'Mode' at time index 'Time' to the value 'a'.
==============================================================================
  Parameters
  ----------
    const unsigned int Mode
    const unsigned int Time
    const double a
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  

Set the argument (phase) of mode 'Mode' to the input data.
==========================================================
  Parameters
  ----------
    const unsigned int Mode
    const vector<double>& a
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  

Set the argument (phase) of the Waveform to the input data.
===========================================================
  Parameters
  ----------
    const Matrix<double>& a
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  
"""

%feature("docstring") WaveformObjects::Waveform::swap """
Efficiently swap data between two Waveform objects.
===================================================
  Parameters
  ----------
    Waveform& b
  
  Returns
  -------
    void
  
  Description
  -----------
    This function uses the std::vector method 'swap' which simply swaps
    pointers to data, for efficiency.
  
"""

%feature("docstring") WaveformObjects::Waveform::SetT """
Set the time at index 'Time' to value 'a'.
==========================================
  Parameters
  ----------
    const unsigned int Time
    const double a
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  

Set the time vector to the input data.
======================================
  Parameters
  ----------
    const vector<double>& a
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  
"""

%feature("docstring") WaveformAtAPointFT::ZeroAbove """


  Parameters
  ----------
    const double Frequency
  
  Returns
  -------
    WaveformAtAPointFT&
  
"""

%feature("docstring") WaveformObjects::Waveform::SetTimeScale """
Change the Waveform time scale to the input string.
===================================================
  Parameters
  ----------
    const string& NewTimeScale
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  
"""

%feature("docstring") WaveformObjects::Waveform::SetR """
Set the radius at index 'Time' to value 'a'.
============================================
  Parameters
  ----------
    const unsigned int Time
    const double a
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  

Set the radius vector to the input data.
========================================
  Parameters
  ----------
    const vector<double>& a
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  
"""

%feature("docstring") MaximizeMagSum """
class MaximizeMagSum
====================
  Member variables
  ----------------
    const WaveformObjects::Waveform& W
    unsigned int t
    double hRe2Neg2
    double hIm2Neg2
    double hRe2Neg1
    double hIm2Neg1
    double hRe20
    double hIm20
    double hRe21
    double hIm21
    double hRe22
    double hIm22
  
"""

%feature("docstring") WaveformObjects::Waveform::TypeIndex """
Return the index for the Type of the data.
==========================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    const unsigned int
  
  Description
  -----------
    A more useful function might be the 'Type()' function, which returns the
    type as a string.
  
"""

%feature("docstring") WaveformObjects::Waveform::DropLMode """


  Parameters
  ----------
    const int L
  
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

%feature("docstring") WaveformObjects::Waveform::clear """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    void
  
"""

%feature("docstring") MaximizeMagSum::MaximizeMagSum """


  Parameters
  ----------
    const WaveformObjects::Waveform& iW
  
  Returns
  -------
    MaximizeMagSum
  
"""

%feature("docstring") WaveformObjects::Waveform::L2Norm """
Calculate the L2 norm of the data.
==================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    vector<double>
  
"""

%feature("docstring") WaveformObjects::Waveform::operator[] """
Return a copy of the Waveform with only the requested mode.
===========================================================
  Parameters
  ----------
    const unsigned int mode
  
  Returns
  -------
    Waveform
  
  Description
  -----------
    All other data (history, typeIndex, timeScale, t, r, frame) are kept as
    they are. Only the lm, mag, and arg data are reduced to the single mode
    requested.
  
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

%feature("docstring") WaveformObjects::Waveform::Mag """
Return the magnitude of mode 'Mode' at time index 'Time'.
=========================================================
  Parameters
  ----------
    const unsigned int Mode
    const unsigned int Time
  
  Returns
  -------
    const double
  

Return the magnitude of mode 'Mode' as a function of time.
==========================================================
  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    const vector<double>&
  

Return the magnitude of all modes as a function of time.
========================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    const vector<vector<double>>&
  
  Description
  -----------
    The return value is actually a Matrix when called from c++.
  
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

%feature("docstring") WaveformObjects::Waveform::UnfixNonOscillatingData """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
  
"""

%feature("docstring") WaveformUtilities """
namespace WaveformUtilities
===========================
"""

%feature("docstring") WaveformObjects::Waveform::TransformToStationaryFrame """
Transform the Waveform back to a stationary frame.
==================================================
  Parameters
  ----------
    const Quaternion Q = Quaternion(1, 0, 0, 0)
  
  Returns
  -------
    Waveform&
  
  Description
  -----------
    The input quaternion may be used to specify the orientation of the final
    frame relative to the frame in which the Waveform was originally measured.
    Compare `TransformToStandardFrame()`.
  
"""

%feature("docstring") WaveformObjects::Waveforms::Waveforms """
Basic copy constructor.
=======================
  Parameters
  ----------
    const Waveforms& In
  
  Returns
  -------
    Waveforms
  

Nearly-empty constructor of N empty objects.
============================================
  Parameters
  ----------
    const int N = 0
  
  Returns
  -------
    Waveforms
  

Construct from a vector of radii and corresponding data file names.
===================================================================
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
  
  Description
  -----------
    This constructor is used for extrapolation, primarily. The various file
    names are expected to be printf-formatted strings, where each radius is the
    quantity used in the printf statement. Thus, for example, '(100, 110, ...)'
    and 'rPsi4_R04.0fm_U8+.dat' may be input, where the file names are
    'rPsi4_R0100m_U8+.dat', 'rPsi4_R0110m_U8+.dat', etc. The input AreaFile and
    LapseFile are treated similarly.
  

Construct Waveforms from multiple [*-data] .bbh sections.
=========================================================
  Parameters
  ----------
    const string& BBHFileName
    const Matrix<int> LM = Matrix<int>(0, 0)
  
  Returns
  -------
    Waveforms
  

Construct Waveforms from a single [*-data] .bbh section.
========================================================
  Parameters
  ----------
    const vector<string>& BBHDataSection
    const string Dir = ''
    const Matrix<int> LM = Matrix<int>(0, 0)
  
  Returns
  -------
    Waveforms
  
  Description
  -----------
    The resulting set of Waveforms really represents just one Waveform, but
    each mode can have different times. The modes can be re-assembled into a
    single Waveform by calling the Merge() method. That is probably the most
    useful format. This constructor and Merge() are called by the
    Waveform::Waveform constructor having the same arguments as this function.
  
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

%feature("docstring") WaveformObjects::Waveform::AlignPhasesToTwoPi """
Align phases of two Waveforms to within 2*pi at a fractional time in this Waveform of tFrac.
============================================================================================
  Parameters
  ----------
    const Waveform& a
    const double tFrac = 0.25
  
  Returns
  -------
    Waveform&
  
"""

%feature("docstring") WaveformObjects::Waveform::Omega2m2 """
Return the frequency of the (2,-2) mode.
========================================
  Parameters
  ----------
    const double t1 = -1e300
    const double t2 = 1e300
  
  Returns
  -------
    vector<double>
  
  Description
  -----------
    In standard configuration, this quantity will typically be increasing; the
    (2,2) frequency will typically be decreasing because of the definitions of
    h and Psi4 and the definition of the frequency as the derivative of `arg`.
  
"""

%feature("docstring") WaveformObjects::Waveform::TransformToSchmidtFrame """
Transform the Waveform to the naive radiation frame.
====================================================
  Parameters
  ----------
    const double alpha0Guess = 0.0
    const double beta0Guess = 0.0
  
  Returns
  -------
    Waveform&
  
  Description
  -----------
    This function finds the radiation axis, then rotates the coordinates in
    which the physical system is expressed (by calling RotateCoordinates) to
    align with that frame. Note that the rotation in this case always has the
    third Euler angle (gamma) set to 0.
    
    We define the Euler angles (alpha, beta, gamma) using the z-y'-z''
    convention, where the first rotation is through an angle alpha about the z
    axis, the second through beta about the (new) y' axis, and the third
    through gamma about the (new) z'' axis. Note that this is equivalent to
    rotations in the opposite order about the fixed set of axes z-y-z.
    
    See PRD 84, 124011 (2011) for more details.
  
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
  
"""

%feature("docstring") WaveformObjects::Waveform::PeakFluxTimeIndex """
Return the time index at which the GW flux peaks.
=================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    unsigned int
  
"""

%feature("docstring") sign """


  Parameters
  ----------
    const double x
  
  Returns
  -------
    double
  
"""

%feature("docstring") MaximizeMagSum::df """


  Parameters
  ----------
    const vector<double>& x
    vector<double>& dfdx
  
  Returns
  -------
    void
  
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

%feature("docstring") WaveformObjects::Waveform::TransformToStandardFrame """
Transform the Waveform back to the original frame.
==================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
  
  Description
  -----------
    Simply reverses the total rotation given to the Waveform up to this point.
    Assuming all such rotations have been correctly recorded in the Waveform
    object (which should not require any user intervention), this should return
    the Waveform as originally measured in the simulation code's frame, modulo
    any time-regridding, rescaling, etc.
  
"""

%feature("docstring") WaveformObjects::Waveforms::FixNonOscillatingData """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    void
  
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
Append the input string to the Waveform history.
================================================
  Parameters
  ----------
    const string& Hist
  
  Returns
  -------
    void
  
"""

%feature("docstring") WaveformObjects::Waveform::DropBefore """
Delete data from the Waveform occurring at or before the input time.
====================================================================
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
Calculate the GW flux.
======================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    vector<double>
  
  Description
  -----------
    NB: This function can only be used on Waveform data of type `rhdot`. To
    calculate the flux from data of type `rh`, simply apply the Differentiate()
    function first, but remember that that function operates in place, so you
    may wish to make a copy of the Waveform first. For example, you may wish to
    use `Waveform(bla).Differentiate().Flux()`.
    
    Also, if the frame is non-constant, the Waveform is copied, the copy is
    transformed into the original frame, and the flux is calculated for that
    copy.
  
"""

%feature("docstring") MinimalRotation """
Alter gamma to enforce the minimal-rotation condition.
======================================================
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
Interpolate to evenly spaced time axis of size N.
=================================================
  Parameters
  ----------
    const unsigned int N = 200
  
  Returns
  -------
    Waveform&
  
"""

%feature("docstring") WaveformObjects::Waveform::DropAfter """
Delete data from the Waveform occurring after the input time.
=============================================================
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
  

Output single mode of Waveform to file.
=======================================
  Parameters
  ----------
    const string& FileName
    const WaveformObjects::Waveform& a
    const unsigned int Mode
    const unsigned int precision = 14
  
  Returns
  -------
    void
  

Output single mode of Waveform to ostream.
==========================================
  Parameters
  ----------
    ostream& os
    const Waveform& a
    const unsigned int Mode
  
  Returns
  -------
    void
  
  Description
  -----------
    This is intended to be a helper function.
  

Output single mode of Waveform to file.
=======================================
  Parameters
  ----------
    const string& FileName
    const WaveformObjects::Waveform& a
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
Return a reference to the stringstream recording the Waveform's history.
========================================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    stringstream&
  
  Description
  -----------
    Note that the methods 'SetHistory(const std::string& Hist)' and
    'AppendHistory(const std::string& Hist)' are also available.
    
    This function is not available via SWIG (e.g., in python).
  
"""

%feature("docstring") WaveformObjects::Waveform::SetTypeIndex """
Change the Waveform type index to the input int.
================================================
  Parameters
  ----------
    const unsigned int NewTypeIndex
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  
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

%feature("docstring") WaveformAligner::WaveformAligner """


  Parameters
  ----------
    const Waveform& A
    const Waveform& B
    const double t1
    const double t2
  
  Returns
  -------
    WaveformAligner
  
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

%feature("docstring") MaximizeMagSum::operator() """


  Parameters
  ----------
    const vector<double>& x
  
  Returns
  -------
    double
  
"""

%feature("docstring") WaveformAtAPointFT::operator * """


  Parameters
  ----------
    const double b
  
  Returns
  -------
    WaveformAtAPointFT
  
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

%feature("docstring") WaveformObjects::WaveformAtAPoint::VarthetaRef """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    double&
  
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
Transform the Waveform to the minimal-rotation radiation frame.
===============================================================
  Parameters
  ----------
    const double alpha0Guess = 0.0
    const double beta0Guess = 0.0
  
  Returns
  -------
    Waveform&
  
  Description
  -----------
    This function finds the minimal-rotation radiation axis, then rotates the
    coordinates in which the physical system is expressed (by calling
    RotateCoordinates) to align with that frame.
    
    We define the Euler angles (alpha, beta, gamma) using the z-y'-z''
    convention, where the first rotation is through an angle alpha about the z
    axis, the second through beta about the (new) y' axis, and the third
    through gamma about the (new) z'' axis. Note that this is equivalent to
    rotations in the opposite order about the fixed set of axes z-y-z.
    
    See PRD 84, 124011 (2011) for more details.
  
"""

%feature("docstring") WaveformObjects::Waveform::AddToTime """
Simply add the input constant to the time data of the Waveform.
===============================================================
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

%feature("docstring") WaveformObjects::Waveform::DropZeroMModes """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
  
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
Subtract Waveforms and normalize.
=================================
  Parameters
  ----------
    const Waveform& b
  
  Returns
  -------
    Waveform
  
  Description
  -----------
    The two Waveforms are interpolated onto their intersection, then the second
    is subtracted from this Waveform, and the difference in magnitudes is
    normalized by the magnitude of the second Waveform. The two Waveforms are
    assumed to have identical (l,m) modes, and any alignment should be done
    before calling this function.
  
"""

%feature("docstring") WaveformObjects::Waveform::FindModeIndex """
Find index of mode with given (l,m) data.
=========================================
  Parameters
  ----------
    const int L
    const int M
  
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
    vector<string> Types
    stringstream history
    unsigned int typeIndex
    string timeScale
    vector<double> t
    vector<double> r
    vector<Quaternion> frame
    Matrix<int> lm
    Matrix<double> mag
    Matrix<double> arg
  
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
Set contents of this Waveform equal to the contents of another.
===============================================================
  Parameters
  ----------
    const Waveform& b
  
  Returns
  -------
    Waveform&
  
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
Return a string containing the history of the Waveform.
=======================================================
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
Return a reference to the argument (phase) of mode 'Mode' at time index 'Time'.
===============================================================================
  Parameters
  ----------
    const unsigned int Mode
    const unsigned int Time
  
  Returns
  -------
    double&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  

Return a reference to the argument (phase) of mode 'Mode' as a function of time.
================================================================================
  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    vector<double>&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  

Return a reference to the argument (phase) of all modes as a function of time.
==============================================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    Matrix<double>&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  
"""

%feature("docstring") WaveformObjects::Waveform::Differentiate """
Differentiate the Waveform.
===========================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
  
  Description
  -----------
    Most useful for finding the Flux, or (when used twice) for comparing h to
    Psi4.
    
    This function only works on data of type h or hdot (or multiples thereof).
    In particular, the code does not know what data type Psi4 should be after
    being differentiated.
    
    Also note that if the Waveform is in a rotating frame, the data is first
    transformed to a stationary frame, then differentiated, then transformed
    back into the original rotating frame.
  
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

%feature("docstring") WaveformObjects::WaveformAtAPoint::~WaveformAtAPoint """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    ~WaveformAtAPoint
  
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
    stringstream history
    vector<Waveform> Ws
    bool CommonTimeSet
    bool PhasesAligned
  
"""

%feature("docstring") WaveformObjects::Waveforms::SetCommonTime """


  Parameters
  ----------
    const double& MinStep = 0.005
    const double& MinTime = 0.0
  
  Returns
  -------
    void
  
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
Replace the Waveform history with the input string.
===================================================
  Parameters
  ----------
    const string& Hist
  
  Returns
  -------
    void
  
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
Return a string describing the Type of the data.
================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    const string
  
"""

%feature("docstring") WaveformAligner """
class WaveformAligner
=====================
  Member variables
  ----------------
    const Waveform& a
    const Waveform b
    vector<double> t
    vector<double> arga
    int LMa
    int LMb
  
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

%feature("docstring") WaveformObjects::Waveform::Frame """
Return a quaternion describing the frame in which the data are decomposed at time index 'Time'.
===============================================================================================
  Parameters
  ----------
    const unsigned int Time
  
  Returns
  -------
    const Quaternion&
  

Return the entire vector of frames in which the data are decomposed.
====================================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    const vector<Quaternion>&
  
  Description
  -----------
    Note that this vector may contain 0, 1, or NTimes() elements. If 1, the
    frame is assumed to be constant. If 0, it is constant, and equal to the
    standard frame.
  
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
  

Rotate all modes by the given quaternion.
=========================================
  Parameters
  ----------
    const Quaternion& Q
  
  Returns
  -------
    Waveform&
  
  Description
  -----------
    This rotates the coordinates, leaving the physical system in place -- which
    is just the opposite rotation compared to RotatePhysicalSystem. One way of
    thinking about this is that the zHat axis is rotated to the point
    Q*zHat*Qbar, while the physical point that was located there is left in
    place. In the new coordinates, that physical point is at Qbar*zHat*Q.
  

Rotate all modes by the given quaternion data.
==============================================
  Parameters
  ----------
    const vector<Quaternion>& Q
  
  Returns
  -------
    Waveform&
  
  Description
  -----------
    This rotates the coordinates, leaving the physical system in place -- which
    is just the opposite rotation compared to RotatePhysicalSystem. One way of
    thinking about this is that the zHat axis is rotated to the point
    Q*zHat*Qbar, while the physical point that was located there is left in
    place. In the new coordinates, that physical point is at Qbar*zHat*Q.
  
"""

%feature("docstring") WaveformObjects::Waveforms::Merge """


  Parameters
  ----------
    const double& MinStep = 0.0
    const double& MinTime = 0.0
  
  Returns
  -------
    Waveform
  
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
Return the (l,m) indices of mode 'Mode'.
========================================
  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    const vector<int>&
  

Return the (l,m) data for all modes.
====================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    const vector<vector<int>>&
  
  Description
  -----------
    The return value is actually a Matrix when called from c++.
  
"""

%feature("docstring") WaveformObjects::Waveform::MRef """
Return a reference to the m (magnetic) index of mode 'Mode'.
============================================================
  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    int&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  
"""

%feature("docstring") WaveformObjects::WaveformAtAPoint::VarphiRef """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    double&
  
"""

%feature("docstring") WaveformObjects::Waveforms::Extrapolate """


  Parameters
  ----------
    const int ExtrapolationOrder = 5
  
  Returns
  -------
    Waveform
  
"""

%feature("docstring") WaveformObjects::Waveform::TRef """
Return a reference.
===================
  Parameters
  ----------
    const unsigned int Time
  
  Returns
  -------
    double&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  

Return a reference to the entire vector of times in the data.
=============================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    vector<double>&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  
"""

%feature("docstring") WaveformObjects::Waveform::SetLM """
Set the (l,m) data of mode 'Mode' to the input data.
====================================================
  Parameters
  ----------
    const unsigned int Mode
    const vector<int>& a
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  

Set the (l,m) data to the input data.
=====================================
  Parameters
  ----------
    const Matrix<int>& a
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  
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
  

Construct Waveform from data file.
==================================
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
  

Construct a single Waveform from a .bbh or .minimal file.
=========================================================
  Parameters
  ----------
    const string& BBHFileName
    int SectionToUse = 0
    const Matrix<int> LM = Matrix<int>(0, 0)
  
  Returns
  -------
    Waveform
  

Construct a single Waveform from a [*-data] bbh section.
========================================================
  Parameters
  ----------
    const vector<string>& BBHDataSection
    const string Dir = ''
    const Matrix<int> LM = Matrix<int>(0, 0)
  
  Returns
  -------
    Waveform
  
  Description
  -----------
    The section is passed as a vector of strings, each element of which
    contains the 'l,m = path' line from a metadata file.
  

Simple PN/EOB constructor for non-precessing systems.
=====================================================
  Parameters
  ----------
    const string& Approximant
      ('TaylorT1'|'TaylorT2'|'TaylorT3'|'TaylorT4'|'EOB')
    const double delta
      $\\delta = (M_1 - M_2) / (M_2 + M_2)$
    const double chis
      $\\chi_s = (\\chi_1+\\chi_2)/2$
    const double chia
      $\\chi_a = (\\chi_1-\\chi_2)/2$
    const double v0
      Initial Newtonian velocity: $v = \\left( \\frac{G\\, M\\, \\Omega}{c^3}
      \\right)^{1/3}$
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
    
    The total number of modes required for $L$ is given by \\begin{align}{ ///
    N_{\\text{modes}} ///&= \\sum_{l=2}^{L} (2l+1) \\\\ ///&= 2\\left[L\\,
    (L-1)/2-1\\right] + (L-2) \\\\ ///&= (L+3)\\, (L-1) /// \\end{align}
  

PN/EOB constructor for precessing systems.
==========================================
  Parameters
  ----------
    const string& Approximant
      ('TaylorT4Spin')
    const double delta
      $\\delta = (M_1 - M_2) / (M_2 + M_2)$
    const vector<double>& chi1
      $\\vec{\\chi}_1 = \\vec{S}_1 / M_1^2$
    const vector<double>& chi2
      $\\vec{\\chi}_2 = \\vec{S}_2 / M_2^2$
    const double v0
      Initial Newtonian velocity: $v = \\left( \\frac{G\\, M\\, \\Omega}{c^3}
      \\right)^{1/3}$
    vector<double>& alpha
      Returns vector containing $\\alpha$ coordinates of frame rotation
    vector<double>& beta
      Returns vector containing $\\beta$ coordinates of frame rotation
    vector<double>& gamma
      Returns vector containing $\\gamma$ coordinates of frame rotation
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

%feature("docstring") WaveformObjects::Waveforms::size """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    unsigned int
  
"""

%feature("docstring") WaveformObjects::Waveform::UniformTimeToPowerOfTwo """
Interpolate to evenly spaced time axis with size 2^n for integer n.
===================================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    Waveform&
  
  Description
  -----------
    This function is useful for interpolating the data to a time series
    appropriate for FFTing. The size of the output is the smallest 2^n that is
    larger than the current size of the data.
  
"""

%feature("docstring") WaveformObjects::Waveform::SetTotalMassToOne """


  Parameters
  ----------
    const double TotalMassInCurrentUnits
  
  Returns
  -------
    Waveform&
  
"""

%feature("docstring") WaveformObjects::Waveform::SetFrame """
Set the frame at index 'Time' to the value 'a'.
===============================================
  Parameters
  ----------
    const unsigned int Time
    const Quaternion& a
  
  Returns
  -------
    void
  
  Description
  -----------
    Note that no transformation of the modes is done by this function.
    
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  

Set the frame to the input data.
================================
  Parameters
  ----------
    const vector<Quaternion>& a
  
  Returns
  -------
    void
  
  Description
  -----------
    Note that no transformation of the modes is done by this function.
    
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  
"""

%feature("docstring") WaveformAligner::operator() """


  Parameters
  ----------
    const double dt
  
  Returns
  -------
    double
  
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
Check various data for NaNs.
============================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    bool
  
"""

%feature("docstring") WaveformObjects::Waveform::MagRef """
Return a reference to the magnitude of mode 'Mode' at time index 'Time'.
========================================================================
  Parameters
  ----------
    const unsigned int Mode
    const unsigned int Time
  
  Returns
  -------
    double&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  

Return a reference to the magnitude of mode 'Mode' as a function of time.
=========================================================================
  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    vector<double>&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  

Return a reference to the magnitude of all modes as a function of time.
=======================================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    Matrix<double>&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  
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

%feature("docstring") WaveformObjects::Waveform::SetMag """
Set the magnitude of mode 'Mode' at time index 'Time' to the value 'a'.
=======================================================================
  Parameters
  ----------
    const unsigned int Mode
    const unsigned int Time
    const double a
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  

Set the magnitude of mode 'Mode' to the input data.
===================================================
  Parameters
  ----------
    const unsigned int Mode
    const vector<double>& a
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  

Set the magnitude of the Waveform to the input data.
====================================================
  Parameters
  ----------
    const Matrix<double>& a
  
  Returns
  -------
    void
  
  Description
  -----------
    This function is only available via SWIG (e.g., python), not c++. In c++,
    use the reference method.
  
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
Set magnitude to zero for data at or before the input time.
===========================================================
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
Return a reference to the l (azimuthal) index of mode 'Mode'.
=============================================================
  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    int&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  
"""

%feature("docstring") WaveformObjects::Waveform::RotatePhysicalSystem """
Rotate all modes by the given Euler angles.
===========================================
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
  

Rotate all modes by the given quaternion data.
==============================================
  Parameters
  ----------
    const Quaternion& Q
  
  Returns
  -------
    Waveform&
  
  Description
  -----------
    This rotates the physical system, leaving the coordinates in place -- which
    is just the opposite rotation compared to RotateCoordinates. One way of
    thinking about this is that whatever physical point is at the tip of the
    zHat axis is rotated to the point Q*zHat*Qbar.
  

Rotate all modes by the given quaternion data.
==============================================
  Parameters
  ----------
    const vector<Quaternion>& Q
  
  Returns
  -------
    Waveform&
  
  Description
  -----------
    This rotates the physical system, leaving the coordinates in place -- which
    is just the opposite rotation compared to RotateCoordinates. One way of
    thinking about this is that whatever physical point is at the tip of the
    zHat axis is rotated to the point Q*zHat*Qbar.
  
"""

%feature("docstring") sqr """


  Parameters
  ----------
    const double t
  
  Returns
  -------
    double
  
"""

%feature("docstring") WaveformObjects::Waveform::Arg """
Return the argument (phase) of mode 'Mode' at time index 'Time'.
================================================================
  Parameters
  ----------
    const unsigned int Mode
    const unsigned int Time
  
  Returns
  -------
    const double
  

Return the argument (phase) of mode 'Mode' as a function of time.
=================================================================
  Parameters
  ----------
    const unsigned int Mode
  
  Returns
  -------
    const vector<double>&
  

Return the argument (phase) of all modes as a function of time.
===============================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    const vector<vector<double>>&
  
  Description
  -----------
    The return value is actually a Matrix when called from c++.
  
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
Return a string describing the time scale (e.g., units).
========================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    const string
  
"""

%feature("docstring") WaveformObjects::Waveform::Peak22TimeIndex """
Return the time index at which the (2,2) mode peaks.
====================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    unsigned int
  
"""

%feature("docstring") MaximizeMagSum::SetT """


  Parameters
  ----------
    const unsigned int T
  
  Returns
  -------
    void
  
"""

%feature("docstring") Output """
Output Waveform to file.
========================
  Parameters
  ----------
    const string& FileName
    const WaveformObjects::Waveform& a
    const unsigned int precision = 14
  
  Returns
  -------
    void
  

Output Waveform to file.
========================
  Parameters
  ----------
    const string& FileName
    const WaveformObjects::Waveform& a
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
Return the number of modes in the data.
=======================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    const unsigned int
  
"""

%feature("docstring") WaveformObjects::Waveform::NTimes """
Return the number of time steps in the data.
============================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    const unsigned int
  
"""

%feature("docstring") WaveformObjects::Waveform::TimeScaleRef """
Return a reference to the string describing the time scale (e.g., units).
=========================================================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    string&
  
  Description
  -----------
    This function is not available via SWIG (e.g., in python).
  
"""

%feature("docstring") WaveformObjects::Waveform::PeakFluxTime """
Return the time at which the GW flux peaks.
===========================================
  Parameters
  ----------
    (none)
  
  Returns
  -------
    double
  
"""

%feature("docstring") WaveformAligner::darg """


  Parameters
  ----------
    const double dt
    const unsigned int mode
  
  Returns
  -------
    double
  
"""

%feature("docstring") WaveformAligner::LM_a """


  Parameters
  ----------
    (none)
  
  Returns
  -------
    int
  
"""

