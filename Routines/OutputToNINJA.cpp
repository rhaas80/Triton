#include "NumericalRecipes.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Waveform.hpp"
using WaveformObjects::Waveform;
using namespace std;

/// usage: OutputToNINJA <DataFile.dat> <MetadataTemplate.bbh> [Format [ExtractionRadiusString WaveformIdentifier]]
/// 
/// This routine outputs a series of files in `dirname
///   MetadataTemplate.bbh` containing each mode of the data read from
///   DataFile.dat, and appends that information appropriately to the
///   metadata file itself.  The string Format defaults to "MagArg",
///   but may also be "ReIm" for the standard output format of wave
///   extraction (not extrapolation).  However, the only use of this
///   option is to hush the warning that results if the ReIm format is
///   detected.  If the Format is specified, it is also possible to
///   give two other strings, ExtractionRadiusString and
///   WaveformIdentifier.  The first of these is used in the metadata
///   file, after "[ht-ampphi-data]" to give the "extraction-radius"
///   value; the second is used in the waveform name to distinguish it
///   from other waveforms that may then be in the same directory.

int main(int argc, char* argv[]) {
  if(argc!=3 && argc!=4 && argc!=6) {
    cerr << "Expecting two, three, or five arguments; got " << argc-1 << endl;
    throw("Bad arguments");
  }
  
  string DataFileName(argv[1]);
  string MetadataFileName(argv[2]);
  string Format = (argc>3 ? argv[3] : "MagArg");
  string ExtractionRadiusString = (argc>4 ? argv[4] : "");
  string WaveformIdentifier = (argc>5 ? argv[5] : "");
  
  cout << "Reading " << DataFileName << " ... " << flush;
  Waveform W(DataFileName, Format);
  cout << "☺" << endl;
  
  cout << "Writing " << MetadataFileName << " (among others) ... " << flush;
  W.OutputToNINJAFormat(MetadataFileName, ExtractionRadiusString, WaveformIdentifier);
  cout << "☺" << endl;
  
  return 0;
}
