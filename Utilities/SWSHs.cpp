#include "SWSHs.hpp"
#include <cstdlib>
#include "VectorFunctions.hpp"
using namespace std;
namespace WU = WaveformUtilities;

#ifdef __INTEL_COMPILER
#pragma optimize("", off)
#endif
#if (__GNUC__ > 3 && __GNUC_MINOR__ > 3)
#pragma GCC optimize(0)
#endif

namespace WaveformUtilities {
  #include <cmath>
}

void WU::SWSH(const int L, const int M, const double vartheta, const double varphi, double& amp, double& arg) {
  if(L<2) { throw("l<2 unsupported."); }
  if(labs(M)>L) { throw("abs(m)>l unsupported for s=-2 spin-weighted spherical harmonics."); }
  if(L>12) { throw("l>12 unsupported."); }
  
  switch(L) {
  case 2:
    switch(M) {
    case -2:
      amp = 0.630783130505040012*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 1.26156626101008002*cos(0.5*vartheta)*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -varphi + M_PI;
      } else {
        arg = -varphi;
      }
      return;
    case 0:
      amp = 0.38627420202318958*::pow(sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 1.26156626101008002*::pow(cos(0.5*vartheta),3)*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = varphi + M_PI;
      } else {
        arg = varphi;
      }
      return;
    case 2:
      amp = 0.630783130505040012*::pow(cos(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    } // switch(M)
    
  case 3:
    switch(M) {
    case -3:
      amp = 1.82818319785786294*cos(0.5*vartheta)*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.746352665180230783*(2. + 3.*cos(vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 1.18008717985328702*cos(0.5*vartheta)*(1. + 3.*cos(vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -varphi + M_PI;
      } else {
        arg = -varphi;
      }
      return;
    case 0:
      amp = 1.02198547643328236*cos(vartheta)*::pow(sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 1.18008717985328702*::pow(cos(0.5*vartheta),3)*(-1. + 3.*cos(vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = varphi + M_PI;
      } else {
        arg = varphi;
      }
      return;
    case 2:
      amp = 0.746352665180230783*::pow(cos(0.5*vartheta),4)*(-2. + 3.*cos(vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -1.82818319785786294*::pow(cos(0.5*vartheta),5)*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    } // switch(M)
    
  case 4:
    switch(M) {
    case -4:
      amp = 4.4781159910813847*::pow(cos(0.5*vartheta),2)*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 3.16650618423356409*cos(0.5*vartheta)*(1. + 2.*cos(vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.423142187660817215*(9. + 14.*cos(vartheta) + 7.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.598413420602149017*cos(0.5*vartheta)*(6. + 7.*cos(vartheta) + 7.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -varphi + M_PI;
      } else {
        arg = -varphi;
      }
      return;
    case 0:
      amp = 0.167261635889322292*(5. + 7.*cos(2.*vartheta))*::pow(sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.598413420602149017*::pow(cos(0.5*vartheta),3)*(6. - 7.*cos(vartheta) + 7.*cos(2.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = varphi + M_PI;
      } else {
        arg = varphi;
      }
      return;
    case 2:
      amp = 0.423142187660817215*::pow(cos(0.5*vartheta),4)*(9. - 14.*cos(vartheta) + 7.*cos(2.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -3.16650618423356409*::pow(cos(0.5*vartheta),5)*(-1. + 2.*cos(vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 4.4781159910813847*::pow(cos(0.5*vartheta),6)*::pow(sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    } // switch(M)
    
  case 5:
    switch(M) {
    case -5:
      amp = 10.2490127544388841*::pow(cos(0.5*vartheta),3)*::pow(sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 3.24102240721428709*::pow(cos(0.5*vartheta),2)*(2. + 5.*cos(vartheta))*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.572937230529692607*cos(0.5*vartheta)*(17. + 24.*cos(vartheta) + 15.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.233900644906847193*(32. + 57.*cos(vartheta) + 36.*cos(2.*vartheta) + 15.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.309421468960572107*cos(0.5*vartheta)*(14. + 33.*cos(vartheta) + 18.*cos(2.*vartheta) + 15.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -varphi + M_PI;
      } else {
        arg = -varphi;
      }
      return;
    case 0:
      amp = 0.847385591630449638*cos(vartheta)*(1. + 3.*cos(2.*vartheta))*::pow(sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.309421468960572107*::pow(cos(0.5*vartheta),3)*(-14. + 33.*cos(vartheta) - 18.*cos(2.*vartheta) + 15.*cos(3.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = varphi + M_PI;
      } else {
        arg = varphi;
      }
      return;
    case 2:
      amp = 0.233900644906847193*::pow(cos(0.5*vartheta),4)*(-32. + 57.*cos(vartheta) - 36.*cos(2.*vartheta) + 15.*cos(3.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.572937230529692607*::pow(cos(0.5*vartheta),5)*(17. - 24.*cos(vartheta) + 15.*cos(2.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 3.24102240721428709*::pow(cos(0.5*vartheta),6)*(-2. + 5.*cos(vartheta))*::pow(sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -10.2490127544388841*::pow(cos(0.5*vartheta),7)*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    } // switch(M)
    
  case 6:
    switch(M) {
    case -6:
      amp = 22.6292074407870777*::pow(cos(0.5*vartheta),4)*::pow(sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 13.0649790074863016*::pow(cos(0.5*vartheta),3)*(1. + 3.*cos(vartheta))*::pow(sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.696365720891772932*::pow(cos(0.5*vartheta),2)*(35. + 44.*cos(vartheta) + 33.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.190707606802885278*cos(0.5*vartheta)*(98. + 185.*cos(vartheta) + 110.*cos(2.*vartheta) + 55.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.00794615028345355324*(1709. + 3096.*cos(vartheta) + 2340.*cos(2.*vartheta) + 1320.*cos(3.*vartheta) + 495.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.0502558670514116131*cos(0.5*vartheta)*(161. + 252.*cos(vartheta) + 252.*cos(2.*vartheta) + 132.*cos(3.*vartheta) + 99.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -varphi + M_PI;
      } else {
        arg = -varphi;
      }
      return;
    case 0:
      amp = 0.0407119053667322336*(35. + 60.*cos(2.*vartheta) + 33.*cos(4.*vartheta))*::pow(sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.0502558670514116131*::pow(cos(0.5*vartheta),3)*(161. - 252.*cos(vartheta) + 252.*cos(2.*vartheta) - 132.*cos(3.*vartheta) + 99.*cos(4.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = varphi + M_PI;
      } else {
        arg = varphi;
      }
      return;
    case 2:
      amp = 0.00794615028345355324*::pow(cos(0.5*vartheta),4)*(1709. - 3096.*cos(vartheta) + 2340.*cos(2.*vartheta) - 1320.*cos(3.*vartheta) + 495.*cos(4.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.190707606802885278*::pow(cos(0.5*vartheta),5)*(-98. + 185.*cos(vartheta) - 110.*cos(2.*vartheta) + 55.*cos(3.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.696365720891772932*::pow(cos(0.5*vartheta),6)*(35. - 44.*cos(vartheta) + 33.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -13.0649790074863016*::pow(cos(0.5*vartheta),7)*(-1. + 3.*cos(vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 22.6292074407870777*::pow(cos(0.5*vartheta),8)*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 6*varphi + M_PI;
      } else {
        arg = 6*varphi;
      }
      return;
    } // switch(M)
    
  case 7:
    switch(M) {
    case -7:
      amp = 48.8846752114075978*::pow(cos(0.5*vartheta),5)*::pow(sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = -7*varphi + M_PI;
      } else {
        arg = -7*varphi;
      }
      return;
    case -6:
      amp = 13.0649790074863016*::pow(cos(0.5*vartheta),4)*(2. + 7.*cos(vartheta))*::pow(sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 0.640563297152430255*::pow(cos(0.5*vartheta),3)*(93. + 104.*cos(vartheta) + 91.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.320281648576215128*::pow(cos(0.5*vartheta),2)*(140. + 285.*cos(vartheta) + 156.*cos(2.*vartheta) + 91.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.0120710688132246744*cos(0.5*vartheta)*(3115. + 5456.*cos(vartheta) + 4268.*cos(2.*vartheta) + 2288.*cos(3.*vartheta) + 1001.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.00426776730700030887*(5220. + 9810.*cos(vartheta) + 7920.*cos(2.*vartheta) + 5445.*cos(3.*vartheta) + 2860.*cos(4.*vartheta) + 1001.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.00522692612154132162*cos(0.5*vartheta)*(1890. + 4130.*cos(vartheta) + 3080.*cos(2.*vartheta) + 2805.*cos(3.*vartheta) + 1430.*cos(4.*vartheta) + 1001.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -varphi + M_PI;
      } else {
        arg = -varphi;
      }
      return;
    case 0:
      amp = 0.0195573667327867542*cos(vartheta)*(109. + 132.*cos(2.*vartheta) + 143.*cos(4.*vartheta))*::pow(sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.00522692612154132162*::pow(cos(0.5*vartheta),3)*(-1890. + 4130.*cos(vartheta) - 3080.*cos(2.*vartheta) + 2805.*cos(3.*vartheta) - 1430.*cos(4.*vartheta) + 1001.*cos(5.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = varphi + M_PI;
      } else {
        arg = varphi;
      }
      return;
    case 2:
      amp = 0.00426776730700030887*::pow(cos(0.5*vartheta),4)*(-5220. + 9810.*cos(vartheta) - 7920.*cos(2.*vartheta) + 5445.*cos(3.*vartheta) - 2860.*cos(4.*vartheta) + 1001.*cos(5.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.0120710688132246744*::pow(cos(0.5*vartheta),5)*(3115. - 5456.*cos(vartheta) + 4268.*cos(2.*vartheta) - 2288.*cos(3.*vartheta) + 1001.*cos(4.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.320281648576215128*::pow(cos(0.5*vartheta),6)*(-140. + 285.*cos(vartheta) - 156.*cos(2.*vartheta) + 91.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -0.640563297152430255*::pow(cos(0.5*vartheta),7)*(93. - 104.*cos(vartheta) + 91.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 13.0649790074863016*::pow(cos(0.5*vartheta),8)*(-2. + 7.*cos(vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 6*varphi + M_PI;
      } else {
        arg = 6*varphi;
      }
      return;
    case 7:
      amp = -48.8846752114075978*::pow(cos(0.5*vartheta),9)*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = 7*varphi + M_PI;
      } else {
        arg = 7*varphi;
      }
      return;
    } // switch(M)
    
  case 8:
    switch(M) {
    case -8:
      amp = 104.083421669251111*::pow(cos(0.5*vartheta),6)*::pow(sin(0.5*vartheta),10);
      if(amp<0) {
        amp = -amp;
        arg = -8*varphi + M_PI;
      } else {
        arg = -8*varphi;
      }
      return;
    case -7:
      amp = 52.0417108346255555*::pow(cos(0.5*vartheta),5)*(1. + 4.*cos(vartheta))*::pow(sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = -7*varphi + M_PI;
      } else {
        arg = -7*varphi;
      }
      return;
    case -6:
      amp = 285.044189552854222*::pow(cos(0.5*vartheta),4)*(1. + 2.*cos(vartheta))*sin(0.78539816339744831 - 0.5*vartheta)*sin(0.78539816339744831 + 0.5*vartheta)*::pow(sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 5.49790916690436597*::pow(cos(0.5*vartheta),3)*(19. + 42.*cos(vartheta) + 21.*cos(2.*vartheta) + 14.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.381211411713792221*::pow(cos(0.5*vartheta),2)*(265. + 442.*cos(vartheta) + 364.*cos(2.*vartheta) + 182.*cos(3.*vartheta) + 91.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.0738212724475868138*cos(0.5*vartheta)*(869. + 1660.*cos(vartheta) + 1300.*cos(2.*vartheta) + 910.*cos(3.*vartheta) + 455.*cos(4.*vartheta) + 182.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.00454338524578249815*(7626. + 14454.*cos(vartheta) + 12375.*cos(2.*vartheta) + 9295.*cos(3.*vartheta) + 6006.*cos(4.*vartheta) + 3003.*cos(5.*vartheta) + 1001.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.0190063441014545613*cos(0.5*vartheta)*(798. + 1386.*cos(vartheta) + 1386.*cos(2.*vartheta) + 1001.*cos(3.*vartheta) + 858.*cos(4.*vartheta) + 429.*cos(5.*vartheta) + 286.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -varphi + M_PI;
      } else {
        arg = -varphi;
      }
      return;
    case 0:
      amp = 0.010079636099777594*(210. + 385.*cos(2.*vartheta) + 286.*cos(4.*vartheta) + 143.*cos(6.*vartheta))*::pow(sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.0190063441014545613*::pow(cos(0.5*vartheta),3)*(798. - 1386.*cos(vartheta) + 1386.*cos(2.*vartheta) - 1001.*cos(3.*vartheta) + 858.*cos(4.*vartheta) - 429.*cos(5.*vartheta) + 286.*cos(6.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = varphi + M_PI;
      } else {
        arg = varphi;
      }
      return;
    case 2:
      amp = 0.00454338524578249815*::pow(cos(0.5*vartheta),4)*(7626. - 14454.*cos(vartheta) + 12375.*cos(2.*vartheta) - 9295.*cos(3.*vartheta) + 6006.*cos(4.*vartheta) - 3003.*cos(5.*vartheta) + 1001.*cos(6.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.0738212724475868138*::pow(cos(0.5*vartheta),5)*(-869. + 1660.*cos(vartheta) - 1300.*cos(2.*vartheta) + 910.*cos(3.*vartheta) - 455.*cos(4.*vartheta) + 182.*cos(5.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.381211411713792221*::pow(cos(0.5*vartheta),6)*(265. - 442.*cos(vartheta) + 364.*cos(2.*vartheta) - 182.*cos(3.*vartheta) + 91.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -5.49790916690436597*::pow(cos(0.5*vartheta),7)*(-19. + 42.*cos(vartheta) - 21.*cos(2.*vartheta) + 14.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 285.044189552854222*::pow(cos(0.5*vartheta),8)*(-1. + 2.*cos(vartheta))*sin(0.78539816339744831 - 0.5*vartheta)*sin(0.78539816339744831 + 0.5*vartheta)*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 6*varphi + M_PI;
      } else {
        arg = 6*varphi;
      }
      return;
    case 7:
      amp = -52.0417108346255555*::pow(cos(0.5*vartheta),9)*(-1. + 4.*cos(vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = 7*varphi + M_PI;
      } else {
        arg = 7*varphi;
      }
      return;
    case 8:
      amp = 104.083421669251111*::pow(cos(0.5*vartheta),10)*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = 8*varphi + M_PI;
      } else {
        arg = 8*varphi;
      }
      return;
    } // switch(M)
    
  case 9:
    switch(M) {
    case -9:
      amp = 219.355865285354367*::pow(cos(0.5*vartheta),7)*::pow(sin(0.5*vartheta),11);
      if(amp<0) {
        amp = -amp;
        arg = -9*varphi + M_PI;
      } else {
        arg = -9*varphi;
      }
      return;
    case -8:
      amp = 51.7026732787722888*::pow(cos(0.5*vartheta),6)*(2. + 9.*cos(vartheta))*::pow(sin(0.5*vartheta),10);
      if(amp<0) {
        amp = -amp;
        arg = -8*varphi + M_PI;
      } else {
        arg = -8*varphi;
      }
      return;
    case -7:
      amp = 2.21673382884871148*::pow(cos(0.5*vartheta),5)*(151. + 136.*cos(vartheta) + 153.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = -7*varphi + M_PI;
      } else {
        arg = -7*varphi;
      }
      return;
    case -6:
      amp = 3.83949561842266015*::pow(cos(0.5*vartheta),4)*(62. + 149.*cos(vartheta) + 68.*cos(2.*vartheta) + 51.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 0.619595941166137906*::pow(cos(0.5*vartheta),3)*(427. + 672.*cos(vartheta) + 588.*cos(2.*vartheta) + 272.*cos(3.*vartheta) + 153.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.259195578288233226*::pow(cos(0.5*vartheta),2)*(676. + 1330.*cos(vartheta) + 1000.*cos(2.*vartheta) + 725.*cos(3.*vartheta) + 340.*cos(4.*vartheta) + 153.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.022011090048569557*cos(0.5*vartheta)*(4906. + 9152.*cos(vartheta) + 7865.*cos(2.*vartheta) + 5720.*cos(3.*vartheta) + 3718.*cos(4.*vartheta) + 1768.*cos(5.*vartheta) + 663.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.00240160681609664791*(21252. + 40887.*cos(vartheta) + 36036.*cos(2.*vartheta) + 29029.*cos(3.*vartheta) + 20748.*cos(4.*vartheta) + 12831.*cos(5.*vartheta) + 6188.*cos(6.*vartheta) + 1989.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.00281613361477977156*cos(0.5*vartheta)*(6468. + 13671.*cos(vartheta) + 11466.*cos(2.*vartheta) + 10829.*cos(3.*vartheta) + 7644.*cos(4.*vartheta) + 6279.*cos(5.*vartheta) + 3094.*cos(6.*vartheta) + 1989.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -varphi + M_PI;
      } else {
        arg = -varphi;
      }
      return;
    case 0:
      amp = 0.0133580946271009442*cos(vartheta)*(166. + 403.*cos(2.*vartheta) + 234.*cos(4.*vartheta) + 221.*cos(6.*vartheta))*::pow(sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.00281613361477977156*::pow(cos(0.5*vartheta),3)*(-6468. + 13671.*cos(vartheta) - 11466.*cos(2.*vartheta) + 10829.*cos(3.*vartheta) - 7644.*cos(4.*vartheta) + 6279.*cos(5.*vartheta) - 3094.*cos(6.*vartheta) + 1989.*cos(7.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = varphi + M_PI;
      } else {
        arg = varphi;
      }
      return;
    case 2:
      amp = 0.00240160681609664791*::pow(cos(0.5*vartheta),4)*(-21252. + 40887.*cos(vartheta) - 36036.*cos(2.*vartheta) + 29029.*cos(3.*vartheta) - 20748.*cos(4.*vartheta) + 12831.*cos(5.*vartheta) - 6188.*cos(6.*vartheta) + 1989.*cos(7.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.022011090048569557*::pow(cos(0.5*vartheta),5)*(4906. - 9152.*cos(vartheta) + 7865.*cos(2.*vartheta) - 5720.*cos(3.*vartheta) + 3718.*cos(4.*vartheta) - 1768.*cos(5.*vartheta) + 663.*cos(6.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.259195578288233226*::pow(cos(0.5*vartheta),6)*(-676. + 1330.*cos(vartheta) - 1000.*cos(2.*vartheta) + 725.*cos(3.*vartheta) - 340.*cos(4.*vartheta) + 153.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -0.619595941166137906*::pow(cos(0.5*vartheta),7)*(427. - 672.*cos(vartheta) + 588.*cos(2.*vartheta) - 272.*cos(3.*vartheta) + 153.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 3.83949561842266015*::pow(cos(0.5*vartheta),8)*(-62. + 149.*cos(vartheta) - 68.*cos(2.*vartheta) + 51.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 6*varphi + M_PI;
      } else {
        arg = 6*varphi;
      }
      return;
    case 7:
      amp = -2.21673382884871148*::pow(cos(0.5*vartheta),9)*(151. - 136.*cos(vartheta) + 153.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = 7*varphi + M_PI;
      } else {
        arg = 7*varphi;
      }
      return;
    case 8:
      amp = 51.7026732787722888*::pow(cos(0.5*vartheta),10)*(-2. + 9.*cos(vartheta))*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = 8*varphi + M_PI;
      } else {
        arg = 8*varphi;
      }
      return;
    case 9:
      amp = -219.355865285354367*::pow(cos(0.5*vartheta),11)*::pow(sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = 9*varphi + M_PI;
      } else {
        arg = 9*varphi;
      }
      return;
    } // switch(M)
    
  case 10:
    switch(M) {
    case -10:
      amp = 458.815710175124215*::pow(cos(0.5*vartheta),8)*::pow(sin(0.5*vartheta),12);
      if(amp<0) {
        amp = -amp;
        arg = -10*varphi + M_PI;
      } else {
        arg = -10*varphi;
      }
      return;
    case -9:
      amp = 205.188623419283937*::pow(cos(0.5*vartheta),7)*(1. + 5.*cos(vartheta))*::pow(sin(0.5*vartheta),11);
      if(amp<0) {
        amp = -amp;
        arg = -9*varphi + M_PI;
      } else {
        arg = -9*varphi;
      }
      return;
    case -8:
      amp = 8.32149752273527606*::pow(cos(0.5*vartheta),6)*(93. + 76.*cos(vartheta) + 95.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),10);
      if(amp<0) {
        amp = -amp;
        arg = -8*varphi + M_PI;
      } else {
        arg = -8*varphi;
      }
      return;
    case -7:
      amp = 1.69861856887797376*::pow(cos(0.5*vartheta),5)*(314. + 819.*cos(vartheta) + 342.*cos(2.*vartheta) + 285.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = -7*varphi + M_PI;
      } else {
        arg = -7*varphi;
      }
      return;
    case -6:
      amp = 0.0514969395376425972*::pow(cos(0.5*vartheta),4)*(13159. + 19448.*cos(vartheta) + 18156.*cos(2.*vartheta) + 7752.*cos(3.*vartheta) + 4845.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 0.115150657439365437*::pow(cos(0.5*vartheta),3)*(3990. + 8162.*cos(vartheta) + 5848.*cos(2.*vartheta) + 4437.*cos(3.*vartheta) + 1938.*cos(4.*vartheta) + 969.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.00910345878935517795*::pow(cos(0.5*vartheta),2)*(35126. + 63960.*cos(vartheta) + 55875.*cos(2.*vartheta) + 39100.*cos(3.*vartheta) + 26010.*cos(4.*vartheta) + 11628.*cos(5.*vartheta) + 4845.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.00321855872110266232*cos(0.5*vartheta)*(52052. + 100639.*cos(vartheta) + 87010.*cos(2.*vartheta) + 69685.*cos(3.*vartheta) + 48076.*cos(4.*vartheta) + 29631.*cos(5.*vartheta) + 13566.*cos(6.*vartheta) + 4845.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.0000789014121372438118*(919611. + 1.777776e6*cos(vartheta) + 1.609608e6*cos(2.*vartheta) + 1.349712e6*cos(3.*vartheta) + 1.041404e6*cos(4.*vartheta) + 717808.*cos(5.*vartheta) + 429624.*cos(6.*vartheta) + 201552.*cos(7.*vartheta) + 62985.*cos(8.*vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.000273322509221275921*cos(0.5*vartheta)*(92169. + 168168.*cos(vartheta) + 168168.*cos(2.*vartheta) + 137592.*cos(3.*vartheta) + 124852.*cos(4.*vartheta) + 86632.*cos(5.*vartheta) + 68952.*cos(6.*vartheta) + 33592.*cos(7.*vartheta) + 20995.*cos(8.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -varphi + M_PI;
      } else {
        arg = -varphi;
      }
      return;
    case 0:
      amp = 0.00035832883259417753*(8085. + 15288.*cos(2.*vartheta) + 12740.*cos(4.*vartheta) + 8840.*cos(6.*vartheta) + 4199.*cos(8.*vartheta))*::pow(sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.000273322509221275921*::pow(cos(0.5*vartheta),3)*(92169. - 168168.*cos(vartheta) + 168168.*cos(2.*vartheta) - 137592.*cos(3.*vartheta) + 124852.*cos(4.*vartheta) - 86632.*cos(5.*vartheta) + 68952.*cos(6.*vartheta) - 33592.*cos(7.*vartheta) + 20995.*cos(8.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = varphi + M_PI;
      } else {
        arg = varphi;
      }
      return;
    case 2:
      amp = 0.0000789014121372438118*::pow(cos(0.5*vartheta),4)*(919611. - 1.777776e6*cos(vartheta) + 1.609608e6*cos(2.*vartheta) - 1.349712e6*cos(3.*vartheta) + 1.041404e6*cos(4.*vartheta) - 717808.*cos(5.*vartheta) + 429624.*cos(6.*vartheta) - 201552.*cos(7.*vartheta) + 62985.*cos(8.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.00321855872110266232*::pow(cos(0.5*vartheta),5)*(-52052. + 100639.*cos(vartheta) - 87010.*cos(2.*vartheta) + 69685.*cos(3.*vartheta) - 48076.*cos(4.*vartheta) + 29631.*cos(5.*vartheta) - 13566.*cos(6.*vartheta) + 4845.*cos(7.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.00910345878935517795*::pow(cos(0.5*vartheta),6)*(35126. - 63960.*cos(vartheta) + 55875.*cos(2.*vartheta) - 39100.*cos(3.*vartheta) + 26010.*cos(4.*vartheta) - 11628.*cos(5.*vartheta) + 4845.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -0.115150657439365437*::pow(cos(0.5*vartheta),7)*(-3990. + 8162.*cos(vartheta) - 5848.*cos(2.*vartheta) + 4437.*cos(3.*vartheta) - 1938.*cos(4.*vartheta) + 969.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 0.0514969395376425972*::pow(cos(0.5*vartheta),8)*(13159. - 19448.*cos(vartheta) + 18156.*cos(2.*vartheta) - 7752.*cos(3.*vartheta) + 4845.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 6*varphi + M_PI;
      } else {
        arg = 6*varphi;
      }
      return;
    case 7:
      amp = -1.69861856887797376*::pow(cos(0.5*vartheta),9)*(-314. + 819.*cos(vartheta) - 342.*cos(2.*vartheta) + 285.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = 7*varphi + M_PI;
      } else {
        arg = 7*varphi;
      }
      return;
    case 8:
      amp = 8.32149752273527606*::pow(cos(0.5*vartheta),10)*(93. - 76.*cos(vartheta) + 95.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = 8*varphi + M_PI;
      } else {
        arg = 8*varphi;
      }
      return;
    case 9:
      amp = -205.188623419283937*::pow(cos(0.5*vartheta),11)*(-1. + 5.*cos(vartheta))*::pow(sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = 9*varphi + M_PI;
      } else {
        arg = 9*varphi;
      }
      return;
    case 10:
      amp = 458.815710175124215*::pow(cos(0.5*vartheta),12)*::pow(sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = 10*varphi + M_PI;
      } else {
        arg = 10*varphi;
      }
      return;
    } // switch(M)
    
  case 11:
    switch(M) {
    case -11:
      amp = 954.1586847148967*::pow(cos(0.5*vartheta),9)*::pow(sin(0.5*vartheta),13);
      if(amp<0) {
        amp = -amp;
        arg = -11*varphi + M_PI;
      } else {
        arg = -11*varphi;
      }
      return;
    case -10:
      amp = 203.427315098143017*::pow(cos(0.5*vartheta),8)*(2. + 11.*cos(vartheta))*::pow(sin(0.5*vartheta),12);
      if(amp<0) {
        amp = -amp;
        arg = -10*varphi + M_PI;
      } else {
        arg = -10*varphi;
      }
      return;
    case -9:
      amp = 23.542137145078129*::pow(cos(0.5*vartheta),7)*(75. + 56.*cos(vartheta) + 77.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),11);
      if(amp<0) {
        amp = -amp;
        arg = -9*varphi + M_PI;
      } else {
        arg = -9*varphi;
      }
      return;
    case -8:
      amp = 3.03927683656728721*::pow(cos(0.5*vartheta),6)*(388. + 1095.*cos(vartheta) + 420.*cos(2.*vartheta) + 385.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),10);
      if(amp<0) {
        amp = -amp;
        arg = -8*varphi + M_PI;
      } else {
        arg = -8*varphi;
      }
      return;
    case -7:
      amp = 0.0871572407371104511*::pow(cos(0.5*vartheta),5)*(19529. + 27056.*cos(vartheta) + 26980.*cos(2.*vartheta) + 10640.*cos(3.*vartheta) + 7315.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = -7*varphi + M_PI;
      } else {
        arg = -7*varphi;
      }
      return;
    case -6:
      amp = 0.206711546478661343*::pow(cos(0.5*vartheta),4)*(5644. + 12078.*cos(vartheta) + 8208.*cos(2.*vartheta) + 6555.*cos(3.*vartheta) + 2660.*cos(4.*vartheta) + 1463.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 0.00511687324626887852*::pow(cos(0.5*vartheta),3)*(178010. + 314160.*cos(vartheta) + 281673.*cos(2.*vartheta) + 188632.*cos(3.*vartheta) + 129846.*cos(4.*vartheta) + 54264.*cos(5.*vartheta) + 24871.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.0135379740998672131*::pow(cos(0.5*vartheta),2)*(37960. + 74347.*cos(vartheta) + 62764.*cos(2.*vartheta) + 50609.*cos(3.*vartheta) + 33592.*cos(4.*vartheta) + 20995.*cos(5.*vartheta) + 9044.*cos(6.*vartheta) + 3553.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.000926881724677246133*cos(0.5*vartheta)*(274703. + 526240.*cos(vartheta) + 474760.*cos(2.*vartheta) + 388960.*cos(3.*vartheta) + 296140.*cos(4.*vartheta) + 196384.*cos(5.*vartheta) + 116280.*cos(6.*vartheta) + 51680.*cos(7.*vartheta) + 17765.*cos(8.*vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.0000412865934738617689*(2.414412e6 + 4.702698e6*cos(vartheta) + 4.32432e6*cos(2.*vartheta) + 3.75102e6*cos(3.*vartheta) + 3.033072e6*cos(4.*vartheta) + 2.266236e6*cos(5.*vartheta) + 1.519392e6*cos(6.*vartheta) + 886635.*cos(7.*vartheta) + 406980.*cos(8.*vartheta) + 124355.*cos(9.*vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.000235369796324778191*cos(0.5*vartheta)*(126126. + 261954.*cos(vartheta) + 232848.*cos(2.*vartheta) + 224028.*cos(3.*vartheta) + 179928.*cos(4.*vartheta) + 158508.*cos(5.*vartheta) + 108528.*cos(6.*vartheta) + 84303.*cos(7.*vartheta) + 40698.*cos(8.*vartheta) + 24871.*cos(9.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -varphi + M_PI;
      } else {
        arg = -varphi;
      }
      return;
    case 0:
      amp = 0.00135209654009058458*cos(vartheta)*(2719. + 4264.*cos(2.*vartheta) + 4556.*cos(4.*vartheta) + 2584.*cos(6.*vartheta) + 2261.*cos(8.*vartheta))*::pow(sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.000235369796324778191*::pow(cos(0.5*vartheta),3)*(-126126. + 261954.*cos(vartheta) - 232848.*cos(2.*vartheta) + 224028.*cos(3.*vartheta) - 179928.*cos(4.*vartheta) + 158508.*cos(5.*vartheta) - 108528.*cos(6.*vartheta) + 84303.*cos(7.*vartheta) - 40698.*cos(8.*vartheta) + 24871.*cos(9.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = varphi + M_PI;
      } else {
        arg = varphi;
      }
      return;
    case 2:
      amp = 0.0000412865934738617689*::pow(cos(0.5*vartheta),4)*(-2.414412e6 + 4.702698e6*cos(vartheta) - 4.32432e6*cos(2.*vartheta) + 3.75102e6*cos(3.*vartheta) - 3.033072e6*cos(4.*vartheta) + 2.266236e6*cos(5.*vartheta) - 1.519392e6*cos(6.*vartheta) + 886635.*cos(7.*vartheta) - 406980.*cos(8.*vartheta) + 124355.*cos(9.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.000926881724677246133*::pow(cos(0.5*vartheta),5)*(274703. - 526240.*cos(vartheta) + 474760.*cos(2.*vartheta) - 388960.*cos(3.*vartheta) + 296140.*cos(4.*vartheta) - 196384.*cos(5.*vartheta) + 116280.*cos(6.*vartheta) - 51680.*cos(7.*vartheta) + 17765.*cos(8.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.0135379740998672131*::pow(cos(0.5*vartheta),6)*(-37960. + 74347.*cos(vartheta) - 62764.*cos(2.*vartheta) + 50609.*cos(3.*vartheta) - 33592.*cos(4.*vartheta) + 20995.*cos(5.*vartheta) - 9044.*cos(6.*vartheta) + 3553.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -0.00511687324626887852*::pow(cos(0.5*vartheta),7)*(178010. - 314160.*cos(vartheta) + 281673.*cos(2.*vartheta) - 188632.*cos(3.*vartheta) + 129846.*cos(4.*vartheta) - 54264.*cos(5.*vartheta) + 24871.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 0.206711546478661343*::pow(cos(0.5*vartheta),8)*(-5644. + 12078.*cos(vartheta) - 8208.*cos(2.*vartheta) + 6555.*cos(3.*vartheta) - 2660.*cos(4.*vartheta) + 1463.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 6*varphi + M_PI;
      } else {
        arg = 6*varphi;
      }
      return;
    case 7:
      amp = -0.0871572407371104511*::pow(cos(0.5*vartheta),9)*(19529. - 27056.*cos(vartheta) + 26980.*cos(2.*vartheta) - 10640.*cos(3.*vartheta) + 7315.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = 7*varphi + M_PI;
      } else {
        arg = 7*varphi;
      }
      return;
    case 8:
      amp = 3.03927683656728721*::pow(cos(0.5*vartheta),10)*(-388. + 1095.*cos(vartheta) - 420.*cos(2.*vartheta) + 385.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = 8*varphi + M_PI;
      } else {
        arg = 8*varphi;
      }
      return;
    case 9:
      amp = -23.542137145078129*::pow(cos(0.5*vartheta),11)*(75. - 56.*cos(vartheta) + 77.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = 9*varphi + M_PI;
      } else {
        arg = 9*varphi;
      }
      return;
    case 10:
      amp = 203.427315098143017*::pow(cos(0.5*vartheta),12)*(-2. + 11.*cos(vartheta))*::pow(sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = 10*varphi + M_PI;
      } else {
        arg = 10*varphi;
      }
      return;
    case 11:
      amp = -954.1586847148967*::pow(cos(0.5*vartheta),13)*::pow(sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = 11*varphi + M_PI;
      } else {
        arg = 11*varphi;
      }
      return;
    } // switch(M)
    
  case 12:
    switch(M) {
    case -12:
      amp = 1975.29613940745059*::pow(cos(0.5*vartheta),10)*::pow(sin(0.5*vartheta),14);
      if(amp<0) {
        amp = -amp;
        arg = -12*varphi + M_PI;
      } else {
        arg = -12*varphi;
      }
      return;
    case -11:
      amp = 806.411272072960143*::pow(cos(0.5*vartheta),9)*(1. + 6.*cos(vartheta))*::pow(sin(0.5*vartheta),13);
      if(amp<0) {
        amp = -amp;
        arg = -11*varphi + M_PI;
      } else {
        arg = -11*varphi;
      }
      return;
    case -10:
      amp = 59.4494277098981063*::pow(cos(0.5*vartheta),8)*(67. + 46.*cos(vartheta) + 69.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),12);
      if(amp<0) {
        amp = -amp;
        arg = -10*varphi + M_PI;
      } else {
        arg = -10*varphi;
      }
      return;
    case -9:
      amp = 10.9765780420191242*::pow(cos(0.5*vartheta),7)*(235. + 715.*cos(vartheta) + 253.*cos(2.*vartheta) + 253.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),11);
      if(amp<0) {
        amp = -amp;
        arg = -9*varphi + M_PI;
      } else {
        arg = -9*varphi;
      }
      return;
    case -8:
      amp = 2.09587498954761674*::pow(cos(0.5*vartheta),6)*(2005. + 2604.*cos(vartheta) + 2772.*cos(2.*vartheta) + 1012.*cos(3.*vartheta) + 759.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),10);
      if(amp<0) {
        amp = -amp;
        arg = -8*varphi + M_PI;
      } else {
        arg = -8*varphi;
      }
      return;
    case -7:
      amp = 1.04793749477380837*::pow(cos(0.5*vartheta),5)*(2755. + 6190.*cos(vartheta) + 3980.*cos(2.*vartheta) + 3355.*cos(3.*vartheta) + 1265.*cos(4.*vartheta) + 759.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = -7*varphi + M_PI;
      } else {
        arg = -7*varphi;
      }
      return;
    case -6:
      amp = 0.0736112541772210869*::pow(cos(0.5*vartheta),4)*(34170. + 58140.*cos(vartheta) + 53865.*cos(2.*vartheta) + 34390.*cos(3.*vartheta) + 24662.*cos(4.*vartheta) + 9614.*cos(5.*vartheta) + 4807.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 0.00983671760506762245*::pow(cos(0.5*vartheta),3)*(152150. + 303975.*cos(vartheta) + 249375.*cos(2.*vartheta) + 204421.*cos(3.*vartheta) + 130074.*cos(4.*vartheta) + 83391.*cos(5.*vartheta) + 33649.*cos(6.*vartheta) + 14421.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.000210872893964438159*::pow(cos(0.5*vartheta),2)*(3.952975e6 + 7.4698e6*cos(vartheta) + 6.769672e6*cos(2.*vartheta) + 5.408312e6*cos(3.*vartheta) + 4.11502e6*cos(4.*vartheta) + 2.62276e6*cos(5.*vartheta) + 1.56332e6*cos(6.*vartheta) + 653752.*cos(7.*vartheta) + 245157.*cos(8.*vartheta))*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.000210872893964438159*cos(0.5*vartheta)*(1.748175e6 + 3.408834e6*cos(vartheta) + 3.092232e6*cos(2.*vartheta) + 2.654652e6*cos(3.*vartheta) + 2.089164e6*cos(4.*vartheta) + 1.53102e6*cos(5.*vartheta) + 984504.*cos(6.*vartheta) + 564927.*cos(7.*vartheta) + 245157.*cos(8.*vartheta) + 81719.*cos(9.*vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.0000215221246165373339*(6.205914e6 + 1.212354e7*cos(vartheta) + 1.131273e7*cos(2.*vartheta) + 1.003068e7*cos(3.*vartheta) + 8.42724e6*cos(4.*vartheta) + 6.62796e6*cos(5.*vartheta) + 4.830465e6*cos(6.*vartheta) + 3.16863e6*cos(7.*vartheta) + 1.81203e6*cos(8.*vartheta) + 817190.*cos(9.*vartheta) + 245157.*cos(10.*vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.000267082542659574423*cos(0.5*vartheta)*(144144. + 270270.*cos(vartheta) + 270270.*cos(2.*vartheta) + 235620.*cos(3.*vartheta) + 220320.*cos(4.*vartheta) + 174420.*cos(5.*vartheta) + 150195.*cos(6.*vartheta) + 101745.*cos(7.*vartheta) + 77520.*cos(8.*vartheta) + 37145.*cos(9.*vartheta) + 22287.*cos(10.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -varphi + M_PI;
      } else {
        arg = -varphi;
      }
      return;
    case 0:
      amp = 0.000208491243039524634*(18018. + 34650.*cos(2.*vartheta) + 30600.*cos(4.*vartheta) + 24225.*cos(6.*vartheta) + 16150.*cos(8.*vartheta) + 7429.*cos(10.*vartheta))*::pow(sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.000267082542659574423*::pow(cos(0.5*vartheta),3)*(144144. - 270270.*cos(vartheta) + 270270.*cos(2.*vartheta) - 235620.*cos(3.*vartheta) + 220320.*cos(4.*vartheta) - 174420.*cos(5.*vartheta) + 150195.*cos(6.*vartheta) - 101745.*cos(7.*vartheta) + 77520.*cos(8.*vartheta) - 37145.*cos(9.*vartheta) + 22287.*cos(10.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = varphi + M_PI;
      } else {
        arg = varphi;
      }
      return;
    case 2:
      amp = 0.0000215221246165373339*::pow(cos(0.5*vartheta),4)*(6.205914e6 - 1.212354e7*cos(vartheta) + 1.131273e7*cos(2.*vartheta) - 1.003068e7*cos(3.*vartheta) + 8.42724e6*cos(4.*vartheta) - 6.62796e6*cos(5.*vartheta) + 4.830465e6*cos(6.*vartheta) - 3.16863e6*cos(7.*vartheta) + 1.81203e6*cos(8.*vartheta) - 817190.*cos(9.*vartheta) + 245157.*cos(10.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.000210872893964438159*::pow(cos(0.5*vartheta),5)*(-1.748175e6 + 3.408834e6*cos(vartheta) - 3.092232e6*cos(2.*vartheta) + 2.654652e6*cos(3.*vartheta) - 2.089164e6*cos(4.*vartheta) + 1.53102e6*cos(5.*vartheta) - 984504.*cos(6.*vartheta) + 564927.*cos(7.*vartheta) - 245157.*cos(8.*vartheta) + 81719.*cos(9.*vartheta))*sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.000210872893964438159*::pow(cos(0.5*vartheta),6)*(3.952975e6 - 7.4698e6*cos(vartheta) + 6.769672e6*cos(2.*vartheta) - 5.408312e6*cos(3.*vartheta) + 4.11502e6*cos(4.*vartheta) - 2.62276e6*cos(5.*vartheta) + 1.56332e6*cos(6.*vartheta) - 653752.*cos(7.*vartheta) + 245157.*cos(8.*vartheta))*::pow(sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -0.00983671760506762245*::pow(cos(0.5*vartheta),7)*(-152150. + 303975.*cos(vartheta) - 249375.*cos(2.*vartheta) + 204421.*cos(3.*vartheta) - 130074.*cos(4.*vartheta) + 83391.*cos(5.*vartheta) - 33649.*cos(6.*vartheta) + 14421.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 0.0736112541772210869*::pow(cos(0.5*vartheta),8)*(34170. - 58140.*cos(vartheta) + 53865.*cos(2.*vartheta) - 34390.*cos(3.*vartheta) + 24662.*cos(4.*vartheta) - 9614.*cos(5.*vartheta) + 4807.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 6*varphi + M_PI;
      } else {
        arg = 6*varphi;
      }
      return;
    case 7:
      amp = -1.04793749477380837*::pow(cos(0.5*vartheta),9)*(-2755. + 6190.*cos(vartheta) - 3980.*cos(2.*vartheta) + 3355.*cos(3.*vartheta) - 1265.*cos(4.*vartheta) + 759.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = 7*varphi + M_PI;
      } else {
        arg = 7*varphi;
      }
      return;
    case 8:
      amp = 2.09587498954761674*::pow(cos(0.5*vartheta),10)*(2005. - 2604.*cos(vartheta) + 2772.*cos(2.*vartheta) - 1012.*cos(3.*vartheta) + 759.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = 8*varphi + M_PI;
      } else {
        arg = 8*varphi;
      }
      return;
    case 9:
      amp = -10.9765780420191242*::pow(cos(0.5*vartheta),11)*(-235. + 715.*cos(vartheta) - 253.*cos(2.*vartheta) + 253.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = 9*varphi + M_PI;
      } else {
        arg = 9*varphi;
      }
      return;
    case 10:
      amp = 59.4494277098981063*::pow(cos(0.5*vartheta),12)*(67. - 46.*cos(vartheta) + 69.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = 10*varphi + M_PI;
      } else {
        arg = 10*varphi;
      }
      return;
    case 11:
      amp = -806.411272072960143*::pow(cos(0.5*vartheta),13)*(-1. + 6.*cos(vartheta))*::pow(sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = 11*varphi + M_PI;
      } else {
        arg = 11*varphi;
      }
      return;
    case 12:
      amp = 1975.29613940745059*::pow(cos(0.5*vartheta),14)*::pow(sin(0.5*vartheta),10);
      if(amp<0) {
        amp = -amp;
        arg = 12*varphi + M_PI;
      } else {
        arg = 12*varphi;
      }
      return;
    } // switch(M)
    
  } // switch(L)

  return;
}


std::complex<double> WU::SWSH(const int L, const int M, const double vartheta, const double varphi) {
  double amp,arg;
  SWSH(L, M, vartheta, varphi, amp, arg);
  return std::complex<double>(amp*cos(arg), amp*sin(arg));
}


void WU::SWSH(const int L, const int M, const vector<double>& vartheta, const vector<double>& varphi, vector<double>& amp, vector<double>& arg) {
  if(L<2) { throw("l<2 unsupported."); }
  if(labs(M)>L) { throw("abs(m)>l unsupported for s=-2 spin-weighted spherical harmonics."); }
  if(vartheta.size() != varphi.size()) {
    std::cerr << "\n\nvartheta.size()=" << vartheta.size() << "  varphi.size()=" << varphi.size() << std::endl;
    throw("Size mismatch in input data");
  }
  if(L>12) { throw("l>12 unsupported."); }
  
  amp.resize(vartheta.size());
  arg.resize(vartheta.size());
  
  switch(L) {
  case 2:
    switch(M) {
    case -2:
      amp = 0.630783130505040012*::pow(sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 1.26156626101008002*cos(0.5*vartheta)*::pow(sin(0.5*vartheta),3);
      arg = -varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.38627420202318958*::pow(sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 1.26156626101008002*::pow(cos(0.5*vartheta),3)*sin(0.5*vartheta);
      arg = varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.630783130505040012*::pow(cos(0.5*vartheta),4);
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    } // switch(M)
    
  case 3:
    switch(M) {
    case -3:
      amp = 1.82818319785786294*cos(0.5*vartheta)*::pow(sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.746352665180230783*(2. + 3.*cos(vartheta))*::pow(sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 1.18008717985328702*cos(0.5*vartheta)*(1. + 3.*cos(vartheta))*::pow(sin(0.5*vartheta),3);
      arg = -varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 1.02198547643328236*cos(vartheta)*::pow(sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 1.18008717985328702*::pow(cos(0.5*vartheta),3)*(-1. + 3.*cos(vartheta))*sin(0.5*vartheta);
      arg = varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.746352665180230783*::pow(cos(0.5*vartheta),4)*(-2. + 3.*cos(vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -1.82818319785786294*::pow(cos(0.5*vartheta),5)*sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    } // switch(M)
    
  case 4:
    switch(M) {
    case -4:
      amp = 4.4781159910813847*::pow(cos(0.5*vartheta),2)*::pow(sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 3.16650618423356409*cos(0.5*vartheta)*(1. + 2.*cos(vartheta))*::pow(sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.423142187660817215*(9. + 14.*cos(vartheta) + 7.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.598413420602149017*cos(0.5*vartheta)*(6. + 7.*cos(vartheta) + 7.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = -varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.167261635889322292*(5. + 7.*cos(2.*vartheta))*::pow(sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.598413420602149017*::pow(cos(0.5*vartheta),3)*(6. - 7.*cos(vartheta) + 7.*cos(2.*vartheta))*sin(0.5*vartheta);
      arg = varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.423142187660817215*::pow(cos(0.5*vartheta),4)*(9. - 14.*cos(vartheta) + 7.*cos(2.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -3.16650618423356409*::pow(cos(0.5*vartheta),5)*(-1. + 2.*cos(vartheta))*sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 4.4781159910813847*::pow(cos(0.5*vartheta),6)*::pow(sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    } // switch(M)
    
  case 5:
    switch(M) {
    case -5:
      amp = 10.2490127544388841*::pow(cos(0.5*vartheta),3)*::pow(sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 3.24102240721428709*::pow(cos(0.5*vartheta),2)*(2. + 5.*cos(vartheta))*::pow(sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.572937230529692607*cos(0.5*vartheta)*(17. + 24.*cos(vartheta) + 15.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.233900644906847193*(32. + 57.*cos(vartheta) + 36.*cos(2.*vartheta) + 15.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.309421468960572107*cos(0.5*vartheta)*(14. + 33.*cos(vartheta) + 18.*cos(2.*vartheta) + 15.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = -varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.847385591630449638*cos(vartheta)*(1. + 3.*cos(2.*vartheta))*::pow(sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.309421468960572107*::pow(cos(0.5*vartheta),3)*(-14. + 33.*cos(vartheta) - 18.*cos(2.*vartheta) + 15.*cos(3.*vartheta))*sin(0.5*vartheta);
      arg = varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.233900644906847193*::pow(cos(0.5*vartheta),4)*(-32. + 57.*cos(vartheta) - 36.*cos(2.*vartheta) + 15.*cos(3.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.572937230529692607*::pow(cos(0.5*vartheta),5)*(17. - 24.*cos(vartheta) + 15.*cos(2.*vartheta))*sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 3.24102240721428709*::pow(cos(0.5*vartheta),6)*(-2. + 5.*cos(vartheta))*::pow(sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -10.2490127544388841*::pow(cos(0.5*vartheta),7)*::pow(sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    } // switch(M)
    
  case 6:
    switch(M) {
    case -6:
      amp = 22.6292074407870777*::pow(cos(0.5*vartheta),4)*::pow(sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 13.0649790074863016*::pow(cos(0.5*vartheta),3)*(1. + 3.*cos(vartheta))*::pow(sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.696365720891772932*::pow(cos(0.5*vartheta),2)*(35. + 44.*cos(vartheta) + 33.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.190707606802885278*cos(0.5*vartheta)*(98. + 185.*cos(vartheta) + 110.*cos(2.*vartheta) + 55.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.00794615028345355324*(1709. + 3096.*cos(vartheta) + 2340.*cos(2.*vartheta) + 1320.*cos(3.*vartheta) + 495.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.0502558670514116131*cos(0.5*vartheta)*(161. + 252.*cos(vartheta) + 252.*cos(2.*vartheta) + 132.*cos(3.*vartheta) + 99.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = -varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.0407119053667322336*(35. + 60.*cos(2.*vartheta) + 33.*cos(4.*vartheta))*::pow(sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.0502558670514116131*::pow(cos(0.5*vartheta),3)*(161. - 252.*cos(vartheta) + 252.*cos(2.*vartheta) - 132.*cos(3.*vartheta) + 99.*cos(4.*vartheta))*sin(0.5*vartheta);
      arg = varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.00794615028345355324*::pow(cos(0.5*vartheta),4)*(1709. - 3096.*cos(vartheta) + 2340.*cos(2.*vartheta) - 1320.*cos(3.*vartheta) + 495.*cos(4.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.190707606802885278*::pow(cos(0.5*vartheta),5)*(-98. + 185.*cos(vartheta) - 110.*cos(2.*vartheta) + 55.*cos(3.*vartheta))*sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.696365720891772932*::pow(cos(0.5*vartheta),6)*(35. - 44.*cos(vartheta) + 33.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -13.0649790074863016*::pow(cos(0.5*vartheta),7)*(-1. + 3.*cos(vartheta))*::pow(sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 22.6292074407870777*::pow(cos(0.5*vartheta),8)*::pow(sin(0.5*vartheta),4);
      arg = 6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    } // switch(M)
    
  case 7:
    switch(M) {
    case -7:
      amp = 48.8846752114075978*::pow(cos(0.5*vartheta),5)*::pow(sin(0.5*vartheta),9);
      arg = -7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -6:
      amp = 13.0649790074863016*::pow(cos(0.5*vartheta),4)*(2. + 7.*cos(vartheta))*::pow(sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 0.640563297152430255*::pow(cos(0.5*vartheta),3)*(93. + 104.*cos(vartheta) + 91.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.320281648576215128*::pow(cos(0.5*vartheta),2)*(140. + 285.*cos(vartheta) + 156.*cos(2.*vartheta) + 91.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.0120710688132246744*cos(0.5*vartheta)*(3115. + 5456.*cos(vartheta) + 4268.*cos(2.*vartheta) + 2288.*cos(3.*vartheta) + 1001.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.00426776730700030887*(5220. + 9810.*cos(vartheta) + 7920.*cos(2.*vartheta) + 5445.*cos(3.*vartheta) + 2860.*cos(4.*vartheta) + 1001.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.00522692612154132162*cos(0.5*vartheta)*(1890. + 4130.*cos(vartheta) + 3080.*cos(2.*vartheta) + 2805.*cos(3.*vartheta) + 1430.*cos(4.*vartheta) + 1001.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = -varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.0195573667327867542*cos(vartheta)*(109. + 132.*cos(2.*vartheta) + 143.*cos(4.*vartheta))*::pow(sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.00522692612154132162*::pow(cos(0.5*vartheta),3)*(-1890. + 4130.*cos(vartheta) - 3080.*cos(2.*vartheta) + 2805.*cos(3.*vartheta) - 1430.*cos(4.*vartheta) + 1001.*cos(5.*vartheta))*sin(0.5*vartheta);
      arg = varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.00426776730700030887*::pow(cos(0.5*vartheta),4)*(-5220. + 9810.*cos(vartheta) - 7920.*cos(2.*vartheta) + 5445.*cos(3.*vartheta) - 2860.*cos(4.*vartheta) + 1001.*cos(5.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.0120710688132246744*::pow(cos(0.5*vartheta),5)*(3115. - 5456.*cos(vartheta) + 4268.*cos(2.*vartheta) - 2288.*cos(3.*vartheta) + 1001.*cos(4.*vartheta))*sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.320281648576215128*::pow(cos(0.5*vartheta),6)*(-140. + 285.*cos(vartheta) - 156.*cos(2.*vartheta) + 91.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -0.640563297152430255*::pow(cos(0.5*vartheta),7)*(93. - 104.*cos(vartheta) + 91.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 13.0649790074863016*::pow(cos(0.5*vartheta),8)*(-2. + 7.*cos(vartheta))*::pow(sin(0.5*vartheta),4);
      arg = 6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 7:
      amp = -48.8846752114075978*::pow(cos(0.5*vartheta),9)*::pow(sin(0.5*vartheta),5);
      arg = 7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    } // switch(M)
    
  case 8:
    switch(M) {
    case -8:
      amp = 104.083421669251111*::pow(cos(0.5*vartheta),6)*::pow(sin(0.5*vartheta),10);
      arg = -8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -7:
      amp = 52.0417108346255555*::pow(cos(0.5*vartheta),5)*(1. + 4.*cos(vartheta))*::pow(sin(0.5*vartheta),9);
      arg = -7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -6:
      amp = 285.044189552854222*::pow(cos(0.5*vartheta),4)*(1. + 2.*cos(vartheta))*sin(0.78539816339744831 - 0.5*vartheta)*sin(0.78539816339744831 + 0.5*vartheta)*::pow(sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 5.49790916690436597*::pow(cos(0.5*vartheta),3)*(19. + 42.*cos(vartheta) + 21.*cos(2.*vartheta) + 14.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.381211411713792221*::pow(cos(0.5*vartheta),2)*(265. + 442.*cos(vartheta) + 364.*cos(2.*vartheta) + 182.*cos(3.*vartheta) + 91.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.0738212724475868138*cos(0.5*vartheta)*(869. + 1660.*cos(vartheta) + 1300.*cos(2.*vartheta) + 910.*cos(3.*vartheta) + 455.*cos(4.*vartheta) + 182.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.00454338524578249815*(7626. + 14454.*cos(vartheta) + 12375.*cos(2.*vartheta) + 9295.*cos(3.*vartheta) + 6006.*cos(4.*vartheta) + 3003.*cos(5.*vartheta) + 1001.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.0190063441014545613*cos(0.5*vartheta)*(798. + 1386.*cos(vartheta) + 1386.*cos(2.*vartheta) + 1001.*cos(3.*vartheta) + 858.*cos(4.*vartheta) + 429.*cos(5.*vartheta) + 286.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = -varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.010079636099777594*(210. + 385.*cos(2.*vartheta) + 286.*cos(4.*vartheta) + 143.*cos(6.*vartheta))*::pow(sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.0190063441014545613*::pow(cos(0.5*vartheta),3)*(798. - 1386.*cos(vartheta) + 1386.*cos(2.*vartheta) - 1001.*cos(3.*vartheta) + 858.*cos(4.*vartheta) - 429.*cos(5.*vartheta) + 286.*cos(6.*vartheta))*sin(0.5*vartheta);
      arg = varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.00454338524578249815*::pow(cos(0.5*vartheta),4)*(7626. - 14454.*cos(vartheta) + 12375.*cos(2.*vartheta) - 9295.*cos(3.*vartheta) + 6006.*cos(4.*vartheta) - 3003.*cos(5.*vartheta) + 1001.*cos(6.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.0738212724475868138*::pow(cos(0.5*vartheta),5)*(-869. + 1660.*cos(vartheta) - 1300.*cos(2.*vartheta) + 910.*cos(3.*vartheta) - 455.*cos(4.*vartheta) + 182.*cos(5.*vartheta))*sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.381211411713792221*::pow(cos(0.5*vartheta),6)*(265. - 442.*cos(vartheta) + 364.*cos(2.*vartheta) - 182.*cos(3.*vartheta) + 91.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -5.49790916690436597*::pow(cos(0.5*vartheta),7)*(-19. + 42.*cos(vartheta) - 21.*cos(2.*vartheta) + 14.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 285.044189552854222*::pow(cos(0.5*vartheta),8)*(-1. + 2.*cos(vartheta))*sin(0.78539816339744831 - 0.5*vartheta)*sin(0.78539816339744831 + 0.5*vartheta)*::pow(sin(0.5*vartheta),4);
      arg = 6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 7:
      amp = -52.0417108346255555*::pow(cos(0.5*vartheta),9)*(-1. + 4.*cos(vartheta))*::pow(sin(0.5*vartheta),5);
      arg = 7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 8:
      amp = 104.083421669251111*::pow(cos(0.5*vartheta),10)*::pow(sin(0.5*vartheta),6);
      arg = 8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    } // switch(M)
    
  case 9:
    switch(M) {
    case -9:
      amp = 219.355865285354367*::pow(cos(0.5*vartheta),7)*::pow(sin(0.5*vartheta),11);
      arg = -9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -8:
      amp = 51.7026732787722888*::pow(cos(0.5*vartheta),6)*(2. + 9.*cos(vartheta))*::pow(sin(0.5*vartheta),10);
      arg = -8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -7:
      amp = 2.21673382884871148*::pow(cos(0.5*vartheta),5)*(151. + 136.*cos(vartheta) + 153.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),9);
      arg = -7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -6:
      amp = 3.83949561842266015*::pow(cos(0.5*vartheta),4)*(62. + 149.*cos(vartheta) + 68.*cos(2.*vartheta) + 51.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 0.619595941166137906*::pow(cos(0.5*vartheta),3)*(427. + 672.*cos(vartheta) + 588.*cos(2.*vartheta) + 272.*cos(3.*vartheta) + 153.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.259195578288233226*::pow(cos(0.5*vartheta),2)*(676. + 1330.*cos(vartheta) + 1000.*cos(2.*vartheta) + 725.*cos(3.*vartheta) + 340.*cos(4.*vartheta) + 153.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.022011090048569557*cos(0.5*vartheta)*(4906. + 9152.*cos(vartheta) + 7865.*cos(2.*vartheta) + 5720.*cos(3.*vartheta) + 3718.*cos(4.*vartheta) + 1768.*cos(5.*vartheta) + 663.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.00240160681609664791*(21252. + 40887.*cos(vartheta) + 36036.*cos(2.*vartheta) + 29029.*cos(3.*vartheta) + 20748.*cos(4.*vartheta) + 12831.*cos(5.*vartheta) + 6188.*cos(6.*vartheta) + 1989.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.00281613361477977156*cos(0.5*vartheta)*(6468. + 13671.*cos(vartheta) + 11466.*cos(2.*vartheta) + 10829.*cos(3.*vartheta) + 7644.*cos(4.*vartheta) + 6279.*cos(5.*vartheta) + 3094.*cos(6.*vartheta) + 1989.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = -varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.0133580946271009442*cos(vartheta)*(166. + 403.*cos(2.*vartheta) + 234.*cos(4.*vartheta) + 221.*cos(6.*vartheta))*::pow(sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.00281613361477977156*::pow(cos(0.5*vartheta),3)*(-6468. + 13671.*cos(vartheta) - 11466.*cos(2.*vartheta) + 10829.*cos(3.*vartheta) - 7644.*cos(4.*vartheta) + 6279.*cos(5.*vartheta) - 3094.*cos(6.*vartheta) + 1989.*cos(7.*vartheta))*sin(0.5*vartheta);
      arg = varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.00240160681609664791*::pow(cos(0.5*vartheta),4)*(-21252. + 40887.*cos(vartheta) - 36036.*cos(2.*vartheta) + 29029.*cos(3.*vartheta) - 20748.*cos(4.*vartheta) + 12831.*cos(5.*vartheta) - 6188.*cos(6.*vartheta) + 1989.*cos(7.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.022011090048569557*::pow(cos(0.5*vartheta),5)*(4906. - 9152.*cos(vartheta) + 7865.*cos(2.*vartheta) - 5720.*cos(3.*vartheta) + 3718.*cos(4.*vartheta) - 1768.*cos(5.*vartheta) + 663.*cos(6.*vartheta))*sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.259195578288233226*::pow(cos(0.5*vartheta),6)*(-676. + 1330.*cos(vartheta) - 1000.*cos(2.*vartheta) + 725.*cos(3.*vartheta) - 340.*cos(4.*vartheta) + 153.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -0.619595941166137906*::pow(cos(0.5*vartheta),7)*(427. - 672.*cos(vartheta) + 588.*cos(2.*vartheta) - 272.*cos(3.*vartheta) + 153.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 3.83949561842266015*::pow(cos(0.5*vartheta),8)*(-62. + 149.*cos(vartheta) - 68.*cos(2.*vartheta) + 51.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),4);
      arg = 6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 7:
      amp = -2.21673382884871148*::pow(cos(0.5*vartheta),9)*(151. - 136.*cos(vartheta) + 153.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),5);
      arg = 7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 8:
      amp = 51.7026732787722888*::pow(cos(0.5*vartheta),10)*(-2. + 9.*cos(vartheta))*::pow(sin(0.5*vartheta),6);
      arg = 8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 9:
      amp = -219.355865285354367*::pow(cos(0.5*vartheta),11)*::pow(sin(0.5*vartheta),7);
      arg = 9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    } // switch(M)
    
  case 10:
    switch(M) {
    case -10:
      amp = 458.815710175124215*::pow(cos(0.5*vartheta),8)*::pow(sin(0.5*vartheta),12);
      arg = -10*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -9:
      amp = 205.188623419283937*::pow(cos(0.5*vartheta),7)*(1. + 5.*cos(vartheta))*::pow(sin(0.5*vartheta),11);
      arg = -9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -8:
      amp = 8.32149752273527606*::pow(cos(0.5*vartheta),6)*(93. + 76.*cos(vartheta) + 95.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),10);
      arg = -8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -7:
      amp = 1.69861856887797376*::pow(cos(0.5*vartheta),5)*(314. + 819.*cos(vartheta) + 342.*cos(2.*vartheta) + 285.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),9);
      arg = -7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -6:
      amp = 0.0514969395376425972*::pow(cos(0.5*vartheta),4)*(13159. + 19448.*cos(vartheta) + 18156.*cos(2.*vartheta) + 7752.*cos(3.*vartheta) + 4845.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 0.115150657439365437*::pow(cos(0.5*vartheta),3)*(3990. + 8162.*cos(vartheta) + 5848.*cos(2.*vartheta) + 4437.*cos(3.*vartheta) + 1938.*cos(4.*vartheta) + 969.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.00910345878935517795*::pow(cos(0.5*vartheta),2)*(35126. + 63960.*cos(vartheta) + 55875.*cos(2.*vartheta) + 39100.*cos(3.*vartheta) + 26010.*cos(4.*vartheta) + 11628.*cos(5.*vartheta) + 4845.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.00321855872110266232*cos(0.5*vartheta)*(52052. + 100639.*cos(vartheta) + 87010.*cos(2.*vartheta) + 69685.*cos(3.*vartheta) + 48076.*cos(4.*vartheta) + 29631.*cos(5.*vartheta) + 13566.*cos(6.*vartheta) + 4845.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.0000789014121372438118*(919611. + 1.777776e6*cos(vartheta) + 1.609608e6*cos(2.*vartheta) + 1.349712e6*cos(3.*vartheta) + 1.041404e6*cos(4.*vartheta) + 717808.*cos(5.*vartheta) + 429624.*cos(6.*vartheta) + 201552.*cos(7.*vartheta) + 62985.*cos(8.*vartheta))*::pow(sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.000273322509221275921*cos(0.5*vartheta)*(92169. + 168168.*cos(vartheta) + 168168.*cos(2.*vartheta) + 137592.*cos(3.*vartheta) + 124852.*cos(4.*vartheta) + 86632.*cos(5.*vartheta) + 68952.*cos(6.*vartheta) + 33592.*cos(7.*vartheta) + 20995.*cos(8.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = -varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.00035832883259417753*(8085. + 15288.*cos(2.*vartheta) + 12740.*cos(4.*vartheta) + 8840.*cos(6.*vartheta) + 4199.*cos(8.*vartheta))*::pow(sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.000273322509221275921*::pow(cos(0.5*vartheta),3)*(92169. - 168168.*cos(vartheta) + 168168.*cos(2.*vartheta) - 137592.*cos(3.*vartheta) + 124852.*cos(4.*vartheta) - 86632.*cos(5.*vartheta) + 68952.*cos(6.*vartheta) - 33592.*cos(7.*vartheta) + 20995.*cos(8.*vartheta))*sin(0.5*vartheta);
      arg = varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.0000789014121372438118*::pow(cos(0.5*vartheta),4)*(919611. - 1.777776e6*cos(vartheta) + 1.609608e6*cos(2.*vartheta) - 1.349712e6*cos(3.*vartheta) + 1.041404e6*cos(4.*vartheta) - 717808.*cos(5.*vartheta) + 429624.*cos(6.*vartheta) - 201552.*cos(7.*vartheta) + 62985.*cos(8.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.00321855872110266232*::pow(cos(0.5*vartheta),5)*(-52052. + 100639.*cos(vartheta) - 87010.*cos(2.*vartheta) + 69685.*cos(3.*vartheta) - 48076.*cos(4.*vartheta) + 29631.*cos(5.*vartheta) - 13566.*cos(6.*vartheta) + 4845.*cos(7.*vartheta))*sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.00910345878935517795*::pow(cos(0.5*vartheta),6)*(35126. - 63960.*cos(vartheta) + 55875.*cos(2.*vartheta) - 39100.*cos(3.*vartheta) + 26010.*cos(4.*vartheta) - 11628.*cos(5.*vartheta) + 4845.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -0.115150657439365437*::pow(cos(0.5*vartheta),7)*(-3990. + 8162.*cos(vartheta) - 5848.*cos(2.*vartheta) + 4437.*cos(3.*vartheta) - 1938.*cos(4.*vartheta) + 969.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 0.0514969395376425972*::pow(cos(0.5*vartheta),8)*(13159. - 19448.*cos(vartheta) + 18156.*cos(2.*vartheta) - 7752.*cos(3.*vartheta) + 4845.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),4);
      arg = 6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 7:
      amp = -1.69861856887797376*::pow(cos(0.5*vartheta),9)*(-314. + 819.*cos(vartheta) - 342.*cos(2.*vartheta) + 285.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),5);
      arg = 7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 8:
      amp = 8.32149752273527606*::pow(cos(0.5*vartheta),10)*(93. - 76.*cos(vartheta) + 95.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),6);
      arg = 8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 9:
      amp = -205.188623419283937*::pow(cos(0.5*vartheta),11)*(-1. + 5.*cos(vartheta))*::pow(sin(0.5*vartheta),7);
      arg = 9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 10:
      amp = 458.815710175124215*::pow(cos(0.5*vartheta),12)*::pow(sin(0.5*vartheta),8);
      arg = 10*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    } // switch(M)
    
  case 11:
    switch(M) {
    case -11:
      amp = 954.1586847148967*::pow(cos(0.5*vartheta),9)*::pow(sin(0.5*vartheta),13);
      arg = -11*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -10:
      amp = 203.427315098143017*::pow(cos(0.5*vartheta),8)*(2. + 11.*cos(vartheta))*::pow(sin(0.5*vartheta),12);
      arg = -10*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -9:
      amp = 23.542137145078129*::pow(cos(0.5*vartheta),7)*(75. + 56.*cos(vartheta) + 77.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),11);
      arg = -9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -8:
      amp = 3.03927683656728721*::pow(cos(0.5*vartheta),6)*(388. + 1095.*cos(vartheta) + 420.*cos(2.*vartheta) + 385.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),10);
      arg = -8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -7:
      amp = 0.0871572407371104511*::pow(cos(0.5*vartheta),5)*(19529. + 27056.*cos(vartheta) + 26980.*cos(2.*vartheta) + 10640.*cos(3.*vartheta) + 7315.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),9);
      arg = -7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -6:
      amp = 0.206711546478661343*::pow(cos(0.5*vartheta),4)*(5644. + 12078.*cos(vartheta) + 8208.*cos(2.*vartheta) + 6555.*cos(3.*vartheta) + 2660.*cos(4.*vartheta) + 1463.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 0.00511687324626887852*::pow(cos(0.5*vartheta),3)*(178010. + 314160.*cos(vartheta) + 281673.*cos(2.*vartheta) + 188632.*cos(3.*vartheta) + 129846.*cos(4.*vartheta) + 54264.*cos(5.*vartheta) + 24871.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.0135379740998672131*::pow(cos(0.5*vartheta),2)*(37960. + 74347.*cos(vartheta) + 62764.*cos(2.*vartheta) + 50609.*cos(3.*vartheta) + 33592.*cos(4.*vartheta) + 20995.*cos(5.*vartheta) + 9044.*cos(6.*vartheta) + 3553.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.000926881724677246133*cos(0.5*vartheta)*(274703. + 526240.*cos(vartheta) + 474760.*cos(2.*vartheta) + 388960.*cos(3.*vartheta) + 296140.*cos(4.*vartheta) + 196384.*cos(5.*vartheta) + 116280.*cos(6.*vartheta) + 51680.*cos(7.*vartheta) + 17765.*cos(8.*vartheta))*::pow(sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.0000412865934738617689*(2.414412e6 + 4.702698e6*cos(vartheta) + 4.32432e6*cos(2.*vartheta) + 3.75102e6*cos(3.*vartheta) + 3.033072e6*cos(4.*vartheta) + 2.266236e6*cos(5.*vartheta) + 1.519392e6*cos(6.*vartheta) + 886635.*cos(7.*vartheta) + 406980.*cos(8.*vartheta) + 124355.*cos(9.*vartheta))*::pow(sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.000235369796324778191*cos(0.5*vartheta)*(126126. + 261954.*cos(vartheta) + 232848.*cos(2.*vartheta) + 224028.*cos(3.*vartheta) + 179928.*cos(4.*vartheta) + 158508.*cos(5.*vartheta) + 108528.*cos(6.*vartheta) + 84303.*cos(7.*vartheta) + 40698.*cos(8.*vartheta) + 24871.*cos(9.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = -varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.00135209654009058458*cos(vartheta)*(2719. + 4264.*cos(2.*vartheta) + 4556.*cos(4.*vartheta) + 2584.*cos(6.*vartheta) + 2261.*cos(8.*vartheta))*::pow(sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.000235369796324778191*::pow(cos(0.5*vartheta),3)*(-126126. + 261954.*cos(vartheta) - 232848.*cos(2.*vartheta) + 224028.*cos(3.*vartheta) - 179928.*cos(4.*vartheta) + 158508.*cos(5.*vartheta) - 108528.*cos(6.*vartheta) + 84303.*cos(7.*vartheta) - 40698.*cos(8.*vartheta) + 24871.*cos(9.*vartheta))*sin(0.5*vartheta);
      arg = varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.0000412865934738617689*::pow(cos(0.5*vartheta),4)*(-2.414412e6 + 4.702698e6*cos(vartheta) - 4.32432e6*cos(2.*vartheta) + 3.75102e6*cos(3.*vartheta) - 3.033072e6*cos(4.*vartheta) + 2.266236e6*cos(5.*vartheta) - 1.519392e6*cos(6.*vartheta) + 886635.*cos(7.*vartheta) - 406980.*cos(8.*vartheta) + 124355.*cos(9.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.000926881724677246133*::pow(cos(0.5*vartheta),5)*(274703. - 526240.*cos(vartheta) + 474760.*cos(2.*vartheta) - 388960.*cos(3.*vartheta) + 296140.*cos(4.*vartheta) - 196384.*cos(5.*vartheta) + 116280.*cos(6.*vartheta) - 51680.*cos(7.*vartheta) + 17765.*cos(8.*vartheta))*sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.0135379740998672131*::pow(cos(0.5*vartheta),6)*(-37960. + 74347.*cos(vartheta) - 62764.*cos(2.*vartheta) + 50609.*cos(3.*vartheta) - 33592.*cos(4.*vartheta) + 20995.*cos(5.*vartheta) - 9044.*cos(6.*vartheta) + 3553.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -0.00511687324626887852*::pow(cos(0.5*vartheta),7)*(178010. - 314160.*cos(vartheta) + 281673.*cos(2.*vartheta) - 188632.*cos(3.*vartheta) + 129846.*cos(4.*vartheta) - 54264.*cos(5.*vartheta) + 24871.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 0.206711546478661343*::pow(cos(0.5*vartheta),8)*(-5644. + 12078.*cos(vartheta) - 8208.*cos(2.*vartheta) + 6555.*cos(3.*vartheta) - 2660.*cos(4.*vartheta) + 1463.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),4);
      arg = 6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 7:
      amp = -0.0871572407371104511*::pow(cos(0.5*vartheta),9)*(19529. - 27056.*cos(vartheta) + 26980.*cos(2.*vartheta) - 10640.*cos(3.*vartheta) + 7315.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),5);
      arg = 7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 8:
      amp = 3.03927683656728721*::pow(cos(0.5*vartheta),10)*(-388. + 1095.*cos(vartheta) - 420.*cos(2.*vartheta) + 385.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),6);
      arg = 8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 9:
      amp = -23.542137145078129*::pow(cos(0.5*vartheta),11)*(75. - 56.*cos(vartheta) + 77.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),7);
      arg = 9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 10:
      amp = 203.427315098143017*::pow(cos(0.5*vartheta),12)*(-2. + 11.*cos(vartheta))*::pow(sin(0.5*vartheta),8);
      arg = 10*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 11:
      amp = -954.1586847148967*::pow(cos(0.5*vartheta),13)*::pow(sin(0.5*vartheta),9);
      arg = 11*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    } // switch(M)
    
  case 12:
    switch(M) {
    case -12:
      amp = 1975.29613940745059*::pow(cos(0.5*vartheta),10)*::pow(sin(0.5*vartheta),14);
      arg = -12*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -11:
      amp = 806.411272072960143*::pow(cos(0.5*vartheta),9)*(1. + 6.*cos(vartheta))*::pow(sin(0.5*vartheta),13);
      arg = -11*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -10:
      amp = 59.4494277098981063*::pow(cos(0.5*vartheta),8)*(67. + 46.*cos(vartheta) + 69.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),12);
      arg = -10*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -9:
      amp = 10.9765780420191242*::pow(cos(0.5*vartheta),7)*(235. + 715.*cos(vartheta) + 253.*cos(2.*vartheta) + 253.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),11);
      arg = -9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -8:
      amp = 2.09587498954761674*::pow(cos(0.5*vartheta),6)*(2005. + 2604.*cos(vartheta) + 2772.*cos(2.*vartheta) + 1012.*cos(3.*vartheta) + 759.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),10);
      arg = -8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -7:
      amp = 1.04793749477380837*::pow(cos(0.5*vartheta),5)*(2755. + 6190.*cos(vartheta) + 3980.*cos(2.*vartheta) + 3355.*cos(3.*vartheta) + 1265.*cos(4.*vartheta) + 759.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),9);
      arg = -7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -6:
      amp = 0.0736112541772210869*::pow(cos(0.5*vartheta),4)*(34170. + 58140.*cos(vartheta) + 53865.*cos(2.*vartheta) + 34390.*cos(3.*vartheta) + 24662.*cos(4.*vartheta) + 9614.*cos(5.*vartheta) + 4807.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 0.00983671760506762245*::pow(cos(0.5*vartheta),3)*(152150. + 303975.*cos(vartheta) + 249375.*cos(2.*vartheta) + 204421.*cos(3.*vartheta) + 130074.*cos(4.*vartheta) + 83391.*cos(5.*vartheta) + 33649.*cos(6.*vartheta) + 14421.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.000210872893964438159*::pow(cos(0.5*vartheta),2)*(3.952975e6 + 7.4698e6*cos(vartheta) + 6.769672e6*cos(2.*vartheta) + 5.408312e6*cos(3.*vartheta) + 4.11502e6*cos(4.*vartheta) + 2.62276e6*cos(5.*vartheta) + 1.56332e6*cos(6.*vartheta) + 653752.*cos(7.*vartheta) + 245157.*cos(8.*vartheta))*::pow(sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.000210872893964438159*cos(0.5*vartheta)*(1.748175e6 + 3.408834e6*cos(vartheta) + 3.092232e6*cos(2.*vartheta) + 2.654652e6*cos(3.*vartheta) + 2.089164e6*cos(4.*vartheta) + 1.53102e6*cos(5.*vartheta) + 984504.*cos(6.*vartheta) + 564927.*cos(7.*vartheta) + 245157.*cos(8.*vartheta) + 81719.*cos(9.*vartheta))*::pow(sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.0000215221246165373339*(6.205914e6 + 1.212354e7*cos(vartheta) + 1.131273e7*cos(2.*vartheta) + 1.003068e7*cos(3.*vartheta) + 8.42724e6*cos(4.*vartheta) + 6.62796e6*cos(5.*vartheta) + 4.830465e6*cos(6.*vartheta) + 3.16863e6*cos(7.*vartheta) + 1.81203e6*cos(8.*vartheta) + 817190.*cos(9.*vartheta) + 245157.*cos(10.*vartheta))*::pow(sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.000267082542659574423*cos(0.5*vartheta)*(144144. + 270270.*cos(vartheta) + 270270.*cos(2.*vartheta) + 235620.*cos(3.*vartheta) + 220320.*cos(4.*vartheta) + 174420.*cos(5.*vartheta) + 150195.*cos(6.*vartheta) + 101745.*cos(7.*vartheta) + 77520.*cos(8.*vartheta) + 37145.*cos(9.*vartheta) + 22287.*cos(10.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = -varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.000208491243039524634*(18018. + 34650.*cos(2.*vartheta) + 30600.*cos(4.*vartheta) + 24225.*cos(6.*vartheta) + 16150.*cos(8.*vartheta) + 7429.*cos(10.*vartheta))*::pow(sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.000267082542659574423*::pow(cos(0.5*vartheta),3)*(144144. - 270270.*cos(vartheta) + 270270.*cos(2.*vartheta) - 235620.*cos(3.*vartheta) + 220320.*cos(4.*vartheta) - 174420.*cos(5.*vartheta) + 150195.*cos(6.*vartheta) - 101745.*cos(7.*vartheta) + 77520.*cos(8.*vartheta) - 37145.*cos(9.*vartheta) + 22287.*cos(10.*vartheta))*sin(0.5*vartheta);
      arg = varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.0000215221246165373339*::pow(cos(0.5*vartheta),4)*(6.205914e6 - 1.212354e7*cos(vartheta) + 1.131273e7*cos(2.*vartheta) - 1.003068e7*cos(3.*vartheta) + 8.42724e6*cos(4.*vartheta) - 6.62796e6*cos(5.*vartheta) + 4.830465e6*cos(6.*vartheta) - 3.16863e6*cos(7.*vartheta) + 1.81203e6*cos(8.*vartheta) - 817190.*cos(9.*vartheta) + 245157.*cos(10.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.000210872893964438159*::pow(cos(0.5*vartheta),5)*(-1.748175e6 + 3.408834e6*cos(vartheta) - 3.092232e6*cos(2.*vartheta) + 2.654652e6*cos(3.*vartheta) - 2.089164e6*cos(4.*vartheta) + 1.53102e6*cos(5.*vartheta) - 984504.*cos(6.*vartheta) + 564927.*cos(7.*vartheta) - 245157.*cos(8.*vartheta) + 81719.*cos(9.*vartheta))*sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.000210872893964438159*::pow(cos(0.5*vartheta),6)*(3.952975e6 - 7.4698e6*cos(vartheta) + 6.769672e6*cos(2.*vartheta) - 5.408312e6*cos(3.*vartheta) + 4.11502e6*cos(4.*vartheta) - 2.62276e6*cos(5.*vartheta) + 1.56332e6*cos(6.*vartheta) - 653752.*cos(7.*vartheta) + 245157.*cos(8.*vartheta))*::pow(sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -0.00983671760506762245*::pow(cos(0.5*vartheta),7)*(-152150. + 303975.*cos(vartheta) - 249375.*cos(2.*vartheta) + 204421.*cos(3.*vartheta) - 130074.*cos(4.*vartheta) + 83391.*cos(5.*vartheta) - 33649.*cos(6.*vartheta) + 14421.*cos(7.*vartheta))*::pow(sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 0.0736112541772210869*::pow(cos(0.5*vartheta),8)*(34170. - 58140.*cos(vartheta) + 53865.*cos(2.*vartheta) - 34390.*cos(3.*vartheta) + 24662.*cos(4.*vartheta) - 9614.*cos(5.*vartheta) + 4807.*cos(6.*vartheta))*::pow(sin(0.5*vartheta),4);
      arg = 6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 7:
      amp = -1.04793749477380837*::pow(cos(0.5*vartheta),9)*(-2755. + 6190.*cos(vartheta) - 3980.*cos(2.*vartheta) + 3355.*cos(3.*vartheta) - 1265.*cos(4.*vartheta) + 759.*cos(5.*vartheta))*::pow(sin(0.5*vartheta),5);
      arg = 7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 8:
      amp = 2.09587498954761674*::pow(cos(0.5*vartheta),10)*(2005. - 2604.*cos(vartheta) + 2772.*cos(2.*vartheta) - 1012.*cos(3.*vartheta) + 759.*cos(4.*vartheta))*::pow(sin(0.5*vartheta),6);
      arg = 8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 9:
      amp = -10.9765780420191242*::pow(cos(0.5*vartheta),11)*(-235. + 715.*cos(vartheta) - 253.*cos(2.*vartheta) + 253.*cos(3.*vartheta))*::pow(sin(0.5*vartheta),7);
      arg = 9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 10:
      amp = 59.4494277098981063*::pow(cos(0.5*vartheta),12)*(67. - 46.*cos(vartheta) + 69.*cos(2.*vartheta))*::pow(sin(0.5*vartheta),8);
      arg = 10*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 11:
      amp = -806.411272072960143*::pow(cos(0.5*vartheta),13)*(-1. + 6.*cos(vartheta))*::pow(sin(0.5*vartheta),9);
      arg = 11*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 12:
      amp = 1975.29613940745059*::pow(cos(0.5*vartheta),14)*::pow(sin(0.5*vartheta),10);
      arg = 12*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    } // switch(M)
    
  } // switch(L)

  return;
}

vector<complex<double> > WU::SWSH(const int L, const int M, const vector<double>& vartheta, const vector<double>& varphi) {
  if(L<2) { throw("l<2 unsupported."); }
  if(labs(M)>L) { throw("abs(m)>l unsupported for s=-2 spin-weighted spherical harmonics."); }
  if(vartheta.size() != varphi.size()) {
    std::cerr << "\n\nvartheta.size()=" << vartheta.size() << "  varphi.size()=" << varphi.size() << std::endl;
    throw("Size mismatch in input data");
  }
  if(L>12) { throw("l>12 unsupported."); }
  
  vector<complex<double> > swsh(vartheta.size());
  
  switch(L) {
  case 2:
    switch(M) {
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.630783130505040012*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -varphi[i];
        swsh[i] = 1.26156626101008002*cos(0.5*vartheta[i])*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.38627420202318958*::pow(sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = varphi[i];
        swsh[i] = 1.26156626101008002*::pow(cos(0.5*vartheta[i]),3)*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.630783130505040012*::pow(cos(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 3:
    switch(M) {
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 1.82818319785786294*cos(0.5*vartheta[i])*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.746352665180230783*(2. + 3.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -varphi[i];
        swsh[i] = 1.18008717985328702*cos(0.5*vartheta[i])*(1. + 3.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 1.02198547643328236*cos(vartheta[i])*::pow(sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = varphi[i];
        swsh[i] = 1.18008717985328702*::pow(cos(0.5*vartheta[i]),3)*(-1. + 3.*cos(vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.746352665180230783*::pow(cos(0.5*vartheta[i]),4)*(-2. + 3.*cos(vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -1.82818319785786294*::pow(cos(0.5*vartheta[i]),5)*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 4:
    switch(M) {
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 4.4781159910813847*::pow(cos(0.5*vartheta[i]),2)*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 3.16650618423356409*cos(0.5*vartheta[i])*(1. + 2.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.423142187660817215*(9. + 14.*cos(vartheta[i]) + 7.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -varphi[i];
        swsh[i] = 0.598413420602149017*cos(0.5*vartheta[i])*(6. + 7.*cos(vartheta[i]) + 7.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.167261635889322292*(5. + 7.*cos(2.*vartheta[i]))*::pow(sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = varphi[i];
        swsh[i] = 0.598413420602149017*::pow(cos(0.5*vartheta[i]),3)*(6. - 7.*cos(vartheta[i]) + 7.*cos(2.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.423142187660817215*::pow(cos(0.5*vartheta[i]),4)*(9. - 14.*cos(vartheta[i]) + 7.*cos(2.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -3.16650618423356409*::pow(cos(0.5*vartheta[i]),5)*(-1. + 2.*cos(vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 4.4781159910813847*::pow(cos(0.5*vartheta[i]),6)*::pow(sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 5:
    switch(M) {
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 10.2490127544388841*::pow(cos(0.5*vartheta[i]),3)*::pow(sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 3.24102240721428709*::pow(cos(0.5*vartheta[i]),2)*(2. + 5.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.572937230529692607*cos(0.5*vartheta[i])*(17. + 24.*cos(vartheta[i]) + 15.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.233900644906847193*(32. + 57.*cos(vartheta[i]) + 36.*cos(2.*vartheta[i]) + 15.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -varphi[i];
        swsh[i] = 0.309421468960572107*cos(0.5*vartheta[i])*(14. + 33.*cos(vartheta[i]) + 18.*cos(2.*vartheta[i]) + 15.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.847385591630449638*cos(vartheta[i])*(1. + 3.*cos(2.*vartheta[i]))*::pow(sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = varphi[i];
        swsh[i] = 0.309421468960572107*::pow(cos(0.5*vartheta[i]),3)*(-14. + 33.*cos(vartheta[i]) - 18.*cos(2.*vartheta[i]) + 15.*cos(3.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.233900644906847193*::pow(cos(0.5*vartheta[i]),4)*(-32. + 57.*cos(vartheta[i]) - 36.*cos(2.*vartheta[i]) + 15.*cos(3.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.572937230529692607*::pow(cos(0.5*vartheta[i]),5)*(17. - 24.*cos(vartheta[i]) + 15.*cos(2.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 3.24102240721428709*::pow(cos(0.5*vartheta[i]),6)*(-2. + 5.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -10.2490127544388841*::pow(cos(0.5*vartheta[i]),7)*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 6:
    switch(M) {
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 22.6292074407870777*::pow(cos(0.5*vartheta[i]),4)*::pow(sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 13.0649790074863016*::pow(cos(0.5*vartheta[i]),3)*(1. + 3.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.696365720891772932*::pow(cos(0.5*vartheta[i]),2)*(35. + 44.*cos(vartheta[i]) + 33.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.190707606802885278*cos(0.5*vartheta[i])*(98. + 185.*cos(vartheta[i]) + 110.*cos(2.*vartheta[i]) + 55.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.00794615028345355324*(1709. + 3096.*cos(vartheta[i]) + 2340.*cos(2.*vartheta[i]) + 1320.*cos(3.*vartheta[i]) + 495.*cos(4.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -varphi[i];
        swsh[i] = 0.0502558670514116131*cos(0.5*vartheta[i])*(161. + 252.*cos(vartheta[i]) + 252.*cos(2.*vartheta[i]) + 132.*cos(3.*vartheta[i]) + 99.*cos(4.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.0407119053667322336*(35. + 60.*cos(2.*vartheta[i]) + 33.*cos(4.*vartheta[i]))*::pow(sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = varphi[i];
        swsh[i] = 0.0502558670514116131*::pow(cos(0.5*vartheta[i]),3)*(161. - 252.*cos(vartheta[i]) + 252.*cos(2.*vartheta[i]) - 132.*cos(3.*vartheta[i]) + 99.*cos(4.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.00794615028345355324*::pow(cos(0.5*vartheta[i]),4)*(1709. - 3096.*cos(vartheta[i]) + 2340.*cos(2.*vartheta[i]) - 1320.*cos(3.*vartheta[i]) + 495.*cos(4.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.190707606802885278*::pow(cos(0.5*vartheta[i]),5)*(-98. + 185.*cos(vartheta[i]) - 110.*cos(2.*vartheta[i]) + 55.*cos(3.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.696365720891772932*::pow(cos(0.5*vartheta[i]),6)*(35. - 44.*cos(vartheta[i]) + 33.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -13.0649790074863016*::pow(cos(0.5*vartheta[i]),7)*(-1. + 3.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 22.6292074407870777*::pow(cos(0.5*vartheta[i]),8)*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 7:
    switch(M) {
    case -7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -7*varphi[i];
        swsh[i] = 48.8846752114075978*::pow(cos(0.5*vartheta[i]),5)*::pow(sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 13.0649790074863016*::pow(cos(0.5*vartheta[i]),4)*(2. + 7.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 0.640563297152430255*::pow(cos(0.5*vartheta[i]),3)*(93. + 104.*cos(vartheta[i]) + 91.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.320281648576215128*::pow(cos(0.5*vartheta[i]),2)*(140. + 285.*cos(vartheta[i]) + 156.*cos(2.*vartheta[i]) + 91.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.0120710688132246744*cos(0.5*vartheta[i])*(3115. + 5456.*cos(vartheta[i]) + 4268.*cos(2.*vartheta[i]) + 2288.*cos(3.*vartheta[i]) + 1001.*cos(4.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.00426776730700030887*(5220. + 9810.*cos(vartheta[i]) + 7920.*cos(2.*vartheta[i]) + 5445.*cos(3.*vartheta[i]) + 2860.*cos(4.*vartheta[i]) + 1001.*cos(5.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -varphi[i];
        swsh[i] = 0.00522692612154132162*cos(0.5*vartheta[i])*(1890. + 4130.*cos(vartheta[i]) + 3080.*cos(2.*vartheta[i]) + 2805.*cos(3.*vartheta[i]) + 1430.*cos(4.*vartheta[i]) + 1001.*cos(5.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.0195573667327867542*cos(vartheta[i])*(109. + 132.*cos(2.*vartheta[i]) + 143.*cos(4.*vartheta[i]))*::pow(sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = varphi[i];
        swsh[i] = 0.00522692612154132162*::pow(cos(0.5*vartheta[i]),3)*(-1890. + 4130.*cos(vartheta[i]) - 3080.*cos(2.*vartheta[i]) + 2805.*cos(3.*vartheta[i]) - 1430.*cos(4.*vartheta[i]) + 1001.*cos(5.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.00426776730700030887*::pow(cos(0.5*vartheta[i]),4)*(-5220. + 9810.*cos(vartheta[i]) - 7920.*cos(2.*vartheta[i]) + 5445.*cos(3.*vartheta[i]) - 2860.*cos(4.*vartheta[i]) + 1001.*cos(5.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.0120710688132246744*::pow(cos(0.5*vartheta[i]),5)*(3115. - 5456.*cos(vartheta[i]) + 4268.*cos(2.*vartheta[i]) - 2288.*cos(3.*vartheta[i]) + 1001.*cos(4.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.320281648576215128*::pow(cos(0.5*vartheta[i]),6)*(-140. + 285.*cos(vartheta[i]) - 156.*cos(2.*vartheta[i]) + 91.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -0.640563297152430255*::pow(cos(0.5*vartheta[i]),7)*(93. - 104.*cos(vartheta[i]) + 91.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 13.0649790074863016*::pow(cos(0.5*vartheta[i]),8)*(-2. + 7.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 7*varphi[i];
        swsh[i] = -48.8846752114075978*::pow(cos(0.5*vartheta[i]),9)*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 8:
    switch(M) {
    case -8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -8*varphi[i];
        swsh[i] = 104.083421669251111*::pow(cos(0.5*vartheta[i]),6)*::pow(sin(0.5*vartheta[i]),10)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -7*varphi[i];
        swsh[i] = 52.0417108346255555*::pow(cos(0.5*vartheta[i]),5)*(1. + 4.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 285.044189552854222*::pow(cos(0.5*vartheta[i]),4)*(1. + 2.*cos(vartheta[i]))*sin(0.78539816339744831 - 0.5*vartheta[i])*sin(0.78539816339744831 + 0.5*vartheta[i])*::pow(sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 5.49790916690436597*::pow(cos(0.5*vartheta[i]),3)*(19. + 42.*cos(vartheta[i]) + 21.*cos(2.*vartheta[i]) + 14.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.381211411713792221*::pow(cos(0.5*vartheta[i]),2)*(265. + 442.*cos(vartheta[i]) + 364.*cos(2.*vartheta[i]) + 182.*cos(3.*vartheta[i]) + 91.*cos(4.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.0738212724475868138*cos(0.5*vartheta[i])*(869. + 1660.*cos(vartheta[i]) + 1300.*cos(2.*vartheta[i]) + 910.*cos(3.*vartheta[i]) + 455.*cos(4.*vartheta[i]) + 182.*cos(5.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.00454338524578249815*(7626. + 14454.*cos(vartheta[i]) + 12375.*cos(2.*vartheta[i]) + 9295.*cos(3.*vartheta[i]) + 6006.*cos(4.*vartheta[i]) + 3003.*cos(5.*vartheta[i]) + 1001.*cos(6.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -varphi[i];
        swsh[i] = 0.0190063441014545613*cos(0.5*vartheta[i])*(798. + 1386.*cos(vartheta[i]) + 1386.*cos(2.*vartheta[i]) + 1001.*cos(3.*vartheta[i]) + 858.*cos(4.*vartheta[i]) + 429.*cos(5.*vartheta[i]) + 286.*cos(6.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.010079636099777594*(210. + 385.*cos(2.*vartheta[i]) + 286.*cos(4.*vartheta[i]) + 143.*cos(6.*vartheta[i]))*::pow(sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = varphi[i];
        swsh[i] = 0.0190063441014545613*::pow(cos(0.5*vartheta[i]),3)*(798. - 1386.*cos(vartheta[i]) + 1386.*cos(2.*vartheta[i]) - 1001.*cos(3.*vartheta[i]) + 858.*cos(4.*vartheta[i]) - 429.*cos(5.*vartheta[i]) + 286.*cos(6.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.00454338524578249815*::pow(cos(0.5*vartheta[i]),4)*(7626. - 14454.*cos(vartheta[i]) + 12375.*cos(2.*vartheta[i]) - 9295.*cos(3.*vartheta[i]) + 6006.*cos(4.*vartheta[i]) - 3003.*cos(5.*vartheta[i]) + 1001.*cos(6.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.0738212724475868138*::pow(cos(0.5*vartheta[i]),5)*(-869. + 1660.*cos(vartheta[i]) - 1300.*cos(2.*vartheta[i]) + 910.*cos(3.*vartheta[i]) - 455.*cos(4.*vartheta[i]) + 182.*cos(5.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.381211411713792221*::pow(cos(0.5*vartheta[i]),6)*(265. - 442.*cos(vartheta[i]) + 364.*cos(2.*vartheta[i]) - 182.*cos(3.*vartheta[i]) + 91.*cos(4.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -5.49790916690436597*::pow(cos(0.5*vartheta[i]),7)*(-19. + 42.*cos(vartheta[i]) - 21.*cos(2.*vartheta[i]) + 14.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 285.044189552854222*::pow(cos(0.5*vartheta[i]),8)*(-1. + 2.*cos(vartheta[i]))*sin(0.78539816339744831 - 0.5*vartheta[i])*sin(0.78539816339744831 + 0.5*vartheta[i])*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 7*varphi[i];
        swsh[i] = -52.0417108346255555*::pow(cos(0.5*vartheta[i]),9)*(-1. + 4.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 8*varphi[i];
        swsh[i] = 104.083421669251111*::pow(cos(0.5*vartheta[i]),10)*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 9:
    switch(M) {
    case -9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -9*varphi[i];
        swsh[i] = 219.355865285354367*::pow(cos(0.5*vartheta[i]),7)*::pow(sin(0.5*vartheta[i]),11)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -8*varphi[i];
        swsh[i] = 51.7026732787722888*::pow(cos(0.5*vartheta[i]),6)*(2. + 9.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),10)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -7*varphi[i];
        swsh[i] = 2.21673382884871148*::pow(cos(0.5*vartheta[i]),5)*(151. + 136.*cos(vartheta[i]) + 153.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 3.83949561842266015*::pow(cos(0.5*vartheta[i]),4)*(62. + 149.*cos(vartheta[i]) + 68.*cos(2.*vartheta[i]) + 51.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 0.619595941166137906*::pow(cos(0.5*vartheta[i]),3)*(427. + 672.*cos(vartheta[i]) + 588.*cos(2.*vartheta[i]) + 272.*cos(3.*vartheta[i]) + 153.*cos(4.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.259195578288233226*::pow(cos(0.5*vartheta[i]),2)*(676. + 1330.*cos(vartheta[i]) + 1000.*cos(2.*vartheta[i]) + 725.*cos(3.*vartheta[i]) + 340.*cos(4.*vartheta[i]) + 153.*cos(5.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.022011090048569557*cos(0.5*vartheta[i])*(4906. + 9152.*cos(vartheta[i]) + 7865.*cos(2.*vartheta[i]) + 5720.*cos(3.*vartheta[i]) + 3718.*cos(4.*vartheta[i]) + 1768.*cos(5.*vartheta[i]) + 663.*cos(6.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.00240160681609664791*(21252. + 40887.*cos(vartheta[i]) + 36036.*cos(2.*vartheta[i]) + 29029.*cos(3.*vartheta[i]) + 20748.*cos(4.*vartheta[i]) + 12831.*cos(5.*vartheta[i]) + 6188.*cos(6.*vartheta[i]) + 1989.*cos(7.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -varphi[i];
        swsh[i] = 0.00281613361477977156*cos(0.5*vartheta[i])*(6468. + 13671.*cos(vartheta[i]) + 11466.*cos(2.*vartheta[i]) + 10829.*cos(3.*vartheta[i]) + 7644.*cos(4.*vartheta[i]) + 6279.*cos(5.*vartheta[i]) + 3094.*cos(6.*vartheta[i]) + 1989.*cos(7.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.0133580946271009442*cos(vartheta[i])*(166. + 403.*cos(2.*vartheta[i]) + 234.*cos(4.*vartheta[i]) + 221.*cos(6.*vartheta[i]))*::pow(sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = varphi[i];
        swsh[i] = 0.00281613361477977156*::pow(cos(0.5*vartheta[i]),3)*(-6468. + 13671.*cos(vartheta[i]) - 11466.*cos(2.*vartheta[i]) + 10829.*cos(3.*vartheta[i]) - 7644.*cos(4.*vartheta[i]) + 6279.*cos(5.*vartheta[i]) - 3094.*cos(6.*vartheta[i]) + 1989.*cos(7.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.00240160681609664791*::pow(cos(0.5*vartheta[i]),4)*(-21252. + 40887.*cos(vartheta[i]) - 36036.*cos(2.*vartheta[i]) + 29029.*cos(3.*vartheta[i]) - 20748.*cos(4.*vartheta[i]) + 12831.*cos(5.*vartheta[i]) - 6188.*cos(6.*vartheta[i]) + 1989.*cos(7.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.022011090048569557*::pow(cos(0.5*vartheta[i]),5)*(4906. - 9152.*cos(vartheta[i]) + 7865.*cos(2.*vartheta[i]) - 5720.*cos(3.*vartheta[i]) + 3718.*cos(4.*vartheta[i]) - 1768.*cos(5.*vartheta[i]) + 663.*cos(6.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.259195578288233226*::pow(cos(0.5*vartheta[i]),6)*(-676. + 1330.*cos(vartheta[i]) - 1000.*cos(2.*vartheta[i]) + 725.*cos(3.*vartheta[i]) - 340.*cos(4.*vartheta[i]) + 153.*cos(5.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -0.619595941166137906*::pow(cos(0.5*vartheta[i]),7)*(427. - 672.*cos(vartheta[i]) + 588.*cos(2.*vartheta[i]) - 272.*cos(3.*vartheta[i]) + 153.*cos(4.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 3.83949561842266015*::pow(cos(0.5*vartheta[i]),8)*(-62. + 149.*cos(vartheta[i]) - 68.*cos(2.*vartheta[i]) + 51.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 7*varphi[i];
        swsh[i] = -2.21673382884871148*::pow(cos(0.5*vartheta[i]),9)*(151. - 136.*cos(vartheta[i]) + 153.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 8*varphi[i];
        swsh[i] = 51.7026732787722888*::pow(cos(0.5*vartheta[i]),10)*(-2. + 9.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 9*varphi[i];
        swsh[i] = -219.355865285354367*::pow(cos(0.5*vartheta[i]),11)*::pow(sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 10:
    switch(M) {
    case -10:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -10*varphi[i];
        swsh[i] = 458.815710175124215*::pow(cos(0.5*vartheta[i]),8)*::pow(sin(0.5*vartheta[i]),12)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -9*varphi[i];
        swsh[i] = 205.188623419283937*::pow(cos(0.5*vartheta[i]),7)*(1. + 5.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),11)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -8*varphi[i];
        swsh[i] = 8.32149752273527606*::pow(cos(0.5*vartheta[i]),6)*(93. + 76.*cos(vartheta[i]) + 95.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),10)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -7*varphi[i];
        swsh[i] = 1.69861856887797376*::pow(cos(0.5*vartheta[i]),5)*(314. + 819.*cos(vartheta[i]) + 342.*cos(2.*vartheta[i]) + 285.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 0.0514969395376425972*::pow(cos(0.5*vartheta[i]),4)*(13159. + 19448.*cos(vartheta[i]) + 18156.*cos(2.*vartheta[i]) + 7752.*cos(3.*vartheta[i]) + 4845.*cos(4.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 0.115150657439365437*::pow(cos(0.5*vartheta[i]),3)*(3990. + 8162.*cos(vartheta[i]) + 5848.*cos(2.*vartheta[i]) + 4437.*cos(3.*vartheta[i]) + 1938.*cos(4.*vartheta[i]) + 969.*cos(5.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.00910345878935517795*::pow(cos(0.5*vartheta[i]),2)*(35126. + 63960.*cos(vartheta[i]) + 55875.*cos(2.*vartheta[i]) + 39100.*cos(3.*vartheta[i]) + 26010.*cos(4.*vartheta[i]) + 11628.*cos(5.*vartheta[i]) + 4845.*cos(6.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.00321855872110266232*cos(0.5*vartheta[i])*(52052. + 100639.*cos(vartheta[i]) + 87010.*cos(2.*vartheta[i]) + 69685.*cos(3.*vartheta[i]) + 48076.*cos(4.*vartheta[i]) + 29631.*cos(5.*vartheta[i]) + 13566.*cos(6.*vartheta[i]) + 4845.*cos(7.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.0000789014121372438118*(919611. + 1.777776e6*cos(vartheta[i]) + 1.609608e6*cos(2.*vartheta[i]) + 1.349712e6*cos(3.*vartheta[i]) + 1.041404e6*cos(4.*vartheta[i]) + 717808.*cos(5.*vartheta[i]) + 429624.*cos(6.*vartheta[i]) + 201552.*cos(7.*vartheta[i]) + 62985.*cos(8.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -varphi[i];
        swsh[i] = 0.000273322509221275921*cos(0.5*vartheta[i])*(92169. + 168168.*cos(vartheta[i]) + 168168.*cos(2.*vartheta[i]) + 137592.*cos(3.*vartheta[i]) + 124852.*cos(4.*vartheta[i]) + 86632.*cos(5.*vartheta[i]) + 68952.*cos(6.*vartheta[i]) + 33592.*cos(7.*vartheta[i]) + 20995.*cos(8.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.00035832883259417753*(8085. + 15288.*cos(2.*vartheta[i]) + 12740.*cos(4.*vartheta[i]) + 8840.*cos(6.*vartheta[i]) + 4199.*cos(8.*vartheta[i]))*::pow(sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = varphi[i];
        swsh[i] = 0.000273322509221275921*::pow(cos(0.5*vartheta[i]),3)*(92169. - 168168.*cos(vartheta[i]) + 168168.*cos(2.*vartheta[i]) - 137592.*cos(3.*vartheta[i]) + 124852.*cos(4.*vartheta[i]) - 86632.*cos(5.*vartheta[i]) + 68952.*cos(6.*vartheta[i]) - 33592.*cos(7.*vartheta[i]) + 20995.*cos(8.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.0000789014121372438118*::pow(cos(0.5*vartheta[i]),4)*(919611. - 1.777776e6*cos(vartheta[i]) + 1.609608e6*cos(2.*vartheta[i]) - 1.349712e6*cos(3.*vartheta[i]) + 1.041404e6*cos(4.*vartheta[i]) - 717808.*cos(5.*vartheta[i]) + 429624.*cos(6.*vartheta[i]) - 201552.*cos(7.*vartheta[i]) + 62985.*cos(8.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.00321855872110266232*::pow(cos(0.5*vartheta[i]),5)*(-52052. + 100639.*cos(vartheta[i]) - 87010.*cos(2.*vartheta[i]) + 69685.*cos(3.*vartheta[i]) - 48076.*cos(4.*vartheta[i]) + 29631.*cos(5.*vartheta[i]) - 13566.*cos(6.*vartheta[i]) + 4845.*cos(7.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.00910345878935517795*::pow(cos(0.5*vartheta[i]),6)*(35126. - 63960.*cos(vartheta[i]) + 55875.*cos(2.*vartheta[i]) - 39100.*cos(3.*vartheta[i]) + 26010.*cos(4.*vartheta[i]) - 11628.*cos(5.*vartheta[i]) + 4845.*cos(6.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -0.115150657439365437*::pow(cos(0.5*vartheta[i]),7)*(-3990. + 8162.*cos(vartheta[i]) - 5848.*cos(2.*vartheta[i]) + 4437.*cos(3.*vartheta[i]) - 1938.*cos(4.*vartheta[i]) + 969.*cos(5.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 0.0514969395376425972*::pow(cos(0.5*vartheta[i]),8)*(13159. - 19448.*cos(vartheta[i]) + 18156.*cos(2.*vartheta[i]) - 7752.*cos(3.*vartheta[i]) + 4845.*cos(4.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 7*varphi[i];
        swsh[i] = -1.69861856887797376*::pow(cos(0.5*vartheta[i]),9)*(-314. + 819.*cos(vartheta[i]) - 342.*cos(2.*vartheta[i]) + 285.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 8*varphi[i];
        swsh[i] = 8.32149752273527606*::pow(cos(0.5*vartheta[i]),10)*(93. - 76.*cos(vartheta[i]) + 95.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 9*varphi[i];
        swsh[i] = -205.188623419283937*::pow(cos(0.5*vartheta[i]),11)*(-1. + 5.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 10:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 10*varphi[i];
        swsh[i] = 458.815710175124215*::pow(cos(0.5*vartheta[i]),12)*::pow(sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 11:
    switch(M) {
    case -11:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -11*varphi[i];
        swsh[i] = 954.1586847148967*::pow(cos(0.5*vartheta[i]),9)*::pow(sin(0.5*vartheta[i]),13)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -10:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -10*varphi[i];
        swsh[i] = 203.427315098143017*::pow(cos(0.5*vartheta[i]),8)*(2. + 11.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),12)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -9*varphi[i];
        swsh[i] = 23.542137145078129*::pow(cos(0.5*vartheta[i]),7)*(75. + 56.*cos(vartheta[i]) + 77.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),11)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -8*varphi[i];
        swsh[i] = 3.03927683656728721*::pow(cos(0.5*vartheta[i]),6)*(388. + 1095.*cos(vartheta[i]) + 420.*cos(2.*vartheta[i]) + 385.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),10)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -7*varphi[i];
        swsh[i] = 0.0871572407371104511*::pow(cos(0.5*vartheta[i]),5)*(19529. + 27056.*cos(vartheta[i]) + 26980.*cos(2.*vartheta[i]) + 10640.*cos(3.*vartheta[i]) + 7315.*cos(4.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 0.206711546478661343*::pow(cos(0.5*vartheta[i]),4)*(5644. + 12078.*cos(vartheta[i]) + 8208.*cos(2.*vartheta[i]) + 6555.*cos(3.*vartheta[i]) + 2660.*cos(4.*vartheta[i]) + 1463.*cos(5.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 0.00511687324626887852*::pow(cos(0.5*vartheta[i]),3)*(178010. + 314160.*cos(vartheta[i]) + 281673.*cos(2.*vartheta[i]) + 188632.*cos(3.*vartheta[i]) + 129846.*cos(4.*vartheta[i]) + 54264.*cos(5.*vartheta[i]) + 24871.*cos(6.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.0135379740998672131*::pow(cos(0.5*vartheta[i]),2)*(37960. + 74347.*cos(vartheta[i]) + 62764.*cos(2.*vartheta[i]) + 50609.*cos(3.*vartheta[i]) + 33592.*cos(4.*vartheta[i]) + 20995.*cos(5.*vartheta[i]) + 9044.*cos(6.*vartheta[i]) + 3553.*cos(7.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.000926881724677246133*cos(0.5*vartheta[i])*(274703. + 526240.*cos(vartheta[i]) + 474760.*cos(2.*vartheta[i]) + 388960.*cos(3.*vartheta[i]) + 296140.*cos(4.*vartheta[i]) + 196384.*cos(5.*vartheta[i]) + 116280.*cos(6.*vartheta[i]) + 51680.*cos(7.*vartheta[i]) + 17765.*cos(8.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.0000412865934738617689*(2.414412e6 + 4.702698e6*cos(vartheta[i]) + 4.32432e6*cos(2.*vartheta[i]) + 3.75102e6*cos(3.*vartheta[i]) + 3.033072e6*cos(4.*vartheta[i]) + 2.266236e6*cos(5.*vartheta[i]) + 1.519392e6*cos(6.*vartheta[i]) + 886635.*cos(7.*vartheta[i]) + 406980.*cos(8.*vartheta[i]) + 124355.*cos(9.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -varphi[i];
        swsh[i] = 0.000235369796324778191*cos(0.5*vartheta[i])*(126126. + 261954.*cos(vartheta[i]) + 232848.*cos(2.*vartheta[i]) + 224028.*cos(3.*vartheta[i]) + 179928.*cos(4.*vartheta[i]) + 158508.*cos(5.*vartheta[i]) + 108528.*cos(6.*vartheta[i]) + 84303.*cos(7.*vartheta[i]) + 40698.*cos(8.*vartheta[i]) + 24871.*cos(9.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.00135209654009058458*cos(vartheta[i])*(2719. + 4264.*cos(2.*vartheta[i]) + 4556.*cos(4.*vartheta[i]) + 2584.*cos(6.*vartheta[i]) + 2261.*cos(8.*vartheta[i]))*::pow(sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = varphi[i];
        swsh[i] = 0.000235369796324778191*::pow(cos(0.5*vartheta[i]),3)*(-126126. + 261954.*cos(vartheta[i]) - 232848.*cos(2.*vartheta[i]) + 224028.*cos(3.*vartheta[i]) - 179928.*cos(4.*vartheta[i]) + 158508.*cos(5.*vartheta[i]) - 108528.*cos(6.*vartheta[i]) + 84303.*cos(7.*vartheta[i]) - 40698.*cos(8.*vartheta[i]) + 24871.*cos(9.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.0000412865934738617689*::pow(cos(0.5*vartheta[i]),4)*(-2.414412e6 + 4.702698e6*cos(vartheta[i]) - 4.32432e6*cos(2.*vartheta[i]) + 3.75102e6*cos(3.*vartheta[i]) - 3.033072e6*cos(4.*vartheta[i]) + 2.266236e6*cos(5.*vartheta[i]) - 1.519392e6*cos(6.*vartheta[i]) + 886635.*cos(7.*vartheta[i]) - 406980.*cos(8.*vartheta[i]) + 124355.*cos(9.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.000926881724677246133*::pow(cos(0.5*vartheta[i]),5)*(274703. - 526240.*cos(vartheta[i]) + 474760.*cos(2.*vartheta[i]) - 388960.*cos(3.*vartheta[i]) + 296140.*cos(4.*vartheta[i]) - 196384.*cos(5.*vartheta[i]) + 116280.*cos(6.*vartheta[i]) - 51680.*cos(7.*vartheta[i]) + 17765.*cos(8.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.0135379740998672131*::pow(cos(0.5*vartheta[i]),6)*(-37960. + 74347.*cos(vartheta[i]) - 62764.*cos(2.*vartheta[i]) + 50609.*cos(3.*vartheta[i]) - 33592.*cos(4.*vartheta[i]) + 20995.*cos(5.*vartheta[i]) - 9044.*cos(6.*vartheta[i]) + 3553.*cos(7.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -0.00511687324626887852*::pow(cos(0.5*vartheta[i]),7)*(178010. - 314160.*cos(vartheta[i]) + 281673.*cos(2.*vartheta[i]) - 188632.*cos(3.*vartheta[i]) + 129846.*cos(4.*vartheta[i]) - 54264.*cos(5.*vartheta[i]) + 24871.*cos(6.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 0.206711546478661343*::pow(cos(0.5*vartheta[i]),8)*(-5644. + 12078.*cos(vartheta[i]) - 8208.*cos(2.*vartheta[i]) + 6555.*cos(3.*vartheta[i]) - 2660.*cos(4.*vartheta[i]) + 1463.*cos(5.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 7*varphi[i];
        swsh[i] = -0.0871572407371104511*::pow(cos(0.5*vartheta[i]),9)*(19529. - 27056.*cos(vartheta[i]) + 26980.*cos(2.*vartheta[i]) - 10640.*cos(3.*vartheta[i]) + 7315.*cos(4.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 8*varphi[i];
        swsh[i] = 3.03927683656728721*::pow(cos(0.5*vartheta[i]),10)*(-388. + 1095.*cos(vartheta[i]) - 420.*cos(2.*vartheta[i]) + 385.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 9*varphi[i];
        swsh[i] = -23.542137145078129*::pow(cos(0.5*vartheta[i]),11)*(75. - 56.*cos(vartheta[i]) + 77.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 10:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 10*varphi[i];
        swsh[i] = 203.427315098143017*::pow(cos(0.5*vartheta[i]),12)*(-2. + 11.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 11:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 11*varphi[i];
        swsh[i] = -954.1586847148967*::pow(cos(0.5*vartheta[i]),13)*::pow(sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 12:
    switch(M) {
    case -12:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -12*varphi[i];
        swsh[i] = 1975.29613940745059*::pow(cos(0.5*vartheta[i]),10)*::pow(sin(0.5*vartheta[i]),14)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -11:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -11*varphi[i];
        swsh[i] = 806.411272072960143*::pow(cos(0.5*vartheta[i]),9)*(1. + 6.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),13)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -10:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -10*varphi[i];
        swsh[i] = 59.4494277098981063*::pow(cos(0.5*vartheta[i]),8)*(67. + 46.*cos(vartheta[i]) + 69.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),12)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -9*varphi[i];
        swsh[i] = 10.9765780420191242*::pow(cos(0.5*vartheta[i]),7)*(235. + 715.*cos(vartheta[i]) + 253.*cos(2.*vartheta[i]) + 253.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),11)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -8*varphi[i];
        swsh[i] = 2.09587498954761674*::pow(cos(0.5*vartheta[i]),6)*(2005. + 2604.*cos(vartheta[i]) + 2772.*cos(2.*vartheta[i]) + 1012.*cos(3.*vartheta[i]) + 759.*cos(4.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),10)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -7*varphi[i];
        swsh[i] = 1.04793749477380837*::pow(cos(0.5*vartheta[i]),5)*(2755. + 6190.*cos(vartheta[i]) + 3980.*cos(2.*vartheta[i]) + 3355.*cos(3.*vartheta[i]) + 1265.*cos(4.*vartheta[i]) + 759.*cos(5.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 0.0736112541772210869*::pow(cos(0.5*vartheta[i]),4)*(34170. + 58140.*cos(vartheta[i]) + 53865.*cos(2.*vartheta[i]) + 34390.*cos(3.*vartheta[i]) + 24662.*cos(4.*vartheta[i]) + 9614.*cos(5.*vartheta[i]) + 4807.*cos(6.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 0.00983671760506762245*::pow(cos(0.5*vartheta[i]),3)*(152150. + 303975.*cos(vartheta[i]) + 249375.*cos(2.*vartheta[i]) + 204421.*cos(3.*vartheta[i]) + 130074.*cos(4.*vartheta[i]) + 83391.*cos(5.*vartheta[i]) + 33649.*cos(6.*vartheta[i]) + 14421.*cos(7.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.000210872893964438159*::pow(cos(0.5*vartheta[i]),2)*(3.952975e6 + 7.4698e6*cos(vartheta[i]) + 6.769672e6*cos(2.*vartheta[i]) + 5.408312e6*cos(3.*vartheta[i]) + 4.11502e6*cos(4.*vartheta[i]) + 2.62276e6*cos(5.*vartheta[i]) + 1.56332e6*cos(6.*vartheta[i]) + 653752.*cos(7.*vartheta[i]) + 245157.*cos(8.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.000210872893964438159*cos(0.5*vartheta[i])*(1.748175e6 + 3.408834e6*cos(vartheta[i]) + 3.092232e6*cos(2.*vartheta[i]) + 2.654652e6*cos(3.*vartheta[i]) + 2.089164e6*cos(4.*vartheta[i]) + 1.53102e6*cos(5.*vartheta[i]) + 984504.*cos(6.*vartheta[i]) + 564927.*cos(7.*vartheta[i]) + 245157.*cos(8.*vartheta[i]) + 81719.*cos(9.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.0000215221246165373339*(6.205914e6 + 1.212354e7*cos(vartheta[i]) + 1.131273e7*cos(2.*vartheta[i]) + 1.003068e7*cos(3.*vartheta[i]) + 8.42724e6*cos(4.*vartheta[i]) + 6.62796e6*cos(5.*vartheta[i]) + 4.830465e6*cos(6.*vartheta[i]) + 3.16863e6*cos(7.*vartheta[i]) + 1.81203e6*cos(8.*vartheta[i]) + 817190.*cos(9.*vartheta[i]) + 245157.*cos(10.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -varphi[i];
        swsh[i] = 0.000267082542659574423*cos(0.5*vartheta[i])*(144144. + 270270.*cos(vartheta[i]) + 270270.*cos(2.*vartheta[i]) + 235620.*cos(3.*vartheta[i]) + 220320.*cos(4.*vartheta[i]) + 174420.*cos(5.*vartheta[i]) + 150195.*cos(6.*vartheta[i]) + 101745.*cos(7.*vartheta[i]) + 77520.*cos(8.*vartheta[i]) + 37145.*cos(9.*vartheta[i]) + 22287.*cos(10.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.000208491243039524634*(18018. + 34650.*cos(2.*vartheta[i]) + 30600.*cos(4.*vartheta[i]) + 24225.*cos(6.*vartheta[i]) + 16150.*cos(8.*vartheta[i]) + 7429.*cos(10.*vartheta[i]))*::pow(sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = varphi[i];
        swsh[i] = 0.000267082542659574423*::pow(cos(0.5*vartheta[i]),3)*(144144. - 270270.*cos(vartheta[i]) + 270270.*cos(2.*vartheta[i]) - 235620.*cos(3.*vartheta[i]) + 220320.*cos(4.*vartheta[i]) - 174420.*cos(5.*vartheta[i]) + 150195.*cos(6.*vartheta[i]) - 101745.*cos(7.*vartheta[i]) + 77520.*cos(8.*vartheta[i]) - 37145.*cos(9.*vartheta[i]) + 22287.*cos(10.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.0000215221246165373339*::pow(cos(0.5*vartheta[i]),4)*(6.205914e6 - 1.212354e7*cos(vartheta[i]) + 1.131273e7*cos(2.*vartheta[i]) - 1.003068e7*cos(3.*vartheta[i]) + 8.42724e6*cos(4.*vartheta[i]) - 6.62796e6*cos(5.*vartheta[i]) + 4.830465e6*cos(6.*vartheta[i]) - 3.16863e6*cos(7.*vartheta[i]) + 1.81203e6*cos(8.*vartheta[i]) - 817190.*cos(9.*vartheta[i]) + 245157.*cos(10.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.000210872893964438159*::pow(cos(0.5*vartheta[i]),5)*(-1.748175e6 + 3.408834e6*cos(vartheta[i]) - 3.092232e6*cos(2.*vartheta[i]) + 2.654652e6*cos(3.*vartheta[i]) - 2.089164e6*cos(4.*vartheta[i]) + 1.53102e6*cos(5.*vartheta[i]) - 984504.*cos(6.*vartheta[i]) + 564927.*cos(7.*vartheta[i]) - 245157.*cos(8.*vartheta[i]) + 81719.*cos(9.*vartheta[i]))*sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.000210872893964438159*::pow(cos(0.5*vartheta[i]),6)*(3.952975e6 - 7.4698e6*cos(vartheta[i]) + 6.769672e6*cos(2.*vartheta[i]) - 5.408312e6*cos(3.*vartheta[i]) + 4.11502e6*cos(4.*vartheta[i]) - 2.62276e6*cos(5.*vartheta[i]) + 1.56332e6*cos(6.*vartheta[i]) - 653752.*cos(7.*vartheta[i]) + 245157.*cos(8.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -0.00983671760506762245*::pow(cos(0.5*vartheta[i]),7)*(-152150. + 303975.*cos(vartheta[i]) - 249375.*cos(2.*vartheta[i]) + 204421.*cos(3.*vartheta[i]) - 130074.*cos(4.*vartheta[i]) + 83391.*cos(5.*vartheta[i]) - 33649.*cos(6.*vartheta[i]) + 14421.*cos(7.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 0.0736112541772210869*::pow(cos(0.5*vartheta[i]),8)*(34170. - 58140.*cos(vartheta[i]) + 53865.*cos(2.*vartheta[i]) - 34390.*cos(3.*vartheta[i]) + 24662.*cos(4.*vartheta[i]) - 9614.*cos(5.*vartheta[i]) + 4807.*cos(6.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 7*varphi[i];
        swsh[i] = -1.04793749477380837*::pow(cos(0.5*vartheta[i]),9)*(-2755. + 6190.*cos(vartheta[i]) - 3980.*cos(2.*vartheta[i]) + 3355.*cos(3.*vartheta[i]) - 1265.*cos(4.*vartheta[i]) + 759.*cos(5.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 8*varphi[i];
        swsh[i] = 2.09587498954761674*::pow(cos(0.5*vartheta[i]),10)*(2005. - 2604.*cos(vartheta[i]) + 2772.*cos(2.*vartheta[i]) - 1012.*cos(3.*vartheta[i]) + 759.*cos(4.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 9*varphi[i];
        swsh[i] = -10.9765780420191242*::pow(cos(0.5*vartheta[i]),11)*(-235. + 715.*cos(vartheta[i]) - 253.*cos(2.*vartheta[i]) + 253.*cos(3.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 10:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 10*varphi[i];
        swsh[i] = 59.4494277098981063*::pow(cos(0.5*vartheta[i]),12)*(67. - 46.*cos(vartheta[i]) + 69.*cos(2.*vartheta[i]))*::pow(sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 11:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 11*varphi[i];
        swsh[i] = -806.411272072960143*::pow(cos(0.5*vartheta[i]),13)*(-1. + 6.*cos(vartheta[i]))*::pow(sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 12:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 12*varphi[i];
        swsh[i] = 1975.29613940745059*::pow(cos(0.5*vartheta[i]),14)*::pow(sin(0.5*vartheta[i]),10)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  } // switch(L)

  return swsh;
}


void WU::SWSH(const vector<vector<int> >& LM, const double vartheta, const double varphi, vector<double>& amp, vector<double>& arg) {
  amp.resize(LM.size());
  arg.resize(LM.size());
  for(unsigned int i=0; i<LM.size(); ++i) {
    WU::SWSH(LM[i][0], LM[i][1], vartheta, varphi, amp[i], arg[i]);
  }
  return;
}
