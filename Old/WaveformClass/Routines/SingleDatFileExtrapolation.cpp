#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cmath>

#include "VectorFunctions.hpp"
#include "Interpolate.hpp"
#include "Fit.hpp"
#include "EasyParser.hpp"
#include "FileIO.hpp"

using namespace std;

#define throw(message) \
{printf("ERROR: %s\n\tin file %s at line %d\n", message,__FILE__,__LINE__); throw(1);}


int BufferSize = 1000;

class DataSet {
private:  // Member data
  string DataType;
  vector<double> DataTime;
  vector<double> Radii;
  vector<vector<double> > Data;
  
public:  // Constructors
  DataSet() : DataType(""), DataTime(0), Radii(0), Data(0, vector<double>(0)) { }
  DataSet(const string& DataTypeIn, const vector<vector<double> >& DataIn, const vector<double>& TimeIn, const vector<double>& RadiiIn,
	  const double M=1.0, const double MinStep=0.0, const double MinTime=0.0)
    : DataType(DataTypeIn), DataTime(0), Radii(RadiiIn), Data(RadiiIn.size(), vector<double>(0))
  {
    vector<vector<double> > Times(RadiiIn.size(), vector<double>(TimeIn.size()));
    for(unsigned int i=0; i<Times.size(); ++i) {
      Times[i] = TimeIn - (RadiiIn[i] + 2.0*M*log((RadiiIn[i]/(2.0*M))-1.0));
    }
    DataTime = Intersection(Times, MinStep, MinTime);
    for(unsigned int i=0; i<Times.size(); ++i) {
      Interpolate(Times[i], DataIn[i], DataTime, Data[i]);
    }
  }
  
public:  // Member functions
  const string& Type() const { return DataType; }
  unsigned int Size() const { return Data.size(); }
  const vector<double>& Time() const { return DataTime; }
  vector<double> Extrapolate(const int ExtrapOrder=2) const {
    if(ExtrapOrder<0) { return Data[Data.size()+ExtrapOrder]; }
    vector<double> Extrapolated(Data[0].size());
    vector<double> OneOverR(Radii.size());
    for(unsigned int i=0; i<OneOverR.size(); ++i) {
      OneOverR[i] = 1.0/Radii[i];
    }
    vector<double> Datum(Data.size());
    const vector<double> Sigma(Data.size(), 3e-6);  // These sigmas should never be less than 3e-6.
    Fit DataFit(OneOverR, Datum, Sigma, ExtrapOrder);
    for(unsigned int i=0; i<Extrapolated.size(); ++i) {  // Loop over time steps
      for(unsigned int j=0; j<Data.size(); ++j) {  // Loop over data points
	Datum[j] = Data[j][i];
      }
      DataFit.fit();
      Extrapolated[i] = DataFit.Evaluate(0.0);
    }
    return Extrapolated;
  }
};


int main (void) {
  // Get the input options
  double M = 1.0;
  double MinStep = 0.005;
  double MinTime = 0.0;
  string FileName = "Adm.dat";
  vector<int> ExtrapolationOrders(StringToVectorInt("-1 1 2 3 4 5 6"));
  
  // Read the data
  vector<vector<double> > Data(0, vector<double>(0));
  vector<string> Header(0, "");
  ReadDatFile(FileName, Data, Header, true);
  
  // Look through the header to find out what data sets and radii we have
  vector<string> DataTypes(0, "");
  vector<vector<int> > DataIndices(0, vector<int>(0));
  vector<vector<double> > DataRadii(0, vector<double>(0));
  for(unsigned int i=0; i<Header.size(); ++i) {
    if(Header[i].compare(0,3,"# [")==0 && Header[i].compare(0,8,"# [1] = ")!=0) {
      size_t Bracket1 = Header[i].find("[");
      size_t Bracket2 = Header[i].find("]", Bracket1);
      size_t Paren1 = Header[i].rfind("(");
      size_t Paren2 = Header[i].find(")",Paren1);
      size_t Equals1 = Header[i].rfind("=", Paren1);
      size_t Equals2 = Header[i].find( "=", Paren1);
      if(Bracket1 != string::npos && Bracket2 != string::npos && Paren1 != string::npos
	 && Paren2 != string::npos && Equals1 != string::npos && Equals2 != string::npos)
	{
	  string DataType = TrimWhiteSpace(Header[i].substr(Equals1+1, Paren1-Equals1-1));
	  int DataIndex = StringToInt(Header[i].substr(Bracket1+1, Bracket2-Bracket1-1))-1;
	  double DataRadius = StringToDouble(Header[i].substr(Equals2+1, Paren2-Equals2-1));
	  if(DataTypes.size()>0 && DataType == DataTypes[DataTypes.size()-1]) {
	    DataIndices[DataIndices.size()-1].push_back(DataIndex);
	    DataRadii[DataRadii.size()-1].push_back(DataRadius);
	  } else {
	    DataTypes.push_back(DataType);
	    DataIndices.push_back(vector<int>(1, DataIndex));
	    DataRadii.push_back(vector<double>(1, DataRadius));
	  }
	} else {
	cerr << "Choked on \"" << Header[i] << "\" in " << __FILE__ << endl;
	exit(1);
      }
    }
  }
  
  // Assemble into individual data sets
  vector<DataSet> DataSets(DataTypes.size());
  const vector<double> TimeIn = Data[0];
  for(unsigned int i=0; i<DataSets.size(); ++i) {
    vector<vector<double> > DataIn(DataIndices[i].size(), vector<double>(0));
    for(unsigned int j=0; j<DataIn.size(); ++j) {
      DataIn[j] = Data[DataIndices[i][j]];
    }
    DataSets[i] = DataSet(DataTypes[i], DataIn, TimeIn, DataRadii[i], M, MinStep, MinTime);
  }
  Data.clear();
  Header.clear();
  
  // Extrapolate each in turn, and output
  for(unsigned int i=0; i<DataSets.size(); ++i) {
    cout << "Extrapolating " << DataSets[i].Type() << "... " << endl;
    for(unsigned int j=0; j<ExtrapolationOrders.size(); ++j) {
      if(DataSets[i].Size() > (unsigned int)(abs(ExtrapolationOrders[j])+1)) {
	char ExtrapolatedFile[BufferSize];
	sprintf(ExtrapolatedFile, ("Extrapolated_" + DataSets[i].Type() + "_N%d.dat").c_str(), ExtrapolationOrders[j]);
	cout << "\tWorking on " << string(ExtrapolatedFile) << "... " << flush;
	vector<double> Extrapolated = DataSets[i].Extrapolate(ExtrapolationOrders[j]);
	ofstream ofs(ExtrapolatedFile, ofstream::out);
	ofs << "# [1] = (t-r*)\n"
	    << "# [2] = " << DataSets[i].Type() << endl;
	ofs << setprecision(14) << flush;
	for(unsigned int k=0; k<DataSets[i].Time().size(); ++k) {
	  ofs << DataSets[i].Time()[k] << " " << Extrapolated[k] << endl;
	}
	ofs.close();
	cout << "☺" << endl;
      } else {
	cout << "\tSkipping " << DataSets[i].Type() << " with N=" << ExtrapolationOrders[j] << "; insufficient input data." << endl;;
      }
    }
    cout << "☺\n" << endl;
  }
  
  return 0;
}
