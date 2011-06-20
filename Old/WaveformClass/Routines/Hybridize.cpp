#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cmath>

#include "Waveforms.hpp"
#include "EasyParser.hpp"
#include "VectorFunctions.hpp"

using namespace std;

#define throw(message) \
{printf("ERROR: %s\n\tin file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}

int BufferSize = 1000;

int main (void) {
  //// Set up input parameters
  double delta = 0.0;
  double chis = 0.0;
  double chia = 0.0;
  double v0 = 0.144;
  string Approximant = "TaylorT4";
  string NRFile = "";
  bool Conjugate = false;
  bool UniformTime = false;
  bool ChangeToPsi4 = false;
  double t1 = 500;
  double t2 = 2000;
  double tmerger = 3000;
  bool DropM0Modes = true;
  bool DropOddMModes = false;
  vector<int> DropLs(0);
  vector<int> DropLMs(0);
  double DropAfter = 1e200;
  string HybridFileName = "Hybrid";
  string DiffFileName = "";
  double HybridDt = 0.0;
  bool NINJAFormat = false;
  bool MinimalGrid = false;
  double AmpTol = 1.e-5;
  double PhiTol = AmpTol;
  
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
    } else if(Keys[i].compare("Approximant")==0) {
      Approximant = Values[i];
    } else if(Keys[i].compare("NRFile")==0) {
      NRFile = Values[i];
    } else if(Keys[i].compare("Conjugate")==0) {
      Conjugate = StringToBool(Values[i]);
    } else if(Keys[i].compare("UniformTime")==0) {
      UniformTime = StringToBool(Values[i]);
    } else if(Keys[i].compare("ChangeToPsi4")==0) {
      ChangeToPsi4 = StringToBool(Values[i]);
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
    } else if(Keys[i].compare("HybridFileName")==0) {
      HybridFileName = Values[i];
    } else if(Keys[i].compare("DiffFileName")==0) {
      DiffFileName = Values[i];
    } else if(Keys[i].compare("HybridDt")==0) {
      HybridDt = StringToDouble(Values[i]);
    } else if(Keys[i].compare("NINJAFormat")==0) {
      NINJAFormat = StringToBool(Values[i]);
    } else if(Keys[i].compare("MinimalGrid")==0) {
      MinimalGrid = StringToBool(Values[i]);
    } else if(Keys[i].compare("AmpTol")==0) {
      AmpTol = StringToDouble(Values[i]);
    } else if(Keys[i].compare("PhiTol")==0) {
      PhiTol = StringToDouble(Values[i]);
    } else {
      throw(("Unknown key " + Keys[i] + ".\n").c_str());
    }
  }
  cout << "##Using the following parameters:\n"
       << "\ndelta = " << delta
       << ";\nchis = " << chis
       << ";\nchia = " << chia
       << ";\nv0 = " << v0
       << ";\nApproximant = " << Approximant
       << ";\nNRFile = " << NRFile
       << ";\nConjugate = " << (Conjugate ? "true" : "false")
       << ";\nUniformTime = " << (UniformTime ? "true" : "false")
       << ";\nChangeToPsi4 = " << (ChangeToPsi4 ? "true" : "false")
       << ";\nt1 = " << t1
       << ";\nt2 = " << t2
       << ";\ntmerger = " << tmerger
       << ";\nDropM0Modes = " << (DropM0Modes ? "true" : "false")
       << ";\nDropOddMModes = " << (DropOddMModes ? "true" : "false")
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
       << ";\nHybridFileName = " << HybridFileName
       << ";\nDiffFileName = " << DiffFileName
       << ";\nHybridDt = " << HybridDt
       << ";\nNINJAFormat = " << (NINJAFormat ? "true" : "false")
       << ";\nMinimalGrid = " << (MinimalGrid ? "true" : "false")
       << ";\nAmpTol = " << AmpTol
       << ";\nPhiTol = " << PhiTol << ";\n" << endl;
  
  //// Read the NR Waveform from file
  cout << "Reading " << NRFile << "... " << flush;
  Waveform NR(NRFile, "AmpPhi");
  cout << "☺" << endl;
  if(DropM0Modes) {
    NR.DropZeroMModes();
  }
  if(DropOddMModes) {
    NR.DropOddMModes();
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
  if(UniformTime) { NR = NR.UniformTime(); }
  if(ChangeToPsi4) { NR = NR.Differentiate().Differentiate(); }
  Waveform& Hybrid = NR;
  
  // If desired, create the PN approximant and hybridize
  if(Approximant.compare("None")!=0 && Approximant.compare("none")!=0) {
    cout << "Constructing PN approximant " << Approximant << " ...\n\t" << flush;
    //// Construct the PN Waveform
    Waveform PN(Approximant, delta, chis, chia, v0, 3.5, NR.LM);
    PN.Time += tmerger;
    
    if(NR.Type%3 == 0) { PN = PN.Differentiate().Differentiate(); }
    
    //// Match
    PN = PN.MatchTo(NR, t1, t2);
    
    /// Diff, if desired
    if( ! DiffFileName.empty() ) {
      DiffFileName = Waveform::Types[Hybrid.Type] + "_" + DiffFileName + ".dat";
      cout << "Writing difference to " << DiffFileName << " ..." << flush;
      ofstream ofs(DiffFileName.c_str(), ofstream::out);
      ofs << setprecision(14) << flush;
      ofs << PN / NR;
      ofs.close();
      cout << " ☺" << endl;
    }
    
    //// Hybridize
    PN = PN.HybridizeWith(NR, t1, t2);
    Hybrid = PN;
    
    cout << "☺" << endl;
  }
  
  // If desired, interpolate to uniform grid
  if(HybridDt!=0.0) {
    cout << "Interpolating Hybrid to grid with dt=" << HybridDt << " ... " << flush;
    vector<double> Time((unsigned int)(floor((Hybrid.Time[Hybrid.Time.size()-1]-Hybrid.Time[0])/HybridDt)), 0.0);
    Time[0] = Hybrid.Time[0];
    for(unsigned int i=1; i<Time.size(); ++i) {
      Time[i] = Time[0] + i*HybridDt;
    }
    Hybrid.Interpolate(Time);
    cout << "☺" << endl;
  }
  
  //// Write the Hybrid to file(s)
  if(MinimalGrid) {
    for(unsigned int i=0; i<Hybrid.LM.size(); ++i) {
      int l = Hybrid.LM[i][0];
      int m = Hybrid.LM[i][1];
      char ModeFile[BufferSize];
      sprintf(ModeFile, (Waveform::Types[Hybrid.Type] + "_" + HybridFileName + "_L%d_M%d.dat.minimal").c_str(), l, m);
      cout << "Writing " << ModeFile << " ..." << flush;
      Waveform Mode=Hybrid[i].MinimalGrid(AmpTol, PhiTol);
      ofstream ofs(ModeFile, ofstream::out);
      ofs << setprecision(14) << flush;
      ofs << Mode;
      ofs.close();
      cout << " ☺" << endl;
    }
  } else {
    if(NINJAFormat) {
      for(unsigned int i=0; i<Hybrid.LM.size(); ++i) {
	int l = Hybrid.LM[i][0];
	int m = Hybrid.LM[i][1];
	char ModeFile[BufferSize];
	sprintf(ModeFile, (Waveform::Types[Hybrid.Type] + "_" + HybridFileName + "_L%d_M%d.dat.minimal").c_str(), l, m);
	cout << "Writing " << ModeFile << " ..." << flush;
	ofstream ofs(ModeFile, ofstream::out);
	ofs << setprecision(14) << flush;
	ofs << Hybrid[i];
	ofs.close();
	cout << " ☺" << endl;
      }
    } else {
      HybridFileName = Waveform::Types[Hybrid.Type] + "_" + HybridFileName + ".dat";
      cout << "Writing hybrid to " << HybridFileName << " ..." << flush;
      ofstream ofs(HybridFileName.c_str(), ofstream::out);
      ofs << setprecision(14) << flush;
      ofs << Hybrid;
      ofs.close();
      cout << " ☺" << endl;
    }
  }
  
  return 0;
}
