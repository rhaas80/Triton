#ifndef FFT_HPP
#define FFT_HPP

#include <vector>

namespace WaveformUtilities {
  
  std::vector<double> TimeToFrequency(const std::vector<double>& Time);
  
  /// The following call the Numerical Recipes fft routines (from fourier.h).
  void  fft(const std::vector<double>& ReT, const std::vector<double>& ImT, std::vector<double>& ReF, std::vector<double>& ImF);
  void  fft(const std::vector<double>& T, const std::vector<double>& ReT, const std::vector<double>& ImT, std::vector<double>& F,
	    std::vector<double>& ReF, std::vector<double>& ImF);
  void ifft(const std::vector<double>& ReF, const std::vector<double>& ImF, std::vector<double>& ReT, std::vector<double>& ImT);
  
  void  realfft(std::vector<double>& data);
  void realifft(std::vector<double>& data);
  
  std::vector<double> convlv(const std::vector<double>& data, const std::vector<double>& respns, const int isign);
  
}

#endif // FFT_HPP
