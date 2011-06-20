#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cmath>

#include "WaveformAtAPoint.hpp"
#include "EasyParser.hpp"
#include "VectorFunctions.hpp"

using namespace std;

#define throw(message) \
{printf("ERROR: %s\n\tin file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}

int BufferSize = 1000;

int main (void) {
  //// Set up input parameters
  string DataIn  = "rPsi4_R100m_U8+.dat";
  string DataOut = "rPsi4_R100m_Theta%0.4f_Phi%0.4f.dat";
  double Theta = 0.0;
  double Phi = 0.0;
  
  //// Parse the input options
  string Option(""), Options("");
  vector<string> Keys, Values;
  while(getline(cin, Option)) {
    Options += Option + '\n';
  }
  SplitStringToKeysAndValues(Options, Keys, Values);
  for(unsigned int i=0; i<Keys.size(); ++i) {
    if(Keys[i].compare("DataIn")==0) {
      DataIn = Values[i];
    } else if(Keys[i].compare("DataOut")==0) {
      DataOut = Values[i];
    } else if(Keys[i].compare("Theta")==0) {
      Theta = StringToDouble(Values[i]);
    } else if(Keys[i].compare("Phi")==0) {
      Phi = StringToDouble(Values[i]);
    } else {
      throw(("Unknown key " + Keys[i] + ".\n").c_str());
    }
  }
  
  //// Read and convert the data
  WaveformAtAPoint W;
  {
    cerr << "Warning: Assuming 'ReIm' format for the data" << endl;
    cout << "Reading " << DataIn << "... " << flush;
    Waveform WIn(DataIn);
    cout << "☺" << endl;
    W = WaveformAtAPoint(WIn, Theta, Phi);
  }
  
  //// Output the data
  char Buffer[BufferSize];
  sprintf(Buffer, DataOut.c_str(), Theta, Phi);
  cout << "Writing " << string(Buffer) << "... " << flush;
  ofstream ofs(Buffer, ofstream::out);
  ofs << setprecision(14) << flush;
  ofs << "# [1] = T (KiPS)" << endl;
  ofs << "# [2] = Re{" << Waveform::Types[W.Type] << "(Theta=" << Theta << ", Phi=" << Phi << ")}" << endl;
  ofs << "# [3] = Im{" << Waveform::Types[W.Type] << "(Theta=" << Theta << ", Phi=" << Phi << ")}" << endl;
  for(unsigned int i=0; i<W.Time.size(); ++i) {
    ofs << W.T(i) << " " << W.Re(i) << " " << W.Im(i) << endl;
  }
  ofs.close();
  cout << "☺" << endl;
  
  return 0;
}
