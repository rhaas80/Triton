  if(L==2) {
    switch(abs(M)) {
    case 1:
      amp = ((2.1137745587232059)*pow(2.7182818284590452,3.1415926535897932*Hreal*Omega)*delta*nu*pPhi*v*vPhi*pow(1. - 0.0014880952380952381*(708. + 189.*pow(chis,2) - 184.*nu)*pow(v,2) - 1.1072137188208617e-6*(435960.*pow(chieff,2) + 178605.*pow(chieff,4) + 16.*(47009. + 43972.*nu - 7404.*pow(nu,2)))*pow(v,4) + pow(v,6)*(2.9192806270460926 + 5.0003947216907596*pow(chieff,2) + 0.23785400390625*pow(chieff,4) - 0.2335968017578125*pow(chieff,6) - 0.50952380952380952*(2.5407256909229563 + 2.*log(v))) + pow(v,8)*(-1.2823578089221299 + 0.53681972789115646*(2.5407256909229563 + 2.*log(v))) + 6.0353093865606013e-14*pow(v,10)*(-6.3735873771463e13 + 7.03068108288e12*(2.5407256909229563 + 2.*log(v))),2))/r;
      phi = -M_PI/2.0 + 0.66666666666666667*Hreal*Omega + 0.0095238095238095238*(336.15041393410788 - 51.*chieff)*pow(Hreal,2)*pow(Omega,2) + 3.347039885889984*pow(Hreal,3)*pow(Omega,3) - 11.738095238095238*nu*pow(v,5) + 0.021428571428571429*pow(chieff,2)*pow(v,7) + 2.*Hreal*Omega*log(4.*Omega);
      break;
    
    case 2:
      amp = 6.3413236761696176*pow(2.7182818284590452,6.2831853071795865*Hreal*Omega)*Heff*nu*pow(vPhi,2)*pow(1. + 0.011904761904761905*(-86. + 55.*nu)*pow(v,2) + 0.000023620559334845049*(-82220. + 21168.*(pow(chis,2) + 2.*chia*chis*sqrt(1. - 4.*nu) + pow(chia,2)*(1. - 4.*nu)) - 66050.*nu + 19583.*pow(nu,2))*pow(v,4) + pow(v,10)*(-30.14143102836864 + 7.9162977360256272*(1.9635100260214235 + log(v))) + 1.0225350361404783e-9*pow(v,6)*(1.2455352904e10 + 3.453912e8*pow(chieff,2) - 2.8382682366160832e9*nu - 1.8876183e9*pow(nu,2) + 2.65518625e8*pow(nu,3) - 1.99317888e9*(3.927020052042847 + 2.*log(v))) + pow(v,8)*(-2.4172313935587003 + 0.86701625094482237*pow(chieff,2) - 0.125*pow(chieff,4) + 2.0866213151927438*(3.927020052042847 + 2.*log(v))),2);
      phi = M_PI + 2.3333333333333333*Hreal*Omega + (12.805730054632681 - 1.3333333333333333*chieff)*pow(Hreal,2)*pow(Omega,2) + 26.442985753786539*pow(Hreal,3)*pow(Omega,3) - 24.*nu*pow(v,5) + 0.31746031746031746*chieff*pow(v,8) + 4.*Hreal*Omega*log(8.*Omega);
      break;
    
    default:
      cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
      throw(1);
    } // switch(abs(M))
  } // L=2
            
            
  else if(L==3) {
    switch(abs(M)) {
    case 1:
      amp = (0.14123250342181271)*pow(2.7182818284590452,3.1415926535897932*Hreal*Omega)*delta*Heff*nu*pow(vPhi,3)*pow(1. - 0.055555555555555556*(13. + 4.*nu)*pow(v,2) - 0.00014029180695847363*(-101. + 5940.*pow(chieff,2) + 6740.*nu + 3316.*pow(nu,2))*pow(v,4) + pow(v,6)*(1.9098284139598073 - 0.4537037037037037*pow(chieff,2) - 0.20634920634920635*(2.5407256909229563 + 2.*log(v))) + pow(v,8)*(0.53681503166151791 + 0.1490299823633157*(2.5407256909229563 + 2.*log(v))),3);
      phi = -M_PI/2.0 + 0.43333333333333333*Hreal*Omega + (1.944795452222253 + 3.05*chieff)*pow(Hreal,2)*pow(Omega,2) + 1.2604910579451674*pow(Hreal,3)*pow(Omega,3) - 1.7*nu*pow(v,5) - 4.8*pow(chieff,2)*pow(v,7) + 2.*Hreal*Omega*log(4.*Omega);
      break;
    
    case 2:
      amp = 0.44661639046045251*pow(2.7182818284590452,6.2831853071795865*Hreal*Omega)*(1. + 3.*pow(delta,2))*nu*pPhi*v*pow(vPhi,4)*pow(1. + (0.0037037037037037037*(-328. + 2099.*nu - 5.*(733. + 24.*pow(chieff,2))*pow(nu,2) + 960.*pow(nu,3))*pow(v,2))/pow(1. - 3.*nu,2) + (0.33333333333333333*pow(chieff,2) + (6.2351914203766056e-7*(-1.444528e6 + 8.050045e6*nu - 4.725605e6*pow(nu,2) - 2.033896e7*pow(nu,3) + 3.08564e6*pow(nu,4)))/pow(1. - 3.*nu,2))*pow(v,4) + pow(v,6)*(6.2209979552144292 + 1.2049382716049383*pow(chieff,2) - 0.8253968253968254*(3.927020052042847 + 2.*log(v))) + pow(v,8)*(-3.4527288879001269 + 1.0027042915931805*(3.927020052042847 + 2.*log(v))),3);
      phi = M_PI + (Hreal*(10. + 33.*nu)*Omega)/(15. - 45.*nu) + 0.012698412698412698*(612.61056745000968 - 238.*chieff)*pow(Hreal,2)*pow(Omega,2) + 10.086595130228006*pow(Hreal,3)*pow(Omega,3) + 4.*chieff*pow(v,4) + 4.*Hreal*Omega*log(8.*Omega);
      break;
    
    case 3:
      amp = (4.9229202032627637)*pow(2.7182818284590452,9.4247779607693797*Hreal*Omega)*delta*Heff*nu*pow(vPhi,3)*pow(1. + 0.16666666666666667*(-7. + 4.*nu)*pow(v,2) + 0.00025252525252525253*(-6719. + 1980.*pow(chieff,2) - 7444.*nu + 1788.*pow(nu,2))*pow(v,4) + pow(v,6)*(14.10891386831863 + 0.13888888888888889*pow(chieff,2) - 1.8571428571428571*(4.7379502682591757 + 2.*log(v))) + pow(v,8)*(-6.7233753149441281 + 2.1666666666666667*(4.7379502682591757 + 2.*log(v))),3);
      phi = M_PI/2.0 + 1.3*Hreal*Omega + (17.503159070000277 - 4.05*chieff)*pow(Hreal,2)*pow(Omega,2) + 34.03325856451952*pow(Hreal,3)*pow(Omega,3) - 33.290946502057613*nu*pow(v,5) + 6.*Hreal*Omega*log(12.*Omega);
      break;
    
    default:
      cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
      throw(1);
    } // switch(abs(M))
  } // L=3
            
            
  else if(L==4) {
    switch(abs(M)) {
    case 1:
      amp = (0.011936325117290479)*pow(2.7182818284590452,3.1415926535897932*Hreal*Omega)*delta*(1. + pow(delta,2))*nu*pPhi*v*pow(vPhi,5)*pow(1. + (0.0018939393939393939*(602. - 1385.*nu + 288.*pow(nu,2))*pow(v,2))/(-1. + 2.*nu) + (-0.36778992787515515 + 0.375*pow(chieff,2))*pow(v,4) + pow(v,6)*(0.69815501755355344 - 0.11334776334776335*(2.5407256909229563 + 2.*log(v))),4);
      phi = -M_PI/2.0 + (Hreal*(2. + 507.*nu)*Omega)/(10. - 20.*nu) + 1.424370002536671*pow(Hreal,2)*pow(Omega,2) + 0.91666666666666667*chieff*pow(v,4) + 2.*Hreal*Omega*log(4.*Omega);
      break;
    
    case 2:
      amp = 0.056268376219222731*pow(2.7182818284590452,6.2831853071795865*Hreal*Omega)*(1. + 3.*pow(delta,2))*Heff*nu*pow(vPhi,4)*pow(1. + (0.00075757575757575758*(1146. - 3530.*nu + 285.*pow(nu,2))*pow(v,2))/(-1. + 3.*nu) + (0.5*pow(chieff,2) + (3.1534122443213352e-9*(-1.14859044e8 + 2.95834536e8*nu + 1.204388696e9*pow(nu,2) - 3.04798116e9*pow(nu,3) - 3.79526805e8*pow(nu,4)))/pow(1. - 3.*nu,2))*pow(v,4) + pow(v,6)*(3.8598071861190466 + 0.58661616161616162*pow(chieff,2) - 0.45339105339105339*(3.927020052042847 + 2.*log(v))),4);
      phi = M_PI + 0.00023088023088023088*(24677.210293947826 + 12243.*chieff)*pow(Hreal,2)*pow(Omega,2) + (7.*Hreal*(Omega + 6.*nu*Omega))/(15. - 45.*nu) + 4.*Hreal*Omega*log(8.*Omega);
      break;
    
    case 3:
      amp = (0.85267479136584114)*pow(2.7182818284590452,9.4247779607693797*Hreal*Omega)*delta*(1. + pow(delta,2))*nu*pPhi*v*pow(vPhi,5)*pow(1. + (0.0056818181818181818*(222. - 547.*nu + 160.*pow(nu,2))*pow(v,2))/(-1. + 2.*nu) + (-0.97832182022522932 + 0.375*pow(chieff,2))*pow(v,4) + pow(v,6)*(8.5194561570724222 - 2.0402597402597403*(2.3689751341295879 + log(v))),4);
      phi = M_PI/2.0 + (0.0012345679012345679*Hreal*(486. + 4961.*nu)*Omega)/(1. - 2.*nu) + 12.819330022830039*pow(Hreal,2)*pow(Omega,2) + 2.75*chieff*pow(v,4) + 6.*Hreal*Omega*log(12.*Omega);
      break;
    
    case 4:
      amp = (1.1909770412278734*pow(2.7182818284590452,12.566370614359173*Hreal*Omega)*(1. + 3.*pow(delta,2))*Heff*nu*pow(vPhi,2)*pow(1. + (0.00075757575757575758*(1614. - 5870.*nu + 2625.*pow(nu,2))*pow(v,2))/(-1. + 3.*nu) + (0.5*pow(chieff,2) + (3.1534122443213352e-9*(-5.11573572e8 + 2.338945704e9*nu - 3.13857376e8*pow(nu,2) - 6.733146e9*pow(nu,3) + 1.252563795e9*pow(nu,4)))/pow(1. - 3.*nu,2))*pow(v,4) + pow(v,6)*(15.108111214795124 + 0.054797979797979798*pow(chieff,2) - 1.8135642135642136*(5.3133144131627376 + 2.*log(v))),4))/r;
      phi = (0.0083333333333333333*Hreal*(112. + 219.*nu)*Omega)/(1. - 3.*nu) + (22.789920040586737 - 6.1866666666666667*chieff)*pow(Hreal,2)*pow(Omega,2) + 8.*Hreal*Omega*log(16.*Omega);
      break;
    
    default:
      cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
      throw(1);
    } // switch(abs(M))
  } // L=4
            
            
  else if(L==5) {
    switch(abs(M)) {
    case 1:
      amp = (0.0005610829516591605)*pow(2.7182818284590452,3.1415926535897932*Hreal*Omega)*delta*(1. + pow(delta,2))*Heff*nu*pow(1. + (0.0025641025641025641*(319. - 626.*nu + 8.*pow(nu,2))*pow(v,2))/(-1. + 2.*nu) + (-0.1047896120973044 + 0.5*pow(chieff,2))*pow(v,4),5)*pow(vPhi,5);
      phi = -M_PI/2.0 + 0.14761904761904762*Hreal*Omega + 2.*Hreal*Omega*log(4.*Omega);
      break;
    
    case 2:
      amp = 0.0039586292132485712*pow(2.7182818284590452,6.2831853071795865*Hreal*Omega)*(1. + 10.*pow(delta,2) + 5.*pow(delta,4))*nu*pPhi*v*pow(1. + (0.00007326007326007326*(-15828. + 84679.*nu - 104930.*pow(nu,2) + 21980.*pow(nu,3))*pow(v,2))/(1. - 5.*nu + 5.*pow(nu,2)) + (-0.46293371976009339 + 0.4*pow(chieff,2))*pow(v,4),5)*pow(vPhi,6);
      phi = M_PI + 0.13333333333333333*(2.*Hreal*Omega + 9.*chieff*pow(v,4)) + 4.*Hreal*Omega*log(8.*Omega);
      break;
    
    case 3:
      amp = (0.14726744136001343)*pow(2.7182818284590452,9.4247779607693797*Hreal*Omega)*delta*(1. + pow(delta,2))*Heff*nu*pow(1. + (0.0025641025641025641*(375. - 850.*nu + 176.*pow(nu,2))*pow(v,2))/(-1. + 2.*nu) + (-0.57880107072414765 + 0.5*pow(chieff,2))*pow(v,4),5)*pow(vPhi,5);
      phi = M_PI/2.0 + 0.44285714285714286*Hreal*Omega + 6.*Hreal*Omega*log(12.*Omega);
      break;
    
    case 4:
      amp = 0.10970475081076699*pow(2.7182818284590452,12.566370614359173*Hreal*Omega)*(1. + 10.*pow(delta,2) + 5.*pow(delta,4))*nu*pPhi*v*pow(1. + (0.00007326007326007326*(-17448. + 96019.*nu - 127610.*pow(nu,2) + 33320.*pow(nu,3))*pow(v,2))/(1. - 5.*nu + 5.*pow(nu,2)) + (-1.0442142414362195 + 0.4*pow(chieff,2))*pow(v,4),5)*pow(vPhi,6);
      phi = 0.26666666666666667*(2.*Hreal*Omega + 9.*chieff*pow(v,4)) + 8.*Hreal*Omega*log(16.*Omega);
      break;
    
    case 5:
      amp = (2.5408951369865286)*pow(2.7182818284590452,15.707963267948966*Hreal*Omega)*delta*(1. + pow(delta,2))*Heff*nu*pow(1. + (0.0025641025641025641*(487. - 1298.*nu + 512.*pow(nu,2))*pow(v,2))/(-1. + 2.*nu) + (-1.5749727622804546 + 0.5*pow(chieff,2))*pow(v,4),5)*pow(vPhi,5);
      phi = -M_PI/2.0 + (7.619047619047619e-6*Hreal*(96875. + 857528.*nu)*Omega)/(1. - 2.*nu) + 10.*Hreal*Omega*log(20.*Omega);
      break;
    
    default:
      cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
      throw(1);
    } // switch(abs(M))
  } // L=5
            
            
  else if(L==6) {
    switch(abs(M)) {
    case 1:
      amp = (9.3467103402375442e-6)*pow(2.7182818284590452,3.1415926535897932*Hreal*Omega)*delta*(3. + 10.*pow(delta,2) + 3.*pow(delta,4))*nu*pPhi*v*pow(1. + (0.0069444444444444444*(-161. + 694.*nu - 670.*pow(nu,2) + 124.*pow(nu,3))*pow(v,2))/(1. - 4.*nu + 3.*pow(nu,2)),6)*pow(vPhi,7);
      phi = -M_PI/2.0 + 0.095238095238095238*Hreal*Omega + 2.*Hreal*Omega*log(4.*Omega);
      break;
    
    case 2:
      amp = 0.00033103720501597735*pow(2.7182818284590452,6.2831853071795865*Hreal*Omega)*(1. + 10.*pow(delta,2) + 5.*pow(delta,4))*Heff*nu*pow(1. + (0.011904761904761905*(-74. + 378.*nu - 413.*pow(nu,2) + 49.*pow(nu,3))*pow(v,2))/(1. - 5.*nu + 5.*pow(nu,2)) + (-0.24797525070634314 + 0.5*pow(chieff,2))*pow(v,4),6)*pow(vPhi,6);
      phi = M_PI + 0.20476190476190476*Hreal*Omega + 4.*Hreal*Omega*log(8.*Omega);
      break;
    
    case 3:
      amp = (0.0064640925658030578)*pow(2.7182818284590452,9.4247779607693797*Hreal*Omega)*delta*(3. + 10.*pow(delta,2) + 3.*pow(delta,4))*nu*pPhi*v*pow(1. + (0.0069444444444444444*(-169. + 742.*nu - 750.*pow(nu,2) + 156.*pow(nu,3))*pow(v,2))/(1. - 4.*nu + 3.*pow(nu,2)),6)*pow(vPhi,7);
      phi = M_PI/2.0 + 0.28571428571428571*Hreal*Omega + 6.*Hreal*Omega*log(12.*Omega);
      break;
    
    case 4:
      amp = 0.023208517703771279*pow(2.7182818284590452,12.566370614359173*Hreal*Omega)*(1. + 10.*pow(delta,2) + 5.*pow(delta,4))*Heff*nu*pow(1. + (0.011904761904761905*(-86. + 462.*nu - 581.*pow(nu,2) + 133.*pow(nu,3))*pow(v,2))/(1. - 5.*nu + 5.*pow(nu,2)) + (-0.72284519868553482 + 0.5*pow(chieff,2))*pow(v,4),6)*pow(vPhi,6);
      phi = 0.40952380952380952*Hreal*Omega + 8.*Hreal*Omega*log(16.*Omega);
      break;
    
    case 5:
      amp = (0.1186453652517154)*pow(2.7182818284590452,15.707963267948966*Hreal*Omega)*delta*(3. + 10.*pow(delta,2) + 3.*pow(delta,4))*nu*pPhi*v*pow(1. + (0.0069444444444444444*(-185. + 838.*nu - 910.*pow(nu,2) + 220.*pow(nu,3))*pow(v,2))/(1. - 4.*nu + 3.*pow(nu,2)),6)*pow(vPhi,7);
      phi = -M_PI/2.0 + 0.47619047619047619*Hreal*Omega + 10.*Hreal*Omega*log(20.*Omega);
      break;
    
    case 6:
      amp = 0.35794448485193036*pow(2.7182818284590452,18.849555921538759*Hreal*Omega)*(1. + 10.*pow(delta,2) + 5.*pow(delta,4))*Heff*nu*pow(1. + (0.011904761904761905*(-106. + 602.*nu - 861.*pow(nu,2) + 273.*pow(nu,3))*pow(v,2))/(1. - 5.*nu + 5.*pow(nu,2)) + (-1.5543111183867486 + 0.5*pow(chieff,2))*pow(v,4),6)*pow(vPhi,6);
      phi = M_PI + 0.61428571428571429*Hreal*Omega + 12.*Hreal*Omega*log(24.*Omega);
      break;
    
    default:
      cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
      throw(1);
    } // switch(abs(M))
  } // L=6
            
            
  else if(L==7) {
    switch(abs(M)) {
    case 1:
      amp = (3.2403887873688399e-7)*pow(2.7182818284590452,3.1415926535897932*Hreal*Omega)*delta*(3. + 10.*pow(delta,2) + 3.*pow(delta,4))*Heff*nu*pow(1. + (0.0014005602240896359*(-618. + 2518.*nu - 2083.*pow(nu,2) + 228.*pow(nu,3))*pow(v,2))/(1. - 4.*nu + 3.*pow(nu,2)),7)*pow(vPhi,7);
      phi = -M_PI/2.0 + 0.075396825396825397*Hreal*Omega + 2.*Hreal*Omega*log(4.*Omega);
      break;
    
    case 2:
      amp = 0.000019049517833495026*pow(2.7182818284590452,6.2831853071795865*Hreal*Omega)*(1. + 21.*pow(delta,2) + 35.*pow(delta,4) + 7.*pow(delta,6))*nu*pPhi*v*pow(1. + (0.000066693344004268374*(16832. - 123489.*nu + 273924.*pow(nu,2) - 190239.*pow(nu,3) + 32760.*pow(nu,4))*pow(v,2))/(-1. + 7.*nu - 14.*pow(nu,2) + 7.*pow(nu,3)),7)*pow(vPhi,8);
      phi = M_PI + 4.*Hreal*Omega*log(8.*Omega);
      break;
    
    case 3:
      amp = (0.00073647461405943263)*pow(2.7182818284590452,9.4247779607693797*Hreal*Omega)*delta*(3. + 10.*pow(delta,2) + 3.*pow(delta,4))*Heff*nu*pow(1. + (0.0014005602240896359*(-666. + 2806.*nu - 2563.*pow(nu,2) + 420.*pow(nu,3))*pow(v,2))/(1. - 4.*nu + 3.*pow(nu,2)),7)*pow(vPhi,7);
      phi = M_PI/2.0 + 0.22619047619047619*Hreal*Omega + 6.*Hreal*Omega*log(12.*Omega);
      break;
    
    case 4:
      amp = 0.0022873640617795211*pow(2.7182818284590452,12.566370614359173*Hreal*Omega)*(1. + 21.*pow(delta,2) + 35.*pow(delta,4) + 7.*pow(delta,6))*nu*pPhi*v*pow(1. + (0.000066693344004268374*(17756. - 131805.*nu + 298872.*pow(nu,2) - 217959.*pow(nu,3) + 41076.*pow(nu,4))*pow(v,2))/(-1. + 7.*nu - 14.*pow(nu,2) + 7.*pow(nu,3)),7)*pow(vPhi,8);
      phi = 8.*Hreal*Omega*log(16.*Omega);
      break;
    
    case 5:
      amp = (0.029085338106530776)*pow(2.7182818284590452,15.707963267948966*Hreal*Omega)*delta*(3. + 10.*pow(delta,2) + 3.*pow(delta,4))*Heff*nu*pow(1. + (0.0014005602240896359*(-762. + 3382.*nu - 3523.*pow(nu,2) + 804.*pow(nu,3))*pow(v,2))/(1. - 4.*nu + 3.*pow(nu,2)),7)*pow(vPhi,7);
      phi = -M_PI/2.0 + 0.37698412698412698*Hreal*Omega + 10.*Hreal*Omega*log(20.*Omega);
      break;
    
    case 6:
      amp = 0.033213108967104201*pow(2.7182818284590452,18.849555921538759*Hreal*Omega)*(1. + 21.*pow(delta,2) + 35.*pow(delta,4) + 7.*pow(delta,6))*nu*pPhi*v*pow(1. + (0.00060024009603841537*(2144. - 16185.*nu + 37828.*pow(nu,2) - 29351.*pow(nu,3) + 6104.*pow(nu,4))*pow(v,2))/(-1. + 7.*nu - 14.*pow(nu,2) + 7.*pow(nu,3)),7)*pow(vPhi,8);
      phi = M_PI + 12.*Hreal*Omega*log(24.*Omega);
      break;
    
    case 7:
      amp = (0.41782365378884111)*pow(2.7182818284590452,21.991148575128553*Hreal*Omega)*delta*(3. + 10.*pow(delta,2) + 3.*pow(delta,4))*Heff*nu*pow(1. + (0.0014005602240896359*(-906. + 4246.*nu - 4963.*pow(nu,2) + 1380.*pow(nu,3))*pow(v,2))/(1. - 4.*nu + 3.*pow(nu,2)),7)*pow(vPhi,7);
      phi = M_PI/2.0 + 0.52777777777777778*Hreal*Omega + 14.*Hreal*Omega*log(28.*Omega);
      break;
    
    default:
      cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
      throw(1);
    } // switch(abs(M))
  } // L=7
            
            
  else if(L==8) {
    switch(abs(M)) {
    case 1:
      amp = (3.4655361196960976e-8)*pow(2.7182818284590452,3.1415926535897932*Hreal*Omega)*delta*(1. + 7.*pow(delta,2) + 7.*pow(delta,4) + pow(delta,6))*nu*pPhi*v*pow(1. + (0.000054824561403508772*(20022. - 126451.*nu + 236922.*pow(nu,2) - 138430.*pow(nu,3) + 21640.*pow(nu,4))*pow(v,2))/(-1. + 6.*nu - 10.*pow(nu,2) + 4.*pow(nu,3)),8)*pow(vPhi,9);
      phi = -M_PI/2.0 + 2.*Hreal*Omega*log(4.*Omega);
      break;
    
    case 2:
      amp = 1.1929270800794335e-6*pow(2.7182818284590452,6.2831853071795865*Hreal*Omega)*(1. + 21.*pow(delta,2) + 35.*pow(delta,4) + 7.*pow(delta,6))*Heff*nu*pow(1. + (0.00036549707602339181*(2462. - 17598.*nu + 37119.*pow(nu,2) - 22845.*pow(nu,3) + 3063.*pow(nu,4))*pow(v,2))/(-1. + 7.*nu - 14.*pow(nu,2) + 7.*pow(nu,3)),8)*pow(vPhi,8);
      phi = M_PI + 4.*Hreal*Omega*log(8.*Omega);
      break;
    
    case 3:
      amp = (0.00022078187392841438)*pow(2.7182818284590452,9.4247779607693797*Hreal*Omega)*delta*(1. + 7.*pow(delta,2) + 7.*pow(delta,4) + pow(delta,6))*nu*pPhi*v*pow(1. + (0.000054824561403508772*(20598. - 131059.*nu + 249018.*pow(nu,2) - 149950.*pow(nu,3) + 24520.*pow(nu,4))*pow(v,2))/(-1. + 6.*nu - 10.*pow(nu,2) + 4.*pow(nu,3)),8)*pow(vPhi,9);
      phi = M_PI/2.0 + 6.*Hreal*Omega*log(12.*Omega);
      break;
    
    case 4:
      amp = 0.00032029503406312776*pow(2.7182818284590452,12.566370614359173*Hreal*Omega)*(1. + 21.*pow(delta,2) + 35.*pow(delta,4) + 7.*pow(delta,6))*Heff*nu*pow(1. + (0.00036549707602339181*(2666. - 19434.*nu + 42627.*pow(nu,2) - 28965.*pow(nu,3) + 4899.*pow(nu,4))*pow(v,2))/(-1. + 7.*nu - 14.*pow(nu,2) + 7.*pow(nu,3)),8)*pow(vPhi,8);
      phi = 8.*Hreal*Omega*log(16.*Omega);
      break;
    
    case 5:
      amp = (0.012237126759328759)*pow(2.7182818284590452,15.707963267948966*Hreal*Omega)*delta*(1. + 7.*pow(delta,2) + 7.*pow(delta,4) + pow(delta,6))*nu*pPhi*v*pow(1. + (0.00027412280701754386*(4350. - 28055.*nu + 54642.*pow(nu,2) - 34598.*pow(nu,3) + 6056.*pow(nu,4))*pow(v,2))/(-1. + 6.*nu - 10.*pow(nu,2) + 4.*pow(nu,3)),8)*pow(vPhi,9);
      phi = -M_PI/2.0 + 10.*Hreal*Omega*log(20.*Omega);
      break;
    
    case 6:
      amp = 0.0091339221215335885*pow(2.7182818284590452,18.849555921538759*Hreal*Omega)*(1. + 21.*pow(delta,2) + 35.*pow(delta,4) + 7.*pow(delta,6))*Heff*nu*pow(1. + (0.0010964912280701754*(1002. - 7498.*nu + 17269.*pow(nu,2) - 13055.*pow(nu,3) + 2653.*pow(nu,4))*pow(v,2))/(-1. + 7.*nu - 14.*pow(nu,2) + 7.*pow(nu,3)),8)*pow(vPhi,8);
      phi = M_PI + 12.*Hreal*Omega*log(24.*Omega);
      break;
    
    case 7:
      amp = (0.15262993747897231)*pow(2.7182818284590452,21.991148575128553*Hreal*Omega)*delta*(1. + 7.*pow(delta,2) + 7.*pow(delta,4) + pow(delta,6))*nu*pPhi*v*pow(1. + (0.000054824561403508772*(23478. - 154099.*nu + 309498.*pow(nu,2) - 207550.*pow(nu,3) + 38920.*pow(nu,4))*pow(v,2))/(-1. + 6.*nu - 10.*pow(nu,2) + 4.*pow(nu,3)),8)*pow(vPhi,9);
      phi = M_PI/2.0 + 14.*Hreal*Omega*log(28.*Omega);
      break;
    
    case 8:
      amp = 0.12493031449806835*pow(2.7182818284590452,25.132741228718346*Hreal*Omega)*(1. + 21.*pow(delta,2) + 35.*pow(delta,4) + 7.*pow(delta,6))*Heff*nu*pow(1. + (0.00036549707602339181*(3482. - 26778.*nu + 64659.*pow(nu,2) - 53445.*pow(nu,3) + 12243.*pow(nu,4))*pow(v,2))/(-1. + 7.*nu - 14.*pow(nu,2) + 7.*pow(nu,3)),8)*pow(vPhi,8);
      phi = 16.*Hreal*Omega*log(32.*Omega);
      break;
    
    default:
      cerr << "Somehow (L,M)=(" << L << "," << M << ") didn't break from any switches..." << endl;
      throw(1);
    } // switch(abs(M))
  } // L=8
            
            
