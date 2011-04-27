#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#define throw(message) \
  { printf("ERROR: %s\n\tin file %s at line %d\n", message, __FILE__, __LINE__); throw(1); }

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
