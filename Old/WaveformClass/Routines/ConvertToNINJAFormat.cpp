#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Waveform.hpp"
using namespace std;


int main() {
  double dt;
  string DataFileName;
  string MetadataFileName;
  
  cout << "Enter the name of the file you wish to convert: " << flush;
  cin >> DataFileName;
  cout << "Enter the output time space (0 to leave unchanged): " << flush;
  cin >> dt;
  cout << "Enter the name of the metadata file you wish to append: " << flush;
  cin >> MetadataFileName;
  
  cout << "Reading " << DataFileName << " ... " << flush;
  Waveform W(DataFileName, "AmpPhi");
  cout << "☺" << endl;
  
  if(dt!=0.0) {
    cout << "Interpolating to uniform time grid with spacing dt = " << dt << " ... " << flush;
    int steps = int(floor((W.Time[W.Time.size()-1] - W.Time[0])/dt));
    vector<double> NewTime(steps, 0.0);
    for(unsigned int i=0; i<NewTime.size(); ++i) { NewTime[i] = W.Time[0] + i*dt; }
    W.Interpolate(NewTime);
    cout << "☺" << endl;
  }
  
  cout << "Writing " << MetadataFileName << " (among others) ... " << flush;
  W.OutputToNINJAFormat(MetadataFileName);
  cout << "☺" << endl;
  
  return 0;
}
