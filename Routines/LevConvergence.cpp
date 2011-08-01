#include "NumericalRecipes.hpp"

#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>

#include "EasyParser.hpp"
#include "VectorFunctions.hpp"
#include "Waveforms.hpp"
#include "Interpolate.hpp"

using WaveformUtilities::SplitStringToKeysAndValues;
using WaveformUtilities::StringToDouble;
using WaveformUtilities::StringToBool;
using WaveformUtilities::StringToInt;
using WaveformUtilities::StringToVectorInt;
using WaveformUtilities::StringToVectorDouble;
using WaveformUtilities::max;
using WaveformUtilities::min;
using WaveformUtilities::Interpolate;
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
using std::ifstream;
using std::stringstream;
using std::setprecision;

void ReadFluxFile(const string& InFileName, string& Header, vector<double>& T, vector<double>& Omega2m2,
		  vector<double>& Flux, vector<double>& PNFlux, vector<double>& NormalizedFlux);

int main() {
  //// Set up input parameters
  string LevList = "../Lev4 ../Lev5 ../Lev6";
  string Psi4Files = "";//rMPsi4_ExtrapolatedN%d.dat";
  string RWZFiles  = "rhOverM_ExtrapolatedN%d.dat";
  string FluxFiles = "";//FluxN%d.dat";
  vector<int> ExtrapolationOrders(StringToVectorInt("-1 2 3 4 5 6 7 8"));
  string DifferenceFiles = "%s-%s_N%d.dat";
  double ConvergenceAlignmentT1=3.0e300;
  double ConvergenceAlignmentT2=3.0e300;
  
  //// Parse the input options
  string Option(""), Options("");
  vector<string> Keys, Values;
  while(getline(cin, Option)) {
    Options += Option + '\n';
  }
  SplitStringToKeysAndValues(Options, Keys, Values);
  for(unsigned int i=0; i<Keys.size(); ++i) {
    if(Keys[i].compare("LevList")==0) {
      LevList = Values[i];
    } else if(Keys[i].compare("Psi4Files")==0) {
      Psi4Files = Values[i];
    } else if(Keys[i].compare("RWZFiles")==0) {
      RWZFiles = Values[i];
    } else if(Keys[i].compare("FluxFiles")==0) {
      FluxFiles = Values[i];
    } else if(Keys[i].compare("ExtrapolationOrders")==0) {
      ExtrapolationOrders = StringToVectorInt(Values[i]);
    } else if(Keys[i].compare("DifferenceFiles")==0) {
      DifferenceFiles = Values[i];
    } else if(Keys[i].compare("ConvergenceAlignmentT1")==0) {
      ConvergenceAlignmentT1 = StringToDouble(Values[i]);
    } else if(Keys[i].compare("ConvergenceAlignmentT2")==0) {
      ConvergenceAlignmentT2 = StringToDouble(Values[i]);
    } else {
      throw(("Unknown key " + Keys[i] + ".\n").c_str());
    }
  }
  
  size_t A=0, B=0;
  B = LevList.find(" ");
  string LastLev = LevList.substr(A,B-A);
  A = B+1;
  B = LevList.find(" ", B+1);
  string NextLev = LevList.substr(A,B-A);
  Waveforms Diff(2);
  vector<double> FluxA(0), OmegaA(0), FluxB(0), OmegaB(0), PNFlux(0), FluxDiff(0);
  while(A!=string::npos+1) {
    if(!Psi4Files.empty()) for(unsigned int i=0; i<ExtrapolationOrders.size(); ++i) {
	char NextFile[1000], LastFile[1000], DiffFile[1000];
	sprintf(LastFile, (LastLev + "/" + Psi4Files).c_str(), ExtrapolationOrders[i]);
	sprintf(NextFile, (NextLev + "/" + Psi4Files).c_str(), ExtrapolationOrders[i]);
	cout << "Computing " << LastFile << " - " << NextFile << "... " << flush;
	Diff[0] = Waveform(LastFile, "AmpPhi");
	Diff[1] = Waveform(NextFile, "AmpPhi");
	if(ConvergenceAlignmentT1!=3.0e300 && ConvergenceAlignmentT1!=3.0e300) {
	  Diff[1] = Diff[1].AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
	}
	Diff.AlignPhases();
	sprintf(DiffFile, (Diff[0].Type() + "_" + DifferenceFiles).c_str(), LastLev.substr(LastLev.rfind("/")+1).c_str(), NextLev.substr(NextLev.rfind("/")+1).c_str(), ExtrapolationOrders[i]);
	cout << "and printing " << DiffFile << "... " << flush;
	ofstream ofs(DiffFile, ofstream::out);
	ofs << setprecision(14) << flush;
	ofs << Diff[0]/Diff[1];
	ofs.close();
	cout << "☺" << endl;
      }
    if(!RWZFiles.empty()) for(unsigned int i=0; i<ExtrapolationOrders.size(); ++i) {
	char NextFile[1000], LastFile[1000], DiffFile[1000];
	sprintf(LastFile, (LastLev + "/" + RWZFiles).c_str(), ExtrapolationOrders[i]);
	sprintf(NextFile, (NextLev + "/" + RWZFiles).c_str(), ExtrapolationOrders[i]);
	cout << "Computing " << LastFile << " - " << NextFile << "... " << flush;
	Diff[0] = Waveform(LastFile, "AmpPhi");
	Diff[1] = Waveform(NextFile, "AmpPhi");
	if(ConvergenceAlignmentT1!=3.0e300 && ConvergenceAlignmentT1!=3.0e300) {
	  Diff[1] = Diff[1].AlignTo(Diff[0], ConvergenceAlignmentT1, ConvergenceAlignmentT2);
	}
	Diff.AlignPhases();
	sprintf(DiffFile, (Diff[0].Type() + "_" + DifferenceFiles).c_str(), LastLev.substr(LastLev.rfind("/")+1).c_str(), NextLev.substr(NextLev.rfind("/")+1).c_str(), ExtrapolationOrders[i]);
	cout << "and printing " << DiffFile << "... " << flush;
	ofstream ofs(DiffFile, ofstream::out);
	ofs << setprecision(14) << flush;
	ofs << Diff[0]/Diff[1];
	ofs.close();
	cout << "☺" << endl;
      }
    if(!FluxFiles.empty()) for(unsigned int i=0; i<ExtrapolationOrders.size(); ++i) {
	char NextFile[1000], LastFile[1000], DiffFile[1000];
	string Header="";
	vector<double> T, NormalizedFlux;
	sprintf(LastFile, (LastLev + "/" + FluxFiles).c_str(), ExtrapolationOrders[i]);
	sprintf(NextFile, (NextLev + "/" + FluxFiles).c_str(), ExtrapolationOrders[i]);
	cout << "Computing " << LastFile << " - " << NextFile << "... " << flush;
	ReadFluxFile(LastFile, Header, T, OmegaB, FluxB, PNFlux, NormalizedFlux);
	ReadFluxFile(NextFile, Header, T, OmegaA, FluxA, PNFlux, NormalizedFlux);
	FluxDiff = FluxA - Interpolate(OmegaB, FluxB, OmegaA);
	sprintf(DiffFile, ("Flux_" + DifferenceFiles).c_str(), LastLev.substr(LastLev.rfind("/")+1).c_str(), NextLev.substr(NextLev.rfind("/")+1).c_str(), ExtrapolationOrders[i]);
	cout << "and printing " << DiffFile << "... " << flush;
	ofstream ofs(DiffFile, ofstream::out);
	ofs << "# [1] = M*omega_hdot(2,-2)\n"
	    << "# [2] = FluxA-FluxB\n"
	    << "# [3] = (FluxA-FluxB)/PNFluxA\n"
	    << setprecision(8) << flush;
	for(unsigned int j=0; j<OmegaA.size(); ++j) {
	  ofs << OmegaA[j] << " " << FluxDiff[j] << " " << FluxDiff[j]/PNFlux[j] << endl;
	}
	ofs.close();
	cout << "☺" << endl;
      }
    LastLev = NextLev;
    A = B+1;
    B = LevList.find(" ", B+1);
    NextLev = LevList.substr(A,B-A);
  }
  
  return 0;
}



