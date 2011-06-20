#ifndef EASYPARSER_HPP
#define EASYPARSER_HPP

#include <vector>
#include <string>

std::vector<std::string>& split(const std::string& s, std::vector<std::string>& elems, char delim=';');
std::vector<std::string> split(const std::string &s, char delim=';');
std::string TrimWhiteSpace(const std::string& String);
std::string StripComments(const std::string& String, const char CommentChar='#');

void SplitStringToKeysAndValues(const std::string& String, std::vector<std::string>& Keys, std::vector<std::string>& Values);

int StringToInt(const std::string& String);
bool StringToBool(const std::string& String);
double StringToDouble(const std::string& String);
std::vector<int> StringToVectorInt(const std::string& String);
std::vector<double> StringToVectorDouble(const std::string& String);
std::vector<std::string> StringToVectorString(const std::string& String);

std::string DoubleToString(const double x, const unsigned int Width=0);

#endif // EASYPARSER_HPP
