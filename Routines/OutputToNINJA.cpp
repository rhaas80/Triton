#include "NumericalRecipes.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Waveform.hpp"
using WaveformObjects::Waveform;
using namespace std;

/// usage: OutputToNINJA <DataFile.dat> <MetadataTemplate.bbh> [Format]

/// This routine outputs a series of files in `dirname
///   MetadataTemplate.bbh` containing each mode of the data read from
///   DataFile.dat, and appends that information appropriately to the
///   metadata file itself.  The string Format defaults to "MagArg",
///   but may also be "ReIm" for the standard output format of wave
///   extraction (not extrapolation).  However, the only use of this
///   option is to hush the warning that results if the ReIm format is
///   detected.

int main(int argc, char* argv[]) {
  if(argc<3 || argc>4) {
    cerr << "Expecting two or three arguments; got " << argc-1 << endl;
    throw("Bad arguments");
  }
  
  string DataFileName(argv[1]);
  string Format = (argc>3 ? argv[3] : "MagArg");
  string MetadataFileName(argv[2]);
  
  cout << "Reading " << DataFileName << " ... " << flush;
  Waveform W(DataFileName, Format);
  cout << "☺" << endl;
  
  cout << "Writing " << MetadataFileName << " (among others) ... " << flush;
  W.OutputToNINJAFormat(MetadataFileName);
  cout << "☺" << endl;
  
  return 0;
}
