#include "SWSHs.hpp"
#include <cstdlib>
#include <cmath>
#include "VectorFunctions.hpp"
using namespace std;
namespace WU = WaveformUtilities;

void WU::SWSH(const int L, const int M, const double vartheta, const double varphi, double& amp, double& arg) {
  if(L<2) { Throw1WithMessage("l<2 unsupported."); }
  if(labs(M)>L) { Throw1WithMessage("abs(m)>l unsupported for s=-2 spin-weighted spherical harmonics."); }
  if(L>12) { Throw1WithMessage("l>12 unsupported."); }
  
  switch(L) {
  case 2:
    switch(M) {
    case -2:
      amp = 0.630783130505040012*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 1.26156626101008002*Cos(0.5*vartheta)*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -1*varphi + M_PI;
      } else {
        arg = -1*varphi;
      }
      return;
    case 0:
      amp = 0.38627420202318958*Power(Sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 1.26156626101008002*Power(Cos(0.5*vartheta),3)*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 1*varphi + M_PI;
      } else {
        arg = 1*varphi;
      }
      return;
    case 2:
      amp = 0.630783130505040012*Power(Cos(0.5*vartheta),4);
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
      amp = 1.82818319785786294*Cos(0.5*vartheta)*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.746352665180230783*(2. + 3.*Cos(vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 1.18008717985328702*Cos(0.5*vartheta)*(1. + 3.*Cos(vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -1*varphi + M_PI;
      } else {
        arg = -1*varphi;
      }
      return;
    case 0:
      amp = 1.02198547643328236*Cos(vartheta)*Power(Sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 1.18008717985328702*Power(Cos(0.5*vartheta),3)*(-1. + 3.*Cos(vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 1*varphi + M_PI;
      } else {
        arg = 1*varphi;
      }
      return;
    case 2:
      amp = 0.746352665180230783*Power(Cos(0.5*vartheta),4)*(-2. + 3.*Cos(vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -1.82818319785786294*Power(Cos(0.5*vartheta),5)*Sin(0.5*vartheta);
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
      amp = 4.4781159910813847*Power(Cos(0.5*vartheta),2)*Power(Sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 3.16650618423356409*Cos(0.5*vartheta)*(1. + 2.*Cos(vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.423142187660817215*(9. + 14.*Cos(vartheta) + 7.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.598413420602149017*Cos(0.5*vartheta)*(6. + 7.*Cos(vartheta) + 7.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -1*varphi + M_PI;
      } else {
        arg = -1*varphi;
      }
      return;
    case 0:
      amp = 0.167261635889322292*(5. + 7.*Cos(2.*vartheta))*Power(Sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.598413420602149017*Power(Cos(0.5*vartheta),3)*(6. - 7.*Cos(vartheta) + 7.*Cos(2.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 1*varphi + M_PI;
      } else {
        arg = 1*varphi;
      }
      return;
    case 2:
      amp = 0.423142187660817215*Power(Cos(0.5*vartheta),4)*(9. - 14.*Cos(vartheta) + 7.*Cos(2.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -3.16650618423356409*Power(Cos(0.5*vartheta),5)*(-1. + 2.*Cos(vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 4.4781159910813847*Power(Cos(0.5*vartheta),6)*Power(Sin(0.5*vartheta),2);
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
      amp = 10.2490127544388841*Power(Cos(0.5*vartheta),3)*Power(Sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 3.24102240721428709*Power(Cos(0.5*vartheta),2)*(2. + 5.*Cos(vartheta))*Power(Sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.572937230529692607*Cos(0.5*vartheta)*(17. + 24.*Cos(vartheta) + 15.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.233900644906847193*(32. + 57.*Cos(vartheta) + 36.*Cos(2.*vartheta) + 15.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.309421468960572107*Cos(0.5*vartheta)*(14. + 33.*Cos(vartheta) + 18.*Cos(2.*vartheta) + 15.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -1*varphi + M_PI;
      } else {
        arg = -1*varphi;
      }
      return;
    case 0:
      amp = 0.847385591630449638*Cos(vartheta)*(1. + 3.*Cos(2.*vartheta))*Power(Sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.309421468960572107*Power(Cos(0.5*vartheta),3)*(-14. + 33.*Cos(vartheta) - 18.*Cos(2.*vartheta) + 15.*Cos(3.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 1*varphi + M_PI;
      } else {
        arg = 1*varphi;
      }
      return;
    case 2:
      amp = 0.233900644906847193*Power(Cos(0.5*vartheta),4)*(-32. + 57.*Cos(vartheta) - 36.*Cos(2.*vartheta) + 15.*Cos(3.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.572937230529692607*Power(Cos(0.5*vartheta),5)*(17. - 24.*Cos(vartheta) + 15.*Cos(2.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 3.24102240721428709*Power(Cos(0.5*vartheta),6)*(-2. + 5.*Cos(vartheta))*Power(Sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -10.2490127544388841*Power(Cos(0.5*vartheta),7)*Power(Sin(0.5*vartheta),3);
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
      amp = 22.6292074407870777*Power(Cos(0.5*vartheta),4)*Power(Sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 13.0649790074863016*Power(Cos(0.5*vartheta),3)*(1. + 3.*Cos(vartheta))*Power(Sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.696365720891772932*Power(Cos(0.5*vartheta),2)*(35. + 44.*Cos(vartheta) + 33.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.190707606802885278*Cos(0.5*vartheta)*(98. + 185.*Cos(vartheta) + 110.*Cos(2.*vartheta) + 55.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.00794615028345355324*(1709. + 3096.*Cos(vartheta) + 2340.*Cos(2.*vartheta) + 1320.*Cos(3.*vartheta) + 495.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.0502558670514116131*Cos(0.5*vartheta)*(161. + 252.*Cos(vartheta) + 252.*Cos(2.*vartheta) + 132.*Cos(3.*vartheta) + 99.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -1*varphi + M_PI;
      } else {
        arg = -1*varphi;
      }
      return;
    case 0:
      amp = 0.0407119053667322336*(35. + 60.*Cos(2.*vartheta) + 33.*Cos(4.*vartheta))*Power(Sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.0502558670514116131*Power(Cos(0.5*vartheta),3)*(161. - 252.*Cos(vartheta) + 252.*Cos(2.*vartheta) - 132.*Cos(3.*vartheta) + 99.*Cos(4.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 1*varphi + M_PI;
      } else {
        arg = 1*varphi;
      }
      return;
    case 2:
      amp = 0.00794615028345355324*Power(Cos(0.5*vartheta),4)*(1709. - 3096.*Cos(vartheta) + 2340.*Cos(2.*vartheta) - 1320.*Cos(3.*vartheta) + 495.*Cos(4.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.190707606802885278*Power(Cos(0.5*vartheta),5)*(-98. + 185.*Cos(vartheta) - 110.*Cos(2.*vartheta) + 55.*Cos(3.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.696365720891772932*Power(Cos(0.5*vartheta),6)*(35. - 44.*Cos(vartheta) + 33.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -13.0649790074863016*Power(Cos(0.5*vartheta),7)*(-1. + 3.*Cos(vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 22.6292074407870777*Power(Cos(0.5*vartheta),8)*Power(Sin(0.5*vartheta),4);
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
      amp = 48.8846752114075978*Power(Cos(0.5*vartheta),5)*Power(Sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = -7*varphi + M_PI;
      } else {
        arg = -7*varphi;
      }
      return;
    case -6:
      amp = 13.0649790074863016*Power(Cos(0.5*vartheta),4)*(2. + 7.*Cos(vartheta))*Power(Sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 0.640563297152430255*Power(Cos(0.5*vartheta),3)*(93. + 104.*Cos(vartheta) + 91.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.320281648576215128*Power(Cos(0.5*vartheta),2)*(140. + 285.*Cos(vartheta) + 156.*Cos(2.*vartheta) + 91.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.0120710688132246744*Cos(0.5*vartheta)*(3115. + 5456.*Cos(vartheta) + 4268.*Cos(2.*vartheta) + 2288.*Cos(3.*vartheta) + 1001.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.00426776730700030887*(5220. + 9810.*Cos(vartheta) + 7920.*Cos(2.*vartheta) + 5445.*Cos(3.*vartheta) + 2860.*Cos(4.*vartheta) + 1001.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.00522692612154132162*Cos(0.5*vartheta)*(1890. + 4130.*Cos(vartheta) + 3080.*Cos(2.*vartheta) + 2805.*Cos(3.*vartheta) + 1430.*Cos(4.*vartheta) + 1001.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -1*varphi + M_PI;
      } else {
        arg = -1*varphi;
      }
      return;
    case 0:
      amp = 0.0195573667327867542*Cos(vartheta)*(109. + 132.*Cos(2.*vartheta) + 143.*Cos(4.*vartheta))*Power(Sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.00522692612154132162*Power(Cos(0.5*vartheta),3)*(-1890. + 4130.*Cos(vartheta) - 3080.*Cos(2.*vartheta) + 2805.*Cos(3.*vartheta) - 1430.*Cos(4.*vartheta) + 1001.*Cos(5.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 1*varphi + M_PI;
      } else {
        arg = 1*varphi;
      }
      return;
    case 2:
      amp = 0.00426776730700030887*Power(Cos(0.5*vartheta),4)*(-5220. + 9810.*Cos(vartheta) - 7920.*Cos(2.*vartheta) + 5445.*Cos(3.*vartheta) - 2860.*Cos(4.*vartheta) + 1001.*Cos(5.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.0120710688132246744*Power(Cos(0.5*vartheta),5)*(3115. - 5456.*Cos(vartheta) + 4268.*Cos(2.*vartheta) - 2288.*Cos(3.*vartheta) + 1001.*Cos(4.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.320281648576215128*Power(Cos(0.5*vartheta),6)*(-140. + 285.*Cos(vartheta) - 156.*Cos(2.*vartheta) + 91.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -0.640563297152430255*Power(Cos(0.5*vartheta),7)*(93. - 104.*Cos(vartheta) + 91.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 13.0649790074863016*Power(Cos(0.5*vartheta),8)*(-2. + 7.*Cos(vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 6*varphi + M_PI;
      } else {
        arg = 6*varphi;
      }
      return;
    case 7:
      amp = -48.8846752114075978*Power(Cos(0.5*vartheta),9)*Power(Sin(0.5*vartheta),5);
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
      amp = 104.083421669251111*Power(Cos(0.5*vartheta),6)*Power(Sin(0.5*vartheta),10);
      if(amp<0) {
        amp = -amp;
        arg = -8*varphi + M_PI;
      } else {
        arg = -8*varphi;
      }
      return;
    case -7:
      amp = 52.0417108346255555*Power(Cos(0.5*vartheta),5)*(1. + 4.*Cos(vartheta))*Power(Sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = -7*varphi + M_PI;
      } else {
        arg = -7*varphi;
      }
      return;
    case -6:
      amp = 285.044189552854222*Power(Cos(0.5*vartheta),4)*(1. + 2.*Cos(vartheta))*Sin(0.78539816339744831 - 0.5*vartheta)*Sin(0.78539816339744831 + 0.5*vartheta)*Power(Sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 5.49790916690436597*Power(Cos(0.5*vartheta),3)*(19. + 42.*Cos(vartheta) + 21.*Cos(2.*vartheta) + 14.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.381211411713792221*Power(Cos(0.5*vartheta),2)*(265. + 442.*Cos(vartheta) + 364.*Cos(2.*vartheta) + 182.*Cos(3.*vartheta) + 91.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.0738212724475868138*Cos(0.5*vartheta)*(869. + 1660.*Cos(vartheta) + 1300.*Cos(2.*vartheta) + 910.*Cos(3.*vartheta) + 455.*Cos(4.*vartheta) + 182.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.00454338524578249815*(7626. + 14454.*Cos(vartheta) + 12375.*Cos(2.*vartheta) + 9295.*Cos(3.*vartheta) + 6006.*Cos(4.*vartheta) + 3003.*Cos(5.*vartheta) + 1001.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.0190063441014545613*Cos(0.5*vartheta)*(798. + 1386.*Cos(vartheta) + 1386.*Cos(2.*vartheta) + 1001.*Cos(3.*vartheta) + 858.*Cos(4.*vartheta) + 429.*Cos(5.*vartheta) + 286.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -1*varphi + M_PI;
      } else {
        arg = -1*varphi;
      }
      return;
    case 0:
      amp = 0.010079636099777594*(210. + 385.*Cos(2.*vartheta) + 286.*Cos(4.*vartheta) + 143.*Cos(6.*vartheta))*Power(Sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.0190063441014545613*Power(Cos(0.5*vartheta),3)*(798. - 1386.*Cos(vartheta) + 1386.*Cos(2.*vartheta) - 1001.*Cos(3.*vartheta) + 858.*Cos(4.*vartheta) - 429.*Cos(5.*vartheta) + 286.*Cos(6.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 1*varphi + M_PI;
      } else {
        arg = 1*varphi;
      }
      return;
    case 2:
      amp = 0.00454338524578249815*Power(Cos(0.5*vartheta),4)*(7626. - 14454.*Cos(vartheta) + 12375.*Cos(2.*vartheta) - 9295.*Cos(3.*vartheta) + 6006.*Cos(4.*vartheta) - 3003.*Cos(5.*vartheta) + 1001.*Cos(6.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.0738212724475868138*Power(Cos(0.5*vartheta),5)*(-869. + 1660.*Cos(vartheta) - 1300.*Cos(2.*vartheta) + 910.*Cos(3.*vartheta) - 455.*Cos(4.*vartheta) + 182.*Cos(5.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.381211411713792221*Power(Cos(0.5*vartheta),6)*(265. - 442.*Cos(vartheta) + 364.*Cos(2.*vartheta) - 182.*Cos(3.*vartheta) + 91.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -5.49790916690436597*Power(Cos(0.5*vartheta),7)*(-19. + 42.*Cos(vartheta) - 21.*Cos(2.*vartheta) + 14.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 285.044189552854222*Power(Cos(0.5*vartheta),8)*(-1. + 2.*Cos(vartheta))*Sin(0.78539816339744831 - 0.5*vartheta)*Sin(0.78539816339744831 + 0.5*vartheta)*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 6*varphi + M_PI;
      } else {
        arg = 6*varphi;
      }
      return;
    case 7:
      amp = -52.0417108346255555*Power(Cos(0.5*vartheta),9)*(-1. + 4.*Cos(vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = 7*varphi + M_PI;
      } else {
        arg = 7*varphi;
      }
      return;
    case 8:
      amp = 104.083421669251111*Power(Cos(0.5*vartheta),10)*Power(Sin(0.5*vartheta),6);
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
      amp = 219.355865285354367*Power(Cos(0.5*vartheta),7)*Power(Sin(0.5*vartheta),11);
      if(amp<0) {
        amp = -amp;
        arg = -9*varphi + M_PI;
      } else {
        arg = -9*varphi;
      }
      return;
    case -8:
      amp = 51.7026732787722888*Power(Cos(0.5*vartheta),6)*(2. + 9.*Cos(vartheta))*Power(Sin(0.5*vartheta),10);
      if(amp<0) {
        amp = -amp;
        arg = -8*varphi + M_PI;
      } else {
        arg = -8*varphi;
      }
      return;
    case -7:
      amp = 2.21673382884871148*Power(Cos(0.5*vartheta),5)*(151. + 136.*Cos(vartheta) + 153.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = -7*varphi + M_PI;
      } else {
        arg = -7*varphi;
      }
      return;
    case -6:
      amp = 3.83949561842266015*Power(Cos(0.5*vartheta),4)*(62. + 149.*Cos(vartheta) + 68.*Cos(2.*vartheta) + 51.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 0.619595941166137906*Power(Cos(0.5*vartheta),3)*(427. + 672.*Cos(vartheta) + 588.*Cos(2.*vartheta) + 272.*Cos(3.*vartheta) + 153.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.259195578288233226*Power(Cos(0.5*vartheta),2)*(676. + 1330.*Cos(vartheta) + 1000.*Cos(2.*vartheta) + 725.*Cos(3.*vartheta) + 340.*Cos(4.*vartheta) + 153.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.022011090048569557*Cos(0.5*vartheta)*(4906. + 9152.*Cos(vartheta) + 7865.*Cos(2.*vartheta) + 5720.*Cos(3.*vartheta) + 3718.*Cos(4.*vartheta) + 1768.*Cos(5.*vartheta) + 663.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.00240160681609664791*(21252. + 40887.*Cos(vartheta) + 36036.*Cos(2.*vartheta) + 29029.*Cos(3.*vartheta) + 20748.*Cos(4.*vartheta) + 12831.*Cos(5.*vartheta) + 6188.*Cos(6.*vartheta) + 1989.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.00281613361477977156*Cos(0.5*vartheta)*(6468. + 13671.*Cos(vartheta) + 11466.*Cos(2.*vartheta) + 10829.*Cos(3.*vartheta) + 7644.*Cos(4.*vartheta) + 6279.*Cos(5.*vartheta) + 3094.*Cos(6.*vartheta) + 1989.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -1*varphi + M_PI;
      } else {
        arg = -1*varphi;
      }
      return;
    case 0:
      amp = 0.0133580946271009442*Cos(vartheta)*(166. + 403.*Cos(2.*vartheta) + 234.*Cos(4.*vartheta) + 221.*Cos(6.*vartheta))*Power(Sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.00281613361477977156*Power(Cos(0.5*vartheta),3)*(-6468. + 13671.*Cos(vartheta) - 11466.*Cos(2.*vartheta) + 10829.*Cos(3.*vartheta) - 7644.*Cos(4.*vartheta) + 6279.*Cos(5.*vartheta) - 3094.*Cos(6.*vartheta) + 1989.*Cos(7.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 1*varphi + M_PI;
      } else {
        arg = 1*varphi;
      }
      return;
    case 2:
      amp = 0.00240160681609664791*Power(Cos(0.5*vartheta),4)*(-21252. + 40887.*Cos(vartheta) - 36036.*Cos(2.*vartheta) + 29029.*Cos(3.*vartheta) - 20748.*Cos(4.*vartheta) + 12831.*Cos(5.*vartheta) - 6188.*Cos(6.*vartheta) + 1989.*Cos(7.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.022011090048569557*Power(Cos(0.5*vartheta),5)*(4906. - 9152.*Cos(vartheta) + 7865.*Cos(2.*vartheta) - 5720.*Cos(3.*vartheta) + 3718.*Cos(4.*vartheta) - 1768.*Cos(5.*vartheta) + 663.*Cos(6.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.259195578288233226*Power(Cos(0.5*vartheta),6)*(-676. + 1330.*Cos(vartheta) - 1000.*Cos(2.*vartheta) + 725.*Cos(3.*vartheta) - 340.*Cos(4.*vartheta) + 153.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -0.619595941166137906*Power(Cos(0.5*vartheta),7)*(427. - 672.*Cos(vartheta) + 588.*Cos(2.*vartheta) - 272.*Cos(3.*vartheta) + 153.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 3.83949561842266015*Power(Cos(0.5*vartheta),8)*(-62. + 149.*Cos(vartheta) - 68.*Cos(2.*vartheta) + 51.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 6*varphi + M_PI;
      } else {
        arg = 6*varphi;
      }
      return;
    case 7:
      amp = -2.21673382884871148*Power(Cos(0.5*vartheta),9)*(151. - 136.*Cos(vartheta) + 153.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = 7*varphi + M_PI;
      } else {
        arg = 7*varphi;
      }
      return;
    case 8:
      amp = 51.7026732787722888*Power(Cos(0.5*vartheta),10)*(-2. + 9.*Cos(vartheta))*Power(Sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = 8*varphi + M_PI;
      } else {
        arg = 8*varphi;
      }
      return;
    case 9:
      amp = -219.355865285354367*Power(Cos(0.5*vartheta),11)*Power(Sin(0.5*vartheta),7);
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
      amp = 458.815710175124215*Power(Cos(0.5*vartheta),8)*Power(Sin(0.5*vartheta),12);
      if(amp<0) {
        amp = -amp;
        arg = -10*varphi + M_PI;
      } else {
        arg = -10*varphi;
      }
      return;
    case -9:
      amp = 205.188623419283937*Power(Cos(0.5*vartheta),7)*(1. + 5.*Cos(vartheta))*Power(Sin(0.5*vartheta),11);
      if(amp<0) {
        amp = -amp;
        arg = -9*varphi + M_PI;
      } else {
        arg = -9*varphi;
      }
      return;
    case -8:
      amp = 8.32149752273527606*Power(Cos(0.5*vartheta),6)*(93. + 76.*Cos(vartheta) + 95.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),10);
      if(amp<0) {
        amp = -amp;
        arg = -8*varphi + M_PI;
      } else {
        arg = -8*varphi;
      }
      return;
    case -7:
      amp = 1.69861856887797376*Power(Cos(0.5*vartheta),5)*(314. + 819.*Cos(vartheta) + 342.*Cos(2.*vartheta) + 285.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = -7*varphi + M_PI;
      } else {
        arg = -7*varphi;
      }
      return;
    case -6:
      amp = 0.0514969395376425972*Power(Cos(0.5*vartheta),4)*(13159. + 19448.*Cos(vartheta) + 18156.*Cos(2.*vartheta) + 7752.*Cos(3.*vartheta) + 4845.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 0.115150657439365437*Power(Cos(0.5*vartheta),3)*(3990. + 8162.*Cos(vartheta) + 5848.*Cos(2.*vartheta) + 4437.*Cos(3.*vartheta) + 1938.*Cos(4.*vartheta) + 969.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.00910345878935517795*Power(Cos(0.5*vartheta),2)*(35126. + 63960.*Cos(vartheta) + 55875.*Cos(2.*vartheta) + 39100.*Cos(3.*vartheta) + 26010.*Cos(4.*vartheta) + 11628.*Cos(5.*vartheta) + 4845.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.00321855872110266232*Cos(0.5*vartheta)*(52052. + 100639.*Cos(vartheta) + 87010.*Cos(2.*vartheta) + 69685.*Cos(3.*vartheta) + 48076.*Cos(4.*vartheta) + 29631.*Cos(5.*vartheta) + 13566.*Cos(6.*vartheta) + 4845.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.0000789014121372438118*(919611. + 1.777776e6*Cos(vartheta) + 1.609608e6*Cos(2.*vartheta) + 1.349712e6*Cos(3.*vartheta) + 1.041404e6*Cos(4.*vartheta) + 717808.*Cos(5.*vartheta) + 429624.*Cos(6.*vartheta) + 201552.*Cos(7.*vartheta) + 62985.*Cos(8.*vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.000273322509221275921*Cos(0.5*vartheta)*(92169. + 168168.*Cos(vartheta) + 168168.*Cos(2.*vartheta) + 137592.*Cos(3.*vartheta) + 124852.*Cos(4.*vartheta) + 86632.*Cos(5.*vartheta) + 68952.*Cos(6.*vartheta) + 33592.*Cos(7.*vartheta) + 20995.*Cos(8.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -1*varphi + M_PI;
      } else {
        arg = -1*varphi;
      }
      return;
    case 0:
      amp = 0.00035832883259417753*(8085. + 15288.*Cos(2.*vartheta) + 12740.*Cos(4.*vartheta) + 8840.*Cos(6.*vartheta) + 4199.*Cos(8.*vartheta))*Power(Sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.000273322509221275921*Power(Cos(0.5*vartheta),3)*(92169. - 168168.*Cos(vartheta) + 168168.*Cos(2.*vartheta) - 137592.*Cos(3.*vartheta) + 124852.*Cos(4.*vartheta) - 86632.*Cos(5.*vartheta) + 68952.*Cos(6.*vartheta) - 33592.*Cos(7.*vartheta) + 20995.*Cos(8.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 1*varphi + M_PI;
      } else {
        arg = 1*varphi;
      }
      return;
    case 2:
      amp = 0.0000789014121372438118*Power(Cos(0.5*vartheta),4)*(919611. - 1.777776e6*Cos(vartheta) + 1.609608e6*Cos(2.*vartheta) - 1.349712e6*Cos(3.*vartheta) + 1.041404e6*Cos(4.*vartheta) - 717808.*Cos(5.*vartheta) + 429624.*Cos(6.*vartheta) - 201552.*Cos(7.*vartheta) + 62985.*Cos(8.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.00321855872110266232*Power(Cos(0.5*vartheta),5)*(-52052. + 100639.*Cos(vartheta) - 87010.*Cos(2.*vartheta) + 69685.*Cos(3.*vartheta) - 48076.*Cos(4.*vartheta) + 29631.*Cos(5.*vartheta) - 13566.*Cos(6.*vartheta) + 4845.*Cos(7.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.00910345878935517795*Power(Cos(0.5*vartheta),6)*(35126. - 63960.*Cos(vartheta) + 55875.*Cos(2.*vartheta) - 39100.*Cos(3.*vartheta) + 26010.*Cos(4.*vartheta) - 11628.*Cos(5.*vartheta) + 4845.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -0.115150657439365437*Power(Cos(0.5*vartheta),7)*(-3990. + 8162.*Cos(vartheta) - 5848.*Cos(2.*vartheta) + 4437.*Cos(3.*vartheta) - 1938.*Cos(4.*vartheta) + 969.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 0.0514969395376425972*Power(Cos(0.5*vartheta),8)*(13159. - 19448.*Cos(vartheta) + 18156.*Cos(2.*vartheta) - 7752.*Cos(3.*vartheta) + 4845.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 6*varphi + M_PI;
      } else {
        arg = 6*varphi;
      }
      return;
    case 7:
      amp = -1.69861856887797376*Power(Cos(0.5*vartheta),9)*(-314. + 819.*Cos(vartheta) - 342.*Cos(2.*vartheta) + 285.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = 7*varphi + M_PI;
      } else {
        arg = 7*varphi;
      }
      return;
    case 8:
      amp = 8.32149752273527606*Power(Cos(0.5*vartheta),10)*(93. - 76.*Cos(vartheta) + 95.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = 8*varphi + M_PI;
      } else {
        arg = 8*varphi;
      }
      return;
    case 9:
      amp = -205.188623419283937*Power(Cos(0.5*vartheta),11)*(-1. + 5.*Cos(vartheta))*Power(Sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = 9*varphi + M_PI;
      } else {
        arg = 9*varphi;
      }
      return;
    case 10:
      amp = 458.815710175124215*Power(Cos(0.5*vartheta),12)*Power(Sin(0.5*vartheta),8);
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
      amp = 954.1586847148967*Power(Cos(0.5*vartheta),9)*Power(Sin(0.5*vartheta),13);
      if(amp<0) {
        amp = -amp;
        arg = -11*varphi + M_PI;
      } else {
        arg = -11*varphi;
      }
      return;
    case -10:
      amp = 203.427315098143017*Power(Cos(0.5*vartheta),8)*(2. + 11.*Cos(vartheta))*Power(Sin(0.5*vartheta),12);
      if(amp<0) {
        amp = -amp;
        arg = -10*varphi + M_PI;
      } else {
        arg = -10*varphi;
      }
      return;
    case -9:
      amp = 23.542137145078129*Power(Cos(0.5*vartheta),7)*(75. + 56.*Cos(vartheta) + 77.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),11);
      if(amp<0) {
        amp = -amp;
        arg = -9*varphi + M_PI;
      } else {
        arg = -9*varphi;
      }
      return;
    case -8:
      amp = 3.03927683656728721*Power(Cos(0.5*vartheta),6)*(388. + 1095.*Cos(vartheta) + 420.*Cos(2.*vartheta) + 385.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),10);
      if(amp<0) {
        amp = -amp;
        arg = -8*varphi + M_PI;
      } else {
        arg = -8*varphi;
      }
      return;
    case -7:
      amp = 0.0871572407371104511*Power(Cos(0.5*vartheta),5)*(19529. + 27056.*Cos(vartheta) + 26980.*Cos(2.*vartheta) + 10640.*Cos(3.*vartheta) + 7315.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = -7*varphi + M_PI;
      } else {
        arg = -7*varphi;
      }
      return;
    case -6:
      amp = 0.206711546478661343*Power(Cos(0.5*vartheta),4)*(5644. + 12078.*Cos(vartheta) + 8208.*Cos(2.*vartheta) + 6555.*Cos(3.*vartheta) + 2660.*Cos(4.*vartheta) + 1463.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 0.00511687324626887852*Power(Cos(0.5*vartheta),3)*(178010. + 314160.*Cos(vartheta) + 281673.*Cos(2.*vartheta) + 188632.*Cos(3.*vartheta) + 129846.*Cos(4.*vartheta) + 54264.*Cos(5.*vartheta) + 24871.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.0135379740998672131*Power(Cos(0.5*vartheta),2)*(37960. + 74347.*Cos(vartheta) + 62764.*Cos(2.*vartheta) + 50609.*Cos(3.*vartheta) + 33592.*Cos(4.*vartheta) + 20995.*Cos(5.*vartheta) + 9044.*Cos(6.*vartheta) + 3553.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.000926881724677246133*Cos(0.5*vartheta)*(274703. + 526240.*Cos(vartheta) + 474760.*Cos(2.*vartheta) + 388960.*Cos(3.*vartheta) + 296140.*Cos(4.*vartheta) + 196384.*Cos(5.*vartheta) + 116280.*Cos(6.*vartheta) + 51680.*Cos(7.*vartheta) + 17765.*Cos(8.*vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.0000412865934738617689*(2.414412e6 + 4.702698e6*Cos(vartheta) + 4.32432e6*Cos(2.*vartheta) + 3.75102e6*Cos(3.*vartheta) + 3.033072e6*Cos(4.*vartheta) + 2.266236e6*Cos(5.*vartheta) + 1.519392e6*Cos(6.*vartheta) + 886635.*Cos(7.*vartheta) + 406980.*Cos(8.*vartheta) + 124355.*Cos(9.*vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.000235369796324778191*Cos(0.5*vartheta)*(126126. + 261954.*Cos(vartheta) + 232848.*Cos(2.*vartheta) + 224028.*Cos(3.*vartheta) + 179928.*Cos(4.*vartheta) + 158508.*Cos(5.*vartheta) + 108528.*Cos(6.*vartheta) + 84303.*Cos(7.*vartheta) + 40698.*Cos(8.*vartheta) + 24871.*Cos(9.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -1*varphi + M_PI;
      } else {
        arg = -1*varphi;
      }
      return;
    case 0:
      amp = 0.00135209654009058458*Cos(vartheta)*(2719. + 4264.*Cos(2.*vartheta) + 4556.*Cos(4.*vartheta) + 2584.*Cos(6.*vartheta) + 2261.*Cos(8.*vartheta))*Power(Sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.000235369796324778191*Power(Cos(0.5*vartheta),3)*(-126126. + 261954.*Cos(vartheta) - 232848.*Cos(2.*vartheta) + 224028.*Cos(3.*vartheta) - 179928.*Cos(4.*vartheta) + 158508.*Cos(5.*vartheta) - 108528.*Cos(6.*vartheta) + 84303.*Cos(7.*vartheta) - 40698.*Cos(8.*vartheta) + 24871.*Cos(9.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 1*varphi + M_PI;
      } else {
        arg = 1*varphi;
      }
      return;
    case 2:
      amp = 0.0000412865934738617689*Power(Cos(0.5*vartheta),4)*(-2.414412e6 + 4.702698e6*Cos(vartheta) - 4.32432e6*Cos(2.*vartheta) + 3.75102e6*Cos(3.*vartheta) - 3.033072e6*Cos(4.*vartheta) + 2.266236e6*Cos(5.*vartheta) - 1.519392e6*Cos(6.*vartheta) + 886635.*Cos(7.*vartheta) - 406980.*Cos(8.*vartheta) + 124355.*Cos(9.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.000926881724677246133*Power(Cos(0.5*vartheta),5)*(274703. - 526240.*Cos(vartheta) + 474760.*Cos(2.*vartheta) - 388960.*Cos(3.*vartheta) + 296140.*Cos(4.*vartheta) - 196384.*Cos(5.*vartheta) + 116280.*Cos(6.*vartheta) - 51680.*Cos(7.*vartheta) + 17765.*Cos(8.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.0135379740998672131*Power(Cos(0.5*vartheta),6)*(-37960. + 74347.*Cos(vartheta) - 62764.*Cos(2.*vartheta) + 50609.*Cos(3.*vartheta) - 33592.*Cos(4.*vartheta) + 20995.*Cos(5.*vartheta) - 9044.*Cos(6.*vartheta) + 3553.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -0.00511687324626887852*Power(Cos(0.5*vartheta),7)*(178010. - 314160.*Cos(vartheta) + 281673.*Cos(2.*vartheta) - 188632.*Cos(3.*vartheta) + 129846.*Cos(4.*vartheta) - 54264.*Cos(5.*vartheta) + 24871.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 0.206711546478661343*Power(Cos(0.5*vartheta),8)*(-5644. + 12078.*Cos(vartheta) - 8208.*Cos(2.*vartheta) + 6555.*Cos(3.*vartheta) - 2660.*Cos(4.*vartheta) + 1463.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 6*varphi + M_PI;
      } else {
        arg = 6*varphi;
      }
      return;
    case 7:
      amp = -0.0871572407371104511*Power(Cos(0.5*vartheta),9)*(19529. - 27056.*Cos(vartheta) + 26980.*Cos(2.*vartheta) - 10640.*Cos(3.*vartheta) + 7315.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = 7*varphi + M_PI;
      } else {
        arg = 7*varphi;
      }
      return;
    case 8:
      amp = 3.03927683656728721*Power(Cos(0.5*vartheta),10)*(-388. + 1095.*Cos(vartheta) - 420.*Cos(2.*vartheta) + 385.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = 8*varphi + M_PI;
      } else {
        arg = 8*varphi;
      }
      return;
    case 9:
      amp = -23.542137145078129*Power(Cos(0.5*vartheta),11)*(75. - 56.*Cos(vartheta) + 77.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = 9*varphi + M_PI;
      } else {
        arg = 9*varphi;
      }
      return;
    case 10:
      amp = 203.427315098143017*Power(Cos(0.5*vartheta),12)*(-2. + 11.*Cos(vartheta))*Power(Sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = 10*varphi + M_PI;
      } else {
        arg = 10*varphi;
      }
      return;
    case 11:
      amp = -954.1586847148967*Power(Cos(0.5*vartheta),13)*Power(Sin(0.5*vartheta),9);
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
      amp = 1975.29613940745059*Power(Cos(0.5*vartheta),10)*Power(Sin(0.5*vartheta),14);
      if(amp<0) {
        amp = -amp;
        arg = -12*varphi + M_PI;
      } else {
        arg = -12*varphi;
      }
      return;
    case -11:
      amp = 806.411272072960143*Power(Cos(0.5*vartheta),9)*(1. + 6.*Cos(vartheta))*Power(Sin(0.5*vartheta),13);
      if(amp<0) {
        amp = -amp;
        arg = -11*varphi + M_PI;
      } else {
        arg = -11*varphi;
      }
      return;
    case -10:
      amp = 59.4494277098981063*Power(Cos(0.5*vartheta),8)*(67. + 46.*Cos(vartheta) + 69.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),12);
      if(amp<0) {
        amp = -amp;
        arg = -10*varphi + M_PI;
      } else {
        arg = -10*varphi;
      }
      return;
    case -9:
      amp = 10.9765780420191242*Power(Cos(0.5*vartheta),7)*(235. + 715.*Cos(vartheta) + 253.*Cos(2.*vartheta) + 253.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),11);
      if(amp<0) {
        amp = -amp;
        arg = -9*varphi + M_PI;
      } else {
        arg = -9*varphi;
      }
      return;
    case -8:
      amp = 2.09587498954761674*Power(Cos(0.5*vartheta),6)*(2005. + 2604.*Cos(vartheta) + 2772.*Cos(2.*vartheta) + 1012.*Cos(3.*vartheta) + 759.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),10);
      if(amp<0) {
        amp = -amp;
        arg = -8*varphi + M_PI;
      } else {
        arg = -8*varphi;
      }
      return;
    case -7:
      amp = 1.04793749477380837*Power(Cos(0.5*vartheta),5)*(2755. + 6190.*Cos(vartheta) + 3980.*Cos(2.*vartheta) + 3355.*Cos(3.*vartheta) + 1265.*Cos(4.*vartheta) + 759.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = -7*varphi + M_PI;
      } else {
        arg = -7*varphi;
      }
      return;
    case -6:
      amp = 0.0736112541772210869*Power(Cos(0.5*vartheta),4)*(34170. + 58140.*Cos(vartheta) + 53865.*Cos(2.*vartheta) + 34390.*Cos(3.*vartheta) + 24662.*Cos(4.*vartheta) + 9614.*Cos(5.*vartheta) + 4807.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = -6*varphi + M_PI;
      } else {
        arg = -6*varphi;
      }
      return;
    case -5:
      amp = 0.00983671760506762245*Power(Cos(0.5*vartheta),3)*(152150. + 303975.*Cos(vartheta) + 249375.*Cos(2.*vartheta) + 204421.*Cos(3.*vartheta) + 130074.*Cos(4.*vartheta) + 83391.*Cos(5.*vartheta) + 33649.*Cos(6.*vartheta) + 14421.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = -5*varphi + M_PI;
      } else {
        arg = -5*varphi;
      }
      return;
    case -4:
      amp = 0.000210872893964438159*Power(Cos(0.5*vartheta),2)*(3.952975e6 + 7.4698e6*Cos(vartheta) + 6.769672e6*Cos(2.*vartheta) + 5.408312e6*Cos(3.*vartheta) + 4.11502e6*Cos(4.*vartheta) + 2.62276e6*Cos(5.*vartheta) + 1.56332e6*Cos(6.*vartheta) + 653752.*Cos(7.*vartheta) + 245157.*Cos(8.*vartheta))*Power(Sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = -4*varphi + M_PI;
      } else {
        arg = -4*varphi;
      }
      return;
    case -3:
      amp = 0.000210872893964438159*Cos(0.5*vartheta)*(1.748175e6 + 3.408834e6*Cos(vartheta) + 3.092232e6*Cos(2.*vartheta) + 2.654652e6*Cos(3.*vartheta) + 2.089164e6*Cos(4.*vartheta) + 1.53102e6*Cos(5.*vartheta) + 984504.*Cos(6.*vartheta) + 564927.*Cos(7.*vartheta) + 245157.*Cos(8.*vartheta) + 81719.*Cos(9.*vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = -3*varphi + M_PI;
      } else {
        arg = -3*varphi;
      }
      return;
    case -2:
      amp = 0.0000215221246165373339*(6.205914e6 + 1.212354e7*Cos(vartheta) + 1.131273e7*Cos(2.*vartheta) + 1.003068e7*Cos(3.*vartheta) + 8.42724e6*Cos(4.*vartheta) + 6.62796e6*Cos(5.*vartheta) + 4.830465e6*Cos(6.*vartheta) + 3.16863e6*Cos(7.*vartheta) + 1.81203e6*Cos(8.*vartheta) + 817190.*Cos(9.*vartheta) + 245157.*Cos(10.*vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = -2*varphi + M_PI;
      } else {
        arg = -2*varphi;
      }
      return;
    case -1:
      amp = 0.000267082542659574423*Cos(0.5*vartheta)*(144144. + 270270.*Cos(vartheta) + 270270.*Cos(2.*vartheta) + 235620.*Cos(3.*vartheta) + 220320.*Cos(4.*vartheta) + 174420.*Cos(5.*vartheta) + 150195.*Cos(6.*vartheta) + 101745.*Cos(7.*vartheta) + 77520.*Cos(8.*vartheta) + 37145.*Cos(9.*vartheta) + 22287.*Cos(10.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = -1*varphi + M_PI;
      } else {
        arg = -1*varphi;
      }
      return;
    case 0:
      amp = 0.000208491243039524634*(18018. + 34650.*Cos(2.*vartheta) + 30600.*Cos(4.*vartheta) + 24225.*Cos(6.*vartheta) + 16150.*Cos(8.*vartheta) + 7429.*Cos(10.*vartheta))*Power(Sin(vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 0*varphi + M_PI;
      } else {
        arg = 0*varphi;
      }
      return;
    case 1:
      amp = 0.000267082542659574423*Power(Cos(0.5*vartheta),3)*(144144. - 270270.*Cos(vartheta) + 270270.*Cos(2.*vartheta) - 235620.*Cos(3.*vartheta) + 220320.*Cos(4.*vartheta) - 174420.*Cos(5.*vartheta) + 150195.*Cos(6.*vartheta) - 101745.*Cos(7.*vartheta) + 77520.*Cos(8.*vartheta) - 37145.*Cos(9.*vartheta) + 22287.*Cos(10.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 1*varphi + M_PI;
      } else {
        arg = 1*varphi;
      }
      return;
    case 2:
      amp = 0.0000215221246165373339*Power(Cos(0.5*vartheta),4)*(6.205914e6 - 1.212354e7*Cos(vartheta) + 1.131273e7*Cos(2.*vartheta) - 1.003068e7*Cos(3.*vartheta) + 8.42724e6*Cos(4.*vartheta) - 6.62796e6*Cos(5.*vartheta) + 4.830465e6*Cos(6.*vartheta) - 3.16863e6*Cos(7.*vartheta) + 1.81203e6*Cos(8.*vartheta) - 817190.*Cos(9.*vartheta) + 245157.*Cos(10.*vartheta));
      if(amp<0) {
        amp = -amp;
        arg = 2*varphi + M_PI;
      } else {
        arg = 2*varphi;
      }
      return;
    case 3:
      amp = -0.000210872893964438159*Power(Cos(0.5*vartheta),5)*(-1.748175e6 + 3.408834e6*Cos(vartheta) - 3.092232e6*Cos(2.*vartheta) + 2.654652e6*Cos(3.*vartheta) - 2.089164e6*Cos(4.*vartheta) + 1.53102e6*Cos(5.*vartheta) - 984504.*Cos(6.*vartheta) + 564927.*Cos(7.*vartheta) - 245157.*Cos(8.*vartheta) + 81719.*Cos(9.*vartheta))*Sin(0.5*vartheta);
      if(amp<0) {
        amp = -amp;
        arg = 3*varphi + M_PI;
      } else {
        arg = 3*varphi;
      }
      return;
    case 4:
      amp = 0.000210872893964438159*Power(Cos(0.5*vartheta),6)*(3.952975e6 - 7.4698e6*Cos(vartheta) + 6.769672e6*Cos(2.*vartheta) - 5.408312e6*Cos(3.*vartheta) + 4.11502e6*Cos(4.*vartheta) - 2.62276e6*Cos(5.*vartheta) + 1.56332e6*Cos(6.*vartheta) - 653752.*Cos(7.*vartheta) + 245157.*Cos(8.*vartheta))*Power(Sin(0.5*vartheta),2);
      if(amp<0) {
        amp = -amp;
        arg = 4*varphi + M_PI;
      } else {
        arg = 4*varphi;
      }
      return;
    case 5:
      amp = -0.00983671760506762245*Power(Cos(0.5*vartheta),7)*(-152150. + 303975.*Cos(vartheta) - 249375.*Cos(2.*vartheta) + 204421.*Cos(3.*vartheta) - 130074.*Cos(4.*vartheta) + 83391.*Cos(5.*vartheta) - 33649.*Cos(6.*vartheta) + 14421.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),3);
      if(amp<0) {
        amp = -amp;
        arg = 5*varphi + M_PI;
      } else {
        arg = 5*varphi;
      }
      return;
    case 6:
      amp = 0.0736112541772210869*Power(Cos(0.5*vartheta),8)*(34170. - 58140.*Cos(vartheta) + 53865.*Cos(2.*vartheta) - 34390.*Cos(3.*vartheta) + 24662.*Cos(4.*vartheta) - 9614.*Cos(5.*vartheta) + 4807.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),4);
      if(amp<0) {
        amp = -amp;
        arg = 6*varphi + M_PI;
      } else {
        arg = 6*varphi;
      }
      return;
    case 7:
      amp = -1.04793749477380837*Power(Cos(0.5*vartheta),9)*(-2755. + 6190.*Cos(vartheta) - 3980.*Cos(2.*vartheta) + 3355.*Cos(3.*vartheta) - 1265.*Cos(4.*vartheta) + 759.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),5);
      if(amp<0) {
        amp = -amp;
        arg = 7*varphi + M_PI;
      } else {
        arg = 7*varphi;
      }
      return;
    case 8:
      amp = 2.09587498954761674*Power(Cos(0.5*vartheta),10)*(2005. - 2604.*Cos(vartheta) + 2772.*Cos(2.*vartheta) - 1012.*Cos(3.*vartheta) + 759.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),6);
      if(amp<0) {
        amp = -amp;
        arg = 8*varphi + M_PI;
      } else {
        arg = 8*varphi;
      }
      return;
    case 9:
      amp = -10.9765780420191242*Power(Cos(0.5*vartheta),11)*(-235. + 715.*Cos(vartheta) - 253.*Cos(2.*vartheta) + 253.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),7);
      if(amp<0) {
        amp = -amp;
        arg = 9*varphi + M_PI;
      } else {
        arg = 9*varphi;
      }
      return;
    case 10:
      amp = 59.4494277098981063*Power(Cos(0.5*vartheta),12)*(67. - 46.*Cos(vartheta) + 69.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),8);
      if(amp<0) {
        amp = -amp;
        arg = 10*varphi + M_PI;
      } else {
        arg = 10*varphi;
      }
      return;
    case 11:
      amp = -806.411272072960143*Power(Cos(0.5*vartheta),13)*(-1. + 6.*Cos(vartheta))*Power(Sin(0.5*vartheta),9);
      if(amp<0) {
        amp = -amp;
        arg = 11*varphi + M_PI;
      } else {
        arg = 11*varphi;
      }
      return;
    case 12:
      amp = 1975.29613940745059*Power(Cos(0.5*vartheta),14)*Power(Sin(0.5*vartheta),10);
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
  if(L<2) { Throw1WithMessage("l<2 unsupported."); }
  if(labs(M)>L) { Throw1WithMessage("abs(m)>l unsupported for s=-2 spin-weighted spherical harmonics."); }
  if(vartheta.size() != varphi.size()) {
    std::cerr << "\n\nvartheta.size()=" << vartheta.size() << "  varphi.size()=" << varphi.size() << std::endl;
    Throw1WithMessage("Size mismatch in input data");
  }
  if(L>12) { Throw1WithMessage("l>12 unsupported."); }
  
  amp.resize(vartheta.size());
  arg.resize(vartheta.size());
  
  switch(L) {
  case 2:
    switch(M) {
    case -2:
      amp = 0.630783130505040012*Power(Sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 1.26156626101008002*Cos(0.5*vartheta)*Power(Sin(0.5*vartheta),3);
      arg = -1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.38627420202318958*Power(Sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 1.26156626101008002*Power(Cos(0.5*vartheta),3)*Sin(0.5*vartheta);
      arg = 1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.630783130505040012*Power(Cos(0.5*vartheta),4);
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
      amp = 1.82818319785786294*Cos(0.5*vartheta)*Power(Sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.746352665180230783*(2. + 3.*Cos(vartheta))*Power(Sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 1.18008717985328702*Cos(0.5*vartheta)*(1. + 3.*Cos(vartheta))*Power(Sin(0.5*vartheta),3);
      arg = -1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 1.02198547643328236*Cos(vartheta)*Power(Sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 1.18008717985328702*Power(Cos(0.5*vartheta),3)*(-1. + 3.*Cos(vartheta))*Sin(0.5*vartheta);
      arg = 1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.746352665180230783*Power(Cos(0.5*vartheta),4)*(-2. + 3.*Cos(vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -1.82818319785786294*Power(Cos(0.5*vartheta),5)*Sin(0.5*vartheta);
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
      amp = 4.4781159910813847*Power(Cos(0.5*vartheta),2)*Power(Sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 3.16650618423356409*Cos(0.5*vartheta)*(1. + 2.*Cos(vartheta))*Power(Sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.423142187660817215*(9. + 14.*Cos(vartheta) + 7.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.598413420602149017*Cos(0.5*vartheta)*(6. + 7.*Cos(vartheta) + 7.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = -1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.167261635889322292*(5. + 7.*Cos(2.*vartheta))*Power(Sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.598413420602149017*Power(Cos(0.5*vartheta),3)*(6. - 7.*Cos(vartheta) + 7.*Cos(2.*vartheta))*Sin(0.5*vartheta);
      arg = 1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.423142187660817215*Power(Cos(0.5*vartheta),4)*(9. - 14.*Cos(vartheta) + 7.*Cos(2.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -3.16650618423356409*Power(Cos(0.5*vartheta),5)*(-1. + 2.*Cos(vartheta))*Sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 4.4781159910813847*Power(Cos(0.5*vartheta),6)*Power(Sin(0.5*vartheta),2);
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
      amp = 10.2490127544388841*Power(Cos(0.5*vartheta),3)*Power(Sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 3.24102240721428709*Power(Cos(0.5*vartheta),2)*(2. + 5.*Cos(vartheta))*Power(Sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.572937230529692607*Cos(0.5*vartheta)*(17. + 24.*Cos(vartheta) + 15.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.233900644906847193*(32. + 57.*Cos(vartheta) + 36.*Cos(2.*vartheta) + 15.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.309421468960572107*Cos(0.5*vartheta)*(14. + 33.*Cos(vartheta) + 18.*Cos(2.*vartheta) + 15.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = -1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.847385591630449638*Cos(vartheta)*(1. + 3.*Cos(2.*vartheta))*Power(Sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.309421468960572107*Power(Cos(0.5*vartheta),3)*(-14. + 33.*Cos(vartheta) - 18.*Cos(2.*vartheta) + 15.*Cos(3.*vartheta))*Sin(0.5*vartheta);
      arg = 1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.233900644906847193*Power(Cos(0.5*vartheta),4)*(-32. + 57.*Cos(vartheta) - 36.*Cos(2.*vartheta) + 15.*Cos(3.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.572937230529692607*Power(Cos(0.5*vartheta),5)*(17. - 24.*Cos(vartheta) + 15.*Cos(2.*vartheta))*Sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 3.24102240721428709*Power(Cos(0.5*vartheta),6)*(-2. + 5.*Cos(vartheta))*Power(Sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -10.2490127544388841*Power(Cos(0.5*vartheta),7)*Power(Sin(0.5*vartheta),3);
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
      amp = 22.6292074407870777*Power(Cos(0.5*vartheta),4)*Power(Sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 13.0649790074863016*Power(Cos(0.5*vartheta),3)*(1. + 3.*Cos(vartheta))*Power(Sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.696365720891772932*Power(Cos(0.5*vartheta),2)*(35. + 44.*Cos(vartheta) + 33.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.190707606802885278*Cos(0.5*vartheta)*(98. + 185.*Cos(vartheta) + 110.*Cos(2.*vartheta) + 55.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.00794615028345355324*(1709. + 3096.*Cos(vartheta) + 2340.*Cos(2.*vartheta) + 1320.*Cos(3.*vartheta) + 495.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.0502558670514116131*Cos(0.5*vartheta)*(161. + 252.*Cos(vartheta) + 252.*Cos(2.*vartheta) + 132.*Cos(3.*vartheta) + 99.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = -1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.0407119053667322336*(35. + 60.*Cos(2.*vartheta) + 33.*Cos(4.*vartheta))*Power(Sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.0502558670514116131*Power(Cos(0.5*vartheta),3)*(161. - 252.*Cos(vartheta) + 252.*Cos(2.*vartheta) - 132.*Cos(3.*vartheta) + 99.*Cos(4.*vartheta))*Sin(0.5*vartheta);
      arg = 1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.00794615028345355324*Power(Cos(0.5*vartheta),4)*(1709. - 3096.*Cos(vartheta) + 2340.*Cos(2.*vartheta) - 1320.*Cos(3.*vartheta) + 495.*Cos(4.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.190707606802885278*Power(Cos(0.5*vartheta),5)*(-98. + 185.*Cos(vartheta) - 110.*Cos(2.*vartheta) + 55.*Cos(3.*vartheta))*Sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.696365720891772932*Power(Cos(0.5*vartheta),6)*(35. - 44.*Cos(vartheta) + 33.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -13.0649790074863016*Power(Cos(0.5*vartheta),7)*(-1. + 3.*Cos(vartheta))*Power(Sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 22.6292074407870777*Power(Cos(0.5*vartheta),8)*Power(Sin(0.5*vartheta),4);
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
      amp = 48.8846752114075978*Power(Cos(0.5*vartheta),5)*Power(Sin(0.5*vartheta),9);
      arg = -7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -6:
      amp = 13.0649790074863016*Power(Cos(0.5*vartheta),4)*(2. + 7.*Cos(vartheta))*Power(Sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 0.640563297152430255*Power(Cos(0.5*vartheta),3)*(93. + 104.*Cos(vartheta) + 91.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.320281648576215128*Power(Cos(0.5*vartheta),2)*(140. + 285.*Cos(vartheta) + 156.*Cos(2.*vartheta) + 91.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.0120710688132246744*Cos(0.5*vartheta)*(3115. + 5456.*Cos(vartheta) + 4268.*Cos(2.*vartheta) + 2288.*Cos(3.*vartheta) + 1001.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.00426776730700030887*(5220. + 9810.*Cos(vartheta) + 7920.*Cos(2.*vartheta) + 5445.*Cos(3.*vartheta) + 2860.*Cos(4.*vartheta) + 1001.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.00522692612154132162*Cos(0.5*vartheta)*(1890. + 4130.*Cos(vartheta) + 3080.*Cos(2.*vartheta) + 2805.*Cos(3.*vartheta) + 1430.*Cos(4.*vartheta) + 1001.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = -1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.0195573667327867542*Cos(vartheta)*(109. + 132.*Cos(2.*vartheta) + 143.*Cos(4.*vartheta))*Power(Sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.00522692612154132162*Power(Cos(0.5*vartheta),3)*(-1890. + 4130.*Cos(vartheta) - 3080.*Cos(2.*vartheta) + 2805.*Cos(3.*vartheta) - 1430.*Cos(4.*vartheta) + 1001.*Cos(5.*vartheta))*Sin(0.5*vartheta);
      arg = 1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.00426776730700030887*Power(Cos(0.5*vartheta),4)*(-5220. + 9810.*Cos(vartheta) - 7920.*Cos(2.*vartheta) + 5445.*Cos(3.*vartheta) - 2860.*Cos(4.*vartheta) + 1001.*Cos(5.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.0120710688132246744*Power(Cos(0.5*vartheta),5)*(3115. - 5456.*Cos(vartheta) + 4268.*Cos(2.*vartheta) - 2288.*Cos(3.*vartheta) + 1001.*Cos(4.*vartheta))*Sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.320281648576215128*Power(Cos(0.5*vartheta),6)*(-140. + 285.*Cos(vartheta) - 156.*Cos(2.*vartheta) + 91.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -0.640563297152430255*Power(Cos(0.5*vartheta),7)*(93. - 104.*Cos(vartheta) + 91.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 13.0649790074863016*Power(Cos(0.5*vartheta),8)*(-2. + 7.*Cos(vartheta))*Power(Sin(0.5*vartheta),4);
      arg = 6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 7:
      amp = -48.8846752114075978*Power(Cos(0.5*vartheta),9)*Power(Sin(0.5*vartheta),5);
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
      amp = 104.083421669251111*Power(Cos(0.5*vartheta),6)*Power(Sin(0.5*vartheta),10);
      arg = -8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -7:
      amp = 52.0417108346255555*Power(Cos(0.5*vartheta),5)*(1. + 4.*Cos(vartheta))*Power(Sin(0.5*vartheta),9);
      arg = -7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -6:
      amp = 285.044189552854222*Power(Cos(0.5*vartheta),4)*(1. + 2.*Cos(vartheta))*Sin(0.78539816339744831 - 0.5*vartheta)*Sin(0.78539816339744831 + 0.5*vartheta)*Power(Sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 5.49790916690436597*Power(Cos(0.5*vartheta),3)*(19. + 42.*Cos(vartheta) + 21.*Cos(2.*vartheta) + 14.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.381211411713792221*Power(Cos(0.5*vartheta),2)*(265. + 442.*Cos(vartheta) + 364.*Cos(2.*vartheta) + 182.*Cos(3.*vartheta) + 91.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.0738212724475868138*Cos(0.5*vartheta)*(869. + 1660.*Cos(vartheta) + 1300.*Cos(2.*vartheta) + 910.*Cos(3.*vartheta) + 455.*Cos(4.*vartheta) + 182.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.00454338524578249815*(7626. + 14454.*Cos(vartheta) + 12375.*Cos(2.*vartheta) + 9295.*Cos(3.*vartheta) + 6006.*Cos(4.*vartheta) + 3003.*Cos(5.*vartheta) + 1001.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.0190063441014545613*Cos(0.5*vartheta)*(798. + 1386.*Cos(vartheta) + 1386.*Cos(2.*vartheta) + 1001.*Cos(3.*vartheta) + 858.*Cos(4.*vartheta) + 429.*Cos(5.*vartheta) + 286.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = -1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.010079636099777594*(210. + 385.*Cos(2.*vartheta) + 286.*Cos(4.*vartheta) + 143.*Cos(6.*vartheta))*Power(Sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.0190063441014545613*Power(Cos(0.5*vartheta),3)*(798. - 1386.*Cos(vartheta) + 1386.*Cos(2.*vartheta) - 1001.*Cos(3.*vartheta) + 858.*Cos(4.*vartheta) - 429.*Cos(5.*vartheta) + 286.*Cos(6.*vartheta))*Sin(0.5*vartheta);
      arg = 1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.00454338524578249815*Power(Cos(0.5*vartheta),4)*(7626. - 14454.*Cos(vartheta) + 12375.*Cos(2.*vartheta) - 9295.*Cos(3.*vartheta) + 6006.*Cos(4.*vartheta) - 3003.*Cos(5.*vartheta) + 1001.*Cos(6.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.0738212724475868138*Power(Cos(0.5*vartheta),5)*(-869. + 1660.*Cos(vartheta) - 1300.*Cos(2.*vartheta) + 910.*Cos(3.*vartheta) - 455.*Cos(4.*vartheta) + 182.*Cos(5.*vartheta))*Sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.381211411713792221*Power(Cos(0.5*vartheta),6)*(265. - 442.*Cos(vartheta) + 364.*Cos(2.*vartheta) - 182.*Cos(3.*vartheta) + 91.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -5.49790916690436597*Power(Cos(0.5*vartheta),7)*(-19. + 42.*Cos(vartheta) - 21.*Cos(2.*vartheta) + 14.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 285.044189552854222*Power(Cos(0.5*vartheta),8)*(-1. + 2.*Cos(vartheta))*Sin(0.78539816339744831 - 0.5*vartheta)*Sin(0.78539816339744831 + 0.5*vartheta)*Power(Sin(0.5*vartheta),4);
      arg = 6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 7:
      amp = -52.0417108346255555*Power(Cos(0.5*vartheta),9)*(-1. + 4.*Cos(vartheta))*Power(Sin(0.5*vartheta),5);
      arg = 7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 8:
      amp = 104.083421669251111*Power(Cos(0.5*vartheta),10)*Power(Sin(0.5*vartheta),6);
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
      amp = 219.355865285354367*Power(Cos(0.5*vartheta),7)*Power(Sin(0.5*vartheta),11);
      arg = -9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -8:
      amp = 51.7026732787722888*Power(Cos(0.5*vartheta),6)*(2. + 9.*Cos(vartheta))*Power(Sin(0.5*vartheta),10);
      arg = -8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -7:
      amp = 2.21673382884871148*Power(Cos(0.5*vartheta),5)*(151. + 136.*Cos(vartheta) + 153.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),9);
      arg = -7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -6:
      amp = 3.83949561842266015*Power(Cos(0.5*vartheta),4)*(62. + 149.*Cos(vartheta) + 68.*Cos(2.*vartheta) + 51.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 0.619595941166137906*Power(Cos(0.5*vartheta),3)*(427. + 672.*Cos(vartheta) + 588.*Cos(2.*vartheta) + 272.*Cos(3.*vartheta) + 153.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.259195578288233226*Power(Cos(0.5*vartheta),2)*(676. + 1330.*Cos(vartheta) + 1000.*Cos(2.*vartheta) + 725.*Cos(3.*vartheta) + 340.*Cos(4.*vartheta) + 153.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.022011090048569557*Cos(0.5*vartheta)*(4906. + 9152.*Cos(vartheta) + 7865.*Cos(2.*vartheta) + 5720.*Cos(3.*vartheta) + 3718.*Cos(4.*vartheta) + 1768.*Cos(5.*vartheta) + 663.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.00240160681609664791*(21252. + 40887.*Cos(vartheta) + 36036.*Cos(2.*vartheta) + 29029.*Cos(3.*vartheta) + 20748.*Cos(4.*vartheta) + 12831.*Cos(5.*vartheta) + 6188.*Cos(6.*vartheta) + 1989.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.00281613361477977156*Cos(0.5*vartheta)*(6468. + 13671.*Cos(vartheta) + 11466.*Cos(2.*vartheta) + 10829.*Cos(3.*vartheta) + 7644.*Cos(4.*vartheta) + 6279.*Cos(5.*vartheta) + 3094.*Cos(6.*vartheta) + 1989.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = -1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.0133580946271009442*Cos(vartheta)*(166. + 403.*Cos(2.*vartheta) + 234.*Cos(4.*vartheta) + 221.*Cos(6.*vartheta))*Power(Sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.00281613361477977156*Power(Cos(0.5*vartheta),3)*(-6468. + 13671.*Cos(vartheta) - 11466.*Cos(2.*vartheta) + 10829.*Cos(3.*vartheta) - 7644.*Cos(4.*vartheta) + 6279.*Cos(5.*vartheta) - 3094.*Cos(6.*vartheta) + 1989.*Cos(7.*vartheta))*Sin(0.5*vartheta);
      arg = 1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.00240160681609664791*Power(Cos(0.5*vartheta),4)*(-21252. + 40887.*Cos(vartheta) - 36036.*Cos(2.*vartheta) + 29029.*Cos(3.*vartheta) - 20748.*Cos(4.*vartheta) + 12831.*Cos(5.*vartheta) - 6188.*Cos(6.*vartheta) + 1989.*Cos(7.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.022011090048569557*Power(Cos(0.5*vartheta),5)*(4906. - 9152.*Cos(vartheta) + 7865.*Cos(2.*vartheta) - 5720.*Cos(3.*vartheta) + 3718.*Cos(4.*vartheta) - 1768.*Cos(5.*vartheta) + 663.*Cos(6.*vartheta))*Sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.259195578288233226*Power(Cos(0.5*vartheta),6)*(-676. + 1330.*Cos(vartheta) - 1000.*Cos(2.*vartheta) + 725.*Cos(3.*vartheta) - 340.*Cos(4.*vartheta) + 153.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -0.619595941166137906*Power(Cos(0.5*vartheta),7)*(427. - 672.*Cos(vartheta) + 588.*Cos(2.*vartheta) - 272.*Cos(3.*vartheta) + 153.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 3.83949561842266015*Power(Cos(0.5*vartheta),8)*(-62. + 149.*Cos(vartheta) - 68.*Cos(2.*vartheta) + 51.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),4);
      arg = 6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 7:
      amp = -2.21673382884871148*Power(Cos(0.5*vartheta),9)*(151. - 136.*Cos(vartheta) + 153.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),5);
      arg = 7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 8:
      amp = 51.7026732787722888*Power(Cos(0.5*vartheta),10)*(-2. + 9.*Cos(vartheta))*Power(Sin(0.5*vartheta),6);
      arg = 8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 9:
      amp = -219.355865285354367*Power(Cos(0.5*vartheta),11)*Power(Sin(0.5*vartheta),7);
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
      amp = 458.815710175124215*Power(Cos(0.5*vartheta),8)*Power(Sin(0.5*vartheta),12);
      arg = -10*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -9:
      amp = 205.188623419283937*Power(Cos(0.5*vartheta),7)*(1. + 5.*Cos(vartheta))*Power(Sin(0.5*vartheta),11);
      arg = -9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -8:
      amp = 8.32149752273527606*Power(Cos(0.5*vartheta),6)*(93. + 76.*Cos(vartheta) + 95.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),10);
      arg = -8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -7:
      amp = 1.69861856887797376*Power(Cos(0.5*vartheta),5)*(314. + 819.*Cos(vartheta) + 342.*Cos(2.*vartheta) + 285.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),9);
      arg = -7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -6:
      amp = 0.0514969395376425972*Power(Cos(0.5*vartheta),4)*(13159. + 19448.*Cos(vartheta) + 18156.*Cos(2.*vartheta) + 7752.*Cos(3.*vartheta) + 4845.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 0.115150657439365437*Power(Cos(0.5*vartheta),3)*(3990. + 8162.*Cos(vartheta) + 5848.*Cos(2.*vartheta) + 4437.*Cos(3.*vartheta) + 1938.*Cos(4.*vartheta) + 969.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.00910345878935517795*Power(Cos(0.5*vartheta),2)*(35126. + 63960.*Cos(vartheta) + 55875.*Cos(2.*vartheta) + 39100.*Cos(3.*vartheta) + 26010.*Cos(4.*vartheta) + 11628.*Cos(5.*vartheta) + 4845.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.00321855872110266232*Cos(0.5*vartheta)*(52052. + 100639.*Cos(vartheta) + 87010.*Cos(2.*vartheta) + 69685.*Cos(3.*vartheta) + 48076.*Cos(4.*vartheta) + 29631.*Cos(5.*vartheta) + 13566.*Cos(6.*vartheta) + 4845.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.0000789014121372438118*(919611. + 1.777776e6*Cos(vartheta) + 1.609608e6*Cos(2.*vartheta) + 1.349712e6*Cos(3.*vartheta) + 1.041404e6*Cos(4.*vartheta) + 717808.*Cos(5.*vartheta) + 429624.*Cos(6.*vartheta) + 201552.*Cos(7.*vartheta) + 62985.*Cos(8.*vartheta))*Power(Sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.000273322509221275921*Cos(0.5*vartheta)*(92169. + 168168.*Cos(vartheta) + 168168.*Cos(2.*vartheta) + 137592.*Cos(3.*vartheta) + 124852.*Cos(4.*vartheta) + 86632.*Cos(5.*vartheta) + 68952.*Cos(6.*vartheta) + 33592.*Cos(7.*vartheta) + 20995.*Cos(8.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = -1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.00035832883259417753*(8085. + 15288.*Cos(2.*vartheta) + 12740.*Cos(4.*vartheta) + 8840.*Cos(6.*vartheta) + 4199.*Cos(8.*vartheta))*Power(Sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.000273322509221275921*Power(Cos(0.5*vartheta),3)*(92169. - 168168.*Cos(vartheta) + 168168.*Cos(2.*vartheta) - 137592.*Cos(3.*vartheta) + 124852.*Cos(4.*vartheta) - 86632.*Cos(5.*vartheta) + 68952.*Cos(6.*vartheta) - 33592.*Cos(7.*vartheta) + 20995.*Cos(8.*vartheta))*Sin(0.5*vartheta);
      arg = 1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.0000789014121372438118*Power(Cos(0.5*vartheta),4)*(919611. - 1.777776e6*Cos(vartheta) + 1.609608e6*Cos(2.*vartheta) - 1.349712e6*Cos(3.*vartheta) + 1.041404e6*Cos(4.*vartheta) - 717808.*Cos(5.*vartheta) + 429624.*Cos(6.*vartheta) - 201552.*Cos(7.*vartheta) + 62985.*Cos(8.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.00321855872110266232*Power(Cos(0.5*vartheta),5)*(-52052. + 100639.*Cos(vartheta) - 87010.*Cos(2.*vartheta) + 69685.*Cos(3.*vartheta) - 48076.*Cos(4.*vartheta) + 29631.*Cos(5.*vartheta) - 13566.*Cos(6.*vartheta) + 4845.*Cos(7.*vartheta))*Sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.00910345878935517795*Power(Cos(0.5*vartheta),6)*(35126. - 63960.*Cos(vartheta) + 55875.*Cos(2.*vartheta) - 39100.*Cos(3.*vartheta) + 26010.*Cos(4.*vartheta) - 11628.*Cos(5.*vartheta) + 4845.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -0.115150657439365437*Power(Cos(0.5*vartheta),7)*(-3990. + 8162.*Cos(vartheta) - 5848.*Cos(2.*vartheta) + 4437.*Cos(3.*vartheta) - 1938.*Cos(4.*vartheta) + 969.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 0.0514969395376425972*Power(Cos(0.5*vartheta),8)*(13159. - 19448.*Cos(vartheta) + 18156.*Cos(2.*vartheta) - 7752.*Cos(3.*vartheta) + 4845.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),4);
      arg = 6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 7:
      amp = -1.69861856887797376*Power(Cos(0.5*vartheta),9)*(-314. + 819.*Cos(vartheta) - 342.*Cos(2.*vartheta) + 285.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),5);
      arg = 7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 8:
      amp = 8.32149752273527606*Power(Cos(0.5*vartheta),10)*(93. - 76.*Cos(vartheta) + 95.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),6);
      arg = 8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 9:
      amp = -205.188623419283937*Power(Cos(0.5*vartheta),11)*(-1. + 5.*Cos(vartheta))*Power(Sin(0.5*vartheta),7);
      arg = 9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 10:
      amp = 458.815710175124215*Power(Cos(0.5*vartheta),12)*Power(Sin(0.5*vartheta),8);
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
      amp = 954.1586847148967*Power(Cos(0.5*vartheta),9)*Power(Sin(0.5*vartheta),13);
      arg = -11*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -10:
      amp = 203.427315098143017*Power(Cos(0.5*vartheta),8)*(2. + 11.*Cos(vartheta))*Power(Sin(0.5*vartheta),12);
      arg = -10*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -9:
      amp = 23.542137145078129*Power(Cos(0.5*vartheta),7)*(75. + 56.*Cos(vartheta) + 77.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),11);
      arg = -9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -8:
      amp = 3.03927683656728721*Power(Cos(0.5*vartheta),6)*(388. + 1095.*Cos(vartheta) + 420.*Cos(2.*vartheta) + 385.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),10);
      arg = -8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -7:
      amp = 0.0871572407371104511*Power(Cos(0.5*vartheta),5)*(19529. + 27056.*Cos(vartheta) + 26980.*Cos(2.*vartheta) + 10640.*Cos(3.*vartheta) + 7315.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),9);
      arg = -7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -6:
      amp = 0.206711546478661343*Power(Cos(0.5*vartheta),4)*(5644. + 12078.*Cos(vartheta) + 8208.*Cos(2.*vartheta) + 6555.*Cos(3.*vartheta) + 2660.*Cos(4.*vartheta) + 1463.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 0.00511687324626887852*Power(Cos(0.5*vartheta),3)*(178010. + 314160.*Cos(vartheta) + 281673.*Cos(2.*vartheta) + 188632.*Cos(3.*vartheta) + 129846.*Cos(4.*vartheta) + 54264.*Cos(5.*vartheta) + 24871.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.0135379740998672131*Power(Cos(0.5*vartheta),2)*(37960. + 74347.*Cos(vartheta) + 62764.*Cos(2.*vartheta) + 50609.*Cos(3.*vartheta) + 33592.*Cos(4.*vartheta) + 20995.*Cos(5.*vartheta) + 9044.*Cos(6.*vartheta) + 3553.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.000926881724677246133*Cos(0.5*vartheta)*(274703. + 526240.*Cos(vartheta) + 474760.*Cos(2.*vartheta) + 388960.*Cos(3.*vartheta) + 296140.*Cos(4.*vartheta) + 196384.*Cos(5.*vartheta) + 116280.*Cos(6.*vartheta) + 51680.*Cos(7.*vartheta) + 17765.*Cos(8.*vartheta))*Power(Sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.0000412865934738617689*(2.414412e6 + 4.702698e6*Cos(vartheta) + 4.32432e6*Cos(2.*vartheta) + 3.75102e6*Cos(3.*vartheta) + 3.033072e6*Cos(4.*vartheta) + 2.266236e6*Cos(5.*vartheta) + 1.519392e6*Cos(6.*vartheta) + 886635.*Cos(7.*vartheta) + 406980.*Cos(8.*vartheta) + 124355.*Cos(9.*vartheta))*Power(Sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.000235369796324778191*Cos(0.5*vartheta)*(126126. + 261954.*Cos(vartheta) + 232848.*Cos(2.*vartheta) + 224028.*Cos(3.*vartheta) + 179928.*Cos(4.*vartheta) + 158508.*Cos(5.*vartheta) + 108528.*Cos(6.*vartheta) + 84303.*Cos(7.*vartheta) + 40698.*Cos(8.*vartheta) + 24871.*Cos(9.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = -1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.00135209654009058458*Cos(vartheta)*(2719. + 4264.*Cos(2.*vartheta) + 4556.*Cos(4.*vartheta) + 2584.*Cos(6.*vartheta) + 2261.*Cos(8.*vartheta))*Power(Sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.000235369796324778191*Power(Cos(0.5*vartheta),3)*(-126126. + 261954.*Cos(vartheta) - 232848.*Cos(2.*vartheta) + 224028.*Cos(3.*vartheta) - 179928.*Cos(4.*vartheta) + 158508.*Cos(5.*vartheta) - 108528.*Cos(6.*vartheta) + 84303.*Cos(7.*vartheta) - 40698.*Cos(8.*vartheta) + 24871.*Cos(9.*vartheta))*Sin(0.5*vartheta);
      arg = 1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.0000412865934738617689*Power(Cos(0.5*vartheta),4)*(-2.414412e6 + 4.702698e6*Cos(vartheta) - 4.32432e6*Cos(2.*vartheta) + 3.75102e6*Cos(3.*vartheta) - 3.033072e6*Cos(4.*vartheta) + 2.266236e6*Cos(5.*vartheta) - 1.519392e6*Cos(6.*vartheta) + 886635.*Cos(7.*vartheta) - 406980.*Cos(8.*vartheta) + 124355.*Cos(9.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.000926881724677246133*Power(Cos(0.5*vartheta),5)*(274703. - 526240.*Cos(vartheta) + 474760.*Cos(2.*vartheta) - 388960.*Cos(3.*vartheta) + 296140.*Cos(4.*vartheta) - 196384.*Cos(5.*vartheta) + 116280.*Cos(6.*vartheta) - 51680.*Cos(7.*vartheta) + 17765.*Cos(8.*vartheta))*Sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.0135379740998672131*Power(Cos(0.5*vartheta),6)*(-37960. + 74347.*Cos(vartheta) - 62764.*Cos(2.*vartheta) + 50609.*Cos(3.*vartheta) - 33592.*Cos(4.*vartheta) + 20995.*Cos(5.*vartheta) - 9044.*Cos(6.*vartheta) + 3553.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -0.00511687324626887852*Power(Cos(0.5*vartheta),7)*(178010. - 314160.*Cos(vartheta) + 281673.*Cos(2.*vartheta) - 188632.*Cos(3.*vartheta) + 129846.*Cos(4.*vartheta) - 54264.*Cos(5.*vartheta) + 24871.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 0.206711546478661343*Power(Cos(0.5*vartheta),8)*(-5644. + 12078.*Cos(vartheta) - 8208.*Cos(2.*vartheta) + 6555.*Cos(3.*vartheta) - 2660.*Cos(4.*vartheta) + 1463.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),4);
      arg = 6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 7:
      amp = -0.0871572407371104511*Power(Cos(0.5*vartheta),9)*(19529. - 27056.*Cos(vartheta) + 26980.*Cos(2.*vartheta) - 10640.*Cos(3.*vartheta) + 7315.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),5);
      arg = 7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 8:
      amp = 3.03927683656728721*Power(Cos(0.5*vartheta),10)*(-388. + 1095.*Cos(vartheta) - 420.*Cos(2.*vartheta) + 385.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),6);
      arg = 8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 9:
      amp = -23.542137145078129*Power(Cos(0.5*vartheta),11)*(75. - 56.*Cos(vartheta) + 77.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),7);
      arg = 9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 10:
      amp = 203.427315098143017*Power(Cos(0.5*vartheta),12)*(-2. + 11.*Cos(vartheta))*Power(Sin(0.5*vartheta),8);
      arg = 10*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 11:
      amp = -954.1586847148967*Power(Cos(0.5*vartheta),13)*Power(Sin(0.5*vartheta),9);
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
      amp = 1975.29613940745059*Power(Cos(0.5*vartheta),10)*Power(Sin(0.5*vartheta),14);
      arg = -12*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -11:
      amp = 806.411272072960143*Power(Cos(0.5*vartheta),9)*(1. + 6.*Cos(vartheta))*Power(Sin(0.5*vartheta),13);
      arg = -11*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -10:
      amp = 59.4494277098981063*Power(Cos(0.5*vartheta),8)*(67. + 46.*Cos(vartheta) + 69.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),12);
      arg = -10*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -9:
      amp = 10.9765780420191242*Power(Cos(0.5*vartheta),7)*(235. + 715.*Cos(vartheta) + 253.*Cos(2.*vartheta) + 253.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),11);
      arg = -9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -8:
      amp = 2.09587498954761674*Power(Cos(0.5*vartheta),6)*(2005. + 2604.*Cos(vartheta) + 2772.*Cos(2.*vartheta) + 1012.*Cos(3.*vartheta) + 759.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),10);
      arg = -8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -7:
      amp = 1.04793749477380837*Power(Cos(0.5*vartheta),5)*(2755. + 6190.*Cos(vartheta) + 3980.*Cos(2.*vartheta) + 3355.*Cos(3.*vartheta) + 1265.*Cos(4.*vartheta) + 759.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),9);
      arg = -7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -6:
      amp = 0.0736112541772210869*Power(Cos(0.5*vartheta),4)*(34170. + 58140.*Cos(vartheta) + 53865.*Cos(2.*vartheta) + 34390.*Cos(3.*vartheta) + 24662.*Cos(4.*vartheta) + 9614.*Cos(5.*vartheta) + 4807.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),8);
      arg = -6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -5:
      amp = 0.00983671760506762245*Power(Cos(0.5*vartheta),3)*(152150. + 303975.*Cos(vartheta) + 249375.*Cos(2.*vartheta) + 204421.*Cos(3.*vartheta) + 130074.*Cos(4.*vartheta) + 83391.*Cos(5.*vartheta) + 33649.*Cos(6.*vartheta) + 14421.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),7);
      arg = -5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -4:
      amp = 0.000210872893964438159*Power(Cos(0.5*vartheta),2)*(3.952975e6 + 7.4698e6*Cos(vartheta) + 6.769672e6*Cos(2.*vartheta) + 5.408312e6*Cos(3.*vartheta) + 4.11502e6*Cos(4.*vartheta) + 2.62276e6*Cos(5.*vartheta) + 1.56332e6*Cos(6.*vartheta) + 653752.*Cos(7.*vartheta) + 245157.*Cos(8.*vartheta))*Power(Sin(0.5*vartheta),6);
      arg = -4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -3:
      amp = 0.000210872893964438159*Cos(0.5*vartheta)*(1.748175e6 + 3.408834e6*Cos(vartheta) + 3.092232e6*Cos(2.*vartheta) + 2.654652e6*Cos(3.*vartheta) + 2.089164e6*Cos(4.*vartheta) + 1.53102e6*Cos(5.*vartheta) + 984504.*Cos(6.*vartheta) + 564927.*Cos(7.*vartheta) + 245157.*Cos(8.*vartheta) + 81719.*Cos(9.*vartheta))*Power(Sin(0.5*vartheta),5);
      arg = -3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -2:
      amp = 0.0000215221246165373339*(6.205914e6 + 1.212354e7*Cos(vartheta) + 1.131273e7*Cos(2.*vartheta) + 1.003068e7*Cos(3.*vartheta) + 8.42724e6*Cos(4.*vartheta) + 6.62796e6*Cos(5.*vartheta) + 4.830465e6*Cos(6.*vartheta) + 3.16863e6*Cos(7.*vartheta) + 1.81203e6*Cos(8.*vartheta) + 817190.*Cos(9.*vartheta) + 245157.*Cos(10.*vartheta))*Power(Sin(0.5*vartheta),4);
      arg = -2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case -1:
      amp = 0.000267082542659574423*Cos(0.5*vartheta)*(144144. + 270270.*Cos(vartheta) + 270270.*Cos(2.*vartheta) + 235620.*Cos(3.*vartheta) + 220320.*Cos(4.*vartheta) + 174420.*Cos(5.*vartheta) + 150195.*Cos(6.*vartheta) + 101745.*Cos(7.*vartheta) + 77520.*Cos(8.*vartheta) + 37145.*Cos(9.*vartheta) + 22287.*Cos(10.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = -1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 0:
      amp = 0.000208491243039524634*(18018. + 34650.*Cos(2.*vartheta) + 30600.*Cos(4.*vartheta) + 24225.*Cos(6.*vartheta) + 16150.*Cos(8.*vartheta) + 7429.*Cos(10.*vartheta))*Power(Sin(vartheta),2);
      arg = 0*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 1:
      amp = 0.000267082542659574423*Power(Cos(0.5*vartheta),3)*(144144. - 270270.*Cos(vartheta) + 270270.*Cos(2.*vartheta) - 235620.*Cos(3.*vartheta) + 220320.*Cos(4.*vartheta) - 174420.*Cos(5.*vartheta) + 150195.*Cos(6.*vartheta) - 101745.*Cos(7.*vartheta) + 77520.*Cos(8.*vartheta) - 37145.*Cos(9.*vartheta) + 22287.*Cos(10.*vartheta))*Sin(0.5*vartheta);
      arg = 1*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 2:
      amp = 0.0000215221246165373339*Power(Cos(0.5*vartheta),4)*(6.205914e6 - 1.212354e7*Cos(vartheta) + 1.131273e7*Cos(2.*vartheta) - 1.003068e7*Cos(3.*vartheta) + 8.42724e6*Cos(4.*vartheta) - 6.62796e6*Cos(5.*vartheta) + 4.830465e6*Cos(6.*vartheta) - 3.16863e6*Cos(7.*vartheta) + 1.81203e6*Cos(8.*vartheta) - 817190.*Cos(9.*vartheta) + 245157.*Cos(10.*vartheta));
      arg = 2*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 3:
      amp = -0.000210872893964438159*Power(Cos(0.5*vartheta),5)*(-1.748175e6 + 3.408834e6*Cos(vartheta) - 3.092232e6*Cos(2.*vartheta) + 2.654652e6*Cos(3.*vartheta) - 2.089164e6*Cos(4.*vartheta) + 1.53102e6*Cos(5.*vartheta) - 984504.*Cos(6.*vartheta) + 564927.*Cos(7.*vartheta) - 245157.*Cos(8.*vartheta) + 81719.*Cos(9.*vartheta))*Sin(0.5*vartheta);
      arg = 3*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 4:
      amp = 0.000210872893964438159*Power(Cos(0.5*vartheta),6)*(3.952975e6 - 7.4698e6*Cos(vartheta) + 6.769672e6*Cos(2.*vartheta) - 5.408312e6*Cos(3.*vartheta) + 4.11502e6*Cos(4.*vartheta) - 2.62276e6*Cos(5.*vartheta) + 1.56332e6*Cos(6.*vartheta) - 653752.*Cos(7.*vartheta) + 245157.*Cos(8.*vartheta))*Power(Sin(0.5*vartheta),2);
      arg = 4*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 5:
      amp = -0.00983671760506762245*Power(Cos(0.5*vartheta),7)*(-152150. + 303975.*Cos(vartheta) - 249375.*Cos(2.*vartheta) + 204421.*Cos(3.*vartheta) - 130074.*Cos(4.*vartheta) + 83391.*Cos(5.*vartheta) - 33649.*Cos(6.*vartheta) + 14421.*Cos(7.*vartheta))*Power(Sin(0.5*vartheta),3);
      arg = 5*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 6:
      amp = 0.0736112541772210869*Power(Cos(0.5*vartheta),8)*(34170. - 58140.*Cos(vartheta) + 53865.*Cos(2.*vartheta) - 34390.*Cos(3.*vartheta) + 24662.*Cos(4.*vartheta) - 9614.*Cos(5.*vartheta) + 4807.*Cos(6.*vartheta))*Power(Sin(0.5*vartheta),4);
      arg = 6*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 7:
      amp = -1.04793749477380837*Power(Cos(0.5*vartheta),9)*(-2755. + 6190.*Cos(vartheta) - 3980.*Cos(2.*vartheta) + 3355.*Cos(3.*vartheta) - 1265.*Cos(4.*vartheta) + 759.*Cos(5.*vartheta))*Power(Sin(0.5*vartheta),5);
      arg = 7*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 8:
      amp = 2.09587498954761674*Power(Cos(0.5*vartheta),10)*(2005. - 2604.*Cos(vartheta) + 2772.*Cos(2.*vartheta) - 1012.*Cos(3.*vartheta) + 759.*Cos(4.*vartheta))*Power(Sin(0.5*vartheta),6);
      arg = 8*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 9:
      amp = -10.9765780420191242*Power(Cos(0.5*vartheta),11)*(-235. + 715.*Cos(vartheta) - 253.*Cos(2.*vartheta) + 253.*Cos(3.*vartheta))*Power(Sin(0.5*vartheta),7);
      arg = 9*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 10:
      amp = 59.4494277098981063*Power(Cos(0.5*vartheta),12)*(67. - 46.*Cos(vartheta) + 69.*Cos(2.*vartheta))*Power(Sin(0.5*vartheta),8);
      arg = 10*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 11:
      amp = -806.411272072960143*Power(Cos(0.5*vartheta),13)*(-1. + 6.*Cos(vartheta))*Power(Sin(0.5*vartheta),9);
      arg = 11*varphi;
      for(unsigned int i=0; i<amp.size(); ++i) {
        if(amp[i]<0) {
          amp[i] *= -1.0;
          arg[i] += M_PI;
        }
      }
      return;
    case 12:
      amp = 1975.29613940745059*Power(Cos(0.5*vartheta),14)*Power(Sin(0.5*vartheta),10);
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
  if(L<2) { Throw1WithMessage("l<2 unsupported."); }
  if(labs(M)>L) { Throw1WithMessage("abs(m)>l unsupported for s=-2 spin-weighted spherical harmonics."); }
  if(vartheta.size() != varphi.size()) {
    std::cerr << "\n\nvartheta.size()=" << vartheta.size() << "  varphi.size()=" << varphi.size() << std::endl;
    Throw1WithMessage("Size mismatch in input data");
  }
  if(L>12) { Throw1WithMessage("l>12 unsupported."); }
  
  vector<complex<double> > swsh(vartheta.size());
  
  switch(L) {
  case 2:
    switch(M) {
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.630783130505040012*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -1*varphi[i];
        swsh[i] = 1.26156626101008002*Cos(0.5*vartheta[i])*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.38627420202318958*Power(Sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 1*varphi[i];
        swsh[i] = 1.26156626101008002*Power(Cos(0.5*vartheta[i]),3)*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.630783130505040012*Power(Cos(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 3:
    switch(M) {
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 1.82818319785786294*Cos(0.5*vartheta[i])*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.746352665180230783*(2. + 3.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -1*varphi[i];
        swsh[i] = 1.18008717985328702*Cos(0.5*vartheta[i])*(1. + 3.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 1.02198547643328236*Cos(vartheta[i])*Power(Sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 1*varphi[i];
        swsh[i] = 1.18008717985328702*Power(Cos(0.5*vartheta[i]),3)*(-1. + 3.*Cos(vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.746352665180230783*Power(Cos(0.5*vartheta[i]),4)*(-2. + 3.*Cos(vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -1.82818319785786294*Power(Cos(0.5*vartheta[i]),5)*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 4:
    switch(M) {
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 4.4781159910813847*Power(Cos(0.5*vartheta[i]),2)*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 3.16650618423356409*Cos(0.5*vartheta[i])*(1. + 2.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.423142187660817215*(9. + 14.*Cos(vartheta[i]) + 7.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -1*varphi[i];
        swsh[i] = 0.598413420602149017*Cos(0.5*vartheta[i])*(6. + 7.*Cos(vartheta[i]) + 7.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.167261635889322292*(5. + 7.*Cos(2.*vartheta[i]))*Power(Sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 1*varphi[i];
        swsh[i] = 0.598413420602149017*Power(Cos(0.5*vartheta[i]),3)*(6. - 7.*Cos(vartheta[i]) + 7.*Cos(2.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.423142187660817215*Power(Cos(0.5*vartheta[i]),4)*(9. - 14.*Cos(vartheta[i]) + 7.*Cos(2.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -3.16650618423356409*Power(Cos(0.5*vartheta[i]),5)*(-1. + 2.*Cos(vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 4.4781159910813847*Power(Cos(0.5*vartheta[i]),6)*Power(Sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 5:
    switch(M) {
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 10.2490127544388841*Power(Cos(0.5*vartheta[i]),3)*Power(Sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 3.24102240721428709*Power(Cos(0.5*vartheta[i]),2)*(2. + 5.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.572937230529692607*Cos(0.5*vartheta[i])*(17. + 24.*Cos(vartheta[i]) + 15.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.233900644906847193*(32. + 57.*Cos(vartheta[i]) + 36.*Cos(2.*vartheta[i]) + 15.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -1*varphi[i];
        swsh[i] = 0.309421468960572107*Cos(0.5*vartheta[i])*(14. + 33.*Cos(vartheta[i]) + 18.*Cos(2.*vartheta[i]) + 15.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.847385591630449638*Cos(vartheta[i])*(1. + 3.*Cos(2.*vartheta[i]))*Power(Sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 1*varphi[i];
        swsh[i] = 0.309421468960572107*Power(Cos(0.5*vartheta[i]),3)*(-14. + 33.*Cos(vartheta[i]) - 18.*Cos(2.*vartheta[i]) + 15.*Cos(3.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.233900644906847193*Power(Cos(0.5*vartheta[i]),4)*(-32. + 57.*Cos(vartheta[i]) - 36.*Cos(2.*vartheta[i]) + 15.*Cos(3.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.572937230529692607*Power(Cos(0.5*vartheta[i]),5)*(17. - 24.*Cos(vartheta[i]) + 15.*Cos(2.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 3.24102240721428709*Power(Cos(0.5*vartheta[i]),6)*(-2. + 5.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -10.2490127544388841*Power(Cos(0.5*vartheta[i]),7)*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 6:
    switch(M) {
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 22.6292074407870777*Power(Cos(0.5*vartheta[i]),4)*Power(Sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 13.0649790074863016*Power(Cos(0.5*vartheta[i]),3)*(1. + 3.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.696365720891772932*Power(Cos(0.5*vartheta[i]),2)*(35. + 44.*Cos(vartheta[i]) + 33.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.190707606802885278*Cos(0.5*vartheta[i])*(98. + 185.*Cos(vartheta[i]) + 110.*Cos(2.*vartheta[i]) + 55.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.00794615028345355324*(1709. + 3096.*Cos(vartheta[i]) + 2340.*Cos(2.*vartheta[i]) + 1320.*Cos(3.*vartheta[i]) + 495.*Cos(4.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -1*varphi[i];
        swsh[i] = 0.0502558670514116131*Cos(0.5*vartheta[i])*(161. + 252.*Cos(vartheta[i]) + 252.*Cos(2.*vartheta[i]) + 132.*Cos(3.*vartheta[i]) + 99.*Cos(4.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.0407119053667322336*(35. + 60.*Cos(2.*vartheta[i]) + 33.*Cos(4.*vartheta[i]))*Power(Sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 1*varphi[i];
        swsh[i] = 0.0502558670514116131*Power(Cos(0.5*vartheta[i]),3)*(161. - 252.*Cos(vartheta[i]) + 252.*Cos(2.*vartheta[i]) - 132.*Cos(3.*vartheta[i]) + 99.*Cos(4.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.00794615028345355324*Power(Cos(0.5*vartheta[i]),4)*(1709. - 3096.*Cos(vartheta[i]) + 2340.*Cos(2.*vartheta[i]) - 1320.*Cos(3.*vartheta[i]) + 495.*Cos(4.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.190707606802885278*Power(Cos(0.5*vartheta[i]),5)*(-98. + 185.*Cos(vartheta[i]) - 110.*Cos(2.*vartheta[i]) + 55.*Cos(3.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.696365720891772932*Power(Cos(0.5*vartheta[i]),6)*(35. - 44.*Cos(vartheta[i]) + 33.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -13.0649790074863016*Power(Cos(0.5*vartheta[i]),7)*(-1. + 3.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 22.6292074407870777*Power(Cos(0.5*vartheta[i]),8)*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 7:
    switch(M) {
    case -7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -7*varphi[i];
        swsh[i] = 48.8846752114075978*Power(Cos(0.5*vartheta[i]),5)*Power(Sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 13.0649790074863016*Power(Cos(0.5*vartheta[i]),4)*(2. + 7.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 0.640563297152430255*Power(Cos(0.5*vartheta[i]),3)*(93. + 104.*Cos(vartheta[i]) + 91.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.320281648576215128*Power(Cos(0.5*vartheta[i]),2)*(140. + 285.*Cos(vartheta[i]) + 156.*Cos(2.*vartheta[i]) + 91.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.0120710688132246744*Cos(0.5*vartheta[i])*(3115. + 5456.*Cos(vartheta[i]) + 4268.*Cos(2.*vartheta[i]) + 2288.*Cos(3.*vartheta[i]) + 1001.*Cos(4.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.00426776730700030887*(5220. + 9810.*Cos(vartheta[i]) + 7920.*Cos(2.*vartheta[i]) + 5445.*Cos(3.*vartheta[i]) + 2860.*Cos(4.*vartheta[i]) + 1001.*Cos(5.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -1*varphi[i];
        swsh[i] = 0.00522692612154132162*Cos(0.5*vartheta[i])*(1890. + 4130.*Cos(vartheta[i]) + 3080.*Cos(2.*vartheta[i]) + 2805.*Cos(3.*vartheta[i]) + 1430.*Cos(4.*vartheta[i]) + 1001.*Cos(5.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.0195573667327867542*Cos(vartheta[i])*(109. + 132.*Cos(2.*vartheta[i]) + 143.*Cos(4.*vartheta[i]))*Power(Sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 1*varphi[i];
        swsh[i] = 0.00522692612154132162*Power(Cos(0.5*vartheta[i]),3)*(-1890. + 4130.*Cos(vartheta[i]) - 3080.*Cos(2.*vartheta[i]) + 2805.*Cos(3.*vartheta[i]) - 1430.*Cos(4.*vartheta[i]) + 1001.*Cos(5.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.00426776730700030887*Power(Cos(0.5*vartheta[i]),4)*(-5220. + 9810.*Cos(vartheta[i]) - 7920.*Cos(2.*vartheta[i]) + 5445.*Cos(3.*vartheta[i]) - 2860.*Cos(4.*vartheta[i]) + 1001.*Cos(5.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.0120710688132246744*Power(Cos(0.5*vartheta[i]),5)*(3115. - 5456.*Cos(vartheta[i]) + 4268.*Cos(2.*vartheta[i]) - 2288.*Cos(3.*vartheta[i]) + 1001.*Cos(4.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.320281648576215128*Power(Cos(0.5*vartheta[i]),6)*(-140. + 285.*Cos(vartheta[i]) - 156.*Cos(2.*vartheta[i]) + 91.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -0.640563297152430255*Power(Cos(0.5*vartheta[i]),7)*(93. - 104.*Cos(vartheta[i]) + 91.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 13.0649790074863016*Power(Cos(0.5*vartheta[i]),8)*(-2. + 7.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 7*varphi[i];
        swsh[i] = -48.8846752114075978*Power(Cos(0.5*vartheta[i]),9)*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 8:
    switch(M) {
    case -8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -8*varphi[i];
        swsh[i] = 104.083421669251111*Power(Cos(0.5*vartheta[i]),6)*Power(Sin(0.5*vartheta[i]),10)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -7*varphi[i];
        swsh[i] = 52.0417108346255555*Power(Cos(0.5*vartheta[i]),5)*(1. + 4.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 285.044189552854222*Power(Cos(0.5*vartheta[i]),4)*(1. + 2.*Cos(vartheta[i]))*Sin(0.78539816339744831 - 0.5*vartheta[i])*Sin(0.78539816339744831 + 0.5*vartheta[i])*Power(Sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 5.49790916690436597*Power(Cos(0.5*vartheta[i]),3)*(19. + 42.*Cos(vartheta[i]) + 21.*Cos(2.*vartheta[i]) + 14.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.381211411713792221*Power(Cos(0.5*vartheta[i]),2)*(265. + 442.*Cos(vartheta[i]) + 364.*Cos(2.*vartheta[i]) + 182.*Cos(3.*vartheta[i]) + 91.*Cos(4.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.0738212724475868138*Cos(0.5*vartheta[i])*(869. + 1660.*Cos(vartheta[i]) + 1300.*Cos(2.*vartheta[i]) + 910.*Cos(3.*vartheta[i]) + 455.*Cos(4.*vartheta[i]) + 182.*Cos(5.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.00454338524578249815*(7626. + 14454.*Cos(vartheta[i]) + 12375.*Cos(2.*vartheta[i]) + 9295.*Cos(3.*vartheta[i]) + 6006.*Cos(4.*vartheta[i]) + 3003.*Cos(5.*vartheta[i]) + 1001.*Cos(6.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -1*varphi[i];
        swsh[i] = 0.0190063441014545613*Cos(0.5*vartheta[i])*(798. + 1386.*Cos(vartheta[i]) + 1386.*Cos(2.*vartheta[i]) + 1001.*Cos(3.*vartheta[i]) + 858.*Cos(4.*vartheta[i]) + 429.*Cos(5.*vartheta[i]) + 286.*Cos(6.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.010079636099777594*(210. + 385.*Cos(2.*vartheta[i]) + 286.*Cos(4.*vartheta[i]) + 143.*Cos(6.*vartheta[i]))*Power(Sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 1*varphi[i];
        swsh[i] = 0.0190063441014545613*Power(Cos(0.5*vartheta[i]),3)*(798. - 1386.*Cos(vartheta[i]) + 1386.*Cos(2.*vartheta[i]) - 1001.*Cos(3.*vartheta[i]) + 858.*Cos(4.*vartheta[i]) - 429.*Cos(5.*vartheta[i]) + 286.*Cos(6.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.00454338524578249815*Power(Cos(0.5*vartheta[i]),4)*(7626. - 14454.*Cos(vartheta[i]) + 12375.*Cos(2.*vartheta[i]) - 9295.*Cos(3.*vartheta[i]) + 6006.*Cos(4.*vartheta[i]) - 3003.*Cos(5.*vartheta[i]) + 1001.*Cos(6.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.0738212724475868138*Power(Cos(0.5*vartheta[i]),5)*(-869. + 1660.*Cos(vartheta[i]) - 1300.*Cos(2.*vartheta[i]) + 910.*Cos(3.*vartheta[i]) - 455.*Cos(4.*vartheta[i]) + 182.*Cos(5.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.381211411713792221*Power(Cos(0.5*vartheta[i]),6)*(265. - 442.*Cos(vartheta[i]) + 364.*Cos(2.*vartheta[i]) - 182.*Cos(3.*vartheta[i]) + 91.*Cos(4.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -5.49790916690436597*Power(Cos(0.5*vartheta[i]),7)*(-19. + 42.*Cos(vartheta[i]) - 21.*Cos(2.*vartheta[i]) + 14.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 285.044189552854222*Power(Cos(0.5*vartheta[i]),8)*(-1. + 2.*Cos(vartheta[i]))*Sin(0.78539816339744831 - 0.5*vartheta[i])*Sin(0.78539816339744831 + 0.5*vartheta[i])*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 7*varphi[i];
        swsh[i] = -52.0417108346255555*Power(Cos(0.5*vartheta[i]),9)*(-1. + 4.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 8*varphi[i];
        swsh[i] = 104.083421669251111*Power(Cos(0.5*vartheta[i]),10)*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 9:
    switch(M) {
    case -9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -9*varphi[i];
        swsh[i] = 219.355865285354367*Power(Cos(0.5*vartheta[i]),7)*Power(Sin(0.5*vartheta[i]),11)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -8*varphi[i];
        swsh[i] = 51.7026732787722888*Power(Cos(0.5*vartheta[i]),6)*(2. + 9.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),10)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -7*varphi[i];
        swsh[i] = 2.21673382884871148*Power(Cos(0.5*vartheta[i]),5)*(151. + 136.*Cos(vartheta[i]) + 153.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 3.83949561842266015*Power(Cos(0.5*vartheta[i]),4)*(62. + 149.*Cos(vartheta[i]) + 68.*Cos(2.*vartheta[i]) + 51.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 0.619595941166137906*Power(Cos(0.5*vartheta[i]),3)*(427. + 672.*Cos(vartheta[i]) + 588.*Cos(2.*vartheta[i]) + 272.*Cos(3.*vartheta[i]) + 153.*Cos(4.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.259195578288233226*Power(Cos(0.5*vartheta[i]),2)*(676. + 1330.*Cos(vartheta[i]) + 1000.*Cos(2.*vartheta[i]) + 725.*Cos(3.*vartheta[i]) + 340.*Cos(4.*vartheta[i]) + 153.*Cos(5.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.022011090048569557*Cos(0.5*vartheta[i])*(4906. + 9152.*Cos(vartheta[i]) + 7865.*Cos(2.*vartheta[i]) + 5720.*Cos(3.*vartheta[i]) + 3718.*Cos(4.*vartheta[i]) + 1768.*Cos(5.*vartheta[i]) + 663.*Cos(6.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.00240160681609664791*(21252. + 40887.*Cos(vartheta[i]) + 36036.*Cos(2.*vartheta[i]) + 29029.*Cos(3.*vartheta[i]) + 20748.*Cos(4.*vartheta[i]) + 12831.*Cos(5.*vartheta[i]) + 6188.*Cos(6.*vartheta[i]) + 1989.*Cos(7.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -1*varphi[i];
        swsh[i] = 0.00281613361477977156*Cos(0.5*vartheta[i])*(6468. + 13671.*Cos(vartheta[i]) + 11466.*Cos(2.*vartheta[i]) + 10829.*Cos(3.*vartheta[i]) + 7644.*Cos(4.*vartheta[i]) + 6279.*Cos(5.*vartheta[i]) + 3094.*Cos(6.*vartheta[i]) + 1989.*Cos(7.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.0133580946271009442*Cos(vartheta[i])*(166. + 403.*Cos(2.*vartheta[i]) + 234.*Cos(4.*vartheta[i]) + 221.*Cos(6.*vartheta[i]))*Power(Sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 1*varphi[i];
        swsh[i] = 0.00281613361477977156*Power(Cos(0.5*vartheta[i]),3)*(-6468. + 13671.*Cos(vartheta[i]) - 11466.*Cos(2.*vartheta[i]) + 10829.*Cos(3.*vartheta[i]) - 7644.*Cos(4.*vartheta[i]) + 6279.*Cos(5.*vartheta[i]) - 3094.*Cos(6.*vartheta[i]) + 1989.*Cos(7.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.00240160681609664791*Power(Cos(0.5*vartheta[i]),4)*(-21252. + 40887.*Cos(vartheta[i]) - 36036.*Cos(2.*vartheta[i]) + 29029.*Cos(3.*vartheta[i]) - 20748.*Cos(4.*vartheta[i]) + 12831.*Cos(5.*vartheta[i]) - 6188.*Cos(6.*vartheta[i]) + 1989.*Cos(7.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.022011090048569557*Power(Cos(0.5*vartheta[i]),5)*(4906. - 9152.*Cos(vartheta[i]) + 7865.*Cos(2.*vartheta[i]) - 5720.*Cos(3.*vartheta[i]) + 3718.*Cos(4.*vartheta[i]) - 1768.*Cos(5.*vartheta[i]) + 663.*Cos(6.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.259195578288233226*Power(Cos(0.5*vartheta[i]),6)*(-676. + 1330.*Cos(vartheta[i]) - 1000.*Cos(2.*vartheta[i]) + 725.*Cos(3.*vartheta[i]) - 340.*Cos(4.*vartheta[i]) + 153.*Cos(5.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -0.619595941166137906*Power(Cos(0.5*vartheta[i]),7)*(427. - 672.*Cos(vartheta[i]) + 588.*Cos(2.*vartheta[i]) - 272.*Cos(3.*vartheta[i]) + 153.*Cos(4.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 3.83949561842266015*Power(Cos(0.5*vartheta[i]),8)*(-62. + 149.*Cos(vartheta[i]) - 68.*Cos(2.*vartheta[i]) + 51.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 7*varphi[i];
        swsh[i] = -2.21673382884871148*Power(Cos(0.5*vartheta[i]),9)*(151. - 136.*Cos(vartheta[i]) + 153.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 8*varphi[i];
        swsh[i] = 51.7026732787722888*Power(Cos(0.5*vartheta[i]),10)*(-2. + 9.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 9*varphi[i];
        swsh[i] = -219.355865285354367*Power(Cos(0.5*vartheta[i]),11)*Power(Sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 10:
    switch(M) {
    case -10:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -10*varphi[i];
        swsh[i] = 458.815710175124215*Power(Cos(0.5*vartheta[i]),8)*Power(Sin(0.5*vartheta[i]),12)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -9*varphi[i];
        swsh[i] = 205.188623419283937*Power(Cos(0.5*vartheta[i]),7)*(1. + 5.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),11)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -8*varphi[i];
        swsh[i] = 8.32149752273527606*Power(Cos(0.5*vartheta[i]),6)*(93. + 76.*Cos(vartheta[i]) + 95.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),10)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -7*varphi[i];
        swsh[i] = 1.69861856887797376*Power(Cos(0.5*vartheta[i]),5)*(314. + 819.*Cos(vartheta[i]) + 342.*Cos(2.*vartheta[i]) + 285.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 0.0514969395376425972*Power(Cos(0.5*vartheta[i]),4)*(13159. + 19448.*Cos(vartheta[i]) + 18156.*Cos(2.*vartheta[i]) + 7752.*Cos(3.*vartheta[i]) + 4845.*Cos(4.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 0.115150657439365437*Power(Cos(0.5*vartheta[i]),3)*(3990. + 8162.*Cos(vartheta[i]) + 5848.*Cos(2.*vartheta[i]) + 4437.*Cos(3.*vartheta[i]) + 1938.*Cos(4.*vartheta[i]) + 969.*Cos(5.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.00910345878935517795*Power(Cos(0.5*vartheta[i]),2)*(35126. + 63960.*Cos(vartheta[i]) + 55875.*Cos(2.*vartheta[i]) + 39100.*Cos(3.*vartheta[i]) + 26010.*Cos(4.*vartheta[i]) + 11628.*Cos(5.*vartheta[i]) + 4845.*Cos(6.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.00321855872110266232*Cos(0.5*vartheta[i])*(52052. + 100639.*Cos(vartheta[i]) + 87010.*Cos(2.*vartheta[i]) + 69685.*Cos(3.*vartheta[i]) + 48076.*Cos(4.*vartheta[i]) + 29631.*Cos(5.*vartheta[i]) + 13566.*Cos(6.*vartheta[i]) + 4845.*Cos(7.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.0000789014121372438118*(919611. + 1.777776e6*Cos(vartheta[i]) + 1.609608e6*Cos(2.*vartheta[i]) + 1.349712e6*Cos(3.*vartheta[i]) + 1.041404e6*Cos(4.*vartheta[i]) + 717808.*Cos(5.*vartheta[i]) + 429624.*Cos(6.*vartheta[i]) + 201552.*Cos(7.*vartheta[i]) + 62985.*Cos(8.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -1*varphi[i];
        swsh[i] = 0.000273322509221275921*Cos(0.5*vartheta[i])*(92169. + 168168.*Cos(vartheta[i]) + 168168.*Cos(2.*vartheta[i]) + 137592.*Cos(3.*vartheta[i]) + 124852.*Cos(4.*vartheta[i]) + 86632.*Cos(5.*vartheta[i]) + 68952.*Cos(6.*vartheta[i]) + 33592.*Cos(7.*vartheta[i]) + 20995.*Cos(8.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.00035832883259417753*(8085. + 15288.*Cos(2.*vartheta[i]) + 12740.*Cos(4.*vartheta[i]) + 8840.*Cos(6.*vartheta[i]) + 4199.*Cos(8.*vartheta[i]))*Power(Sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 1*varphi[i];
        swsh[i] = 0.000273322509221275921*Power(Cos(0.5*vartheta[i]),3)*(92169. - 168168.*Cos(vartheta[i]) + 168168.*Cos(2.*vartheta[i]) - 137592.*Cos(3.*vartheta[i]) + 124852.*Cos(4.*vartheta[i]) - 86632.*Cos(5.*vartheta[i]) + 68952.*Cos(6.*vartheta[i]) - 33592.*Cos(7.*vartheta[i]) + 20995.*Cos(8.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.0000789014121372438118*Power(Cos(0.5*vartheta[i]),4)*(919611. - 1.777776e6*Cos(vartheta[i]) + 1.609608e6*Cos(2.*vartheta[i]) - 1.349712e6*Cos(3.*vartheta[i]) + 1.041404e6*Cos(4.*vartheta[i]) - 717808.*Cos(5.*vartheta[i]) + 429624.*Cos(6.*vartheta[i]) - 201552.*Cos(7.*vartheta[i]) + 62985.*Cos(8.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.00321855872110266232*Power(Cos(0.5*vartheta[i]),5)*(-52052. + 100639.*Cos(vartheta[i]) - 87010.*Cos(2.*vartheta[i]) + 69685.*Cos(3.*vartheta[i]) - 48076.*Cos(4.*vartheta[i]) + 29631.*Cos(5.*vartheta[i]) - 13566.*Cos(6.*vartheta[i]) + 4845.*Cos(7.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.00910345878935517795*Power(Cos(0.5*vartheta[i]),6)*(35126. - 63960.*Cos(vartheta[i]) + 55875.*Cos(2.*vartheta[i]) - 39100.*Cos(3.*vartheta[i]) + 26010.*Cos(4.*vartheta[i]) - 11628.*Cos(5.*vartheta[i]) + 4845.*Cos(6.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -0.115150657439365437*Power(Cos(0.5*vartheta[i]),7)*(-3990. + 8162.*Cos(vartheta[i]) - 5848.*Cos(2.*vartheta[i]) + 4437.*Cos(3.*vartheta[i]) - 1938.*Cos(4.*vartheta[i]) + 969.*Cos(5.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 0.0514969395376425972*Power(Cos(0.5*vartheta[i]),8)*(13159. - 19448.*Cos(vartheta[i]) + 18156.*Cos(2.*vartheta[i]) - 7752.*Cos(3.*vartheta[i]) + 4845.*Cos(4.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 7*varphi[i];
        swsh[i] = -1.69861856887797376*Power(Cos(0.5*vartheta[i]),9)*(-314. + 819.*Cos(vartheta[i]) - 342.*Cos(2.*vartheta[i]) + 285.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 8*varphi[i];
        swsh[i] = 8.32149752273527606*Power(Cos(0.5*vartheta[i]),10)*(93. - 76.*Cos(vartheta[i]) + 95.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 9*varphi[i];
        swsh[i] = -205.188623419283937*Power(Cos(0.5*vartheta[i]),11)*(-1. + 5.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 10:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 10*varphi[i];
        swsh[i] = 458.815710175124215*Power(Cos(0.5*vartheta[i]),12)*Power(Sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 11:
    switch(M) {
    case -11:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -11*varphi[i];
        swsh[i] = 954.1586847148967*Power(Cos(0.5*vartheta[i]),9)*Power(Sin(0.5*vartheta[i]),13)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -10:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -10*varphi[i];
        swsh[i] = 203.427315098143017*Power(Cos(0.5*vartheta[i]),8)*(2. + 11.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),12)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -9*varphi[i];
        swsh[i] = 23.542137145078129*Power(Cos(0.5*vartheta[i]),7)*(75. + 56.*Cos(vartheta[i]) + 77.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),11)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -8*varphi[i];
        swsh[i] = 3.03927683656728721*Power(Cos(0.5*vartheta[i]),6)*(388. + 1095.*Cos(vartheta[i]) + 420.*Cos(2.*vartheta[i]) + 385.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),10)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -7*varphi[i];
        swsh[i] = 0.0871572407371104511*Power(Cos(0.5*vartheta[i]),5)*(19529. + 27056.*Cos(vartheta[i]) + 26980.*Cos(2.*vartheta[i]) + 10640.*Cos(3.*vartheta[i]) + 7315.*Cos(4.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 0.206711546478661343*Power(Cos(0.5*vartheta[i]),4)*(5644. + 12078.*Cos(vartheta[i]) + 8208.*Cos(2.*vartheta[i]) + 6555.*Cos(3.*vartheta[i]) + 2660.*Cos(4.*vartheta[i]) + 1463.*Cos(5.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 0.00511687324626887852*Power(Cos(0.5*vartheta[i]),3)*(178010. + 314160.*Cos(vartheta[i]) + 281673.*Cos(2.*vartheta[i]) + 188632.*Cos(3.*vartheta[i]) + 129846.*Cos(4.*vartheta[i]) + 54264.*Cos(5.*vartheta[i]) + 24871.*Cos(6.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.0135379740998672131*Power(Cos(0.5*vartheta[i]),2)*(37960. + 74347.*Cos(vartheta[i]) + 62764.*Cos(2.*vartheta[i]) + 50609.*Cos(3.*vartheta[i]) + 33592.*Cos(4.*vartheta[i]) + 20995.*Cos(5.*vartheta[i]) + 9044.*Cos(6.*vartheta[i]) + 3553.*Cos(7.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.000926881724677246133*Cos(0.5*vartheta[i])*(274703. + 526240.*Cos(vartheta[i]) + 474760.*Cos(2.*vartheta[i]) + 388960.*Cos(3.*vartheta[i]) + 296140.*Cos(4.*vartheta[i]) + 196384.*Cos(5.*vartheta[i]) + 116280.*Cos(6.*vartheta[i]) + 51680.*Cos(7.*vartheta[i]) + 17765.*Cos(8.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.0000412865934738617689*(2.414412e6 + 4.702698e6*Cos(vartheta[i]) + 4.32432e6*Cos(2.*vartheta[i]) + 3.75102e6*Cos(3.*vartheta[i]) + 3.033072e6*Cos(4.*vartheta[i]) + 2.266236e6*Cos(5.*vartheta[i]) + 1.519392e6*Cos(6.*vartheta[i]) + 886635.*Cos(7.*vartheta[i]) + 406980.*Cos(8.*vartheta[i]) + 124355.*Cos(9.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -1*varphi[i];
        swsh[i] = 0.000235369796324778191*Cos(0.5*vartheta[i])*(126126. + 261954.*Cos(vartheta[i]) + 232848.*Cos(2.*vartheta[i]) + 224028.*Cos(3.*vartheta[i]) + 179928.*Cos(4.*vartheta[i]) + 158508.*Cos(5.*vartheta[i]) + 108528.*Cos(6.*vartheta[i]) + 84303.*Cos(7.*vartheta[i]) + 40698.*Cos(8.*vartheta[i]) + 24871.*Cos(9.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.00135209654009058458*Cos(vartheta[i])*(2719. + 4264.*Cos(2.*vartheta[i]) + 4556.*Cos(4.*vartheta[i]) + 2584.*Cos(6.*vartheta[i]) + 2261.*Cos(8.*vartheta[i]))*Power(Sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 1*varphi[i];
        swsh[i] = 0.000235369796324778191*Power(Cos(0.5*vartheta[i]),3)*(-126126. + 261954.*Cos(vartheta[i]) - 232848.*Cos(2.*vartheta[i]) + 224028.*Cos(3.*vartheta[i]) - 179928.*Cos(4.*vartheta[i]) + 158508.*Cos(5.*vartheta[i]) - 108528.*Cos(6.*vartheta[i]) + 84303.*Cos(7.*vartheta[i]) - 40698.*Cos(8.*vartheta[i]) + 24871.*Cos(9.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.0000412865934738617689*Power(Cos(0.5*vartheta[i]),4)*(-2.414412e6 + 4.702698e6*Cos(vartheta[i]) - 4.32432e6*Cos(2.*vartheta[i]) + 3.75102e6*Cos(3.*vartheta[i]) - 3.033072e6*Cos(4.*vartheta[i]) + 2.266236e6*Cos(5.*vartheta[i]) - 1.519392e6*Cos(6.*vartheta[i]) + 886635.*Cos(7.*vartheta[i]) - 406980.*Cos(8.*vartheta[i]) + 124355.*Cos(9.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.000926881724677246133*Power(Cos(0.5*vartheta[i]),5)*(274703. - 526240.*Cos(vartheta[i]) + 474760.*Cos(2.*vartheta[i]) - 388960.*Cos(3.*vartheta[i]) + 296140.*Cos(4.*vartheta[i]) - 196384.*Cos(5.*vartheta[i]) + 116280.*Cos(6.*vartheta[i]) - 51680.*Cos(7.*vartheta[i]) + 17765.*Cos(8.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.0135379740998672131*Power(Cos(0.5*vartheta[i]),6)*(-37960. + 74347.*Cos(vartheta[i]) - 62764.*Cos(2.*vartheta[i]) + 50609.*Cos(3.*vartheta[i]) - 33592.*Cos(4.*vartheta[i]) + 20995.*Cos(5.*vartheta[i]) - 9044.*Cos(6.*vartheta[i]) + 3553.*Cos(7.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -0.00511687324626887852*Power(Cos(0.5*vartheta[i]),7)*(178010. - 314160.*Cos(vartheta[i]) + 281673.*Cos(2.*vartheta[i]) - 188632.*Cos(3.*vartheta[i]) + 129846.*Cos(4.*vartheta[i]) - 54264.*Cos(5.*vartheta[i]) + 24871.*Cos(6.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 0.206711546478661343*Power(Cos(0.5*vartheta[i]),8)*(-5644. + 12078.*Cos(vartheta[i]) - 8208.*Cos(2.*vartheta[i]) + 6555.*Cos(3.*vartheta[i]) - 2660.*Cos(4.*vartheta[i]) + 1463.*Cos(5.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 7*varphi[i];
        swsh[i] = -0.0871572407371104511*Power(Cos(0.5*vartheta[i]),9)*(19529. - 27056.*Cos(vartheta[i]) + 26980.*Cos(2.*vartheta[i]) - 10640.*Cos(3.*vartheta[i]) + 7315.*Cos(4.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 8*varphi[i];
        swsh[i] = 3.03927683656728721*Power(Cos(0.5*vartheta[i]),10)*(-388. + 1095.*Cos(vartheta[i]) - 420.*Cos(2.*vartheta[i]) + 385.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 9*varphi[i];
        swsh[i] = -23.542137145078129*Power(Cos(0.5*vartheta[i]),11)*(75. - 56.*Cos(vartheta[i]) + 77.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 10:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 10*varphi[i];
        swsh[i] = 203.427315098143017*Power(Cos(0.5*vartheta[i]),12)*(-2. + 11.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 11:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 11*varphi[i];
        swsh[i] = -954.1586847148967*Power(Cos(0.5*vartheta[i]),13)*Power(Sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    } // switch(M)
    
  case 12:
    switch(M) {
    case -12:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -12*varphi[i];
        swsh[i] = 1975.29613940745059*Power(Cos(0.5*vartheta[i]),10)*Power(Sin(0.5*vartheta[i]),14)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -11:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -11*varphi[i];
        swsh[i] = 806.411272072960143*Power(Cos(0.5*vartheta[i]),9)*(1. + 6.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),13)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -10:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -10*varphi[i];
        swsh[i] = 59.4494277098981063*Power(Cos(0.5*vartheta[i]),8)*(67. + 46.*Cos(vartheta[i]) + 69.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),12)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -9*varphi[i];
        swsh[i] = 10.9765780420191242*Power(Cos(0.5*vartheta[i]),7)*(235. + 715.*Cos(vartheta[i]) + 253.*Cos(2.*vartheta[i]) + 253.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),11)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -8*varphi[i];
        swsh[i] = 2.09587498954761674*Power(Cos(0.5*vartheta[i]),6)*(2005. + 2604.*Cos(vartheta[i]) + 2772.*Cos(2.*vartheta[i]) + 1012.*Cos(3.*vartheta[i]) + 759.*Cos(4.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),10)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -7*varphi[i];
        swsh[i] = 1.04793749477380837*Power(Cos(0.5*vartheta[i]),5)*(2755. + 6190.*Cos(vartheta[i]) + 3980.*Cos(2.*vartheta[i]) + 3355.*Cos(3.*vartheta[i]) + 1265.*Cos(4.*vartheta[i]) + 759.*Cos(5.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -6*varphi[i];
        swsh[i] = 0.0736112541772210869*Power(Cos(0.5*vartheta[i]),4)*(34170. + 58140.*Cos(vartheta[i]) + 53865.*Cos(2.*vartheta[i]) + 34390.*Cos(3.*vartheta[i]) + 24662.*Cos(4.*vartheta[i]) + 9614.*Cos(5.*vartheta[i]) + 4807.*Cos(6.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -5*varphi[i];
        swsh[i] = 0.00983671760506762245*Power(Cos(0.5*vartheta[i]),3)*(152150. + 303975.*Cos(vartheta[i]) + 249375.*Cos(2.*vartheta[i]) + 204421.*Cos(3.*vartheta[i]) + 130074.*Cos(4.*vartheta[i]) + 83391.*Cos(5.*vartheta[i]) + 33649.*Cos(6.*vartheta[i]) + 14421.*Cos(7.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -4*varphi[i];
        swsh[i] = 0.000210872893964438159*Power(Cos(0.5*vartheta[i]),2)*(3.952975e6 + 7.4698e6*Cos(vartheta[i]) + 6.769672e6*Cos(2.*vartheta[i]) + 5.408312e6*Cos(3.*vartheta[i]) + 4.11502e6*Cos(4.*vartheta[i]) + 2.62276e6*Cos(5.*vartheta[i]) + 1.56332e6*Cos(6.*vartheta[i]) + 653752.*Cos(7.*vartheta[i]) + 245157.*Cos(8.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -3*varphi[i];
        swsh[i] = 0.000210872893964438159*Cos(0.5*vartheta[i])*(1.748175e6 + 3.408834e6*Cos(vartheta[i]) + 3.092232e6*Cos(2.*vartheta[i]) + 2.654652e6*Cos(3.*vartheta[i]) + 2.089164e6*Cos(4.*vartheta[i]) + 1.53102e6*Cos(5.*vartheta[i]) + 984504.*Cos(6.*vartheta[i]) + 564927.*Cos(7.*vartheta[i]) + 245157.*Cos(8.*vartheta[i]) + 81719.*Cos(9.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -2*varphi[i];
        swsh[i] = 0.0000215221246165373339*(6.205914e6 + 1.212354e7*Cos(vartheta[i]) + 1.131273e7*Cos(2.*vartheta[i]) + 1.003068e7*Cos(3.*vartheta[i]) + 8.42724e6*Cos(4.*vartheta[i]) + 6.62796e6*Cos(5.*vartheta[i]) + 4.830465e6*Cos(6.*vartheta[i]) + 3.16863e6*Cos(7.*vartheta[i]) + 1.81203e6*Cos(8.*vartheta[i]) + 817190.*Cos(9.*vartheta[i]) + 245157.*Cos(10.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case -1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = -1*varphi[i];
        swsh[i] = 0.000267082542659574423*Cos(0.5*vartheta[i])*(144144. + 270270.*Cos(vartheta[i]) + 270270.*Cos(2.*vartheta[i]) + 235620.*Cos(3.*vartheta[i]) + 220320.*Cos(4.*vartheta[i]) + 174420.*Cos(5.*vartheta[i]) + 150195.*Cos(6.*vartheta[i]) + 101745.*Cos(7.*vartheta[i]) + 77520.*Cos(8.*vartheta[i]) + 37145.*Cos(9.*vartheta[i]) + 22287.*Cos(10.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 0:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 0*varphi[i];
        swsh[i] = 0.000208491243039524634*(18018. + 34650.*Cos(2.*vartheta[i]) + 30600.*Cos(4.*vartheta[i]) + 24225.*Cos(6.*vartheta[i]) + 16150.*Cos(8.*vartheta[i]) + 7429.*Cos(10.*vartheta[i]))*Power(Sin(vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 1:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 1*varphi[i];
        swsh[i] = 0.000267082542659574423*Power(Cos(0.5*vartheta[i]),3)*(144144. - 270270.*Cos(vartheta[i]) + 270270.*Cos(2.*vartheta[i]) - 235620.*Cos(3.*vartheta[i]) + 220320.*Cos(4.*vartheta[i]) - 174420.*Cos(5.*vartheta[i]) + 150195.*Cos(6.*vartheta[i]) - 101745.*Cos(7.*vartheta[i]) + 77520.*Cos(8.*vartheta[i]) - 37145.*Cos(9.*vartheta[i]) + 22287.*Cos(10.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 2:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 2*varphi[i];
        swsh[i] = 0.0000215221246165373339*Power(Cos(0.5*vartheta[i]),4)*(6.205914e6 - 1.212354e7*Cos(vartheta[i]) + 1.131273e7*Cos(2.*vartheta[i]) - 1.003068e7*Cos(3.*vartheta[i]) + 8.42724e6*Cos(4.*vartheta[i]) - 6.62796e6*Cos(5.*vartheta[i]) + 4.830465e6*Cos(6.*vartheta[i]) - 3.16863e6*Cos(7.*vartheta[i]) + 1.81203e6*Cos(8.*vartheta[i]) - 817190.*Cos(9.*vartheta[i]) + 245157.*Cos(10.*vartheta[i]))*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 3:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 3*varphi[i];
        swsh[i] = -0.000210872893964438159*Power(Cos(0.5*vartheta[i]),5)*(-1.748175e6 + 3.408834e6*Cos(vartheta[i]) - 3.092232e6*Cos(2.*vartheta[i]) + 2.654652e6*Cos(3.*vartheta[i]) - 2.089164e6*Cos(4.*vartheta[i]) + 1.53102e6*Cos(5.*vartheta[i]) - 984504.*Cos(6.*vartheta[i]) + 564927.*Cos(7.*vartheta[i]) - 245157.*Cos(8.*vartheta[i]) + 81719.*Cos(9.*vartheta[i]))*Sin(0.5*vartheta[i])*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 4:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 4*varphi[i];
        swsh[i] = 0.000210872893964438159*Power(Cos(0.5*vartheta[i]),6)*(3.952975e6 - 7.4698e6*Cos(vartheta[i]) + 6.769672e6*Cos(2.*vartheta[i]) - 5.408312e6*Cos(3.*vartheta[i]) + 4.11502e6*Cos(4.*vartheta[i]) - 2.62276e6*Cos(5.*vartheta[i]) + 1.56332e6*Cos(6.*vartheta[i]) - 653752.*Cos(7.*vartheta[i]) + 245157.*Cos(8.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),2)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 5:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 5*varphi[i];
        swsh[i] = -0.00983671760506762245*Power(Cos(0.5*vartheta[i]),7)*(-152150. + 303975.*Cos(vartheta[i]) - 249375.*Cos(2.*vartheta[i]) + 204421.*Cos(3.*vartheta[i]) - 130074.*Cos(4.*vartheta[i]) + 83391.*Cos(5.*vartheta[i]) - 33649.*Cos(6.*vartheta[i]) + 14421.*Cos(7.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),3)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 6:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 6*varphi[i];
        swsh[i] = 0.0736112541772210869*Power(Cos(0.5*vartheta[i]),8)*(34170. - 58140.*Cos(vartheta[i]) + 53865.*Cos(2.*vartheta[i]) - 34390.*Cos(3.*vartheta[i]) + 24662.*Cos(4.*vartheta[i]) - 9614.*Cos(5.*vartheta[i]) + 4807.*Cos(6.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),4)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 7:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 7*varphi[i];
        swsh[i] = -1.04793749477380837*Power(Cos(0.5*vartheta[i]),9)*(-2755. + 6190.*Cos(vartheta[i]) - 3980.*Cos(2.*vartheta[i]) + 3355.*Cos(3.*vartheta[i]) - 1265.*Cos(4.*vartheta[i]) + 759.*Cos(5.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),5)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 8:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 8*varphi[i];
        swsh[i] = 2.09587498954761674*Power(Cos(0.5*vartheta[i]),10)*(2005. - 2604.*Cos(vartheta[i]) + 2772.*Cos(2.*vartheta[i]) - 1012.*Cos(3.*vartheta[i]) + 759.*Cos(4.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),6)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 9:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 9*varphi[i];
        swsh[i] = -10.9765780420191242*Power(Cos(0.5*vartheta[i]),11)*(-235. + 715.*Cos(vartheta[i]) - 253.*Cos(2.*vartheta[i]) + 253.*Cos(3.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),7)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 10:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 10*varphi[i];
        swsh[i] = 59.4494277098981063*Power(Cos(0.5*vartheta[i]),12)*(67. - 46.*Cos(vartheta[i]) + 69.*Cos(2.*vartheta[i]))*Power(Sin(0.5*vartheta[i]),8)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 11:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 11*varphi[i];
        swsh[i] = -806.411272072960143*Power(Cos(0.5*vartheta[i]),13)*(-1. + 6.*Cos(vartheta[i]))*Power(Sin(0.5*vartheta[i]),9)*(complex<double>(cos(arg),sin(arg)));
      }
      return swsh;
    case 12:
      for(unsigned int i=0; i<swsh.size(); ++i) {
        const double arg = 12*varphi[i];
        swsh[i] = 1975.29613940745059*Power(Cos(0.5*vartheta[i]),14)*Power(Sin(0.5*vartheta[i]),10)*(complex<double>(cos(arg),sin(arg)));
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
