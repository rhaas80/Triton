#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#ifndef THROW_REPLACEMENT
#define THROW_REPLACEMENT
#include <iostream>
#define throw(message) \
  { std::cerr << "ERROR: " << message << "\n       in file " << __FILE__ << " at line " << __LINE__ << std::endl; throw(1); }
//  { fprintf(stderr, "ERROR: %s\n       in file %s at line %d\n", message, __FILE__, __LINE__); throw(1); }
#endif // THROW_REPLACEMENT

#ifndef EulerGamma
#define EulerGamma 0.57721566490153286061
#endif // EulerGamma

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // M_PI

#ifndef M_E
#define M_E 2.71828182845904523536
#endif // M_E

#endif // UTILITIES_HPP
