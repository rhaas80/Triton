#include "NumericalRecipes.hpp"

#include <fstream>
#include <iomanip>
#include <ctime>

#include "EasyParser.hpp"
#include "VectorFunctions.hpp"
#include "PostNewtonian.hpp"
#include "Waveform.hpp"

using WaveformUtilities::SplitStringToKeysAndValues;
using WaveformUtilities::StringToDouble;
using WaveformUtilities::StringToBool;
using WaveformUtilities::StringToInt;
using WaveformUtilities::StringToVectorInt;
using WaveformObjects::Waveform;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::flush;
using std::ofstream;
using std::setprecision;

const int BufferSize = 1000;

int main () {
  //// Set up input parameters
  double delta = 0.0;
  double chis = 0.0;
  double chia = 0.0;
  double v0 = 0.144;
  string NRFile = "";
  bool Conjugate = false;
  bool ChangeToPsi4 = false;
  int UniformTime = -1;
  double omegaAlign = 0.0;
  double t1 = 500;
  double t2 = 2000;
  double tmerger = 3000;
  bool DropM0Modes = true;
  bool DropOddMModes = false;
  bool DropNegativeMModes = true;
  vector<int> DropLs(0);
  vector<int> DropLMs(0);
  double DropAfter = 1e200;
  string DiffFileNameBase = "NR";
  bool ZeroEnds = true;
  vector<string> Approximants(4);
  
  Approximants[0] = "T1";
  Approximants[1] = "T2";
  Approximants[2] = "T3";
  Approximants[3] = "T4";
  
  //// Parse the input options
  string Option(""), Options("");
  vector<string> Keys, Values;
  while(getline(cin, Option)) {
    Options += Option + '\n';
  }
  SplitStringToKeysAndValues(Options, Keys, Values);
  for(unsigned int i=0; i<Keys.size(); ++i) {
    if(Keys[i].compare("delta")==0) {
      delta = StringToDouble(Values[i]);
    } else if(Keys[i].compare("chis")==0) {
      chis = StringToDouble(Values[i]);
    } else if(Keys[i].compare("chia")==0) {
      chia = StringToDouble(Values[i]);
    } else if(Keys[i].compare("v0")==0) {
      v0 = StringToDouble(Values[i]);
    } else if(Keys[i].compare("NRFile")==0) {
      NRFile = Values[i];
    } else if(Keys[i].compare("Conjugate")==0) {
      Conjugate = StringToBool(Values[i]);
    } else if(Keys[i].compare("ChangeToPsi4")==0) {
      ChangeToPsi4 = StringToBool(Values[i]);
    } else if(Keys[i].compare("UniformTime")==0) {
      UniformTime = StringToInt(Values[i]);
    } else if(Keys[i].compare("omegaAlign")==0) {
      omegaAlign = StringToDouble(Values[i]);
    } else if(Keys[i].compare("t1")==0) {
      t1 = StringToDouble(Values[i]);
    } else if(Keys[i].compare("t2")==0) {
      t2 = StringToDouble(Values[i]);
    } else if(Keys[i].compare("tmerger")==0) {
      tmerger = StringToDouble(Values[i]);
    } else if(Keys[i].compare("DropM0Modes")==0) {
      DropM0Modes = StringToBool(Values[i]);
    } else if(Keys[i].compare("DropOddMModes")==0) {
      DropOddMModes = StringToBool(Values[i]);
    } else if(Keys[i].compare("DropNegativeMModes")==0) {
      DropNegativeMModes = StringToBool(Values[i]);
    } else if(Keys[i].compare("DropLs")==0) {
      DropLs = StringToVectorInt(Values[i]);
    } else if(Keys[i].compare("DropLMs")==0) {
      DropLMs = StringToVectorInt(Values[i]);
      if(DropLMs.size()%2 != 0) {
	cerr << "DropLMs = " << Values[i] << "; does not have an even number of elements!" << endl;
	exit(1);
      }
    } else if(Keys[i].compare("DropAfter")==0) {
      DropAfter = StringToDouble(Values[i]);
    } else if(Keys[i].compare("DiffFileNameBase")==0) {
      DiffFileNameBase = Values[i];
    } else {
      throw(("Unknown key " + Keys[i] + ".\n").c_str());
    }
  }
  cout << "##Using the following parameters:\n"
       << "\ndelta = " << delta
       << ";\nchis = " << chis
       << ";\nchia = " << chia
       << ";\nv0 = " << v0
       << ";\nNRFile = " << NRFile
       << ";\nConjugate = " << (Conjugate ? "true" : "false")
       << ";\nChangeToPsi4 = " << (ChangeToPsi4 ? "true" : "false")
       << ";\nUniformTime = " << UniformTime
       << ";\nomegaAlign = " << omegaAlign
       << ";\nt1 = " << t1
       << ";\nt2 = " << t2
       << ";\ntmerger = " << tmerger
       << ";\nDropM0Modes = " << (DropM0Modes ? "true" : "false")
       << ";\nDropOddMModes = " << (DropOddMModes ? "true" : "false")
       << ";\nDropNegativeMModes = " << (DropNegativeMModes ? "true" : "false")
       << ";\nDropLs = (" << flush;
  if(DropLs.size()>0) {
    for(unsigned int i=0; i<DropLs.size()-1; ++i) {
      cout << DropLs[i] << ", ";
    }
    cout << DropLs[DropLs.size()-1];
  }
  cout << ");\nDropLMs = (" << flush;
  if(DropLMs.size()>0) {
    for(unsigned int i=0; i<DropLMs.size()-2; i+=2) {
      cout << "(" << DropLMs[i] << ", " << DropLMs[i+1] << "), ";
    }
    cout << "(" << DropLMs[DropLMs.size()-2] << ", " << DropLMs[DropLMs.size()-1] << ")";
  }
  cout << ");\nDropAfter = " << DropAfter
       << ";\nDiffFileNameBase = " << DiffFileNameBase << ";\n" << endl;
  
  //// Read the NR Waveform from file
  cout << "Reading " << NRFile << "... " << flush;
  Waveform NR(NRFile, "MagArg", ZeroEnds);
  cout << "☺" << endl;
  if(DropM0Modes) {
    NR.DropZeroMModes();
  }
  if(DropOddMModes) {
    NR.DropOddMModes();
  }
  if(DropNegativeMModes) {
    NR.DropNegativeMModes();
  }
  if(DropLs.size()>0) {
    for(unsigned int i=0; i<DropLs.size(); ++i) {
      NR.DropLMode(DropLs[i]);
    }
  }
  if(DropLMs.size()>0) {
    for(unsigned int i=0; i<DropLMs.size(); i+=2) {
      NR.DropLMMode(DropLMs[i], DropLMs[i+1]);
    }
  }
  if(DropAfter!=1e200) { NR.DropAfter(DropAfter); }
  if(Conjugate) { NR.Conjugate(); }
  if(ChangeToPsi4) { NR = NR.Differentiate().Differentiate(); }
  
  // If desired, create the PN approximant and hybridize
  for(unsigned int app=0; app<Approximants.size(); ++app) {
    const string Approximant = Approximants[app];
    cout << "Working on PN approximant Taylor" << Approximant << " ..." << endl;
    
    //// Construct the PN Waveform
    Waveform PN("Taylor"+Approximant, delta, chis, chia, v0, NR.LM());
    PN.AddToTime(tmerger);
    if(NR.TypeIndex()%3 == 0) { PN = PN.Differentiate().Differentiate(); }
    
    //// Match
    if(omegaAlign!=0.0) {
      PN = PN.AlignTo_F(NR, omegaAlign, t1, t2);
    } else {
      PN = PN.AlignTo(NR, t1, t2);
    }
    
    /// Output difference
    const string DiffFileName = NR.Type() + "_" + DiffFileNameBase + "-" + Approximant + ".dat";
    cout << "Writing difference to " << DiffFileName << " ..." << flush;
    if(UniformTime>1) {
      Waveform Diff = PN/NR;
      Output(DiffFileName, Diff.UniformTime(UniformTime));
    } else {
      Output(DiffFileName, PN/NR);
    }
    cout << " ☺" << endl;
  }
  
  return 0;
}
