#include "NumericalRecipes.hpp"

#include <iostream>

#include "EasyParser.hpp"
#include "VectorFunctions.hpp"
#include "Utilities.hpp"
#include "RadiationAxis.hpp"
#include "Quaternions.hpp"

#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

using WaveformUtilities::SplitStringToKeysAndValues;
using WaveformUtilities::StringToDouble;
using WaveformUtilities::StringToBool;
using WaveformUtilities::StringToInt;
using WaveformUtilities::StringToVectorInt;
using WaveformUtilities::StringToVectorDouble;

using WaveformUtilities::square;
using WaveformUtilities::norm;
using WaveformUtilities::Matrix;
using WaveformUtilities::RadiationAxis;
using WaveformUtilities::MinimalRotation;
using WaveformUtilities::Quaternion;
using WaveformUtilities::Quaternions;
using WaveformObjects::Waveform;

const int BufferSize = 1000;

void RewriteNames(const string& DataFileName, const string& RotatedFiles, const string& RotationAnglesFiles,
		  string& RotatedFileName, string& RotationAnglesFileName);

int main() {
  //// Set up input parameters
  vector<double> Radii(0);
  string InputDirectory = "";
  string OutputDirectory = "";
  string DataFile = "rPsi4_R%04.0fm_U8+.dat";
  string RotatedFiles = "_Rotated";
  string RotationAnglesFiles = "_RotationAngles";
  
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
    } else if(Keys[i].compare("InputDirectory")==0) {
      InputDirectory = Values[i];
      if(InputDirectory.length()>0 && InputDirectory[InputDirectory.length()-1]!='/') { InputDirectory += "/"; }
    } else if(Keys[i].compare("OutputDirectory")==0) {
      OutputDirectory = Values[i];
      if(OutputDirectory.length()>0 && OutputDirectory[OutputDirectory.length()-1]!='/') { OutputDirectory += "/"; }
    } else if(Keys[i].compare("DataFile")==0) {
      DataFile = Values[i];
    } else if(Keys[i].compare("RotatedFiles")==0) {
      RotatedFiles = Values[i];
    } else if(Keys[i].compare("RotationAnglesFiles")==0) {
      RotationAnglesFiles = Values[i];
    } else {
      throw(("Unknown key " + Keys[i] + ".\n").c_str());
    }
  }
  
  //// Make sure a list of radii has been input
  if(Radii.size()==0) {
    throw("You need to enter a list of radii for the data files.");
  }
  
  //// Main loop over the waveforms
  for(unsigned int r=0; r<Radii.size(); ++r) {
    double Radius = Radii[r];
    char DataFileNameChars[BufferSize];
    sprintf(DataFileNameChars, DataFile.c_str(), Radius);
    const string DataFileName(DataFileNameChars);
    string RotatedFileName = "";
    string RotationAnglesFileName = "";
    RewriteNames(DataFileName, RotatedFiles, RotationAnglesFiles,
		 RotatedFileName, RotationAnglesFileName);
    
    //// Read in the waveform
    cout << "Reading " << DataFileName << "... " << flush;
    Waveform W(InputDirectory+DataFileName, "ReIm");
    cout << "☺" << endl;
    
    //// Get the minimal-rotation frame angles
    cout << "Getting rotation angles ... " << flush;
    vector<double> alpha(W.NTimes());
    vector<double> beta(W.NTimes());
    vector<double> gamma(W.NTimes());
    MinimalRotation(W, alpha, beta, gamma);
    
    //// Rotate the Waveform into that frame
    cout << "and rotating ... " << flush;
    W.RotateCoordinates(alpha, beta, gamma);
    cout << "☺" << endl;
    
    //// Output the rotated Waveform itself
    cout << "Writing " << RotatedFileName << "... " << flush;
    Output(OutputDirectory+RotatedFileName, W);
    cout << "☺" << endl;
    
    //// Output the rotation angles
    cout << "Writing " << RotationAnglesFileName << "... " << flush;
    ofstream file((OutputDirectory+RotationAnglesFileName).c_str());
    file << "# [1] = t\n"
	 << "# [2] = alpha\n"
	 << "# [3] = beta\n"
	 << "# [4] = gamma\n"
       << setprecision(16);
    for(unsigned int t=0; t<W.NTimes(); ++t) {
      file << W.T(t) << " "
	   << alpha[t] << " "
	   << beta[t] << " "
	   << gamma[t]
	   << endl;
    }
    file.close();
    cout << "☺\n" << endl;
    
  }
  
  return 0;
}

void RewriteNames(const string& DataFileName, const string& RotatedFiles, const string& RotationAnglesFiles,
		  string& RotatedFileName, string& RotationAnglesFileName) {
  if(DataFileName.length()<5 || DataFileName.substr(DataFileName.length()-4, 4) != ".dat") {
    cerr << "\n\nLast four characters of '" << DataFileName << "' are not '.dat'." << endl;
    throw("Misunderstood DataFileName");
  }
  
  RotatedFileName = DataFileName;
  RotationAnglesFileName = DataFileName;
  RotatedFileName.insert(RotatedFileName.length()-4, RotatedFiles);
  RotationAnglesFileName.insert(RotationAnglesFileName.length()-4, RotationAnglesFiles);
  
  if(RotatedFileName.empty() || RotationAnglesFileName.empty()) {
    cerr << "\n\nCouldn't get RotatedFileName or RotationAnglesFileName!\n"
	 << "DataFileName = " << DataFileName << "; RotatedFiles = " << RotatedFiles << "; RotationAnglesFiles = " << RotationAnglesFiles
	 << ";\nRotatedFileName = " << RotatedFileName << "; RotationAnglesFileName = " << RotationAnglesFileName << endl;
    throw("Bad file names for output data");
  }
  
  return;
}
