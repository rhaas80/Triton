#include "NumericalRecipes.hpp"

#include <iostream>

#include "VectorFunctions.hpp"
#include "Utilities.hpp"
#include "Waveform.hpp"

#include <fstream>
#include <iomanip>
#include <ctime>
#include <sys/time.h>

using namespace std;

using WaveformObjects::Waveform;

long long
timeval_diff(struct timeval *difference,
             struct timeval *end_time,
             struct timeval *start_time
            )
{
  struct timeval temp_diff;

  if(difference==NULL)
  {
    difference=&temp_diff;
  }

  difference->tv_sec =end_time->tv_sec -start_time->tv_sec ;
  difference->tv_usec=end_time->tv_usec-start_time->tv_usec;

  /* Using while instead of if below makes the code slightly more robust. */

  while(difference->tv_usec<0)
  {
    difference->tv_usec+=1000000;
    difference->tv_sec -=1;
  }

  return 1000000LL*difference->tv_sec+
                   difference->tv_usec;

} /* timeval_diff() */


int main() {
  timeval startval, endval, diff;
  long long difference;
  
  time_t start,end;
  cout << setprecision(15);
  
  gettimeofday(&startval,NULL);
  Waveform W1("/Users/boyle/Research/Data/nrar/SpEC-Case01/SpEC-Case01-Lev1/SpEC-Case01-Lev1-short.bbh", "ReIm");
  gettimeofday(&endval,NULL);
  difference = timeval_diff(&diff, &endval, &startval);
  cout << "H5 read 1 took " << difference/1000000. << " seconds." << endl;
  cout << "W1.NTimes()=" << W1.NTimes() << "\tW1.NModes()=" << W1.NModes() << endl;
  cout << "W1.LM()=" << W1.LM() << endl;
  
  gettimeofday(&startval,NULL);
  Output("/Users/boyle/Research/Data/nrar/SpEC-Case01/SpEC-Case01-Lev1/FiniteRadius/h_TestH5_1.dat", W1);
  gettimeofday(&endval,NULL);
  difference = timeval_diff(&diff, &endval, &startval);
  cout << "Dat output 1 took " << difference/1000000. << " seconds." << endl;
  
  gettimeofday(&startval,NULL);
  Waveform W2("/Users/boyle/Research/Data/nrar/SpEC-Case01/SpEC-Case01-Lev1/FiniteRadius/h_TestH5_1.dat", "MagArg");
  gettimeofday(&endval,NULL);
  difference = timeval_diff(&diff, &endval, &startval);
  cout << "Dat read took " << difference/1000000. << " seconds." << endl;
  cout << "W2.NTimes()=" << W2.NTimes() << "\tW2.NModes()=" << W2.NModes() << endl;
  cout << "W2.LM()=" << W2.LM() << endl;
  
  gettimeofday(&startval,NULL);
  Output("/Users/boyle/Research/Data/nrar/SpEC-Case01/SpEC-Case01-Lev1/FiniteRadius/h_TestH5_2.dat", W2);
  gettimeofday(&endval,NULL);
  difference = timeval_diff(&diff, &endval, &startval);
  cout << "Dat output 2 took " << difference/1000000. << " seconds." << endl;
  
  gettimeofday(&startval,NULL);
  Waveform W3("/Users/boyle/Research/Data/nrar/SpEC-Case01/SpEC-Case01-Lev1/SpEC-Case01-Lev1-short.bbh", "ReIm");
  gettimeofday(&endval,NULL);
  difference = timeval_diff(&diff, &endval, &startval);
  cout << "H5 read 2 took " << difference/1000000. << " seconds." << endl;
  cout << "W3.NTimes()=" << W3.NTimes() << "\tW3.NModes()=" << W3.NModes() << endl;
  cout << "W3.LM()=" << W3.LM() << endl;
  
  return 0;
}
