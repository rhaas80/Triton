  double Uninitialized() {
    std::cerr << "\nThis matrix has not yet been initialized with L,M,MP information." << std::endl;
    Throw1WithMessage("Trying to use an uninitialized Wigner D matrix.");
    return 0.0;
  }

  double Identity() {
    return 1.0;
  }

  double Zero() {
    return 0.0;
  }

  double D_8_neg8_neg8() {
    return Power(Mag30,16);
  }

  double D_8_neg7_neg8() {
    return 4.*Mag12*Power(Mag30,15);
  }

  double D_8_neg6_neg8() {
    return 10.9544511501033223*Power(Mag12,2)*Power(Mag30,14);
  }

  double D_8_neg5_neg8() {
    return 23.6643191323984642*Power(Mag12,3)*Power(Mag30,13);
  }

  double D_8_neg4_neg8() {
    return 42.6614580154030835*Power(Mag12,4)*Power(Mag30,12);
  }

  double D_8_neg3_neg8() {
    return 66.0908465674332242*Power(Mag12,5)*Power(Mag30,11);
  }

  double D_8_neg2_neg8() {
    return 89.4874292847883747*Power(Mag12,6)*Power(Mag30,10);
  }

  double D_8_neg1_neg8() {
    return 106.957935656967501*Power(Mag12,7)*Power(Mag30,9);
  }

  double D_8_0_neg8() {
    return 113.446022407134222*Power(Mag12,8)*Power(Mag30,8);
  }

  double D_8_1_neg8() {
    return 106.957935656967501*Power(Mag12,9)*Power(Mag30,7);
  }

  double D_8_2_neg8() {
    return 89.4874292847883747*Power(Mag12,10)*Power(Mag30,6);
  }

  double D_8_3_neg8() {
    return 66.0908465674332242*Power(Mag12,11)*Power(Mag30,5);
  }

  double D_8_4_neg8() {
    return 42.6614580154030835*Power(Mag12,12)*Power(Mag30,4);
  }

  double D_8_5_neg8() {
    return 23.6643191323984642*Power(Mag12,13)*Power(Mag30,3);
  }

  double D_8_6_neg8() {
    return 10.9544511501033223*Power(Mag12,14)*Power(Mag30,2);
  }

  double D_8_7_neg8() {
    return 4.*Power(Mag12,15)*Mag30;
  }

  double D_8_8_neg8() {
    return Power(Mag12,16);
  }

  double D_8_neg8_neg7() {
    return -4.*Mag12*Power(Mag30,15);
  }

  double D_8_neg7_neg7() {
    return Power(Mag30,14)*(-15.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_8_neg6_neg7() {
    return Power(Mag30,13)*(-38.3405790253616279*Power(Mag12,3) + 5.4772255750516611*Mag12*Power(Mag30,2));
  }

  double D_8_neg5_neg7() {
    return Power(Mag30,12)*(-76.909037180295009*Power(Mag12,4) + 17.7482393492988481*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_8_neg4_neg7() {
    return Power(Mag30,11)*(-127.984374046209251*Power(Mag12,5) + 42.6614580154030835*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_8_neg3_neg7() {
    return Power(Mag30,10)*(-181.749828060441367*Power(Mag12,6) + 82.61355820929153*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_8_neg2_neg7() {
    return Power(Mag30,9)*(-223.718573211970937*Power(Mag12,7) + 134.231143927182562*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_8_neg1_neg7() {
    return Power(Mag30,8)*(-240.655355228176878*Power(Mag12,8) + 187.176387399693127*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_8_0_neg7() {
    return Power(Mag30,7)*(-226.892044814268444*Power(Mag12,9) + 226.892044814268444*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_8_1_neg7() {
    return Power(Mag30,6)*(-187.176387399693127*Power(Mag12,10) + 240.655355228176878*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_8_2_neg7() {
    return Power(Mag30,5)*(-134.231143927182562*Power(Mag12,11) + 223.718573211970937*Power(Mag12,9)*Power(Mag30,2));
  }

  double D_8_3_neg7() {
    return Power(Mag30,4)*(-82.61355820929153*Power(Mag12,12) + 181.749828060441367*Power(Mag12,10)*Power(Mag30,2));
  }

  double D_8_4_neg7() {
    return Power(Mag30,3)*(-42.6614580154030835*Power(Mag12,13) + 127.984374046209251*Power(Mag12,11)*Power(Mag30,2));
  }

  double D_8_5_neg7() {
    return Power(Mag30,2)*(-17.7482393492988481*Power(Mag12,14) + 76.909037180295009*Power(Mag12,12)*Power(Mag30,2));
  }

  double D_8_6_neg7() {
    return Mag30*(-5.47722557505166113*Power(Mag12,15) + 38.3405790253616279*Power(Mag12,13)*Power(Mag30,2));
  }

  double D_8_7_neg7() {
    return -1.*Power(Mag12,16) + 15.*Power(Mag12,14)*Power(Mag30,2);
  }

  double D_8_8_neg7() {
    return 4.*Power(Mag12,15)*Mag30;
  }

  double D_8_neg8_neg6() {
    return 10.9544511501033223*Power(Mag12,2)*Power(Mag30,14);
  }

  double D_8_neg7_neg6() {
    return Power(Mag30,13)*(38.3405790253616279*Power(Mag12,3) - 5.4772255750516611*Mag12*Power(Mag30,2));
  }

  double D_8_neg6_neg6() {
    return Power(Mag30,12)*(91.*Power(Mag12,4) + Power(Mag30,2)*(-28.*Power(Mag12,2) + Power(Mag30,2)));
  }

  double D_8_neg5_neg6() {
    return Power(Mag30,11)*(168.499258158604366*Power(Mag12,5) + Power(Mag30,2)*(-84.249629079302183*Power(Mag12,3) + 6.48074069840786023*Mag12*Power(Mag30,2)));
  }

  double D_8_neg4_neg6() {
    return Power(Mag30,10)*(257.033071802054297*Power(Mag12,6) + Power(Mag30,2)*(-186.933143128766762*Power(Mag12,4) + 23.3666428910958452*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_8_neg3_neg6() {
    return Power(Mag30,9)*(331.828268837963834*Power(Mag12,7) + Power(Mag30,2)*(-331.828268837963834*Power(Mag12,5) + 60.332412515993424*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_8_neg2_neg6() {
    return Power(Mag30,8)*(367.6071272432024*Power(Mag12,8) + Power(Mag30,2)*(-490.142836324269866*Power(Mag12,6) + 122.535709081067467*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_8_neg1_neg6() {
    return Power(Mag30,7)*(351.499644381043436*Power(Mag12,9) + Power(Mag30,2)*(-615.12437766682601*Power(Mag12,7) + 205.041459222275337*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_8_0_neg6() {
    return Power(Mag30,6)*(289.972412480911708*Power(Mag12,10) + Power(Mag30,2)*(-662.79408567065533*Power(Mag12,8) + 289.972412480911708*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_8_1_neg6() {
    return Power(Mag30,5)*(205.041459222275337*Power(Mag12,11) + Power(Mag30,2)*(-615.12437766682601*Power(Mag12,9) + 351.499644381043436*Power(Mag12,7)*Power(Mag30,2)));
  }

  double D_8_2_neg6() {
    return Power(Mag30,4)*(122.535709081067467*Power(Mag12,12) + Power(Mag30,2)*(-490.142836324269866*Power(Mag12,10) + 367.6071272432024*Power(Mag12,8)*Power(Mag30,2)));
  }

  double D_8_3_neg6() {
    return Power(Mag30,3)*(60.332412515993424*Power(Mag12,13) + Power(Mag30,2)*(-331.828268837963834*Power(Mag12,11) + 331.828268837963834*Power(Mag12,9)*Power(Mag30,2)));
  }

  double D_8_4_neg6() {
    return Power(Mag30,2)*(23.3666428910958452*Power(Mag12,14) + Power(Mag30,2)*(-186.933143128766762*Power(Mag12,12) + 257.033071802054297*Power(Mag12,10)*Power(Mag30,2)));
  }

  double D_8_5_neg6() {
    return Mag30*(6.48074069840786023*Power(Mag12,15) + Power(Mag30,2)*(-84.249629079302183*Power(Mag12,13) + 168.499258158604366*Power(Mag12,11)*Power(Mag30,2)));
  }

  double D_8_6_neg6() {
    return Power(Mag12,16) + Power(Mag30,2)*(-28.*Power(Mag12,14) + 91.*Power(Mag12,12)*Power(Mag30,2));
  }

  double D_8_7_neg6() {
    return Mag30*(-5.47722557505166113*Power(Mag12,15) + 38.3405790253616279*Power(Mag12,13)*Power(Mag30,2));
  }

  double D_8_8_neg6() {
    return 10.9544511501033223*Power(Mag12,14)*Power(Mag30,2);
  }

  double D_8_neg8_neg5() {
    return -23.6643191323984642*Power(Mag12,3)*Power(Mag30,13);
  }

  double D_8_neg7_neg5() {
    return Power(Mag30,12)*(-76.909037180295009*Power(Mag12,4) + 17.7482393492988481*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_8_neg6_neg5() {
    return Power(Mag30,11)*(-168.499258158604366*Power(Mag12,5) + Power(Mag30,2)*(84.249629079302183*Power(Mag12,3) - 6.48074069840786023*Mag12*Power(Mag30,2)));
  }

  double D_8_neg5_neg5() {
    return Power(Mag30,10)*(-286.*Power(Mag12,6) + Power(Mag30,2)*(234.*Power(Mag12,4) + Power(Mag30,2)*(-39.*Power(Mag12,2) + Power(Mag30,2))));
  }

  double D_8_neg4_neg5() {
    return Power(Mag30,9)*(-396.610640301038822*Power(Mag12,7) + Power(Mag30,2)*(475.932768361246587*Power(Mag12,5) + Power(Mag30,2)*(-129.799845916703615*Power(Mag12,3) + 7.2111025509279786*Mag12*Power(Mag30,2))));
  }

  double D_8_neg3_neg5() {
    return Power(Mag30,8)*(-460.819921444375059*Power(Mag12,8) + Power(Mag30,2)*(768.03320240729176*Power(Mag12,6) + Power(Mag30,2)*(-307.213280962916706*Power(Mag12,4) + 27.9284800875378823*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_8_neg2_neg5() {
    return Power(Mag30,7)*(-453.784089628536888*Power(Mag12,9) + Power(Mag30,2)*(1021.014201664208*Power(Mag12,7) + Power(Mag30,2)*(-567.23011203567111*Power(Mag12,5) + 75.630681604756148*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_8_neg1_neg5() {
    return Power(Mag30,6)*(-379.66300846935299*Power(Mag12,10) + Power(Mag30,2)*(1138.98902540805897*Power(Mag12,8) + Power(Mag30,2)*(-854.24176905604423*Power(Mag12,6) + 158.192920195563746*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_8_0_neg5() {
    return Power(Mag30,5)*(-268.462287854365124*Power(Mag12,11) + Power(Mag30,2)*(1073.8491514174605*Power(Mag12,9) + Power(Mag30,2)*(-1073.8491514174605*Power(Mag12,7) + 268.462287854365124*Power(Mag12,5)*Power(Mag30,2))));
  }

  double D_8_1_neg5() {
    return Power(Mag30,4)*(-158.192920195563746*Power(Mag12,12) + Power(Mag30,2)*(854.24176905604423*Power(Mag12,10) + Power(Mag30,2)*(-1138.98902540805897*Power(Mag12,8) + 379.66300846935299*Power(Mag12,6)*Power(Mag30,2))));
  }

  double D_8_2_neg5() {
    return Power(Mag30,3)*(-75.630681604756148*Power(Mag12,13) + Power(Mag30,2)*(567.23011203567111*Power(Mag12,11) + Power(Mag30,2)*(-1021.014201664208*Power(Mag12,9) + 453.784089628536888*Power(Mag12,7)*Power(Mag30,2))));
  }

  double D_8_3_neg5() {
    return Power(Mag30,2)*(-27.9284800875378823*Power(Mag12,14) + Power(Mag30,2)*(307.213280962916706*Power(Mag12,12) + Power(Mag30,2)*(-768.03320240729176*Power(Mag12,10) + 460.819921444375059*Power(Mag12,8)*Power(Mag30,2))));
  }

  double D_8_4_neg5() {
    return Mag30*(-7.21110255092797859*Power(Mag12,15) + Power(Mag30,2)*(129.799845916703615*Power(Mag12,13) + Power(Mag30,2)*(-475.932768361246587*Power(Mag12,11) + 396.610640301038822*Power(Mag12,9)*Power(Mag30,2))));
  }

  double D_8_5_neg5() {
    return -1.*Power(Mag12,16) + Power(Mag30,2)*(39.*Power(Mag12,14) + Power(Mag30,2)*(-234.*Power(Mag12,12) + 286.*Power(Mag12,10)*Power(Mag30,2)));
  }

  double D_8_6_neg5() {
    return Mag30*(6.48074069840786023*Power(Mag12,15) + Power(Mag30,2)*(-84.249629079302183*Power(Mag12,13) + 168.499258158604366*Power(Mag12,11)*Power(Mag30,2)));
  }

  double D_8_7_neg5() {
    return Power(Mag30,2)*(-17.7482393492988481*Power(Mag12,14) + 76.909037180295009*Power(Mag12,12)*Power(Mag30,2));
  }

  double D_8_8_neg5() {
    return 23.6643191323984642*Power(Mag12,13)*Power(Mag30,3);
  }

  double D_8_neg8_neg4() {
    return 42.6614580154030835*Power(Mag12,4)*Power(Mag30,12);
  }

  double D_8_neg7_neg4() {
    return Power(Mag30,11)*(127.984374046209251*Power(Mag12,5) - 42.6614580154030835*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_8_neg6_neg4() {
    return Power(Mag30,10)*(257.033071802054297*Power(Mag12,6) + Power(Mag30,2)*(-186.933143128766762*Power(Mag12,4) + 23.3666428910958452*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_8_neg5_neg4() {
    return Power(Mag30,9)*(396.610640301038822*Power(Mag12,7) + Power(Mag30,2)*(-475.932768361246587*Power(Mag12,5) + Power(Mag30,2)*(129.799845916703615*Power(Mag12,3) - 7.2111025509279786*Mag12*Power(Mag30,2))));
  }

  double D_8_neg4_neg4() {
    return Power(Mag30,8)*(495.*Power(Mag12,8) + Power(Mag30,2)*(-880.*Power(Mag12,6) + Power(Mag30,2)*(396.*Power(Mag12,4) + Power(Mag30,2)*(-48.*Power(Mag12,2) + Power(Mag30,2)))));
  }

  double D_8_neg3_neg4() {
    return Power(Mag30,7)*(511.23380169937903*Power(Mag12,9) + Power(Mag30,2)*(-1278.08450424844757*Power(Mag12,7) + Power(Mag30,2)*(852.05633616563171*Power(Mag12,5) + Power(Mag30,2)*(-170.411267233126343*Power(Mag12,3) + 7.74596669241483377*Mag12*Power(Mag30,2)))));
  }

  double D_8_neg2_neg4() {
    return Power(Mag30,6)*(440.49971623146365*Power(Mag12,10) + Power(Mag30,2)*(-1510.28474136501823*Power(Mag12,8) + Power(Mag30,2)*(1415.89194502970459*Power(Mag12,6) + Power(Mag30,2)*(-419.523539268060619*Power(Mag12,4) + 31.4642654451045464*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_8_neg1_neg4() {
    return Power(Mag30,5)*(315.898717946116394*Power(Mag12,11) + Power(Mag30,2)*(-1474.19401708187651*Power(Mag12,9) + Power(Mag30,2)*(1895.39230767669837*Power(Mag12,7) + Power(Mag30,2)*(-789.74679486529099*Power(Mag12,5) + 87.749643873921221*Power(Mag12,3)*Power(Mag30,2)))));
  }

  double D_8_0_neg4() {
    return Power(Mag30,4)*(186.145104689862849*Power(Mag12,12) + Power(Mag30,2)*(-1191.32867001512223*Power(Mag12,10) + Power(Mag30,2)*(2084.82517252646391*Power(Mag12,8) + Power(Mag30,2)*(-1191.32867001512223*Power(Mag12,6) + 186.145104689862849*Power(Mag12,4)*Power(Mag30,2)))));
  }

  double D_8_1_neg4() {
    return Power(Mag30,3)*(87.749643873921221*Power(Mag12,13) + Power(Mag30,2)*(-789.74679486529099*Power(Mag12,11) + Power(Mag30,2)*(1895.39230767669837*Power(Mag12,9) + Power(Mag30,2)*(-1474.19401708187651*Power(Mag12,7) + 315.898717946116394*Power(Mag12,5)*Power(Mag30,2)))));
  }

  double D_8_2_neg4() {
    return Power(Mag30,2)*(31.4642654451045464*Power(Mag12,14) + Power(Mag30,2)*(-419.523539268060619*Power(Mag12,12) + Power(Mag30,2)*(1415.89194502970459*Power(Mag12,10) + Power(Mag30,2)*(-1510.28474136501823*Power(Mag12,8) + 440.49971623146365*Power(Mag12,6)*Power(Mag30,2)))));
  }

  double D_8_3_neg4() {
    return Mag30*(7.74596669241483377*Power(Mag12,15) + Power(Mag30,2)*(-170.411267233126343*Power(Mag12,13) + Power(Mag30,2)*(852.05633616563171*Power(Mag12,11) + Power(Mag30,2)*(-1278.08450424844757*Power(Mag12,9) + 511.23380169937903*Power(Mag12,7)*Power(Mag30,2)))));
  }

  double D_8_4_neg4() {
    return Power(Mag12,16) + Power(Mag30,2)*(-48.*Power(Mag12,14) + Power(Mag30,2)*(396.*Power(Mag12,12) + Power(Mag30,2)*(-880.*Power(Mag12,10) + 495.*Power(Mag12,8)*Power(Mag30,2))));
  }

  double D_8_5_neg4() {
    return Mag30*(-7.21110255092797859*Power(Mag12,15) + Power(Mag30,2)*(129.799845916703615*Power(Mag12,13) + Power(Mag30,2)*(-475.932768361246587*Power(Mag12,11) + 396.610640301038822*Power(Mag12,9)*Power(Mag30,2))));
  }

  double D_8_6_neg4() {
    return Power(Mag30,2)*(23.3666428910958452*Power(Mag12,14) + Power(Mag30,2)*(-186.933143128766762*Power(Mag12,12) + 257.033071802054297*Power(Mag12,10)*Power(Mag30,2)));
  }

  double D_8_7_neg4() {
    return Power(Mag30,3)*(-42.6614580154030835*Power(Mag12,13) + 127.984374046209251*Power(Mag12,11)*Power(Mag30,2));
  }

  double D_8_8_neg4() {
    return 42.6614580154030835*Power(Mag12,12)*Power(Mag30,4);
  }

  double D_8_neg8_neg3() {
    return -66.0908465674332242*Power(Mag12,5)*Power(Mag30,11);
  }

  double D_8_neg7_neg3() {
    return Power(Mag30,10)*(-181.749828060441367*Power(Mag12,6) + 82.61355820929153*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_8_neg6_neg3() {
    return Power(Mag30,9)*(-331.828268837963834*Power(Mag12,7) + Power(Mag30,2)*(331.828268837963834*Power(Mag12,5) - 60.332412515993424*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_8_neg5_neg3() {
    return Power(Mag30,8)*(-460.819921444375059*Power(Mag12,8) + Power(Mag30,2)*(768.03320240729176*Power(Mag12,6) + Power(Mag30,2)*(-307.213280962916706*Power(Mag12,4) + 27.9284800875378823*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_8_neg4_neg3() {
    return Power(Mag30,7)*(-511.23380169937903*Power(Mag12,9) + Power(Mag30,2)*(1278.08450424844757*Power(Mag12,7) + Power(Mag30,2)*(-852.05633616563171*Power(Mag12,5) + Power(Mag30,2)*(170.411267233126343*Power(Mag12,3) - 7.74596669241483377*Mag12*Power(Mag30,2)))));
  }

  double D_8_neg3_neg3() {
    return Power(Mag30,6)*(-462.*Power(Mag12,10) + Power(Mag30,2)*(1650.*Power(Mag12,8) + Power(Mag30,2)*(-1650.*Power(Mag12,6) + Power(Mag30,2)*(550.*Power(Mag12,4) + Power(Mag30,2)*(-55.*Power(Mag12,2) + Power(Mag30,2))))));
  }

  double D_8_neg2_neg3() {
    return Power(Mag30,5)*(-341.209612994710335*Power(Mag12,11) + Power(Mag30,2)*(1706.04806497355168*Power(Mag12,9) + Power(Mag30,2)*(-2437.21152139078811*Power(Mag12,7) + Power(Mag30,2)*(1218.60576069539405*Power(Mag12,5) + Power(Mag30,2)*(-203.100960115899009*Power(Mag12,3) + 8.1240384046359604*Mag12*Power(Mag30,2))))));
  }

  double D_8_neg1_neg3() {
    return Power(Mag30,4)*(-203.911745615597141*Power(Mag12,12) + Power(Mag30,2)*(1427.38221930917999*Power(Mag12,10) + Power(Mag30,2)*(-2854.76443861835998*Power(Mag12,8) + Power(Mag30,2)*(2039.11745615597141*Power(Mag12,6) + Power(Mag30,2)*(-509.77936403899285*Power(Mag12,4) + 33.9852909359328569*Power(Mag12,2)*Power(Mag30,2))))));
  }

  double D_8_0_neg3() {
    return Power(Mag30,3)*(-96.1249187255833262*Power(Mag12,13) + Power(Mag30,2)*(961.24918725583326*Power(Mag12,11) + Power(Mag30,2)*(-2691.49772431633313*Power(Mag12,9) + Power(Mag30,2)*(2691.49772431633313*Power(Mag12,7) + Power(Mag30,2)*(-961.24918725583326*Power(Mag12,5) + 96.124918725583326*Power(Mag12,3)*Power(Mag30,2))))));
  }

  double D_8_1_neg3() {
    return Power(Mag30,2)*(-33.9852909359328569*Power(Mag12,14) + Power(Mag30,2)*(509.77936403899285*Power(Mag12,12) + Power(Mag30,2)*(-2039.11745615597141*Power(Mag12,10) + Power(Mag30,2)*(2854.76443861835998*Power(Mag12,8) + Power(Mag30,2)*(-1427.38221930917999*Power(Mag12,6) + 203.911745615597141*Power(Mag12,4)*Power(Mag30,2))))));
  }

  double D_8_2_neg3() {
    return Mag30*(-8.12403840463596036*Power(Mag12,15) + Power(Mag30,2)*(203.100960115899009*Power(Mag12,13) + Power(Mag30,2)*(-1218.60576069539405*Power(Mag12,11) + Power(Mag30,2)*(2437.21152139078811*Power(Mag12,9) + Power(Mag30,2)*(-1706.04806497355168*Power(Mag12,7) + 341.209612994710335*Power(Mag12,5)*Power(Mag30,2))))));
  }

  double D_8_3_neg3() {
    return -1.*Power(Mag12,16) + Power(Mag30,2)*(55.*Power(Mag12,14) + Power(Mag30,2)*(-550.*Power(Mag12,12) + Power(Mag30,2)*(1650.*Power(Mag12,10) + Power(Mag30,2)*(-1650.*Power(Mag12,8) + 462.*Power(Mag12,6)*Power(Mag30,2)))));
  }

  double D_8_4_neg3() {
    return Mag30*(7.74596669241483377*Power(Mag12,15) + Power(Mag30,2)*(-170.411267233126343*Power(Mag12,13) + Power(Mag30,2)*(852.05633616563171*Power(Mag12,11) + Power(Mag30,2)*(-1278.08450424844757*Power(Mag12,9) + 511.23380169937903*Power(Mag12,7)*Power(Mag30,2)))));
  }

  double D_8_5_neg3() {
    return Power(Mag30,2)*(-27.9284800875378823*Power(Mag12,14) + Power(Mag30,2)*(307.213280962916706*Power(Mag12,12) + Power(Mag30,2)*(-768.03320240729176*Power(Mag12,10) + 460.819921444375059*Power(Mag12,8)*Power(Mag30,2))));
  }

  double D_8_6_neg3() {
    return Power(Mag30,3)*(60.332412515993424*Power(Mag12,13) + Power(Mag30,2)*(-331.828268837963834*Power(Mag12,11) + 331.828268837963834*Power(Mag12,9)*Power(Mag30,2)));
  }

  double D_8_7_neg3() {
    return Power(Mag30,4)*(-82.61355820929153*Power(Mag12,12) + 181.749828060441367*Power(Mag12,10)*Power(Mag30,2));
  }

  double D_8_8_neg3() {
    return 66.0908465674332242*Power(Mag12,11)*Power(Mag30,5);
  }

  double D_8_neg8_neg2() {
    return 89.4874292847883747*Power(Mag12,6)*Power(Mag30,10);
  }

  double D_8_neg7_neg2() {
    return Power(Mag30,9)*(223.718573211970937*Power(Mag12,7) - 134.231143927182562*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_8_neg6_neg2() {
    return Power(Mag30,8)*(367.6071272432024*Power(Mag12,8) + Power(Mag30,2)*(-490.142836324269866*Power(Mag12,6) + 122.535709081067467*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_8_neg5_neg2() {
    return Power(Mag30,7)*(453.784089628536888*Power(Mag12,9) + Power(Mag30,2)*(-1021.014201664208*Power(Mag12,7) + Power(Mag30,2)*(567.23011203567111*Power(Mag12,5) - 75.630681604756148*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_8_neg4_neg2() {
    return Power(Mag30,6)*(440.49971623146365*Power(Mag12,10) + Power(Mag30,2)*(-1510.28474136501823*Power(Mag12,8) + Power(Mag30,2)*(1415.89194502970459*Power(Mag12,6) + Power(Mag30,2)*(-419.523539268060619*Power(Mag12,4) + 31.4642654451045464*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_8_neg3_neg2() {
    return Power(Mag30,5)*(341.209612994710335*Power(Mag12,11) + Power(Mag30,2)*(-1706.04806497355168*Power(Mag12,9) + Power(Mag30,2)*(2437.21152139078811*Power(Mag12,7) + Power(Mag30,2)*(-1218.60576069539405*Power(Mag12,5) + Power(Mag30,2)*(203.100960115899009*Power(Mag12,3) - 8.1240384046359604*Mag12*Power(Mag30,2))))));
  }

  double D_8_neg2_neg2() {
    return Power(Mag30,4)*(210.*Power(Mag12,12) + Power(Mag30,2)*(-1512.*Power(Mag12,10) + Power(Mag30,2)*(3150.*Power(Mag12,8) + Power(Mag30,2)*(-2400.*Power(Mag12,6) + Power(Mag30,2)*(675.*Power(Mag12,4) + Power(Mag30,2)*(-60.*Power(Mag12,2) + Power(Mag30,2)))))));
  }

  double D_8_neg1_neg2() {
    return Power(Mag30,3)*(100.399203184089066*Power(Mag12,13) + Power(Mag30,2)*(-1054.19163343293519*Power(Mag12,11) + Power(Mag30,2)*(3162.57490029880557*Power(Mag12,9) + Power(Mag30,2)*(-3513.9721114431173*Power(Mag12,7) + Power(Mag30,2)*(1505.98804776133599*Power(Mag12,5) + Power(Mag30,2)*(-225.898207164200398*Power(Mag12,3) + 8.36660026534075548*Mag12*Power(Mag30,2)))))));
  }

  double D_8_0_neg2() {
    return Power(Mag30,2)*(35.4964786985976963*Power(Mag12,14) + Power(Mag30,2)*(-567.94365917756314*Power(Mag12,12) + Power(Mag30,2)*(2484.75350890183874*Power(Mag12,10) + Power(Mag30,2)*(-3975.60561424294198*Power(Mag12,8) + Power(Mag30,2)*(2484.75350890183874*Power(Mag12,6) + Power(Mag30,2)*(-567.94365917756314*Power(Mag12,4) + 35.4964786985976963*Power(Mag12,2)*Power(Mag30,2)))))));
  }

  double D_8_1_neg2() {
    return Mag30*(8.36660026534075548*Power(Mag12,15) + Power(Mag30,2)*(-225.898207164200398*Power(Mag12,13) + Power(Mag30,2)*(1505.98804776133599*Power(Mag12,11) + Power(Mag30,2)*(-3513.9721114431173*Power(Mag12,9) + Power(Mag30,2)*(3162.57490029880557*Power(Mag12,7) + Power(Mag30,2)*(-1054.19163343293519*Power(Mag12,5) + 100.399203184089066*Power(Mag12,3)*Power(Mag30,2)))))));
  }

  double D_8_2_neg2() {
    return Power(Mag12,16) + Power(Mag30,2)*(-60.*Power(Mag12,14) + Power(Mag30,2)*(675.*Power(Mag12,12) + Power(Mag30,2)*(-2400.*Power(Mag12,10) + Power(Mag30,2)*(3150.*Power(Mag12,8) + Power(Mag30,2)*(-1512.*Power(Mag12,6) + 210.*Power(Mag12,4)*Power(Mag30,2))))));
  }

  double D_8_3_neg2() {
    return Mag30*(-8.12403840463596036*Power(Mag12,15) + Power(Mag30,2)*(203.100960115899009*Power(Mag12,13) + Power(Mag30,2)*(-1218.60576069539405*Power(Mag12,11) + Power(Mag30,2)*(2437.21152139078811*Power(Mag12,9) + Power(Mag30,2)*(-1706.04806497355168*Power(Mag12,7) + 341.209612994710335*Power(Mag12,5)*Power(Mag30,2))))));
  }

  double D_8_4_neg2() {
    return Power(Mag30,2)*(31.4642654451045464*Power(Mag12,14) + Power(Mag30,2)*(-419.523539268060619*Power(Mag12,12) + Power(Mag30,2)*(1415.89194502970459*Power(Mag12,10) + Power(Mag30,2)*(-1510.28474136501823*Power(Mag12,8) + 440.49971623146365*Power(Mag12,6)*Power(Mag30,2)))));
  }

  double D_8_5_neg2() {
    return Power(Mag30,3)*(-75.630681604756148*Power(Mag12,13) + Power(Mag30,2)*(567.23011203567111*Power(Mag12,11) + Power(Mag30,2)*(-1021.014201664208*Power(Mag12,9) + 453.784089628536888*Power(Mag12,7)*Power(Mag30,2))));
  }

  double D_8_6_neg2() {
    return Power(Mag30,4)*(122.535709081067467*Power(Mag12,12) + Power(Mag30,2)*(-490.142836324269866*Power(Mag12,10) + 367.6071272432024*Power(Mag12,8)*Power(Mag30,2)));
  }

  double D_8_7_neg2() {
    return Power(Mag30,5)*(-134.231143927182562*Power(Mag12,11) + 223.718573211970937*Power(Mag12,9)*Power(Mag30,2));
  }

  double D_8_8_neg2() {
    return 89.4874292847883747*Power(Mag12,10)*Power(Mag30,6);
  }

  double D_8_neg8_neg1() {
    return -106.957935656967501*Power(Mag12,7)*Power(Mag30,9);
  }

  double D_8_neg7_neg1() {
    return Power(Mag30,8)*(-240.655355228176878*Power(Mag12,8) + 187.176387399693127*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_8_neg6_neg1() {
    return Power(Mag30,7)*(-351.499644381043436*Power(Mag12,9) + Power(Mag30,2)*(615.12437766682601*Power(Mag12,7) - 205.041459222275337*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_8_neg5_neg1() {
    return Power(Mag30,6)*(-379.66300846935299*Power(Mag12,10) + Power(Mag30,2)*(1138.98902540805897*Power(Mag12,8) + Power(Mag30,2)*(-854.24176905604423*Power(Mag12,6) + 158.192920195563746*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_8_neg4_neg1() {
    return Power(Mag30,5)*(-315.898717946116394*Power(Mag12,11) + Power(Mag30,2)*(1474.19401708187651*Power(Mag12,9) + Power(Mag30,2)*(-1895.39230767669837*Power(Mag12,7) + Power(Mag30,2)*(789.74679486529099*Power(Mag12,5) - 87.749643873921221*Power(Mag12,3)*Power(Mag30,2)))));
  }

  double D_8_neg3_neg1() {
    return Power(Mag30,4)*(-203.911745615597141*Power(Mag12,12) + Power(Mag30,2)*(1427.38221930917999*Power(Mag12,10) + Power(Mag30,2)*(-2854.76443861835998*Power(Mag12,8) + Power(Mag30,2)*(2039.11745615597141*Power(Mag12,6) + Power(Mag30,2)*(-509.77936403899285*Power(Mag12,4) + 33.9852909359328569*Power(Mag12,2)*Power(Mag30,2))))));
  }

  double D_8_neg2_neg1() {
    return Power(Mag30,3)*(-100.399203184089066*Power(Mag12,13) + Power(Mag30,2)*(1054.19163343293519*Power(Mag12,11) + Power(Mag30,2)*(-3162.57490029880557*Power(Mag12,9) + Power(Mag30,2)*(3513.9721114431173*Power(Mag12,7) + Power(Mag30,2)*(-1505.98804776133599*Power(Mag12,5) + Power(Mag30,2)*(225.898207164200398*Power(Mag12,3) - 8.36660026534075548*Mag12*Power(Mag30,2)))))));
  }

  double D_8_neg1_neg1() {
    return Power(Mag30,2)*(-36.*Power(Mag12,14) + Power(Mag30,2)*(588.*Power(Mag12,12) + Power(Mag30,2)*(-2646.*Power(Mag12,10) + Power(Mag30,2)*(4410.*Power(Mag12,8) + Power(Mag30,2)*(-2940.*Power(Mag12,6) + Power(Mag30,2)*(756.*Power(Mag12,4) + Power(Mag30,2)*(-63.*Power(Mag12,2) + Power(Mag30,2))))))));
  }

  double D_8_0_neg1() {
    return Mag30*(-8.48528137423857029*Power(Mag12,15) + Power(Mag30,2)*(237.587878478679968*Power(Mag12,13) + Power(Mag30,2)*(-1663.11514935075978*Power(Mag12,11) + Power(Mag30,2)*(4157.78787337689944*Power(Mag12,9) + Power(Mag30,2)*(-4157.78787337689944*Power(Mag12,7) + Power(Mag30,2)*(1663.11514935075978*Power(Mag12,5) + Power(Mag30,2)*(-237.587878478679968*Power(Mag12,3) + 8.4852813742385703*Mag12*Power(Mag30,2))))))));
  }

  double D_8_1_neg1() {
    return -1.*Power(Mag12,16) + Power(Mag30,2)*(63.*Power(Mag12,14) + Power(Mag30,2)*(-756.*Power(Mag12,12) + Power(Mag30,2)*(2940.*Power(Mag12,10) + Power(Mag30,2)*(-4410.*Power(Mag12,8) + Power(Mag30,2)*(2646.*Power(Mag12,6) + Power(Mag30,2)*(-588.*Power(Mag12,4) + 36.*Power(Mag12,2)*Power(Mag30,2)))))));
  }

  double D_8_2_neg1() {
    return Mag30*(8.36660026534075548*Power(Mag12,15) + Power(Mag30,2)*(-225.898207164200398*Power(Mag12,13) + Power(Mag30,2)*(1505.98804776133599*Power(Mag12,11) + Power(Mag30,2)*(-3513.9721114431173*Power(Mag12,9) + Power(Mag30,2)*(3162.57490029880557*Power(Mag12,7) + Power(Mag30,2)*(-1054.19163343293519*Power(Mag12,5) + 100.399203184089066*Power(Mag12,3)*Power(Mag30,2)))))));
  }

  double D_8_3_neg1() {
    return Power(Mag30,2)*(-33.9852909359328569*Power(Mag12,14) + Power(Mag30,2)*(509.77936403899285*Power(Mag12,12) + Power(Mag30,2)*(-2039.11745615597141*Power(Mag12,10) + Power(Mag30,2)*(2854.76443861835998*Power(Mag12,8) + Power(Mag30,2)*(-1427.38221930917999*Power(Mag12,6) + 203.911745615597141*Power(Mag12,4)*Power(Mag30,2))))));
  }

  double D_8_4_neg1() {
    return Power(Mag30,3)*(87.749643873921221*Power(Mag12,13) + Power(Mag30,2)*(-789.74679486529099*Power(Mag12,11) + Power(Mag30,2)*(1895.39230767669837*Power(Mag12,9) + Power(Mag30,2)*(-1474.19401708187651*Power(Mag12,7) + 315.898717946116394*Power(Mag12,5)*Power(Mag30,2)))));
  }

  double D_8_5_neg1() {
    return Power(Mag30,4)*(-158.192920195563746*Power(Mag12,12) + Power(Mag30,2)*(854.24176905604423*Power(Mag12,10) + Power(Mag30,2)*(-1138.98902540805897*Power(Mag12,8) + 379.66300846935299*Power(Mag12,6)*Power(Mag30,2))));
  }

  double D_8_6_neg1() {
    return Power(Mag30,5)*(205.041459222275337*Power(Mag12,11) + Power(Mag30,2)*(-615.12437766682601*Power(Mag12,9) + 351.499644381043436*Power(Mag12,7)*Power(Mag30,2)));
  }

  double D_8_7_neg1() {
    return Power(Mag30,6)*(-187.176387399693127*Power(Mag12,10) + 240.655355228176878*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_8_8_neg1() {
    return 106.957935656967501*Power(Mag12,9)*Power(Mag30,7);
  }

  double D_8_neg8_0() {
    return 113.446022407134222*Power(Mag12,8)*Power(Mag30,8);
  }

  double D_8_neg7_0() {
    return Power(Mag30,7)*(226.892044814268444*Power(Mag12,9) - 226.892044814268444*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_8_neg6_0() {
    return Power(Mag30,6)*(289.972412480911708*Power(Mag12,10) + Power(Mag30,2)*(-662.79408567065533*Power(Mag12,8) + 289.972412480911708*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_8_neg5_0() {
    return Power(Mag30,5)*(268.462287854365124*Power(Mag12,11) + Power(Mag30,2)*(-1073.8491514174605*Power(Mag12,9) + Power(Mag30,2)*(1073.8491514174605*Power(Mag12,7) - 268.462287854365124*Power(Mag12,5)*Power(Mag30,2))));
  }

  double D_8_neg4_0() {
    return Power(Mag30,4)*(186.145104689862849*Power(Mag12,12) + Power(Mag30,2)*(-1191.32867001512223*Power(Mag12,10) + Power(Mag30,2)*(2084.82517252646391*Power(Mag12,8) + Power(Mag30,2)*(-1191.32867001512223*Power(Mag12,6) + 186.145104689862849*Power(Mag12,4)*Power(Mag30,2)))));
  }

  double D_8_neg3_0() {
    return Power(Mag30,3)*(96.1249187255833262*Power(Mag12,13) + Power(Mag30,2)*(-961.24918725583326*Power(Mag12,11) + Power(Mag30,2)*(2691.49772431633313*Power(Mag12,9) + Power(Mag30,2)*(-2691.49772431633313*Power(Mag12,7) + Power(Mag30,2)*(961.24918725583326*Power(Mag12,5) - 96.124918725583326*Power(Mag12,3)*Power(Mag30,2))))));
  }

  double D_8_neg2_0() {
    return Power(Mag30,2)*(35.4964786985976963*Power(Mag12,14) + Power(Mag30,2)*(-567.94365917756314*Power(Mag12,12) + Power(Mag30,2)*(2484.75350890183874*Power(Mag12,10) + Power(Mag30,2)*(-3975.60561424294198*Power(Mag12,8) + Power(Mag30,2)*(2484.75350890183874*Power(Mag12,6) + Power(Mag30,2)*(-567.94365917756314*Power(Mag12,4) + 35.4964786985976963*Power(Mag12,2)*Power(Mag30,2)))))));
  }

  double D_8_neg1_0() {
    return Mag30*(8.48528137423857029*Power(Mag12,15) + Power(Mag30,2)*(-237.587878478679968*Power(Mag12,13) + Power(Mag30,2)*(1663.11514935075978*Power(Mag12,11) + Power(Mag30,2)*(-4157.78787337689944*Power(Mag12,9) + Power(Mag30,2)*(4157.78787337689944*Power(Mag12,7) + Power(Mag30,2)*(-1663.11514935075978*Power(Mag12,5) + Power(Mag30,2)*(237.587878478679968*Power(Mag12,3) - 8.4852813742385703*Mag12*Power(Mag30,2))))))));
  }

  double D_8_0_0() {
    return Power(Mag12,16) + Power(Mag30,2)*(-64.*Power(Mag12,14) + Power(Mag30,2)*(784.*Power(Mag12,12) + Power(Mag30,2)*(-3136.*Power(Mag12,10) + Power(Mag30,2)*(4900.*Power(Mag12,8) + Power(Mag30,2)*(-3136.*Power(Mag12,6) + Power(Mag30,2)*(784.*Power(Mag12,4) + Power(Mag30,2)*(-64.*Power(Mag12,2) + Power(Mag30,2))))))));
  }

  double D_8_1_0() {
    return Mag30*(-8.48528137423857029*Power(Mag12,15) + Power(Mag30,2)*(237.587878478679968*Power(Mag12,13) + Power(Mag30,2)*(-1663.11514935075978*Power(Mag12,11) + Power(Mag30,2)*(4157.78787337689944*Power(Mag12,9) + Power(Mag30,2)*(-4157.78787337689944*Power(Mag12,7) + Power(Mag30,2)*(1663.11514935075978*Power(Mag12,5) + Power(Mag30,2)*(-237.587878478679968*Power(Mag12,3) + 8.4852813742385703*Mag12*Power(Mag30,2))))))));
  }

  double D_8_2_0() {
    return Power(Mag30,2)*(35.4964786985976963*Power(Mag12,14) + Power(Mag30,2)*(-567.94365917756314*Power(Mag12,12) + Power(Mag30,2)*(2484.75350890183874*Power(Mag12,10) + Power(Mag30,2)*(-3975.60561424294198*Power(Mag12,8) + Power(Mag30,2)*(2484.75350890183874*Power(Mag12,6) + Power(Mag30,2)*(-567.94365917756314*Power(Mag12,4) + 35.4964786985976963*Power(Mag12,2)*Power(Mag30,2)))))));
  }

  double D_8_3_0() {
    return Power(Mag30,3)*(-96.1249187255833262*Power(Mag12,13) + Power(Mag30,2)*(961.24918725583326*Power(Mag12,11) + Power(Mag30,2)*(-2691.49772431633313*Power(Mag12,9) + Power(Mag30,2)*(2691.49772431633313*Power(Mag12,7) + Power(Mag30,2)*(-961.24918725583326*Power(Mag12,5) + 96.124918725583326*Power(Mag12,3)*Power(Mag30,2))))));
  }

  double D_8_4_0() {
    return Power(Mag30,4)*(186.145104689862849*Power(Mag12,12) + Power(Mag30,2)*(-1191.32867001512223*Power(Mag12,10) + Power(Mag30,2)*(2084.82517252646391*Power(Mag12,8) + Power(Mag30,2)*(-1191.32867001512223*Power(Mag12,6) + 186.145104689862849*Power(Mag12,4)*Power(Mag30,2)))));
  }

  double D_8_5_0() {
    return Power(Mag30,5)*(-268.462287854365124*Power(Mag12,11) + Power(Mag30,2)*(1073.8491514174605*Power(Mag12,9) + Power(Mag30,2)*(-1073.8491514174605*Power(Mag12,7) + 268.462287854365124*Power(Mag12,5)*Power(Mag30,2))));
  }

  double D_8_6_0() {
    return Power(Mag30,6)*(289.972412480911708*Power(Mag12,10) + Power(Mag30,2)*(-662.79408567065533*Power(Mag12,8) + 289.972412480911708*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_8_7_0() {
    return Power(Mag30,7)*(-226.892044814268444*Power(Mag12,9) + 226.892044814268444*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_8_8_0() {
    return 113.446022407134222*Power(Mag12,8)*Power(Mag30,8);
  }

  double D_8_neg8_1() {
    return -106.957935656967501*Power(Mag12,9)*Power(Mag30,7);
  }

  double D_8_neg7_1() {
    return Power(Mag30,6)*(-187.176387399693127*Power(Mag12,10) + 240.655355228176878*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_8_neg6_1() {
    return Power(Mag30,5)*(-205.041459222275337*Power(Mag12,11) + Power(Mag30,2)*(615.12437766682601*Power(Mag12,9) - 351.499644381043436*Power(Mag12,7)*Power(Mag30,2)));
  }

  double D_8_neg5_1() {
    return Power(Mag30,4)*(-158.192920195563746*Power(Mag12,12) + Power(Mag30,2)*(854.24176905604423*Power(Mag12,10) + Power(Mag30,2)*(-1138.98902540805897*Power(Mag12,8) + 379.66300846935299*Power(Mag12,6)*Power(Mag30,2))));
  }

  double D_8_neg4_1() {
    return Power(Mag30,3)*(-87.749643873921221*Power(Mag12,13) + Power(Mag30,2)*(789.74679486529099*Power(Mag12,11) + Power(Mag30,2)*(-1895.39230767669837*Power(Mag12,9) + Power(Mag30,2)*(1474.19401708187651*Power(Mag12,7) - 315.898717946116394*Power(Mag12,5)*Power(Mag30,2)))));
  }

  double D_8_neg3_1() {
    return Power(Mag30,2)*(-33.9852909359328569*Power(Mag12,14) + Power(Mag30,2)*(509.77936403899285*Power(Mag12,12) + Power(Mag30,2)*(-2039.11745615597141*Power(Mag12,10) + Power(Mag30,2)*(2854.76443861835998*Power(Mag12,8) + Power(Mag30,2)*(-1427.38221930917999*Power(Mag12,6) + 203.911745615597141*Power(Mag12,4)*Power(Mag30,2))))));
  }

  double D_8_neg2_1() {
    return Mag30*(-8.36660026534075548*Power(Mag12,15) + Power(Mag30,2)*(225.898207164200398*Power(Mag12,13) + Power(Mag30,2)*(-1505.98804776133599*Power(Mag12,11) + Power(Mag30,2)*(3513.9721114431173*Power(Mag12,9) + Power(Mag30,2)*(-3162.57490029880557*Power(Mag12,7) + Power(Mag30,2)*(1054.19163343293519*Power(Mag12,5) - 100.399203184089066*Power(Mag12,3)*Power(Mag30,2)))))));
  }

  double D_8_neg1_1() {
    return -1.*Power(Mag12,16) + Power(Mag30,2)*(63.*Power(Mag12,14) + Power(Mag30,2)*(-756.*Power(Mag12,12) + Power(Mag30,2)*(2940.*Power(Mag12,10) + Power(Mag30,2)*(-4410.*Power(Mag12,8) + Power(Mag30,2)*(2646.*Power(Mag12,6) + Power(Mag30,2)*(-588.*Power(Mag12,4) + 36.*Power(Mag12,2)*Power(Mag30,2)))))));
  }

  double D_8_0_1() {
    return Mag30*(8.48528137423857029*Power(Mag12,15) + Power(Mag30,2)*(-237.587878478679968*Power(Mag12,13) + Power(Mag30,2)*(1663.11514935075978*Power(Mag12,11) + Power(Mag30,2)*(-4157.78787337689944*Power(Mag12,9) + Power(Mag30,2)*(4157.78787337689944*Power(Mag12,7) + Power(Mag30,2)*(-1663.11514935075978*Power(Mag12,5) + Power(Mag30,2)*(237.587878478679968*Power(Mag12,3) - 8.4852813742385703*Mag12*Power(Mag30,2))))))));
  }

  double D_8_1_1() {
    return Power(Mag30,2)*(-36.*Power(Mag12,14) + Power(Mag30,2)*(588.*Power(Mag12,12) + Power(Mag30,2)*(-2646.*Power(Mag12,10) + Power(Mag30,2)*(4410.*Power(Mag12,8) + Power(Mag30,2)*(-2940.*Power(Mag12,6) + Power(Mag30,2)*(756.*Power(Mag12,4) + Power(Mag30,2)*(-63.*Power(Mag12,2) + Power(Mag30,2))))))));
  }

  double D_8_2_1() {
    return Power(Mag30,3)*(100.399203184089066*Power(Mag12,13) + Power(Mag30,2)*(-1054.19163343293519*Power(Mag12,11) + Power(Mag30,2)*(3162.57490029880557*Power(Mag12,9) + Power(Mag30,2)*(-3513.9721114431173*Power(Mag12,7) + Power(Mag30,2)*(1505.98804776133599*Power(Mag12,5) + Power(Mag30,2)*(-225.898207164200398*Power(Mag12,3) + 8.36660026534075548*Mag12*Power(Mag30,2)))))));
  }

  double D_8_3_1() {
    return Power(Mag30,4)*(-203.911745615597141*Power(Mag12,12) + Power(Mag30,2)*(1427.38221930917999*Power(Mag12,10) + Power(Mag30,2)*(-2854.76443861835998*Power(Mag12,8) + Power(Mag30,2)*(2039.11745615597141*Power(Mag12,6) + Power(Mag30,2)*(-509.77936403899285*Power(Mag12,4) + 33.9852909359328569*Power(Mag12,2)*Power(Mag30,2))))));
  }

  double D_8_4_1() {
    return Power(Mag30,5)*(315.898717946116394*Power(Mag12,11) + Power(Mag30,2)*(-1474.19401708187651*Power(Mag12,9) + Power(Mag30,2)*(1895.39230767669837*Power(Mag12,7) + Power(Mag30,2)*(-789.74679486529099*Power(Mag12,5) + 87.749643873921221*Power(Mag12,3)*Power(Mag30,2)))));
  }

  double D_8_5_1() {
    return Power(Mag30,6)*(-379.66300846935299*Power(Mag12,10) + Power(Mag30,2)*(1138.98902540805897*Power(Mag12,8) + Power(Mag30,2)*(-854.24176905604423*Power(Mag12,6) + 158.192920195563746*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_8_6_1() {
    return Power(Mag30,7)*(351.499644381043436*Power(Mag12,9) + Power(Mag30,2)*(-615.12437766682601*Power(Mag12,7) + 205.041459222275337*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_8_7_1() {
    return Power(Mag30,8)*(-240.655355228176878*Power(Mag12,8) + 187.176387399693127*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_8_8_1() {
    return 106.957935656967501*Power(Mag12,7)*Power(Mag30,9);
  }

  double D_8_neg8_2() {
    return 89.4874292847883747*Power(Mag12,10)*Power(Mag30,6);
  }

  double D_8_neg7_2() {
    return Power(Mag30,5)*(134.231143927182562*Power(Mag12,11) - 223.718573211970937*Power(Mag12,9)*Power(Mag30,2));
  }

  double D_8_neg6_2() {
    return Power(Mag30,4)*(122.535709081067467*Power(Mag12,12) + Power(Mag30,2)*(-490.142836324269866*Power(Mag12,10) + 367.6071272432024*Power(Mag12,8)*Power(Mag30,2)));
  }

  double D_8_neg5_2() {
    return Power(Mag30,3)*(75.630681604756148*Power(Mag12,13) + Power(Mag30,2)*(-567.23011203567111*Power(Mag12,11) + Power(Mag30,2)*(1021.014201664208*Power(Mag12,9) - 453.784089628536888*Power(Mag12,7)*Power(Mag30,2))));
  }

  double D_8_neg4_2() {
    return Power(Mag30,2)*(31.4642654451045464*Power(Mag12,14) + Power(Mag30,2)*(-419.523539268060619*Power(Mag12,12) + Power(Mag30,2)*(1415.89194502970459*Power(Mag12,10) + Power(Mag30,2)*(-1510.28474136501823*Power(Mag12,8) + 440.49971623146365*Power(Mag12,6)*Power(Mag30,2)))));
  }

  double D_8_neg3_2() {
    return Mag30*(8.12403840463596036*Power(Mag12,15) + Power(Mag30,2)*(-203.100960115899009*Power(Mag12,13) + Power(Mag30,2)*(1218.60576069539405*Power(Mag12,11) + Power(Mag30,2)*(-2437.21152139078811*Power(Mag12,9) + Power(Mag30,2)*(1706.04806497355168*Power(Mag12,7) - 341.209612994710335*Power(Mag12,5)*Power(Mag30,2))))));
  }

  double D_8_neg2_2() {
    return Power(Mag12,16) + Power(Mag30,2)*(-60.*Power(Mag12,14) + Power(Mag30,2)*(675.*Power(Mag12,12) + Power(Mag30,2)*(-2400.*Power(Mag12,10) + Power(Mag30,2)*(3150.*Power(Mag12,8) + Power(Mag30,2)*(-1512.*Power(Mag12,6) + 210.*Power(Mag12,4)*Power(Mag30,2))))));
  }

  double D_8_neg1_2() {
    return Mag30*(-8.36660026534075548*Power(Mag12,15) + Power(Mag30,2)*(225.898207164200398*Power(Mag12,13) + Power(Mag30,2)*(-1505.98804776133599*Power(Mag12,11) + Power(Mag30,2)*(3513.9721114431173*Power(Mag12,9) + Power(Mag30,2)*(-3162.57490029880557*Power(Mag12,7) + Power(Mag30,2)*(1054.19163343293519*Power(Mag12,5) - 100.399203184089066*Power(Mag12,3)*Power(Mag30,2)))))));
  }

  double D_8_0_2() {
    return Power(Mag30,2)*(35.4964786985976963*Power(Mag12,14) + Power(Mag30,2)*(-567.94365917756314*Power(Mag12,12) + Power(Mag30,2)*(2484.75350890183874*Power(Mag12,10) + Power(Mag30,2)*(-3975.60561424294198*Power(Mag12,8) + Power(Mag30,2)*(2484.75350890183874*Power(Mag12,6) + Power(Mag30,2)*(-567.94365917756314*Power(Mag12,4) + 35.4964786985976963*Power(Mag12,2)*Power(Mag30,2)))))));
  }

  double D_8_1_2() {
    return Power(Mag30,3)*(-100.399203184089066*Power(Mag12,13) + Power(Mag30,2)*(1054.19163343293519*Power(Mag12,11) + Power(Mag30,2)*(-3162.57490029880557*Power(Mag12,9) + Power(Mag30,2)*(3513.9721114431173*Power(Mag12,7) + Power(Mag30,2)*(-1505.98804776133599*Power(Mag12,5) + Power(Mag30,2)*(225.898207164200398*Power(Mag12,3) - 8.36660026534075548*Mag12*Power(Mag30,2)))))));
  }

  double D_8_2_2() {
    return Power(Mag30,4)*(210.*Power(Mag12,12) + Power(Mag30,2)*(-1512.*Power(Mag12,10) + Power(Mag30,2)*(3150.*Power(Mag12,8) + Power(Mag30,2)*(-2400.*Power(Mag12,6) + Power(Mag30,2)*(675.*Power(Mag12,4) + Power(Mag30,2)*(-60.*Power(Mag12,2) + Power(Mag30,2)))))));
  }

  double D_8_3_2() {
    return Power(Mag30,5)*(-341.209612994710335*Power(Mag12,11) + Power(Mag30,2)*(1706.04806497355168*Power(Mag12,9) + Power(Mag30,2)*(-2437.21152139078811*Power(Mag12,7) + Power(Mag30,2)*(1218.60576069539405*Power(Mag12,5) + Power(Mag30,2)*(-203.100960115899009*Power(Mag12,3) + 8.1240384046359604*Mag12*Power(Mag30,2))))));
  }

  double D_8_4_2() {
    return Power(Mag30,6)*(440.49971623146365*Power(Mag12,10) + Power(Mag30,2)*(-1510.28474136501823*Power(Mag12,8) + Power(Mag30,2)*(1415.89194502970459*Power(Mag12,6) + Power(Mag30,2)*(-419.523539268060619*Power(Mag12,4) + 31.4642654451045464*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_8_5_2() {
    return Power(Mag30,7)*(-453.784089628536888*Power(Mag12,9) + Power(Mag30,2)*(1021.014201664208*Power(Mag12,7) + Power(Mag30,2)*(-567.23011203567111*Power(Mag12,5) + 75.630681604756148*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_8_6_2() {
    return Power(Mag30,8)*(367.6071272432024*Power(Mag12,8) + Power(Mag30,2)*(-490.142836324269866*Power(Mag12,6) + 122.535709081067467*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_8_7_2() {
    return Power(Mag30,9)*(-223.718573211970937*Power(Mag12,7) + 134.231143927182562*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_8_8_2() {
    return 89.4874292847883747*Power(Mag12,6)*Power(Mag30,10);
  }

  double D_8_neg8_3() {
    return -66.0908465674332242*Power(Mag12,11)*Power(Mag30,5);
  }

  double D_8_neg7_3() {
    return Power(Mag30,4)*(-82.61355820929153*Power(Mag12,12) + 181.749828060441367*Power(Mag12,10)*Power(Mag30,2));
  }

  double D_8_neg6_3() {
    return Power(Mag30,3)*(-60.332412515993424*Power(Mag12,13) + Power(Mag30,2)*(331.828268837963834*Power(Mag12,11) - 331.828268837963834*Power(Mag12,9)*Power(Mag30,2)));
  }

  double D_8_neg5_3() {
    return Power(Mag30,2)*(-27.9284800875378823*Power(Mag12,14) + Power(Mag30,2)*(307.213280962916706*Power(Mag12,12) + Power(Mag30,2)*(-768.03320240729176*Power(Mag12,10) + 460.819921444375059*Power(Mag12,8)*Power(Mag30,2))));
  }

  double D_8_neg4_3() {
    return Mag30*(-7.74596669241483377*Power(Mag12,15) + Power(Mag30,2)*(170.411267233126343*Power(Mag12,13) + Power(Mag30,2)*(-852.05633616563171*Power(Mag12,11) + Power(Mag30,2)*(1278.08450424844757*Power(Mag12,9) - 511.23380169937903*Power(Mag12,7)*Power(Mag30,2)))));
  }

  double D_8_neg3_3() {
    return -1.*Power(Mag12,16) + Power(Mag30,2)*(55.*Power(Mag12,14) + Power(Mag30,2)*(-550.*Power(Mag12,12) + Power(Mag30,2)*(1650.*Power(Mag12,10) + Power(Mag30,2)*(-1650.*Power(Mag12,8) + 462.*Power(Mag12,6)*Power(Mag30,2)))));
  }

  double D_8_neg2_3() {
    return Mag30*(8.12403840463596036*Power(Mag12,15) + Power(Mag30,2)*(-203.100960115899009*Power(Mag12,13) + Power(Mag30,2)*(1218.60576069539405*Power(Mag12,11) + Power(Mag30,2)*(-2437.21152139078811*Power(Mag12,9) + Power(Mag30,2)*(1706.04806497355168*Power(Mag12,7) - 341.209612994710335*Power(Mag12,5)*Power(Mag30,2))))));
  }

  double D_8_neg1_3() {
    return Power(Mag30,2)*(-33.9852909359328569*Power(Mag12,14) + Power(Mag30,2)*(509.77936403899285*Power(Mag12,12) + Power(Mag30,2)*(-2039.11745615597141*Power(Mag12,10) + Power(Mag30,2)*(2854.76443861835998*Power(Mag12,8) + Power(Mag30,2)*(-1427.38221930917999*Power(Mag12,6) + 203.911745615597141*Power(Mag12,4)*Power(Mag30,2))))));
  }

  double D_8_0_3() {
    return Power(Mag30,3)*(96.1249187255833262*Power(Mag12,13) + Power(Mag30,2)*(-961.24918725583326*Power(Mag12,11) + Power(Mag30,2)*(2691.49772431633313*Power(Mag12,9) + Power(Mag30,2)*(-2691.49772431633313*Power(Mag12,7) + Power(Mag30,2)*(961.24918725583326*Power(Mag12,5) - 96.124918725583326*Power(Mag12,3)*Power(Mag30,2))))));
  }

  double D_8_1_3() {
    return Power(Mag30,4)*(-203.911745615597141*Power(Mag12,12) + Power(Mag30,2)*(1427.38221930917999*Power(Mag12,10) + Power(Mag30,2)*(-2854.76443861835998*Power(Mag12,8) + Power(Mag30,2)*(2039.11745615597141*Power(Mag12,6) + Power(Mag30,2)*(-509.77936403899285*Power(Mag12,4) + 33.9852909359328569*Power(Mag12,2)*Power(Mag30,2))))));
  }

  double D_8_2_3() {
    return Power(Mag30,5)*(341.209612994710335*Power(Mag12,11) + Power(Mag30,2)*(-1706.04806497355168*Power(Mag12,9) + Power(Mag30,2)*(2437.21152139078811*Power(Mag12,7) + Power(Mag30,2)*(-1218.60576069539405*Power(Mag12,5) + Power(Mag30,2)*(203.100960115899009*Power(Mag12,3) - 8.1240384046359604*Mag12*Power(Mag30,2))))));
  }

  double D_8_3_3() {
    return Power(Mag30,6)*(-462.*Power(Mag12,10) + Power(Mag30,2)*(1650.*Power(Mag12,8) + Power(Mag30,2)*(-1650.*Power(Mag12,6) + Power(Mag30,2)*(550.*Power(Mag12,4) + Power(Mag30,2)*(-55.*Power(Mag12,2) + Power(Mag30,2))))));
  }

  double D_8_4_3() {
    return Power(Mag30,7)*(511.23380169937903*Power(Mag12,9) + Power(Mag30,2)*(-1278.08450424844757*Power(Mag12,7) + Power(Mag30,2)*(852.05633616563171*Power(Mag12,5) + Power(Mag30,2)*(-170.411267233126343*Power(Mag12,3) + 7.74596669241483377*Mag12*Power(Mag30,2)))));
  }

  double D_8_5_3() {
    return Power(Mag30,8)*(-460.819921444375059*Power(Mag12,8) + Power(Mag30,2)*(768.03320240729176*Power(Mag12,6) + Power(Mag30,2)*(-307.213280962916706*Power(Mag12,4) + 27.9284800875378823*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_8_6_3() {
    return Power(Mag30,9)*(331.828268837963834*Power(Mag12,7) + Power(Mag30,2)*(-331.828268837963834*Power(Mag12,5) + 60.332412515993424*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_8_7_3() {
    return Power(Mag30,10)*(-181.749828060441367*Power(Mag12,6) + 82.61355820929153*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_8_8_3() {
    return 66.0908465674332242*Power(Mag12,5)*Power(Mag30,11);
  }

  double D_8_neg8_4() {
    return 42.6614580154030835*Power(Mag12,12)*Power(Mag30,4);
  }

  double D_8_neg7_4() {
    return Power(Mag30,3)*(42.6614580154030835*Power(Mag12,13) - 127.984374046209251*Power(Mag12,11)*Power(Mag30,2));
  }

  double D_8_neg6_4() {
    return Power(Mag30,2)*(23.3666428910958452*Power(Mag12,14) + Power(Mag30,2)*(-186.933143128766762*Power(Mag12,12) + 257.033071802054297*Power(Mag12,10)*Power(Mag30,2)));
  }

  double D_8_neg5_4() {
    return Mag30*(7.21110255092797859*Power(Mag12,15) + Power(Mag30,2)*(-129.799845916703615*Power(Mag12,13) + Power(Mag30,2)*(475.932768361246587*Power(Mag12,11) - 396.610640301038822*Power(Mag12,9)*Power(Mag30,2))));
  }

  double D_8_neg4_4() {
    return Power(Mag12,16) + Power(Mag30,2)*(-48.*Power(Mag12,14) + Power(Mag30,2)*(396.*Power(Mag12,12) + Power(Mag30,2)*(-880.*Power(Mag12,10) + 495.*Power(Mag12,8)*Power(Mag30,2))));
  }

  double D_8_neg3_4() {
    return Mag30*(-7.74596669241483377*Power(Mag12,15) + Power(Mag30,2)*(170.411267233126343*Power(Mag12,13) + Power(Mag30,2)*(-852.05633616563171*Power(Mag12,11) + Power(Mag30,2)*(1278.08450424844757*Power(Mag12,9) - 511.23380169937903*Power(Mag12,7)*Power(Mag30,2)))));
  }

  double D_8_neg2_4() {
    return Power(Mag30,2)*(31.4642654451045464*Power(Mag12,14) + Power(Mag30,2)*(-419.523539268060619*Power(Mag12,12) + Power(Mag30,2)*(1415.89194502970459*Power(Mag12,10) + Power(Mag30,2)*(-1510.28474136501823*Power(Mag12,8) + 440.49971623146365*Power(Mag12,6)*Power(Mag30,2)))));
  }

  double D_8_neg1_4() {
    return Power(Mag30,3)*(-87.749643873921221*Power(Mag12,13) + Power(Mag30,2)*(789.74679486529099*Power(Mag12,11) + Power(Mag30,2)*(-1895.39230767669837*Power(Mag12,9) + Power(Mag30,2)*(1474.19401708187651*Power(Mag12,7) - 315.898717946116394*Power(Mag12,5)*Power(Mag30,2)))));
  }

  double D_8_0_4() {
    return Power(Mag30,4)*(186.145104689862849*Power(Mag12,12) + Power(Mag30,2)*(-1191.32867001512223*Power(Mag12,10) + Power(Mag30,2)*(2084.82517252646391*Power(Mag12,8) + Power(Mag30,2)*(-1191.32867001512223*Power(Mag12,6) + 186.145104689862849*Power(Mag12,4)*Power(Mag30,2)))));
  }

  double D_8_1_4() {
    return Power(Mag30,5)*(-315.898717946116394*Power(Mag12,11) + Power(Mag30,2)*(1474.19401708187651*Power(Mag12,9) + Power(Mag30,2)*(-1895.39230767669837*Power(Mag12,7) + Power(Mag30,2)*(789.74679486529099*Power(Mag12,5) - 87.749643873921221*Power(Mag12,3)*Power(Mag30,2)))));
  }

  double D_8_2_4() {
    return Power(Mag30,6)*(440.49971623146365*Power(Mag12,10) + Power(Mag30,2)*(-1510.28474136501823*Power(Mag12,8) + Power(Mag30,2)*(1415.89194502970459*Power(Mag12,6) + Power(Mag30,2)*(-419.523539268060619*Power(Mag12,4) + 31.4642654451045464*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_8_3_4() {
    return Power(Mag30,7)*(-511.23380169937903*Power(Mag12,9) + Power(Mag30,2)*(1278.08450424844757*Power(Mag12,7) + Power(Mag30,2)*(-852.05633616563171*Power(Mag12,5) + Power(Mag30,2)*(170.411267233126343*Power(Mag12,3) - 7.74596669241483377*Mag12*Power(Mag30,2)))));
  }

  double D_8_4_4() {
    return Power(Mag30,8)*(495.*Power(Mag12,8) + Power(Mag30,2)*(-880.*Power(Mag12,6) + Power(Mag30,2)*(396.*Power(Mag12,4) + Power(Mag30,2)*(-48.*Power(Mag12,2) + Power(Mag30,2)))));
  }

  double D_8_5_4() {
    return Power(Mag30,9)*(-396.610640301038822*Power(Mag12,7) + Power(Mag30,2)*(475.932768361246587*Power(Mag12,5) + Power(Mag30,2)*(-129.799845916703615*Power(Mag12,3) + 7.21110255092797859*Mag12*Power(Mag30,2))));
  }

  double D_8_6_4() {
    return Power(Mag30,10)*(257.033071802054297*Power(Mag12,6) + Power(Mag30,2)*(-186.933143128766762*Power(Mag12,4) + 23.3666428910958452*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_8_7_4() {
    return Power(Mag30,11)*(-127.984374046209251*Power(Mag12,5) + 42.6614580154030835*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_8_8_4() {
    return 42.6614580154030835*Power(Mag12,4)*Power(Mag30,12);
  }

  double D_8_neg8_5() {
    return -23.6643191323984642*Power(Mag12,13)*Power(Mag30,3);
  }

  double D_8_neg7_5() {
    return Power(Mag30,2)*(-17.7482393492988481*Power(Mag12,14) + 76.909037180295009*Power(Mag12,12)*Power(Mag30,2));
  }

  double D_8_neg6_5() {
    return Mag30*(-6.48074069840786023*Power(Mag12,15) + Power(Mag30,2)*(84.249629079302183*Power(Mag12,13) - 168.499258158604366*Power(Mag12,11)*Power(Mag30,2)));
  }

  double D_8_neg5_5() {
    return -1.*Power(Mag12,16) + Power(Mag30,2)*(39.*Power(Mag12,14) + Power(Mag30,2)*(-234.*Power(Mag12,12) + 286.*Power(Mag12,10)*Power(Mag30,2)));
  }

  double D_8_neg4_5() {
    return Mag30*(7.21110255092797859*Power(Mag12,15) + Power(Mag30,2)*(-129.799845916703615*Power(Mag12,13) + Power(Mag30,2)*(475.932768361246587*Power(Mag12,11) - 396.610640301038822*Power(Mag12,9)*Power(Mag30,2))));
  }

  double D_8_neg3_5() {
    return Power(Mag30,2)*(-27.9284800875378823*Power(Mag12,14) + Power(Mag30,2)*(307.213280962916706*Power(Mag12,12) + Power(Mag30,2)*(-768.03320240729176*Power(Mag12,10) + 460.819921444375059*Power(Mag12,8)*Power(Mag30,2))));
  }

  double D_8_neg2_5() {
    return Power(Mag30,3)*(75.630681604756148*Power(Mag12,13) + Power(Mag30,2)*(-567.23011203567111*Power(Mag12,11) + Power(Mag30,2)*(1021.014201664208*Power(Mag12,9) - 453.784089628536888*Power(Mag12,7)*Power(Mag30,2))));
  }

  double D_8_neg1_5() {
    return Power(Mag30,4)*(-158.192920195563746*Power(Mag12,12) + Power(Mag30,2)*(854.24176905604423*Power(Mag12,10) + Power(Mag30,2)*(-1138.98902540805897*Power(Mag12,8) + 379.66300846935299*Power(Mag12,6)*Power(Mag30,2))));
  }

  double D_8_0_5() {
    return Power(Mag30,5)*(268.462287854365124*Power(Mag12,11) + Power(Mag30,2)*(-1073.8491514174605*Power(Mag12,9) + Power(Mag30,2)*(1073.8491514174605*Power(Mag12,7) - 268.462287854365124*Power(Mag12,5)*Power(Mag30,2))));
  }

  double D_8_1_5() {
    return Power(Mag30,6)*(-379.66300846935299*Power(Mag12,10) + Power(Mag30,2)*(1138.98902540805897*Power(Mag12,8) + Power(Mag30,2)*(-854.24176905604423*Power(Mag12,6) + 158.192920195563746*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_8_2_5() {
    return Power(Mag30,7)*(453.784089628536888*Power(Mag12,9) + Power(Mag30,2)*(-1021.014201664208*Power(Mag12,7) + Power(Mag30,2)*(567.23011203567111*Power(Mag12,5) - 75.630681604756148*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_8_3_5() {
    return Power(Mag30,8)*(-460.819921444375059*Power(Mag12,8) + Power(Mag30,2)*(768.03320240729176*Power(Mag12,6) + Power(Mag30,2)*(-307.213280962916706*Power(Mag12,4) + 27.9284800875378823*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_8_4_5() {
    return Power(Mag30,9)*(396.610640301038822*Power(Mag12,7) + Power(Mag30,2)*(-475.932768361246587*Power(Mag12,5) + Power(Mag30,2)*(129.799845916703615*Power(Mag12,3) - 7.21110255092797859*Mag12*Power(Mag30,2))));
  }

  double D_8_5_5() {
    return Power(Mag30,10)*(-286.*Power(Mag12,6) + Power(Mag30,2)*(234.*Power(Mag12,4) + Power(Mag30,2)*(-39.*Power(Mag12,2) + Power(Mag30,2))));
  }

  double D_8_6_5() {
    return Power(Mag30,11)*(168.499258158604366*Power(Mag12,5) + Power(Mag30,2)*(-84.249629079302183*Power(Mag12,3) + 6.48074069840786023*Mag12*Power(Mag30,2)));
  }

  double D_8_7_5() {
    return Power(Mag30,12)*(-76.909037180295009*Power(Mag12,4) + 17.7482393492988481*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_8_8_5() {
    return 23.6643191323984642*Power(Mag12,3)*Power(Mag30,13);
  }

  double D_8_neg8_6() {
    return 10.9544511501033223*Power(Mag12,14)*Power(Mag30,2);
  }

  double D_8_neg7_6() {
    return Mag30*(5.47722557505166113*Power(Mag12,15) - 38.3405790253616279*Power(Mag12,13)*Power(Mag30,2));
  }

  double D_8_neg6_6() {
    return Power(Mag12,16) + Power(Mag30,2)*(-28.*Power(Mag12,14) + 91.*Power(Mag12,12)*Power(Mag30,2));
  }

  double D_8_neg5_6() {
    return Mag30*(-6.48074069840786023*Power(Mag12,15) + Power(Mag30,2)*(84.249629079302183*Power(Mag12,13) - 168.499258158604366*Power(Mag12,11)*Power(Mag30,2)));
  }

  double D_8_neg4_6() {
    return Power(Mag30,2)*(23.3666428910958452*Power(Mag12,14) + Power(Mag30,2)*(-186.933143128766762*Power(Mag12,12) + 257.033071802054297*Power(Mag12,10)*Power(Mag30,2)));
  }

  double D_8_neg3_6() {
    return Power(Mag30,3)*(-60.332412515993424*Power(Mag12,13) + Power(Mag30,2)*(331.828268837963834*Power(Mag12,11) - 331.828268837963834*Power(Mag12,9)*Power(Mag30,2)));
  }

  double D_8_neg2_6() {
    return Power(Mag30,4)*(122.535709081067467*Power(Mag12,12) + Power(Mag30,2)*(-490.142836324269866*Power(Mag12,10) + 367.6071272432024*Power(Mag12,8)*Power(Mag30,2)));
  }

  double D_8_neg1_6() {
    return Power(Mag30,5)*(-205.041459222275337*Power(Mag12,11) + Power(Mag30,2)*(615.12437766682601*Power(Mag12,9) - 351.499644381043436*Power(Mag12,7)*Power(Mag30,2)));
  }

  double D_8_0_6() {
    return Power(Mag30,6)*(289.972412480911708*Power(Mag12,10) + Power(Mag30,2)*(-662.79408567065533*Power(Mag12,8) + 289.972412480911708*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_8_1_6() {
    return Power(Mag30,7)*(-351.499644381043436*Power(Mag12,9) + Power(Mag30,2)*(615.12437766682601*Power(Mag12,7) - 205.041459222275337*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_8_2_6() {
    return Power(Mag30,8)*(367.6071272432024*Power(Mag12,8) + Power(Mag30,2)*(-490.142836324269866*Power(Mag12,6) + 122.535709081067467*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_8_3_6() {
    return Power(Mag30,9)*(-331.828268837963834*Power(Mag12,7) + Power(Mag30,2)*(331.828268837963834*Power(Mag12,5) - 60.332412515993424*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_8_4_6() {
    return Power(Mag30,10)*(257.033071802054297*Power(Mag12,6) + Power(Mag30,2)*(-186.933143128766762*Power(Mag12,4) + 23.3666428910958452*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_8_5_6() {
    return Power(Mag30,11)*(-168.499258158604366*Power(Mag12,5) + Power(Mag30,2)*(84.249629079302183*Power(Mag12,3) - 6.48074069840786023*Mag12*Power(Mag30,2)));
  }

  double D_8_6_6() {
    return Power(Mag30,12)*(91.*Power(Mag12,4) + Power(Mag30,2)*(-28.*Power(Mag12,2) + Power(Mag30,2)));
  }

  double D_8_7_6() {
    return Power(Mag30,13)*(-38.3405790253616279*Power(Mag12,3) + 5.47722557505166113*Mag12*Power(Mag30,2));
  }

  double D_8_8_6() {
    return 10.9544511501033223*Power(Mag12,2)*Power(Mag30,14);
  }

  double D_8_neg8_7() {
    return -4.*Power(Mag12,15)*Mag30;
  }

  double D_8_neg7_7() {
    return -1.*Power(Mag12,16) + 15.*Power(Mag12,14)*Power(Mag30,2);
  }

  double D_8_neg6_7() {
    return Mag30*(5.47722557505166113*Power(Mag12,15) - 38.3405790253616279*Power(Mag12,13)*Power(Mag30,2));
  }

  double D_8_neg5_7() {
    return Power(Mag30,2)*(-17.7482393492988481*Power(Mag12,14) + 76.909037180295009*Power(Mag12,12)*Power(Mag30,2));
  }

  double D_8_neg4_7() {
    return Power(Mag30,3)*(42.6614580154030835*Power(Mag12,13) - 127.984374046209251*Power(Mag12,11)*Power(Mag30,2));
  }

  double D_8_neg3_7() {
    return Power(Mag30,4)*(-82.61355820929153*Power(Mag12,12) + 181.749828060441367*Power(Mag12,10)*Power(Mag30,2));
  }

  double D_8_neg2_7() {
    return Power(Mag30,5)*(134.231143927182562*Power(Mag12,11) - 223.718573211970937*Power(Mag12,9)*Power(Mag30,2));
  }

  double D_8_neg1_7() {
    return Power(Mag30,6)*(-187.176387399693127*Power(Mag12,10) + 240.655355228176878*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_8_0_7() {
    return Power(Mag30,7)*(226.892044814268444*Power(Mag12,9) - 226.892044814268444*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_8_1_7() {
    return Power(Mag30,8)*(-240.655355228176878*Power(Mag12,8) + 187.176387399693127*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_8_2_7() {
    return Power(Mag30,9)*(223.718573211970937*Power(Mag12,7) - 134.231143927182562*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_8_3_7() {
    return Power(Mag30,10)*(-181.749828060441367*Power(Mag12,6) + 82.61355820929153*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_8_4_7() {
    return Power(Mag30,11)*(127.984374046209251*Power(Mag12,5) - 42.6614580154030835*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_8_5_7() {
    return Power(Mag30,12)*(-76.909037180295009*Power(Mag12,4) + 17.7482393492988481*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_8_6_7() {
    return Power(Mag30,13)*(38.3405790253616279*Power(Mag12,3) - 5.47722557505166113*Mag12*Power(Mag30,2));
  }

  double D_8_7_7() {
    return Power(Mag30,14)*(-15.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_8_8_7() {
    return 4.*Mag12*Power(Mag30,15);
  }

  double D_8_neg8_8() {
    return Power(Mag12,16);
  }

  double D_8_neg7_8() {
    return -4.*Power(Mag12,15)*Mag30;
  }

  double D_8_neg6_8() {
    return 10.9544511501033223*Power(Mag12,14)*Power(Mag30,2);
  }

  double D_8_neg5_8() {
    return -23.6643191323984642*Power(Mag12,13)*Power(Mag30,3);
  }

  double D_8_neg4_8() {
    return 42.6614580154030835*Power(Mag12,12)*Power(Mag30,4);
  }

  double D_8_neg3_8() {
    return -66.0908465674332242*Power(Mag12,11)*Power(Mag30,5);
  }

  double D_8_neg2_8() {
    return 89.4874292847883747*Power(Mag12,10)*Power(Mag30,6);
  }

  double D_8_neg1_8() {
    return -106.957935656967501*Power(Mag12,9)*Power(Mag30,7);
  }

  double D_8_0_8() {
    return 113.446022407134222*Power(Mag12,8)*Power(Mag30,8);
  }

  double D_8_1_8() {
    return -106.957935656967501*Power(Mag12,7)*Power(Mag30,9);
  }

  double D_8_2_8() {
    return 89.4874292847883747*Power(Mag12,6)*Power(Mag30,10);
  }

  double D_8_3_8() {
    return -66.0908465674332242*Power(Mag12,5)*Power(Mag30,11);
  }

  double D_8_4_8() {
    return 42.6614580154030835*Power(Mag12,4)*Power(Mag30,12);
  }

  double D_8_5_8() {
    return -23.6643191323984642*Power(Mag12,3)*Power(Mag30,13);
  }

  double D_8_6_8() {
    return 10.9544511501033223*Power(Mag12,2)*Power(Mag30,14);
  }

  double D_8_7_8() {
    return -4.*Mag12*Power(Mag30,15);
  }

  double D_8_8_8() {
    return Power(Mag30,16);
  }

  double D_7_neg7_neg7() {
    return Power(Mag30,14);
  }

  double D_7_neg6_neg7() {
    return 3.74165738677394139*Mag12*Power(Mag30,13);
  }

  double D_7_neg5_neg7() {
    return 9.53939201416945649*Power(Mag12,2)*Power(Mag30,12);
  }

  double D_7_neg4_neg7() {
    return 19.078784028338913*Power(Mag12,3)*Power(Mag30,11);
  }

  double D_7_neg3_neg7() {
    return 31.6385840391127491*Power(Mag12,4)*Power(Mag30,10);
  }

  double D_7_neg2_neg7() {
    return 44.7437146423941873*Power(Mag12,5)*Power(Mag30,9);
  }

  double D_7_neg1_neg7() {
    return 54.7996350352810288*Power(Mag12,6)*Power(Mag30,8);
  }

  double D_7_0_neg7() {
    return 58.5832740635072393*Power(Mag12,7)*Power(Mag30,7);
  }

  double D_7_1_neg7() {
    return 54.7996350352810288*Power(Mag12,8)*Power(Mag30,6);
  }

  double D_7_2_neg7() {
    return 44.7437146423941873*Power(Mag12,9)*Power(Mag30,5);
  }

  double D_7_3_neg7() {
    return 31.6385840391127491*Power(Mag12,10)*Power(Mag30,4);
  }

  double D_7_4_neg7() {
    return 19.078784028338913*Power(Mag12,11)*Power(Mag30,3);
  }

  double D_7_5_neg7() {
    return 9.53939201416945649*Power(Mag12,12)*Power(Mag30,2);
  }

  double D_7_6_neg7() {
    return 3.74165738677394139*Power(Mag12,13)*Mag30;
  }

  double D_7_7_neg7() {
    return Power(Mag12,14);
  }

  double D_7_neg7_neg6() {
    return -3.74165738677394139*Mag12*Power(Mag30,13);
  }

  double D_7_neg6_neg6() {
    return Power(Mag30,12)*(-13.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_7_neg5_neg6() {
    return Power(Mag30,11)*(-30.594117081556709*Power(Mag12,3) + 5.0990195135927848*Mag12*Power(Mag30,2));
  }

  double D_7_neg4_neg6() {
    return Power(Mag30,10)*(-56.089214649520633*Power(Mag12,4) + 15.2970585407783545*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_7_neg3_neg6() {
    return Power(Mag30,9)*(-84.557672626438814*Power(Mag12,5) + 33.8230690505755258*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_7_neg2_neg6() {
    return Power(Mag30,8)*(-107.624346687912582*Power(Mag12,6) + 59.79130371550699*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_7_neg1_neg6() {
    return Power(Mag30,7)*(-117.166548127014479*Power(Mag12,7) + 87.874911095260859*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_7_0_neg6() {
    return Power(Mag30,6)*(-109.599270070562058*Power(Mag12,8) + 109.599270070562058*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_7_1_neg6() {
    return Power(Mag30,5)*(-87.874911095260859*Power(Mag12,9) + 117.166548127014479*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_7_2_neg6() {
    return Power(Mag30,4)*(-59.79130371550699*Power(Mag12,10) + 107.624346687912582*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_7_3_neg6() {
    return Power(Mag30,3)*(-33.8230690505755258*Power(Mag12,11) + 84.557672626438814*Power(Mag12,9)*Power(Mag30,2));
  }

  double D_7_4_neg6() {
    return Power(Mag30,2)*(-15.2970585407783545*Power(Mag12,12) + 56.089214649520633*Power(Mag12,10)*Power(Mag30,2));
  }

  double D_7_5_neg6() {
    return Mag30*(-5.09901951359278483*Power(Mag12,13) + 30.594117081556709*Power(Mag12,11)*Power(Mag30,2));
  }

  double D_7_6_neg6() {
    return -1.*Power(Mag12,14) + 13.*Power(Mag12,12)*Power(Mag30,2);
  }

  double D_7_7_neg6() {
    return 3.74165738677394139*Power(Mag12,13)*Mag30;
  }

  double D_7_neg7_neg5() {
    return 9.53939201416945649*Power(Mag12,2)*Power(Mag30,12);
  }

  double D_7_neg6_neg5() {
    return Power(Mag30,11)*(30.594117081556709*Power(Mag12,3) - 5.0990195135927848*Mag12*Power(Mag30,2));
  }

  double D_7_neg5_neg5() {
    return Power(Mag30,10)*(66.*Power(Mag12,4) + Power(Mag30,2)*(-24.*Power(Mag12,2) + Power(Mag30,2)));
  }

  double D_7_neg4_neg5() {
    return Power(Mag30,9)*(110.*Power(Mag12,5) + Power(Mag30,2)*(-66.*Power(Mag12,3) + 6.*Mag12*Power(Mag30,2)));
  }

  double D_7_neg3_neg5() {
    return Power(Mag30,8)*(149.248115565992993*Power(Mag12,6) + Power(Mag30,2)*(-132.664991614215994*Power(Mag12,4) + 19.8997487421323991*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_7_neg2_neg5() {
    return Power(Mag30,7)*(168.854967353643464*Power(Mag12,7) + Power(Mag30,2)*(-211.06870919205433*Power(Mag12,5) + 46.9041575982342955*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_7_neg1_neg5() {
    return Power(Mag30,6)*(160.847754103064802*Power(Mag12,8) + Power(Mag30,2)*(-275.739007033825376*Power(Mag12,6) + 86.16843969807043*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_7_0_neg5() {
    return Power(Mag30,5)*(128.965111561228062*Power(Mag12,9) + Power(Mag30,2)*(-300.918593642865479*Power(Mag12,7) + 128.965111561228062*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_7_1_neg5() {
    return Power(Mag30,4)*(86.16843969807043*Power(Mag12,10) + Power(Mag30,2)*(-275.739007033825376*Power(Mag12,8) + 160.847754103064802*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_7_2_neg5() {
    return Power(Mag30,3)*(46.9041575982342955*Power(Mag12,11) + Power(Mag30,2)*(-211.06870919205433*Power(Mag12,9) + 168.854967353643464*Power(Mag12,7)*Power(Mag30,2)));
  }

  double D_7_3_neg5() {
    return Power(Mag30,2)*(19.8997487421323991*Power(Mag12,12) + Power(Mag30,2)*(-132.664991614215994*Power(Mag12,10) + 149.248115565992993*Power(Mag12,8)*Power(Mag30,2)));
  }

  double D_7_4_neg5() {
    return Mag30*(6.*Power(Mag12,13) + Power(Mag30,2)*(-66.*Power(Mag12,11) + 110.*Power(Mag12,9)*Power(Mag30,2)));
  }

  double D_7_5_neg5() {
    return Power(Mag12,14) + Power(Mag30,2)*(-24.*Power(Mag12,12) + 66.*Power(Mag12,10)*Power(Mag30,2));
  }

  double D_7_6_neg5() {
    return Mag30*(-5.09901951359278483*Power(Mag12,13) + 30.594117081556709*Power(Mag12,11)*Power(Mag30,2));
  }

  double D_7_7_neg5() {
    return 9.53939201416945649*Power(Mag12,12)*Power(Mag30,2);
  }

  double D_7_neg7_neg4() {
    return -19.078784028338913*Power(Mag12,3)*Power(Mag30,11);
  }

  double D_7_neg6_neg4() {
    return Power(Mag30,10)*(-56.089214649520633*Power(Mag12,4) + 15.2970585407783545*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_7_neg5_neg4() {
    return Power(Mag30,9)*(-110.*Power(Mag12,5) + Power(Mag30,2)*(66.*Power(Mag12,3) - 6.*Mag12*Power(Mag30,2)));
  }

  double D_7_neg4_neg4() {
    return Power(Mag30,8)*(-165.*Power(Mag12,6) + Power(Mag30,2)*(165.*Power(Mag12,4) + Power(Mag30,2)*(-33.*Power(Mag12,2) + Power(Mag30,2))));
  }

  double D_7_neg3_neg4() {
    return Power(Mag30,7)*(-198.997487421323991*Power(Mag12,7) + Power(Mag30,2)*(298.496231131985986*Power(Mag12,5) + Power(Mag30,2)*(-99.498743710661995*Power(Mag12,3) + 6.6332495807107997*Mag12*Power(Mag30,2))));
  }

  double D_7_neg2_neg4() {
    return Power(Mag30,6)*(-196.997461912584041*Power(Mag12,8) + Power(Mag30,2)*(422.13741838410866*Power(Mag12,6) + Power(Mag30,2)*(-211.06870919205433*Power(Mag12,4) + 23.4520787991171478*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_7_neg1_neg4() {
    return Power(Mag30,5)*(-160.847754103064802*Power(Mag12,9) + Power(Mag30,2)*(482.543262309194407*Power(Mag12,7) + Power(Mag30,2)*(-344.67375879228172*Power(Mag12,5) + 57.445626465380287*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_7_0_neg4() {
    return Power(Mag30,4)*(-107.470926301023385*Power(Mag12,10) + Power(Mag30,2)*(451.377890464298218*Power(Mag12,8) + Power(Mag30,2)*(-451.377890464298218*Power(Mag12,6) + 107.470926301023385*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_7_1_neg4() {
    return Power(Mag30,3)*(-57.445626465380287*Power(Mag12,11) + Power(Mag30,2)*(344.67375879228172*Power(Mag12,9) + Power(Mag30,2)*(-482.543262309194407*Power(Mag12,7) + 160.847754103064802*Power(Mag12,5)*Power(Mag30,2))));
  }

  double D_7_2_neg4() {
    return Power(Mag30,2)*(-23.4520787991171478*Power(Mag12,12) + Power(Mag30,2)*(211.06870919205433*Power(Mag12,10) + Power(Mag30,2)*(-422.13741838410866*Power(Mag12,8) + 196.997461912584041*Power(Mag12,6)*Power(Mag30,2))));
  }

  double D_7_3_neg4() {
    return Mag30*(-6.6332495807107997*Power(Mag12,13) + Power(Mag30,2)*(99.498743710661995*Power(Mag12,11) + Power(Mag30,2)*(-298.496231131985986*Power(Mag12,9) + 198.997487421323991*Power(Mag12,7)*Power(Mag30,2))));
  }

  double D_7_4_neg4() {
    return -1.*Power(Mag12,14) + Power(Mag30,2)*(33.*Power(Mag12,12) + Power(Mag30,2)*(-165.*Power(Mag12,10) + 165.*Power(Mag12,8)*Power(Mag30,2)));
  }

  double D_7_5_neg4() {
    return Mag30*(6.*Power(Mag12,13) + Power(Mag30,2)*(-66.*Power(Mag12,11) + 110.*Power(Mag12,9)*Power(Mag30,2)));
  }

  double D_7_6_neg4() {
    return Power(Mag30,2)*(-15.2970585407783545*Power(Mag12,12) + 56.089214649520633*Power(Mag12,10)*Power(Mag30,2));
  }

  double D_7_7_neg4() {
    return 19.078784028338913*Power(Mag12,11)*Power(Mag30,3);
  }

  double D_7_neg7_neg3() {
    return 31.6385840391127491*Power(Mag12,4)*Power(Mag30,10);
  }

  double D_7_neg6_neg3() {
    return Power(Mag30,9)*(84.557672626438814*Power(Mag12,5) - 33.8230690505755258*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_7_neg5_neg3() {
    return Power(Mag30,8)*(149.248115565992993*Power(Mag12,6) + Power(Mag30,2)*(-132.664991614215994*Power(Mag12,4) + 19.8997487421323991*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_7_neg4_neg3() {
    return Power(Mag30,7)*(198.997487421323991*Power(Mag12,7) + Power(Mag30,2)*(-298.496231131985986*Power(Mag12,5) + Power(Mag30,2)*(99.498743710661995*Power(Mag12,3) - 6.6332495807107997*Mag12*Power(Mag30,2))));
  }

  double D_7_neg3_neg3() {
    return Power(Mag30,6)*(210.*Power(Mag12,8) + Power(Mag30,2)*(-480.*Power(Mag12,6) + Power(Mag30,2)*(270.*Power(Mag12,4) + Power(Mag30,2)*(-40.*Power(Mag12,2) + Power(Mag30,2)))));
  }

  double D_7_neg2_neg3() {
    return Power(Mag30,5)*(178.190908859009976*Power(Mag12,9) + Power(Mag30,2)*(-593.96969619669992*Power(Mag12,7) + Power(Mag30,2)*(509.11688245431422*Power(Mag12,5) + Power(Mag30,2)*(-127.279220613578554*Power(Mag12,3) + 7.0710678118654752*Mag12*Power(Mag30,2)))));
  }

  double D_7_neg1_neg3() {
    return Power(Mag30,4)*(121.243556529821411*Power(Mag12,10) + Power(Mag30,2)*(-581.96907134314277*Power(Mag12,8) + Power(Mag30,2)*(727.46133917892846*Power(Mag12,6) + Power(Mag30,2)*(-277.128129211020367*Power(Mag12,4) + 25.9807621135331594*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_7_0_neg3() {
    return Power(Mag30,3)*(64.807406984078602*Power(Mag12,11) + Power(Mag30,2)*(-453.651848888550216*Power(Mag12,9) + Power(Mag30,2)*(816.57332799939039*Power(Mag12,7) + Power(Mag30,2)*(-453.651848888550216*Power(Mag12,5) + 64.807406984078602*Power(Mag12,3)*Power(Mag30,2)))));
  }

  double D_7_1_neg3() {
    return Power(Mag30,2)*(25.9807621135331594*Power(Mag12,12) + Power(Mag30,2)*(-277.128129211020367*Power(Mag12,10) + Power(Mag30,2)*(727.46133917892846*Power(Mag12,8) + Power(Mag30,2)*(-581.96907134314277*Power(Mag12,6) + 121.243556529821411*Power(Mag12,4)*Power(Mag30,2)))));
  }

  double D_7_2_neg3() {
    return Mag30*(7.0710678118654752*Power(Mag12,13) + Power(Mag30,2)*(-127.279220613578554*Power(Mag12,11) + Power(Mag30,2)*(509.11688245431422*Power(Mag12,9) + Power(Mag30,2)*(-593.96969619669992*Power(Mag12,7) + 178.190908859009976*Power(Mag12,5)*Power(Mag30,2)))));
  }

  double D_7_3_neg3() {
    return Power(Mag12,14) + Power(Mag30,2)*(-40.*Power(Mag12,12) + Power(Mag30,2)*(270.*Power(Mag12,10) + Power(Mag30,2)*(-480.*Power(Mag12,8) + 210.*Power(Mag12,6)*Power(Mag30,2))));
  }

  double D_7_4_neg3() {
    return Mag30*(-6.6332495807107997*Power(Mag12,13) + Power(Mag30,2)*(99.498743710661995*Power(Mag12,11) + Power(Mag30,2)*(-298.496231131985986*Power(Mag12,9) + 198.997487421323991*Power(Mag12,7)*Power(Mag30,2))));
  }

  double D_7_5_neg3() {
    return Power(Mag30,2)*(19.8997487421323991*Power(Mag12,12) + Power(Mag30,2)*(-132.664991614215994*Power(Mag12,10) + 149.248115565992993*Power(Mag12,8)*Power(Mag30,2)));
  }

  double D_7_6_neg3() {
    return Power(Mag30,3)*(-33.8230690505755258*Power(Mag12,11) + 84.557672626438814*Power(Mag12,9)*Power(Mag30,2));
  }

  double D_7_7_neg3() {
    return 31.6385840391127491*Power(Mag12,10)*Power(Mag30,4);
  }

  double D_7_neg7_neg2() {
    return -44.7437146423941873*Power(Mag12,5)*Power(Mag30,9);
  }

  double D_7_neg6_neg2() {
    return Power(Mag30,8)*(-107.624346687912582*Power(Mag12,6) + 59.79130371550699*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_7_neg5_neg2() {
    return Power(Mag30,7)*(-168.854967353643464*Power(Mag12,7) + Power(Mag30,2)*(211.06870919205433*Power(Mag12,5) - 46.9041575982342955*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_7_neg4_neg2() {
    return Power(Mag30,6)*(-196.997461912584041*Power(Mag12,8) + Power(Mag30,2)*(422.13741838410866*Power(Mag12,6) + Power(Mag30,2)*(-211.06870919205433*Power(Mag12,4) + 23.4520787991171478*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_7_neg3_neg2() {
    return Power(Mag30,5)*(-178.190908859009976*Power(Mag12,9) + Power(Mag30,2)*(593.96969619669992*Power(Mag12,7) + Power(Mag30,2)*(-509.11688245431422*Power(Mag12,5) + Power(Mag30,2)*(127.279220613578554*Power(Mag12,3) - 7.0710678118654752*Mag12*Power(Mag30,2)))));
  }

  double D_7_neg2_neg2() {
    return Power(Mag30,4)*(-126.*Power(Mag12,10) + Power(Mag30,2)*(630.*Power(Mag12,8) + Power(Mag30,2)*(-840.*Power(Mag12,6) + Power(Mag30,2)*(360.*Power(Mag12,4) + Power(Mag30,2)*(-45.*Power(Mag12,2) + Power(Mag30,2))))));
  }

  double D_7_neg1_neg2() {
    return Power(Mag30,3)*(-68.585712797928987*Power(Mag12,11) + Power(Mag30,2)*(514.3928459844674*Power(Mag12,9) + Power(Mag30,2)*(-1028.7856919689348*Power(Mag12,7) + Power(Mag30,2)*(685.85712797928987*Power(Mag12,5) + Power(Mag30,2)*(-146.969384566990686*Power(Mag12,3) + 7.3484692283495343*Mag12*Power(Mag30,2))))));
  }

  double D_7_0_neg2() {
    return Power(Mag30,2)*(-27.49545416973504*Power(Mag12,12) + Power(Mag30,2)*(320.7802986469088*Power(Mag12,10) + Power(Mag30,2)*(-962.3408959407264*Power(Mag12,8) + Power(Mag30,2)*(962.3408959407264*Power(Mag12,6) + Power(Mag30,2)*(-320.7802986469088*Power(Mag12,4) + 27.49545416973504*Power(Mag12,2)*Power(Mag30,2))))));
  }

  double D_7_1_neg2() {
    return Mag30*(-7.3484692283495343*Power(Mag12,13) + Power(Mag30,2)*(146.969384566990686*Power(Mag12,11) + Power(Mag30,2)*(-685.85712797928987*Power(Mag12,9) + Power(Mag30,2)*(1028.7856919689348*Power(Mag12,7) + Power(Mag30,2)*(-514.3928459844674*Power(Mag12,5) + 68.585712797928987*Power(Mag12,3)*Power(Mag30,2))))));
  }

  double D_7_2_neg2() {
    return -1.*Power(Mag12,14) + Power(Mag30,2)*(45.*Power(Mag12,12) + Power(Mag30,2)*(-360.*Power(Mag12,10) + Power(Mag30,2)*(840.*Power(Mag12,8) + Power(Mag30,2)*(-630.*Power(Mag12,6) + 126.*Power(Mag12,4)*Power(Mag30,2)))));
  }

  double D_7_3_neg2() {
    return Mag30*(7.0710678118654752*Power(Mag12,13) + Power(Mag30,2)*(-127.279220613578554*Power(Mag12,11) + Power(Mag30,2)*(509.11688245431422*Power(Mag12,9) + Power(Mag30,2)*(-593.96969619669992*Power(Mag12,7) + 178.190908859009976*Power(Mag12,5)*Power(Mag30,2)))));
  }

  double D_7_4_neg2() {
    return Power(Mag30,2)*(-23.4520787991171478*Power(Mag12,12) + Power(Mag30,2)*(211.06870919205433*Power(Mag12,10) + Power(Mag30,2)*(-422.13741838410866*Power(Mag12,8) + 196.997461912584041*Power(Mag12,6)*Power(Mag30,2))));
  }

  double D_7_5_neg2() {
    return Power(Mag30,3)*(46.9041575982342955*Power(Mag12,11) + Power(Mag30,2)*(-211.06870919205433*Power(Mag12,9) + 168.854967353643464*Power(Mag12,7)*Power(Mag30,2)));
  }

  double D_7_6_neg2() {
    return Power(Mag30,4)*(-59.79130371550699*Power(Mag12,10) + 107.624346687912582*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_7_7_neg2() {
    return 44.7437146423941873*Power(Mag12,9)*Power(Mag30,5);
  }

  double D_7_neg7_neg1() {
    return 54.7996350352810288*Power(Mag12,6)*Power(Mag30,8);
  }

  double D_7_neg6_neg1() {
    return Power(Mag30,7)*(117.166548127014479*Power(Mag12,7) - 87.874911095260859*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_7_neg5_neg1() {
    return Power(Mag30,6)*(160.847754103064802*Power(Mag12,8) + Power(Mag30,2)*(-275.739007033825376*Power(Mag12,6) + 86.16843969807043*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_7_neg4_neg1() {
    return Power(Mag30,5)*(160.847754103064802*Power(Mag12,9) + Power(Mag30,2)*(-482.543262309194407*Power(Mag12,7) + Power(Mag30,2)*(344.67375879228172*Power(Mag12,5) - 57.445626465380287*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_7_neg3_neg1() {
    return Power(Mag30,4)*(121.243556529821411*Power(Mag12,10) + Power(Mag30,2)*(-581.96907134314277*Power(Mag12,8) + Power(Mag30,2)*(727.46133917892846*Power(Mag12,6) + Power(Mag30,2)*(-277.128129211020367*Power(Mag12,4) + 25.9807621135331594*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_7_neg2_neg1() {
    return Power(Mag30,3)*(68.585712797928987*Power(Mag12,11) + Power(Mag30,2)*(-514.3928459844674*Power(Mag12,9) + Power(Mag30,2)*(1028.7856919689348*Power(Mag12,7) + Power(Mag30,2)*(-685.85712797928987*Power(Mag12,5) + Power(Mag30,2)*(146.969384566990686*Power(Mag12,3) - 7.3484692283495343*Mag12*Power(Mag30,2))))));
  }

  double D_7_neg1_neg1() {
    return Power(Mag30,2)*(28.*Power(Mag12,12) + Power(Mag30,2)*(-336.*Power(Mag12,10) + Power(Mag30,2)*(1050.*Power(Mag12,8) + Power(Mag30,2)*(-1120.*Power(Mag12,6) + Power(Mag30,2)*(420.*Power(Mag12,4) + Power(Mag30,2)*(-48.*Power(Mag12,2) + Power(Mag30,2)))))));
  }

  double D_7_0_neg1() {
    return Mag30*(7.48331477354788277*Power(Mag12,13) + Power(Mag30,2)*(-157.149610244505538*Power(Mag12,11) + Power(Mag30,2)*(785.74805122252769*Power(Mag12,9) + Power(Mag30,2)*(-1309.58008537087948*Power(Mag12,7) + Power(Mag30,2)*(785.74805122252769*Power(Mag12,5) + Power(Mag30,2)*(-157.149610244505538*Power(Mag12,3) + 7.48331477354788277*Mag12*Power(Mag30,2)))))));
  }

  double D_7_1_neg1() {
    return Power(Mag12,14) + Power(Mag30,2)*(-48.*Power(Mag12,12) + Power(Mag30,2)*(420.*Power(Mag12,10) + Power(Mag30,2)*(-1120.*Power(Mag12,8) + Power(Mag30,2)*(1050.*Power(Mag12,6) + Power(Mag30,2)*(-336.*Power(Mag12,4) + 28.*Power(Mag12,2)*Power(Mag30,2))))));
  }

  double D_7_2_neg1() {
    return Mag30*(-7.3484692283495343*Power(Mag12,13) + Power(Mag30,2)*(146.969384566990686*Power(Mag12,11) + Power(Mag30,2)*(-685.85712797928987*Power(Mag12,9) + Power(Mag30,2)*(1028.7856919689348*Power(Mag12,7) + Power(Mag30,2)*(-514.3928459844674*Power(Mag12,5) + 68.585712797928987*Power(Mag12,3)*Power(Mag30,2))))));
  }

  double D_7_3_neg1() {
    return Power(Mag30,2)*(25.9807621135331594*Power(Mag12,12) + Power(Mag30,2)*(-277.128129211020367*Power(Mag12,10) + Power(Mag30,2)*(727.46133917892846*Power(Mag12,8) + Power(Mag30,2)*(-581.96907134314277*Power(Mag12,6) + 121.243556529821411*Power(Mag12,4)*Power(Mag30,2)))));
  }

  double D_7_4_neg1() {
    return Power(Mag30,3)*(-57.445626465380287*Power(Mag12,11) + Power(Mag30,2)*(344.67375879228172*Power(Mag12,9) + Power(Mag30,2)*(-482.543262309194407*Power(Mag12,7) + 160.847754103064802*Power(Mag12,5)*Power(Mag30,2))));
  }

  double D_7_5_neg1() {
    return Power(Mag30,4)*(86.16843969807043*Power(Mag12,10) + Power(Mag30,2)*(-275.739007033825376*Power(Mag12,8) + 160.847754103064802*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_7_6_neg1() {
    return Power(Mag30,5)*(-87.874911095260859*Power(Mag12,9) + 117.166548127014479*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_7_7_neg1() {
    return 54.7996350352810288*Power(Mag12,8)*Power(Mag30,6);
  }

  double D_7_neg7_0() {
    return -58.5832740635072393*Power(Mag12,7)*Power(Mag30,7);
  }

  double D_7_neg6_0() {
    return Power(Mag30,6)*(-109.599270070562058*Power(Mag12,8) + 109.599270070562058*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_7_neg5_0() {
    return Power(Mag30,5)*(-128.965111561228062*Power(Mag12,9) + Power(Mag30,2)*(300.918593642865479*Power(Mag12,7) - 128.965111561228062*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_7_neg4_0() {
    return Power(Mag30,4)*(-107.470926301023385*Power(Mag12,10) + Power(Mag30,2)*(451.377890464298218*Power(Mag12,8) + Power(Mag30,2)*(-451.377890464298218*Power(Mag12,6) + 107.470926301023385*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_7_neg3_0() {
    return Power(Mag30,3)*(-64.807406984078602*Power(Mag12,11) + Power(Mag30,2)*(453.651848888550216*Power(Mag12,9) + Power(Mag30,2)*(-816.57332799939039*Power(Mag12,7) + Power(Mag30,2)*(453.651848888550216*Power(Mag12,5) - 64.807406984078602*Power(Mag12,3)*Power(Mag30,2)))));
  }

  double D_7_neg2_0() {
    return Power(Mag30,2)*(-27.49545416973504*Power(Mag12,12) + Power(Mag30,2)*(320.7802986469088*Power(Mag12,10) + Power(Mag30,2)*(-962.3408959407264*Power(Mag12,8) + Power(Mag30,2)*(962.3408959407264*Power(Mag12,6) + Power(Mag30,2)*(-320.7802986469088*Power(Mag12,4) + 27.49545416973504*Power(Mag12,2)*Power(Mag30,2))))));
  }

  double D_7_neg1_0() {
    return Mag30*(-7.48331477354788277*Power(Mag12,13) + Power(Mag30,2)*(157.149610244505538*Power(Mag12,11) + Power(Mag30,2)*(-785.74805122252769*Power(Mag12,9) + Power(Mag30,2)*(1309.58008537087948*Power(Mag12,7) + Power(Mag30,2)*(-785.74805122252769*Power(Mag12,5) + Power(Mag30,2)*(157.149610244505538*Power(Mag12,3) - 7.48331477354788277*Mag12*Power(Mag30,2)))))));
  }

  double D_7_0_0() {
    return -1.*Power(Mag12,14) + Power(Mag30,2)*(49.*Power(Mag12,12) + Power(Mag30,2)*(-441.*Power(Mag12,10) + Power(Mag30,2)*(1225.*Power(Mag12,8) + Power(Mag30,2)*(-1225.*Power(Mag12,6) + Power(Mag30,2)*(441.*Power(Mag12,4) + Power(Mag30,2)*(-49.*Power(Mag12,2) + Power(Mag30,2)))))));
  }

  double D_7_1_0() {
    return Mag30*(7.48331477354788277*Power(Mag12,13) + Power(Mag30,2)*(-157.149610244505538*Power(Mag12,11) + Power(Mag30,2)*(785.74805122252769*Power(Mag12,9) + Power(Mag30,2)*(-1309.58008537087948*Power(Mag12,7) + Power(Mag30,2)*(785.74805122252769*Power(Mag12,5) + Power(Mag30,2)*(-157.149610244505538*Power(Mag12,3) + 7.48331477354788277*Mag12*Power(Mag30,2)))))));
  }

  double D_7_2_0() {
    return Power(Mag30,2)*(-27.49545416973504*Power(Mag12,12) + Power(Mag30,2)*(320.7802986469088*Power(Mag12,10) + Power(Mag30,2)*(-962.3408959407264*Power(Mag12,8) + Power(Mag30,2)*(962.3408959407264*Power(Mag12,6) + Power(Mag30,2)*(-320.7802986469088*Power(Mag12,4) + 27.49545416973504*Power(Mag12,2)*Power(Mag30,2))))));
  }

  double D_7_3_0() {
    return Power(Mag30,3)*(64.807406984078602*Power(Mag12,11) + Power(Mag30,2)*(-453.651848888550216*Power(Mag12,9) + Power(Mag30,2)*(816.57332799939039*Power(Mag12,7) + Power(Mag30,2)*(-453.651848888550216*Power(Mag12,5) + 64.807406984078602*Power(Mag12,3)*Power(Mag30,2)))));
  }

  double D_7_4_0() {
    return Power(Mag30,4)*(-107.470926301023385*Power(Mag12,10) + Power(Mag30,2)*(451.377890464298218*Power(Mag12,8) + Power(Mag30,2)*(-451.377890464298218*Power(Mag12,6) + 107.470926301023385*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_7_5_0() {
    return Power(Mag30,5)*(128.965111561228062*Power(Mag12,9) + Power(Mag30,2)*(-300.918593642865479*Power(Mag12,7) + 128.965111561228062*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_7_6_0() {
    return Power(Mag30,6)*(-109.599270070562058*Power(Mag12,8) + 109.599270070562058*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_7_7_0() {
    return 58.5832740635072393*Power(Mag12,7)*Power(Mag30,7);
  }

  double D_7_neg7_1() {
    return 54.7996350352810288*Power(Mag12,8)*Power(Mag30,6);
  }

  double D_7_neg6_1() {
    return Power(Mag30,5)*(87.874911095260859*Power(Mag12,9) - 117.166548127014479*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_7_neg5_1() {
    return Power(Mag30,4)*(86.16843969807043*Power(Mag12,10) + Power(Mag30,2)*(-275.739007033825376*Power(Mag12,8) + 160.847754103064802*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_7_neg4_1() {
    return Power(Mag30,3)*(57.445626465380287*Power(Mag12,11) + Power(Mag30,2)*(-344.67375879228172*Power(Mag12,9) + Power(Mag30,2)*(482.543262309194407*Power(Mag12,7) - 160.847754103064802*Power(Mag12,5)*Power(Mag30,2))));
  }

  double D_7_neg3_1() {
    return Power(Mag30,2)*(25.9807621135331594*Power(Mag12,12) + Power(Mag30,2)*(-277.128129211020367*Power(Mag12,10) + Power(Mag30,2)*(727.46133917892846*Power(Mag12,8) + Power(Mag30,2)*(-581.96907134314277*Power(Mag12,6) + 121.243556529821411*Power(Mag12,4)*Power(Mag30,2)))));
  }

  double D_7_neg2_1() {
    return Mag30*(7.3484692283495343*Power(Mag12,13) + Power(Mag30,2)*(-146.969384566990686*Power(Mag12,11) + Power(Mag30,2)*(685.85712797928987*Power(Mag12,9) + Power(Mag30,2)*(-1028.7856919689348*Power(Mag12,7) + Power(Mag30,2)*(514.3928459844674*Power(Mag12,5) - 68.585712797928987*Power(Mag12,3)*Power(Mag30,2))))));
  }

  double D_7_neg1_1() {
    return Power(Mag12,14) + Power(Mag30,2)*(-48.*Power(Mag12,12) + Power(Mag30,2)*(420.*Power(Mag12,10) + Power(Mag30,2)*(-1120.*Power(Mag12,8) + Power(Mag30,2)*(1050.*Power(Mag12,6) + Power(Mag30,2)*(-336.*Power(Mag12,4) + 28.*Power(Mag12,2)*Power(Mag30,2))))));
  }

  double D_7_0_1() {
    return Mag30*(-7.48331477354788277*Power(Mag12,13) + Power(Mag30,2)*(157.149610244505538*Power(Mag12,11) + Power(Mag30,2)*(-785.74805122252769*Power(Mag12,9) + Power(Mag30,2)*(1309.58008537087948*Power(Mag12,7) + Power(Mag30,2)*(-785.74805122252769*Power(Mag12,5) + Power(Mag30,2)*(157.149610244505538*Power(Mag12,3) - 7.48331477354788277*Mag12*Power(Mag30,2)))))));
  }

  double D_7_1_1() {
    return Power(Mag30,2)*(28.*Power(Mag12,12) + Power(Mag30,2)*(-336.*Power(Mag12,10) + Power(Mag30,2)*(1050.*Power(Mag12,8) + Power(Mag30,2)*(-1120.*Power(Mag12,6) + Power(Mag30,2)*(420.*Power(Mag12,4) + Power(Mag30,2)*(-48.*Power(Mag12,2) + Power(Mag30,2)))))));
  }

  double D_7_2_1() {
    return Power(Mag30,3)*(-68.585712797928987*Power(Mag12,11) + Power(Mag30,2)*(514.3928459844674*Power(Mag12,9) + Power(Mag30,2)*(-1028.7856919689348*Power(Mag12,7) + Power(Mag30,2)*(685.85712797928987*Power(Mag12,5) + Power(Mag30,2)*(-146.969384566990686*Power(Mag12,3) + 7.3484692283495343*Mag12*Power(Mag30,2))))));
  }

  double D_7_3_1() {
    return Power(Mag30,4)*(121.243556529821411*Power(Mag12,10) + Power(Mag30,2)*(-581.96907134314277*Power(Mag12,8) + Power(Mag30,2)*(727.46133917892846*Power(Mag12,6) + Power(Mag30,2)*(-277.128129211020367*Power(Mag12,4) + 25.9807621135331594*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_7_4_1() {
    return Power(Mag30,5)*(-160.847754103064802*Power(Mag12,9) + Power(Mag30,2)*(482.543262309194407*Power(Mag12,7) + Power(Mag30,2)*(-344.67375879228172*Power(Mag12,5) + 57.445626465380287*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_7_5_1() {
    return Power(Mag30,6)*(160.847754103064802*Power(Mag12,8) + Power(Mag30,2)*(-275.739007033825376*Power(Mag12,6) + 86.16843969807043*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_7_6_1() {
    return Power(Mag30,7)*(-117.166548127014479*Power(Mag12,7) + 87.874911095260859*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_7_7_1() {
    return 54.7996350352810288*Power(Mag12,6)*Power(Mag30,8);
  }

  double D_7_neg7_2() {
    return -44.7437146423941873*Power(Mag12,9)*Power(Mag30,5);
  }

  double D_7_neg6_2() {
    return Power(Mag30,4)*(-59.79130371550699*Power(Mag12,10) + 107.624346687912582*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_7_neg5_2() {
    return Power(Mag30,3)*(-46.9041575982342955*Power(Mag12,11) + Power(Mag30,2)*(211.06870919205433*Power(Mag12,9) - 168.854967353643464*Power(Mag12,7)*Power(Mag30,2)));
  }

  double D_7_neg4_2() {
    return Power(Mag30,2)*(-23.4520787991171478*Power(Mag12,12) + Power(Mag30,2)*(211.06870919205433*Power(Mag12,10) + Power(Mag30,2)*(-422.13741838410866*Power(Mag12,8) + 196.997461912584041*Power(Mag12,6)*Power(Mag30,2))));
  }

  double D_7_neg3_2() {
    return Mag30*(-7.0710678118654752*Power(Mag12,13) + Power(Mag30,2)*(127.279220613578554*Power(Mag12,11) + Power(Mag30,2)*(-509.11688245431422*Power(Mag12,9) + Power(Mag30,2)*(593.96969619669992*Power(Mag12,7) - 178.190908859009976*Power(Mag12,5)*Power(Mag30,2)))));
  }

  double D_7_neg2_2() {
    return -1.*Power(Mag12,14) + Power(Mag30,2)*(45.*Power(Mag12,12) + Power(Mag30,2)*(-360.*Power(Mag12,10) + Power(Mag30,2)*(840.*Power(Mag12,8) + Power(Mag30,2)*(-630.*Power(Mag12,6) + 126.*Power(Mag12,4)*Power(Mag30,2)))));
  }

  double D_7_neg1_2() {
    return Mag30*(7.3484692283495343*Power(Mag12,13) + Power(Mag30,2)*(-146.969384566990686*Power(Mag12,11) + Power(Mag30,2)*(685.85712797928987*Power(Mag12,9) + Power(Mag30,2)*(-1028.7856919689348*Power(Mag12,7) + Power(Mag30,2)*(514.3928459844674*Power(Mag12,5) - 68.585712797928987*Power(Mag12,3)*Power(Mag30,2))))));
  }

  double D_7_0_2() {
    return Power(Mag30,2)*(-27.49545416973504*Power(Mag12,12) + Power(Mag30,2)*(320.7802986469088*Power(Mag12,10) + Power(Mag30,2)*(-962.3408959407264*Power(Mag12,8) + Power(Mag30,2)*(962.3408959407264*Power(Mag12,6) + Power(Mag30,2)*(-320.7802986469088*Power(Mag12,4) + 27.49545416973504*Power(Mag12,2)*Power(Mag30,2))))));
  }

  double D_7_1_2() {
    return Power(Mag30,3)*(68.585712797928987*Power(Mag12,11) + Power(Mag30,2)*(-514.3928459844674*Power(Mag12,9) + Power(Mag30,2)*(1028.7856919689348*Power(Mag12,7) + Power(Mag30,2)*(-685.85712797928987*Power(Mag12,5) + Power(Mag30,2)*(146.969384566990686*Power(Mag12,3) - 7.3484692283495343*Mag12*Power(Mag30,2))))));
  }

  double D_7_2_2() {
    return Power(Mag30,4)*(-126.*Power(Mag12,10) + Power(Mag30,2)*(630.*Power(Mag12,8) + Power(Mag30,2)*(-840.*Power(Mag12,6) + Power(Mag30,2)*(360.*Power(Mag12,4) + Power(Mag30,2)*(-45.*Power(Mag12,2) + Power(Mag30,2))))));
  }

  double D_7_3_2() {
    return Power(Mag30,5)*(178.190908859009976*Power(Mag12,9) + Power(Mag30,2)*(-593.96969619669992*Power(Mag12,7) + Power(Mag30,2)*(509.11688245431422*Power(Mag12,5) + Power(Mag30,2)*(-127.279220613578554*Power(Mag12,3) + 7.0710678118654752*Mag12*Power(Mag30,2)))));
  }

  double D_7_4_2() {
    return Power(Mag30,6)*(-196.997461912584041*Power(Mag12,8) + Power(Mag30,2)*(422.13741838410866*Power(Mag12,6) + Power(Mag30,2)*(-211.06870919205433*Power(Mag12,4) + 23.4520787991171478*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_7_5_2() {
    return Power(Mag30,7)*(168.854967353643464*Power(Mag12,7) + Power(Mag30,2)*(-211.06870919205433*Power(Mag12,5) + 46.9041575982342955*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_7_6_2() {
    return Power(Mag30,8)*(-107.624346687912582*Power(Mag12,6) + 59.79130371550699*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_7_7_2() {
    return 44.7437146423941873*Power(Mag12,5)*Power(Mag30,9);
  }

  double D_7_neg7_3() {
    return 31.6385840391127491*Power(Mag12,10)*Power(Mag30,4);
  }

  double D_7_neg6_3() {
    return Power(Mag30,3)*(33.8230690505755258*Power(Mag12,11) - 84.557672626438814*Power(Mag12,9)*Power(Mag30,2));
  }

  double D_7_neg5_3() {
    return Power(Mag30,2)*(19.8997487421323991*Power(Mag12,12) + Power(Mag30,2)*(-132.664991614215994*Power(Mag12,10) + 149.248115565992993*Power(Mag12,8)*Power(Mag30,2)));
  }

  double D_7_neg4_3() {
    return Mag30*(6.6332495807107997*Power(Mag12,13) + Power(Mag30,2)*(-99.498743710661995*Power(Mag12,11) + Power(Mag30,2)*(298.496231131985986*Power(Mag12,9) - 198.997487421323991*Power(Mag12,7)*Power(Mag30,2))));
  }

  double D_7_neg3_3() {
    return Power(Mag12,14) + Power(Mag30,2)*(-40.*Power(Mag12,12) + Power(Mag30,2)*(270.*Power(Mag12,10) + Power(Mag30,2)*(-480.*Power(Mag12,8) + 210.*Power(Mag12,6)*Power(Mag30,2))));
  }

  double D_7_neg2_3() {
    return Mag30*(-7.0710678118654752*Power(Mag12,13) + Power(Mag30,2)*(127.279220613578554*Power(Mag12,11) + Power(Mag30,2)*(-509.11688245431422*Power(Mag12,9) + Power(Mag30,2)*(593.96969619669992*Power(Mag12,7) - 178.190908859009976*Power(Mag12,5)*Power(Mag30,2)))));
  }

  double D_7_neg1_3() {
    return Power(Mag30,2)*(25.9807621135331594*Power(Mag12,12) + Power(Mag30,2)*(-277.128129211020367*Power(Mag12,10) + Power(Mag30,2)*(727.46133917892846*Power(Mag12,8) + Power(Mag30,2)*(-581.96907134314277*Power(Mag12,6) + 121.243556529821411*Power(Mag12,4)*Power(Mag30,2)))));
  }

  double D_7_0_3() {
    return Power(Mag30,3)*(-64.807406984078602*Power(Mag12,11) + Power(Mag30,2)*(453.651848888550216*Power(Mag12,9) + Power(Mag30,2)*(-816.57332799939039*Power(Mag12,7) + Power(Mag30,2)*(453.651848888550216*Power(Mag12,5) - 64.807406984078602*Power(Mag12,3)*Power(Mag30,2)))));
  }

  double D_7_1_3() {
    return Power(Mag30,4)*(121.243556529821411*Power(Mag12,10) + Power(Mag30,2)*(-581.96907134314277*Power(Mag12,8) + Power(Mag30,2)*(727.46133917892846*Power(Mag12,6) + Power(Mag30,2)*(-277.128129211020367*Power(Mag12,4) + 25.9807621135331594*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_7_2_3() {
    return Power(Mag30,5)*(-178.190908859009976*Power(Mag12,9) + Power(Mag30,2)*(593.96969619669992*Power(Mag12,7) + Power(Mag30,2)*(-509.11688245431422*Power(Mag12,5) + Power(Mag30,2)*(127.279220613578554*Power(Mag12,3) - 7.0710678118654752*Mag12*Power(Mag30,2)))));
  }

  double D_7_3_3() {
    return Power(Mag30,6)*(210.*Power(Mag12,8) + Power(Mag30,2)*(-480.*Power(Mag12,6) + Power(Mag30,2)*(270.*Power(Mag12,4) + Power(Mag30,2)*(-40.*Power(Mag12,2) + Power(Mag30,2)))));
  }

  double D_7_4_3() {
    return Power(Mag30,7)*(-198.997487421323991*Power(Mag12,7) + Power(Mag30,2)*(298.496231131985986*Power(Mag12,5) + Power(Mag30,2)*(-99.498743710661995*Power(Mag12,3) + 6.6332495807107997*Mag12*Power(Mag30,2))));
  }

  double D_7_5_3() {
    return Power(Mag30,8)*(149.248115565992993*Power(Mag12,6) + Power(Mag30,2)*(-132.664991614215994*Power(Mag12,4) + 19.8997487421323991*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_7_6_3() {
    return Power(Mag30,9)*(-84.557672626438814*Power(Mag12,5) + 33.8230690505755258*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_7_7_3() {
    return 31.6385840391127491*Power(Mag12,4)*Power(Mag30,10);
  }

  double D_7_neg7_4() {
    return -19.078784028338913*Power(Mag12,11)*Power(Mag30,3);
  }

  double D_7_neg6_4() {
    return Power(Mag30,2)*(-15.2970585407783545*Power(Mag12,12) + 56.089214649520633*Power(Mag12,10)*Power(Mag30,2));
  }

  double D_7_neg5_4() {
    return Mag30*(-6.*Power(Mag12,13) + Power(Mag30,2)*(66.*Power(Mag12,11) - 110.*Power(Mag12,9)*Power(Mag30,2)));
  }

  double D_7_neg4_4() {
    return -1.*Power(Mag12,14) + Power(Mag30,2)*(33.*Power(Mag12,12) + Power(Mag30,2)*(-165.*Power(Mag12,10) + 165.*Power(Mag12,8)*Power(Mag30,2)));
  }

  double D_7_neg3_4() {
    return Mag30*(6.6332495807107997*Power(Mag12,13) + Power(Mag30,2)*(-99.498743710661995*Power(Mag12,11) + Power(Mag30,2)*(298.496231131985986*Power(Mag12,9) - 198.997487421323991*Power(Mag12,7)*Power(Mag30,2))));
  }

  double D_7_neg2_4() {
    return Power(Mag30,2)*(-23.4520787991171478*Power(Mag12,12) + Power(Mag30,2)*(211.06870919205433*Power(Mag12,10) + Power(Mag30,2)*(-422.13741838410866*Power(Mag12,8) + 196.997461912584041*Power(Mag12,6)*Power(Mag30,2))));
  }

  double D_7_neg1_4() {
    return Power(Mag30,3)*(57.445626465380287*Power(Mag12,11) + Power(Mag30,2)*(-344.67375879228172*Power(Mag12,9) + Power(Mag30,2)*(482.543262309194407*Power(Mag12,7) - 160.847754103064802*Power(Mag12,5)*Power(Mag30,2))));
  }

  double D_7_0_4() {
    return Power(Mag30,4)*(-107.470926301023385*Power(Mag12,10) + Power(Mag30,2)*(451.377890464298218*Power(Mag12,8) + Power(Mag30,2)*(-451.377890464298218*Power(Mag12,6) + 107.470926301023385*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_7_1_4() {
    return Power(Mag30,5)*(160.847754103064802*Power(Mag12,9) + Power(Mag30,2)*(-482.543262309194407*Power(Mag12,7) + Power(Mag30,2)*(344.67375879228172*Power(Mag12,5) - 57.445626465380287*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_7_2_4() {
    return Power(Mag30,6)*(-196.997461912584041*Power(Mag12,8) + Power(Mag30,2)*(422.13741838410866*Power(Mag12,6) + Power(Mag30,2)*(-211.06870919205433*Power(Mag12,4) + 23.4520787991171478*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_7_3_4() {
    return Power(Mag30,7)*(198.997487421323991*Power(Mag12,7) + Power(Mag30,2)*(-298.496231131985986*Power(Mag12,5) + Power(Mag30,2)*(99.498743710661995*Power(Mag12,3) - 6.6332495807107997*Mag12*Power(Mag30,2))));
  }

  double D_7_4_4() {
    return Power(Mag30,8)*(-165.*Power(Mag12,6) + Power(Mag30,2)*(165.*Power(Mag12,4) + Power(Mag30,2)*(-33.*Power(Mag12,2) + Power(Mag30,2))));
  }

  double D_7_5_4() {
    return Power(Mag30,9)*(110.*Power(Mag12,5) + Power(Mag30,2)*(-66.*Power(Mag12,3) + 6.*Mag12*Power(Mag30,2)));
  }

  double D_7_6_4() {
    return Power(Mag30,10)*(-56.089214649520633*Power(Mag12,4) + 15.2970585407783545*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_7_7_4() {
    return 19.078784028338913*Power(Mag12,3)*Power(Mag30,11);
  }

  double D_7_neg7_5() {
    return 9.53939201416945649*Power(Mag12,12)*Power(Mag30,2);
  }

  double D_7_neg6_5() {
    return Mag30*(5.09901951359278483*Power(Mag12,13) - 30.594117081556709*Power(Mag12,11)*Power(Mag30,2));
  }

  double D_7_neg5_5() {
    return Power(Mag12,14) + Power(Mag30,2)*(-24.*Power(Mag12,12) + 66.*Power(Mag12,10)*Power(Mag30,2));
  }

  double D_7_neg4_5() {
    return Mag30*(-6.*Power(Mag12,13) + Power(Mag30,2)*(66.*Power(Mag12,11) - 110.*Power(Mag12,9)*Power(Mag30,2)));
  }

  double D_7_neg3_5() {
    return Power(Mag30,2)*(19.8997487421323991*Power(Mag12,12) + Power(Mag30,2)*(-132.664991614215994*Power(Mag12,10) + 149.248115565992993*Power(Mag12,8)*Power(Mag30,2)));
  }

  double D_7_neg2_5() {
    return Power(Mag30,3)*(-46.9041575982342955*Power(Mag12,11) + Power(Mag30,2)*(211.06870919205433*Power(Mag12,9) - 168.854967353643464*Power(Mag12,7)*Power(Mag30,2)));
  }

  double D_7_neg1_5() {
    return Power(Mag30,4)*(86.16843969807043*Power(Mag12,10) + Power(Mag30,2)*(-275.739007033825376*Power(Mag12,8) + 160.847754103064802*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_7_0_5() {
    return Power(Mag30,5)*(-128.965111561228062*Power(Mag12,9) + Power(Mag30,2)*(300.918593642865479*Power(Mag12,7) - 128.965111561228062*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_7_1_5() {
    return Power(Mag30,6)*(160.847754103064802*Power(Mag12,8) + Power(Mag30,2)*(-275.739007033825376*Power(Mag12,6) + 86.16843969807043*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_7_2_5() {
    return Power(Mag30,7)*(-168.854967353643464*Power(Mag12,7) + Power(Mag30,2)*(211.06870919205433*Power(Mag12,5) - 46.9041575982342955*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_7_3_5() {
    return Power(Mag30,8)*(149.248115565992993*Power(Mag12,6) + Power(Mag30,2)*(-132.664991614215994*Power(Mag12,4) + 19.8997487421323991*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_7_4_5() {
    return Power(Mag30,9)*(-110.*Power(Mag12,5) + Power(Mag30,2)*(66.*Power(Mag12,3) - 6.*Mag12*Power(Mag30,2)));
  }

  double D_7_5_5() {
    return Power(Mag30,10)*(66.*Power(Mag12,4) + Power(Mag30,2)*(-24.*Power(Mag12,2) + Power(Mag30,2)));
  }

  double D_7_6_5() {
    return Power(Mag30,11)*(-30.594117081556709*Power(Mag12,3) + 5.09901951359278483*Mag12*Power(Mag30,2));
  }

  double D_7_7_5() {
    return 9.53939201416945649*Power(Mag12,2)*Power(Mag30,12);
  }

  double D_7_neg7_6() {
    return -3.74165738677394139*Power(Mag12,13)*Mag30;
  }

  double D_7_neg6_6() {
    return -1.*Power(Mag12,14) + 13.*Power(Mag12,12)*Power(Mag30,2);
  }

  double D_7_neg5_6() {
    return Mag30*(5.09901951359278483*Power(Mag12,13) - 30.594117081556709*Power(Mag12,11)*Power(Mag30,2));
  }

  double D_7_neg4_6() {
    return Power(Mag30,2)*(-15.2970585407783545*Power(Mag12,12) + 56.089214649520633*Power(Mag12,10)*Power(Mag30,2));
  }

  double D_7_neg3_6() {
    return Power(Mag30,3)*(33.8230690505755258*Power(Mag12,11) - 84.557672626438814*Power(Mag12,9)*Power(Mag30,2));
  }

  double D_7_neg2_6() {
    return Power(Mag30,4)*(-59.79130371550699*Power(Mag12,10) + 107.624346687912582*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_7_neg1_6() {
    return Power(Mag30,5)*(87.874911095260859*Power(Mag12,9) - 117.166548127014479*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_7_0_6() {
    return Power(Mag30,6)*(-109.599270070562058*Power(Mag12,8) + 109.599270070562058*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_7_1_6() {
    return Power(Mag30,7)*(117.166548127014479*Power(Mag12,7) - 87.874911095260859*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_7_2_6() {
    return Power(Mag30,8)*(-107.624346687912582*Power(Mag12,6) + 59.79130371550699*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_7_3_6() {
    return Power(Mag30,9)*(84.557672626438814*Power(Mag12,5) - 33.8230690505755258*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_7_4_6() {
    return Power(Mag30,10)*(-56.089214649520633*Power(Mag12,4) + 15.2970585407783545*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_7_5_6() {
    return Power(Mag30,11)*(30.594117081556709*Power(Mag12,3) - 5.09901951359278483*Mag12*Power(Mag30,2));
  }

  double D_7_6_6() {
    return Power(Mag30,12)*(-13.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_7_7_6() {
    return 3.74165738677394139*Mag12*Power(Mag30,13);
  }

  double D_7_neg7_7() {
    return Power(Mag12,14);
  }

  double D_7_neg6_7() {
    return -3.74165738677394139*Power(Mag12,13)*Mag30;
  }

  double D_7_neg5_7() {
    return 9.53939201416945649*Power(Mag12,12)*Power(Mag30,2);
  }

  double D_7_neg4_7() {
    return -19.078784028338913*Power(Mag12,11)*Power(Mag30,3);
  }

  double D_7_neg3_7() {
    return 31.6385840391127491*Power(Mag12,10)*Power(Mag30,4);
  }

  double D_7_neg2_7() {
    return -44.7437146423941873*Power(Mag12,9)*Power(Mag30,5);
  }

  double D_7_neg1_7() {
    return 54.7996350352810288*Power(Mag12,8)*Power(Mag30,6);
  }

  double D_7_0_7() {
    return -58.5832740635072393*Power(Mag12,7)*Power(Mag30,7);
  }

  double D_7_1_7() {
    return 54.7996350352810288*Power(Mag12,6)*Power(Mag30,8);
  }

  double D_7_2_7() {
    return -44.7437146423941873*Power(Mag12,5)*Power(Mag30,9);
  }

  double D_7_3_7() {
    return 31.6385840391127491*Power(Mag12,4)*Power(Mag30,10);
  }

  double D_7_4_7() {
    return -19.078784028338913*Power(Mag12,3)*Power(Mag30,11);
  }

  double D_7_5_7() {
    return 9.53939201416945649*Power(Mag12,2)*Power(Mag30,12);
  }

  double D_7_6_7() {
    return -3.74165738677394139*Mag12*Power(Mag30,13);
  }

  double D_7_7_7() {
    return Power(Mag30,14);
  }

  double D_6_neg6_neg6() {
    return Power(Mag30,12);
  }

  double D_6_neg5_neg6() {
    return 3.46410161513775459*Mag12*Power(Mag30,11);
  }

  double D_6_neg4_neg6() {
    return 8.12403840463596036*Power(Mag12,2)*Power(Mag30,10);
  }

  double D_6_neg3_neg6() {
    return 14.8323969741913259*Power(Mag12,3)*Power(Mag30,9);
  }

  double D_6_neg2_neg6() {
    return 22.2485954612869888*Power(Mag12,4)*Power(Mag30,8);
  }

  double D_6_neg1_neg6() {
    return 28.1424945589405773*Power(Mag12,5)*Power(Mag30,7);
  }

  double D_6_0_neg6() {
    return 30.3973683071413273*Power(Mag12,6)*Power(Mag30,6);
  }

  double D_6_1_neg6() {
    return 28.1424945589405773*Power(Mag12,7)*Power(Mag30,5);
  }

  double D_6_2_neg6() {
    return 22.2485954612869888*Power(Mag12,8)*Power(Mag30,4);
  }

  double D_6_3_neg6() {
    return 14.8323969741913259*Power(Mag12,9)*Power(Mag30,3);
  }

  double D_6_4_neg6() {
    return 8.12403840463596036*Power(Mag12,10)*Power(Mag30,2);
  }

  double D_6_5_neg6() {
    return 3.46410161513775459*Power(Mag12,11)*Mag30;
  }

  double D_6_6_neg6() {
    return Power(Mag12,12);
  }

  double D_6_neg6_neg5() {
    return -3.46410161513775459*Mag12*Power(Mag30,11);
  }

  double D_6_neg5_neg5() {
    return Power(Mag30,10)*(-11.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_6_neg4_neg5() {
    return Power(Mag30,9)*(-23.4520787991171478*Power(Mag12,3) + 4.69041575982342955*Mag12*Power(Mag30,2));
  }

  double D_6_neg3_neg5() {
    return Power(Mag30,8)*(-38.5356977359953871*Power(Mag12,4) + 12.845232578665129*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_6_neg2_neg5() {
    return Power(Mag30,7)*(-51.380930314660516*Power(Mag12,5) + 25.690465157330258*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_6_neg1_neg5() {
    return Power(Mag30,6)*(-56.868268832451723*Power(Mag12,6) + 40.6201920231798018*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_6_0_neg5() {
    return Power(Mag30,5)*(-52.6497863243527324*Power(Mag12,7) + 52.649786324352732*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_6_1_neg5() {
    return Power(Mag30,4)*(-40.6201920231798018*Power(Mag12,8) + 56.868268832451723*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_6_2_neg5() {
    return Power(Mag30,3)*(-25.690465157330258*Power(Mag12,9) + 51.380930314660516*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_6_3_neg5() {
    return Power(Mag30,2)*(-12.845232578665129*Power(Mag12,10) + 38.5356977359953871*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_6_4_neg5() {
    return Mag30*(-4.69041575982342955*Power(Mag12,11) + 23.4520787991171478*Power(Mag12,9)*Power(Mag30,2));
  }

  double D_6_5_neg5() {
    return -1.*Power(Mag12,12) + 11.*Power(Mag12,10)*Power(Mag30,2);
  }

  double D_6_6_neg5() {
    return 3.46410161513775459*Power(Mag12,11)*Mag30;
  }

  double D_6_neg6_neg4() {
    return 8.12403840463596036*Power(Mag12,2)*Power(Mag30,10);
  }

  double D_6_neg5_neg4() {
    return Power(Mag30,9)*(23.4520787991171478*Power(Mag12,3) - 4.69041575982342955*Mag12*Power(Mag30,2));
  }

  double D_6_neg4_neg4() {
    return Power(Mag30,8)*(45.*Power(Mag12,4) + Power(Mag30,2)*(-20.*Power(Mag12,2) + Power(Mag30,2)));
  }

  double D_6_neg3_neg4() {
    return Power(Mag30,7)*(65.726706900619934*Power(Mag12,5) + Power(Mag30,2)*(-49.2950301754649502*Power(Mag12,3) + 5.47722557505166113*Mag12*Power(Mag30,2)));
  }

  double D_6_neg2_neg4() {
    return Power(Mag30,6)*(76.681158050723256*Power(Mag12,6) + Power(Mag30,2)*(-87.635609200826578*Power(Mag12,4) + 16.4316767251549834*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_6_neg1_neg4() {
    return Power(Mag30,5)*(72.746133917892846*Power(Mag12,7) + Power(Mag30,2)*(-121.243556529821411*Power(Mag12,5) + 34.6410161513775459*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_6_0_neg4() {
    return Power(Mag30,4)*(56.124860801609121*Power(Mag12,8) + Power(Mag30,2)*(-134.69966592386189*Power(Mag12,6) + 56.124860801609121*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_6_1_neg4() {
    return Power(Mag30,3)*(34.6410161513775459*Power(Mag12,9) + Power(Mag30,2)*(-121.243556529821411*Power(Mag12,7) + 72.746133917892846*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_6_2_neg4() {
    return Power(Mag30,2)*(16.4316767251549834*Power(Mag12,10) + Power(Mag30,2)*(-87.635609200826578*Power(Mag12,8) + 76.681158050723256*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_6_3_neg4() {
    return Mag30*(5.47722557505166113*Power(Mag12,11) + Power(Mag30,2)*(-49.2950301754649502*Power(Mag12,9) + 65.726706900619934*Power(Mag12,7)*Power(Mag30,2)));
  }

  double D_6_4_neg4() {
    return Power(Mag12,12) + Power(Mag30,2)*(-20.*Power(Mag12,10) + 45.*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_6_5_neg4() {
    return Mag30*(-4.69041575982342955*Power(Mag12,11) + 23.4520787991171478*Power(Mag12,9)*Power(Mag30,2));
  }

  double D_6_6_neg4() {
    return 8.12403840463596036*Power(Mag12,10)*Power(Mag30,2);
  }

  double D_6_neg6_neg3() {
    return -14.8323969741913259*Power(Mag12,3)*Power(Mag30,9);
  }

  double D_6_neg5_neg3() {
    return Power(Mag30,8)*(-38.5356977359953871*Power(Mag12,4) + 12.845232578665129*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_6_neg4_neg3() {
    return Power(Mag30,7)*(-65.726706900619934*Power(Mag12,5) + Power(Mag30,2)*(49.2950301754649502*Power(Mag12,3) - 5.47722557505166113*Mag12*Power(Mag30,2)));
  }

  double D_6_neg3_neg3() {
    return Power(Mag30,6)*(-84.*Power(Mag12,6) + Power(Mag30,2)*(108.*Power(Mag12,4) + Power(Mag30,2)*(-27.*Power(Mag12,2) + Power(Mag30,2))));
  }

  double D_6_neg2_neg3() {
    return Power(Mag30,5)*(-84.*Power(Mag12,7) + Power(Mag30,2)*(168.*Power(Mag12,5) + Power(Mag30,2)*(-72.*Power(Mag12,3) + 6.*Mag12*Power(Mag30,2))));
  }

  double D_6_neg1_neg3() {
    return Power(Mag30,4)*(-66.407830863535966*Power(Mag12,8) + Power(Mag30,2)*(199.223492590607898*Power(Mag12,6) + Power(Mag30,2)*(-132.815661727071932*Power(Mag12,4) + 18.973665961010276*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_6_0_neg3() {
    return Power(Mag30,3)*(-40.9878030638383935*Power(Mag12,9) + Power(Mag30,2)*(184.445113787272771*Power(Mag12,7) + Power(Mag30,2)*(-184.445113787272771*Power(Mag12,5) + 40.9878030638383935*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_6_1_neg3() {
    return Power(Mag30,2)*(-18.973665961010276*Power(Mag12,10) + Power(Mag30,2)*(132.815661727071932*Power(Mag12,8) + Power(Mag30,2)*(-199.223492590607898*Power(Mag12,6) + 66.407830863535966*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_6_2_neg3() {
    return Mag30*(-6.*Power(Mag12,11) + Power(Mag30,2)*(72.*Power(Mag12,9) + Power(Mag30,2)*(-168.*Power(Mag12,7) + 84.*Power(Mag12,5)*Power(Mag30,2))));
  }

  double D_6_3_neg3() {
    return -1.*Power(Mag12,12) + Power(Mag30,2)*(27.*Power(Mag12,10) + Power(Mag30,2)*(-108.*Power(Mag12,8) + 84.*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_6_4_neg3() {
    return Mag30*(5.47722557505166113*Power(Mag12,11) + Power(Mag30,2)*(-49.2950301754649502*Power(Mag12,9) + 65.726706900619934*Power(Mag12,7)*Power(Mag30,2)));
  }

  double D_6_5_neg3() {
    return Power(Mag30,2)*(-12.845232578665129*Power(Mag12,10) + 38.5356977359953871*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_6_6_neg3() {
    return 14.8323969741913259*Power(Mag12,9)*Power(Mag30,3);
  }

  double D_6_neg6_neg2() {
    return 22.2485954612869888*Power(Mag12,4)*Power(Mag30,8);
  }

  double D_6_neg5_neg2() {
    return Power(Mag30,7)*(51.380930314660516*Power(Mag12,5) - 25.690465157330258*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_6_neg4_neg2() {
    return Power(Mag30,6)*(76.681158050723256*Power(Mag12,6) + Power(Mag30,2)*(-87.635609200826578*Power(Mag12,4) + 16.4316767251549834*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_6_neg3_neg2() {
    return Power(Mag30,5)*(84.*Power(Mag12,7) + Power(Mag30,2)*(-168.*Power(Mag12,5) + Power(Mag30,2)*(72.*Power(Mag12,3) - 6.*Mag12*Power(Mag30,2))));
  }

  double D_6_neg2_neg2() {
    return Power(Mag30,4)*(70.*Power(Mag12,8) + Power(Mag30,2)*(-224.*Power(Mag12,6) + Power(Mag30,2)*(168.*Power(Mag12,4) + Power(Mag30,2)*(-32.*Power(Mag12,2) + Power(Mag30,2)))));
  }

  double D_6_neg1_neg2() {
    return Power(Mag30,3)*(44.2718872423573106*Power(Mag12,9) + Power(Mag30,2)*(-221.359436211786553*Power(Mag12,7) + Power(Mag30,2)*(265.631323454143864*Power(Mag12,5) + Power(Mag30,2)*(-88.543774484714621*Power(Mag12,3) + 6.32455532033675866*Mag12*Power(Mag30,2)))));
  }

  double D_6_0_neg2() {
    return Power(Mag30,2)*(20.4939015319191968*Power(Mag12,10) + Power(Mag30,2)*(-163.951212255353574*Power(Mag12,8) + Power(Mag30,2)*(307.408522978787951*Power(Mag12,6) + Power(Mag30,2)*(-163.951212255353574*Power(Mag12,4) + 20.4939015319191968*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_6_1_neg2() {
    return Mag30*(6.32455532033675866*Power(Mag12,11) + Power(Mag30,2)*(-88.543774484714621*Power(Mag12,9) + Power(Mag30,2)*(265.631323454143864*Power(Mag12,7) + Power(Mag30,2)*(-221.359436211786553*Power(Mag12,5) + 44.2718872423573106*Power(Mag12,3)*Power(Mag30,2)))));
  }

  double D_6_2_neg2() {
    return Power(Mag12,12) + Power(Mag30,2)*(-32.*Power(Mag12,10) + Power(Mag30,2)*(168.*Power(Mag12,8) + Power(Mag30,2)*(-224.*Power(Mag12,6) + 70.*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_6_3_neg2() {
    return Mag30*(-6.*Power(Mag12,11) + Power(Mag30,2)*(72.*Power(Mag12,9) + Power(Mag30,2)*(-168.*Power(Mag12,7) + 84.*Power(Mag12,5)*Power(Mag30,2))));
  }

  double D_6_4_neg2() {
    return Power(Mag30,2)*(16.4316767251549834*Power(Mag12,10) + Power(Mag30,2)*(-87.635609200826578*Power(Mag12,8) + 76.681158050723256*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_6_5_neg2() {
    return Power(Mag30,3)*(-25.690465157330258*Power(Mag12,9) + 51.380930314660516*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_6_6_neg2() {
    return 22.2485954612869888*Power(Mag12,8)*Power(Mag30,4);
  }

  double D_6_neg6_neg1() {
    return -28.1424945589405773*Power(Mag12,5)*Power(Mag30,7);
  }

  double D_6_neg5_neg1() {
    return Power(Mag30,6)*(-56.868268832451723*Power(Mag12,6) + 40.6201920231798018*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_6_neg4_neg1() {
    return Power(Mag30,5)*(-72.746133917892846*Power(Mag12,7) + Power(Mag30,2)*(121.243556529821411*Power(Mag12,5) - 34.6410161513775459*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_6_neg3_neg1() {
    return Power(Mag30,4)*(-66.407830863535966*Power(Mag12,8) + Power(Mag30,2)*(199.223492590607898*Power(Mag12,6) + Power(Mag30,2)*(-132.815661727071932*Power(Mag12,4) + 18.973665961010276*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_6_neg2_neg1() {
    return Power(Mag30,3)*(-44.2718872423573106*Power(Mag12,9) + Power(Mag30,2)*(221.359436211786553*Power(Mag12,7) + Power(Mag30,2)*(-265.631323454143864*Power(Mag12,5) + Power(Mag30,2)*(88.543774484714621*Power(Mag12,3) - 6.32455532033675866*Mag12*Power(Mag30,2)))));
  }

  double D_6_neg1_neg1() {
    return Power(Mag30,2)*(-21.*Power(Mag12,10) + Power(Mag30,2)*(175.*Power(Mag12,8) + Power(Mag30,2)*(-350.*Power(Mag12,6) + Power(Mag30,2)*(210.*Power(Mag12,4) + Power(Mag30,2)*(-35.*Power(Mag12,2) + Power(Mag30,2))))));
  }

  double D_6_0_neg1() {
    return Mag30*(-6.48074069840786023*Power(Mag12,11) + Power(Mag30,2)*(97.211110476117903*Power(Mag12,9) + Power(Mag30,2)*(-324.037034920393012*Power(Mag12,7) + Power(Mag30,2)*(324.037034920393012*Power(Mag12,5) + Power(Mag30,2)*(-97.211110476117903*Power(Mag12,3) + 6.4807406984078602*Mag12*Power(Mag30,2))))));
  }

  double D_6_1_neg1() {
    return -1.*Power(Mag12,12) + Power(Mag30,2)*(35.*Power(Mag12,10) + Power(Mag30,2)*(-210.*Power(Mag12,8) + Power(Mag30,2)*(350.*Power(Mag12,6) + Power(Mag30,2)*(-175.*Power(Mag12,4) + 21.*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_6_2_neg1() {
    return Mag30*(6.32455532033675866*Power(Mag12,11) + Power(Mag30,2)*(-88.543774484714621*Power(Mag12,9) + Power(Mag30,2)*(265.631323454143864*Power(Mag12,7) + Power(Mag30,2)*(-221.359436211786553*Power(Mag12,5) + 44.2718872423573106*Power(Mag12,3)*Power(Mag30,2)))));
  }

  double D_6_3_neg1() {
    return Power(Mag30,2)*(-18.973665961010276*Power(Mag12,10) + Power(Mag30,2)*(132.815661727071932*Power(Mag12,8) + Power(Mag30,2)*(-199.223492590607898*Power(Mag12,6) + 66.407830863535966*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_6_4_neg1() {
    return Power(Mag30,3)*(34.6410161513775459*Power(Mag12,9) + Power(Mag30,2)*(-121.243556529821411*Power(Mag12,7) + 72.746133917892846*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_6_5_neg1() {
    return Power(Mag30,4)*(-40.6201920231798018*Power(Mag12,8) + 56.868268832451723*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_6_6_neg1() {
    return 28.1424945589405773*Power(Mag12,7)*Power(Mag30,5);
  }

  double D_6_neg6_0() {
    return 30.3973683071413273*Power(Mag12,6)*Power(Mag30,6);
  }

  double D_6_neg5_0() {
    return Power(Mag30,5)*(52.6497863243527324*Power(Mag12,7) - 52.649786324352732*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_6_neg4_0() {
    return Power(Mag30,4)*(56.124860801609121*Power(Mag12,8) + Power(Mag30,2)*(-134.69966592386189*Power(Mag12,6) + 56.124860801609121*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_6_neg3_0() {
    return Power(Mag30,3)*(40.9878030638383935*Power(Mag12,9) + Power(Mag30,2)*(-184.445113787272771*Power(Mag12,7) + Power(Mag30,2)*(184.445113787272771*Power(Mag12,5) - 40.9878030638383935*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_6_neg2_0() {
    return Power(Mag30,2)*(20.4939015319191968*Power(Mag12,10) + Power(Mag30,2)*(-163.951212255353574*Power(Mag12,8) + Power(Mag30,2)*(307.408522978787951*Power(Mag12,6) + Power(Mag30,2)*(-163.951212255353574*Power(Mag12,4) + 20.4939015319191968*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_6_neg1_0() {
    return Mag30*(6.48074069840786023*Power(Mag12,11) + Power(Mag30,2)*(-97.211110476117903*Power(Mag12,9) + Power(Mag30,2)*(324.037034920393012*Power(Mag12,7) + Power(Mag30,2)*(-324.037034920393012*Power(Mag12,5) + Power(Mag30,2)*(97.211110476117903*Power(Mag12,3) - 6.4807406984078602*Mag12*Power(Mag30,2))))));
  }

  double D_6_0_0() {
    return Power(Mag12,12) + Power(Mag30,2)*(-36.*Power(Mag12,10) + Power(Mag30,2)*(225.*Power(Mag12,8) + Power(Mag30,2)*(-400.*Power(Mag12,6) + Power(Mag30,2)*(225.*Power(Mag12,4) + Power(Mag30,2)*(-36.*Power(Mag12,2) + Power(Mag30,2))))));
  }

  double D_6_1_0() {
    return Mag30*(-6.48074069840786023*Power(Mag12,11) + Power(Mag30,2)*(97.211110476117903*Power(Mag12,9) + Power(Mag30,2)*(-324.037034920393012*Power(Mag12,7) + Power(Mag30,2)*(324.037034920393012*Power(Mag12,5) + Power(Mag30,2)*(-97.211110476117903*Power(Mag12,3) + 6.4807406984078602*Mag12*Power(Mag30,2))))));
  }

  double D_6_2_0() {
    return Power(Mag30,2)*(20.4939015319191968*Power(Mag12,10) + Power(Mag30,2)*(-163.951212255353574*Power(Mag12,8) + Power(Mag30,2)*(307.408522978787951*Power(Mag12,6) + Power(Mag30,2)*(-163.951212255353574*Power(Mag12,4) + 20.4939015319191968*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_6_3_0() {
    return Power(Mag30,3)*(-40.9878030638383935*Power(Mag12,9) + Power(Mag30,2)*(184.445113787272771*Power(Mag12,7) + Power(Mag30,2)*(-184.445113787272771*Power(Mag12,5) + 40.9878030638383935*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_6_4_0() {
    return Power(Mag30,4)*(56.124860801609121*Power(Mag12,8) + Power(Mag30,2)*(-134.69966592386189*Power(Mag12,6) + 56.124860801609121*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_6_5_0() {
    return Power(Mag30,5)*(-52.649786324352732*Power(Mag12,7) + 52.6497863243527324*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_6_6_0() {
    return 30.3973683071413273*Power(Mag12,6)*Power(Mag30,6);
  }

  double D_6_neg6_1() {
    return -28.1424945589405773*Power(Mag12,7)*Power(Mag30,5);
  }

  double D_6_neg5_1() {
    return Power(Mag30,4)*(-40.6201920231798018*Power(Mag12,8) + 56.868268832451723*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_6_neg4_1() {
    return Power(Mag30,3)*(-34.6410161513775459*Power(Mag12,9) + Power(Mag30,2)*(121.243556529821411*Power(Mag12,7) - 72.746133917892846*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_6_neg3_1() {
    return Power(Mag30,2)*(-18.973665961010276*Power(Mag12,10) + Power(Mag30,2)*(132.815661727071932*Power(Mag12,8) + Power(Mag30,2)*(-199.223492590607898*Power(Mag12,6) + 66.407830863535966*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_6_neg2_1() {
    return Mag30*(-6.32455532033675866*Power(Mag12,11) + Power(Mag30,2)*(88.543774484714621*Power(Mag12,9) + Power(Mag30,2)*(-265.631323454143864*Power(Mag12,7) + Power(Mag30,2)*(221.359436211786553*Power(Mag12,5) - 44.2718872423573106*Power(Mag12,3)*Power(Mag30,2)))));
  }

  double D_6_neg1_1() {
    return -1.*Power(Mag12,12) + Power(Mag30,2)*(35.*Power(Mag12,10) + Power(Mag30,2)*(-210.*Power(Mag12,8) + Power(Mag30,2)*(350.*Power(Mag12,6) + Power(Mag30,2)*(-175.*Power(Mag12,4) + 21.*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_6_0_1() {
    return Mag30*(6.4807406984078602*Power(Mag12,11) + Power(Mag30,2)*(-97.211110476117903*Power(Mag12,9) + Power(Mag30,2)*(324.037034920393012*Power(Mag12,7) + Power(Mag30,2)*(-324.037034920393012*Power(Mag12,5) + Power(Mag30,2)*(97.211110476117903*Power(Mag12,3) - 6.48074069840786023*Mag12*Power(Mag30,2))))));
  }

  double D_6_1_1() {
    return Power(Mag30,2)*(-21.*Power(Mag12,10) + Power(Mag30,2)*(175.*Power(Mag12,8) + Power(Mag30,2)*(-350.*Power(Mag12,6) + Power(Mag30,2)*(210.*Power(Mag12,4) + Power(Mag30,2)*(-35.*Power(Mag12,2) + Power(Mag30,2))))));
  }

  double D_6_2_1() {
    return Power(Mag30,3)*(44.2718872423573106*Power(Mag12,9) + Power(Mag30,2)*(-221.359436211786553*Power(Mag12,7) + Power(Mag30,2)*(265.631323454143864*Power(Mag12,5) + Power(Mag30,2)*(-88.543774484714621*Power(Mag12,3) + 6.32455532033675866*Mag12*Power(Mag30,2)))));
  }

  double D_6_3_1() {
    return Power(Mag30,4)*(-66.407830863535966*Power(Mag12,8) + Power(Mag30,2)*(199.223492590607898*Power(Mag12,6) + Power(Mag30,2)*(-132.815661727071932*Power(Mag12,4) + 18.973665961010276*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_6_4_1() {
    return Power(Mag30,5)*(72.746133917892846*Power(Mag12,7) + Power(Mag30,2)*(-121.243556529821411*Power(Mag12,5) + 34.6410161513775459*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_6_5_1() {
    return Power(Mag30,6)*(-56.868268832451723*Power(Mag12,6) + 40.6201920231798018*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_6_6_1() {
    return 28.1424945589405773*Power(Mag12,5)*Power(Mag30,7);
  }

  double D_6_neg6_2() {
    return 22.2485954612869888*Power(Mag12,8)*Power(Mag30,4);
  }

  double D_6_neg5_2() {
    return Power(Mag30,3)*(25.690465157330258*Power(Mag12,9) - 51.380930314660516*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_6_neg4_2() {
    return Power(Mag30,2)*(16.4316767251549834*Power(Mag12,10) + Power(Mag30,2)*(-87.635609200826578*Power(Mag12,8) + 76.681158050723256*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_6_neg3_2() {
    return Mag30*(6.*Power(Mag12,11) + Power(Mag30,2)*(-72.*Power(Mag12,9) + Power(Mag30,2)*(168.*Power(Mag12,7) - 84.*Power(Mag12,5)*Power(Mag30,2))));
  }

  double D_6_neg2_2() {
    return Power(Mag12,12) + Power(Mag30,2)*(-32.*Power(Mag12,10) + Power(Mag30,2)*(168.*Power(Mag12,8) + Power(Mag30,2)*(-224.*Power(Mag12,6) + 70.*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_6_neg1_2() {
    return Mag30*(-6.32455532033675866*Power(Mag12,11) + Power(Mag30,2)*(88.543774484714621*Power(Mag12,9) + Power(Mag30,2)*(-265.631323454143864*Power(Mag12,7) + Power(Mag30,2)*(221.359436211786553*Power(Mag12,5) - 44.2718872423573106*Power(Mag12,3)*Power(Mag30,2)))));
  }

  double D_6_0_2() {
    return Power(Mag30,2)*(20.4939015319191968*Power(Mag12,10) + Power(Mag30,2)*(-163.951212255353574*Power(Mag12,8) + Power(Mag30,2)*(307.408522978787951*Power(Mag12,6) + Power(Mag30,2)*(-163.951212255353574*Power(Mag12,4) + 20.4939015319191968*Power(Mag12,2)*Power(Mag30,2)))));
  }

  double D_6_1_2() {
    return Power(Mag30,3)*(-44.2718872423573106*Power(Mag12,9) + Power(Mag30,2)*(221.359436211786553*Power(Mag12,7) + Power(Mag30,2)*(-265.631323454143864*Power(Mag12,5) + Power(Mag30,2)*(88.543774484714621*Power(Mag12,3) - 6.32455532033675866*Mag12*Power(Mag30,2)))));
  }

  double D_6_2_2() {
    return Power(Mag30,4)*(70.*Power(Mag12,8) + Power(Mag30,2)*(-224.*Power(Mag12,6) + Power(Mag30,2)*(168.*Power(Mag12,4) + Power(Mag30,2)*(-32.*Power(Mag12,2) + Power(Mag30,2)))));
  }

  double D_6_3_2() {
    return Power(Mag30,5)*(-84.*Power(Mag12,7) + Power(Mag30,2)*(168.*Power(Mag12,5) + Power(Mag30,2)*(-72.*Power(Mag12,3) + 6.*Mag12*Power(Mag30,2))));
  }

  double D_6_4_2() {
    return Power(Mag30,6)*(76.681158050723256*Power(Mag12,6) + Power(Mag30,2)*(-87.635609200826578*Power(Mag12,4) + 16.4316767251549834*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_6_5_2() {
    return Power(Mag30,7)*(-51.380930314660516*Power(Mag12,5) + 25.690465157330258*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_6_6_2() {
    return 22.2485954612869888*Power(Mag12,4)*Power(Mag30,8);
  }

  double D_6_neg6_3() {
    return -14.8323969741913259*Power(Mag12,9)*Power(Mag30,3);
  }

  double D_6_neg5_3() {
    return Power(Mag30,2)*(-12.845232578665129*Power(Mag12,10) + 38.5356977359953871*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_6_neg4_3() {
    return Mag30*(-5.47722557505166113*Power(Mag12,11) + Power(Mag30,2)*(49.2950301754649502*Power(Mag12,9) - 65.726706900619934*Power(Mag12,7)*Power(Mag30,2)));
  }

  double D_6_neg3_3() {
    return -1.*Power(Mag12,12) + Power(Mag30,2)*(27.*Power(Mag12,10) + Power(Mag30,2)*(-108.*Power(Mag12,8) + 84.*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_6_neg2_3() {
    return Mag30*(6.*Power(Mag12,11) + Power(Mag30,2)*(-72.*Power(Mag12,9) + Power(Mag30,2)*(168.*Power(Mag12,7) - 84.*Power(Mag12,5)*Power(Mag30,2))));
  }

  double D_6_neg1_3() {
    return Power(Mag30,2)*(-18.973665961010276*Power(Mag12,10) + Power(Mag30,2)*(132.815661727071932*Power(Mag12,8) + Power(Mag30,2)*(-199.223492590607898*Power(Mag12,6) + 66.407830863535966*Power(Mag12,4)*Power(Mag30,2))));
  }

  double D_6_0_3() {
    return Power(Mag30,3)*(40.9878030638383935*Power(Mag12,9) + Power(Mag30,2)*(-184.445113787272771*Power(Mag12,7) + Power(Mag30,2)*(184.445113787272771*Power(Mag12,5) - 40.9878030638383935*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_6_1_3() {
    return Power(Mag30,4)*(-66.407830863535966*Power(Mag12,8) + Power(Mag30,2)*(199.223492590607898*Power(Mag12,6) + Power(Mag30,2)*(-132.815661727071932*Power(Mag12,4) + 18.973665961010276*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_6_2_3() {
    return Power(Mag30,5)*(84.*Power(Mag12,7) + Power(Mag30,2)*(-168.*Power(Mag12,5) + Power(Mag30,2)*(72.*Power(Mag12,3) - 6.*Mag12*Power(Mag30,2))));
  }

  double D_6_3_3() {
    return Power(Mag30,6)*(-84.*Power(Mag12,6) + Power(Mag30,2)*(108.*Power(Mag12,4) + Power(Mag30,2)*(-27.*Power(Mag12,2) + Power(Mag30,2))));
  }

  double D_6_4_3() {
    return Power(Mag30,7)*(65.726706900619934*Power(Mag12,5) + Power(Mag30,2)*(-49.2950301754649502*Power(Mag12,3) + 5.47722557505166113*Mag12*Power(Mag30,2)));
  }

  double D_6_5_3() {
    return Power(Mag30,8)*(-38.5356977359953871*Power(Mag12,4) + 12.845232578665129*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_6_6_3() {
    return 14.8323969741913259*Power(Mag12,3)*Power(Mag30,9);
  }

  double D_6_neg6_4() {
    return 8.12403840463596036*Power(Mag12,10)*Power(Mag30,2);
  }

  double D_6_neg5_4() {
    return Mag30*(4.69041575982342955*Power(Mag12,11) - 23.4520787991171478*Power(Mag12,9)*Power(Mag30,2));
  }

  double D_6_neg4_4() {
    return Power(Mag12,12) + Power(Mag30,2)*(-20.*Power(Mag12,10) + 45.*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_6_neg3_4() {
    return Mag30*(-5.47722557505166113*Power(Mag12,11) + Power(Mag30,2)*(49.2950301754649502*Power(Mag12,9) - 65.726706900619934*Power(Mag12,7)*Power(Mag30,2)));
  }

  double D_6_neg2_4() {
    return Power(Mag30,2)*(16.4316767251549834*Power(Mag12,10) + Power(Mag30,2)*(-87.635609200826578*Power(Mag12,8) + 76.681158050723256*Power(Mag12,6)*Power(Mag30,2)));
  }

  double D_6_neg1_4() {
    return Power(Mag30,3)*(-34.6410161513775459*Power(Mag12,9) + Power(Mag30,2)*(121.243556529821411*Power(Mag12,7) - 72.746133917892846*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_6_0_4() {
    return Power(Mag30,4)*(56.124860801609121*Power(Mag12,8) + Power(Mag30,2)*(-134.69966592386189*Power(Mag12,6) + 56.124860801609121*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_6_1_4() {
    return Power(Mag30,5)*(-72.746133917892846*Power(Mag12,7) + Power(Mag30,2)*(121.243556529821411*Power(Mag12,5) - 34.6410161513775459*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_6_2_4() {
    return Power(Mag30,6)*(76.681158050723256*Power(Mag12,6) + Power(Mag30,2)*(-87.635609200826578*Power(Mag12,4) + 16.4316767251549834*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_6_3_4() {
    return Power(Mag30,7)*(-65.726706900619934*Power(Mag12,5) + Power(Mag30,2)*(49.2950301754649502*Power(Mag12,3) - 5.47722557505166113*Mag12*Power(Mag30,2)));
  }

  double D_6_4_4() {
    return Power(Mag30,8)*(45.*Power(Mag12,4) + Power(Mag30,2)*(-20.*Power(Mag12,2) + Power(Mag30,2)));
  }

  double D_6_5_4() {
    return Power(Mag30,9)*(-23.4520787991171478*Power(Mag12,3) + 4.69041575982342955*Mag12*Power(Mag30,2));
  }

  double D_6_6_4() {
    return 8.12403840463596036*Power(Mag12,2)*Power(Mag30,10);
  }

  double D_6_neg6_5() {
    return -3.46410161513775459*Power(Mag12,11)*Mag30;
  }

  double D_6_neg5_5() {
    return -1.*Power(Mag12,12) + 11.*Power(Mag12,10)*Power(Mag30,2);
  }

  double D_6_neg4_5() {
    return Mag30*(4.69041575982342955*Power(Mag12,11) - 23.4520787991171478*Power(Mag12,9)*Power(Mag30,2));
  }

  double D_6_neg3_5() {
    return Power(Mag30,2)*(-12.845232578665129*Power(Mag12,10) + 38.5356977359953871*Power(Mag12,8)*Power(Mag30,2));
  }

  double D_6_neg2_5() {
    return Power(Mag30,3)*(25.690465157330258*Power(Mag12,9) - 51.380930314660516*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_6_neg1_5() {
    return Power(Mag30,4)*(-40.6201920231798018*Power(Mag12,8) + 56.868268832451723*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_6_0_5() {
    return Power(Mag30,5)*(52.649786324352732*Power(Mag12,7) - 52.649786324352732*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_6_1_5() {
    return Power(Mag30,6)*(-56.868268832451723*Power(Mag12,6) + 40.6201920231798018*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_6_2_5() {
    return Power(Mag30,7)*(51.380930314660516*Power(Mag12,5) - 25.690465157330258*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_6_3_5() {
    return Power(Mag30,8)*(-38.5356977359953871*Power(Mag12,4) + 12.845232578665129*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_6_4_5() {
    return Power(Mag30,9)*(23.4520787991171478*Power(Mag12,3) - 4.69041575982342955*Mag12*Power(Mag30,2));
  }

  double D_6_5_5() {
    return Power(Mag30,10)*(-11.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_6_6_5() {
    return 3.46410161513775459*Mag12*Power(Mag30,11);
  }

  double D_6_neg6_6() {
    return Power(Mag12,12);
  }

  double D_6_neg5_6() {
    return -3.46410161513775459*Power(Mag12,11)*Mag30;
  }

  double D_6_neg4_6() {
    return 8.12403840463596036*Power(Mag12,10)*Power(Mag30,2);
  }

  double D_6_neg3_6() {
    return -14.8323969741913259*Power(Mag12,9)*Power(Mag30,3);
  }

  double D_6_neg2_6() {
    return 22.2485954612869888*Power(Mag12,8)*Power(Mag30,4);
  }

  double D_6_neg1_6() {
    return -28.1424945589405773*Power(Mag12,7)*Power(Mag30,5);
  }

  double D_6_0_6() {
    return 30.3973683071413273*Power(Mag12,6)*Power(Mag30,6);
  }

  double D_6_1_6() {
    return -28.1424945589405773*Power(Mag12,5)*Power(Mag30,7);
  }

  double D_6_2_6() {
    return 22.2485954612869888*Power(Mag12,4)*Power(Mag30,8);
  }

  double D_6_3_6() {
    return -14.8323969741913259*Power(Mag12,3)*Power(Mag30,9);
  }

  double D_6_4_6() {
    return 8.12403840463596036*Power(Mag12,2)*Power(Mag30,10);
  }

  double D_6_5_6() {
    return -3.46410161513775459*Mag12*Power(Mag30,11);
  }

  double D_6_6_6() {
    return Power(Mag30,12);
  }

  double D_5_neg5_neg5() {
    return Power(Mag30,10);
  }

  double D_5_neg4_neg5() {
    return 3.16227766016837933*Mag12*Power(Mag30,9);
  }

  double D_5_neg3_neg5() {
    return 6.70820393249936909*Power(Mag12,2)*Power(Mag30,8);
  }

  double D_5_neg2_neg5() {
    return 10.9544511501033223*Power(Mag12,3)*Power(Mag30,7);
  }

  double D_5_neg1_neg5() {
    return 14.4913767461894386*Power(Mag12,4)*Power(Mag30,6);
  }

  double D_5_0_neg5() {
    return 15.8745078663875435*Power(Mag12,5)*Power(Mag30,5);
  }

  double D_5_1_neg5() {
    return 14.4913767461894386*Power(Mag12,6)*Power(Mag30,4);
  }

  double D_5_2_neg5() {
    return 10.9544511501033223*Power(Mag12,7)*Power(Mag30,3);
  }

  double D_5_3_neg5() {
    return 6.70820393249936909*Power(Mag12,8)*Power(Mag30,2);
  }

  double D_5_4_neg5() {
    return 3.16227766016837933*Power(Mag12,9)*Mag30;
  }

  double D_5_5_neg5() {
    return Power(Mag12,10);
  }

  double D_5_neg5_neg4() {
    return -3.16227766016837933*Mag12*Power(Mag30,9);
  }

  double D_5_neg4_neg4() {
    return Power(Mag30,8)*(-9.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_5_neg3_neg4() {
    return Power(Mag30,7)*(-16.9705627484771406*Power(Mag12,3) + 4.24264068711928515*Mag12*Power(Mag30,2));
  }

  double D_5_neg2_neg4() {
    return Power(Mag30,6)*(-24.2487113059642821*Power(Mag12,4) + 10.3923048454132638*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_5_neg1_neg4() {
    return Power(Mag30,5)*(-27.49545416973504*Power(Mag12,5) + 18.33030277982336*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_5_0_neg4() {
    return Power(Mag30,4)*(-25.0998007960222664*Power(Mag12,6) + 25.0998007960222664*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_5_1_neg4() {
    return Power(Mag30,3)*(-18.33030277982336*Power(Mag12,7) + 27.49545416973504*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_5_2_neg4() {
    return Power(Mag30,2)*(-10.3923048454132638*Power(Mag12,8) + 24.2487113059642821*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_5_3_neg4() {
    return Mag30*(-4.24264068711928515*Power(Mag12,9) + 16.9705627484771406*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_5_4_neg4() {
    return -1.*Power(Mag12,10) + 9.*Power(Mag12,8)*Power(Mag30,2);
  }

  double D_5_5_neg4() {
    return 3.16227766016837933*Power(Mag12,9)*Mag30;
  }

  double D_5_neg5_neg3() {
    return 6.70820393249936909*Power(Mag12,2)*Power(Mag30,8);
  }

  double D_5_neg4_neg3() {
    return Power(Mag30,7)*(16.9705627484771406*Power(Mag12,3) - 4.24264068711928515*Mag12*Power(Mag30,2));
  }

  double D_5_neg3_neg3() {
    return Power(Mag30,6)*(28.*Power(Mag12,4) + Power(Mag30,2)*(-16.*Power(Mag12,2) + Power(Mag30,2)));
  }

  double D_5_neg2_neg3() {
    return Power(Mag30,5)*(34.2928563989644934*Power(Mag12,5) + Power(Mag30,2)*(-34.2928563989644934*Power(Mag12,3) + 4.8989794855663562*Mag12*Power(Mag30,2)));
  }

  double D_5_neg1_neg3() {
    return Power(Mag30,4)*(32.4037034920393012*Power(Mag12,6) + Power(Mag30,2)*(-51.845925587262882*Power(Mag12,4) + 12.9614813968157205*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_5_0_neg3() {
    return Power(Mag30,3)*(23.6643191323984642*Power(Mag12,7) + Power(Mag30,2)*(-59.16079783099616*Power(Mag12,5) + 23.6643191323984642*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_5_1_neg3() {
    return Power(Mag30,2)*(12.9614813968157205*Power(Mag12,8) + Power(Mag30,2)*(-51.845925587262882*Power(Mag12,6) + 32.4037034920393012*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_5_2_neg3() {
    return Mag30*(4.8989794855663562*Power(Mag12,9) + Power(Mag30,2)*(-34.2928563989644934*Power(Mag12,7) + 34.2928563989644934*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_5_3_neg3() {
    return Power(Mag12,10) + Power(Mag30,2)*(-16.*Power(Mag12,8) + 28.*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_5_4_neg3() {
    return Mag30*(-4.24264068711928515*Power(Mag12,9) + 16.9705627484771406*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_5_5_neg3() {
    return 6.70820393249936909*Power(Mag12,8)*Power(Mag30,2);
  }

  double D_5_neg5_neg2() {
    return -10.9544511501033223*Power(Mag12,3)*Power(Mag30,7);
  }

  double D_5_neg4_neg2() {
    return Power(Mag30,6)*(-24.2487113059642821*Power(Mag12,4) + 10.3923048454132638*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_5_neg3_neg2() {
    return Power(Mag30,5)*(-34.2928563989644934*Power(Mag12,5) + Power(Mag30,2)*(34.2928563989644934*Power(Mag12,3) - 4.8989794855663562*Mag12*Power(Mag30,2)));
  }

  double D_5_neg2_neg2() {
    return Power(Mag30,4)*(-35.*Power(Mag12,6) + Power(Mag30,2)*(63.*Power(Mag12,4) + Power(Mag30,2)*(-21.*Power(Mag12,2) + Power(Mag30,2))));
  }

  double D_5_neg1_neg2() {
    return Power(Mag30,3)*(-26.4575131106459059*Power(Mag12,7) + Power(Mag30,2)*(79.372539331937718*Power(Mag12,5) + Power(Mag30,2)*(-47.6235235991626306*Power(Mag12,3) + 5.2915026221291812*Mag12*Power(Mag30,2))));
  }

  double D_5_0_neg2() {
    return Power(Mag30,2)*(-14.4913767461894386*Power(Mag12,8) + Power(Mag30,2)*(72.456883730947193*Power(Mag12,6) + Power(Mag30,2)*(-72.456883730947193*Power(Mag12,4) + 14.4913767461894386*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_5_1_neg2() {
    return Mag30*(-5.29150262212918118*Power(Mag12,9) + Power(Mag30,2)*(47.6235235991626306*Power(Mag12,7) + Power(Mag30,2)*(-79.372539331937718*Power(Mag12,5) + 26.4575131106459059*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_5_2_neg2() {
    return -1.*Power(Mag12,10) + Power(Mag30,2)*(21.*Power(Mag12,8) + Power(Mag30,2)*(-63.*Power(Mag12,6) + 35.*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_5_3_neg2() {
    return Mag30*(4.8989794855663562*Power(Mag12,9) + Power(Mag30,2)*(-34.2928563989644934*Power(Mag12,7) + 34.2928563989644934*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_5_4_neg2() {
    return Power(Mag30,2)*(-10.3923048454132638*Power(Mag12,8) + 24.2487113059642821*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_5_5_neg2() {
    return 10.9544511501033223*Power(Mag12,7)*Power(Mag30,3);
  }

  double D_5_neg5_neg1() {
    return 14.4913767461894386*Power(Mag12,4)*Power(Mag30,6);
  }

  double D_5_neg4_neg1() {
    return Power(Mag30,5)*(27.49545416973504*Power(Mag12,5) - 18.33030277982336*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_5_neg3_neg1() {
    return Power(Mag30,4)*(32.4037034920393012*Power(Mag12,6) + Power(Mag30,2)*(-51.845925587262882*Power(Mag12,4) + 12.9614813968157205*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_5_neg2_neg1() {
    return Power(Mag30,3)*(26.4575131106459059*Power(Mag12,7) + Power(Mag30,2)*(-79.372539331937718*Power(Mag12,5) + Power(Mag30,2)*(47.6235235991626306*Power(Mag12,3) - 5.2915026221291812*Mag12*Power(Mag30,2))));
  }

  double D_5_neg1_neg1() {
    return Power(Mag30,2)*(15.*Power(Mag12,8) + Power(Mag30,2)*(-80.*Power(Mag12,6) + Power(Mag30,2)*(90.*Power(Mag12,4) + Power(Mag30,2)*(-24.*Power(Mag12,2) + Power(Mag30,2)))));
  }

  double D_5_0_neg1() {
    return Mag30*(5.47722557505166113*Power(Mag12,9) + Power(Mag30,2)*(-54.772255750516611*Power(Mag12,7) + Power(Mag30,2)*(109.544511501033223*Power(Mag12,5) + Power(Mag30,2)*(-54.772255750516611*Power(Mag12,3) + 5.47722557505166113*Mag12*Power(Mag30,2)))));
  }

  double D_5_1_neg1() {
    return Power(Mag12,10) + Power(Mag30,2)*(-24.*Power(Mag12,8) + Power(Mag30,2)*(90.*Power(Mag12,6) + Power(Mag30,2)*(-80.*Power(Mag12,4) + 15.*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_5_2_neg1() {
    return Mag30*(-5.29150262212918118*Power(Mag12,9) + Power(Mag30,2)*(47.6235235991626306*Power(Mag12,7) + Power(Mag30,2)*(-79.372539331937718*Power(Mag12,5) + 26.4575131106459059*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_5_3_neg1() {
    return Power(Mag30,2)*(12.9614813968157205*Power(Mag12,8) + Power(Mag30,2)*(-51.845925587262882*Power(Mag12,6) + 32.4037034920393012*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_5_4_neg1() {
    return Power(Mag30,3)*(-18.33030277982336*Power(Mag12,7) + 27.49545416973504*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_5_5_neg1() {
    return 14.4913767461894386*Power(Mag12,6)*Power(Mag30,4);
  }

  double D_5_neg5_0() {
    return -15.8745078663875435*Power(Mag12,5)*Power(Mag30,5);
  }

  double D_5_neg4_0() {
    return Power(Mag30,4)*(-25.0998007960222664*Power(Mag12,6) + 25.0998007960222664*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_5_neg3_0() {
    return Power(Mag30,3)*(-23.6643191323984642*Power(Mag12,7) + Power(Mag30,2)*(59.16079783099616*Power(Mag12,5) - 23.6643191323984642*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_5_neg2_0() {
    return Power(Mag30,2)*(-14.4913767461894386*Power(Mag12,8) + Power(Mag30,2)*(72.456883730947193*Power(Mag12,6) + Power(Mag30,2)*(-72.456883730947193*Power(Mag12,4) + 14.4913767461894386*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_5_neg1_0() {
    return Mag30*(-5.47722557505166113*Power(Mag12,9) + Power(Mag30,2)*(54.772255750516611*Power(Mag12,7) + Power(Mag30,2)*(-109.544511501033223*Power(Mag12,5) + Power(Mag30,2)*(54.772255750516611*Power(Mag12,3) - 5.47722557505166113*Mag12*Power(Mag30,2)))));
  }

  double D_5_0_0() {
    return -1.*Power(Mag12,10) + Power(Mag30,2)*(25.*Power(Mag12,8) + Power(Mag30,2)*(-100.*Power(Mag12,6) + Power(Mag30,2)*(100.*Power(Mag12,4) + Power(Mag30,2)*(-25.*Power(Mag12,2) + Power(Mag30,2)))));
  }

  double D_5_1_0() {
    return Mag30*(5.47722557505166113*Power(Mag12,9) + Power(Mag30,2)*(-54.772255750516611*Power(Mag12,7) + Power(Mag30,2)*(109.544511501033223*Power(Mag12,5) + Power(Mag30,2)*(-54.772255750516611*Power(Mag12,3) + 5.47722557505166113*Mag12*Power(Mag30,2)))));
  }

  double D_5_2_0() {
    return Power(Mag30,2)*(-14.4913767461894386*Power(Mag12,8) + Power(Mag30,2)*(72.456883730947193*Power(Mag12,6) + Power(Mag30,2)*(-72.456883730947193*Power(Mag12,4) + 14.4913767461894386*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_5_3_0() {
    return Power(Mag30,3)*(23.6643191323984642*Power(Mag12,7) + Power(Mag30,2)*(-59.16079783099616*Power(Mag12,5) + 23.6643191323984642*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_5_4_0() {
    return Power(Mag30,4)*(-25.0998007960222664*Power(Mag12,6) + 25.0998007960222664*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_5_5_0() {
    return 15.8745078663875435*Power(Mag12,5)*Power(Mag30,5);
  }

  double D_5_neg5_1() {
    return 14.4913767461894386*Power(Mag12,6)*Power(Mag30,4);
  }

  double D_5_neg4_1() {
    return Power(Mag30,3)*(18.33030277982336*Power(Mag12,7) - 27.49545416973504*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_5_neg3_1() {
    return Power(Mag30,2)*(12.9614813968157205*Power(Mag12,8) + Power(Mag30,2)*(-51.845925587262882*Power(Mag12,6) + 32.4037034920393012*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_5_neg2_1() {
    return Mag30*(5.29150262212918118*Power(Mag12,9) + Power(Mag30,2)*(-47.6235235991626306*Power(Mag12,7) + Power(Mag30,2)*(79.372539331937718*Power(Mag12,5) - 26.4575131106459059*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_5_neg1_1() {
    return Power(Mag12,10) + Power(Mag30,2)*(-24.*Power(Mag12,8) + Power(Mag30,2)*(90.*Power(Mag12,6) + Power(Mag30,2)*(-80.*Power(Mag12,4) + 15.*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_5_0_1() {
    return Mag30*(-5.47722557505166113*Power(Mag12,9) + Power(Mag30,2)*(54.772255750516611*Power(Mag12,7) + Power(Mag30,2)*(-109.544511501033223*Power(Mag12,5) + Power(Mag30,2)*(54.772255750516611*Power(Mag12,3) - 5.47722557505166113*Mag12*Power(Mag30,2)))));
  }

  double D_5_1_1() {
    return Power(Mag30,2)*(15.*Power(Mag12,8) + Power(Mag30,2)*(-80.*Power(Mag12,6) + Power(Mag30,2)*(90.*Power(Mag12,4) + Power(Mag30,2)*(-24.*Power(Mag12,2) + Power(Mag30,2)))));
  }

  double D_5_2_1() {
    return Power(Mag30,3)*(-26.4575131106459059*Power(Mag12,7) + Power(Mag30,2)*(79.372539331937718*Power(Mag12,5) + Power(Mag30,2)*(-47.6235235991626306*Power(Mag12,3) + 5.29150262212918118*Mag12*Power(Mag30,2))));
  }

  double D_5_3_1() {
    return Power(Mag30,4)*(32.4037034920393012*Power(Mag12,6) + Power(Mag30,2)*(-51.845925587262882*Power(Mag12,4) + 12.9614813968157205*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_5_4_1() {
    return Power(Mag30,5)*(-27.49545416973504*Power(Mag12,5) + 18.33030277982336*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_5_5_1() {
    return 14.4913767461894386*Power(Mag12,4)*Power(Mag30,6);
  }

  double D_5_neg5_2() {
    return -10.9544511501033223*Power(Mag12,7)*Power(Mag30,3);
  }

  double D_5_neg4_2() {
    return Power(Mag30,2)*(-10.3923048454132638*Power(Mag12,8) + 24.2487113059642821*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_5_neg3_2() {
    return Mag30*(-4.8989794855663562*Power(Mag12,9) + Power(Mag30,2)*(34.2928563989644934*Power(Mag12,7) - 34.2928563989644934*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_5_neg2_2() {
    return -1.*Power(Mag12,10) + Power(Mag30,2)*(21.*Power(Mag12,8) + Power(Mag30,2)*(-63.*Power(Mag12,6) + 35.*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_5_neg1_2() {
    return Mag30*(5.29150262212918118*Power(Mag12,9) + Power(Mag30,2)*(-47.6235235991626306*Power(Mag12,7) + Power(Mag30,2)*(79.372539331937718*Power(Mag12,5) - 26.4575131106459059*Power(Mag12,3)*Power(Mag30,2))));
  }

  double D_5_0_2() {
    return Power(Mag30,2)*(-14.4913767461894386*Power(Mag12,8) + Power(Mag30,2)*(72.456883730947193*Power(Mag12,6) + Power(Mag30,2)*(-72.456883730947193*Power(Mag12,4) + 14.4913767461894386*Power(Mag12,2)*Power(Mag30,2))));
  }

  double D_5_1_2() {
    return Power(Mag30,3)*(26.4575131106459059*Power(Mag12,7) + Power(Mag30,2)*(-79.372539331937718*Power(Mag12,5) + Power(Mag30,2)*(47.6235235991626306*Power(Mag12,3) - 5.29150262212918118*Mag12*Power(Mag30,2))));
  }

  double D_5_2_2() {
    return Power(Mag30,4)*(-35.*Power(Mag12,6) + Power(Mag30,2)*(63.*Power(Mag12,4) + Power(Mag30,2)*(-21.*Power(Mag12,2) + Power(Mag30,2))));
  }

  double D_5_3_2() {
    return Power(Mag30,5)*(34.2928563989644934*Power(Mag12,5) + Power(Mag30,2)*(-34.2928563989644934*Power(Mag12,3) + 4.8989794855663562*Mag12*Power(Mag30,2)));
  }

  double D_5_4_2() {
    return Power(Mag30,6)*(-24.2487113059642821*Power(Mag12,4) + 10.3923048454132638*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_5_5_2() {
    return 10.9544511501033223*Power(Mag12,3)*Power(Mag30,7);
  }

  double D_5_neg5_3() {
    return 6.70820393249936909*Power(Mag12,8)*Power(Mag30,2);
  }

  double D_5_neg4_3() {
    return Mag30*(4.24264068711928515*Power(Mag12,9) - 16.9705627484771406*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_5_neg3_3() {
    return Power(Mag12,10) + Power(Mag30,2)*(-16.*Power(Mag12,8) + 28.*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_5_neg2_3() {
    return Mag30*(-4.8989794855663562*Power(Mag12,9) + Power(Mag30,2)*(34.2928563989644934*Power(Mag12,7) - 34.2928563989644934*Power(Mag12,5)*Power(Mag30,2)));
  }

  double D_5_neg1_3() {
    return Power(Mag30,2)*(12.9614813968157205*Power(Mag12,8) + Power(Mag30,2)*(-51.845925587262882*Power(Mag12,6) + 32.4037034920393012*Power(Mag12,4)*Power(Mag30,2)));
  }

  double D_5_0_3() {
    return Power(Mag30,3)*(-23.6643191323984642*Power(Mag12,7) + Power(Mag30,2)*(59.16079783099616*Power(Mag12,5) - 23.6643191323984642*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_5_1_3() {
    return Power(Mag30,4)*(32.4037034920393012*Power(Mag12,6) + Power(Mag30,2)*(-51.845925587262882*Power(Mag12,4) + 12.9614813968157205*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_5_2_3() {
    return Power(Mag30,5)*(-34.2928563989644934*Power(Mag12,5) + Power(Mag30,2)*(34.2928563989644934*Power(Mag12,3) - 4.8989794855663562*Mag12*Power(Mag30,2)));
  }

  double D_5_3_3() {
    return Power(Mag30,6)*(28.*Power(Mag12,4) + Power(Mag30,2)*(-16.*Power(Mag12,2) + Power(Mag30,2)));
  }

  double D_5_4_3() {
    return Power(Mag30,7)*(-16.9705627484771406*Power(Mag12,3) + 4.24264068711928515*Mag12*Power(Mag30,2));
  }

  double D_5_5_3() {
    return 6.70820393249936909*Power(Mag12,2)*Power(Mag30,8);
  }

  double D_5_neg5_4() {
    return -3.16227766016837933*Power(Mag12,9)*Mag30;
  }

  double D_5_neg4_4() {
    return -1.*Power(Mag12,10) + 9.*Power(Mag12,8)*Power(Mag30,2);
  }

  double D_5_neg3_4() {
    return Mag30*(4.24264068711928515*Power(Mag12,9) - 16.9705627484771406*Power(Mag12,7)*Power(Mag30,2));
  }

  double D_5_neg2_4() {
    return Power(Mag30,2)*(-10.3923048454132638*Power(Mag12,8) + 24.2487113059642821*Power(Mag12,6)*Power(Mag30,2));
  }

  double D_5_neg1_4() {
    return Power(Mag30,3)*(18.33030277982336*Power(Mag12,7) - 27.49545416973504*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_5_0_4() {
    return Power(Mag30,4)*(-25.0998007960222664*Power(Mag12,6) + 25.0998007960222664*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_5_1_4() {
    return Power(Mag30,5)*(27.49545416973504*Power(Mag12,5) - 18.33030277982336*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_5_2_4() {
    return Power(Mag30,6)*(-24.2487113059642821*Power(Mag12,4) + 10.3923048454132638*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_5_3_4() {
    return Power(Mag30,7)*(16.9705627484771406*Power(Mag12,3) - 4.24264068711928515*Mag12*Power(Mag30,2));
  }

  double D_5_4_4() {
    return Power(Mag30,8)*(-9.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_5_5_4() {
    return 3.16227766016837933*Mag12*Power(Mag30,9);
  }

  double D_5_neg5_5() {
    return Power(Mag12,10);
  }

  double D_5_neg4_5() {
    return -3.16227766016837933*Power(Mag12,9)*Mag30;
  }

  double D_5_neg3_5() {
    return 6.70820393249936909*Power(Mag12,8)*Power(Mag30,2);
  }

  double D_5_neg2_5() {
    return -10.9544511501033223*Power(Mag12,7)*Power(Mag30,3);
  }

  double D_5_neg1_5() {
    return 14.4913767461894386*Power(Mag12,6)*Power(Mag30,4);
  }

  double D_5_0_5() {
    return -15.8745078663875435*Power(Mag12,5)*Power(Mag30,5);
  }

  double D_5_1_5() {
    return 14.4913767461894386*Power(Mag12,4)*Power(Mag30,6);
  }

  double D_5_2_5() {
    return -10.9544511501033223*Power(Mag12,3)*Power(Mag30,7);
  }

  double D_5_3_5() {
    return 6.70820393249936909*Power(Mag12,2)*Power(Mag30,8);
  }

  double D_5_4_5() {
    return -3.16227766016837933*Mag12*Power(Mag30,9);
  }

  double D_5_5_5() {
    return Power(Mag30,10);
  }

  double D_4_neg4_neg4() {
    return Power(Mag30,8);
  }

  double D_4_neg3_neg4() {
    return 2.8284271247461901*Mag12*Power(Mag30,7);
  }

  double D_4_neg2_neg4() {
    return 5.29150262212918118*Power(Mag12,2)*Power(Mag30,6);
  }

  double D_4_neg1_neg4() {
    return 7.48331477354788277*Power(Mag12,3)*Power(Mag30,5);
  }

  double D_4_0_neg4() {
    return 8.36660026534075548*Power(Mag12,4)*Power(Mag30,4);
  }

  double D_4_1_neg4() {
    return 7.48331477354788277*Power(Mag12,5)*Power(Mag30,3);
  }

  double D_4_2_neg4() {
    return 5.29150262212918118*Power(Mag12,6)*Power(Mag30,2);
  }

  double D_4_3_neg4() {
    return 2.8284271247461901*Power(Mag12,7)*Mag30;
  }

  double D_4_4_neg4() {
    return Power(Mag12,8);
  }

  double D_4_neg4_neg3() {
    return -2.8284271247461901*Mag12*Power(Mag30,7);
  }

  double D_4_neg3_neg3() {
    return Power(Mag30,6)*(-7.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_4_neg2_neg3() {
    return Power(Mag30,5)*(-11.2249721603218242*Power(Mag12,3) + 3.74165738677394139*Mag12*Power(Mag30,2));
  }

  double D_4_neg1_neg3() {
    return Power(Mag30,4)*(-13.228756555322953*Power(Mag12,4) + 7.9372539331937718*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_4_0_neg3() {
    return Power(Mag30,3)*(-11.8321595661992321*Power(Mag12,5) + 11.8321595661992321*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_4_1_neg3() {
    return Power(Mag30,2)*(-7.9372539331937718*Power(Mag12,6) + 13.228756555322953*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_4_2_neg3() {
    return Mag30*(-3.74165738677394139*Power(Mag12,7) + 11.2249721603218242*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_4_3_neg3() {
    return -1.*Power(Mag12,8) + 7.*Power(Mag12,6)*Power(Mag30,2);
  }

  double D_4_4_neg3() {
    return 2.8284271247461901*Power(Mag12,7)*Mag30;
  }

  double D_4_neg4_neg2() {
    return 5.29150262212918118*Power(Mag12,2)*Power(Mag30,6);
  }

  double D_4_neg3_neg2() {
    return Power(Mag30,5)*(11.2249721603218242*Power(Mag12,3) - 3.74165738677394139*Mag12*Power(Mag30,2));
  }

  double D_4_neg2_neg2() {
    return Power(Mag30,4)*(15.*Power(Mag12,4) + Power(Mag30,2)*(-12.*Power(Mag12,2) + Power(Mag30,2)));
  }

  double D_4_neg1_neg2() {
    return Power(Mag30,3)*(14.1421356237309505*Power(Mag12,5) + Power(Mag30,2)*(-21.2132034355964257*Power(Mag12,3) + 4.24264068711928515*Mag12*Power(Mag30,2)));
  }

  double D_4_0_neg2() {
    return Power(Mag30,2)*(9.486832980505138*Power(Mag12,6) + Power(Mag30,2)*(-25.2982212813470347*Power(Mag12,4) + 9.486832980505138*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_4_1_neg2() {
    return Mag30*(4.24264068711928515*Power(Mag12,7) + Power(Mag30,2)*(-21.2132034355964257*Power(Mag12,5) + 14.1421356237309505*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_4_2_neg2() {
    return Power(Mag12,8) + Power(Mag30,2)*(-12.*Power(Mag12,6) + 15.*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_4_3_neg2() {
    return Mag30*(-3.74165738677394139*Power(Mag12,7) + 11.2249721603218242*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_4_4_neg2() {
    return 5.29150262212918118*Power(Mag12,6)*Power(Mag30,2);
  }

  double D_4_neg4_neg1() {
    return -7.48331477354788277*Power(Mag12,3)*Power(Mag30,5);
  }

  double D_4_neg3_neg1() {
    return Power(Mag30,4)*(-13.228756555322953*Power(Mag12,4) + 7.9372539331937718*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_4_neg2_neg1() {
    return Power(Mag30,3)*(-14.1421356237309505*Power(Mag12,5) + Power(Mag30,2)*(21.2132034355964257*Power(Mag12,3) - 4.24264068711928515*Mag12*Power(Mag30,2)));
  }

  double D_4_neg1_neg1() {
    return Power(Mag30,2)*(-10.*Power(Mag12,6) + Power(Mag30,2)*(30.*Power(Mag12,4) + Power(Mag30,2)*(-15.*Power(Mag12,2) + Power(Mag30,2))));
  }

  double D_4_0_neg1() {
    return Mag30*(-4.47213595499957939*Power(Mag12,7) + Power(Mag30,2)*(26.8328157299974764*Power(Mag12,5) + Power(Mag30,2)*(-26.8328157299974764*Power(Mag12,3) + 4.47213595499957939*Mag12*Power(Mag30,2))));
  }

  double D_4_1_neg1() {
    return -1.*Power(Mag12,8) + Power(Mag30,2)*(15.*Power(Mag12,6) + Power(Mag30,2)*(-30.*Power(Mag12,4) + 10.*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_4_2_neg1() {
    return Mag30*(4.24264068711928515*Power(Mag12,7) + Power(Mag30,2)*(-21.2132034355964257*Power(Mag12,5) + 14.1421356237309505*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_4_3_neg1() {
    return Power(Mag30,2)*(-7.9372539331937718*Power(Mag12,6) + 13.228756555322953*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_4_4_neg1() {
    return 7.48331477354788277*Power(Mag12,5)*Power(Mag30,3);
  }

  double D_4_neg4_0() {
    return 8.36660026534075548*Power(Mag12,4)*Power(Mag30,4);
  }

  double D_4_neg3_0() {
    return Power(Mag30,3)*(11.8321595661992321*Power(Mag12,5) - 11.8321595661992321*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_4_neg2_0() {
    return Power(Mag30,2)*(9.486832980505138*Power(Mag12,6) + Power(Mag30,2)*(-25.2982212813470347*Power(Mag12,4) + 9.486832980505138*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_4_neg1_0() {
    return Mag30*(4.47213595499957939*Power(Mag12,7) + Power(Mag30,2)*(-26.8328157299974764*Power(Mag12,5) + Power(Mag30,2)*(26.8328157299974764*Power(Mag12,3) - 4.47213595499957939*Mag12*Power(Mag30,2))));
  }

  double D_4_0_0() {
    return Power(Mag12,8) + Power(Mag30,2)*(-16.*Power(Mag12,6) + Power(Mag30,2)*(36.*Power(Mag12,4) + Power(Mag30,2)*(-16.*Power(Mag12,2) + Power(Mag30,2))));
  }

  double D_4_1_0() {
    return Mag30*(-4.47213595499957939*Power(Mag12,7) + Power(Mag30,2)*(26.8328157299974764*Power(Mag12,5) + Power(Mag30,2)*(-26.8328157299974764*Power(Mag12,3) + 4.47213595499957939*Mag12*Power(Mag30,2))));
  }

  double D_4_2_0() {
    return Power(Mag30,2)*(9.486832980505138*Power(Mag12,6) + Power(Mag30,2)*(-25.2982212813470347*Power(Mag12,4) + 9.486832980505138*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_4_3_0() {
    return Power(Mag30,3)*(-11.8321595661992321*Power(Mag12,5) + 11.8321595661992321*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_4_4_0() {
    return 8.36660026534075548*Power(Mag12,4)*Power(Mag30,4);
  }

  double D_4_neg4_1() {
    return -7.48331477354788277*Power(Mag12,5)*Power(Mag30,3);
  }

  double D_4_neg3_1() {
    return Power(Mag30,2)*(-7.9372539331937718*Power(Mag12,6) + 13.228756555322953*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_4_neg2_1() {
    return Mag30*(-4.24264068711928515*Power(Mag12,7) + Power(Mag30,2)*(21.2132034355964257*Power(Mag12,5) - 14.1421356237309505*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_4_neg1_1() {
    return -1.*Power(Mag12,8) + Power(Mag30,2)*(15.*Power(Mag12,6) + Power(Mag30,2)*(-30.*Power(Mag12,4) + 10.*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_4_0_1() {
    return Mag30*(4.47213595499957939*Power(Mag12,7) + Power(Mag30,2)*(-26.8328157299974764*Power(Mag12,5) + Power(Mag30,2)*(26.8328157299974764*Power(Mag12,3) - 4.47213595499957939*Mag12*Power(Mag30,2))));
  }

  double D_4_1_1() {
    return Power(Mag30,2)*(-10.*Power(Mag12,6) + Power(Mag30,2)*(30.*Power(Mag12,4) + Power(Mag30,2)*(-15.*Power(Mag12,2) + Power(Mag30,2))));
  }

  double D_4_2_1() {
    return Power(Mag30,3)*(14.1421356237309505*Power(Mag12,5) + Power(Mag30,2)*(-21.2132034355964257*Power(Mag12,3) + 4.24264068711928515*Mag12*Power(Mag30,2)));
  }

  double D_4_3_1() {
    return Power(Mag30,4)*(-13.228756555322953*Power(Mag12,4) + 7.9372539331937718*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_4_4_1() {
    return 7.48331477354788277*Power(Mag12,3)*Power(Mag30,5);
  }

  double D_4_neg4_2() {
    return 5.29150262212918118*Power(Mag12,6)*Power(Mag30,2);
  }

  double D_4_neg3_2() {
    return Mag30*(3.74165738677394139*Power(Mag12,7) - 11.2249721603218242*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_4_neg2_2() {
    return Power(Mag12,8) + Power(Mag30,2)*(-12.*Power(Mag12,6) + 15.*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_4_neg1_2() {
    return Mag30*(-4.24264068711928515*Power(Mag12,7) + Power(Mag30,2)*(21.2132034355964257*Power(Mag12,5) - 14.1421356237309505*Power(Mag12,3)*Power(Mag30,2)));
  }

  double D_4_0_2() {
    return Power(Mag30,2)*(9.486832980505138*Power(Mag12,6) + Power(Mag30,2)*(-25.2982212813470347*Power(Mag12,4) + 9.486832980505138*Power(Mag12,2)*Power(Mag30,2)));
  }

  double D_4_1_2() {
    return Power(Mag30,3)*(-14.1421356237309505*Power(Mag12,5) + Power(Mag30,2)*(21.2132034355964257*Power(Mag12,3) - 4.24264068711928515*Mag12*Power(Mag30,2)));
  }

  double D_4_2_2() {
    return Power(Mag30,4)*(15.*Power(Mag12,4) + Power(Mag30,2)*(-12.*Power(Mag12,2) + Power(Mag30,2)));
  }

  double D_4_3_2() {
    return Power(Mag30,5)*(-11.2249721603218242*Power(Mag12,3) + 3.74165738677394139*Mag12*Power(Mag30,2));
  }

  double D_4_4_2() {
    return 5.29150262212918118*Power(Mag12,2)*Power(Mag30,6);
  }

  double D_4_neg4_3() {
    return -2.8284271247461901*Power(Mag12,7)*Mag30;
  }

  double D_4_neg3_3() {
    return -1.*Power(Mag12,8) + 7.*Power(Mag12,6)*Power(Mag30,2);
  }

  double D_4_neg2_3() {
    return Mag30*(3.74165738677394139*Power(Mag12,7) - 11.2249721603218242*Power(Mag12,5)*Power(Mag30,2));
  }

  double D_4_neg1_3() {
    return Power(Mag30,2)*(-7.9372539331937718*Power(Mag12,6) + 13.228756555322953*Power(Mag12,4)*Power(Mag30,2));
  }

  double D_4_0_3() {
    return Power(Mag30,3)*(11.8321595661992321*Power(Mag12,5) - 11.8321595661992321*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_4_1_3() {
    return Power(Mag30,4)*(-13.228756555322953*Power(Mag12,4) + 7.9372539331937718*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_4_2_3() {
    return Power(Mag30,5)*(11.2249721603218242*Power(Mag12,3) - 3.74165738677394139*Mag12*Power(Mag30,2));
  }

  double D_4_3_3() {
    return Power(Mag30,6)*(-7.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_4_4_3() {
    return 2.8284271247461901*Mag12*Power(Mag30,7);
  }

  double D_4_neg4_4() {
    return Power(Mag12,8);
  }

  double D_4_neg3_4() {
    return -2.8284271247461901*Power(Mag12,7)*Mag30;
  }

  double D_4_neg2_4() {
    return 5.29150262212918118*Power(Mag12,6)*Power(Mag30,2);
  }

  double D_4_neg1_4() {
    return -7.48331477354788277*Power(Mag12,5)*Power(Mag30,3);
  }

  double D_4_0_4() {
    return 8.36660026534075548*Power(Mag12,4)*Power(Mag30,4);
  }

  double D_4_1_4() {
    return -7.48331477354788277*Power(Mag12,3)*Power(Mag30,5);
  }

  double D_4_2_4() {
    return 5.29150262212918118*Power(Mag12,2)*Power(Mag30,6);
  }

  double D_4_3_4() {
    return -2.8284271247461901*Mag12*Power(Mag30,7);
  }

  double D_4_4_4() {
    return Power(Mag30,8);
  }

  double D_3_neg3_neg3() {
    return Power(Mag30,6);
  }

  double D_3_neg2_neg3() {
    return 2.4494897427831781*Mag12*Power(Mag30,5);
  }

  double D_3_neg1_neg3() {
    return 3.87298334620741689*Power(Mag12,2)*Power(Mag30,4);
  }

  double D_3_0_neg3() {
    return 4.47213595499957939*Power(Mag12,3)*Power(Mag30,3);
  }

  double D_3_1_neg3() {
    return 3.87298334620741689*Power(Mag12,4)*Power(Mag30,2);
  }

  double D_3_2_neg3() {
    return 2.4494897427831781*Power(Mag12,5)*Mag30;
  }

  double D_3_3_neg3() {
    return Power(Mag12,6);
  }

  double D_3_neg3_neg2() {
    return -2.4494897427831781*Mag12*Power(Mag30,5);
  }

  double D_3_neg2_neg2() {
    return Power(Mag30,4)*(-5.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_3_neg1_neg2() {
    return Power(Mag30,3)*(-6.3245553203367587*Power(Mag12,3) + 3.16227766016837933*Mag12*Power(Mag30,2));
  }

  double D_3_0_neg2() {
    return Power(Mag30,2)*(-5.47722557505166113*Power(Mag12,4) + 5.4772255750516611*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_3_1_neg2() {
    return Mag30*(-3.16227766016837933*Power(Mag12,5) + 6.3245553203367587*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_3_2_neg2() {
    return -1.*Power(Mag12,6) + 5.*Power(Mag12,4)*Power(Mag30,2);
  }

  double D_3_3_neg2() {
    return 2.4494897427831781*Power(Mag12,5)*Mag30;
  }

  double D_3_neg3_neg1() {
    return 3.87298334620741689*Power(Mag12,2)*Power(Mag30,4);
  }

  double D_3_neg2_neg1() {
    return Power(Mag30,3)*(6.3245553203367587*Power(Mag12,3) - 3.16227766016837933*Mag12*Power(Mag30,2));
  }

  double D_3_neg1_neg1() {
    return Power(Mag30,2)*(6.*Power(Mag12,4) + Power(Mag30,2)*(-8.*Power(Mag12,2) + Power(Mag30,2)));
  }

  double D_3_0_neg1() {
    return Mag30*(3.46410161513775459*Power(Mag12,5) + Power(Mag30,2)*(-10.3923048454132638*Power(Mag12,3) + 3.46410161513775459*Mag12*Power(Mag30,2)));
  }

  double D_3_1_neg1() {
    return Power(Mag12,6) + Power(Mag30,2)*(-8.*Power(Mag12,4) + 6.*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_3_2_neg1() {
    return Mag30*(-3.16227766016837933*Power(Mag12,5) + 6.3245553203367587*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_3_3_neg1() {
    return 3.87298334620741689*Power(Mag12,4)*Power(Mag30,2);
  }

  double D_3_neg3_0() {
    return -4.47213595499957939*Power(Mag12,3)*Power(Mag30,3);
  }

  double D_3_neg2_0() {
    return Power(Mag30,2)*(-5.47722557505166113*Power(Mag12,4) + 5.4772255750516611*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_3_neg1_0() {
    return Mag30*(-3.46410161513775459*Power(Mag12,5) + Power(Mag30,2)*(10.3923048454132638*Power(Mag12,3) - 3.46410161513775459*Mag12*Power(Mag30,2)));
  }

  double D_3_0_0() {
    return -1.*Power(Mag12,6) + Power(Mag30,2)*(9.*Power(Mag12,4) + Power(Mag30,2)*(-9.*Power(Mag12,2) + Power(Mag30,2)));
  }

  double D_3_1_0() {
    return Mag30*(3.46410161513775459*Power(Mag12,5) + Power(Mag30,2)*(-10.3923048454132638*Power(Mag12,3) + 3.46410161513775459*Mag12*Power(Mag30,2)));
  }

  double D_3_2_0() {
    return Power(Mag30,2)*(-5.47722557505166113*Power(Mag12,4) + 5.4772255750516611*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_3_3_0() {
    return 4.47213595499957939*Power(Mag12,3)*Power(Mag30,3);
  }

  double D_3_neg3_1() {
    return 3.87298334620741689*Power(Mag12,4)*Power(Mag30,2);
  }

  double D_3_neg2_1() {
    return Mag30*(3.16227766016837933*Power(Mag12,5) - 6.3245553203367587*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_3_neg1_1() {
    return Power(Mag12,6) + Power(Mag30,2)*(-8.*Power(Mag12,4) + 6.*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_3_0_1() {
    return Mag30*(-3.46410161513775459*Power(Mag12,5) + Power(Mag30,2)*(10.3923048454132638*Power(Mag12,3) - 3.46410161513775459*Mag12*Power(Mag30,2)));
  }

  double D_3_1_1() {
    return Power(Mag30,2)*(6.*Power(Mag12,4) + Power(Mag30,2)*(-8.*Power(Mag12,2) + Power(Mag30,2)));
  }

  double D_3_2_1() {
    return Power(Mag30,3)*(-6.3245553203367587*Power(Mag12,3) + 3.16227766016837933*Mag12*Power(Mag30,2));
  }

  double D_3_3_1() {
    return 3.87298334620741689*Power(Mag12,2)*Power(Mag30,4);
  }

  double D_3_neg3_2() {
    return -2.4494897427831781*Power(Mag12,5)*Mag30;
  }

  double D_3_neg2_2() {
    return -1.*Power(Mag12,6) + 5.*Power(Mag12,4)*Power(Mag30,2);
  }

  double D_3_neg1_2() {
    return Mag30*(3.16227766016837933*Power(Mag12,5) - 6.3245553203367587*Power(Mag12,3)*Power(Mag30,2));
  }

  double D_3_0_2() {
    return Power(Mag30,2)*(-5.47722557505166113*Power(Mag12,4) + 5.4772255750516611*Power(Mag12,2)*Power(Mag30,2));
  }

  double D_3_1_2() {
    return Power(Mag30,3)*(6.3245553203367587*Power(Mag12,3) - 3.16227766016837933*Mag12*Power(Mag30,2));
  }

  double D_3_2_2() {
    return Power(Mag30,4)*(-5.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_3_3_2() {
    return 2.4494897427831781*Mag12*Power(Mag30,5);
  }

  double D_3_neg3_3() {
    return Power(Mag12,6);
  }

  double D_3_neg2_3() {
    return -2.4494897427831781*Power(Mag12,5)*Mag30;
  }

  double D_3_neg1_3() {
    return 3.87298334620741689*Power(Mag12,4)*Power(Mag30,2);
  }

  double D_3_0_3() {
    return -4.47213595499957939*Power(Mag12,3)*Power(Mag30,3);
  }

  double D_3_1_3() {
    return 3.87298334620741689*Power(Mag12,2)*Power(Mag30,4);
  }

  double D_3_2_3() {
    return -2.4494897427831781*Mag12*Power(Mag30,5);
  }

  double D_3_3_3() {
    return Power(Mag30,6);
  }

  double D_2_neg2_neg2() {
    return Power(Mag30,4);
  }

  double D_2_neg1_neg2() {
    return 2.*Mag12*Power(Mag30,3);
  }

  double D_2_0_neg2() {
    return 2.4494897427831781*Power(Mag12,2)*Power(Mag30,2);
  }

  double D_2_1_neg2() {
    return 2.*Power(Mag12,3)*Mag30;
  }

  double D_2_2_neg2() {
    return Power(Mag12,4);
  }

  double D_2_neg2_neg1() {
    return -2.*Mag12*Power(Mag30,3);
  }

  double D_2_neg1_neg1() {
    return Power(Mag30,2)*(-3.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_2_0_neg1() {
    return Mag30*(-2.4494897427831781*Power(Mag12,3) + 2.4494897427831781*Mag12*Power(Mag30,2));
  }

  double D_2_1_neg1() {
    return -1.*Power(Mag12,4) + 3.*Power(Mag12,2)*Power(Mag30,2);
  }

  double D_2_2_neg1() {
    return 2.*Power(Mag12,3)*Mag30;
  }

  double D_2_neg2_0() {
    return 2.4494897427831781*Power(Mag12,2)*Power(Mag30,2);
  }

  double D_2_neg1_0() {
    return Mag30*(2.4494897427831781*Power(Mag12,3) - 2.4494897427831781*Mag12*Power(Mag30,2));
  }

  double D_2_0_0() {
    return Power(Mag12,4) + Power(Mag30,2)*(-4.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_2_1_0() {
    return Mag30*(-2.4494897427831781*Power(Mag12,3) + 2.4494897427831781*Mag12*Power(Mag30,2));
  }

  double D_2_2_0() {
    return 2.4494897427831781*Power(Mag12,2)*Power(Mag30,2);
  }

  double D_2_neg2_1() {
    return -2.*Power(Mag12,3)*Mag30;
  }

  double D_2_neg1_1() {
    return -1.*Power(Mag12,4) + 3.*Power(Mag12,2)*Power(Mag30,2);
  }

  double D_2_0_1() {
    return Mag30*(2.4494897427831781*Power(Mag12,3) - 2.4494897427831781*Mag12*Power(Mag30,2));
  }

  double D_2_1_1() {
    return Power(Mag30,2)*(-3.*Power(Mag12,2) + Power(Mag30,2));
  }

  double D_2_2_1() {
    return 2.*Mag12*Power(Mag30,3);
  }

  double D_2_neg2_2() {
    return Power(Mag12,4);
  }

  double D_2_neg1_2() {
    return -2.*Power(Mag12,3)*Mag30;
  }

  double D_2_0_2() {
    return 2.4494897427831781*Power(Mag12,2)*Power(Mag30,2);
  }

  double D_2_1_2() {
    return -2.*Mag12*Power(Mag30,3);
  }

  double D_2_2_2() {
    return Power(Mag30,4);
  }

  double D_1_neg1_neg1() {
    return Power(Mag30,2);
  }

  double D_1_0_neg1() {
    return 1.41421356237309505*Mag12*Mag30;
  }

  double D_1_1_neg1() {
    return Power(Mag12,2);
  }

  double D_1_neg1_0() {
    return -1.41421356237309505*Mag12*Mag30;
  }

  double D_1_0_0() {
    return -1.*Power(Mag12,2) + Power(Mag30,2);
  }

  double D_1_1_0() {
    return 1.41421356237309505*Mag12*Mag30;
  }

  double D_1_neg1_1() {
    return Power(Mag12,2);
  }

  double D_1_0_1() {
    return -1.41421356237309505*Mag12*Mag30;
  }

  double D_1_1_1() {
    return Power(Mag30,2);
  }

  double D_0_0_0() {
    return 1.;
  }
