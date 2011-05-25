#include "NumericalRecipes.hpp"

#include <fstream>
#include <iomanip>
#include <ctime>

#include "OrbitalPhasing_T1.hpp"
#include "OrbitalPhasing_T2.hpp"
#include "OrbitalPhasing_T3.hpp"
#include "OrbitalPhasing_T4.hpp"
#include "OrbitalPhasing_EOB.hpp"
using namespace std;

int main() {
  const bool SpeedComparison = false;
  const bool WaveformOutput = true;
  
  const double q = 6;
  const double delta=(q-1.0)/(q+1.0);
  const double chis = 0;//-0.9900;
  const double v0 = 0.11;//0.02025;
  vector<double> t, v, Phi;
  vector<double> r, prstar, pPhi;
  const int NPoints = 10000;
  const int nsave = 40;
  const bool denseish = true;
  cout << "v0 = " << v0 << "\tdelta = " << delta << "\tchis = " << chis << endl;
  
  clock_t start,end;
  
  const unsigned int N=1000;
  
  if(SpeedComparison) {
    cout << N << " iterations of TaylorT1 ... " << endl;
    start = clock();
    for(unsigned int i=0; i<N; ++i) {
      WaveformUtilities::TaylorT1(delta, chis, v0, t, v, Phi, nsave, denseish);
    }
    end = clock();
    cout << "... took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds." << endl;
    
    cout << N << " iterations of TaylorT2 ... " << endl;
    start = clock();
    for(unsigned int i=0; i<N; ++i) {
      WaveformUtilities::TaylorT2(delta, chis, v0, t, v, Phi, NPoints);
    }
    end = clock();
    cout << "... took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds." << endl;
    
    cout << N << " iterations of TaylorT3 ... " << endl;
    start = clock();
    for(unsigned int i=0; i<N; ++i) {
      WaveformUtilities::TaylorT3(delta, chis, v0, t, v, Phi, NPoints);
    }
    end = clock();
    cout << "... took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds." << endl;
    
    cout << N << " iterations of TaylorT4 ... " << endl;
    start = clock();
    for(unsigned int i=0; i<N; ++i) {
      WaveformUtilities::TaylorT4(delta, chis, v0, t, v, Phi, nsave, denseish);
    }
    end = clock();
    cout << "... took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds." << endl;
    
//     cout << N << " iterations of EOB ... " << endl;
//     start = clock();
//     for(unsigned int i=0; i<N; ++i) {
//       WaveformUtilities::EOB(delta, chis, v0, t, v, Phi, r, prstar, pPhi, nsave, denseish);
//     }
//     end = clock();
//     cout << "... took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds." << endl;
    
  } // if(SpeedComparison)
  
  if(WaveformOutput) {
    {
      cout << "Calculating T1 ... " << flush;
      start = clock();
      WaveformUtilities::TaylorT1(delta, chis, v0, t, v, Phi, nsave, denseish);
      end = clock();
      cout << "took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds.  ☺" << endl;
      ofstream ofs("Outputs/TestPN_T1.dat");
      ofs << "# [1] = t" << endl
	  << "# [2] = v" << endl
	  << "# [3] = Phi" << endl;
      ofs << setprecision(16);
      for(unsigned int i=0; i<t.size(); ++i) {
	ofs << t[i] << " " << v[i] << " " << Phi[i] << endl;
      }
      ofs.close();
    }
    
    {
      cout << "Calculating T2 ... " << flush;
      start = clock();
      WaveformUtilities::TaylorT2(delta, chis, v0, t, v, Phi, NPoints);
      end = clock();
      cout << "took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds.  ☺" << endl;
      ofstream ofs("Outputs/TestPN_T2.dat");
      ofs << "# [1] = t" << endl
	  << "# [2] = v" << endl
	  << "# [3] = Phi" << endl;
      ofs << setprecision(16);
      for(unsigned int i=0; i<t.size(); ++i) {
	ofs << t[i] << " " << v[i] << " " << Phi[i] << endl;
      }
      ofs.close();
    }
    
    {
      cout << "Calculating T3 ... " << flush;
      start = clock();
      WaveformUtilities::TaylorT3(delta, chis, v0, t, v, Phi, NPoints);
      end = clock();
      cout << "took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds.  ☺" << endl;
      ofstream ofs("Outputs/TestPN_T3.dat");
      ofs << "# [1] = t" << endl
	  << "# [2] = v" << endl
	  << "# [3] = Phi" << endl;
      ofs << setprecision(16);
      for(unsigned int i=0; i<t.size(); ++i) {
	ofs << t[i] << " " << v[i] << " " << Phi[i] << endl;
      }
      ofs.close();
    }
    
    {
      cout << "Calculating T4 ... " << flush;
      start = clock();
      WaveformUtilities::TaylorT4(delta, chis, v0, t, v, Phi, nsave, denseish);
      end = clock();
      cout << "took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds.  ☺" << endl;
      ofstream ofs("Outputs/TestPN_T4.dat");
      ofs << "# [1] = t" << endl
	  << "# [2] = v" << endl
	  << "# [3] = Phi" << endl;
      ofs << setprecision(16);
      for(unsigned int i=0; i<t.size(); ++i) {
	ofs << t[i] << " " << v[i] << " " << Phi[i] << endl;
      }
      ofs.close();
    }
    
    {
      cout << "Calculating EOB ... " << flush;
      start = clock();
      WaveformUtilities::EOB(delta, chis, v0, t, v, Phi, r, prstar, pPhi, nsave, denseish);
      end = clock();
      cout << "took " << setprecision(10) << double(end-start)/double(CLOCKS_PER_SEC) << " seconds.  ☺" << endl;
      ofstream ofs("Outputs/TestPN_EOB.dat");
      ofs << "# [1] = t" << endl
	  << "# [2] = v" << endl
	  << "# [3] = Phi" << endl
	  << "# [4] = r" << endl
	  << "# [5] = prstar" << endl
	  << "# [6] = pPhi" << endl;
      ofs << setprecision(16);
      for(unsigned int i=0; i<t.size(); ++i) {
	ofs << t[i] << " " << v[i] << " " << Phi[i] << " " << r[i] << " " << prstar[i] << " " << pPhi[i] << endl;
      }
      ofs.close();
    }
  } // if WaveformOutput
  
  return 0;
}
