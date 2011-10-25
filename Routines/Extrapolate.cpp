#include "NumericalRecipes.hpp"

#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>

#include "EasyParser.hpp"
#include "VectorFunctions.hpp"
#include "Waveforms.hpp"

using WaveformUtilities::SplitStringToKeysAndValues;
using WaveformUtilities::StringToDouble;
using WaveformUtilities::StringToBool;
using WaveformUtilities::StringToInt;
using WaveformUtilities::StringToVectorInt;
using WaveformUtilities::StringToVectorDouble;
using WaveformUtilities::max;
using WaveformUtilities::min;
using WaveformObjects::Waveform;
using WaveformObjects::Waveforms;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::flush;
using std::ofstream;
using std::stringstream;
using std::setprecision;

int BufferSize = 1000;

int main () {
  //// Set up input parameters
  vector<double> Radii(0);
  vector<int> ExtrapolationOrders(StringToVectorInt("-1 2 3 4 5 6 7 8"));
  string InputDirectory = "";
  string OutputDirectory = "";
  string DataFile = "rPsi4_R%04.0fm_U8+.dat";
  string AreaFile = "SurfaceArea_R%04.0fm.dat";
  string LapseFile = "LapseSurfaceIntegral_R%04.0fm.dat";
  double ADMMass = 1.0;
  double ChMass  = 1.0;
  string ExtrapolatedFiles = "ExtrapolatedN%d.dat";
  string DifferenceFiles = "ExtrapConvergence_N%d-N%d.dat";
  bool ZeroEnd = false;
  
  //// Parse the input options
  string Option(""), Options("");
  vector<string> Keys, Values;
  while(getline(cin, Option)) {
    Options += Option + '\n';
  }
  SplitStringToKeysAndValues(Options, Keys, Values);
  for(unsigned int i=0; i<Keys.size(); ++i) {
    if(Keys[i].compare("Radii")==0) {
      Radii = StringToVectorDouble(Values[i]);
    } else if(Keys[i].compare("ExtrapolationOrders")==0) {
      ExtrapolationOrders = StringToVectorInt(Values[i]);
    } else if(Keys[i].compare("InputDirectory")==0) {
      InputDirectory = Values[i];
      if(InputDirectory.length()>0 && InputDirectory[InputDirectory.length()-1]!='/') { InputDirectory += "/"; }
    } else if(Keys[i].compare("OutputDirectory")==0) {
      OutputDirectory = Values[i];
      if(OutputDirectory.length()>0 && OutputDirectory[OutputDirectory.length()-1]!='/') { OutputDirectory += "/"; }
    } else if(Keys[i].compare("DataFile")==0) {
      DataFile = Values[i];
    } else if(Keys[i].compare("AreaFile")==0) {
      AreaFile = Values[i];
    } else if(Keys[i].compare("LapseFile")==0) {
      LapseFile = Values[i];
    } else if(Keys[i].compare("ADMMass")==0) {
      ADMMass = StringToDouble(Values[i]);
    } else if(Keys[i].compare("ChMass")==0) {
      ChMass = StringToDouble(Values[i]);
    } else if(Keys[i].compare("ExtrapolatedFiles")==0) {
      ExtrapolatedFiles = Values[i];
    } else if(Keys[i].compare("DifferenceFiles")==0) {
      DifferenceFiles = Values[i];
    } else if(Keys[i].compare("ConvergenceAlignmentT1")==0 || Keys[i].compare("ConvergenceMatchingT1")==0) {
      const double ConvergenceAlignmentT1 = StringToDouble(Values[i]);
      cerr << "\nCannot use ConvergenceAlignmentT1=" << ConvergenceAlignmentT1 << ".  This is a deprecated option.\n"
	   << "Use the 'Convergence' routine if you want this functionality." << endl;
      if(ConvergenceAlignmentT1 != 3.0e300) {
	throw("Old option input to the 'Extrapolate' routine.");
      }
    } else if(Keys[i].compare("ConvergenceAlignmentT2")==0 || Keys[i].compare("ConvergenceMatchingT2")==0) {
      const double ConvergenceAlignmentT2 = StringToDouble(Values[i]);
      cerr << "\nCannot use ConvergenceAlignmentT2=" << ConvergenceAlignmentT2 << ".  This is a deprecated option.\n"
	   << "Use the 'Convergence' routine if you want this functionality." << endl;
      if(ConvergenceAlignmentT2 != 3.0e300) {
	throw("Old option input to the 'Extrapolate' routine.");
      }
    } else if(Keys[i].compare("ZeroEnd")==0) {
      ZeroEnd = StringToBool(Values[i]);
    } else {
      throw(("Unknown key " + Keys[i] + ".\n").c_str());
    }
  }
  
  //// Make sure a list of radii has been input
  if(Radii.size()==0) {
    throw("You need to enter a list of radii for the data files.");
  }
  
  //// Make sure there are enough radii to do the requested extrapolations
  if(int(Radii.size())<=max(ExtrapolationOrders) && max(ExtrapolationOrders)>-1) {
    stringstream Message("");
    Message << "Not enough data sets (" << Radii.size()
	    << ") for max extrapolation order (N=" << max(ExtrapolationOrders) << ").";
    throw(Message.str().c_str());
  }
  if(-int(Radii.size())>min(ExtrapolationOrders)) {
    stringstream Message("");
    Message << "Not enough data sets (" << Radii.size()
	    << ") for min extrapolation order (N=" << min(ExtrapolationOrders) << ").";
    throw(Message.str().c_str());
  }
  
  //// Read in the Waveforms and set things up nicely
  Waveforms Ws(Radii, InputDirectory+DataFile, InputDirectory+AreaFile, InputDirectory+LapseFile, ADMMass, ChMass, ZeroEnd);
  Ws.SetCommonTime();
  Ws.FixNonOscillatingData();
  
  //// Loop over all the ExtrapolationOrders, doing the dirty business
  time_t start,end;
  Waveform Last;
  for(unsigned int i=0; i<ExtrapolationOrders.size(); ++i) {
    cout << "Extrapolating with order N=" << ExtrapolationOrders[i] << endl;
    
    //// Extrapolate
    try {
      time(&start);
      Waveform Extrap = Ws.Extrapolate(ExtrapolationOrders[i]);
      time(&end);
      Extrap.UnfixNonOscillatingData();
      
      //// Output the data
      char ExtrapolatedFile[BufferSize];
      sprintf(ExtrapolatedFile, (Extrap.Type() + "_" + ExtrapolatedFiles).c_str(), ExtrapolationOrders[i]);
      cout << "Finished N=" << ExtrapolationOrders[i] << " in " << setprecision(3) << difftime(end, start) << " seconds." << endl;
      cout << "Writing " << string(ExtrapolatedFile) << "... " << flush;
      Output(OutputDirectory+string(ExtrapolatedFile), Extrap);
      cout << "☺" << endl;
      
      //// Compare to the last one
      if(i>0) {
	Waveform Diff = Extrap/Last;
	char DifferenceFile[BufferSize];
	sprintf(DifferenceFile, (Extrap.Type() + "_" + DifferenceFiles).c_str(), ExtrapolationOrders[i], ExtrapolationOrders[i-1]);
	cout << "Writing " << string(DifferenceFile) << "... " << flush;
	Output(OutputDirectory+string(DifferenceFile), Diff);
	cout << "☺" << endl;
      }
      Last = Extrap;
    } catch(...) { cout << "Bad extrapolation ☹\n" << endl; }
  }
  
  return 0;
}
