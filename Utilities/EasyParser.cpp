#include "EasyParser.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
namespace WU = WaveformUtilities;

vector<string>& WU::split(const string& s, vector<string>& elems, char delim) {
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> WU::split(const string &s, char delim) {
    vector<string> elems;
    return WU::split(s, elems, delim);
}

string replace(string String, const string& ReplaceThis, const string& WithThis) {
  size_t index = String.find(ReplaceThis, 0);
  while(index != string::npos && index<String.size()) {
    String.replace(index, ReplaceThis.size(), WithThis);
    index += WithThis.size();
    if(index>String.size()) { break; }
    index = String.find(ReplaceThis, index);
  }
  return String;
}

string WU::TrimWhiteSpace(const string& String) {
  if(String.length()==0) { return String; }
  string Stripped = String;
  while(*Stripped.begin()==' ' || *Stripped.begin()=='\t' || *Stripped.begin()=='\n') {
    Stripped.erase(Stripped.begin(),Stripped.begin()+1);
  }
  if(Stripped.length()==0) { return Stripped; }
  while(*(Stripped.end()-1)==' ' || *(Stripped.end()-1)=='\t' || *(Stripped.end()-1)=='\n') {
    Stripped.erase(Stripped.end()-1,Stripped.end());
  }
  return Stripped;
}

string WU::StripComments(const string& String, const char CommentChar) {
  string Uncommented = String;
  size_t Begin, End;
  while((Begin=Uncommented.find(CommentChar)) != string::npos) {
    End = Uncommented.find('\n', Begin);
    Uncommented.erase(Begin, End-Begin);
  }
  return Uncommented;
}

void WU::SplitStringToKeysAndValues(const string& String, vector<string>& Keys, vector<string>& Values) {
  string Uncommented = WU::StripComments(String);
  vector<string> Pairs = WU::split(Uncommented);
  vector<string> Pair(2, "");
  Keys = vector<string>(Pairs.size()-1, "");
  Values = vector<string>(Pairs.size()-1, "");
  for(unsigned int i=0; i<Pairs.size()-1; ++i) {
    Pair = split(Pairs[i], '=');
    Keys[i] = TrimWhiteSpace(Pair[0]);
    Values[i] = TrimWhiteSpace(Pair[1]);
  }
  return;
}

int WU::StringToInt(const string& String) {
  int Int;
  stringstream ss(String);
  ss >> Int;
  return Int;
}

bool WU::StringToBool(const string& String) {
  bool Bool;
  if(String.compare("true")==0 || String.compare("True")==0 || String.compare("t")==0 || String.compare("T")==0 || String.compare("1")==0) { Bool = true; }
  else if(String.compare("false")==0 || String.compare("False")==0 || String.compare("f")==0 || String.compare("F")==0 || String.compare("0")==0) { Bool = false; }
  else { cerr << "Unknown boolean in '" << String << "'." << endl; exit(1); }
  return Bool;
}

double WU::StringToDouble(const string& String) {
  double Double;
  stringstream ss(String);
  ss >> Double;
  return Double;
}

vector<int> WU::StringToVectorInt(const string& String) {
  int Int;
  vector<int> VectorInt(0);
  stringstream ss(String);
  while(ss >> Int) {
    VectorInt.push_back(Int);
  }
  return VectorInt;
}

vector<double> WU::StringToVectorDouble(const string& String) {
  double Double;
  vector<double> VectorDouble(0);
  stringstream ss(String);
  while(ss >> Double) {
    VectorDouble.push_back(Double);
  }
  return VectorDouble;
}

vector<string> WU::StringToVectorString(const string& String) {
  return split(String, ' ');
}



string WU::DoubleToString(const double x, const unsigned int Width) {
  ostringstream SStream;
  if(Width>0) SStream << setfill('0') << setw(Width);
  SStream << x;
  return SStream.str();
}
