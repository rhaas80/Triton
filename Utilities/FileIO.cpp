#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "FileIO.hpp"
#include "VectorFunctions.hpp"
using namespace std;
namespace WU = WaveformUtilities;

// #include <H5Cpp.h>
// using namespace H5;

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


void WU::ReadDatFile(const string& FileName, vector<vector<double> >& Data,
                     vector<string>& Header, const bool Transpose)
{
  // If the FileName points to an h5 file and dataset, just get that
  if(FileName.find(".h5:")!=string::npos) {
    Throw1WithMessage("This capability has been removed from the code due to module hell.  Uncomment and recompile at your own risk!");
    // if(!Transpose) {
    //   Throw1WithMessage("Don't yet know how to return un-transposed h5 file.  It shouldn't be hard to implement...");
    // }
    // size_t found = FileName.find(".h5:");
    // std::string FILE_NAME = FileName.substr(0, found+3);
    // std::string DATASET_NAME = FileName.substr(found+4);
    // // Open the specified file and the specified dataset in the file.
    // H5File file( FILE_NAME, H5F_ACC_RDONLY );
    // DataSet dataset = file.openDataSet( DATASET_NAME );
    // // Get dataspace of the dataset.
    // DataSpace dataspace = dataset.getSpace();
    // // Get the number of dimensions in the dataspace.
    // int rank = dataspace.getSimpleExtentNdims();
    // if(rank != 2) {
    //   cerr << "rank=" << rank << endl;
    //   Throw1WithMessage("Unknown data shape");
    // }
    // // Get the dimension size of each dimension in the dataspace
    // hsize_t dims_out[2];
    // int ndims = dataspace.getSimpleExtentDims( dims_out, NULL);
    // int NTimes = dims_out[0];
    // int NModes = dims_out[1];
    // //ORIENTATION!!!
    // Data = vector<vector<double> >(NModes, vector<double>(NTimes));
    // //  Define hyperslab in the dataset; implicitly giving stride and
    // //  block NULL
    // hsize_t      offset[2];	// hyperslab offset in the file
    // hsize_t      count[2];	// size of the hyperslab in the file
    // offset[0] = 0;
    // offset[1] = 0;
    // count[0]  = NTimes;
    // count[1]  = 1;
    // dataspace.selectHyperslab( H5S_SELECT_SET, count, offset );
    // // Define the memory dataspace
    // hsize_t     dimsm[2];              /* memory space dimensions */
    // dimsm[0] = NTimes;
    // dimsm[1] = 1;
    // DataSpace memspace( 2, dimsm );
    // // Define memory hyperslab.
    // hsize_t      offset_out[2];	// hyperslab offset in memory
    // hsize_t      count_out[2];	// size of the hyperslab in memory
    // offset_out[0] = 0;
    // offset_out[1] = 0;
    // count_out[0]  = NTimes;
    // count_out[1]  = 1;
    // memspace.selectHyperslab( H5S_SELECT_SET, count_out, offset_out );
    // // Read data from hyperslab in the file into the hyperslab in memory
    // for(unsigned int mode=0; mode<NModes; ++mode) {
    //   offset[1] = mode;
    //   dataspace.selectHyperslab( H5S_SELECT_SET, count, offset );
    //   dataset.read( &Data[mode][0], PredType::NATIVE_DOUBLE, memspace, dataspace );
    // }
    // Header = vector<string>(0);
    // return;
  }

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
    Throw1WithMessage("Bad file name");
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
void WU::WriteDatFile(const string& FileName, const vector<double>& Data,
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
void WU::WriteDatFile(const string& FileName, const vector<vector<double> >& Data,
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
void WU::WriteDatFile(const string& FileName, const vector<double>& Time,
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
