#ifndef FILEIO_HPP
#define FILEIO_HPP

#include <vector>
#include <string>

namespace WaveformUtilities {

  void ReadDatFile(const std::string& FileName, std::vector<std::vector<double> >& Data,
                   std::vector<std::string>& Header, const bool Transpose=false);

  void WriteDatFile(const std::string& FileName, const std::vector<double>& Data,
                    const std::vector<std::string>& Header = std::vector<std::string>(0));

  //ORIENTATION!!!
  void WriteDatFile(const std::string& FileName, const std::vector<std::vector<double> >& Data,
                    const std::vector<std::string>& Header = std::vector<std::string>(0));

  //ORIENTATION!!!
  void WriteDatFile(const std::string& FileName, const std::vector<double>& Time,
                    const std::vector<std::vector<double> >& Data,
                    const std::vector<std::string>& Header = std::vector<std::string>(0));

}

#endif // FILEIO_HPP