void ReadFluxFile(const string& InFileName, string& Header, vector<double>& T, vector<double>& Omega2m2,
		  vector<double>& Flux, vector<double>& PNFlux, vector<double>& NormalizedFlux) {
  // Make sure the string and vectors are empty
  Header = "";
  T   = vector<double>(0);
  Omega2m2 = vector<double>(0);
  Flux = vector<double>(0);
  PNFlux = vector<double>(0);
  NormalizedFlux = vector<double>(0);
  
  // Initialize variables
  string Temp="";
  double tVal=0.0, OmegaVal=0.0, FluxVal=0.0, PNFluxVal=0.0, NormFluxVal=0.0;
  ifstream InFile(InFileName.c_str());
  
  // Read the file
  if(InFile.is_open()) {
    // Get the header
    while(InFile.peek()=='#' || InFile.peek()=='%') {
      getline(InFile, Temp);
      if(Temp.compare(1, 5, " time") != 0 || InFile.peek()=='#' || InFile.peek()=='%') {
	Header += Temp + "\n";
      }
    }
    // Get the data
    InFile >> tVal;
    while (!InFile.eof()) {
      T.push_back(tVal);
      InFile >> OmegaVal;
      InFile >> FluxVal;
      InFile >> PNFluxVal;
      InFile >> NormFluxVal;
      InFile >> tVal;
      Omega2m2.push_back(OmegaVal);
      Flux.push_back(FluxVal);
      PNFlux.push_back(PNFluxVal);
      NormalizedFlux.push_back(NormFluxVal);
    }
    InFile.close();
  } else {
    cerr << "Couldn't open input file " << InFileName
	 << " for reading."  << endl;
    throw("Bad file name");
  }
  return;
}
