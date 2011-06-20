#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>

#include "Waveforms.hpp"
#include "EasyParser.hpp"
#include "VectorFunctions.hpp"
#include "Interpolate.hpp"

using namespace std;

#define throw(message) \
{printf("ERROR: %s\n\tin file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}

int BufferSize = 1000;

int main (void) {
  //// Set up input parameters
  vector<int> ExtrapolationOrders(StringToVectorInt("-1 2 3 4 5 6"));
  double MassRatio = 0.25; // This is expected to be the symmetric mass ratio nu=m1*m2/(m1+m2)
  string DataFiles = "rhOverM_ExtrapolatedN%d.dat";
  string FluxFiles = "FluxN%d.dat";
  string DifferenceFiles = "FluxConvergence_N%d-N%d.dat";
  double DropBefore = -3e300;
  double DropAfter = 3e300;
  bool Smooth = false;
  int SmoothingNLeft = 32;
  int SmoothingNRight = SmoothingNLeft;
  int SmoothingPolyOrder = 4;
  
  //// Parse the input options
  string Option(""), Options("");
  vector<string> Keys, Values;
  while(getline(cin, Option)) {
    Options += Option + '\n';
  }
  SplitStringToKeysAndValues(Options, Keys, Values);
  for(unsigned int i=0; i<Keys.size(); ++i) {
    if(Keys[i].compare("ExtrapolationOrders")==0) {
      ExtrapolationOrders = StringToVectorInt(Values[i]);
    } else if(Keys[i].compare("MassRatio")==0) {
      MassRatio = StringToDouble(Values[i]);
    } else if(Keys[i].compare("DataFiles")==0) {
      DataFiles = Values[i];
    } else if(Keys[i].compare("FluxFiles")==0) {
      FluxFiles = Values[i];
    } else if(Keys[i].compare("DifferenceFiles")==0) {
      DifferenceFiles = Values[i];
    } else if(Keys[i].compare("DropBefore")==0) {
      DropBefore = StringToDouble(Values[i]);
    } else if(Keys[i].compare("DropAfter")==0) {
      DropAfter = StringToDouble(Values[i]);
    } else if(Keys[i].compare("Smooth")==0) {
      Smooth = StringToBool(Values[i]);
    } else if(Keys[i].compare("SmoothingNLeft")==0) {
      SmoothingNLeft = StringToInt(Values[i]);
    } else if(Keys[i].compare("SmoothingNRight")==0) {
      SmoothingNRight = StringToInt(Values[i]);
    } else if(Keys[i].compare("SmoothingPolyOrder")==0) {
      SmoothingPolyOrder = StringToInt(Values[i]);
    } else {
      throw(("Unknown key " + Keys[i] + ".\n").c_str());
    }
  }
  
  //// Do the work
  char FileName[BufferSize];
  Waveform W;
  vector<double> Omega(0), OmegaOld(0), Flux(0), FluxOld(0), PNFlux(0), NormalizedFlux(0), Diff(0), NormalizedDiff(0);
  for(unsigned int i=0; i<ExtrapolationOrders.size(); ++i) {
    // Get flux and omega
    sprintf(FileName, DataFiles.c_str(), ExtrapolationOrders[i]);
    cout << "Reading " << FileName << "... " << flush;
    W = Waveform(FileName, "AmpPhi").DropBefore(DropBefore).DropAfter(DropAfter).Differentiate();
    cout << "☺\nComputing omega, flux, PN flux, and normalized flux... " << flush;
    if(Smooth) {
      cout << "and smoothing... " << flush;
      W = W.UniformTimeToPowerOfTwo();
      Omega =  W.Omega2m2Smooth(SmoothingNLeft, SmoothingNRight, SmoothingPolyOrder);
    } else {
      Omega = W.Omega2m2();
    }
    Flux = W.Flux();
    PNFlux = ((32.0/5.0)*MassRatio*MassRatio)*pow(fabs(Omega)/2.0, 10.0/3.0);
    NormalizedFlux = Flux/PNFlux;
    cout << "☺" << endl;
    
    // Output data for this go round
    sprintf(FileName, FluxFiles.c_str(), ExtrapolationOrders[i]);
    cout << "Outputting data to " << FileName << "... " << flush;
    ofstream ofs(FileName, ofstream::out);
    ofs << "# [1] = (t-r*)/M\n"
	<< "# [2] = M*omega_hdot(2,-2)\n"
	<< "# [3] = Flux\n"
	<< "# [4] = PNFlux\n"
	<< "# [5] = NormalizedFlux\n"
	<< setprecision(8) << flush;
    for(unsigned int j=0; j<W.Time.size(); ++j) {
      ofs << W.Time[j] << " " << Omega[j] << " " << Flux[j] << " " << PNFlux[j] << " " << NormalizedFlux[j] << endl;
    }
    ofs.close();
    cout << "☺" << endl;
    
    // Output the difference from the last, if possible
    if(i>0) {
      cout << "Calculating flux difference and normalized by PN flux... " << flush;
      Diff = Flux - Interpolate(OmegaOld, FluxOld, Omega);
      NormalizedDiff = Diff / PNFlux;
      cout << "☺" << endl;
      sprintf(FileName, DifferenceFiles.c_str(), ExtrapolationOrders[i], ExtrapolationOrders[i-1]);
      cout << "Outputting difference data to " << FileName << "... " << flush;
      ofstream ofs(FileName, ofstream::out);
      ofs << "# [1] = (t-r*)/M\n"
	  << "# [2] = M*omega_hdot(2,-2)\n"
	  << "# [3] = FluxN" << ExtrapolationOrders[i] << "-FluxN" << ExtrapolationOrders[i-1] << "\n"
	  << "# [4] = (FluxN" << ExtrapolationOrders[i] << "-FluxN" << ExtrapolationOrders[i-1] << ")/PNFluxN" << ExtrapolationOrders[i] << "\n"
	  << setprecision(8) << flush;
      for(unsigned int j=0; j<W.Time.size(); ++j) {
	ofs << W.Time[j] << " " << Omega[j] << " " << Diff[j] << " " << NormalizedDiff[j] << endl;
      }
      ofs.close();
      cout << "☺" << endl;
    }
    
    // Save current flux and frequency, if necessary
    if(i<ExtrapolationOrders.size()-1){
      FluxOld = Flux;
      OmegaOld = Omega;
    }
    
    cout << endl;
  }
  
  return 0;
}
