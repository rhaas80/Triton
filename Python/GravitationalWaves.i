// -*- c++ -*-

%module GravitationalWaves
%{
  #define SWIG_FILE_WITH_INIT
  // Includes the header in the wrapper code
  #include "../Objects/Waveform.hpp"
%}

%include numpy.i

%init %{
  import_array();
%}

// Make sure std strings and vectors are dealt with appropriately
%include "std_string.i"
%include "std_vector.i"
%apply const std::string& {std::string* foo};
namespace std {
   %template(vectori) vector<int>;
   %template(vectord) vector<double>;
   %template(vectorvectord) vector<vector<double> >;
   %template(vectors) vector<string>;
};

// Try to handle Matrix objects as numpy arrays
%ignore WaveformUtilities::Matrix::operator=;
%ignore WaveformUtilities::Matrix::operator[];

  %typemap(out) matrixd { // From C++ to python
    $result = numpy.empty($1.nrows(), $1.ncols());
    for(unsigned int i=0; i<$1.nrows(); ++i) {
      for(unsigned int j=0; j<$1.ncols(); ++j) {
	$result[i][j] = $1[i][j];
      }
    }
  }

%include "../Utilities/Matrix.hpp"
namespace WaveformUtilities {
  %template(matrixd) Matrix<double>;
  %template(matrixi) Matrix<int>;
//   //  #if defined(SWIGPYTHON)
//   %typemap(out) Matrix { // From C++ to python
//     $result = numpy.empty($1.nrows(), $1.ncols());
//     for(unsigned int i=0; i<$1.nrows(); ++i) {
//       for(unsigned int j=0; j<$1.ncols(); ++j) {
// 	$result[i][j] = $1[i][j];
//       }
//     }
//   }
//   %typemap(in) Matrix<double> { // From python to C++
//     $1 = Matrix<double>($input.nrows(), $input.ncols());
//     for(unsigned int i=0; i<$1.nrows(); ++i) {
//       for(unsigned int j=0; j<$1.ncols(); ++j) {
// 	$1[i][j] = $input[i][j];
//       }
//     }
//   }
//   %typemap(memberin) Matrix<double> { // From python to C++
//     $1 = Matrix<double>($input.nrows(), $input.ncols());
//     for(unsigned int i=0; i<$1.nrows(); ++i) {
//       for(unsigned int j=0; j<$1.ncols(); ++j) {
// 	$1[i][j] = $input[i][j];
//       }
//     }
//   }
//   //  #else
//   //    #warning no "in" typemap defined for Matrix objects
//   //  #endif

}


// Ignore things that don't translate well...
%ignore WaveformObjects::Waveform::operator=;
%ignore WaveformObjects::Waveform::operator[];
%ignore operator<<;
%ignore WaveformObjects::Waveform::History();

// ...and rename things that do
%rename(__divide__) WaveformObjects::Waveform::operator/;

