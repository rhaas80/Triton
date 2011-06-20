#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "FileIO.hpp"
using namespace std;

typedef unsigned int uint;

vector<string> ReadHeader(ifstream& ifs, int& HeaderLines) {
  string Temp;
  vector<string> Return;
  HeaderLines = 0;
  while(ifs.peek() == '#' || ifs.peek() == '%') {
    getline(ifs, Temp);
    Return.push_back(Temp);
    HeaderLines++;
  }
  return Return;
}


void ReadDatFile(const string& FileName, vector<vector<double> >& Data,
		 vector<string>& Header, const bool Transpose)
{
  // Get the number of lines in the file
  char LengthChar[9];
  FILE* fp = popen(("wc -l " + FileName).c_str(), "r");
  fgets(LengthChar, 9, fp);
  pclose(fp);
  int FileLength = atoi(LengthChar);
  
  // Open the file stream
  ifstream ifs(FileName.c_str(), ifstream::in);
  if(!ifs.is_open()) {
    cerr << "Couldn't open '" << FileName << "'" << endl;
    throw(1);
  }
  
  // Get the header and number of header lines
  int HeaderLines = 0;
  Header = ReadHeader(ifs, HeaderLines);
  
  // Read the data
  vector<double> Line;
  unsigned int NumLines = FileLength - HeaderLines;
  double Test = 0.0;
  string LineString;
  getline(ifs, LineString);
  istringstream LineStream(LineString);
  while(LineStream >> Test) Line.push_back(Test);
  if(Transpose) {
    Data = vector<vector<double> >(Line.size(), vector<double>(NumLines));
    for(uint j=0; j<Line.size(); ++j) { Data[j][0] = Line[j]; }
    for(uint i=1; i<NumLines; ++i) {
      for(uint j=0; j<Line.size(); ++j) {
	ifs >> Data[j][i];
      }
    }
  } else {
    Data = vector<vector<double> >(NumLines, Line);
    for(uint i=1; i<Data.size(); ++i) {
      for(uint j=0; j<Data[i].size(); ++j) {
	ifs >> Data[i][j];
      }
    }
  }
  
  // Close the file stream
  ifs.close();
}


// This function writes a data file with a single column
// Note that the Header is empty by default
void WriteDatFile(const string& FileName, const vector<double>& Data,
		  const vector<string>& Header)
{
  // Open the file stream
  ofstream ofs(FileName.c_str(), ofstream::out);
  ofs << setprecision(14) << flush;
  
  // Write the header
  for(uint i=0; i<Header.size(); ++i) {
    ofs << Header[i] << endl;
  }
  
  // Write the data
  for(uint i=0; i<Data.size()-1; ++i) {
    ofs << Data[i] << " ";
  }
  ofs << Data[Data.size()-1] << endl;
  
  // Close the file stream
  ofs.close();
}


// This function writes a dat file
// Note that the Header is empty by default
//ORIENTATION!!!
void WriteDatFile(const string& FileName, const vector<vector<double> >& Data,
		  const vector<string>& Header)
{
  // Open the file stream
  ofstream ofs(FileName.c_str(), ofstream::out);
  ofs << setprecision(14) << flush;
  
  // Write the header
  for(uint i=0; i<Header.size(); ++i) {
    ofs << Header[i] << endl;
  }
  
  // Write the data
  for(uint i=0; i<Data.size(); ++i) {
    for(uint j=0; j<Data[i].size()-1; ++j) {
      ofs << Data[i][j] << " ";
    }
    ofs << Data[i][Data[i].size()-1] << endl;
  }
  
  // Close the file stream
  ofs.close();
}


// This function writes a dat file with a time column
// Note that the Header is empty by default
//ORIENTATION!!!
void WriteDatFile(const string& FileName, const vector<double>& Time,
		  const vector<vector<double> >& Data, const vector<string>& Header)
{
  // Make sure Time and Data have same length
  if(Data.size()<1) {
    cerr << "ERROR!!!\n" << "No data input.  Nothing written." << endl;
    return;
  }
  if(Time.size() != Data[0].size()) {
    cerr << "ERROR!!!\n"
	 << "Time and Data vectors have wrong dimensions.\n"
	 << "Outputting to separate files instead!" << endl;
    WriteDatFile(FileName+".time", Time, Header);
    WriteDatFile(FileName+".data", Data, Header);
  } else {
    
    // Open the file stream
    ofstream ofs(FileName.c_str(), ofstream::out);
    ofs << setprecision(14) << flush;
    
    // Write the header
    for(uint i=0; i<Header.size(); ++i) {
      ofs << Header[i] << endl;
    }
    
    // Write the time and data
    for(uint i=0; i<Time.size(); ++i) { // Loop over times
      ofs << Time[i] << " ";
      for(uint j=0; j<Data.size()-1; ++j) { // Loop over components
	ofs << Data[j][i] << " ";
      }
      ofs << Data[Data.size()-1][i] << endl;
    }
    
    // Close the file stream
    ofs.close();
  }
}
