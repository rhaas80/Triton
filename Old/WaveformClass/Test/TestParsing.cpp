#include "EasyParser.hpp"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, const vector<double>& v) {
  for(unsigned int i=0; i<v.size()-1; ++i) {
    out << v[i] << ", ";
  }
  out << v[v.size()-1] << flush;
  return out;
}

int main() {
  string String = "Hello = 0 1 2 3; # definitely\nGoodbye = 123.456; # possibly\nHello = 123.4 56.7 89.0; # definitely not\n";
  vector<string> Keys, Values;
  cout << "String: _" << String << "_\n" << endl;
  
  SplitStringToKeysAndValues(String, Keys, Values);
  
  for(unsigned int i=0; i<Keys.size(); ++i) {
    cout << "Keys[" << i << "] = " << Keys[i] << endl;
    cout << "Values[" << i << "] = " << Values[i] << endl;
  }
  
  cout << "Test vector conversion: _" << StringToVectorDouble(Values[2]) << "_" << endl;
  
  return 0;
}