/////////////////////////////////////////////////////////////////////////
// Ignore some getty/setty functions that will be better defined below //
/////////////////////////////////////////////////////////////////////////
// const unsigned int WaveformObjects::Waveform::NTimes() const;
// const unsigned int WaveformObjects::Waveform::NModes() const;
// const unsigned int WaveformObjects::Waveform::TypeIndex() const;
// const std::string WaveformObjects::Waveform::HistoryStr() const;
// const std::string WaveformObjects::Waveform::TimeScale() const;
// const std::string WaveformObjects::Waveform::Type() const;
// const double WaveformObjects::Waveform::T(const unsigned int Time) const;
// const double WaveformObjects::Waveform::R(const unsigned int Time) const;
// const double WaveformObjects::Waveform::Mag(const unsigned int Mode, const unsigned int Time) const;
// const double WaveformObjects::Waveform::Arg(const unsigned int Mode, const unsigned int Time) const;
//const std::vector<double>& WaveformObjects::Waveform::T() const;
%ignore WaveformObjects::Waveform::T() const; // TODO
//const std::vector<double>& WaveformObjects::Waveform::R() const;
%ignore WaveformObjects::Waveform::R() const; // TODO
// const int& WaveformObjects::Waveform::L(const unsigned int Mode) const;
// const int& WaveformObjects::Waveform::M(const unsigned int Mode) const;
//const std::vector<int>& WaveformObjects::Waveform::LM(const unsigned int Mode) const;
%ignore WaveformObjects::Waveform::LM(const unsigned int Mode) const; // TODO
//const std::vector<double>& WaveformObjects::Waveform::Mag(const unsigned int Mode) const;
%ignore WaveformObjects::Waveform::Mag(const unsigned int Mode) const; // TODO
//const std::vector<double>& WaveformObjects::Waveform::Arg(const unsigned int Mode) const;
%ignore WaveformObjects::Waveform::Arg(const unsigned int Mode) const; // TODO
//const WaveformUtilities::Matrix<int>& WaveformObjects::Waveform::LM() const;
%ignore WaveformObjects::Waveform::LM() const;
//const WaveformUtilities::Matrix<double>& WaveformObjects::Waveform::Mag() const;
%ignore WaveformObjects::Waveform::Mag() const; // TODO
//const WaveformUtilities::Matrix<double>& WaveformObjects::Waveform::Arg() const;
%ignore WaveformObjects::Waveform::Arg() const; // TODO
// unsigned int& WaveformObjects::Waveform::TypeIndexRef();
// void WaveformObjects::Waveform::SetHistory(const std::string& Hist);
// void WaveformObjects::Waveform::AppendHistory(const std::string& Hist);
//std::stringstream& WaveformObjects::Waveform::History();
%ignore WaveformObjects::Waveform::History(); // and don't redefine
// std::string& WaveformObjects::Waveform::TimeScaleRef();
// double& WaveformObjects::Waveform::TRef(const unsigned int Time);
// double& WaveformObjects::Waveform::RRef(const unsigned int Time);
// double& WaveformObjects::Waveform::MagRef(const unsigned int Mode, const unsigned int Time);
// double& WaveformObjects::Waveform::ArgRef(const unsigned int Mode, const unsigned int Time);
//std::vector<double>& WaveformObjects::Waveform::TRef();
%ignore WaveformObjects::Waveform::TRef(); // DONE
//std::vector<double>& WaveformObjects::Waveform::RRef();
%ignore WaveformObjects::Waveform::RRef(); // DONE
// int& WaveformObjects::Waveform::LRef(const unsigned int Mode);
// int& WaveformObjects::Waveform::MRef(const unsigned int Mode);
//std::vector<int>& WaveformObjects::Waveform::LMRef(const unsigned int Mode);
%ignore WaveformObjects::Waveform::LMRef(const unsigned int Mode); // DONE
//std::vector<double>& WaveformObjects::Waveform::MagRef(const unsigned int Mode);
%ignore WaveformObjects::Waveform::MagRef(const unsigned int Mode); // DONE
//std::vector<double>& WaveformObjects::Waveform::ArgRef(const unsigned int Mode);
%ignore WaveformObjects::Waveform::ArgRef(const unsigned int Mode); // DONE
//WaveformUtilities::Matrix<int>& WaveformObjects::Waveform::LMRef();
%ignore WaveformObjects::Waveform::LMRef(); // TODOish
//WaveformUtilities::Matrix<double>& WaveformObjects::Waveform::MagRef();
%ignore WaveformObjects::Waveform::MagRef(); // TODOish
//WaveformUtilities::Matrix<double>& WaveformObjects::Waveform::ArgRef();
%ignore WaveformObjects::Waveform::ArgRef(); // TODOish


// Translate to numpy arrays
%apply (double** ARGOUTVIEW_ARRAY2, int *DIM1, int *DIM2) {(double** mat, int* nrows, int* ncols)}
%apply (int** ARGOUTVIEW_ARRAY2, int *DIM1, int *DIM2) {(int** matint, int* nrows, int* ncols)}
%apply (double** ARGOUTVIEW_ARRAY1, int *DIM1) {(double** vec, int* n)}
%apply (int** ARGOUTVIEW_ARRAY1, int *DIM1) {(int** vecint, int* n)}

// Parse the header file to generate wrappers
%include "../Objects/Waveform.hpp"

%extend WaveformObjects::Waveform {
  void TRef(double** vec, int *n) {
    *vec = &($self->TRef(0));
    *n = $self->NTimes();
    return;
  }
  void RRef(double** vec, int *n) {
    *vec = &($self->RRef(0));
    *n = $self->RRef().size();
    return;
  }
  void LMRef(const unsigned int Mode, int** vecint, int* n) {
    *vecint = &($self->LRef(Mode));
    *n = $self->LMRef(Mode).size(); // This should be 2
    return;
  }
  void MagRef(const unsigned int Mode, double** vec, int* n) {
    *vec = &($self->MagRef(Mode,0));
    *n = $self->MagRef(Mode).size(); // This should equal NTimes()
    return;
  }
  void ArgRef(const unsigned int Mode, double** vec, int* n) {
    *vec = &($self->ArgRef(Mode,0));
    *n = $self->ArgRef(Mode).size(); // This should equal NTimes()
    return;
  }
  void LMRef(int** matint, int* nrows, int* ncols) {
    *matint = &($self->LRef(0));
    *nrows = $self->LMRef().nrows(); // This should equal NModes()
    *ncols = $self->LMRef().ncols(); // This should be 2
    return;
  }
  void MagRef(double** mat, int* nrows, int* ncols) {
    *mat = &($self->MagRef(0,0));
    *nrows = $self->MagRef().nrows(); // This should equal NTimes()
    *nrows = $self->MagRef().ncols(); // This should equal NModes()
    return;
  }
  void ArgRef(double** mat, int* nrows, int* ncols) {
    *mat = &($self->ArgRef(0,0));
    *nrows = $self->ArgRef().nrows(); // This should equal NTimes()
    *ncols = $self->ArgRef().ncols(); // This should equal NModes()
    return;
  }
 };
