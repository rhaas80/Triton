#include "NumericalRecipes.hpp"

#include <fstream>
#include <iomanip>

#include "WaveformAtAPointFT.hpp"
#include "NoiseCurves.hpp"
#include "VectorFunctions.hpp"

using namespace WaveformUtilities;
using namespace WaveformObjects;
using namespace std;

int main() {
  const unsigned int SamplesPerCycle22 = 20;

  cout << "Reading waveform ... " << flush;
  const Waveform Full("Inputs/rhOverM_ExtrapolatedN5.dat", "MagArg");
  cout << "☺" << endl;

  cout << "Shortening waveform ... " << flush;
  Waveform Short = Full;
  Short.NSamplesPerCycle22(SamplesPerCycle22);
  cout << "☺" << endl;

  cout << "The old waveform had " << Full.NTimes() << " points; the new Waveform has " << Short.NTimes() << endl;

  cout << "Writing waveform ... " << flush;
  Output("Outputs/TestNSamplesPerCycle22.dat", Short);
  cout << "☺" << endl;

  return 0;
}
