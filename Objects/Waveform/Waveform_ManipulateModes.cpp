#include "NumericalRecipes.hpp"

#include <unistd.h>
#include <sys/param.h>

#include <fstream>

#include "../Waveform.hpp"

#include "Interpolate.hpp"
#include "Minimize.hpp"
#include "FileIO.hpp"
#include "SWSHs.hpp"
#include "EasyParser.hpp"
#include "VectorFunctions.hpp"
#include "Utilities.hpp"
#include "Units.hpp"
#include "PostNewtonian.hpp"
#include "WignerDMatrix.hpp"
#include "Quaternions.hpp"

using namespace WaveformUtilities;
using namespace WaveformObjects;
using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::flush;
using std::endl;
using std::setprecision;
using std::stringstream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::min;
using std::max;
using std::ios_base;


Waveform& WaveformObjects::Waveform::DropLMode(const int L) {
  History() << "### this->DropLMode(" << L << ");" << endl;
  vector<vector<double> >::iterator magrit=MagRef().RawData().end();
  vector<vector<double> >::iterator argrit=ArgRef().RawData().end();
  vector<vector<int> >::iterator LMrit=LMRef().RawData().end();
  magrit--;
  argrit--;
  LMrit--;
  //ORIENTATION!!! following loop
  while(LMrit >= LMRef().RawData().begin()) {
    if((*LMrit)[0]==L) {
      MagRef().RawData().erase(magrit);
      ArgRef().RawData().erase(argrit);
      LMRef().RawData().erase(LMrit);
    }
    magrit--;
    argrit--;
    LMrit--;
  }
  return *this;
}

Waveform& WaveformObjects::Waveform::DropLMMode(const int L, const int M) {
  History() << "### this->DropLMMode(" << L << ", " << M << ");" << endl;
  vector<vector<double> >::iterator magrit=MagRef().RawData().end();
  vector<vector<double> >::iterator argrit=ArgRef().RawData().end();
  vector<vector<int> >::iterator LMrit=LMRef().RawData().end();
  magrit--;
  argrit--;
  LMrit--;
  while(LMrit >= LMRef().RawData().begin()) {
    //ORIENTATION!!! following if statements
    if((*LMrit)[0]==L && (((*LMrit)[1]==M) || ((*LMrit)[1]==-M))) {
      MagRef().RawData().erase(magrit);
      ArgRef().RawData().erase(argrit);
      LMRef().RawData().erase(LMrit);
    }
    magrit--;
    argrit--;
    LMrit--;
  }
  return *this;
}

Waveform& WaveformObjects::Waveform::DropOddMModes() {
  History() << "### this->DropOddMModes();" << endl;
  vector<vector<double> >::iterator magrit=MagRef().RawData().end();
  vector<vector<double> >::iterator argrit=ArgRef().RawData().end();
  vector<vector<int> >::iterator LMrit=LMRef().RawData().end();
  magrit--;
  argrit--;
  LMrit--;
  //ORIENTATION!!! following loop
  while(LMrit >= LMRef().RawData().begin()) {
    if((*LMrit)[1]%2!=0) {
      MagRef().RawData().erase(magrit);
      ArgRef().RawData().erase(argrit);
      LMRef().RawData().erase(LMrit);
    }
    magrit--;
    argrit--;
    LMrit--;
  }
  return *this;
}

Waveform& WaveformObjects::Waveform::DropZeroMModes() {
  History() << "### this->DropZeroMModes();" << endl;
  vector<vector<double> >::iterator magrit=MagRef().RawData().end();
  vector<vector<double> >::iterator argrit=ArgRef().RawData().end();
  vector<vector<int> >::iterator LMrit=LMRef().RawData().end();
  magrit--;
  argrit--;
  LMrit--;
  //ORIENTATION!!! following loop
  while(LMrit >= LMRef().RawData().begin()) {
    if((*LMrit)[1]==0) {
      MagRef().RawData().erase(magrit);
      ArgRef().RawData().erase(argrit);
      LMRef().RawData().erase(LMrit);
    }
    magrit--;
    argrit--;
    LMrit--;
  }
  return *this;
}

Waveform& WaveformObjects::Waveform::DropNegativeMModes() {
  History() << "### this->DropNegativeMModes();" << endl;
  vector<vector<double> >::iterator magrit=MagRef().RawData().end();
  vector<vector<double> >::iterator argrit=ArgRef().RawData().end();
  vector<vector<int> >::iterator LMrit=LMRef().RawData().end();
  magrit--;
  argrit--;
  LMrit--;
  //ORIENTATION!!! following loop
  while(LMrit >= LMRef().RawData().begin()) {
    if((*LMrit)[1]<0) {
      MagRef().RawData().erase(magrit);
      ArgRef().RawData().erase(argrit);
      LMRef().RawData().erase(LMrit);
    }
    magrit--;
    argrit--;
    LMrit--;
  }
  return *this;
}

Waveform& WaveformObjects::Waveform::Conjugate() {
  ArgRef() *= -1.0;
  return *this;
}

Waveform& WaveformObjects::Waveform::HackOddLPlusM() {
  History() << "### this->HackOddLPlusM();" << endl;
  cerr << "\n\nWARNING!  Hacking modes with odd l+m to fix bad RWZ extraction.\n" << endl;
  for(unsigned int mode=0; mode<NModes(); ++mode) {
    if((L(mode)+M(mode)) % 2 != 0) {
      ArgRef(mode) += M_PI;
    }
  }
  return *this;
}


// Convert (mag,arg) to (re,im) for, e.g., m=0 modes
Waveform& WaveformObjects::Waveform::FixNonOscillatingData() {
  History() << "### this->FixNonOscillatingData();" << endl;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<NModes(); ++i) { // Loop over components
    if(M(i)==0) {
      vector<double> Im = Mag(i) * sin(Arg(i));
      MagRef(i) = Mag(i) * cos(Arg(i));
      ArgRef(i) = Im;
    }
  }
  return *this;
}

Waveform& WaveformObjects::Waveform::UnfixNonOscillatingData() {
  History() << "### this->UnfixNonOscillatingData();" << endl;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<NModes(); ++i) { // Loop over components
    if(M(i)==0) {
      vector<double> Re = Mag(i);
      vector<double> Im = Arg(i);
      MagArg(Re, Im, MagRef(i), ArgRef(i));
    }
  }
  return *this;
}

Waveform& WaveformObjects::Waveform::ConvertReImToMagArg() {
  History() << "### this->ConvertReImToMagArg();" << endl;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<NModes(); ++i) { // Loop over components
    vector<double> Re = Mag(i);
    vector<double> Im = Arg(i);
    MagArg(Re, Im, MagRef(i), ArgRef(i));
  }
  return *this;
}

Waveform& WaveformObjects::Waveform::ConvertMagArgToReIm() {
  History() << "### this->ConvertMagArgToReIm();" << endl;
  //ORIENTATION!!! following loop
  for(unsigned int i=0; i<NModes(); ++i) { // Loop over components
    const vector<double> Im = Mag(i) * sin(Arg(i));
    MagRef(i) = Mag(i) * cos(Arg(i));
    ArgRef(i) = Im;
  }
  return *this;
}
