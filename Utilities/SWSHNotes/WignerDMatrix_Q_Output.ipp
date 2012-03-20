
  double Uninitialized() {
    std::cerr << "\nThis matrix has not yet been initialized with L,M,MP information." << std::endl;
    throw("Trying to use an uninitialized Wigner D matrix.");
    return 0.0;
  }
  
  double Identity() {
    return 1.0;
  }
  
  double Zero() {
    return 0.0;
  }
  
  double D_8_neg8_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0000152587890625 + RzRbar3*(0.000244140625 + RzRbar3*(0.0018310546875 + RzRbar3*(0.008544921875 + RzRbar3*(0.02777099609375 + RzRbar3*(0.066650390625 + RzRbar3*(0.1221923828125 + RzRbar3*(0.174560546875 + RzRbar3*(0.196380615234375 + RzRbar3*(0.174560546875 + RzRbar3*(0.1221923828125 + RzRbar3*(0.066650390625 + RzRbar3*(0.02777099609375 + RzRbar3*(0.008544921875 + RzRbar3*(0.0018310546875 + (0.000244140625 + 0.0000152587890625*RzRbar3)*RzRbar3)))))))))))))))/Power(Mag30,16);
  }
  
  double D_8_neg7_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00006103515625 + RzRbar3*(0.0008544921875 + RzRbar3*(0.0054931640625 + RzRbar3*(0.0213623046875 + RzRbar3*(0.0555419921875 + RzRbar3*(0.0999755859375 + RzRbar3*(0.1221923828125 + RzRbar3*(0.0872802734375 + RzRbar3*(0.e-17 + RzRbar3*(-0.0872802734375 + RzRbar3*(-0.1221923828125 + RzRbar3*(-0.0999755859375 + RzRbar3*(-0.0555419921875 + RzRbar3*(-0.0213623046875 + RzRbar3*(-0.0054931640625 + (-0.0008544921875 - 0.00006103515625*RzRbar3)*RzRbar3)))))))))))))))/(Mag12*Power(Mag30,15));
  }
  
  double D_8_neg6_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00016715165939488712 + RzRbar3*(0.0020058199127386454 + RzRbar3*(0.010697706201272776 + RzRbar3*(0.03276172524139788 + RzRbar3*(0.06084320401973891 + RzRbar3*(0.06084320401973891 + RzRbar3*(0.e-16 + RzRbar3*(-0.0956107491738754 + RzRbar3*(-0.1434161237608131 + RzRbar3*(-0.0956107491738754 + RzRbar3*(0.e-17 + RzRbar3*(0.06084320401973891 + RzRbar3*(0.06084320401973891 + RzRbar3*(0.032761725241397875 + RzRbar3*(0.0106977062012727757 + (0.00200581991273864544 + 0.00016715165939488712*RzRbar3)*RzRbar3)))))))))))))))/(Power(Mag12,2)*Power(Mag30,14));
  }
  
  double D_8_neg5_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00036108885394895117 + RzRbar3*(0.0036108885394895117 + RzRbar3*(0.015165731865855949 + RzRbar3*(0.03249799685540561 + RzRbar3*(0.02816493060801819 + RzRbar3*(-0.0281649306080182 + RzRbar3*(-0.1032714122294 + RzRbar3*(-0.1032714122294 + RzRbar3*(0.e-16 + RzRbar3*(0.1032714122294 + RzRbar3*(0.1032714122294 + RzRbar3*(0.02816493060801819 + RzRbar3*(-0.02816493060801819 + RzRbar3*(-0.032497996855405606 + RzRbar3*(-0.015165731865855949 + (-0.0036108885394895117 - 0.000361088853948951174*RzRbar3)*RzRbar3)))))))))))))))/(Power(Mag12,3)*Power(Mag30,13));
  }
  
  double D_8_neg4_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0006509621889557355 + RzRbar3*(0.005207697511645884 + RzRbar3*(0.01562309253493765 + RzRbar3*(0.01562309253493765 + RzRbar3*(-0.0234346388024065 + RzRbar3*(-0.0781154626746883 + RzRbar3*(-0.0572846726281047 + RzRbar3*(0.0572846726281047 + RzRbar3*(0.1288905134132356 + RzRbar3*(0.0572846726281047 + RzRbar3*(-0.0572846726281047 + RzRbar3*(-0.0781154626746883 + RzRbar3*(-0.02343463880240648 + RzRbar3*(0.01562309253493765 + RzRbar3*(0.015623092534937653 + (0.0052076975116458842 + 0.000650962188955735527*RzRbar3)*RzRbar3)))))))))))))))/(Power(Mag12,4)*Power(Mag30,12));
  }
  
  double D_8_neg3_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0010084662867345158 + RzRbar3*(0.006050797720407095 + RzRbar3*(0.01008466286734516 + RzRbar3*(-0.01008466286734516 + RzRbar3*(-0.0504233143367258 + RzRbar3*(-0.0342878537489735 + RzRbar3*(0.066558774924478 + RzRbar3*(0.110931291540797 + RzRbar3*(0.e-15 + RzRbar3*(-0.1109312915407967 + RzRbar3*(-0.066558774924478 + RzRbar3*(0.0342878537489735 + RzRbar3*(0.05042331433672579 + RzRbar3*(0.01008466286734516 + RzRbar3*(-0.010084662867345157 + (-0.0060507977204070945 - 0.00100846628673451575*RzRbar3)*RzRbar3)))))))))))))))/(Power(Mag12,5)*Power(Mag30,11));
  }
  
  double D_8_neg2_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.001365469807201971 + RzRbar3*(0.005461879228807884 + RzRbar3*(0.e-17 + RzRbar3*(-0.0273093961440394 + RzRbar3*(-0.0273093961440394 + RzRbar3*(0.049156913059271 + RzRbar3*(0.087390067660926 + RzRbar3*(-0.027309396144039 + RzRbar3*(-0.122892282648177 + RzRbar3*(-0.027309396144039 + RzRbar3*(0.0873900676609261 + RzRbar3*(0.049156913059271 + RzRbar3*(-0.0273093961440394 + RzRbar3*(-0.02730939614403942 + RzRbar3*(0.e-18 + (0.0054618792288078842 + 0.00136546980720197105*RzRbar3)*RzRbar3)))))))))))))))/(Power(Mag12,6)*Power(Mag30,10));
  }
  
  double D_8_neg1_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0016320485787501145 + RzRbar3*(0.003264097157500229 + RzRbar3*(-0.00979229147250069 + RzRbar3*(-0.0228486801025016 + RzRbar3*(0.0228486801025016 + RzRbar3*(0.0685460403075048 + RzRbar3*(-0.022848680102502 + RzRbar3*(-0.114243400512508 + RzRbar3*(0.e-15 + RzRbar3*(0.114243400512508 + RzRbar3*(0.0228486801025016 + RzRbar3*(-0.0685460403075048 + RzRbar3*(-0.0228486801025016 + RzRbar3*(0.0228486801025016 + RzRbar3*(0.009792291472500687 + (-0.0032640971575002289 - 0.00163204857875011446*RzRbar3)*RzRbar3)))))))))))))))/(Power(Mag12,7)*Power(Mag30,9));
  }
  
  double D_8_0_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0017310489258901096 + Power(RzRbar3,2)*(-0.013848391407120877 + Power(RzRbar3,2)*(0.048469369924923069 + Power(RzRbar3,2)*(-0.096938739849846137 + Power(RzRbar3,2)*(0.121173424812307671 + Power(RzRbar3,2)*(-0.096938739849846137 + Power(RzRbar3,2)*(0.048469369924923069 + Power(RzRbar3,2)*(-0.0138483914071208767 + 0.00173104892589010959*Power(RzRbar3,2)))))))))/(Power(Mag12,8)*Power(Mag30,8));
  }
  
  double D_8_1_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0016320485787501145 + RzRbar3*(-0.003264097157500229 + RzRbar3*(-0.00979229147250069 + RzRbar3*(0.0228486801025016 + RzRbar3*(0.0228486801025016 + RzRbar3*(-0.0685460403075048 + RzRbar3*(-0.022848680102502 + RzRbar3*(0.114243400512508 + RzRbar3*(0.e-15 + RzRbar3*(-0.114243400512508 + RzRbar3*(0.0228486801025016 + RzRbar3*(0.0685460403075048 + RzRbar3*(-0.0228486801025016 + RzRbar3*(-0.0228486801025016 + RzRbar3*(0.009792291472500687 + (0.0032640971575002289 - 0.00163204857875011446*RzRbar3)*RzRbar3)))))))))))))))/(Power(Mag12,9)*Power(Mag30,7));
  }
  
  double D_8_2_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.001365469807201971 + RzRbar3*(-0.005461879228807884 + RzRbar3*(0.e-17 + RzRbar3*(0.0273093961440394 + RzRbar3*(-0.0273093961440394 + RzRbar3*(-0.049156913059271 + RzRbar3*(0.087390067660926 + RzRbar3*(0.027309396144039 + RzRbar3*(-0.122892282648177 + RzRbar3*(0.027309396144039 + RzRbar3*(0.0873900676609261 + RzRbar3*(-0.049156913059271 + RzRbar3*(-0.0273093961440394 + RzRbar3*(0.02730939614403942 + RzRbar3*(0.e-18 + (-0.0054618792288078842 + 0.00136546980720197105*RzRbar3)*RzRbar3)))))))))))))))/(Power(Mag12,10)*Power(Mag30,6));
  }
  
  double D_8_3_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0010084662867345158 + RzRbar3*(-0.006050797720407095 + RzRbar3*(0.01008466286734516 + RzRbar3*(0.01008466286734516 + RzRbar3*(-0.0504233143367258 + RzRbar3*(0.0342878537489735 + RzRbar3*(0.066558774924478 + RzRbar3*(-0.110931291540797 + RzRbar3*(0.e-15 + RzRbar3*(0.1109312915407967 + RzRbar3*(-0.066558774924478 + RzRbar3*(-0.0342878537489735 + RzRbar3*(0.05042331433672579 + RzRbar3*(-0.01008466286734516 + RzRbar3*(-0.010084662867345157 + (0.0060507977204070945 - 0.00100846628673451575*RzRbar3)*RzRbar3)))))))))))))))/(Power(Mag12,11)*Power(Mag30,5));
  }
  
  double D_8_4_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0006509621889557355 + RzRbar3*(-0.005207697511645884 + RzRbar3*(0.01562309253493765 + RzRbar3*(-0.01562309253493765 + RzRbar3*(-0.0234346388024065 + RzRbar3*(0.0781154626746883 + RzRbar3*(-0.0572846726281047 + RzRbar3*(-0.0572846726281047 + RzRbar3*(0.1288905134132356 + RzRbar3*(-0.0572846726281047 + RzRbar3*(-0.0572846726281047 + RzRbar3*(0.0781154626746883 + RzRbar3*(-0.02343463880240648 + RzRbar3*(-0.01562309253493765 + RzRbar3*(0.015623092534937653 + (-0.0052076975116458842 + 0.000650962188955735527*RzRbar3)*RzRbar3)))))))))))))))/(Power(Mag12,12)*Power(Mag30,4));
  }
  
  double D_8_5_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00036108885394895117 + RzRbar3*(-0.0036108885394895117 + RzRbar3*(0.015165731865855949 + RzRbar3*(-0.03249799685540561 + RzRbar3*(0.02816493060801819 + RzRbar3*(0.0281649306080182 + RzRbar3*(-0.1032714122294 + RzRbar3*(0.1032714122294 + RzRbar3*(0.e-16 + RzRbar3*(-0.1032714122294 + RzRbar3*(0.1032714122294 + RzRbar3*(-0.02816493060801819 + RzRbar3*(-0.02816493060801819 + RzRbar3*(0.032497996855405606 + RzRbar3*(-0.015165731865855949 + (0.0036108885394895117 - 0.000361088853948951174*RzRbar3)*RzRbar3)))))))))))))))/(Power(Mag12,13)*Power(Mag30,3));
  }
  
  double D_8_6_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00016715165939488712 + RzRbar3*(-0.0020058199127386454 + RzRbar3*(0.010697706201272776 + RzRbar3*(-0.03276172524139788 + RzRbar3*(0.06084320401973891 + RzRbar3*(-0.06084320401973891 + RzRbar3*(0.e-16 + RzRbar3*(0.0956107491738754 + RzRbar3*(-0.1434161237608131 + RzRbar3*(0.0956107491738754 + RzRbar3*(0.e-17 + RzRbar3*(-0.06084320401973891 + RzRbar3*(0.06084320401973891 + RzRbar3*(-0.032761725241397875 + RzRbar3*(0.0106977062012727757 + (-0.00200581991273864544 + 0.00016715165939488712*RzRbar3)*RzRbar3)))))))))))))))/(Power(Mag12,14)*Power(Mag30,2));
  }
  
  double D_8_7_neg8() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00006103515625 + RzRbar3*(-0.0008544921875 + RzRbar3*(0.0054931640625 + RzRbar3*(-0.0213623046875 + RzRbar3*(0.0555419921875 + RzRbar3*(-0.0999755859375 + RzRbar3*(0.1221923828125 + RzRbar3*(-0.0872802734375 + RzRbar3*(0.e-17 + RzRbar3*(0.0872802734375 + RzRbar3*(-0.1221923828125 + RzRbar3*(0.0999755859375 + RzRbar3*(-0.0555419921875 + RzRbar3*(0.0213623046875 + RzRbar3*(-0.0054931640625 + (0.0008544921875 - 0.00006103515625*RzRbar3)*RzRbar3)))))))))))))))/(Power(Mag12,15)*Mag30);
  }
  
  double D_8_8_neg8() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0000152587890625 + RzRbar3*(-0.000244140625 + RzRbar3*(0.0018310546875 + RzRbar3*(-0.008544921875 + RzRbar3*(0.02777099609375 + RzRbar3*(-0.066650390625 + RzRbar3*(0.1221923828125 + RzRbar3*(-0.174560546875 + RzRbar3*(0.196380615234375 + RzRbar3*(-0.174560546875 + RzRbar3*(0.1221923828125 + RzRbar3*(-0.066650390625 + RzRbar3*(0.02777099609375 + RzRbar3*(-0.008544921875 + RzRbar3*(0.0018310546875 + (-0.000244140625 + 0.0000152587890625*RzRbar3)*RzRbar3)))))))))))))))/Power(Mag12,16);
  }
  
  double D_8_neg8_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0001220703125*Mag12 + RzRbar3*(-0.0018310546875*Mag12 + RzRbar3*(-0.0128173828125*Mag12 + RzRbar3*(-0.0555419921875*Mag12 + RzRbar3*(-0.1666259765625*Mag12 + RzRbar3*(-0.3665771484375*Mag12 + RzRbar3*(-0.6109619140625*Mag12 + RzRbar3*(-0.7855224609375*Mag12 + RzRbar3*(-0.7855224609375*Mag12 + RzRbar3*(-0.6109619140625*Mag12 + RzRbar3*(-0.3665771484375*Mag12 + RzRbar3*(-0.1666259765625*Mag12 + RzRbar3*(-0.0555419921875*Mag12 + RzRbar3*(-0.0128173828125*Mag12 + RzRbar3*(-0.0018310546875*Mag12 - 0.0001220703125*Mag12*RzRbar3)))))))))))))))/Power(Mag30,15);
  }
  
  double D_8_neg7_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.00042724609375 + RzRbar3*(-0.0054931640625 + RzRbar3*(-0.03204345703125 + RzRbar3*(-0.111083984375 + RzRbar3*(-0.24993896484375 + RzRbar3*(-0.3665771484375 + RzRbar3*(-0.30548095703125 + RzRbar3*(0.e-16 + RzRbar3*(0.39276123046875 + RzRbar3*(0.6109619140625 + RzRbar3*(0.54986572265625 + RzRbar3*(0.333251953125 + RzRbar3*(0.13885498046875 + RzRbar3*(0.0384521484375 + (0.00640869140625 + 0.00048828125*RzRbar3)*RzRbar3))))))))))))))/Power(Mag30,14);
  }
  
  double D_8_neg6_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0010029099563693227 + RzRbar3*(-0.010697706201272776 + RzRbar3*(-0.04914258786209681 + RzRbar3*(-0.12168640803947782 + RzRbar3*(-0.1521080100493473 + RzRbar3*(0.e-16 + RzRbar3*(0.334637622108564 + RzRbar3*(0.5736644950432526 + RzRbar3*(0.4302483712824394 + RzRbar3*(0.e-16 + RzRbar3*(-0.334637622108564 + RzRbar3*(-0.36505922411843347 + RzRbar3*(-0.21295121406908619 + RzRbar3*(-0.07488394340890943 + (-0.0150436493455398408 - 0.00133721327515909696*RzRbar3)*RzRbar3))))))))))))))/(Mag12*Power(Mag30,13));
  }
  
  double D_8_neg5_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0018054442697447559 + RzRbar3*(-0.015165731865855949 + RzRbar3*(-0.04874699528310841 + RzRbar3*(-0.0563298612160364 + RzRbar3*(0.0704123265200455 + RzRbar3*(0.3098142366882001 + RzRbar3*(0.3614499428029 + RzRbar3*(0.e-15 + RzRbar3*(-0.4647213550323 + RzRbar3*(-0.5163570611470002 + RzRbar3*(-0.1549071183441001 + RzRbar3*(0.1689895836481091 + RzRbar3*(0.21123697956013644 + RzRbar3*(0.106160123060991645 + (0.027081664046171338 + 0.0028887108315916094*RzRbar3)*RzRbar3))))))))))))))/(Power(Mag12,2)*Power(Mag30,12));
  }
  
  double D_8_neg4_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0026038487558229421 + RzRbar3*(-0.015623092534937653 + RzRbar3*(-0.02343463880240648 + RzRbar3*(0.046869277604813 + RzRbar3*(0.1952886566867207 + RzRbar3*(0.171854017884314 + RzRbar3*(-0.200496354198367 + RzRbar3*(-0.515562053652943 + RzRbar3*(-0.257781026826471 + RzRbar3*(0.286423363140524 + RzRbar3*(0.4296350447107854 + RzRbar3*(0.1406078328144389 + RzRbar3*(-0.10155010147709474 + RzRbar3*(-0.10936164774456357 + (-0.039057731337344132 - 0.0052076975116458842*RzRbar3)*RzRbar3))))))))))))))/(Power(Mag12,3)*Power(Mag30,11));
  }
  
  double D_8_neg3_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0030253988602035473 + RzRbar3*(-0.010084662867345158 + RzRbar3*(0.01512699430101774 + RzRbar3*(0.1008466286734516 + RzRbar3*(0.0857196343724338 + RzRbar3*(-0.199676324773434 + RzRbar3*(-0.388259520392789 + RzRbar3*(0.e-15 + RzRbar3*(0.499190811933585 + RzRbar3*(0.33279387462239 + RzRbar3*(-0.188583195619354 + RzRbar3*(-0.3025398860203547 + RzRbar3*(-0.0655503086377435 + RzRbar3*(0.0705926400714161 + (0.045380982903053209 + 0.008067730293876126*RzRbar3)*RzRbar3))))))))))))))/(Power(Mag12,4)*Power(Mag30,10));
  }
  
  double D_8_neg2_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0027309396144039421 + RzRbar3*(0.e-18 + RzRbar3*(0.04096409421605913 + RzRbar3*(0.0546187922880788 + RzRbar3*(-0.1228922826481774 + RzRbar3*(-0.262170202982778 + RzRbar3*(0.095582886504138 + RzRbar3*(0.49156913059271 + RzRbar3*(0.122892282648177 + RzRbar3*(-0.436950338304631 + RzRbar3*(-0.27036302182599 + RzRbar3*(0.1638563768642365 + RzRbar3*(0.1775110749362562 + RzRbar3*(0.e-17 + (-0.040964094216059131 - 0.0109237584576157684*RzRbar3)*RzRbar3))))))))))))))/(Power(Mag12,5)*Power(Mag30,9));
  }
  
  double D_8_neg1_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0016320485787501145 + RzRbar3*(0.009792291472500687 + RzRbar3*(0.0342730201537524 + RzRbar3*(-0.0456973602050032 + RzRbar3*(-0.171365100768762 + RzRbar3*(0.068546040307505 + RzRbar3*(0.399851901793778 + RzRbar3*(0.e-15 + RzRbar3*(-0.514095302306286 + RzRbar3*(-0.114243400512508 + RzRbar3*(0.377003221691276 + RzRbar3*(0.1370920806150096 + RzRbar3*(-0.1485164206662604 + RzRbar3*(-0.06854604030750481 + (0.024480728681251717 + 0.0130563886300009157*RzRbar3)*RzRbar3))))))))))))))/(Power(Mag12,6)*Power(Mag30,8));
  }
  
  double D_8_0_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(0.013848391407120877 + Power(RzRbar3,2)*(-0.096938739849846137 + Power(RzRbar3,2)*(0.29081621954953841 + Power(RzRbar3,2)*(-0.48469369924923069 + Power(RzRbar3,2)*(0.48469369924923069 + Power(RzRbar3,2)*(-0.290816219549538411 + Power(RzRbar3,2)*(0.096938739849846137 - 0.0138483914071208767*Power(RzRbar3,2)))))))))/(Power(Mag12,7)*Power(Mag30,7));
  }
  
  double D_8_1_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0016320485787501145 + RzRbar3*(0.009792291472500687 + RzRbar3*(-0.0342730201537524 + RzRbar3*(-0.0456973602050032 + RzRbar3*(0.171365100768762 + RzRbar3*(0.068546040307505 + RzRbar3*(-0.399851901793778 + RzRbar3*(0.e-15 + RzRbar3*(0.514095302306286 + RzRbar3*(-0.114243400512508 + RzRbar3*(-0.377003221691276 + RzRbar3*(0.1370920806150096 + RzRbar3*(0.1485164206662604 + RzRbar3*(-0.06854604030750481 + (-0.024480728681251717 + 0.0130563886300009157*RzRbar3)*RzRbar3))))))))))))))/(Power(Mag12,8)*Power(Mag30,6));
  }
  
  double D_8_2_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0027309396144039421 + RzRbar3*(0.e-18 + RzRbar3*(-0.04096409421605913 + RzRbar3*(0.0546187922880788 + RzRbar3*(0.1228922826481774 + RzRbar3*(-0.262170202982778 + RzRbar3*(-0.095582886504138 + RzRbar3*(0.49156913059271 + RzRbar3*(-0.122892282648177 + RzRbar3*(-0.436950338304631 + RzRbar3*(0.27036302182599 + RzRbar3*(0.1638563768642365 + RzRbar3*(-0.1775110749362562 + RzRbar3*(0.e-17 + (0.040964094216059131 - 0.0109237584576157684*RzRbar3)*RzRbar3))))))))))))))/(Power(Mag12,9)*Power(Mag30,5));
  }
  
  double D_8_3_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0030253988602035473 + RzRbar3*(-0.010084662867345158 + RzRbar3*(-0.01512699430101774 + RzRbar3*(0.1008466286734516 + RzRbar3*(-0.0857196343724338 + RzRbar3*(-0.199676324773434 + RzRbar3*(0.388259520392789 + RzRbar3*(0.e-15 + RzRbar3*(-0.499190811933585 + RzRbar3*(0.33279387462239 + RzRbar3*(0.188583195619354 + RzRbar3*(-0.3025398860203547 + RzRbar3*(0.0655503086377435 + RzRbar3*(0.0705926400714161 + (-0.045380982903053209 + 0.008067730293876126*RzRbar3)*RzRbar3))))))))))))))/(Power(Mag12,10)*Power(Mag30,4));
  }
  
  double D_8_4_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0026038487558229421 + RzRbar3*(-0.015623092534937653 + RzRbar3*(0.02343463880240648 + RzRbar3*(0.046869277604813 + RzRbar3*(-0.1952886566867207 + RzRbar3*(0.171854017884314 + RzRbar3*(0.200496354198367 + RzRbar3*(-0.515562053652943 + RzRbar3*(0.257781026826471 + RzRbar3*(0.286423363140524 + RzRbar3*(-0.4296350447107854 + RzRbar3*(0.1406078328144389 + RzRbar3*(0.10155010147709474 + RzRbar3*(-0.10936164774456357 + (0.039057731337344132 - 0.0052076975116458842*RzRbar3)*RzRbar3))))))))))))))/(Power(Mag12,11)*Power(Mag30,3));
  }
  
  double D_8_5_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0018054442697447559 + RzRbar3*(-0.015165731865855949 + RzRbar3*(0.04874699528310841 + RzRbar3*(-0.0563298612160364 + RzRbar3*(-0.0704123265200455 + RzRbar3*(0.3098142366882001 + RzRbar3*(-0.3614499428029 + RzRbar3*(0.e-15 + RzRbar3*(0.4647213550323 + RzRbar3*(-0.5163570611470002 + RzRbar3*(0.1549071183441001 + RzRbar3*(0.1689895836481091 + RzRbar3*(-0.21123697956013644 + RzRbar3*(0.106160123060991645 + (-0.027081664046171338 + 0.0028887108315916094*RzRbar3)*RzRbar3))))))))))))))/(Power(Mag12,12)*Power(Mag30,2));
  }
  
  double D_8_6_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0010029099563693227 + RzRbar3*(-0.010697706201272776 + RzRbar3*(0.04914258786209681 + RzRbar3*(-0.12168640803947782 + RzRbar3*(0.1521080100493473 + RzRbar3*(0.e-16 + RzRbar3*(-0.334637622108564 + RzRbar3*(0.5736644950432526 + RzRbar3*(-0.4302483712824394 + RzRbar3*(0.e-16 + RzRbar3*(0.334637622108564 + RzRbar3*(-0.36505922411843347 + RzRbar3*(0.21295121406908619 + RzRbar3*(-0.07488394340890943 + (0.0150436493455398408 - 0.00133721327515909696*RzRbar3)*RzRbar3))))))))))))))/(Power(Mag12,13)*Mag30);
  }
  
  double D_8_7_neg7() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00042724609375 + RzRbar3*(-0.0054931640625 + RzRbar3*(0.03204345703125 + RzRbar3*(-0.111083984375 + RzRbar3*(0.24993896484375 + RzRbar3*(-0.3665771484375 + RzRbar3*(0.30548095703125 + RzRbar3*(0.e-16 + RzRbar3*(-0.39276123046875 + RzRbar3*(0.6109619140625 + RzRbar3*(-0.54986572265625 + RzRbar3*(0.333251953125 + RzRbar3*(-0.13885498046875 + RzRbar3*(0.0384521484375 + (-0.00640869140625 + 0.00048828125*RzRbar3)*RzRbar3))))))))))))))/Power(Mag12,14);
  }
  
  double D_8_8_neg7() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0001220703125*Mag30 + RzRbar3*(-0.0018310546875*Mag30 + RzRbar3*(0.0128173828125*Mag30 + RzRbar3*(-0.0555419921875*Mag30 + RzRbar3*(0.1666259765625*Mag30 + RzRbar3*(-0.3665771484375*Mag30 + RzRbar3*(0.6109619140625*Mag30 + RzRbar3*(-0.7855224609375*Mag30 + RzRbar3*(0.7855224609375*Mag30 + RzRbar3*(-0.6109619140625*Mag30 + RzRbar3*(0.3665771484375*Mag30 + RzRbar3*(-0.1666259765625*Mag30 + RzRbar3*(0.0555419921875*Mag30 + RzRbar3*(-0.0128173828125*Mag30 + RzRbar3*(0.0018310546875*Mag30 - 0.0001220703125*Mag30*RzRbar3)))))))))))))))/Power(Mag12,15);
  }
  
  double D_8_neg8_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0006686066375795485*Power(Mag12,2) + RzRbar3*(0.009360492926113679*Power(Mag12,2) + RzRbar3*(0.060843204019738912*Power(Mag12,2) + RzRbar3*(0.24337281607895565*Power(Mag12,2) + RzRbar3*(0.66927524421712803*Power(Mag12,2) + RzRbar3*(1.3385504884342561*Power(Mag12,2) + RzRbar3*(2.0078257326513841*Power(Mag12,2) + RzRbar3*(2.2946579801730104*Power(Mag12,2) + RzRbar3*(2.0078257326513841*Power(Mag12,2) + RzRbar3*(1.33855048843425605*Power(Mag12,2) + RzRbar3*(0.66927524421712803*Power(Mag12,2) + RzRbar3*(0.243372816078955646*Power(Mag12,2) + RzRbar3*(0.060843204019738912*Power(Mag12,2) + RzRbar3*(0.0093604929261136787*Power(Mag12,2) + 0.000668606637579548478*Power(Mag12,2)*RzRbar3))))))))))))))/Power(Mag30,14);
  }
  
  double D_8_neg7_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0020058199127386454*Mag12 + RzRbar3*(0.023401232315284197*Mag12 + RzRbar3*(0.12168640803947782*Mag12 + RzRbar3*(0.36505922411843347*Mag12 + RzRbar3*(0.669275244217128*Mag12 + RzRbar3*(0.669275244217128*Mag12 + RzRbar3*(0.e-16*Mag12 + RzRbar3*(-1.1473289900865052*Mag12 + RzRbar3*(-2.0078257326513841*Mag12 + RzRbar3*(-2.0078257326513841*Mag12 + RzRbar3*(-1.3385504884342561*Mag12 + RzRbar3*(-0.60843204019738912*Mag12 + RzRbar3*(-0.182529612059216735*Mag12 + RzRbar3*(-0.032761725241397875*Mag12 - 0.00267442655031819391*Mag12*RzRbar3))))))))))))))/Power(Mag30,13);
  }
  
  double D_8_neg6_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00390625 + RzRbar3*(0.035888671875 + RzRbar3*(0.13330078125 + RzRbar3*(0.22216796875 + RzRbar3*(0.e-16 + RzRbar3*(-0.733154296875 + RzRbar3*(-1.46630859375 + RzRbar3*(-1.2568359375 + RzRbar3*(0.e-15 + RzRbar3*(1.221923828125 + RzRbar3*(1.46630859375 + RzRbar3*(0.93310546875 + RzRbar3*(0.35546875 + (0.076904296875 + 0.00732421875*RzRbar3)*RzRbar3)))))))))))))/Power(Mag30,12);
  }
  
  double D_8_neg5_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0055377422960028103 + RzRbar3*(0.03559977190287521 + RzRbar3*(0.06170627129831703 + RzRbar3*(-0.102843785497195 + RzRbar3*(-0.5656408202345728 + RzRbar3*(-0.791897148328402 + RzRbar3*(0.e-15 + RzRbar3*(1.357537968562975 + RzRbar3*(1.696922460703718 + RzRbar3*(0.565640820234573 + RzRbar3*(-0.6787689842814873 + RzRbar3*(-0.9255940694747554 + RzRbar3*(-0.50393454893625573 + (-0.138443557400070256 - 0.015822120845722315*RzRbar3)*RzRbar3)))))))))))))/(Mag12*Power(Mag30,11));
  }
  
  double D_8_neg4_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0057047467995839466 + RzRbar3*(0.01711424039875184 + RzRbar3*(-0.05134272119625552 + RzRbar3*(-0.2852373399791973 + RzRbar3*(-0.313761073977117 + RzRbar3*(0.439265503567964 + RzRbar3*(1.317796510703892 + RzRbar3*(0.753026577545081 + RzRbar3*(-0.941283221931351 + RzRbar3*(-1.568805369885585 + RzRbar3*(-0.5647699331588107 + RzRbar3*(0.4449702503675478 + RzRbar3*(0.51913195876213914 + (0.199666137985438131 + 0.0285237339979197329*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,2)*Power(Mag30,10));
  }
  
  double D_8_neg3_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0036823982248531143 + RzRbar3*(-0.01104719467455934 + RzRbar3*(-0.11047194674559343 + RzRbar3*(-0.1252015396450059 + RzRbar3*(0.364557424260458 + RzRbar3*(0.850633989941069 + RzRbar3*(0.e-15 + RzRbar3*(-1.458229697041833 + RzRbar3*(-1.093672272781375 + RzRbar3*(0.688608468047532 + RzRbar3*(1.215191414201528 + RzRbar3*(0.2872270615385429 + RzRbar3*(-0.3350982384616334 + (-0.2319910881657462 - 0.0441887786982373713*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,3)*Power(Mag30,9));
  }
  
  double D_8_neg2_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-0.029915944599869987 + RzRbar3*(-0.05983188919973997 + RzRbar3*(0.1794956675992199 + RzRbar3*(0.47865511359792 + RzRbar3*(-0.20941161219909 + RzRbar3*(-1.256469673194539 + RzRbar3*(-0.35899133519844 + RzRbar3*(1.435965340793759 + RzRbar3*(0.98722617179571 + RzRbar3*(-0.65815078119714 + RzRbar3*(-0.7778145595966197 + RzRbar3*(0.e-16 + (0.20941161219908991 + 0.059831889199739974*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,4)*Power(Mag30,8));
  }
  
  double D_8_neg1_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0035756392861027368 + RzRbar3*(-0.025029475002719157 + RzRbar3*(0.05005895000543831 + RzRbar3*(0.2502947500271916 + RzRbar3*(-0.125147375013596 + RzRbar3*(-0.876031625095171 + RzRbar3*(0.e-15 + RzRbar3*(1.501768500163149 + RzRbar3*(0.375442125040787 + RzRbar3*(-1.376621125149554 + RzRbar3*(-0.550648450059821 + RzRbar3*(0.6507663500706981 + RzRbar3*(0.325383175035349 + (-0.12514737501359579 - 0.071512785722054735*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,5)*Power(Mag30,7));
  }
  
  double D_8_0_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0050567175725605418 + Power(RzRbar3,2)*(0.106191069023771377 + Power(RzRbar3,2)*(-0.53095534511885689 + Power(RzRbar3,2)*(1.23889580527733274 + Power(RzRbar3,2)*(-1.59286603535657066 + Power(RzRbar3,2)*(1.16810175926148515 + Power(RzRbar3,2)*(-0.4601612991030093 + 0.075850763588408127*Power(RzRbar3,2))))))))/(Power(Mag12,6)*Power(Mag30,6));
  }
  
  double D_8_1_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0035756392861027368 + RzRbar3*(0.025029475002719157 + RzRbar3*(0.05005895000543831 + RzRbar3*(-0.2502947500271916 + RzRbar3*(-0.125147375013596 + RzRbar3*(0.876031625095171 + RzRbar3*(0.e-15 + RzRbar3*(-1.501768500163149 + RzRbar3*(0.375442125040787 + RzRbar3*(1.376621125149554 + RzRbar3*(-0.550648450059821 + RzRbar3*(-0.6507663500706981 + RzRbar3*(0.325383175035349 + (0.12514737501359579 - 0.071512785722054735*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,7)*Power(Mag30,5));
  }
  
  double D_8_2_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(0.029915944599869987 + RzRbar3*(-0.05983188919973997 + RzRbar3*(-0.1794956675992199 + RzRbar3*(0.47865511359792 + RzRbar3*(0.20941161219909 + RzRbar3*(-1.256469673194539 + RzRbar3*(0.35899133519844 + RzRbar3*(1.435965340793759 + RzRbar3*(-0.98722617179571 + RzRbar3*(-0.65815078119714 + RzRbar3*(0.7778145595966197 + RzRbar3*(0.e-16 + (-0.20941161219908991 + 0.059831889199739974*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,8)*Power(Mag30,4));
  }
  
  double D_8_3_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0036823982248531143 + RzRbar3*(0.01104719467455934 + RzRbar3*(-0.11047194674559343 + RzRbar3*(0.1252015396450059 + RzRbar3*(0.364557424260458 + RzRbar3*(-0.850633989941069 + RzRbar3*(0.e-15 + RzRbar3*(1.458229697041833 + RzRbar3*(-1.093672272781375 + RzRbar3*(-0.688608468047532 + RzRbar3*(1.215191414201528 + RzRbar3*(-0.2872270615385429 + RzRbar3*(-0.3350982384616334 + (0.2319910881657462 - 0.0441887786982373713*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,9)*Power(Mag30,3));
  }
  
  double D_8_4_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0057047467995839466 + RzRbar3*(-0.01711424039875184 + RzRbar3*(-0.05134272119625552 + RzRbar3*(0.2852373399791973 + RzRbar3*(-0.313761073977117 + RzRbar3*(-0.439265503567964 + RzRbar3*(1.317796510703892 + RzRbar3*(-0.753026577545081 + RzRbar3*(-0.941283221931351 + RzRbar3*(1.568805369885585 + RzRbar3*(-0.5647699331588107 + RzRbar3*(-0.4449702503675478 + RzRbar3*(0.51913195876213914 + (-0.199666137985438131 + 0.0285237339979197329*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,10)*Power(Mag30,2));
  }
  
  double D_8_5_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0055377422960028103 + RzRbar3*(-0.03559977190287521 + RzRbar3*(0.06170627129831703 + RzRbar3*(0.102843785497195 + RzRbar3*(-0.5656408202345728 + RzRbar3*(0.791897148328402 + RzRbar3*(0.e-15 + RzRbar3*(-1.357537968562975 + RzRbar3*(1.696922460703718 + RzRbar3*(-0.565640820234573 + RzRbar3*(-0.6787689842814873 + RzRbar3*(0.9255940694747554 + RzRbar3*(-0.50393454893625573 + (0.138443557400070256 - 0.015822120845722315*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,11)*Mag30);
  }
  
  double D_8_6_neg6() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00390625 + RzRbar3*(-0.035888671875 + RzRbar3*(0.13330078125 + RzRbar3*(-0.22216796875 + RzRbar3*(0.e-16 + RzRbar3*(0.733154296875 + RzRbar3*(-1.46630859375 + RzRbar3*(1.2568359375 + RzRbar3*(0.e-15 + RzRbar3*(-1.221923828125 + RzRbar3*(1.46630859375 + RzRbar3*(-0.93310546875 + RzRbar3*(0.35546875 + (-0.076904296875 + 0.00732421875*RzRbar3)*RzRbar3)))))))))))))/Power(Mag12,12);
  }
  
  double D_8_7_neg6() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0020058199127386454*Mag30 + RzRbar3*(-0.023401232315284197*Mag30 + RzRbar3*(0.12168640803947782*Mag30 + RzRbar3*(-0.36505922411843347*Mag30 + RzRbar3*(0.669275244217128*Mag30 + RzRbar3*(-0.669275244217128*Mag30 + RzRbar3*(0.e-16*Mag30 + RzRbar3*(1.1473289900865052*Mag30 + RzRbar3*(-2.0078257326513841*Mag30 + RzRbar3*(2.0078257326513841*Mag30 + RzRbar3*(-1.3385504884342561*Mag30 + RzRbar3*(0.60843204019738912*Mag30 + RzRbar3*(-0.182529612059216735*Mag30 + RzRbar3*(0.032761725241397875*Mag30 - 0.00267442655031819391*Mag30*RzRbar3))))))))))))))/Power(Mag12,13);
  }
  
  double D_8_8_neg6() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0006686066375795485*Power(Mag30,2) + RzRbar3*(-0.009360492926113679*Power(Mag30,2) + RzRbar3*(0.060843204019738912*Power(Mag30,2) + RzRbar3*(-0.24337281607895565*Power(Mag30,2) + RzRbar3*(0.66927524421712803*Power(Mag30,2) + RzRbar3*(-1.3385504884342561*Power(Mag30,2) + RzRbar3*(2.0078257326513841*Power(Mag30,2) + RzRbar3*(-2.2946579801730104*Power(Mag30,2) + RzRbar3*(2.0078257326513841*Power(Mag30,2) + RzRbar3*(-1.33855048843425605*Power(Mag30,2) + RzRbar3*(0.66927524421712803*Power(Mag30,2) + RzRbar3*(-0.243372816078955646*Power(Mag30,2) + RzRbar3*(0.060843204019738912*Power(Mag30,2) + RzRbar3*(-0.0093604929261136787*Power(Mag30,2) + 0.000668606637579548478*Power(Mag30,2)*RzRbar3))))))))))))))/Power(Mag12,14);
  }
  
  double D_8_neg8_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0028887108315916094*Power(Mag12,3) + RzRbar3*(-0.037553240810690922*Power(Mag12,3) + RzRbar3*(-0.22531944486414553*Power(Mag12,3) + RzRbar3*(-0.82617129783520029*Power(Mag12,3) + RzRbar3*(-2.0654282445880007*Power(Mag12,3) + RzRbar3*(-3.7177708402584013*Power(Mag12,3) + RzRbar3*(-4.9570277870112017*Power(Mag12,3) + RzRbar3*(-4.9570277870112017*Power(Mag12,3) + RzRbar3*(-3.7177708402584013*Power(Mag12,3) + RzRbar3*(-2.0654282445880007*Power(Mag12,3) + RzRbar3*(-0.82617129783520029*Power(Mag12,3) + RzRbar3*(-0.225319444864145533*Power(Mag12,3) + RzRbar3*(-0.0375532408106909221*Power(Mag12,3) - 0.0028887108315916094*Power(Mag12,3)*RzRbar3)))))))))))))/Power(Mag30,13);
  }
  
  double D_8_neg7_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.007221777078979023*Power(Mag12,2) + RzRbar3*(-0.07510648162138184*Power(Mag12,2) + RzRbar3*(-0.3379791672962183*Power(Mag12,2) + RzRbar3*(-0.8261712978352003*Power(Mag12,2) + RzRbar3*(-1.0327141222940004*Power(Mag12,2) + RzRbar3*(0.e-15*Power(Mag12,2) + RzRbar3*(2.478513893505601*Power(Mag12,2) + RzRbar3*(4.957027787011202*Power(Mag12,2) + RzRbar3*(5.5766562603876019*Power(Mag12,2) + RzRbar3*(4.1308564891760014*Power(Mag12,2) + RzRbar3*(2.0654282445880007*Power(Mag12,2) + RzRbar3*(0.6759583345924366*Power(Mag12,2) + RzRbar3*(0.131436342837418228*Power(Mag12,2) + 0.0115548433263664376*Power(Mag12,2)*RzRbar3)))))))))))))/Power(Mag30,12);
  }
  
  double D_8_neg6_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.011075484592005621*Mag12 + RzRbar3*(-0.08227502839775604*Mag12 + RzRbar3*(-0.2056875709943901*Mag12 + RzRbar3*(0.e-16*Mag12 + RzRbar3*(1.131281640469146*Mag12 + RzRbar3*(2.715075937125949*Mag12 + RzRbar3*(2.715075937125949*Mag12 + RzRbar3*(0.e-15*Mag12 + RzRbar3*(-3.393844921407437*Mag12 + RzRbar3*(-4.5251265618765821*Mag12 + RzRbar3*(-3.1675885933136075*Mag12 + RzRbar3*(-1.31640045436409661*Mag12 + RzRbar3*(-0.30853135649158514*Mag12 - 0.03164424169144463*Mag12*RzRbar3)))))))))))))/Power(Mag30,11);
  }
  
  double D_8_neg5_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.010986328125 + RzRbar3*(-0.0380859375 + RzRbar3*(0.09521484375 + RzRbar3*(0.6982421875 + RzRbar3*(1.221923828125 + RzRbar3*(0.e-15 + RzRbar3*(-2.9326171875 + RzRbar3*(-4.189453125 + RzRbar3*(-1.571044921875 + RzRbar3*(2.0947265625 + RzRbar3*(3.14208984375 + RzRbar3*(1.8662109375 + (0.555419921875 + 0.068359375*RzRbar3)*RzRbar3))))))))))))/Power(Mag30,10);
  }
  
  double D_8_neg4_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0052815692511679531 + RzRbar3*(0.03168941550700772 + RzRbar3*(0.2640784625583977 + RzRbar3*(0.3873150784189832 + RzRbar3*(-0.677801387233221 + RzRbar3*(-2.440084994039594 + RzRbar3*(-1.62672332935973 + RzRbar3*(2.323890470513899 + RzRbar3*(4.357294632213561 + RzRbar3*(1.742917852885425 + RzRbar3*(-1.510528805834035 + RzRbar3*(-1.9224912074251349 + (-0.80103800309380622 - 0.123236615860585572*RzRbar3)*RzRbar3))))))))))))/(Mag12*Power(Mag30,9));
  }
  
  double D_8_neg3_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0034092382919357767 + RzRbar3*(0.068184765838715533 + RzRbar3*(0.11591410192581641 + RzRbar3*(-0.4500194545355225 + RzRbar3*(-1.312556742395274 + RzRbar3*(0.e-15 + RzRbar3*(3.150136181748658 + RzRbar3*(2.700116727213135 + RzRbar3*(-1.912582681775971 + RzRbar3*(-3.750162121129354 + RzRbar3*(-0.975042151493632 + RzRbar3*(1.2409627382646227 + (0.93072205369846703 + 0.190917344348403493*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,2)*Power(Mag30,8));
  }
  
  double D_8_neg2_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.009232260938080584 + RzRbar3*(0.036929043752322338 + RzRbar3*(-0.16618069688545052 + RzRbar3*(-0.5908647000371574 + RzRbar3*(0.32312913283282 + RzRbar3*(2.326529756396307 + RzRbar3*(0.775509918798769 + RzRbar3*(-3.545188200222944 + RzRbar3*(-2.741981498609934 + RzRbar3*(2.031097406377729 + RzRbar3*(2.640426628291047 + RzRbar3*(0.e-16 + (-0.84013574536533319 - 0.258503306266256365*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,3)*Power(Mag30,7));
  }
  
  double D_8_neg1_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.007724263681424011 + RzRbar3*(-0.03089705472569604 + RzRbar3*(-0.23172791044272033 + RzRbar3*(0.1544852736284802 + RzRbar3*(1.351746144249202 + RzRbar3*(0.e-15 + RzRbar3*(-3.244190746198085 + RzRbar3*(-0.926911641770881 + RzRbar3*(3.823510522304885 + RzRbar3*(1.699338009913282 + RzRbar3*(-2.209139412887267 + RzRbar3*(-1.2049851343021457 + (0.50207713929256072 + 0.308970547256960441*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,4)*Power(Mag30,6));
  }
  
  double D_8_0_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-0.06554255074569461 + Power(RzRbar3,2)*(0.6554255074569461 + Power(RzRbar3,2)*(-2.2939892760993114 + Power(RzRbar3,2)*(3.9325530447416766 + Power(RzRbar3,2)*(-3.6048402910132036 + Power(RzRbar3,2)*(1.70410631938805987 - 0.327712753728473052*Power(RzRbar3,2))))))))/(Power(Mag12,5)*Power(Mag30,5));
  }
  
  double D_8_1_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.007724263681424011 + RzRbar3*(-0.03089705472569604 + RzRbar3*(0.23172791044272033 + RzRbar3*(0.1544852736284802 + RzRbar3*(-1.351746144249202 + RzRbar3*(0.e-15 + RzRbar3*(3.244190746198085 + RzRbar3*(-0.926911641770881 + RzRbar3*(-3.823510522304885 + RzRbar3*(1.699338009913282 + RzRbar3*(2.209139412887267 + RzRbar3*(-1.2049851343021457 + (-0.50207713929256072 + 0.308970547256960441*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,6)*Power(Mag30,4));
  }
  
  double D_8_2_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.009232260938080584 + RzRbar3*(0.036929043752322338 + RzRbar3*(0.16618069688545052 + RzRbar3*(-0.5908647000371574 + RzRbar3*(-0.32312913283282 + RzRbar3*(2.326529756396307 + RzRbar3*(-0.775509918798769 + RzRbar3*(-3.545188200222944 + RzRbar3*(2.741981498609934 + RzRbar3*(2.031097406377729 + RzRbar3*(-2.640426628291047 + RzRbar3*(0.e-16 + (0.84013574536533319 - 0.258503306266256365*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,7)*Power(Mag30,3));
  }
  
  double D_8_3_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0034092382919357767 + RzRbar3*(0.068184765838715533 + RzRbar3*(-0.11591410192581641 + RzRbar3*(-0.4500194545355225 + RzRbar3*(1.312556742395274 + RzRbar3*(0.e-15 + RzRbar3*(-3.150136181748658 + RzRbar3*(2.700116727213135 + RzRbar3*(1.912582681775971 + RzRbar3*(-3.750162121129354 + RzRbar3*(0.975042151493632 + RzRbar3*(1.2409627382646227 + (-0.93072205369846703 + 0.190917344348403493*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,8)*Power(Mag30,2));
  }
  
  double D_8_4_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0052815692511679531 + RzRbar3*(0.03168941550700772 + RzRbar3*(-0.2640784625583977 + RzRbar3*(0.3873150784189832 + RzRbar3*(0.677801387233221 + RzRbar3*(-2.440084994039594 + RzRbar3*(1.62672332935973 + RzRbar3*(2.323890470513899 + RzRbar3*(-4.357294632213561 + RzRbar3*(1.742917852885425 + RzRbar3*(1.510528805834035 + RzRbar3*(-1.9224912074251349 + (0.80103800309380622 - 0.123236615860585572*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,9)*Mag30);
  }
  
  double D_8_5_neg5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.010986328125 + RzRbar3*(-0.0380859375 + RzRbar3*(-0.09521484375 + RzRbar3*(0.6982421875 + RzRbar3*(-1.221923828125 + RzRbar3*(0.e-15 + RzRbar3*(2.9326171875 + RzRbar3*(-4.189453125 + RzRbar3*(1.571044921875 + RzRbar3*(2.0947265625 + RzRbar3*(-3.14208984375 + RzRbar3*(1.8662109375 + (-0.555419921875 + 0.068359375*RzRbar3)*RzRbar3))))))))))))/Power(Mag12,10);
  }
  
  double D_8_6_neg5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.011075484592005621*Mag30 + RzRbar3*(-0.08227502839775604*Mag30 + RzRbar3*(0.2056875709943901*Mag30 + RzRbar3*(0.e-16*Mag30 + RzRbar3*(-1.131281640469146*Mag30 + RzRbar3*(2.715075937125949*Mag30 + RzRbar3*(-2.715075937125949*Mag30 + RzRbar3*(0.e-15*Mag30 + RzRbar3*(3.393844921407437*Mag30 + RzRbar3*(-4.5251265618765821*Mag30 + RzRbar3*(3.1675885933136075*Mag30 + RzRbar3*(-1.31640045436409661*Mag30 + RzRbar3*(0.30853135649158514*Mag30 - 0.03164424169144463*Mag30*RzRbar3)))))))))))))/Power(Mag12,11);
  }
  
  double D_8_7_neg5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.007221777078979023*Power(Mag30,2) + RzRbar3*(-0.07510648162138184*Power(Mag30,2) + RzRbar3*(0.3379791672962183*Power(Mag30,2) + RzRbar3*(-0.8261712978352003*Power(Mag30,2) + RzRbar3*(1.0327141222940004*Power(Mag30,2) + RzRbar3*(0.e-15*Power(Mag30,2) + RzRbar3*(-2.478513893505601*Power(Mag30,2) + RzRbar3*(4.957027787011202*Power(Mag30,2) + RzRbar3*(-5.5766562603876019*Power(Mag30,2) + RzRbar3*(4.1308564891760014*Power(Mag30,2) + RzRbar3*(-2.0654282445880007*Power(Mag30,2) + RzRbar3*(0.6759583345924366*Power(Mag30,2) + RzRbar3*(-0.131436342837418228*Power(Mag30,2) + 0.0115548433263664376*Power(Mag30,2)*RzRbar3)))))))))))))/Power(Mag12,12);
  }
  
  double D_8_8_neg5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0028887108315916094*Power(Mag30,3) + RzRbar3*(-0.037553240810690922*Power(Mag30,3) + RzRbar3*(0.22531944486414553*Power(Mag30,3) + RzRbar3*(-0.82617129783520029*Power(Mag30,3) + RzRbar3*(2.0654282445880007*Power(Mag30,3) + RzRbar3*(-3.7177708402584013*Power(Mag30,3) + RzRbar3*(4.9570277870112017*Power(Mag30,3) + RzRbar3*(-4.9570277870112017*Power(Mag30,3) + RzRbar3*(3.7177708402584013*Power(Mag30,3) + RzRbar3*(-2.0654282445880007*Power(Mag30,3) + RzRbar3*(0.82617129783520029*Power(Mag30,3) + RzRbar3*(-0.225319444864145533*Power(Mag30,3) + RzRbar3*(0.0375532408106909221*Power(Mag30,3) - 0.0028887108315916094*Power(Mag30,3)*RzRbar3)))))))))))))/Power(Mag12,13);
  }
  
  double D_8_neg8_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.010415395023291768*Power(Mag12,4) + RzRbar3*(0.12498474027950122*Power(Mag12,4) + RzRbar3*(0.68741607153725672*Power(Mag12,4) + RzRbar3*(2.2913869051241891*Power(Mag12,4) + RzRbar3*(5.1556205365294254*Power(Mag12,4) + RzRbar3*(8.2489928584470806*Power(Mag12,4) + RzRbar3*(9.623825001521594*Power(Mag12,4) + RzRbar3*(8.2489928584470806*Power(Mag12,4) + RzRbar3*(5.1556205365294254*Power(Mag12,4) + RzRbar3*(2.29138690512418906*Power(Mag12,4) + RzRbar3*(0.68741607153725672*Power(Mag12,4) + RzRbar3*(0.124984740279501221*Power(Mag12,4) + 0.0104153950232917684*Power(Mag12,4)*RzRbar3))))))))))))/Power(Mag30,12);
  }
  
  double D_8_neg7_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.020830790046583537*Power(Mag12,3) + RzRbar3*(0.18747711041925183*Power(Mag12,3) + RzRbar3*(0.6874160715372567*Power(Mag12,3) + RzRbar3*(1.1456934525620945*Power(Mag12,3) + RzRbar3*(0.e-15*Power(Mag12,3) + RzRbar3*(-4.12449642922354*Power(Mag12,3) + RzRbar3*(-9.623825001521594*Power(Mag12,3) + RzRbar3*(-12.373489287670621*Power(Mag12,3) + RzRbar3*(-10.3112410730588507*Power(Mag12,3) + RzRbar3*(-5.7284672628104726*Power(Mag12,3) + RzRbar3*(-2.06224821461177015*Power(Mag12,3) + RzRbar3*(-0.43744659097825427*Power(Mag12,3) - 0.0416615800931670737*Power(Mag12,3)*RzRbar3))))))))))))/Power(Mag30,11);
  }
  
  double D_8_neg6_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.022818987198335786*Power(Mag12,2) + RzRbar3*(0.11409493599167893*Power(Mag12,2) + RzRbar3*(0.e-16*Power(Mag12,2) + RzRbar3*(-1.2550442959084682*Power(Mag12,2) + RzRbar3*(-3.765132887725405*Power(Mag12,2) + RzRbar3*(-4.518159465270486*Power(Mag12,2) + RzRbar3*(0.e-15*Power(Mag12,2) + RzRbar3*(7.530265775450809*Power(Mag12,2) + RzRbar3*(11.295398663176214*Power(Mag12,2) + RzRbar3*(8.7853100713592777*Power(Mag12,2) + RzRbar3*(4.0161417469070984*Power(Mag12,2) + RzRbar3*(1.02685442392511039*Power(Mag12,2) + 0.114094935991678932*Power(Mag12,2)*RzRbar3))))))))))))/Power(Mag30,10);
  }
  
  double D_8_neg5_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.010563138502335906*Mag12 + RzRbar3*(-0.05281569251167953*Mag12 + RzRbar3*(-0.5809726176284748*Mag12 + RzRbar3*(-1.3556027744664413*Mag12 + RzRbar3*(0.e-15*Mag12 + RzRbar3*(4.880169988079189*Mag12 + RzRbar3*(8.133616646798648*Mag12 + RzRbar3*(3.485835705770849*Mag12 + RzRbar3*(-5.228753558656274*Mag12 + RzRbar3*(-8.714589264427123*Mag12 + RzRbar3*(-5.6935316527590534*Mag12 + RzRbar3*(-1.84854923790878357*Mag12 - 0.246473231721171143*Mag12*RzRbar3))))))))))))/Power(Mag30,9);
  }
  
  double D_8_neg4_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0087890625 + RzRbar3*(-0.146484375 + RzRbar3*(-0.322265625 + RzRbar3*(0.751953125 + RzRbar3*(3.3837890625 + RzRbar3*(2.70703125 + RzRbar3*(-4.51171875 + RzRbar3*(-9.66796875 + RzRbar3*(-4.3505859375 + RzRbar3*(4.189453125 + RzRbar3*(5.865234375 + (2.666015625 + 0.4443359375*RzRbar3)*RzRbar3)))))))))))/Power(Mag30,8);
  }
  
  double D_8_neg3_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.018911051495153403 + RzRbar3*(-0.06429757508352157 + RzRbar3*(0.37443881960403737 + RzRbar3*(1.456150965126812 + RzRbar3*(0.e-15 + RzRbar3*(-5.242143474456523 + RzRbar3*(-5.242143474456523 + RzRbar3*(4.243639955512424 + RzRbar3*(9.360970490100934 + RzRbar3*(2.704280363806937 + RzRbar3*(-3.7859925093297112 + (-3.0976302349061274 - 0.68836227442358386*RzRbar3)*RzRbar3)))))))))))/(Mag12*Power(Mag30,7));
  }
  
  double D_8_neg2_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.010242273907911636 + RzRbar3*(0.09218046517120473 + RzRbar3*(0.4916291475797585 + RzRbar3*(-0.3584795867769073 + RzRbar3*(-3.226316280992165 + RzRbar3*(-1.290526512396866 + RzRbar3*(6.88280806611662 + RzRbar3*(6.083910701299512 + RzRbar3*(-5.06992558441626 + RzRbar3*(-7.32322584415682 + RzRbar3*(0.e-15 + (2.7961407768598767 + 0.93204692561995889*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,2)*Power(Mag30,6));
  }
  
  double D_8_neg1_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0085693011595626192 + RzRbar3*(0.12853951739343929 + RzRbar3*(-0.1285395173934393 + RzRbar3*(-1.4996277029234584 + RzRbar3*(0.e-15 + RzRbar3*(5.39865973052445 + RzRbar3*(1.79955324350815 + RzRbar3*(-8.483608147966993 + RzRbar3*(-4.241804073983497 + RzRbar3*(6.127050329087273 + RzRbar3*(3.676230197452364 + (-1.6710137261147107 - 1.1140091507431405*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,3)*Power(Mag30,5));
  }
  
  double D_8_0_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.018178232879869419 + Power(RzRbar3,2)*(-0.54534698639608257 + Power(RzRbar3,2)*(3.1811907539771483 + Power(RzRbar3,2)*(-7.6348578095451559 + Power(RzRbar3,2)*(8.9982252755353623 + Power(RzRbar3,2)*(-5.1989746036426538 + 1.18158513719151222*Power(RzRbar3,2)))))))/(Power(Mag12,4)*Power(Mag30,4));
  }
  
  double D_8_1_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0085693011595626192 + RzRbar3*(-0.12853951739343929 + RzRbar3*(-0.1285395173934393 + RzRbar3*(1.4996277029234584 + RzRbar3*(0.e-15 + RzRbar3*(-5.39865973052445 + RzRbar3*(1.79955324350815 + RzRbar3*(8.483608147966993 + RzRbar3*(-4.241804073983497 + RzRbar3*(-6.127050329087273 + RzRbar3*(3.676230197452364 + (1.6710137261147107 - 1.1140091507431405*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,5)*Power(Mag30,3));
  }
  
  double D_8_2_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.010242273907911636 + RzRbar3*(-0.09218046517120473 + RzRbar3*(0.4916291475797585 + RzRbar3*(0.3584795867769073 + RzRbar3*(-3.226316280992165 + RzRbar3*(1.290526512396866 + RzRbar3*(6.88280806611662 + RzRbar3*(-6.083910701299512 + RzRbar3*(-5.06992558441626 + RzRbar3*(7.32322584415682 + RzRbar3*(0.e-15 + (-2.7961407768598767 + 0.93204692561995889*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,6)*Power(Mag30,2));
  }
  
  double D_8_3_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.018911051495153403 + RzRbar3*(0.06429757508352157 + RzRbar3*(0.37443881960403737 + RzRbar3*(-1.456150965126812 + RzRbar3*(0.e-15 + RzRbar3*(5.242143474456523 + RzRbar3*(-5.242143474456523 + RzRbar3*(-4.243639955512424 + RzRbar3*(9.360970490100934 + RzRbar3*(-2.704280363806937 + RzRbar3*(-3.7859925093297112 + (3.0976302349061274 - 0.68836227442358386*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,7)*Mag30);
  }
  
  double D_8_4_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0087890625 + RzRbar3*(0.146484375 + RzRbar3*(-0.322265625 + RzRbar3*(-0.751953125 + RzRbar3*(3.3837890625 + RzRbar3*(-2.70703125 + RzRbar3*(-4.51171875 + RzRbar3*(9.66796875 + RzRbar3*(-4.3505859375 + RzRbar3*(-4.189453125 + RzRbar3*(5.865234375 + (-2.666015625 + 0.4443359375*RzRbar3)*RzRbar3)))))))))))/Power(Mag12,8);
  }
  
  double D_8_5_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.010563138502335906*Mag30 + RzRbar3*(0.05281569251167953*Mag30 + RzRbar3*(-0.5809726176284748*Mag30 + RzRbar3*(1.3556027744664413*Mag30 + RzRbar3*(0.e-15*Mag30 + RzRbar3*(-4.880169988079189*Mag30 + RzRbar3*(8.133616646798648*Mag30 + RzRbar3*(-3.485835705770849*Mag30 + RzRbar3*(-5.228753558656274*Mag30 + RzRbar3*(8.714589264427123*Mag30 + RzRbar3*(-5.6935316527590534*Mag30 + RzRbar3*(1.84854923790878357*Mag30 - 0.246473231721171143*Mag30*RzRbar3))))))))))))/Power(Mag12,9);
  }
  
  double D_8_6_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.022818987198335786*Power(Mag30,2) + RzRbar3*(-0.11409493599167893*Power(Mag30,2) + RzRbar3*(0.e-16*Power(Mag30,2) + RzRbar3*(1.2550442959084682*Power(Mag30,2) + RzRbar3*(-3.765132887725405*Power(Mag30,2) + RzRbar3*(4.518159465270486*Power(Mag30,2) + RzRbar3*(0.e-15*Power(Mag30,2) + RzRbar3*(-7.530265775450809*Power(Mag30,2) + RzRbar3*(11.295398663176214*Power(Mag30,2) + RzRbar3*(-8.7853100713592777*Power(Mag30,2) + RzRbar3*(4.0161417469070984*Power(Mag30,2) + RzRbar3*(-1.02685442392511039*Power(Mag30,2) + 0.114094935991678932*Power(Mag30,2)*RzRbar3))))))))))))/Power(Mag12,10);
  }
  
  double D_8_7_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.020830790046583537*Power(Mag30,3) + RzRbar3*(-0.18747711041925183*Power(Mag30,3) + RzRbar3*(0.6874160715372567*Power(Mag30,3) + RzRbar3*(-1.1456934525620945*Power(Mag30,3) + RzRbar3*(0.e-15*Power(Mag30,3) + RzRbar3*(4.12449642922354*Power(Mag30,3) + RzRbar3*(-9.623825001521594*Power(Mag30,3) + RzRbar3*(12.373489287670621*Power(Mag30,3) + RzRbar3*(-10.3112410730588507*Power(Mag30,3) + RzRbar3*(5.7284672628104726*Power(Mag30,3) + RzRbar3*(-2.06224821461177015*Power(Mag30,3) + RzRbar3*(0.43744659097825427*Power(Mag30,3) - 0.0416615800931670737*Power(Mag30,3)*RzRbar3))))))))))))/Power(Mag12,11);
  }
  
  double D_8_8_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.010415395023291768*Power(Mag30,4) + RzRbar3*(-0.12498474027950122*Power(Mag30,4) + RzRbar3*(0.68741607153725672*Power(Mag30,4) + RzRbar3*(-2.2913869051241891*Power(Mag30,4) + RzRbar3*(5.1556205365294254*Power(Mag30,4) + RzRbar3*(-8.2489928584470806*Power(Mag30,4) + RzRbar3*(9.623825001521594*Power(Mag30,4) + RzRbar3*(-8.2489928584470806*Power(Mag30,4) + RzRbar3*(5.1556205365294254*Power(Mag30,4) + RzRbar3*(-2.29138690512418906*Power(Mag30,4) + RzRbar3*(0.68741607153725672*Power(Mag30,4) + RzRbar3*(-0.124984740279501221*Power(Mag30,4) + 0.0104153950232917684*Power(Mag30,4)*RzRbar3))))))))))))/Power(Mag12,12);
  }
  
  double D_8_neg8_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.032270921175504504*Power(Mag12,5) + RzRbar3*(-0.35498013293054954*Power(Mag12,5) + RzRbar3*(-1.7749006646527477*Power(Mag12,5) + RzRbar3*(-5.3247019939582432*Power(Mag12,5) + RzRbar3*(-10.6494039879164863*Power(Mag12,5) + RzRbar3*(-14.909165583083081*Power(Mag12,5) + RzRbar3*(-14.9091655830830809*Power(Mag12,5) + RzRbar3*(-10.6494039879164863*Power(Mag12,5) + RzRbar3*(-5.3247019939582432*Power(Mag12,5) + RzRbar3*(-1.77490066465274772*Power(Mag12,5) + RzRbar3*(-0.354980132930549544*Power(Mag12,5) - 0.032270921175504504*Power(Mag12,5)*RzRbar3)))))))))))/Power(Mag30,11);
  }
  
  double D_8_neg7_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.048406381763256756*Power(Mag12,4) + RzRbar3*(-0.35498013293054954*Power(Mag12,4) + RzRbar3*(-0.8874503323263739*Power(Mag12,4) + RzRbar3*(0.e-15*Power(Mag12,4) + RzRbar3*(5.324701993958243*Power(Mag12,4) + RzRbar3*(14.909165583083081*Power(Mag12,4) + RzRbar3*(22.363748374624621*Power(Mag12,4) + RzRbar3*(21.298807975832973*Power(Mag12,4) + RzRbar3*(13.3117549848956079*Power(Mag12,4) + RzRbar3*(5.3247019939582432*Power(Mag12,4) + RzRbar3*(1.24243046525692341*Power(Mag12,4) + 0.129083684702018016*Power(Mag12,4)*RzRbar3)))))))))))/Power(Mag30,10);
  }
  
  double D_8_neg6_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.029459185798824914*Power(Mag12,3) + RzRbar3*(0.e-17*Power(Mag12,3) + RzRbar3*(0.9721531313612222*Power(Mag12,3) + RzRbar3*(3.888612525444889*Power(Mag12,3) + RzRbar3*(5.832918788167333*Power(Mag12,3) + RzRbar3*(0.e-15*Power(Mag12,3) + RzRbar3*(-13.61014383905711*Power(Mag12,3) + RzRbar3*(-23.331675152669332*Power(Mag12,3) + RzRbar3*(-20.415215758585666*Power(Mag12,3) + RzRbar3*(-10.3696334011863698*Power(Mag12,3) + RzRbar3*(-2.9164593940836665*Power(Mag12,3) - 0.353510229585898971*Power(Mag12,3)*RzRbar3)))))))))))/Power(Mag30,9);
  }
  
  double D_8_neg5_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.013636953167743107*Power(Mag12,2) + RzRbar3*(0.30001296969034835*Power(Mag12,2) + RzRbar3*(1.0500453939162192*Power(Mag12,2) + RzRbar3*(0.e-15*Power(Mag12,2) + RzRbar3*(-6.300272363497315*Power(Mag12,2) + RzRbar3*(-12.600544726994631*Power(Mag12,2) + RzRbar3*(-6.300272363497315*Power(Mag12,2) + RzRbar3*(10.80046690885254*Power(Mag12,2) + RzRbar3*(20.250875454098513*Power(Mag12,2) + RzRbar3*(14.700635514827069*Power(Mag12,2) + RzRbar3*(5.250226969581096*Power(Mag12,2) + 0.76366937739361397*Power(Mag12,2)*RzRbar3)))))))))))/Power(Mag30,8);
  }
  
  double D_8_neg4_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.037822102990306806*Mag12 + RzRbar3*(0.16641725315734994*Mag12 + RzRbar3*(-0.5824603860507248*Mag12 + RzRbar3*(-3.4947623163043488*Mag12 + RzRbar3*(-3.494762316304349*Mag12 + RzRbar3*(6.989524632608698*Mag12 + RzRbar3*(17.473811581521744*Mag12 + RzRbar3*(8.986531670496897*Mag12 + RzRbar3*(-9.735409309704972*Mag12 + RzRbar3*(-15.143970037318845*Mag12 + RzRbar3*(-7.5719850186594225*Mag12 - 1.37672454884716772*Mag12*RzRbar3)))))))))))/Power(Mag30,7);
  }
  
  double D_8_neg3_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0166015625 + RzRbar3*(-0.193359375 + RzRbar3*(-1.1279296875 + RzRbar3*(0.e-16 + RzRbar3*(6.767578125 + RzRbar3*(8.12109375 + RzRbar3*(-7.669921875 + RzRbar3*(-19.3359375 + RzRbar3*(-6.2841796875 + RzRbar3*(9.775390625 + RzRbar3*(8.7978515625 + 2.1328125*RzRbar3)))))))))))/Power(Mag30,6);
  }
  
  double D_8_neg2_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.023800893763581915 + RzRbar3*(-0.25387620014487376 + RzRbar3*(0.2776770939084557 + RzRbar3*(3.3321251269014681 + RzRbar3*(1.666062563450734 + RzRbar3*(-10.662800406084698 + RzRbar3*(-10.996012918774845 + RzRbar3*(10.472393255976043 + RzRbar3*(17.017639040961069 + RzRbar3*(0.e-15 + (-7.9415648857818323 - 2.88784177664793903*RzRbar3)*RzRbar3))))))))))/(Mag12*Power(Mag30,5));
  }
  
  double D_8_neg1_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.033188760679621931 + RzRbar3*(0.06637752135924386 + RzRbar3*(1.1616066237867676 + RzRbar3*(0.e-16 + RzRbar3*(-6.969639742720605 + RzRbar3*(-2.787855897088242 + RzRbar3*(15.333207433985332 + RzRbar3*(8.76183281942019 + RzRbar3*(-14.237978331557808 + RzRbar3*(-9.491985554371872 + RzRbar3*(4.7459927771859361 + 3.45163111068068078*RzRbar3)))))))))))/(Power(Mag12,2)*Power(Mag30,4));
  }
  
  double D_8_0_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(0.2816159728288574 + Power(RzRbar3,2)*(-3.2855196830033363 + Power(RzRbar3,2)*(11.8278708588120108 + Power(RzRbar3,2)*(-18.5866542067045885 + Power(RzRbar3,2)*(13.4236947048422028 - 3.66100764677514621*Power(RzRbar3,2)))))))/(Power(Mag12,3)*Power(Mag30,3));
  }
  
  double D_8_1_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.033188760679621931 + RzRbar3*(0.06637752135924386 + RzRbar3*(-1.1616066237867676 + RzRbar3*(0.e-16 + RzRbar3*(6.969639742720605 + RzRbar3*(-2.787855897088242 + RzRbar3*(-15.333207433985332 + RzRbar3*(8.76183281942019 + RzRbar3*(14.237978331557808 + RzRbar3*(-9.491985554371872 + RzRbar3*(-4.7459927771859361 + 3.45163111068068078*RzRbar3)))))))))))/(Power(Mag12,4)*Power(Mag30,2));
  }
  
  double D_8_2_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.023800893763581915 + RzRbar3*(-0.25387620014487376 + RzRbar3*(-0.2776770939084557 + RzRbar3*(3.3321251269014681 + RzRbar3*(-1.666062563450734 + RzRbar3*(-10.662800406084698 + RzRbar3*(10.996012918774845 + RzRbar3*(10.472393255976043 + RzRbar3*(-17.017639040961069 + RzRbar3*(0.e-15 + (7.9415648857818323 - 2.88784177664793903*RzRbar3)*RzRbar3))))))))))/(Power(Mag12,5)*Mag30);
  }
  
  double D_8_3_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0166015625 + RzRbar3*(-0.193359375 + RzRbar3*(1.1279296875 + RzRbar3*(0.e-16 + RzRbar3*(-6.767578125 + RzRbar3*(8.12109375 + RzRbar3*(7.669921875 + RzRbar3*(-19.3359375 + RzRbar3*(6.2841796875 + RzRbar3*(9.775390625 + RzRbar3*(-8.7978515625 + 2.1328125*RzRbar3)))))))))))/Power(Mag12,6);
  }
  
  double D_8_4_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.037822102990306806*Mag30 + RzRbar3*(0.16641725315734994*Mag30 + RzRbar3*(0.5824603860507248*Mag30 + RzRbar3*(-3.4947623163043488*Mag30 + RzRbar3*(3.494762316304349*Mag30 + RzRbar3*(6.989524632608698*Mag30 + RzRbar3*(-17.473811581521744*Mag30 + RzRbar3*(8.986531670496897*Mag30 + RzRbar3*(9.735409309704972*Mag30 + RzRbar3*(-15.143970037318845*Mag30 + RzRbar3*(7.5719850186594225*Mag30 - 1.37672454884716772*Mag30*RzRbar3)))))))))))/Power(Mag12,7);
  }
  
  double D_8_5_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.013636953167743107*Power(Mag30,2) + RzRbar3*(0.30001296969034835*Power(Mag30,2) + RzRbar3*(-1.0500453939162192*Power(Mag30,2) + RzRbar3*(0.e-15*Power(Mag30,2) + RzRbar3*(6.300272363497315*Power(Mag30,2) + RzRbar3*(-12.600544726994631*Power(Mag30,2) + RzRbar3*(6.300272363497315*Power(Mag30,2) + RzRbar3*(10.80046690885254*Power(Mag30,2) + RzRbar3*(-20.250875454098513*Power(Mag30,2) + RzRbar3*(14.700635514827069*Power(Mag30,2) + RzRbar3*(-5.250226969581096*Power(Mag30,2) + 0.76366937739361397*Power(Mag30,2)*RzRbar3)))))))))))/Power(Mag12,8);
  }
  
  double D_8_6_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.029459185798824914*Power(Mag30,3) + RzRbar3*(0.e-17*Power(Mag30,3) + RzRbar3*(-0.9721531313612222*Power(Mag30,3) + RzRbar3*(3.888612525444889*Power(Mag30,3) + RzRbar3*(-5.832918788167333*Power(Mag30,3) + RzRbar3*(0.e-15*Power(Mag30,3) + RzRbar3*(13.61014383905711*Power(Mag30,3) + RzRbar3*(-23.331675152669332*Power(Mag30,3) + RzRbar3*(20.415215758585666*Power(Mag30,3) + RzRbar3*(-10.3696334011863698*Power(Mag30,3) + RzRbar3*(2.9164593940836665*Power(Mag30,3) - 0.353510229585898971*Power(Mag30,3)*RzRbar3)))))))))))/Power(Mag12,9);
  }
  
  double D_8_7_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.048406381763256756*Power(Mag30,4) + RzRbar3*(-0.35498013293054954*Power(Mag30,4) + RzRbar3*(0.8874503323263739*Power(Mag30,4) + RzRbar3*(0.e-15*Power(Mag30,4) + RzRbar3*(-5.324701993958243*Power(Mag30,4) + RzRbar3*(14.909165583083081*Power(Mag30,4) + RzRbar3*(-22.363748374624621*Power(Mag30,4) + RzRbar3*(21.298807975832973*Power(Mag30,4) + RzRbar3*(-13.3117549848956079*Power(Mag30,4) + RzRbar3*(5.3247019939582432*Power(Mag30,4) + RzRbar3*(-1.24243046525692341*Power(Mag30,4) + 0.129083684702018016*Power(Mag30,4)*RzRbar3)))))))))))/Power(Mag12,10);
  }
  
  double D_8_8_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.032270921175504504*Power(Mag30,5) + RzRbar3*(-0.35498013293054954*Power(Mag30,5) + RzRbar3*(1.7749006646527477*Power(Mag30,5) + RzRbar3*(-5.3247019939582432*Power(Mag30,5) + RzRbar3*(10.6494039879164863*Power(Mag30,5) + RzRbar3*(-14.909165583083081*Power(Mag30,5) + RzRbar3*(14.9091655830830809*Power(Mag30,5) + RzRbar3*(-10.6494039879164863*Power(Mag30,5) + RzRbar3*(5.3247019939582432*Power(Mag30,5) + RzRbar3*(-1.77490066465274772*Power(Mag30,5) + RzRbar3*(0.354980132930549544*Power(Mag30,5) - 0.032270921175504504*Power(Mag30,5)*RzRbar3)))))))))))/Power(Mag12,11);
  }
  
  double D_8_neg8_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.087390067660926147*Power(Mag12,6) + RzRbar3*(0.87390067660926147*Power(Mag12,6) + RzRbar3*(3.9325530447416766*Power(Mag12,6) + RzRbar3*(10.4868081193111377*Power(Mag12,6) + RzRbar3*(18.351914208794491*Power(Mag12,6) + RzRbar3*(22.022297050553389*Power(Mag12,6) + RzRbar3*(18.3519142087944909*Power(Mag12,6) + RzRbar3*(10.4868081193111377*Power(Mag12,6) + RzRbar3*(3.9325530447416766*Power(Mag12,6) + RzRbar3*(0.87390067660926147*Power(Mag12,6) + 0.0873900676609261472*Power(Mag12,6)*RzRbar3))))))))))/Power(Mag30,10);
  }
  
  double D_8_neg7_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.087390067660926147*Power(Mag12,5) + RzRbar3*(0.4369503383046307*Power(Mag12,5) + RzRbar3*(0.e-16*Power(Mag12,5) + RzRbar3*(-5.243404059655569*Power(Mag12,5) + RzRbar3*(-18.351914208794491*Power(Mag12,5) + RzRbar3*(-33.033445575830084*Power(Mag12,5) + RzRbar3*(-36.703828417588982*Power(Mag12,5) + RzRbar3*(-26.217020298277844*Power(Mag12,5) + RzRbar3*(-11.7976591342250299*Power(Mag12,5) + RzRbar3*(-3.05865236813241515*Power(Mag12,5) - 0.349560270643704589*Power(Mag12,5)*RzRbar3))))))))))/Power(Mag30,9);
  }
  
  double D_8_neg6_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-0.47865511359791979*Power(Mag12,4) + RzRbar3*(-2.8719306815875187*Power(Mag12,4) + RzRbar3*(-5.743861363175037*Power(Mag12,4) + RzRbar3*(0.e-15*Power(Mag12,4) + RzRbar3*(20.103514771112631*Power(Mag12,4) + RzRbar3*(40.207029542225262*Power(Mag12,4) + RzRbar3*(40.207029542225262*Power(Mag12,4) + RzRbar3*(22.97544545270015*Power(Mag12,4) + RzRbar3*(7.1798267039687969*Power(Mag12,4) + 0.95731022719583958*Power(Mag12,4)*RzRbar3))))))))))/Power(Mag30,8);
  }
  
  double D_8_neg5_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.073858087504644676*Power(Mag12,3) + RzRbar3*(-0.51700661253251273*Power(Mag12,3) + RzRbar3*(0.e-16*Power(Mag12,3) + RzRbar3*(6.204079350390153*Power(Mag12,3) + RzRbar3*(15.510198375975382*Power(Mag12,3) + RzRbar3*(9.306119025585229*Power(Mag12,3) + RzRbar3*(-18.612238051170458*Power(Mag12,3) + RzRbar3*(-39.883367252508125*Power(Mag12,3) + RzRbar3*(-32.571416589548302*Power(Mag12,3) + RzRbar3*(-12.9251653133128183*Power(Mag12,3) - 2.06802645013005092*Power(Mag12,3)*RzRbar3))))))))))/Power(Mag30,7);
  }
  
  double D_8_neg4_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.040969095631646545*Power(Mag12,2) + RzRbar3*(0.28678366942152581*Power(Mag12,2) + RzRbar3*(2.5810530247937323*Power(Mag12,2) + RzRbar3*(3.4414040330583098*Power(Mag12,2) + RzRbar3*(-8.603510082645774*Power(Mag12,2) + RzRbar3*(-25.810530247937323*Power(Mag12,2) + RzRbar3*(-15.486318148762394*Power(Mag12,2) + RzRbar3*(19.173536755610583*Power(Mag12,2) + RzRbar3*(33.55368932231852*Power(Mag12,2) + RzRbar3*(18.6409385123991779*Power(Mag12,2) + 3.72818770247983558*Power(Mag12,2)*RzRbar3))))))))))/Power(Mag30,6);
  }
  
  double D_8_neg3_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.04760178752716383*Mag12 + RzRbar3*(0.55535418781691135*Mag12 + RzRbar3*(0.e-16*Mag12 + RzRbar3*(-6.6642502538029362*Mag12 + RzRbar3*(-9.996375380704404*Mag12 + RzRbar3*(11.329225431464992*Mag12 + RzRbar3*(33.321251269014681*Mag12 + RzRbar3*(12.376464757062596*Mag12 + RzRbar3*(-21.658813324859543*Mag12 + RzRbar3*(-21.658813324859543*Mag12 - 5.7756835532958781*Mag12*RzRbar3))))))))))/Power(Mag30,5);
  }
  
  double D_8_neg2_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0625 + RzRbar3*(-0.13671875 + RzRbar3*(-2.4609375 + RzRbar3*(-1.640625 + RzRbar3*(13.125 + RzRbar3*(16.2421875 + RzRbar3*(-18.046875 + RzRbar3*(-33.515625 + RzRbar3*(0.e-15 + RzRbar3*(19.55078125 + 7.8203125*RzRbar3))))))))))/Power(Mag30,4);
  }
  
  double D_8_neg1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.016341016143243663 + RzRbar3*(-0.57193556501352821 + RzRbar3*(0.e-16 + RzRbar3*(6.8632267801623385 + RzRbar3*(3.431613390081169 + RzRbar3*(-22.648648374535717 + RzRbar3*(-15.099098916357145 + RzRbar3*(28.041183701806126 + RzRbar3*(21.030887776354594 + (-11.683826542419219 - 9.3470612339353753*RzRbar3)*RzRbar3)))))))))/(Mag12*Power(Mag30,3));
  }
  
  double D_8_0_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.069329059958198625 + Power(RzRbar3,2)*(2.42651709853695189 + Power(RzRbar3,2)*(-14.5591025912217114 + Power(RzRbar3,2)*(32.030025700687765 + Power(RzRbar3,2)*(-29.7421667220672103 + 9.9140555740224034*Power(RzRbar3,2))))))/(Power(Mag12,2)*Power(Mag30,2));
  }
  
  double D_8_1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.016341016143243663 + RzRbar3*(0.57193556501352821 + RzRbar3*(0.e-16 + RzRbar3*(-6.8632267801623385 + RzRbar3*(3.431613390081169 + RzRbar3*(22.648648374535717 + RzRbar3*(-15.099098916357145 + RzRbar3*(-28.041183701806126 + RzRbar3*(21.030887776354594 + (11.683826542419219 - 9.3470612339353753*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,3)*Mag30);
  }
  
  double D_8_2_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0625 + RzRbar3*(0.13671875 + RzRbar3*(-2.4609375 + RzRbar3*(1.640625 + RzRbar3*(13.125 + RzRbar3*(-16.2421875 + RzRbar3*(-18.046875 + RzRbar3*(33.515625 + RzRbar3*(0.e-15 + RzRbar3*(-19.55078125 + 7.8203125*RzRbar3))))))))))/Power(Mag12,4);
  }
  
  double D_8_3_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.04760178752716383*Mag30 + RzRbar3*(-0.55535418781691135*Mag30 + RzRbar3*(0.e-16*Mag30 + RzRbar3*(6.6642502538029362*Mag30 + RzRbar3*(-9.996375380704404*Mag30 + RzRbar3*(-11.329225431464992*Mag30 + RzRbar3*(33.321251269014681*Mag30 + RzRbar3*(-12.376464757062596*Mag30 + RzRbar3*(-21.658813324859543*Mag30 + RzRbar3*(21.658813324859543*Mag30 - 5.7756835532958781*Mag30*RzRbar3))))))))))/Power(Mag12,5);
  }
  
  double D_8_4_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.040969095631646545*Power(Mag30,2) + RzRbar3*(-0.28678366942152581*Power(Mag30,2) + RzRbar3*(2.5810530247937323*Power(Mag30,2) + RzRbar3*(-3.4414040330583098*Power(Mag30,2) + RzRbar3*(-8.603510082645774*Power(Mag30,2) + RzRbar3*(25.810530247937323*Power(Mag30,2) + RzRbar3*(-15.486318148762394*Power(Mag30,2) + RzRbar3*(-19.173536755610583*Power(Mag30,2) + RzRbar3*(33.55368932231852*Power(Mag30,2) + RzRbar3*(-18.6409385123991779*Power(Mag30,2) + 3.72818770247983558*Power(Mag30,2)*RzRbar3))))))))))/Power(Mag12,6);
  }
  
  double D_8_5_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.073858087504644676*Power(Mag30,3) + RzRbar3*(0.51700661253251273*Power(Mag30,3) + RzRbar3*(0.e-16*Power(Mag30,3) + RzRbar3*(-6.204079350390153*Power(Mag30,3) + RzRbar3*(15.510198375975382*Power(Mag30,3) + RzRbar3*(-9.306119025585229*Power(Mag30,3) + RzRbar3*(-18.612238051170458*Power(Mag30,3) + RzRbar3*(39.883367252508125*Power(Mag30,3) + RzRbar3*(-32.571416589548302*Power(Mag30,3) + RzRbar3*(12.9251653133128183*Power(Mag30,3) - 2.06802645013005092*Power(Mag30,3)*RzRbar3))))))))))/Power(Mag12,7);
  }
  
  double D_8_6_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(0.47865511359791979*Power(Mag30,4) + RzRbar3*(-2.8719306815875187*Power(Mag30,4) + RzRbar3*(5.743861363175037*Power(Mag30,4) + RzRbar3*(0.e-15*Power(Mag30,4) + RzRbar3*(-20.103514771112631*Power(Mag30,4) + RzRbar3*(40.207029542225262*Power(Mag30,4) + RzRbar3*(-40.207029542225262*Power(Mag30,4) + RzRbar3*(22.97544545270015*Power(Mag30,4) + RzRbar3*(-7.1798267039687969*Power(Mag30,4) + 0.95731022719583958*Power(Mag30,4)*RzRbar3))))))))))/Power(Mag12,8);
  }
  
  double D_8_7_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.087390067660926147*Power(Mag30,5) + RzRbar3*(-0.4369503383046307*Power(Mag30,5) + RzRbar3*(0.e-16*Power(Mag30,5) + RzRbar3*(5.243404059655569*Power(Mag30,5) + RzRbar3*(-18.351914208794491*Power(Mag30,5) + RzRbar3*(33.033445575830084*Power(Mag30,5) + RzRbar3*(-36.703828417588982*Power(Mag30,5) + RzRbar3*(26.217020298277844*Power(Mag30,5) + RzRbar3*(-11.7976591342250299*Power(Mag30,5) + RzRbar3*(3.05865236813241515*Power(Mag30,5) - 0.349560270643704589*Power(Mag30,5)*RzRbar3))))))))))/Power(Mag12,9);
  }
  
  double D_8_8_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.087390067660926147*Power(Mag30,6) + RzRbar3*(-0.87390067660926147*Power(Mag30,6) + RzRbar3*(3.9325530447416766*Power(Mag30,6) + RzRbar3*(-10.4868081193111377*Power(Mag30,6) + RzRbar3*(18.351914208794491*Power(Mag30,6) + RzRbar3*(-22.022297050553389*Power(Mag30,6) + RzRbar3*(18.3519142087944909*Power(Mag30,6) + RzRbar3*(-10.4868081193111377*Power(Mag30,6) + RzRbar3*(3.9325530447416766*Power(Mag30,6) + RzRbar3*(-0.87390067660926147*Power(Mag30,6) + 0.0873900676609261472*Power(Mag30,6)*RzRbar3))))))))))/Power(Mag12,10);
  }
  
  double D_8_neg8_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.20890221808001465*Power(Mag12,7) + RzRbar3*(-1.8801199627201319*Power(Mag12,7) + RzRbar3*(-7.5204798508805274*Power(Mag12,7) + RzRbar3*(-17.547786318721231*Power(Mag12,7) + RzRbar3*(-26.321679478081846*Power(Mag12,7) + RzRbar3*(-26.321679478081846*Power(Mag12,7) + RzRbar3*(-17.5477863187212307*Power(Mag12,7) + RzRbar3*(-7.5204798508805274*Power(Mag12,7) + RzRbar3*(-1.88011996272013186*Power(Mag12,7) - 0.208902218080014651*Power(Mag12,7)*RzRbar3)))))))))/Power(Mag30,9);
  }
  
  double D_8_neg7_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.10445110904000733*Power(Mag12,6) + RzRbar3*(0.e-16*Power(Mag12,6) + RzRbar3*(3.7602399254402637*Power(Mag12,6) + RzRbar3*(17.547786318721231*Power(Mag12,6) + RzRbar3*(39.482519217122769*Power(Mag12,6) + RzRbar3*(52.643358956163692*Power(Mag12,6) + RzRbar3*(43.869465796803077*Power(Mag12,6) + RzRbar3*(22.5614395526415823*Power(Mag12,6) + RzRbar3*(6.5804198695204615*Power(Mag12,6) + 0.8356088723200586*Power(Mag12,6)*RzRbar3)))))))))/Power(Mag30,8);
  }
  
  double D_8_neg6_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.11442045715528758*Power(Mag12,5) + RzRbar3*(1.3730454858634509*Power(Mag12,5) + RzRbar3*(4.1191364575903528*Power(Mag12,5) + RzRbar3*(0.e-15*Power(Mag12,5) + RzRbar3*(-24.028296002610391*Power(Mag12,5) + RzRbar3*(-57.667910406264939*Power(Mag12,5) + RzRbar3*(-67.279228807309095*Power(Mag12,5) + RzRbar3*(-43.937455547630429*Power(Mag12,5) + RzRbar3*(-15.4467617159638228*Power(Mag12,5) - 2.28840914310575153*Power(Mag12,5)*RzRbar3)))))))))/Power(Mag30,7);
  }
  
  double D_8_neg5_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.123588218902784176*Power(Mag12,4) + RzRbar3*(0.e-16*Power(Mag12,4) + RzRbar3*(-4.4491758805002303*Power(Mag12,4) + RzRbar3*(-14.830586268334101*Power(Mag12,4) + RzRbar3*(-11.122939701250576*Power(Mag12,4) + RzRbar3*(26.695055283001382*Power(Mag12,4) + RzRbar3*(66.737638207503455*Power(Mag12,4) + RzRbar3*(62.288462327003225*Power(Mag12,4) + RzRbar3*(27.8073492531264397*Power(Mag12,4) + 4.94352875611136705*Power(Mag12,4)*RzRbar3)))))))))/Power(Mag30,6);
  }
  
  double D_8_neg4_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.068554409276500954*Power(Mag12,3) + RzRbar3*(-1.23397936697701716*Power(Mag12,3) + RzRbar3*(-2.4679587339540343*Power(Mag12,3) + RzRbar3*(8.226529113180114*Power(Mag12,3) + RzRbar3*(30.849484174425429*Power(Mag12,3) + RzRbar3*(22.211628605586309*Power(Mag12,3) + RzRbar3*(-32.083463541402446*Power(Mag12,3) + RzRbar3*(-64.166927082804893*Power(Mag12,3) + RzRbar3*(-40.104329426753058*Power(Mag12,3) - 8.912073205945124*Power(Mag12,3)*RzRbar3)))))))))/Power(Mag30,5);
  }
  
  double D_8_neg3_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.132755042718487722*Power(Mag12,2) + RzRbar3*(0.e-17*Power(Mag12,2) + RzRbar3*(4.779181537865558*Power(Mag12,2) + RzRbar3*(9.558363075731116*Power(Mag12,2) + RzRbar3*(-13.541014357285748*Power(Mag12,2) + RzRbar3*(-47.79181537865558*Power(Mag12,2) + RzRbar3*(-20.709786664084085*Power(Mag12,2) + RzRbar3*(41.419573328168169*Power(Mag12,2) + RzRbar3*(46.597019994189191*Power(Mag12,2) + 13.8065244427227231*Power(Mag12,2)*RzRbar3)))))))))/Power(Mag30,4);
  }
  
  double D_8_neg2_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.032682032286487326*Mag12 + RzRbar3*(1.17655316231354374*Mag12 + RzRbar3*(1.1765531623135437*Mag12 + RzRbar3*(-12.5499003980111332*Mag12 + RzRbar3*(-19.413127178173472*Mag12 + RzRbar3*(25.884169570897962*Mag12 + RzRbar3*(56.082367403612252*Mag12 + RzRbar3*(0.e-15*Mag12 + RzRbar3*(-42.061775552709189*Mag12 - 18.6941224678707505*Mag12*RzRbar3)))))))))/Power(Mag30,3);
  }
  
  double D_8_neg1_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.13671875 + RzRbar3*(0.e-17 + RzRbar3*(-4.921875 + RzRbar3*(-3.28125 + RzRbar3*(27.0703125 + RzRbar3*(21.65625 + RzRbar3*(-46.921875 + RzRbar3*(-40.21875 + RzRbar3*(25.13671875 + 22.34375*RzRbar3)))))))))/Power(Mag30,2);
  }
  
  double D_8_0_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-1.16009706288417953 + Power(RzRbar3,2)*(13.9211647546101544 + Power(RzRbar3,2)*(-45.9398436902135095 + Power(RzRbar3,2)*(56.877901711692916 - 23.6991257132053819*Power(RzRbar3,2))))))/(Mag12*Mag30);
  }
  
  double D_8_1_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.13671875 + RzRbar3*(0.e-17 + RzRbar3*(4.921875 + RzRbar3*(-3.28125 + RzRbar3*(-27.0703125 + RzRbar3*(21.65625 + RzRbar3*(46.921875 + RzRbar3*(-40.21875 + RzRbar3*(-25.13671875 + 22.34375*RzRbar3)))))))))/Power(Mag12,2);
  }
  
  double D_8_2_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.032682032286487326*Mag30 + RzRbar3*(1.17655316231354374*Mag30 + RzRbar3*(-1.1765531623135437*Mag30 + RzRbar3*(-12.5499003980111332*Mag30 + RzRbar3*(19.413127178173472*Mag30 + RzRbar3*(25.884169570897962*Mag30 + RzRbar3*(-56.082367403612252*Mag30 + RzRbar3*(0.e-15*Mag30 + RzRbar3*(42.061775552709189*Mag30 - 18.6941224678707505*Mag30*RzRbar3)))))))))/Power(Mag12,3);
  }
  
  double D_8_3_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.132755042718487722*Power(Mag30,2) + RzRbar3*(0.e-17*Power(Mag30,2) + RzRbar3*(-4.779181537865558*Power(Mag30,2) + RzRbar3*(9.558363075731116*Power(Mag30,2) + RzRbar3*(13.541014357285748*Power(Mag30,2) + RzRbar3*(-47.79181537865558*Power(Mag30,2) + RzRbar3*(20.709786664084085*Power(Mag30,2) + RzRbar3*(41.419573328168169*Power(Mag30,2) + RzRbar3*(-46.597019994189191*Power(Mag30,2) + 13.8065244427227231*Power(Mag30,2)*RzRbar3)))))))))/Power(Mag12,4);
  }
  
  double D_8_4_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.068554409276500954*Power(Mag30,3) + RzRbar3*(-1.23397936697701716*Power(Mag30,3) + RzRbar3*(2.4679587339540343*Power(Mag30,3) + RzRbar3*(8.226529113180114*Power(Mag30,3) + RzRbar3*(-30.849484174425429*Power(Mag30,3) + RzRbar3*(22.211628605586309*Power(Mag30,3) + RzRbar3*(32.083463541402446*Power(Mag30,3) + RzRbar3*(-64.166927082804893*Power(Mag30,3) + RzRbar3*(40.104329426753058*Power(Mag30,3) - 8.912073205945124*Power(Mag30,3)*RzRbar3)))))))))/Power(Mag12,5);
  }
  
  double D_8_5_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.123588218902784176*Power(Mag30,4) + RzRbar3*(0.e-16*Power(Mag30,4) + RzRbar3*(4.4491758805002303*Power(Mag30,4) + RzRbar3*(-14.830586268334101*Power(Mag30,4) + RzRbar3*(11.122939701250576*Power(Mag30,4) + RzRbar3*(26.695055283001382*Power(Mag30,4) + RzRbar3*(-66.737638207503455*Power(Mag30,4) + RzRbar3*(62.288462327003225*Power(Mag30,4) + RzRbar3*(-27.8073492531264397*Power(Mag30,4) + 4.94352875611136705*Power(Mag30,4)*RzRbar3)))))))))/Power(Mag12,6);
  }
  
  double D_8_6_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.11442045715528758*Power(Mag30,5) + RzRbar3*(1.3730454858634509*Power(Mag30,5) + RzRbar3*(-4.1191364575903528*Power(Mag30,5) + RzRbar3*(0.e-15*Power(Mag30,5) + RzRbar3*(24.028296002610391*Power(Mag30,5) + RzRbar3*(-57.667910406264939*Power(Mag30,5) + RzRbar3*(67.279228807309095*Power(Mag30,5) + RzRbar3*(-43.937455547630429*Power(Mag30,5) + RzRbar3*(15.4467617159638228*Power(Mag30,5) - 2.28840914310575153*Power(Mag30,5)*RzRbar3)))))))))/Power(Mag12,7);
  }
  
  double D_8_7_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.10445110904000733*Power(Mag30,6) + RzRbar3*(0.e-16*Power(Mag30,6) + RzRbar3*(-3.7602399254402637*Power(Mag30,6) + RzRbar3*(17.547786318721231*Power(Mag30,6) + RzRbar3*(-39.482519217122769*Power(Mag30,6) + RzRbar3*(52.643358956163692*Power(Mag30,6) + RzRbar3*(-43.869465796803077*Power(Mag30,6) + RzRbar3*(22.5614395526415823*Power(Mag30,6) + RzRbar3*(-6.5804198695204615*Power(Mag30,6) + 0.8356088723200586*Power(Mag30,6)*RzRbar3)))))))))/Power(Mag12,8);
  }
  
  double D_8_8_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.20890221808001465*Power(Mag30,7) + RzRbar3*(-1.8801199627201319*Power(Mag30,7) + RzRbar3*(7.5204798508805274*Power(Mag30,7) + RzRbar3*(-17.547786318721231*Power(Mag30,7) + RzRbar3*(26.321679478081846*Power(Mag30,7) + RzRbar3*(-26.321679478081846*Power(Mag30,7) + RzRbar3*(17.5477863187212307*Power(Mag30,7) + RzRbar3*(-7.5204798508805274*Power(Mag30,7) + RzRbar3*(1.88011996272013186*Power(Mag30,7) - 0.208902218080014651*Power(Mag30,7)*RzRbar3)))))))))/Power(Mag12,9);
  }
  
  double D_8_neg8_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.44314852502786806*Power(Mag12,8) + RzRbar3*(3.5451882002229444*Power(Mag12,8) + RzRbar3*(12.4081587007803055*Power(Mag12,8) + RzRbar3*(24.816317401560611*Power(Mag12,8) + RzRbar3*(31.020396751950764*Power(Mag12,8) + RzRbar3*(24.8163174015606111*Power(Mag12,8) + RzRbar3*(12.4081587007803055*Power(Mag12,8) + RzRbar3*(3.54518820022294444*Power(Mag12,8) + 0.443148525027868055*Power(Mag12,8)*RzRbar3))))))))/Power(Mag30,8);
  }
  
  double D_8_neg7_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-1.7725941001114722*Power(Mag12,7) + RzRbar3*(-12.4081587007803055*Power(Mag12,7) + RzRbar3*(-37.224476102340917*Power(Mag12,7) + RzRbar3*(-62.040793503901528*Power(Mag12,7) + RzRbar3*(-62.040793503901528*Power(Mag12,7) + RzRbar3*(-37.224476102340917*Power(Mag12,7) + RzRbar3*(-12.4081587007803055*Power(Mag12,7) - 1.77259410011147222*Power(Mag12,7)*RzRbar3))))))))/Power(Mag30,7);
  }
  
  double D_8_neg6_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.32362992464387467*Power(Mag12,6) + RzRbar3*(-1.941779547863248*Power(Mag12,6) + RzRbar3*(0.e-16*Power(Mag12,6) + RzRbar3*(22.654094725071227*Power(Mag12,6) + RzRbar3*(67.962284175213682*Power(Mag12,6) + RzRbar3*(95.147197845299154*Power(Mag12,6) + RzRbar3*(72.493103120227927*Power(Mag12,6) + RzRbar3*(29.1266932179487207*Power(Mag12,6) + 4.85444886965812011*Power(Mag12,6)*RzRbar3))))))))/Power(Mag30,6);
  }
  
  double D_8_neg5_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(2.0973616238622275*Power(Mag12,5) + RzRbar3*(10.4868081193111377*Power(Mag12,5) + RzRbar3*(10.486808119311138*Power(Mag12,5) + RzRbar3*(-31.460424357933413*Power(Mag12,5) + RzRbar3*(-94.381273073800239*Power(Mag12,5) + RzRbar3*(-102.770719569249149*Power(Mag12,5) + RzRbar3*(-52.434040596555688*Power(Mag12,5) - 10.4868081193111377*Power(Mag12,5)*RzRbar3))))))))/Power(Mag30,5);
  }
  
  double D_8_neg4_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.2908517260779107*Power(Mag12,4) + RzRbar3*(1.16340690431164281*Power(Mag12,4) + RzRbar3*(-5.817034521558214*Power(Mag12,4) + RzRbar3*(-29.08517260779107*Power(Mag12,4) + RzRbar3*(-26.176655347011963*Power(Mag12,4) + RzRbar3*(45.372869268154069*Power(Mag12,4) + RzRbar3*(105.870028292359495*Power(Mag12,4) + RzRbar3*(75.621448780256782*Power(Mag12,4) + 18.9053621950641956*Power(Mag12,4)*RzRbar3))))))))/Power(Mag30,4);
  }
  
  double D_8_neg3_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-2.2529277826308592*Power(Mag12,3) + RzRbar3*(-6.7587833478925776*Power(Mag12,3) + RzRbar3*(12.766590768241536*Power(Mag12,3) + RzRbar3*(56.32319456577148*Power(Mag12,3) + RzRbar3*(29.28806117420117*Power(Mag12,3) + RzRbar3*(-68.338809406469396*Power(Mag12,3) + RzRbar3*(-87.864183522603509*Power(Mag12,3) - 29.2880611742011697*Power(Mag12,3)*RzRbar3))))))))/Power(Mag30,3);
  }
  
  double D_8_neg2_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.2773162398327945*Power(Mag12,2) + RzRbar3*(-0.554632479665589*Power(Mag12,2) + RzRbar3*(8.8741196746494241*Power(Mag12,2) + RzRbar3*(18.3028718289644371*Power(Mag12,2) + RzRbar3*(-30.504786381607395*Power(Mag12,2) + RzRbar3*(-79.312444592179228*Power(Mag12,2) + RzRbar3*(0.e-15*Power(Mag12,2) + RzRbar3*(79.312444592179228*Power(Mag12,2) + 39.6562222960896138*Power(Mag12,2)*RzRbar3))))))))/Power(Mag30,2);
  }
  
  double D_8_neg1_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(2.32019412576835906*Mag12 + RzRbar3*(2.32019412576835906*Mag12 + RzRbar3*(-25.5221353834519497*Mag12 + RzRbar3*(-25.5221353834519497*Mag12 + RzRbar3*(66.357551996975069*Mag12 + RzRbar3*(66.357551996975069*Mag12 + RzRbar3*(-47.3982514264107637*Mag12 - 47.3982514264107637*Mag12*RzRbar3))))))))/Mag30;
  }
  
  double D_8_0_0() {
    return 0.2734375 + Power(RzRbar3,2)*(-9.84375 + Power(RzRbar3,2)*(54.140625 + Power(RzRbar3,2)*(-93.84375 + 50.2734375*Power(RzRbar3,2))));
  }
  
  double D_8_1_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-2.32019412576835906*Mag30 + RzRbar3*(2.32019412576835906*Mag30 + RzRbar3*(25.5221353834519497*Mag30 + RzRbar3*(-25.5221353834519497*Mag30 + RzRbar3*(-66.357551996975069*Mag30 + RzRbar3*(66.357551996975069*Mag30 + RzRbar3*(47.3982514264107637*Mag30 - 47.3982514264107637*Mag30*RzRbar3))))))))/Mag12;
  }
  
  double D_8_2_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.2773162398327945*Power(Mag30,2) + RzRbar3*(0.554632479665589*Power(Mag30,2) + RzRbar3*(8.8741196746494241*Power(Mag30,2) + RzRbar3*(-18.3028718289644371*Power(Mag30,2) + RzRbar3*(-30.504786381607395*Power(Mag30,2) + RzRbar3*(79.312444592179228*Power(Mag30,2) + RzRbar3*(0.e-15*Power(Mag30,2) + RzRbar3*(-79.312444592179228*Power(Mag30,2) + 39.6562222960896138*Power(Mag30,2)*RzRbar3))))))))/Power(Mag12,2);
  }
  
  double D_8_3_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(2.2529277826308592*Power(Mag30,3) + RzRbar3*(-6.7587833478925776*Power(Mag30,3) + RzRbar3*(-12.766590768241536*Power(Mag30,3) + RzRbar3*(56.32319456577148*Power(Mag30,3) + RzRbar3*(-29.28806117420117*Power(Mag30,3) + RzRbar3*(-68.338809406469396*Power(Mag30,3) + RzRbar3*(87.864183522603509*Power(Mag30,3) - 29.2880611742011697*Power(Mag30,3)*RzRbar3))))))))/Power(Mag12,3);
  }
  
  double D_8_4_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.2908517260779107*Power(Mag30,4) + RzRbar3*(-1.16340690431164281*Power(Mag30,4) + RzRbar3*(-5.817034521558214*Power(Mag30,4) + RzRbar3*(29.08517260779107*Power(Mag30,4) + RzRbar3*(-26.176655347011963*Power(Mag30,4) + RzRbar3*(-45.372869268154069*Power(Mag30,4) + RzRbar3*(105.870028292359495*Power(Mag30,4) + RzRbar3*(-75.621448780256782*Power(Mag30,4) + 18.9053621950641956*Power(Mag30,4)*RzRbar3))))))))/Power(Mag12,4);
  }
  
  double D_8_5_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-2.0973616238622275*Power(Mag30,5) + RzRbar3*(10.4868081193111377*Power(Mag30,5) + RzRbar3*(-10.486808119311138*Power(Mag30,5) + RzRbar3*(-31.460424357933413*Power(Mag30,5) + RzRbar3*(94.381273073800239*Power(Mag30,5) + RzRbar3*(-102.770719569249149*Power(Mag30,5) + RzRbar3*(52.434040596555688*Power(Mag30,5) - 10.4868081193111377*Power(Mag30,5)*RzRbar3))))))))/Power(Mag12,5);
  }
  
  double D_8_6_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.32362992464387467*Power(Mag30,6) + RzRbar3*(1.941779547863248*Power(Mag30,6) + RzRbar3*(0.e-16*Power(Mag30,6) + RzRbar3*(-22.654094725071227*Power(Mag30,6) + RzRbar3*(67.962284175213682*Power(Mag30,6) + RzRbar3*(-95.147197845299154*Power(Mag30,6) + RzRbar3*(72.493103120227927*Power(Mag30,6) + RzRbar3*(-29.1266932179487207*Power(Mag30,6) + 4.85444886965812011*Power(Mag30,6)*RzRbar3))))))))/Power(Mag12,6);
  }
  
  double D_8_7_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(1.7725941001114722*Power(Mag30,7) + RzRbar3*(-12.4081587007803055*Power(Mag30,7) + RzRbar3*(37.224476102340917*Power(Mag30,7) + RzRbar3*(-62.040793503901528*Power(Mag30,7) + RzRbar3*(62.040793503901528*Power(Mag30,7) + RzRbar3*(-37.224476102340917*Power(Mag30,7) + RzRbar3*(12.4081587007803055*Power(Mag30,7) - 1.77259410011147222*Power(Mag30,7)*RzRbar3))))))))/Power(Mag12,7);
  }
  
  double D_8_8_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.44314852502786806*Power(Mag30,8) + RzRbar3*(-3.5451882002229444*Power(Mag30,8) + RzRbar3*(12.4081587007803055*Power(Mag30,8) + RzRbar3*(-24.816317401560611*Power(Mag30,8) + RzRbar3*(31.020396751950764*Power(Mag30,8) + RzRbar3*(-24.8163174015606111*Power(Mag30,8) + RzRbar3*(12.4081587007803055*Power(Mag30,8) + RzRbar3*(-3.54518820022294444*Power(Mag30,8) + 0.443148525027868055*Power(Mag30,8)*RzRbar3))))))))/Power(Mag12,8);
  }
  
  double D_8_neg8_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.8356088723200586*Power(Mag12,9) + RzRbar3*(-5.8492621062404102*Power(Mag12,9) + RzRbar3*(-17.547786318721231*Power(Mag12,9) + RzRbar3*(-29.246310531202051*Power(Mag12,9) + RzRbar3*(-29.246310531202051*Power(Mag12,9) + RzRbar3*(-17.5477863187212307*Power(Mag12,9) + RzRbar3*(-5.8492621062404102*Power(Mag12,9) - 0.835608872320058603*Power(Mag12,9)*RzRbar3)))))))/Power(Mag30,7);
  }
  
  double D_8_neg7_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.4178044361600293*Power(Mag12,8) + RzRbar3*(5.8492621062404102*Power(Mag12,8) + RzRbar3*(26.321679478081846*Power(Mag12,8) + RzRbar3*(58.492621062404102*Power(Mag12,8) + RzRbar3*(73.115776328005128*Power(Mag12,8) + RzRbar3*(52.643358956163692*Power(Mag12,8) + RzRbar3*(20.4724173718414358*Power(Mag12,8) + 3.34243548928023441*Power(Mag12,8)*RzRbar3)))))))/Power(Mag30,6);
  }
  
  double D_8_neg6_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.45768182862115031*Power(Mag12,7) + RzRbar3*(0.e-16*Power(Mag12,7) + RzRbar3*(-16.018864001740261*Power(Mag12,7) + RzRbar3*(-64.075456006961043*Power(Mag12,7) + RzRbar3*(-112.132048012181825*Power(Mag12,7) + RzRbar3*(-102.520729611137669*Power(Mag12,7) + RzRbar3*(-48.056592005220782*Power(Mag12,7) - 9.1536365724230061*Power(Mag12,7)*RzRbar3)))))))/Power(Mag30,5);
  }
  
  double D_8_neg5_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.49435287561113671*Power(Mag12,6) + RzRbar3*(-4.9435287561113671*Power(Mag12,6) + RzRbar3*(-7.415293134167051*Power(Mag12,6) + RzRbar3*(29.661172536668202*Power(Mag12,6) + RzRbar3*(111.229397012505759*Power(Mag12,6) + RzRbar3*(145.339745429674191*Power(Mag12,6) + RzRbar3*(86.511753231948923*Power(Mag12,6) + 19.7741150244454682*Power(Mag12,6)*RzRbar3)))))))/Power(Mag30,4);
  }
  
  double D_8_neg4_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.27421763710600381*Power(Mag12,5) + RzRbar3*(2.7421763710600381*Power(Mag12,5) + RzRbar3*(20.5663227829502861*Power(Mag12,5) + RzRbar3*(24.679587339540343*Power(Mag12,5) + RzRbar3*(-53.472439235670744*Power(Mag12,5) + RzRbar3*(-149.722829859878083*Power(Mag12,5) + RzRbar3*(-124.769024883231736*Power(Mag12,5) - 35.6482928237804959*Power(Mag12,5)*RzRbar3)))))))/Power(Mag30,3);
  }
  
  double D_8_neg3_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.53102017087395089*Power(Mag12,4) + RzRbar3*(3.1861210252437053*Power(Mag12,4) + RzRbar3*(-9.0273429048571651*Power(Mag12,4) + RzRbar3*(-53.102017087395089*Power(Mag12,4) + RzRbar3*(-34.516311106806808*Power(Mag12,4) + RzRbar3*(96.645671099059062*Power(Mag12,4) + RzRbar3*(144.968506648588593*Power(Mag12,4) + 55.226097770890892*Power(Mag12,4)*RzRbar3)))))))/Power(Mag30,2);
  }
  
  double D_8_neg2_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.130728129145949304*Power(Mag12,3) + RzRbar3*(-4.18330013267037774*Power(Mag12,3) + RzRbar3*(-12.9420847854489811*Power(Mag12,3) + RzRbar3*(28.760188412108847*Power(Mag12,3) + RzRbar3*(93.470612339353753*Power(Mag12,3) + Power(RzRbar3,2)*(-130.858857275095254*Power(Mag12,3) - 74.776489871483002*Power(Mag12,3)*RzRbar3))))))/Mag30;
  }
  
  double D_8_neg1_1() {
    return -0.546875*Power(Mag12,2) + RzRbar3*(-1.09375*Power(Mag12,2) + RzRbar3*(18.046875*Power(Mag12,2) + RzRbar3*(24.0625*Power(Mag12,2) + RzRbar3*(-78.203125*Power(Mag12,2) + RzRbar3*(-93.84375*Power(Mag12,2) + RzRbar3*(78.203125*Power(Mag12,2) + 89.375*Power(Mag12,2)*RzRbar3))))));
  }
  
  double D_8_0_1() {
    return RzRbar3*(4.64038825153671813*Mag12*Mag30 + Power(RzRbar3,2)*(-51.044270766903899*Mag12*Mag30 + Power(RzRbar3,2)*(132.715103993950138*Mag12*Mag30 - 94.796502852821527*Mag12*Mag30*Power(RzRbar3,2))));
  }
  
  double D_8_1_1() {
    return 0.546875*Power(Mag30,2) + RzRbar3*(-1.09375*Power(Mag30,2) + RzRbar3*(-18.046875*Power(Mag30,2) + RzRbar3*(24.0625*Power(Mag30,2) + RzRbar3*(78.203125*Power(Mag30,2) + RzRbar3*(-93.84375*Power(Mag30,2) + RzRbar3*(-78.203125*Power(Mag30,2) + 89.375*Power(Mag30,2)*RzRbar3))))));
  }
  
  double D_8_2_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.130728129145949304*Power(Mag30,3) + RzRbar3*(-4.18330013267037774*Power(Mag30,3) + RzRbar3*(12.9420847854489811*Power(Mag30,3) + RzRbar3*(28.760188412108847*Power(Mag30,3) + RzRbar3*(-93.470612339353753*Power(Mag30,3) + Power(RzRbar3,2)*(130.858857275095254*Power(Mag30,3) - 74.776489871483002*Power(Mag30,3)*RzRbar3))))))/Mag12;
  }
  
  double D_8_3_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.53102017087395089*Power(Mag30,4) + RzRbar3*(3.1861210252437053*Power(Mag30,4) + RzRbar3*(9.0273429048571651*Power(Mag30,4) + RzRbar3*(-53.102017087395089*Power(Mag30,4) + RzRbar3*(34.516311106806808*Power(Mag30,4) + RzRbar3*(96.645671099059062*Power(Mag30,4) + RzRbar3*(-144.968506648588593*Power(Mag30,4) + 55.226097770890892*Power(Mag30,4)*RzRbar3)))))))/Power(Mag12,2);
  }
  
  double D_8_4_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.27421763710600381*Power(Mag30,5) + RzRbar3*(2.7421763710600381*Power(Mag30,5) + RzRbar3*(-20.5663227829502861*Power(Mag30,5) + RzRbar3*(24.679587339540343*Power(Mag30,5) + RzRbar3*(53.472439235670744*Power(Mag30,5) + RzRbar3*(-149.722829859878083*Power(Mag30,5) + RzRbar3*(124.769024883231736*Power(Mag30,5) - 35.6482928237804959*Power(Mag30,5)*RzRbar3)))))))/Power(Mag12,3);
  }
  
  double D_8_5_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.49435287561113671*Power(Mag30,6) + RzRbar3*(-4.9435287561113671*Power(Mag30,6) + RzRbar3*(7.415293134167051*Power(Mag30,6) + RzRbar3*(29.661172536668202*Power(Mag30,6) + RzRbar3*(-111.229397012505759*Power(Mag30,6) + RzRbar3*(145.339745429674191*Power(Mag30,6) + RzRbar3*(-86.511753231948923*Power(Mag30,6) + 19.7741150244454682*Power(Mag30,6)*RzRbar3)))))))/Power(Mag12,4);
  }
  
  double D_8_6_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.45768182862115031*Power(Mag30,7) + RzRbar3*(0.e-16*Power(Mag30,7) + RzRbar3*(16.018864001740261*Power(Mag30,7) + RzRbar3*(-64.075456006961043*Power(Mag30,7) + RzRbar3*(112.132048012181825*Power(Mag30,7) + RzRbar3*(-102.520729611137669*Power(Mag30,7) + RzRbar3*(48.056592005220782*Power(Mag30,7) - 9.1536365724230061*Power(Mag30,7)*RzRbar3)))))))/Power(Mag12,5);
  }
  
  double D_8_7_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.4178044361600293*Power(Mag30,8) + RzRbar3*(5.8492621062404102*Power(Mag30,8) + RzRbar3*(-26.321679478081846*Power(Mag30,8) + RzRbar3*(58.492621062404102*Power(Mag30,8) + RzRbar3*(-73.115776328005128*Power(Mag30,8) + RzRbar3*(52.643358956163692*Power(Mag30,8) + RzRbar3*(-20.4724173718414358*Power(Mag30,8) + 3.34243548928023441*Power(Mag30,8)*RzRbar3)))))))/Power(Mag12,6);
  }
  
  double D_8_8_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.8356088723200586*Power(Mag30,9) + RzRbar3*(-5.8492621062404102*Power(Mag30,9) + RzRbar3*(17.547786318721231*Power(Mag30,9) + RzRbar3*(-29.246310531202051*Power(Mag30,9) + RzRbar3*(29.246310531202051*Power(Mag30,9) + RzRbar3*(-17.5477863187212307*Power(Mag30,9) + RzRbar3*(5.8492621062404102*Power(Mag30,9) - 0.835608872320058603*Power(Mag30,9)*RzRbar3)))))))/Power(Mag12,7);
  }
  
  double D_8_neg8_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.39824108257481835*Power(Mag12,10) + RzRbar3*(8.3894464954489101*Power(Mag12,10) + RzRbar3*(20.973616238622275*Power(Mag12,10) + RzRbar3*(27.964821651496367*Power(Mag12,10) + RzRbar3*(20.9736162386222753*Power(Mag12,10) + RzRbar3*(8.3894464954489101*Power(Mag12,10) + 1.39824108257481835*Power(Mag12,10)*RzRbar3))))))/Power(Mag30,6);
  }
  
  double D_8_neg7_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.39824108257481835*Power(Mag12,9) + RzRbar3*(-12.5841697431733652*Power(Mag12,9) + RzRbar3*(-41.947232477244551*Power(Mag12,9) + RzRbar3*(-69.912054128740918*Power(Mag12,9) + RzRbar3*(-62.920848715866826*Power(Mag12,9) + RzRbar3*(-29.3630627340711854*Power(Mag12,9) - 5.5929643302992734*Power(Mag12,9)*RzRbar3))))))/Power(Mag30,5);
  }
  
  double D_8_neg6_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(7.6584818175667167*Power(Mag12,8) + RzRbar3*(45.9508909054003*Power(Mag12,8) + RzRbar3*(107.218745445934033*Power(Mag12,8) + RzRbar3*(122.535709081067467*Power(Mag12,8) + RzRbar3*(68.92633635810045*Power(Mag12,8) + 15.3169636351334333*Power(Mag12,8)*RzRbar3))))))/Power(Mag30,4);
  }
  
  double D_8_neg5_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.18172940007431481*Power(Mag12,7) + RzRbar3*(3.5451882002229444*Power(Mag12,7) + RzRbar3*(-21.271129201337667*Power(Mag12,7) + RzRbar3*(-106.355646006688333*Power(Mag12,7) + RzRbar3*(-173.714221810924278*Power(Mag12,7) + RzRbar3*(-124.081587007803055*Power(Mag12,7) - 33.0884232020808148*Power(Mag12,7)*RzRbar3))))))/Power(Mag30,3);
  }
  
  double D_8_neg4_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.65550553010634472*Power(Mag12,6) + RzRbar3*(-9.8325829515951708*Power(Mag12,6) + RzRbar3*(-17.6986493128713074*Power(Mag12,6) + RzRbar3*(51.129431348294888*Power(Mag12,6) + RzRbar3*(178.953009719032108*Power(Mag12,6) + RzRbar3*(178.953009719032108*Power(Mag12,6) + 59.651003239677369*Power(Mag12,6)*RzRbar3))))))/Power(Mag30,2);
  }
  
  double D_8_neg3_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.76162860043462128*Power(Mag12,5) + RzRbar3*(4.31589540246285394*Power(Mag12,5) + RzRbar3*(38.0814300217310642*Power(Mag12,5) + RzRbar3*(33.003906018833589*Power(Mag12,5) + RzRbar3*(-115.513671065917561*Power(Mag12,5) + RzRbar3*(-207.92460791865161*Power(Mag12,5) - 92.410936852734049*Power(Mag12,5)*RzRbar3))))))/Mag30;
  }
  
  double D_8_neg2_2() {
    return 1.*Power(Mag12,4) + RzRbar3*(6.1875*Power(Mag12,4) + RzRbar3*(-20.625*Power(Mag12,4) + RzRbar3*(-89.375*Power(Mag12,4) + Power(RzRbar3,2)*(187.6875*Power(Mag12,4) + 125.125*Power(Mag12,4)*RzRbar3))));
  }
  
  double D_8_neg1_2() {
    return 0.261456258291898609*Power(Mag12,3)*Mag30 + RzRbar3*(-8.6280565236326541*Power(Mag12,3)*Mag30 + RzRbar3*(-17.2561130472653082*Power(Mag12,3)*Mag30 + RzRbar3*(74.776489871483002*Power(Mag12,3)*Mag30 + RzRbar3*(112.164734807224503*Power(Mag12,3)*Mag30 + RzRbar3*(-112.164734807224503*Power(Mag12,3)*Mag30 - 149.552979742966004*Power(Mag12,3)*Mag30*RzRbar3)))));
  }
  
  double D_8_0_2() {
    return -1.10926495933117801*Power(Mag12,2)*Power(Mag30,2) + Power(RzRbar3,2)*(36.6057436579288743*Power(Mag12,2)*Power(Mag30,2) + Power(RzRbar3,2)*(-158.624889184358455*Power(Mag12,2)*Power(Mag30,2) + 158.624889184358455*Power(Mag12,2)*Power(Mag30,2)*Power(RzRbar3,2)));
  }
  
  double D_8_1_2() {
    return 0.261456258291898609*Mag12*Power(Mag30,3) + RzRbar3*(8.6280565236326541*Mag12*Power(Mag30,3) + RzRbar3*(-17.2561130472653082*Mag12*Power(Mag30,3) + RzRbar3*(-74.776489871483002*Mag12*Power(Mag30,3) + RzRbar3*(112.164734807224503*Mag12*Power(Mag30,3) + RzRbar3*(112.164734807224503*Mag12*Power(Mag30,3) - 149.552979742966004*Mag12*Power(Mag30,3)*RzRbar3)))));
  }
  
  double D_8_2_2() {
    return 1.*Power(Mag30,4) + RzRbar3*(-6.1875*Power(Mag30,4) + RzRbar3*(-20.625*Power(Mag30,4) + RzRbar3*(89.375*Power(Mag30,4) + Power(RzRbar3,2)*(-187.6875*Power(Mag30,4) + 125.125*Power(Mag30,4)*RzRbar3))));
  }
  
  double D_8_3_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.76162860043462128*Power(Mag30,5) + RzRbar3*(-4.31589540246285394*Power(Mag30,5) + RzRbar3*(38.0814300217310642*Power(Mag30,5) + RzRbar3*(-33.003906018833589*Power(Mag30,5) + RzRbar3*(-115.513671065917561*Power(Mag30,5) + RzRbar3*(207.92460791865161*Power(Mag30,5) - 92.410936852734049*Power(Mag30,5)*RzRbar3))))))/Mag12;
  }
  
  double D_8_4_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.65550553010634472*Power(Mag30,6) + RzRbar3*(9.8325829515951708*Power(Mag30,6) + RzRbar3*(-17.6986493128713074*Power(Mag30,6) + RzRbar3*(-51.129431348294888*Power(Mag30,6) + RzRbar3*(178.953009719032108*Power(Mag30,6) + RzRbar3*(-178.953009719032108*Power(Mag30,6) + 59.651003239677369*Power(Mag30,6)*RzRbar3))))))/Power(Mag12,2);
  }
  
  double D_8_5_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.18172940007431481*Power(Mag30,7) + RzRbar3*(-3.5451882002229444*Power(Mag30,7) + RzRbar3*(-21.271129201337667*Power(Mag30,7) + RzRbar3*(106.355646006688333*Power(Mag30,7) + RzRbar3*(-173.714221810924278*Power(Mag30,7) + RzRbar3*(124.081587007803055*Power(Mag30,7) - 33.0884232020808148*Power(Mag30,7)*RzRbar3))))))/Power(Mag12,3);
  }
  
  double D_8_6_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-7.6584818175667167*Power(Mag30,8) + RzRbar3*(45.9508909054003*Power(Mag30,8) + RzRbar3*(-107.218745445934033*Power(Mag30,8) + RzRbar3*(122.535709081067467*Power(Mag30,8) + RzRbar3*(-68.92633635810045*Power(Mag30,8) + 15.3169636351334333*Power(Mag30,8)*RzRbar3))))))/Power(Mag12,4);
  }
  
  double D_8_7_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.39824108257481835*Power(Mag30,9) + RzRbar3*(12.5841697431733652*Power(Mag30,9) + RzRbar3*(-41.947232477244551*Power(Mag30,9) + RzRbar3*(69.912054128740918*Power(Mag30,9) + RzRbar3*(-62.920848715866826*Power(Mag30,9) + RzRbar3*(29.3630627340711854*Power(Mag30,9) - 5.5929643302992734*Power(Mag30,9)*RzRbar3))))))/Power(Mag12,5);
  }
  
  double D_8_8_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.39824108257481835*Power(Mag30,10) + RzRbar3*(-8.3894464954489101*Power(Mag30,10) + RzRbar3*(20.973616238622275*Power(Mag30,10) + RzRbar3*(-27.964821651496367*Power(Mag30,10) + RzRbar3*(20.9736162386222753*Power(Mag30,10) + RzRbar3*(-8.3894464954489101*Power(Mag30,10) + 1.39824108257481835*Power(Mag30,10)*RzRbar3))))))/Power(Mag12,6);
  }
  
  double D_8_neg8_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-2.0653389552322883*Power(Mag12,11) + RzRbar3*(-10.3266947761614413*Power(Mag12,11) + RzRbar3*(-20.6533895523228826*Power(Mag12,11) + RzRbar3*(-20.6533895523228826*Power(Mag12,11) + RzRbar3*(-10.3266947761614413*Power(Mag12,11) - 2.06533895523228826*Power(Mag12,11)*RzRbar3)))))/Power(Mag30,5);
  }
  
  double D_8_neg7_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (3.0980084328484324*Power(Mag12,10) + RzRbar3*(20.653389552322883*Power(Mag12,10) + RzRbar3*(51.633473880807206*Power(Mag12,10) + RzRbar3*(61.960168656968648*Power(Mag12,10) + RzRbar3*(36.143431716565045*Power(Mag12,10) + 8.261355820929153*Power(Mag12,10)*RzRbar3)))))/Power(Mag30,4);
  }
  
  double D_8_neg6_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.88538789112479451*Power(Mag12,9) + RzRbar3*(-22.624654693497534*Power(Mag12,9) + RzRbar3*(-79.186291427241369*Power(Mag12,9) + RzRbar3*(-120.664825031986849*Power(Mag12,9) + RzRbar3*(-84.842455100615753*Power(Mag12,9) - 22.6246546934975341*Power(Mag12,9)*RzRbar3)))))/Power(Mag30,3);
  }
  
  double D_8_neg5_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.87276500273555882*Power(Mag12,8) + RzRbar3*(10.4731800328267059*Power(Mag12,8) + RzRbar3*(78.548850246200294*Power(Mag12,8) + RzRbar3*(171.061940536169529*Power(Mag12,8) + RzRbar3*(152.733875478722794*Power(Mag12,8) + 48.8748401531912941*Power(Mag12,8)*RzRbar3)))))/Power(Mag30,2);
  }
  
  double D_8_neg4_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.42061459137963555*Power(Mag12,7) + RzRbar3*(8.714212528966688*Power(Mag12,7) + RzRbar3*(-37.7615876255223146*Power(Mag12,7) + RzRbar3*(-176.220742252437468*Power(Mag12,7) + RzRbar3*(-220.275927815546835*Power(Mag12,7) - 88.110371126218734*Power(Mag12,7)*RzRbar3)))))/Mag30;
  }
  
  double D_8_neg3_3() {
    return -1.0625*Power(Mag12,6) + RzRbar3*(-18.75*Power(Mag12,6) + RzRbar3*(-24.375*Power(Mag12,6) + RzRbar3*(113.75*Power(Mag12,6) + RzRbar3*(255.9375*Power(Mag12,6) + 136.5*Power(Mag12,6)*RzRbar3))));
  }
  
  double D_8_neg2_3() {
    return -1.52325720086924257*Power(Mag12,5)*Mag30 + RzRbar3*(10.1550480057949505*Power(Mag12,5)*Mag30 + RzRbar3*(66.007812037667178*Power(Mag12,5)*Mag30 + Power(RzRbar3,2)*(-231.027342131835123*Power(Mag12,5)*Mag30 - 184.821873705468098*Power(Mag12,5)*Mag30*RzRbar3)));
  }
  
  double D_8_neg1_3() {
    return 2.12408068349580356*Power(Mag12,4)*Power(Mag30,2) + RzRbar3*(8.4963227339832142*Power(Mag12,4)*Power(Mag30,2) + RzRbar3*(-55.226097770890892*Power(Mag12,4)*Power(Mag30,2) + RzRbar3*(-110.452195541781785*Power(Mag12,4)*Power(Mag30,2) + RzRbar3*(138.065244427227231*Power(Mag12,4)*Power(Mag30,2) + 220.90439108356357*Power(Mag12,4)*Power(Mag30,2)*RzRbar3))));
  }
  
  double D_8_0_3() {
    return RzRbar3*(-18.0234222610468737*Power(Mag12,3)*Power(Mag30,3) + Power(RzRbar3,2)*(156.202992929072905*Power(Mag12,3)*Power(Mag30,3) - 234.304489393609358*Power(Mag12,3)*Power(Mag30,3)*Power(RzRbar3,2)));
  }
  
  double D_8_1_3() {
    return -2.12408068349580356*Power(Mag12,2)*Power(Mag30,4) + RzRbar3*(8.4963227339832142*Power(Mag12,2)*Power(Mag30,4) + RzRbar3*(55.226097770890892*Power(Mag12,2)*Power(Mag30,4) + RzRbar3*(-110.452195541781785*Power(Mag12,2)*Power(Mag30,4) + RzRbar3*(-138.065244427227231*Power(Mag12,2)*Power(Mag30,4) + 220.90439108356357*Power(Mag12,2)*Power(Mag30,4)*RzRbar3))));
  }
  
  double D_8_2_3() {
    return 1.52325720086924257*Mag12*Power(Mag30,5) + RzRbar3*(10.1550480057949505*Mag12*Power(Mag30,5) + RzRbar3*(-66.007812037667178*Mag12*Power(Mag30,5) + Power(RzRbar3,2)*(231.027342131835123*Mag12*Power(Mag30,5) - 184.821873705468098*Mag12*Power(Mag30,5)*RzRbar3)));
  }
  
  double D_8_3_3() {
    return 1.0625*Power(Mag30,6) + RzRbar3*(-18.75*Power(Mag30,6) + RzRbar3*(24.375*Power(Mag30,6) + RzRbar3*(113.75*Power(Mag30,6) + RzRbar3*(-255.9375*Power(Mag30,6) + 136.5*Power(Mag30,6)*RzRbar3))));
  }
  
  double D_8_4_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-2.42061459137963555*Power(Mag30,7) + RzRbar3*(8.714212528966688*Power(Mag30,7) + RzRbar3*(37.7615876255223146*Power(Mag30,7) + RzRbar3*(-176.220742252437468*Power(Mag30,7) + RzRbar3*(220.275927815546835*Power(Mag30,7) - 88.110371126218734*Power(Mag30,7)*RzRbar3)))))/Mag12;
  }
  
  double D_8_5_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.87276500273555882*Power(Mag30,8) + RzRbar3*(10.4731800328267059*Power(Mag30,8) + RzRbar3*(-78.548850246200294*Power(Mag30,8) + RzRbar3*(171.061940536169529*Power(Mag30,8) + RzRbar3*(-152.733875478722794*Power(Mag30,8) + 48.8748401531912941*Power(Mag30,8)*RzRbar3)))))/Power(Mag12,2);
  }
  
  double D_8_6_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.88538789112479451*Power(Mag30,9) + RzRbar3*(-22.624654693497534*Power(Mag30,9) + RzRbar3*(79.186291427241369*Power(Mag30,9) + RzRbar3*(-120.664825031986849*Power(Mag30,9) + RzRbar3*(84.842455100615753*Power(Mag30,9) - 22.6246546934975341*Power(Mag30,9)*RzRbar3)))))/Power(Mag12,3);
  }
  
  double D_8_7_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-3.0980084328484324*Power(Mag30,10) + RzRbar3*(20.653389552322883*Power(Mag30,10) + RzRbar3*(-51.633473880807206*Power(Mag30,10) + RzRbar3*(61.960168656968648*Power(Mag30,10) + RzRbar3*(-36.143431716565045*Power(Mag30,10) + 8.261355820929153*Power(Mag30,10)*RzRbar3)))))/Power(Mag12,4);
  }
  
  double D_8_8_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.0653389552322883*Power(Mag30,11) + RzRbar3*(-10.3266947761614413*Power(Mag30,11) + RzRbar3*(20.6533895523228826*Power(Mag30,11) + RzRbar3*(-20.6533895523228826*Power(Mag30,11) + RzRbar3*(10.3266947761614413*Power(Mag30,11) - 2.06533895523228826*Power(Mag30,11)*RzRbar3)))))/Power(Mag12,5);
  }
  
  double D_8_neg8_4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.6663411259626927*Power(Mag12,12) + RzRbar3*(10.6653645038507709*Power(Mag12,12) + RzRbar3*(15.9980467557761563*Power(Mag12,12) + RzRbar3*(10.6653645038507709*Power(Mag12,12) + 2.66634112596269272*Power(Mag12,12)*RzRbar3))))/Power(Mag30,4);
  }
  
  double D_8_neg7_4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-5.3326822519253854*Power(Mag12,11) + RzRbar3*(-26.663411259626927*Power(Mag12,11) + RzRbar3*(-47.994140267328469*Power(Mag12,11) + RzRbar3*(-37.328775763477698*Power(Mag12,11) - 10.6653645038507709*Power(Mag12,11)*RzRbar3))))/Power(Mag30,3);
  }
  
  double D_8_neg6_4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (5.8416607227739613*Power(Mag12,10) + RzRbar3*(40.891625059417729*Power(Mag12,10) + RzRbar3*(93.466571564383381*Power(Mag12,10) + RzRbar3*(87.62491084160942*Power(Mag12,10) + 29.2083036138698065*Power(Mag12,10)*RzRbar3))))/Power(Mag30,2);
  }
  
  double D_8_neg5_4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-2.70416345659799197*Power(Mag12,9) + RzRbar3*(-40.5624518489698795*Power(Mag12,9) + RzRbar3*(-132.504009373301607*Power(Mag12,9) + RzRbar3*(-157.742868301549532*Power(Mag12,9) - 63.097147320619813*Power(Mag12,9)*RzRbar3))))/Mag30;
  }
  
  double D_8_neg4_4() {
    return -2.25*Power(Mag12,8) + RzRbar3*(19.5*Power(Mag12,8) + RzRbar3*(136.5*Power(Mag12,8) + RzRbar3*(227.5*Power(Mag12,8) + 113.75*Power(Mag12,8)*RzRbar3)));
  }
  
  double D_8_neg3_4() {
    return 4.84122918275927111*Power(Mag12,7)*Mag30 + RzRbar3*(12.5871958751741049*Power(Mag12,7)*Mag30 + RzRbar3*(-88.110371126218734*Power(Mag12,7)*Mag30 + RzRbar3*(-264.331113378656202*Power(Mag12,7)*Mag30 - 176.220742252437468*Power(Mag12,7)*Mag30*RzRbar3)));
  }
  
  double D_8_neg2_4() {
    return -2.62202212042537887*Power(Mag12,6)*Power(Mag30,2) + RzRbar3*(-34.0862875655299253*Power(Mag12,6)*Power(Mag30,2) + Power(RzRbar3,2)*(238.604012958709477*Power(Mag12,6)*Power(Mag30,2) + 238.604012958709477*Power(Mag12,6)*Power(Mag30,2)*RzRbar3));
  }
  
  double D_8_neg1_4() {
    return -2.19374109684803052*Power(Mag12,5)*Power(Mag30,3) + RzRbar3*(28.5186342590243967*Power(Mag12,5)*Power(Mag30,3) + RzRbar3*(85.55590277707319*Power(Mag12,5)*Power(Mag30,3) + RzRbar3*(-142.593171295121983*Power(Mag12,5)*Power(Mag30,3) - 285.186342590243967*Power(Mag12,5)*Power(Mag30,3)*RzRbar3)));
  }
  
  double D_8_0_4() {
    return 4.65362761724657122*Power(Mag12,4)*Power(Mag30,4) + Power(RzRbar3,2)*(-120.994318048410852*Power(Mag12,4)*Power(Mag30,4) + 302.48579512102713*Power(Mag12,4)*Power(Mag30,4)*Power(RzRbar3,2));
  }
  
  double D_8_1_4() {
    return -2.19374109684803052*Power(Mag12,3)*Power(Mag30,5) + RzRbar3*(-28.5186342590243967*Power(Mag12,3)*Power(Mag30,5) + RzRbar3*(85.55590277707319*Power(Mag12,3)*Power(Mag30,5) + RzRbar3*(142.593171295121983*Power(Mag12,3)*Power(Mag30,5) - 285.186342590243967*Power(Mag12,3)*Power(Mag30,5)*RzRbar3)));
  }
  
  double D_8_2_4() {
    return -2.62202212042537887*Power(Mag12,2)*Power(Mag30,6) + RzRbar3*(34.0862875655299253*Power(Mag12,2)*Power(Mag30,6) + Power(RzRbar3,2)*(-238.604012958709477*Power(Mag12,2)*Power(Mag30,6) + 238.604012958709477*Power(Mag12,2)*Power(Mag30,6)*RzRbar3));
  }
  
  double D_8_3_4() {
    return 4.84122918275927111*Mag12*Power(Mag30,7) + RzRbar3*(-12.5871958751741049*Mag12*Power(Mag30,7) + RzRbar3*(-88.110371126218734*Mag12*Power(Mag30,7) + RzRbar3*(264.331113378656202*Mag12*Power(Mag30,7) - 176.220742252437468*Mag12*Power(Mag30,7)*RzRbar3)));
  }
  
  double D_8_4_4() {
    return -2.25*Power(Mag30,8) + RzRbar3*(-19.5*Power(Mag30,8) + RzRbar3*(136.5*Power(Mag30,8) + RzRbar3*(-227.5*Power(Mag30,8) + 113.75*Power(Mag30,8)*RzRbar3)));
  }
  
  double D_8_5_4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-2.70416345659799197*Power(Mag30,9) + RzRbar3*(40.5624518489698795*Power(Mag30,9) + RzRbar3*(-132.504009373301607*Power(Mag30,9) + RzRbar3*(157.742868301549532*Power(Mag30,9) - 63.097147320619813*Power(Mag30,9)*RzRbar3))))/Mag12;
  }
  
  double D_8_6_4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (5.8416607227739613*Power(Mag30,10) + RzRbar3*(-40.891625059417729*Power(Mag30,10) + RzRbar3*(93.466571564383381*Power(Mag30,10) + RzRbar3*(-87.62491084160942*Power(Mag30,10) + 29.2083036138698065*Power(Mag30,10)*RzRbar3))))/Power(Mag12,2);
  }
  
  double D_8_7_4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-5.3326822519253854*Power(Mag30,11) + RzRbar3*(26.663411259626927*Power(Mag30,11) + RzRbar3*(-47.994140267328469*Power(Mag30,11) + RzRbar3*(37.328775763477698*Power(Mag30,11) - 10.6653645038507709*Power(Mag30,11)*RzRbar3))))/Power(Mag12,3);
  }
  
  double D_8_8_4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.6663411259626927*Power(Mag30,12) + RzRbar3*(-10.6653645038507709*Power(Mag30,12) + RzRbar3*(15.9980467557761563*Power(Mag30,12) + RzRbar3*(-10.6653645038507709*Power(Mag30,12) + 2.66634112596269272*Power(Mag30,12)*RzRbar3))))/Power(Mag12,4);
  }
  
  double D_8_neg8_5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-2.958039891549808*Power(Mag12,13) + RzRbar3*(-8.8741196746494241*Power(Mag12,13) + RzRbar3*(-8.8741196746494241*Power(Mag12,13) - 2.95803989154980802*Power(Mag12,13)*RzRbar3)))/Power(Mag30,3);
  }
  
  double D_8_neg7_5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (7.3950997288745201*Power(Mag12,12) + RzRbar3*(26.6223590239482722*Power(Mag12,12) + RzRbar3*(31.0594188612729842*Power(Mag12,12) + 11.8321595661992321*Power(Mag12,12)*RzRbar3)))/Power(Mag30,2);
  }
  
  double D_8_neg6_5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-11.3412962222137554*Power(Mag12,11) + RzRbar3*(-51.845925587262882*Power(Mag12,11) + RzRbar3*(-72.908332857088428*Power(Mag12,11) - 32.4037034920393012*Power(Mag12,11)*RzRbar3)))/Mag30;
  }
  
  double D_8_neg5_5() {
    return 11.25*Power(Mag12,10) + RzRbar3*(73.5*Power(Mag12,10) + RzRbar3*(131.25*Power(Mag12,10) + 70.*Power(Mag12,10)*RzRbar3));
  }
  
  double D_8_neg4_5() {
    return -5.4083269131959839*Power(Mag12,9)*Mag30 + RzRbar3*(-75.716576784743775*Power(Mag12,9)*Mag30 + RzRbar3*(-189.291441961859438*Power(Mag12,9)*Mag30 - 126.194294641239625*Power(Mag12,9)*Mag30*RzRbar3));
  }
  
  double D_8_neg3_5() {
    return -3.49106001094223529*Power(Mag12,8)*Power(Mag30,2) + RzRbar3*(48.8748401531912941*Power(Mag12,8)*Power(Mag30,2) + RzRbar3*(219.936780689360823*Power(Mag12,8)*Power(Mag30,2) + 195.499360612765176*Power(Mag12,8)*Power(Mag30,2)*RzRbar3));
  }
  
  double D_8_neg2_5() {
    return 9.4538352005945185*Power(Mag12,7)*Power(Mag30,3) + Power(RzRbar3,2)*(-198.530539212484889*Power(Mag12,7)*Power(Mag30,3) - 264.707385616646518*Power(Mag12,7)*Power(Mag30,3)*RzRbar3);
  }
  
  double D_8_neg1_5() {
    return -7.9096460097781873*Power(Mag12,6)*Power(Mag30,4) + RzRbar3*(-47.4578760586691237*Power(Mag12,6)*Power(Mag30,4) + RzRbar3*(118.644690146672809*Power(Mag12,6)*Power(Mag30,4) + 316.385840391127491*Power(Mag12,6)*Power(Mag30,4)*RzRbar3));
  }
  
  double D_8_0_5() {
    return RzRbar3*(67.115571963591281*Power(Mag12,5)*Power(Mag30,5) - 335.577859817956405*Power(Mag12,5)*Power(Mag30,5)*Power(RzRbar3,2));
  }
  
  double D_8_1_5() {
    return 7.9096460097781873*Power(Mag12,4)*Power(Mag30,6) + RzRbar3*(-47.4578760586691237*Power(Mag12,4)*Power(Mag30,6) + RzRbar3*(-118.644690146672809*Power(Mag12,4)*Power(Mag30,6) + 316.385840391127491*Power(Mag12,4)*Power(Mag30,6)*RzRbar3));
  }
  
  double D_8_2_5() {
    return -9.4538352005945185*Power(Mag12,3)*Power(Mag30,7) + Power(RzRbar3,2)*(198.530539212484889*Power(Mag12,3)*Power(Mag30,7) - 264.707385616646518*Power(Mag12,3)*Power(Mag30,7)*RzRbar3);
  }
  
  double D_8_3_5() {
    return 3.49106001094223529*Power(Mag12,2)*Power(Mag30,8) + RzRbar3*(48.8748401531912941*Power(Mag12,2)*Power(Mag30,8) + RzRbar3*(-219.936780689360823*Power(Mag12,2)*Power(Mag30,8) + 195.499360612765176*Power(Mag12,2)*Power(Mag30,8)*RzRbar3));
  }
  
  double D_8_4_5() {
    return 5.4083269131959839*Mag12*Power(Mag30,9) + RzRbar3*(-75.716576784743775*Mag12*Power(Mag30,9) + RzRbar3*(189.291441961859438*Mag12*Power(Mag30,9) - 126.194294641239625*Mag12*Power(Mag30,9)*RzRbar3));
  }
  
  double D_8_5_5() {
    return -11.25*Power(Mag30,10) + RzRbar3*(73.5*Power(Mag30,10) + RzRbar3*(-131.25*Power(Mag30,10) + 70.*Power(Mag30,10)*RzRbar3));
  }
  
  double D_8_6_5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (11.3412962222137554*Power(Mag30,11) + RzRbar3*(-51.845925587262882*Power(Mag30,11) + RzRbar3*(72.908332857088428*Power(Mag30,11) - 32.4037034920393012*Power(Mag30,11)*RzRbar3)))/Mag12;
  }
  
  double D_8_7_5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-7.3950997288745201*Power(Mag30,12) + RzRbar3*(26.6223590239482722*Power(Mag30,12) + RzRbar3*(-31.0594188612729842*Power(Mag30,12) + 11.8321595661992321*Power(Mag30,12)*RzRbar3)))/Power(Mag12,2);
  }
  
  double D_8_8_5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.958039891549808*Power(Mag30,13) + RzRbar3*(-8.8741196746494241*Power(Mag30,13) + RzRbar3*(8.8741196746494241*Power(Mag30,13) - 2.95803989154980802*Power(Mag30,13)*RzRbar3)))/Power(Mag12,3);
  }
  
  double D_8_neg8_6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.73861278752583057*Power(Mag12,14) + RzRbar3*(5.4772255750516611*Power(Mag12,14) + 2.73861278752583057*Power(Mag12,14)*RzRbar3))/Power(Mag30,2);
  }
  
  double D_8_neg7_6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-8.2158383625774917*Power(Mag12,13) + RzRbar3*(-19.170289512680814*Power(Mag12,13) - 10.9544511501033223*Power(Mag12,13)*RzRbar3))/Mag30;
  }
  
  double D_8_neg6_6() {
    return 16.*Power(Mag12,12) + RzRbar3*(45.*Power(Mag12,12) + 30.*Power(Mag12,12)*RzRbar3);
  }
  
  double D_8_neg5_6() {
    return -22.6825924444275108*Power(Mag12,11)*Mag30 + RzRbar3*(-81.009258730098253*Power(Mag12,11)*Mag30 - 64.807406984078602*Power(Mag12,11)*Mag30*RzRbar3);
  }
  
  double D_8_neg4_6() {
    return 23.3666428910958452*Power(Mag12,10)*Power(Mag30,2) + RzRbar3*(116.833214455479226*Power(Mag12,10)*Power(Mag30,2) + 116.833214455479226*Power(Mag12,10)*Power(Mag30,2)*RzRbar3);
  }
  
  double D_8_neg3_6() {
    return -15.0831031289983561*Power(Mag12,9)*Power(Mag30,3) + RzRbar3*(-135.747928160985205*Power(Mag12,9)*Power(Mag30,3) - 180.997237547980273*Power(Mag12,9)*Power(Mag30,3)*RzRbar3);
  }
  
  double D_8_neg2_6() {
    return RzRbar3*(122.535709081067467*Power(Mag12,8)*Power(Mag30,4) + 245.071418162134933*Power(Mag12,8)*Power(Mag30,4)*RzRbar3);
  }
  
  double D_8_neg1_6() {
    return 14.6458185158768098*Power(Mag12,7)*Power(Mag30,5) + RzRbar3*(-73.229092579384049*Power(Mag12,7)*Power(Mag30,5) - 292.916370317536196*Power(Mag12,7)*Power(Mag30,5)*RzRbar3);
  }
  
  double D_8_0_6() {
    return -20.7123151772079791*Power(Mag12,6)*Power(Mag30,6) + 310.684727658119687*Power(Mag12,6)*Power(Mag30,6)*Power(RzRbar3,2);
  }
  
  double D_8_1_6() {
    return 14.6458185158768098*Power(Mag12,5)*Power(Mag30,7) + RzRbar3*(73.229092579384049*Power(Mag12,5)*Power(Mag30,7) - 292.916370317536196*Power(Mag12,5)*Power(Mag30,7)*RzRbar3);
  }
  
  double D_8_2_6() {
    return RzRbar3*(-122.535709081067467*Power(Mag12,4)*Power(Mag30,8) + 245.071418162134933*Power(Mag12,4)*Power(Mag30,8)*RzRbar3);
  }
  
  double D_8_3_6() {
    return -15.0831031289983561*Power(Mag12,3)*Power(Mag30,9) + RzRbar3*(135.747928160985205*Power(Mag12,3)*Power(Mag30,9) - 180.997237547980273*Power(Mag12,3)*Power(Mag30,9)*RzRbar3);
  }
  
  double D_8_4_6() {
    return 23.3666428910958452*Power(Mag12,2)*Power(Mag30,10) + RzRbar3*(-116.833214455479226*Power(Mag12,2)*Power(Mag30,10) + 116.833214455479226*Power(Mag12,2)*Power(Mag30,10)*RzRbar3);
  }
  
  double D_8_5_6() {
    return -22.6825924444275108*Mag12*Power(Mag30,11) + RzRbar3*(81.009258730098253*Mag12*Power(Mag30,11) - 64.807406984078602*Mag12*Power(Mag30,11)*RzRbar3);
  }
  
  double D_8_6_6() {
    return 16.*Power(Mag30,12) + RzRbar3*(-45.*Power(Mag30,12) + 30.*Power(Mag30,12)*RzRbar3);
  }
  
  double D_8_7_6() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-8.2158383625774917*Power(Mag30,13) + RzRbar3*(19.170289512680814*Power(Mag30,13) - 10.9544511501033223*Power(Mag30,13)*RzRbar3))/Mag12;
  }
  
  double D_8_8_6() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.73861278752583057*Power(Mag30,14) + RzRbar3*(-5.4772255750516611*Power(Mag30,14) + 2.73861278752583057*Power(Mag30,14)*RzRbar3))/Power(Mag12,2);
  }
  
  double D_8_neg8_7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-2.*Power(Mag12,15) - 2.*Power(Mag12,15)*RzRbar3)/Mag30;
  }
  
  double D_8_neg7_7() {
    return 7.*Power(Mag12,14) + 8.*Power(Mag12,14)*RzRbar3;
  }
  
  double D_8_neg6_7() {
    return -16.4316767251549834*Power(Mag12,13)*Mag30 - 21.9089023002066445*Power(Mag12,13)*Mag30*RzRbar3;
  }
  
  double D_8_neg5_7() {
    return 29.5803989154980802*Power(Mag12,12)*Power(Mag30,2) + 47.3286382647969283*Power(Mag12,12)*Power(Mag30,2)*RzRbar3;
  }
  
  double D_8_neg4_7() {
    return -42.6614580154030835*Power(Mag12,11)*Power(Mag30,3) - 85.322916030806167*Power(Mag12,11)*Power(Mag30,3)*RzRbar3;
  }
  
  double D_8_neg3_7() {
    return 49.5681349255749182*Power(Mag12,10)*Power(Mag30,4) + 132.181693134866448*Power(Mag12,10)*Power(Mag30,4)*RzRbar3;
  }
  
  double D_8_neg2_7() {
    return -44.7437146423941873*Power(Mag12,9)*Power(Mag30,5) - 178.974858569576749*Power(Mag12,9)*Power(Mag30,5)*RzRbar3;
  }
  
  double D_8_neg1_7() {
    return 26.7394839142418753*Power(Mag12,8)*Power(Mag30,6) + 213.915871313935002*Power(Mag12,8)*Power(Mag30,6)*RzRbar3;
  }
  
  double D_8_0_7() {
    return -226.892044814268444*Power(Mag12,7)*Power(Mag30,7)*RzRbar3;
  }
  
  double D_8_1_7() {
    return -26.7394839142418753*Power(Mag12,6)*Power(Mag30,8) + 213.915871313935002*Power(Mag12,6)*Power(Mag30,8)*RzRbar3;
  }
  
  double D_8_2_7() {
    return 44.7437146423941873*Power(Mag12,5)*Power(Mag30,9) - 178.974858569576749*Power(Mag12,5)*Power(Mag30,9)*RzRbar3;
  }
  
  double D_8_3_7() {
    return -49.5681349255749182*Power(Mag12,4)*Power(Mag30,10) + 132.181693134866448*Power(Mag12,4)*Power(Mag30,10)*RzRbar3;
  }
  
  double D_8_4_7() {
    return 42.6614580154030835*Power(Mag12,3)*Power(Mag30,11) - 85.322916030806167*Power(Mag12,3)*Power(Mag30,11)*RzRbar3;
  }
  
  double D_8_5_7() {
    return -29.5803989154980802*Power(Mag12,2)*Power(Mag30,12) + 47.3286382647969283*Power(Mag12,2)*Power(Mag30,12)*RzRbar3;
  }
  
  double D_8_6_7() {
    return 16.4316767251549834*Mag12*Power(Mag30,13) - 21.9089023002066445*Mag12*Power(Mag30,13)*RzRbar3;
  }
  
  double D_8_7_7() {
    return -7.*Power(Mag30,14) + 8.*Power(Mag30,14)*RzRbar3;
  }
  
  double D_8_8_7() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.*Power(Mag30,15) - 2.*Power(Mag30,15)*RzRbar3)/Mag12;
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
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00006103515625 + RzRbar3*(0.0008544921875 + RzRbar3*(0.00555419921875 + RzRbar3*(0.022216796875 + RzRbar3*(0.06109619140625 + RzRbar3*(0.1221923828125 + RzRbar3*(0.18328857421875 + RzRbar3*(0.20947265625 + RzRbar3*(0.18328857421875 + RzRbar3*(0.1221923828125 + RzRbar3*(0.06109619140625 + RzRbar3*(0.022216796875 + RzRbar3*(0.00555419921875 + (0.0008544921875 + 0.00006103515625*RzRbar3)*RzRbar3)))))))))))))/Power(Mag30,14);
  }
  
  double D_7_neg6_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0002283726432357142 + RzRbar3*(0.0027404717188285704 + RzRbar3*(0.014844221810321423 + RzRbar3*(0.047501509793028553 + RzRbar3*(0.09797186394812139 + RzRbar3*(0.13062915193082852 + RzRbar3*(0.09797186394812139 + RzRbar3*(0.e-17 + RzRbar3*(-0.09797186394812139 + RzRbar3*(-0.13062915193082852 + RzRbar3*(-0.09797186394812139 + RzRbar3*(-0.047501509793028553 + RzRbar3*(-0.0148442218103214227 + (-0.00274047171882857035 - 0.000228372643235714196*RzRbar3)*RzRbar3)))))))))))))/(Mag12*Power(Mag30,13));
  }
  
  double D_7_neg5_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00058223828211483499 + RzRbar3*(0.00582238282114835 + RzRbar3*(0.025036246130937905 + RzRbar3*(0.0582238282114835 + RzRbar3*(0.07045083213589503 + RzRbar3*(0.0128092422065264 + RzRbar3*(-0.0960693165489478 + RzRbar3*(-0.1537109064783164 + RzRbar3*(-0.0960693165489478 + RzRbar3*(0.01280924220652637 + RzRbar3*(0.07045083213589503 + RzRbar3*(0.058223828211483499 + RzRbar3*(0.025036246130937905 + (0.0058223828211483499 + 0.000582238282114834991*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,2)*Power(Mag30,12));
  }
  
  double D_7_neg4_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00116447656422967 + RzRbar3*(0.00931581251383736 + RzRbar3*(0.02911191410574175 + RzRbar3*(0.03726325005534944 + RzRbar3*(-0.0128092422065264 + RzRbar3*(-0.102473937652211 + RzRbar3*(-0.1152831798587373 + RzRbar3*(0.e-16 + RzRbar3*(0.1152831798587373 + RzRbar3*(0.102473937652211 + RzRbar3*(0.01280924220652637 + RzRbar3*(-0.03726325005534944 + RzRbar3*(-0.02911191410574175 + (-0.0093158125138373599 - 0.00116447656422966998*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,3)*Power(Mag30,11));
  }
  
  double D_7_neg3_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0019310659203560028 + RzRbar3*(0.011586395522136017 + RzRbar3*(0.02124172512391603 + RzRbar3*(-0.00772426368142401 + RzRbar3*(-0.0753115708938841 + RzRbar3*(-0.0733805049735281 + RzRbar3*(0.0521387798496121 + RzRbar3*(0.1390367462656322 + RzRbar3*(0.0521387798496121 + RzRbar3*(-0.0733805049735281 + RzRbar3*(-0.07531157089388411 + RzRbar3*(-0.00772426368142401 + RzRbar3*(0.02124172512391603 + (0.0115863955221360165 + 0.00193106592035600276*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,4)*Power(Mag30,10));
  }
  
  double D_7_neg2_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0027309396144039421 + RzRbar3*(0.010923758457615768 + RzRbar3*(0.00273093961440394 + RzRbar3*(-0.0436950338304631 + RzRbar3*(-0.0518878526736749 + RzRbar3*(0.0546187922880788 + RzRbar3*(0.1228922826481774 + RzRbar3*(0.e-16 + RzRbar3*(-0.1228922826481774 + RzRbar3*(-0.0546187922880788 + RzRbar3*(0.0518878526736749 + RzRbar3*(0.04369503383046307 + RzRbar3*(-0.002730939614403942 + (-0.0109237584576157684 - 0.0027309396144039421*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,5)*Power(Mag30,9));
  }
  
  double D_7_neg1_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0033447042868213519 + RzRbar3*(0.006689408573642704 + RzRbar3*(-0.01672352143410676 + RzRbar3*(-0.0401364514418562 + RzRbar3*(0.0301023385813922 + RzRbar3*(0.1003411286046406 + RzRbar3*(-0.0167235214341068 + RzRbar3*(-0.1337881714728541 + RzRbar3*(-0.0167235214341068 + RzRbar3*(0.1003411286046406 + RzRbar3*(0.0301023385813922 + RzRbar3*(-0.04013645144185622 + RzRbar3*(-0.016723521434106759 + (0.0066894085736427037 + 0.00334470428682135185*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,6)*Power(Mag30,8));
  }
  
  double D_7_0_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0035756392861027368 + Power(RzRbar3,2)*(-0.025029475002719157 + Power(RzRbar3,2)*(0.075088425008157472 + Power(RzRbar3,2)*(-0.125147375013595787 + Power(RzRbar3,2)*(0.125147375013595787 + Power(RzRbar3,2)*(-0.075088425008157472 + Power(RzRbar3,2)*(0.0250294750027191574 - 0.00357563928610273677*Power(RzRbar3,2))))))))/(Power(Mag12,7)*Power(Mag30,7));
  }
  
  double D_7_1_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0033447042868213519 + RzRbar3*(-0.006689408573642704 + RzRbar3*(-0.01672352143410676 + RzRbar3*(0.0401364514418562 + RzRbar3*(0.0301023385813922 + RzRbar3*(-0.1003411286046406 + RzRbar3*(-0.0167235214341068 + RzRbar3*(0.1337881714728541 + RzRbar3*(-0.0167235214341068 + RzRbar3*(-0.1003411286046406 + RzRbar3*(0.0301023385813922 + RzRbar3*(0.04013645144185622 + RzRbar3*(-0.016723521434106759 + (-0.0066894085736427037 + 0.00334470428682135185*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,8)*Power(Mag30,6));
  }
  
  double D_7_2_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0027309396144039421 + RzRbar3*(-0.010923758457615768 + RzRbar3*(0.00273093961440394 + RzRbar3*(0.0436950338304631 + RzRbar3*(-0.0518878526736749 + RzRbar3*(-0.0546187922880788 + RzRbar3*(0.1228922826481774 + RzRbar3*(0.e-16 + RzRbar3*(-0.1228922826481774 + RzRbar3*(0.0546187922880788 + RzRbar3*(0.0518878526736749 + RzRbar3*(-0.04369503383046307 + RzRbar3*(-0.002730939614403942 + (0.0109237584576157684 - 0.0027309396144039421*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,9)*Power(Mag30,5));
  }
  
  double D_7_3_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0019310659203560028 + RzRbar3*(-0.011586395522136017 + RzRbar3*(0.02124172512391603 + RzRbar3*(0.00772426368142401 + RzRbar3*(-0.0753115708938841 + RzRbar3*(0.0733805049735281 + RzRbar3*(0.0521387798496121 + RzRbar3*(-0.1390367462656322 + RzRbar3*(0.0521387798496121 + RzRbar3*(0.0733805049735281 + RzRbar3*(-0.07531157089388411 + RzRbar3*(0.00772426368142401 + RzRbar3*(0.02124172512391603 + (-0.0115863955221360165 + 0.00193106592035600276*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,10)*Power(Mag30,4));
  }
  
  double D_7_4_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00116447656422967 + RzRbar3*(-0.00931581251383736 + RzRbar3*(0.02911191410574175 + RzRbar3*(-0.03726325005534944 + RzRbar3*(-0.0128092422065264 + RzRbar3*(0.102473937652211 + RzRbar3*(-0.1152831798587373 + RzRbar3*(0.e-16 + RzRbar3*(0.1152831798587373 + RzRbar3*(-0.102473937652211 + RzRbar3*(0.01280924220652637 + RzRbar3*(0.03726325005534944 + RzRbar3*(-0.02911191410574175 + (0.0093158125138373599 - 0.00116447656422966998*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,11)*Power(Mag30,3));
  }
  
  double D_7_5_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00058223828211483499 + RzRbar3*(-0.00582238282114835 + RzRbar3*(0.025036246130937905 + RzRbar3*(-0.0582238282114835 + RzRbar3*(0.07045083213589503 + RzRbar3*(-0.0128092422065264 + RzRbar3*(-0.0960693165489478 + RzRbar3*(0.1537109064783164 + RzRbar3*(-0.0960693165489478 + RzRbar3*(-0.01280924220652637 + RzRbar3*(0.07045083213589503 + RzRbar3*(-0.058223828211483499 + RzRbar3*(0.025036246130937905 + (-0.0058223828211483499 + 0.000582238282114834991*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,12)*Power(Mag30,2));
  }
  
  double D_7_6_neg7() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0002283726432357142 + RzRbar3*(-0.0027404717188285704 + RzRbar3*(0.014844221810321423 + RzRbar3*(-0.047501509793028553 + RzRbar3*(0.09797186394812139 + RzRbar3*(-0.13062915193082852 + RzRbar3*(0.09797186394812139 + RzRbar3*(0.e-17 + RzRbar3*(-0.09797186394812139 + RzRbar3*(0.13062915193082852 + RzRbar3*(-0.09797186394812139 + RzRbar3*(0.047501509793028553 + RzRbar3*(-0.0148442218103214227 + (0.00274047171882857035 - 0.000228372643235714196*RzRbar3)*RzRbar3)))))))))))))/(Power(Mag12,13)*Mag30);
  }
  
  double D_7_7_neg7() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00006103515625 + RzRbar3*(-0.0008544921875 + RzRbar3*(0.00555419921875 + RzRbar3*(-0.022216796875 + RzRbar3*(0.06109619140625 + RzRbar3*(-0.1221923828125 + RzRbar3*(0.18328857421875 + RzRbar3*(-0.20947265625 + RzRbar3*(0.18328857421875 + RzRbar3*(-0.1221923828125 + RzRbar3*(0.06109619140625 + RzRbar3*(-0.022216796875 + RzRbar3*(0.00555419921875 + (-0.0008544921875 + 0.00006103515625*RzRbar3)*RzRbar3)))))))))))))/Power(Mag12,14);
  }
  
  double D_7_neg7_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.00045674528647142839*Mag12 + RzRbar3*(-0.0059376887241285691*Mag12 + RzRbar3*(-0.035626132344771415*Mag12 + RzRbar3*(-0.13062915193082852*Mag12 + RzRbar3*(-0.3265728798270713*Mag12 + RzRbar3*(-0.58783118368872834*Mag12 + RzRbar3*(-0.78377491158497112*Mag12 + RzRbar3*(-0.78377491158497112*Mag12 + RzRbar3*(-0.58783118368872834*Mag12 + RzRbar3*(-0.3265728798270713*Mag12 + RzRbar3*(-0.13062915193082852*Mag12 + RzRbar3*(-0.035626132344771415*Mag12 + RzRbar3*(-0.0059376887241285691*Mag12 - 0.000456745286471428392*Mag12*RzRbar3)))))))))))))/Power(Mag30,13);
  }
  
  double D_7_neg6_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.00146484375 + RzRbar3*(-0.015869140625 + RzRbar3*(-0.076171875 + RzRbar3*(-0.20947265625 + RzRbar3*(-0.34912109375 + RzRbar3*(-0.314208984375 + RzRbar3*(0.e-16 + RzRbar3*(0.4189453125 + RzRbar3*(0.62841796875 + RzRbar3*(0.523681640625 + RzRbar3*(0.279296875 + RzRbar3*(0.09521484375 + (0.01904296875 + 0.001708984375*RzRbar3)*RzRbar3))))))))))))/Power(Mag30,12);
  }
  
  double D_7_neg5_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0031121945273393462 + RzRbar3*(-0.026764872935118377 + RzRbar3*(-0.09336583582018039 + RzRbar3*(-0.1506302151232244 + RzRbar3*(-0.0342341398007328 + RzRbar3*(0.3081072582065953 + RzRbar3*(0.5751335486523112 + RzRbar3*(0.4108096776087937 + RzRbar3*(-0.0616214516413191 + RzRbar3*(-0.3765755378080609 + RzRbar3*(-0.34234139800732808 + RzRbar3*(-0.16058923761071026 + (-0.040458528855411501 - 0.00435707233827508469*RzRbar3)*RzRbar3))))))))))))/(Mag12*Power(Mag30,11));
  }
  
  double D_7_neg4_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0049795112437429539 + RzRbar3*(-0.031121945273393462 + RzRbar3*(-0.05975413492491545 + RzRbar3*(0.0273873118405862 + RzRbar3*(0.2738731184058625 + RzRbar3*(0.3697287098479143 + RzRbar3*(0.e-16 + RzRbar3*(-0.4929716131305524 + RzRbar3*(-0.4929716131305524 + RzRbar3*(-0.0684682796014656 + RzRbar3*(0.21909849472468997 + RzRbar3*(0.18673167164036077 + (0.064733646168658401 + 0.0087141446765501694*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,2)*Power(Mag30,10));
  }
  
  double D_7_neg3_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0061931889130692491 + RzRbar3*(-0.02270835934792058 + RzRbar3*(0.0123863778261385 + RzRbar3*(0.1610229117398005 + RzRbar3*(0.1961176489138596 + RzRbar3*(-0.16721610065287 + RzRbar3*(-0.520227868697817 + RzRbar3*(-0.222954800870493 + RzRbar3*(0.3530117680449472 + RzRbar3*(0.4025572793495012 + RzRbar3*(0.0454167186958412 + RzRbar3*(-0.13625015608752348 + (-0.080511455869900238 - 0.0144507741304949146*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,3)*Power(Mag30,9));
  }
  
  double D_7_neg2_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0058389945034674795 + RzRbar3*(-0.00291949725173374 + RzRbar3*(0.07006793404160975 + RzRbar3*(0.1109408955658821 + RzRbar3*(-0.145974862586687 + RzRbar3*(-0.394132128984055 + RzRbar3*(0.e-15 + RzRbar3*(0.525509505312073 + RzRbar3*(0.262754752656037 + RzRbar3*(-0.2773522389147053 + RzRbar3*(-0.2569157581525691 + RzRbar3*(0.01751698351040244 + (0.075906928545077234 + 0.0204364807621361783*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,4)*Power(Mag30,8));
  }
  
  double D_7_neg1_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0035756392861027368 + RzRbar3*(0.017878196430513684 + RzRbar3*(0.06436150714984926 + RzRbar3*(-0.0643615071498493 + RzRbar3*(-0.2681729464577053 + RzRbar3*(0.053634589291541 + RzRbar3*(0.500589500054383 + RzRbar3*(0.071512785722055 + RzRbar3*(-0.482711303623869 + RzRbar3*(-0.1609037678746232 + RzRbar3*(0.2359921928827806 + RzRbar3*(0.1072691785830821 + (-0.046483310719335578 - 0.0250294750027191574*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,5)*Power(Mag30,7));
  }
  
  double D_7_0_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(0.026757634294570815 + Power(RzRbar3,2)*(-0.160545805767424889 + Power(RzRbar3,2)*(0.40136451441856222 + Power(RzRbar3,2)*(-0.5351526858914163 + Power(RzRbar3,2)*(0.40136451441856222 + Power(RzRbar3,2)*(-0.160545805767424889 + 0.0267576342945708148*Power(RzRbar3,2))))))))/(Power(Mag12,6)*Power(Mag30,6));
  }
  
  double D_7_1_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0035756392861027368 + RzRbar3*(0.017878196430513684 + RzRbar3*(-0.06436150714984926 + RzRbar3*(-0.0643615071498493 + RzRbar3*(0.2681729464577053 + RzRbar3*(0.053634589291541 + RzRbar3*(-0.500589500054383 + RzRbar3*(0.071512785722055 + RzRbar3*(0.482711303623869 + RzRbar3*(-0.1609037678746232 + RzRbar3*(-0.2359921928827806 + RzRbar3*(0.1072691785830821 + (0.046483310719335578 - 0.0250294750027191574*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,7)*Power(Mag30,5));
  }
  
  double D_7_2_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0058389945034674795 + RzRbar3*(-0.00291949725173374 + RzRbar3*(-0.07006793404160975 + RzRbar3*(0.1109408955658821 + RzRbar3*(0.145974862586687 + RzRbar3*(-0.394132128984055 + RzRbar3*(0.e-15 + RzRbar3*(0.525509505312073 + RzRbar3*(-0.262754752656037 + RzRbar3*(-0.2773522389147053 + RzRbar3*(0.2569157581525691 + RzRbar3*(0.01751698351040244 + (-0.075906928545077234 + 0.0204364807621361783*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,8)*Power(Mag30,4));
  }
  
  double D_7_3_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0061931889130692491 + RzRbar3*(-0.02270835934792058 + RzRbar3*(-0.0123863778261385 + RzRbar3*(0.1610229117398005 + RzRbar3*(-0.1961176489138596 + RzRbar3*(-0.16721610065287 + RzRbar3*(0.520227868697817 + RzRbar3*(-0.222954800870493 + RzRbar3*(-0.3530117680449472 + RzRbar3*(0.4025572793495012 + RzRbar3*(-0.0454167186958412 + RzRbar3*(-0.13625015608752348 + (0.080511455869900238 - 0.0144507741304949146*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,9)*Power(Mag30,3));
  }
  
  double D_7_4_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0049795112437429539 + RzRbar3*(-0.031121945273393462 + RzRbar3*(0.05975413492491545 + RzRbar3*(0.0273873118405862 + RzRbar3*(-0.2738731184058625 + RzRbar3*(0.3697287098479143 + RzRbar3*(0.e-16 + RzRbar3*(-0.4929716131305524 + RzRbar3*(0.4929716131305524 + RzRbar3*(-0.0684682796014656 + RzRbar3*(-0.21909849472468997 + RzRbar3*(0.18673167164036077 + (-0.064733646168658401 + 0.0087141446765501694*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,10)*Power(Mag30,2));
  }
  
  double D_7_5_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0031121945273393462 + RzRbar3*(-0.026764872935118377 + RzRbar3*(0.09336583582018039 + RzRbar3*(-0.1506302151232244 + RzRbar3*(0.0342341398007328 + RzRbar3*(0.3081072582065953 + RzRbar3*(-0.5751335486523112 + RzRbar3*(0.4108096776087937 + RzRbar3*(0.0616214516413191 + RzRbar3*(-0.3765755378080609 + RzRbar3*(0.34234139800732808 + RzRbar3*(-0.16058923761071026 + (0.040458528855411501 - 0.00435707233827508469*RzRbar3)*RzRbar3))))))))))))/(Power(Mag12,11)*Mag30);
  }
  
  double D_7_6_neg6() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00146484375 + RzRbar3*(-0.015869140625 + RzRbar3*(0.076171875 + RzRbar3*(-0.20947265625 + RzRbar3*(0.34912109375 + RzRbar3*(-0.314208984375 + RzRbar3*(0.e-16 + RzRbar3*(0.4189453125 + RzRbar3*(-0.62841796875 + RzRbar3*(0.523681640625 + RzRbar3*(-0.279296875 + RzRbar3*(0.09521484375 + (-0.01904296875 + 0.001708984375*RzRbar3)*RzRbar3))))))))))))/Power(Mag12,12);
  }
  
  double D_7_7_neg6() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00045674528647142839*Mag30 + RzRbar3*(-0.0059376887241285691*Mag30 + RzRbar3*(0.035626132344771415*Mag30 + RzRbar3*(-0.13062915193082852*Mag30 + RzRbar3*(0.3265728798270713*Mag30 + RzRbar3*(-0.58783118368872834*Mag30 + RzRbar3*(0.78377491158497112*Mag30 + RzRbar3*(-0.78377491158497112*Mag30 + RzRbar3*(0.58783118368872834*Mag30 + RzRbar3*(-0.3265728798270713*Mag30 + RzRbar3*(0.13062915193082852*Mag30 + RzRbar3*(-0.035626132344771415*Mag30 + RzRbar3*(0.0059376887241285691*Mag30 - 0.000456745286471428392*Mag30*RzRbar3)))))))))))))/Power(Mag12,13);
  }
  
  double D_7_neg7_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00232895312845934*Power(Mag12,2) + RzRbar3*(0.02794743754151208*Power(Mag12,2) + RzRbar3*(0.15371090647831644*Power(Mag12,2) + RzRbar3*(0.51236968826105479*Power(Mag12,2) + RzRbar3*(1.1528317985873733*Power(Mag12,2) + RzRbar3*(1.8445308777397973*Power(Mag12,2) + RzRbar3*(2.1519526906964301*Power(Mag12,2) + RzRbar3*(1.8445308777397973*Power(Mag12,2) + RzRbar3*(1.15283179858737328*Power(Mag12,2) + RzRbar3*(0.51236968826105479*Power(Mag12,2) + RzRbar3*(0.153710906478316438*Power(Mag12,2) + RzRbar3*(0.0279474375415120796*Power(Mag12,2) + 0.00232895312845933996*Power(Mag12,2)*RzRbar3))))))))))))/Power(Mag30,12);
  }
  
  double D_7_neg6_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0062243890546786924*Mag12 + RzRbar3*(0.059754134924915447*Mag12 + RzRbar3*(0.24648580656527622*Mag12 + RzRbar3*(0.5477462368117249*Mag12 + RzRbar3*(0.6162145164131905*Mag12 + RzRbar3*(0.e-16*Mag12 + RzRbar3*(-1.1502670973046224*Mag12 + RzRbar3*(-1.9718864525222098*Mag12 + RzRbar3*(-1.8486435492395716*Mag12 + RzRbar3*(-1.09549247362344987*Mag12 + RzRbar3*(-0.4108096776087937*Mag12 + RzRbar3*(-0.089631202387373171*Mag12 - 0.0087141446765501694*Mag12*RzRbar3))))))))))))/Power(Mag30,11);
  }
  
  double D_7_neg5_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.010498046875 + RzRbar3*(0.0732421875 + RzRbar3*(0.17724609375 + RzRbar3*(0.0537109375 + RzRbar3*(-0.604248046875 + RzRbar3*(-1.353515625 + RzRbar3*(-1.1279296875 + RzRbar3*(0.193359375 + RzRbar3*(1.329345703125 + RzRbar3*(1.3427734375 + RzRbar3*(0.69287109375 + (0.1904296875 + 0.022216796875*RzRbar3)*RzRbar3)))))))))))/Power(Mag30,10);
  }
  
  double D_7_neg4_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.01220703125 + RzRbar3*(0.046875 + RzRbar3*(-0.0322265625 + RzRbar3*(-0.4296875 + RzRbar3*(-0.72509765625 + RzRbar3*(0.e-15 + RzRbar3*(1.353515625 + RzRbar3*(1.546875 + RzRbar3*(0.24169921875 + RzRbar3*(-0.859375 + RzRbar3*(-0.8056640625 + (-0.3046875 - 0.04443359375*RzRbar3)*RzRbar3)))))))))))/(Mag12*Power(Mag30,9));
  }
  
  double D_7_neg3_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.008906951341286474 + RzRbar3*(-0.00971667419049434 + RzRbar3*(-0.1894751467146395 + RzRbar3*(-0.3076946826989873 + RzRbar3*(0.327937753929184 + RzRbar3*(1.224300948002286 + RzRbar3*(0.612150474001143 + RzRbar3*(-1.107700857716354 + RzRbar3*(-1.421063600359797 + RzRbar3*(-0.1781390268257295 + RzRbar3*(0.5878587885249073 + (0.37895029342927908 + 0.073684779277915378*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,2)*Power(Mag30,8));
  }
  
  double D_7_neg2_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.001145121035113142 + RzRbar3*(-0.054965809685430815 + RzRbar3*(-0.13054379800289819 + RzRbar3*(0.2290242070226284 + RzRbar3*(0.772956698701371 + RzRbar3*(0.e-15 + RzRbar3*(-1.442852504242559 + RzRbar3*(-0.824487145281462 + RzRbar3*(0.979078485021736 + RzRbar3*(1.0077065108995649 + RzRbar3*(-0.0755779883174674 + (-0.3572777629553003 - 0.10420601419529592*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,3)*Power(Mag30,7));
  }
  
  double D_7_neg1_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.007012405574387242 + RzRbar3*(-0.05048932013558814 + RzRbar3*(0.07573398020338221 + RzRbar3*(0.4207443344632345 + RzRbar3*(-0.1051860836158086 + RzRbar3*(-1.178084136497057 + RzRbar3*(-0.196347356082843 + RzRbar3*(1.514679604067644 + RzRbar3*(0.568004851525367 + RzRbar3*(-0.9256375358191159 + RzRbar3*(-0.462818767909558 + (0.21878705392088195 + 0.127625781453847805*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,4)*Power(Mag30,6));
  }
  
  double D_7_0_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.010495207646584315 + Power(RzRbar3,2)*(0.18891373763851767 + Power(RzRbar3,2)*(-0.78714057349382362 + Power(RzRbar3,2)*(1.46932907052180409 + Power(RzRbar3,2)*(-1.41685303228888252 + Power(RzRbar3,2)*(0.69268370467456479 - 0.136437699405596094*Power(RzRbar3,2)))))))/(Power(Mag12,5)*Power(Mag30,5));
  }
  
  double D_7_1_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.007012405574387242 + RzRbar3*(0.05048932013558814 + RzRbar3*(0.07573398020338221 + RzRbar3*(-0.4207443344632345 + RzRbar3*(-0.1051860836158086 + RzRbar3*(1.178084136497057 + RzRbar3*(-0.196347356082843 + RzRbar3*(-1.514679604067644 + RzRbar3*(0.568004851525367 + RzRbar3*(0.9256375358191159 + RzRbar3*(-0.462818767909558 + (-0.21878705392088195 + 0.127625781453847805*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,6)*Power(Mag30,4));
  }
  
  double D_7_2_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.001145121035113142 + RzRbar3*(0.054965809685430815 + RzRbar3*(-0.13054379800289819 + RzRbar3*(-0.2290242070226284 + RzRbar3*(0.772956698701371 + RzRbar3*(0.e-15 + RzRbar3*(-1.442852504242559 + RzRbar3*(0.824487145281462 + RzRbar3*(0.979078485021736 + RzRbar3*(-1.0077065108995649 + RzRbar3*(-0.0755779883174674 + (0.3572777629553003 - 0.10420601419529592*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,7)*Power(Mag30,3));
  }
  
  double D_7_3_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.008906951341286474 + RzRbar3*(0.00971667419049434 + RzRbar3*(-0.1894751467146395 + RzRbar3*(0.3076946826989873 + RzRbar3*(0.327937753929184 + RzRbar3*(-1.224300948002286 + RzRbar3*(0.612150474001143 + RzRbar3*(1.107700857716354 + RzRbar3*(-1.421063600359797 + RzRbar3*(0.1781390268257295 + RzRbar3*(0.5878587885249073 + (-0.37895029342927908 + 0.073684779277915378*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,8)*Power(Mag30,2));
  }
  
  double D_7_4_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.01220703125 + RzRbar3*(-0.046875 + RzRbar3*(-0.0322265625 + RzRbar3*(0.4296875 + RzRbar3*(-0.72509765625 + RzRbar3*(0.e-15 + RzRbar3*(1.353515625 + RzRbar3*(-1.546875 + RzRbar3*(0.24169921875 + RzRbar3*(0.859375 + RzRbar3*(-0.8056640625 + (0.3046875 - 0.04443359375*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,9)*Mag30);
  }
  
  double D_7_5_neg5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.010498046875 + RzRbar3*(-0.0732421875 + RzRbar3*(0.17724609375 + RzRbar3*(-0.0537109375 + RzRbar3*(-0.604248046875 + RzRbar3*(1.353515625 + RzRbar3*(-1.1279296875 + RzRbar3*(-0.193359375 + RzRbar3*(1.329345703125 + RzRbar3*(-1.3427734375 + RzRbar3*(0.69287109375 + (-0.1904296875 + 0.022216796875*RzRbar3)*RzRbar3)))))))))))/Power(Mag12,10);
  }
  
  double D_7_6_neg5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0062243890546786924*Mag30 + RzRbar3*(-0.059754134924915447*Mag30 + RzRbar3*(0.24648580656527622*Mag30 + RzRbar3*(-0.5477462368117249*Mag30 + RzRbar3*(0.6162145164131905*Mag30 + RzRbar3*(0.e-16*Mag30 + RzRbar3*(-1.1502670973046224*Mag30 + RzRbar3*(1.9718864525222098*Mag30 + RzRbar3*(-1.8486435492395716*Mag30 + RzRbar3*(1.09549247362344987*Mag30 + RzRbar3*(-0.4108096776087937*Mag30 + RzRbar3*(0.089631202387373171*Mag30 - 0.0087141446765501694*Mag30*RzRbar3))))))))))))/Power(Mag12,11);
  }
  
  double D_7_7_neg5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00232895312845934*Power(Mag30,2) + RzRbar3*(-0.02794743754151208*Power(Mag30,2) + RzRbar3*(0.15371090647831644*Power(Mag30,2) + RzRbar3*(-0.51236968826105479*Power(Mag30,2) + RzRbar3*(1.1528317985873733*Power(Mag30,2) + RzRbar3*(-1.8445308777397973*Power(Mag30,2) + RzRbar3*(2.1519526906964301*Power(Mag30,2) + RzRbar3*(-1.8445308777397973*Power(Mag30,2) + RzRbar3*(1.15283179858737328*Power(Mag30,2) + RzRbar3*(-0.51236968826105479*Power(Mag30,2) + RzRbar3*(0.153710906478316438*Power(Mag30,2) + RzRbar3*(-0.0279474375415120796*Power(Mag30,2) + 0.00232895312845933996*Power(Mag30,2)*RzRbar3))))))))))))/Power(Mag12,12);
  }
  
  double D_7_neg7_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.00931581251383736*Power(Mag12,3) + RzRbar3*(-0.10247393765221096*Power(Mag12,3) + RzRbar3*(-0.51236968826105479*Power(Mag12,3) + RzRbar3*(-1.5371090647831644*Power(Mag12,3) + RzRbar3*(-3.0742181295663288*Power(Mag12,3) + RzRbar3*(-4.3039053813928603*Power(Mag12,3) + RzRbar3*(-4.3039053813928603*Power(Mag12,3) + RzRbar3*(-3.0742181295663288*Power(Mag12,3) + RzRbar3*(-1.53710906478316438*Power(Mag12,3) + RzRbar3*(-0.51236968826105479*Power(Mag12,3) + RzRbar3*(-0.102473937652210958*Power(Mag12,3) - 0.00931581251383735986*Power(Mag12,3)*RzRbar3)))))))))))/Power(Mag30,11);
  }
  
  double D_7_neg6_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.019918044974971816*Power(Mag12,2) + RzRbar3*(-0.16432387104351748*Power(Mag12,2) + RzRbar3*(-0.5477462368117249*Power(Mag12,2) + RzRbar3*(-0.8216193552175874*Power(Mag12,2) + RzRbar3*(0.e-16*Power(Mag12,2) + RzRbar3*(2.3005341946092447*Power(Mag12,2) + RzRbar3*(4.6010683892184894*Power(Mag12,2) + RzRbar3*(4.9297161313055244*Power(Mag12,2) + RzRbar3*(3.2864774208703496*Power(Mag12,2) + RzRbar3*(1.36936559202931233*Power(Mag12,2) + RzRbar3*(0.32864774208703496*Power(Mag12,2) + 0.0348565787062006775*Power(Mag12,2)*RzRbar3)))))))))))/Power(Mag30,10);
  }
  
  double D_7_neg5_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0244140625*Mag12 + RzRbar3*(-0.1181640625*Mag12 + RzRbar3*(-0.0537109375*Mag12 + RzRbar3*(0.8056640625*Mag12 + RzRbar3*(2.255859375*Mag12 + RzRbar3*(2.255859375*Mag12 + RzRbar3*(-0.451171875*Mag12 + RzRbar3*(-3.544921875*Mag12 + RzRbar3*(-4.0283203125*Mag12 + RzRbar3*(-2.3095703125*Mag12 + RzRbar3*(-0.6982421875*Mag12 - 0.0888671875*Mag12*RzRbar3)))))))))))/Power(Mag30,9);
  }
  
  double D_7_neg4_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.015625 + RzRbar3*(0.021484375 + RzRbar3*(0.4296875 + RzRbar3*(0.966796875 + RzRbar3*(0.e-15 + RzRbar3*(-2.70703125 + RzRbar3*(-3.609375 + RzRbar3*(-0.64453125 + RzRbar3*(2.578125 + RzRbar3*(2.685546875 + (1.1171875 + 0.177734375*RzRbar3)*RzRbar3))))))))))/Power(Mag30,8);
  }
  
  double D_7_neg3_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0032388913968314452 + RzRbar3*(0.12631676447642636 + RzRbar3*(0.3076946826989873 + RzRbar3*(-0.4372503385722451 + RzRbar3*(-2.04050158000381 + RzRbar3*(-1.224300948002286 + RzRbar3*(2.584635334671493 + RzRbar3*(3.789502934292791 + RzRbar3*(0.534417080477188 + RzRbar3*(-1.9595292950830243 + (-1.38948440924068998 - 0.29473911711166151*RzRbar3)*RzRbar3))))))))))/(Mag12*Power(Mag30,7));
  }
  
  double D_7_neg2_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.018321936561810272 + RzRbar3*(0.08702919866859879 + RzRbar3*(-0.2290242070226284 + RzRbar3*(-1.0306089316018278 + RzRbar3*(0.e-15 + RzRbar3*(2.885705008485118 + RzRbar3*(1.923803338990079 + RzRbar3*(-2.610875960057964 + RzRbar3*(-3.023119532698695 + RzRbar3*(0.2519266277248912 + (1.31001846416943443 + 0.416824056781183681*RzRbar3)*RzRbar3))))))))))/(Power(Mag12,2)*Power(Mag30,6));
  }
  
  double D_7_neg1_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.016829773378529381 + RzRbar3*(-0.05048932013558814 + RzRbar3*(-0.4207443344632345 + RzRbar3*(0.1402481114877448 + RzRbar3*(1.963473560828428 + RzRbar3*(0.392694712165686 + RzRbar3*(-3.53425240949117 + RzRbar3*(-1.514679604067644 + RzRbar3*(2.776912607457348 + RzRbar3*(1.5427292263651932 + (-0.80221919770990049 - 0.51050312581539122*RzRbar3)*RzRbar3))))))))))/(Power(Mag12,3)*Power(Mag30,5));
  }
  
  double D_7_0_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-0.12594249175901178 + Power(RzRbar3,2)*(1.0495207646584315 + Power(RzRbar3,2)*(-2.9386581410436082 + Power(RzRbar3,2)*(3.7782747527703534 + Power(RzRbar3,2)*(-2.30894568224854929 + 0.54575079762238438*Power(RzRbar3,2)))))))/(Power(Mag12,4)*Power(Mag30,4));
  }
  
  double D_7_1_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.016829773378529381 + RzRbar3*(-0.05048932013558814 + RzRbar3*(0.4207443344632345 + RzRbar3*(0.1402481114877448 + RzRbar3*(-1.963473560828428 + RzRbar3*(0.392694712165686 + RzRbar3*(3.53425240949117 + RzRbar3*(-1.514679604067644 + RzRbar3*(-2.776912607457348 + RzRbar3*(1.5427292263651932 + (0.80221919770990049 - 0.51050312581539122*RzRbar3)*RzRbar3))))))))))/(Power(Mag12,5)*Power(Mag30,3));
  }
  
  double D_7_2_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.018321936561810272 + RzRbar3*(0.08702919866859879 + RzRbar3*(0.2290242070226284 + RzRbar3*(-1.0306089316018278 + RzRbar3*(0.e-15 + RzRbar3*(2.885705008485118 + RzRbar3*(-1.923803338990079 + RzRbar3*(-2.610875960057964 + RzRbar3*(3.023119532698695 + RzRbar3*(0.2519266277248912 + (-1.31001846416943443 + 0.416824056781183681*RzRbar3)*RzRbar3))))))))))/(Power(Mag12,6)*Power(Mag30,2));
  }
  
  double D_7_3_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0032388913968314452 + RzRbar3*(0.12631676447642636 + RzRbar3*(-0.3076946826989873 + RzRbar3*(-0.4372503385722451 + RzRbar3*(2.04050158000381 + RzRbar3*(-1.224300948002286 + RzRbar3*(-2.584635334671493 + RzRbar3*(3.789502934292791 + RzRbar3*(-0.534417080477188 + RzRbar3*(-1.9595292950830243 + (1.38948440924068998 - 0.29473911711166151*RzRbar3)*RzRbar3))))))))))/(Power(Mag12,7)*Mag30);
  }
  
  double D_7_4_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.015625 + RzRbar3*(0.021484375 + RzRbar3*(-0.4296875 + RzRbar3*(0.966796875 + RzRbar3*(0.e-15 + RzRbar3*(-2.70703125 + RzRbar3*(3.609375 + RzRbar3*(-0.64453125 + RzRbar3*(-2.578125 + RzRbar3*(2.685546875 + (-1.1171875 + 0.177734375*RzRbar3)*RzRbar3))))))))))/Power(Mag12,8);
  }
  
  double D_7_5_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0244140625*Mag30 + RzRbar3*(-0.1181640625*Mag30 + RzRbar3*(0.0537109375*Mag30 + RzRbar3*(0.8056640625*Mag30 + RzRbar3*(-2.255859375*Mag30 + RzRbar3*(2.255859375*Mag30 + RzRbar3*(0.451171875*Mag30 + RzRbar3*(-3.544921875*Mag30 + RzRbar3*(4.0283203125*Mag30 + RzRbar3*(-2.3095703125*Mag30 + RzRbar3*(0.6982421875*Mag30 - 0.0888671875*Mag30*RzRbar3)))))))))))/Power(Mag12,9);
  }
  
  double D_7_6_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.019918044974971816*Power(Mag30,2) + RzRbar3*(-0.16432387104351748*Power(Mag30,2) + RzRbar3*(0.5477462368117249*Power(Mag30,2) + RzRbar3*(-0.8216193552175874*Power(Mag30,2) + RzRbar3*(0.e-16*Power(Mag30,2) + RzRbar3*(2.3005341946092447*Power(Mag30,2) + RzRbar3*(-4.6010683892184894*Power(Mag30,2) + RzRbar3*(4.9297161313055244*Power(Mag30,2) + RzRbar3*(-3.2864774208703496*Power(Mag30,2) + RzRbar3*(1.36936559202931233*Power(Mag30,2) + RzRbar3*(-0.32864774208703496*Power(Mag30,2) + 0.0348565787062006775*Power(Mag30,2)*RzRbar3)))))))))))/Power(Mag12,10);
  }
  
  double D_7_7_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00931581251383736*Power(Mag30,3) + RzRbar3*(-0.10247393765221096*Power(Mag30,3) + RzRbar3*(0.51236968826105479*Power(Mag30,3) + RzRbar3*(-1.5371090647831644*Power(Mag30,3) + RzRbar3*(3.0742181295663288*Power(Mag30,3) + RzRbar3*(-4.3039053813928603*Power(Mag30,3) + RzRbar3*(4.3039053813928603*Power(Mag30,3) + RzRbar3*(-3.0742181295663288*Power(Mag30,3) + RzRbar3*(1.53710906478316438*Power(Mag30,3) + RzRbar3*(-0.51236968826105479*Power(Mag30,3) + RzRbar3*(0.102473937652210958*Power(Mag30,3) - 0.00931581251383735986*Power(Mag30,3)*RzRbar3)))))))))))/Power(Mag12,11);
  }
  
  double D_7_neg7_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.030897054725696044*Power(Mag12,4) + RzRbar3*(0.30897054725696044*Power(Mag12,4) + RzRbar3*(1.390367462656322*Power(Mag12,4) + RzRbar3*(3.7076465670835253*Power(Mag12,4) + RzRbar3*(6.4883814923961693*Power(Mag12,4) + RzRbar3*(7.7860577908754031*Power(Mag12,4) + RzRbar3*(6.4883814923961693*Power(Mag12,4) + RzRbar3*(3.7076465670835253*Power(Mag12,4) + RzRbar3*(1.39036746265632198*Power(Mag12,4) + RzRbar3*(0.308970547256960441*Power(Mag12,4) + 0.0308970547256960441*Power(Mag12,4)*RzRbar3))))))))))/Power(Mag30,10);
  }
  
  double D_7_neg6_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.049545511304553993*Power(Mag12,3) + RzRbar3*(0.33030340869702662*Power(Mag12,3) + RzRbar3*(0.7431826695683099*Power(Mag12,3) + RzRbar3*(0.e-16*Power(Mag12,3) + RzRbar3*(-3.46818579131878*Power(Mag12,3) + RzRbar3*(-8.323645899165071*Power(Mag12,3) + RzRbar3*(-10.404557373956339*Power(Mag12,3) + RzRbar3*(-7.9272818087286389*Power(Mag12,3) + RzRbar3*(-3.7159133478415495*Power(Mag12,3) + RzRbar3*(-0.99091022609107986*Power(Mag12,3) - 0.115606193043959317*Power(Mag12,3)*RzRbar3))))))))))/Power(Mag30,9);
  }
  
  double D_7_neg5_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.035627805365145897*Power(Mag12,2) + RzRbar3*(0.03238891396831445*Power(Mag12,2) + RzRbar3*(-0.7287505642870752*Power(Mag12,2) + RzRbar3*(-2.7206687733384139*Power(Mag12,2) + RzRbar3*(-3.400835966673017*Power(Mag12,2) + RzRbar3*(0.816200632001524*Power(Mag12,2) + RzRbar3*(7.481839126680638*Power(Mag12,2) + RzRbar3*(9.716674190494335*Power(Mag12,2) + RzRbar3*(6.2672548528688464*Power(Mag12,2) + RzRbar3*(2.10527940794043936*Power(Mag12,2) + 0.29473911711166151*Power(Mag12,2)*RzRbar3))))))))))/Power(Mag30,8);
  }
  
  double D_7_neg4_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0064777827936628903*Mag12 + RzRbar3*(-0.25911131174651561*Mag12 + RzRbar3*(-0.8745006771444902*Mag12 + RzRbar3*(0.e-16*Mag12 + RzRbar3*(4.081003160007621*Mag12 + RzRbar3*(6.529605056012193*Mag12 + RzRbar3*(1.360334386669207*Mag12 + RzRbar3*(-6.218671481916375*Mag12 + RzRbar3*(-7.2875056428707516*Mag12 + RzRbar3*(-3.368447052704703*Mag12 - 0.58947823422332302*Mag12*RzRbar3))))))))))/Power(Mag30,7);
  }
  
  double D_7_neg3_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0380859375 + RzRbar3*(-0.185546875 + RzRbar3*(0.3955078125 + RzRbar3*(2.4609375 + RzRbar3*(1.845703125 + RzRbar3*(-4.67578125 + RzRbar3*(-7.998046875 + RzRbar3*(-1.2890625 + RzRbar3*(5.3173828125 + (4.189453125 + 0.9775390625*RzRbar3)*RzRbar3)))))))))/Power(Mag30,6);
  }
  
  double D_7_neg2_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.026240290708094537 + RzRbar3*(0.13810679320049756 + RzRbar3*(0.9322208541033586 + RzRbar3*(0.e-16 + RzRbar3*(-4.3503639858156732 + RzRbar3*(-3.480291188652539 + RzRbar3*(5.510461048699853 + RzRbar3*(7.292038680986271 + RzRbar3*(-0.683628626342463 + (-3.9498542855342303 - 1.38244899993698061*RzRbar3)*RzRbar3)))))))))/(Mag12*Power(Mag30,5));
  }
  
  double D_7_neg1_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.015223102800898336 + RzRbar3*(0.25371838001497226 + RzRbar3*(-0.1268591900074861 + RzRbar3*(-2.3680382134730744 + RzRbar3*(-0.592009553368269 + RzRbar3*(6.393703176377301 + RzRbar3*(3.19685158818865 + RzRbar3*(-6.698165232395268 + RzRbar3*(-4.1863532702470423 + RzRbar3*(2.4187818894760689 + 1.69314732263324821*RzRbar3))))))))))/(Power(Mag12,2)*Power(Mag30,4));
  }
  
  double D_7_0_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.037973090029733556 + Power(RzRbar3,2)*(-0.9493272507433389 + Power(RzRbar3,2)*(4.4301938368022482 + Power(RzRbar3,2)*(-7.9743489062440468 + Power(RzRbar3,2)*(6.2655598549060367 - 1.81005062475063284*Power(RzRbar3,2))))))/(Power(Mag12,3)*Power(Mag30,3));
  }
  
  double D_7_1_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.015223102800898336 + RzRbar3*(-0.25371838001497226 + RzRbar3*(-0.1268591900074861 + RzRbar3*(2.3680382134730744 + RzRbar3*(-0.592009553368269 + RzRbar3*(-6.393703176377301 + RzRbar3*(3.19685158818865 + RzRbar3*(6.698165232395268 + RzRbar3*(-4.1863532702470423 + RzRbar3*(-2.4187818894760689 + 1.69314732263324821*RzRbar3))))))))))/(Power(Mag12,4)*Power(Mag30,2));
  }
  
  double D_7_2_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.026240290708094537 + RzRbar3*(-0.13810679320049756 + RzRbar3*(0.9322208541033586 + RzRbar3*(0.e-16 + RzRbar3*(-4.3503639858156732 + RzRbar3*(3.480291188652539 + RzRbar3*(5.510461048699853 + RzRbar3*(-7.292038680986271 + RzRbar3*(-0.683628626342463 + (3.9498542855342303 - 1.38244899993698061*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,5)*Mag30);
  }
  
  double D_7_3_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0380859375 + RzRbar3*(0.185546875 + RzRbar3*(0.3955078125 + RzRbar3*(-2.4609375 + RzRbar3*(1.845703125 + RzRbar3*(4.67578125 + RzRbar3*(-7.998046875 + RzRbar3*(1.2890625 + RzRbar3*(5.3173828125 + (-4.189453125 + 0.9775390625*RzRbar3)*RzRbar3)))))))))/Power(Mag12,6);
  }
  
  double D_7_4_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0064777827936628903*Mag30 + RzRbar3*(0.25911131174651561*Mag30 + RzRbar3*(-0.8745006771444902*Mag30 + RzRbar3*(0.e-16*Mag30 + RzRbar3*(4.081003160007621*Mag30 + RzRbar3*(-6.529605056012193*Mag30 + RzRbar3*(1.360334386669207*Mag30 + RzRbar3*(6.218671481916375*Mag30 + RzRbar3*(-7.2875056428707516*Mag30 + RzRbar3*(3.368447052704703*Mag30 - 0.58947823422332302*Mag30*RzRbar3))))))))))/Power(Mag12,7);
  }
  
  double D_7_5_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.035627805365145897*Power(Mag30,2) + RzRbar3*(-0.03238891396831445*Power(Mag30,2) + RzRbar3*(-0.7287505642870752*Power(Mag30,2) + RzRbar3*(2.7206687733384139*Power(Mag30,2) + RzRbar3*(-3.400835966673017*Power(Mag30,2) + RzRbar3*(-0.816200632001524*Power(Mag30,2) + RzRbar3*(7.481839126680638*Power(Mag30,2) + RzRbar3*(-9.716674190494335*Power(Mag30,2) + RzRbar3*(6.2672548528688464*Power(Mag30,2) + RzRbar3*(-2.10527940794043936*Power(Mag30,2) + 0.29473911711166151*Power(Mag30,2)*RzRbar3))))))))))/Power(Mag12,8);
  }
  
  double D_7_6_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.049545511304553993*Power(Mag30,3) + RzRbar3*(-0.33030340869702662*Power(Mag30,3) + RzRbar3*(0.7431826695683099*Power(Mag30,3) + RzRbar3*(0.e-16*Power(Mag30,3) + RzRbar3*(-3.46818579131878*Power(Mag30,3) + RzRbar3*(8.323645899165071*Power(Mag30,3) + RzRbar3*(-10.404557373956339*Power(Mag30,3) + RzRbar3*(7.9272818087286389*Power(Mag30,3) + RzRbar3*(-3.7159133478415495*Power(Mag30,3) + RzRbar3*(0.99091022609107986*Power(Mag30,3) - 0.115606193043959317*Power(Mag30,3)*RzRbar3))))))))))/Power(Mag12,9);
  }
  
  double D_7_7_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.030897054725696044*Power(Mag30,4) + RzRbar3*(-0.30897054725696044*Power(Mag30,4) + RzRbar3*(1.390367462656322*Power(Mag30,4) + RzRbar3*(-3.7076465670835253*Power(Mag30,4) + RzRbar3*(6.4883814923961693*Power(Mag30,4) + RzRbar3*(-7.7860577908754031*Power(Mag30,4) + RzRbar3*(6.4883814923961693*Power(Mag30,4) + RzRbar3*(-3.7076465670835253*Power(Mag30,4) + RzRbar3*(1.39036746265632198*Power(Mag30,4) + RzRbar3*(-0.308970547256960441*Power(Mag30,4) + 0.0308970547256960441*Power(Mag30,4)*RzRbar3))))))))))/Power(Mag12,10);
  }
  
  double D_7_neg7_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.087390067660926147*Power(Mag12,5) + RzRbar3*(-0.78651060894833532*Power(Mag12,5) + RzRbar3*(-3.1460424357933413*Power(Mag12,5) + RzRbar3*(-7.3407656835177964*Power(Mag12,5) + RzRbar3*(-11.0111485252766945*Power(Mag12,5) + RzRbar3*(-11.0111485252766945*Power(Mag12,5) + RzRbar3*(-7.3407656835177964*Power(Mag12,5) + RzRbar3*(-3.1460424357933413*Power(Mag12,5) + RzRbar3*(-0.78651060894833532*Power(Mag12,5) - 0.0873900676609261472*Power(Mag12,5)*RzRbar3)))))))))/Power(Mag30,9);
  }
  
  double D_7_neg6_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.093423912055479672*Power(Mag12,4) + RzRbar3*(-0.42040760424965852*Power(Mag12,4) + RzRbar3*(0.e-16*Power(Mag12,4) + RzRbar3*(3.923804306330146*Power(Mag12,4) + RzRbar3*(11.771412918990439*Power(Mag12,4) + RzRbar3*(17.657119378485658*Power(Mag12,4) + RzRbar3*(15.695217225320585*Power(Mag12,4) + RzRbar3*(8.4081520849931705*Power(Mag12,4) + RzRbar3*(2.52244562549795115*Power(Mag12,4) + 0.326983692194178852*Power(Mag12,4)*RzRbar3)))))))))/Power(Mag30,8);
  }
  
  double D_7_neg5_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0091609682809051358*Power(Mag12,3) + RzRbar3*(0.41224357264073111*Power(Mag12,3) + RzRbar3*(2.3085640067880942*Power(Mag12,3) + RzRbar3*(3.847606677980157*Power(Mag12,3) + RzRbar3*(-1.154282003394047*Power(Mag12,3) + RzRbar3*(-12.697102037334518*Power(Mag12,3) + RzRbar3*(-19.238033389900785*Power(Mag12,3) + RzRbar3*(-14.1811788988411503*Power(Mag12,3) + RzRbar3*(-5.3591664443295045*Power(Mag12,3) - 0.83364811356236736*Power(Mag12,3)*RzRbar3)))))))))/Power(Mag30,7);
  }
  
  double D_7_neg4_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.073287746247241087*Power(Mag12,2) + RzRbar3*(0.49469228716887734*Power(Mag12,2) + RzRbar3*(0.e-16*Power(Mag12,2) + RzRbar3*(-4.6171280135761885*Power(Mag12,2) + RzRbar3*(-9.234256027152377*Power(Mag12,2) + RzRbar3*(-2.308564006788094*Power(Mag12,2) + RzRbar3*(12.312341369536503*Power(Mag12,2) + RzRbar3*(16.489742905629245*Power(Mag12,2) + RzRbar3*(8.5746663109272072*Power(Mag12,2) + 1.66729622712473472*Power(Mag12,2)*RzRbar3)))))))))/Power(Mag30,6);
  }
  
  double D_7_neg3_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.052480581416189074*Mag12 + RzRbar3*(-0.22373300498480605*Mag12 + RzRbar3*(-2.0881747131915232*Mag12 + RzRbar3*(-2.0881747131915232*Mag12 + RzRbar3*(6.612553258439823*Mag12 + RzRbar3*(13.573135635744901*Mag12 + RzRbar3*(2.552213538345195*Mag12 + RzRbar3*(-12.031863823627348*Mag12 + RzRbar3*(-10.6646065709424218*Mag12 - 2.76489799987396122*Mag12*RzRbar3)))))))))/Power(Mag30,5);
  }
  
  double D_7_neg2_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0390625 + RzRbar3*(-0.52734375 + RzRbar3*(0.e-16 + RzRbar3*(4.921875 + RzRbar3*(4.921875 + RzRbar3*(-9.3515625 + RzRbar3*(-14.4375 + RzRbar3*(1.546875 + RzRbar3*(10.0546875 + 3.91015625*RzRbar3)))))))))/Power(Mag30,4);
  }
  
  double D_7_neg1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.071762394808100921 + RzRbar3*(0.07176239480810092 + RzRbar3*(2.0093470546268258 + RzRbar3*(0.6697823515422753 + RzRbar3*(-9.042061745820716 + RzRbar3*(-5.4252370474924296 + RzRbar3*(13.26169056053705 + RzRbar3*(9.472636114669322 + (-6.157213474535059 - 4.78894381352726812*RzRbar3)*RzRbar3))))))))/(Mag12*Power(Mag30,3));
  }
  
  double D_7_0_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(0.5370205892526375 + Power(RzRbar3,2)*(-5.01219216635795 + Power(RzRbar3,2)*(13.532918849166465 + Power(RzRbar3,2)*(-14.17734355626963 + 5.1195962842084775*Power(RzRbar3,2))))))/(Power(Mag12,2)*Power(Mag30,2));
  }
  
  double D_7_1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.071762394808100921 + RzRbar3*(0.07176239480810092 + RzRbar3*(-2.0093470546268258 + RzRbar3*(0.6697823515422753 + RzRbar3*(9.042061745820716 + RzRbar3*(-5.4252370474924296 + RzRbar3*(-13.26169056053705 + RzRbar3*(9.472636114669322 + (6.157213474535059 - 4.78894381352726812*RzRbar3)*RzRbar3))))))))/(Power(Mag12,3)*Mag30);
  }
  
  double D_7_2_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0390625 + RzRbar3*(-0.52734375 + RzRbar3*(0.e-16 + RzRbar3*(4.921875 + RzRbar3*(-4.921875 + RzRbar3*(-9.3515625 + RzRbar3*(14.4375 + RzRbar3*(1.546875 + RzRbar3*(-10.0546875 + 3.91015625*RzRbar3)))))))))/Power(Mag12,4);
  }
  
  double D_7_3_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.052480581416189074*Mag30 + RzRbar3*(-0.22373300498480605*Mag30 + RzRbar3*(2.0881747131915232*Mag30 + RzRbar3*(-2.0881747131915232*Mag30 + RzRbar3*(-6.612553258439823*Mag30 + RzRbar3*(13.573135635744901*Mag30 + RzRbar3*(-2.552213538345195*Mag30 + RzRbar3*(-12.031863823627348*Mag30 + RzRbar3*(10.6646065709424218*Mag30 - 2.76489799987396122*Mag30*RzRbar3)))))))))/Power(Mag12,5);
  }
  
  double D_7_4_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.073287746247241087*Power(Mag30,2) + RzRbar3*(0.49469228716887734*Power(Mag30,2) + RzRbar3*(0.e-16*Power(Mag30,2) + RzRbar3*(-4.6171280135761885*Power(Mag30,2) + RzRbar3*(9.234256027152377*Power(Mag30,2) + RzRbar3*(-2.308564006788094*Power(Mag30,2) + RzRbar3*(-12.312341369536503*Power(Mag30,2) + RzRbar3*(16.489742905629245*Power(Mag30,2) + RzRbar3*(-8.5746663109272072*Power(Mag30,2) + 1.66729622712473472*Power(Mag30,2)*RzRbar3)))))))))/Power(Mag12,6);
  }
  
  double D_7_5_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0091609682809051358*Power(Mag30,3) + RzRbar3*(0.41224357264073111*Power(Mag30,3) + RzRbar3*(-2.3085640067880942*Power(Mag30,3) + RzRbar3*(3.847606677980157*Power(Mag30,3) + RzRbar3*(1.154282003394047*Power(Mag30,3) + RzRbar3*(-12.697102037334518*Power(Mag30,3) + RzRbar3*(19.238033389900785*Power(Mag30,3) + RzRbar3*(-14.1811788988411503*Power(Mag30,3) + RzRbar3*(5.3591664443295045*Power(Mag30,3) - 0.83364811356236736*Power(Mag30,3)*RzRbar3)))))))))/Power(Mag12,7);
  }
  
  double D_7_6_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.093423912055479672*Power(Mag30,4) + RzRbar3*(-0.42040760424965852*Power(Mag30,4) + RzRbar3*(0.e-16*Power(Mag30,4) + RzRbar3*(3.923804306330146*Power(Mag30,4) + RzRbar3*(-11.771412918990439*Power(Mag30,4) + RzRbar3*(17.657119378485658*Power(Mag30,4) + RzRbar3*(-15.695217225320585*Power(Mag30,4) + RzRbar3*(8.4081520849931705*Power(Mag30,4) + RzRbar3*(-2.52244562549795115*Power(Mag30,4) + 0.326983692194178852*Power(Mag30,4)*RzRbar3)))))))))/Power(Mag12,8);
  }
  
  double D_7_7_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.087390067660926147*Power(Mag30,5) + RzRbar3*(-0.78651060894833532*Power(Mag30,5) + RzRbar3*(3.1460424357933413*Power(Mag30,5) + RzRbar3*(-7.3407656835177964*Power(Mag30,5) + RzRbar3*(11.0111485252766945*Power(Mag30,5) + RzRbar3*(-11.0111485252766945*Power(Mag30,5) + RzRbar3*(7.3407656835177964*Power(Mag30,5) + RzRbar3*(-3.1460424357933413*Power(Mag30,5) + RzRbar3*(0.78651060894833532*Power(Mag30,5) - 0.0873900676609261472*Power(Mag30,5)*RzRbar3)))))))))/Power(Mag12,9);
  }
  
  double D_7_neg7_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.21406107435656652*Power(Mag12,6) + RzRbar3*(1.7124885948525321*Power(Mag12,6) + RzRbar3*(5.9937100819838625*Power(Mag12,6) + RzRbar3*(11.987420163967725*Power(Mag12,6) + RzRbar3*(14.9842752049596563*Power(Mag12,6) + RzRbar3*(11.987420163967725*Power(Mag12,6) + RzRbar3*(5.9937100819838625*Power(Mag12,6) + RzRbar3*(1.71248859485253215*Power(Mag12,6) + 0.214061074356566519*Power(Mag12,6)*RzRbar3))))))))/Power(Mag30,8);
  }
  
  double D_7_neg6_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.11442045715528758*Power(Mag12,5) + RzRbar3*(0.e-16*Power(Mag12,5) + RzRbar3*(-3.2037728003480521*Power(Mag12,5) + RzRbar3*(-12.815091201392209*Power(Mag12,5) + RzRbar3*(-24.028296002610391*Power(Mag12,5) + RzRbar3*(-25.630182402784417*Power(Mag12,5) + RzRbar3*(-16.0188640017402607*Power(Mag12,5) + RzRbar3*(-5.4921819434538037*Power(Mag12,5) - 0.80094320008701304*Power(Mag12,5)*RzRbar3))))))))/Power(Mag30,7);
  }
  
  double D_7_neg5_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.112198489190195872*Power(Mag12,4) + RzRbar3*(-1.25662307893019377*Power(Mag12,4) + RzRbar3*(-3.1415576973254844*Power(Mag12,4) + RzRbar3*(1.256623078930194*Power(Mag12,4) + RzRbar3*(17.278567335290164*Power(Mag12,4) + RzRbar3*(31.415576973254844*Power(Mag12,4) + RzRbar3*(27.017396196999166*Power(Mag12,4) + RzRbar3*(11.6686428757803707*Power(Mag12,4) + 2.04201250326156488*Power(Mag12,4)*RzRbar3))))))))/Power(Mag30,6);
  }
  
  double D_7_neg4_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.134638187028235047*Power(Mag12,3) + RzRbar3*(0.e-17*Power(Mag12,3) + RzRbar3*(3.7698692367905813*Power(Mag12,3) + RzRbar3*(10.05298463144155*Power(Mag12,3) + RzRbar3*(3.141557697325484*Power(Mag12,3) + RzRbar3*(-20.1059692628831*Power(Mag12,3) + RzRbar3*(-31.415576973254844*Power(Mag12,3) + RzRbar3*(-18.6698286012485931*Power(Mag12,3) - 4.08402500652312975*Power(Mag12,3)*RzRbar3))))))))/Power(Mag30,5);
  }
  
  double D_7_neg3_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.060892411203593342*Power(Mag12,2) + RzRbar3*(1.13665834246707572*Power(Mag12,2) + RzRbar3*(1.7049875137006136*Power(Mag12,2) + RzRbar3*(-7.1988361689581463*Power(Mag12,2) + RzRbar3*(-18.470698065089981*Power(Mag12,2) + RzRbar3*(-4.167747255712611*Power(Mag12,2) + RzRbar3*(22.92260990641936*Power(Mag12,2) + RzRbar3*(23.2203061389702612*Power(Mag12,2) + 6.7725892905329929*Power(Mag12,2)*RzRbar3))))))))/Power(Mag30,4);
  }
  
  double D_7_neg2_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.143524789616201842*Mag12 + RzRbar3*(0.e-17*Mag12 + RzRbar3*(-4.0186941092536516*Mag12 + RzRbar3*(-5.3582588123382021*Mag12 + RzRbar3*(12.72586467930323*Mag12 + RzRbar3*(23.576338774288089*Mag12 + RzRbar3*(-2.947042346786011*Mag12 + RzRbar3*(-21.8923145761246543*Mag12 - 9.5778876270545362*Mag12*RzRbar3))))))))/Power(Mag30,3);
  }
  
  double D_7_neg1_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.01953125 + RzRbar3*(-1.09375 + RzRbar3*(-0.546875 + RzRbar3*(9.84375 + RzRbar3*(7.3828125 + RzRbar3*(-21.65625 + RzRbar3*(-18.046875 + RzRbar3*(13.40625 + 11.73046875*RzRbar3))))))))/Power(Mag30,2);
  }
  
  double D_7_0_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.146158491670857085 + Power(RzRbar3,2)*(4.09243776678399839 + Power(RzRbar3,2)*(-18.4159699505279928 + Power(RzRbar3,2)*(27.0100892607743894 - 12.5403985853595379*Power(RzRbar3,2)))))/(Mag12*Mag30);
  }
  
  double D_7_1_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.01953125 + RzRbar3*(1.09375 + RzRbar3*(-0.546875 + RzRbar3*(-9.84375 + RzRbar3*(7.3828125 + RzRbar3*(21.65625 + RzRbar3*(-18.046875 + RzRbar3*(-13.40625 + 11.73046875*RzRbar3))))))))/Power(Mag12,2);
  }
  
  double D_7_2_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.143524789616201842*Mag30 + RzRbar3*(0.e-17*Mag30 + RzRbar3*(-4.0186941092536516*Mag30 + RzRbar3*(5.3582588123382021*Mag30 + RzRbar3*(12.72586467930323*Mag30 + RzRbar3*(-23.576338774288089*Mag30 + RzRbar3*(-2.947042346786011*Mag30 + RzRbar3*(21.8923145761246543*Mag30 - 9.5778876270545362*Mag30*RzRbar3))))))))/Power(Mag12,3);
  }
  
  double D_7_3_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.060892411203593342*Power(Mag30,2) + RzRbar3*(-1.13665834246707572*Power(Mag30,2) + RzRbar3*(1.7049875137006136*Power(Mag30,2) + RzRbar3*(7.1988361689581463*Power(Mag30,2) + RzRbar3*(-18.470698065089981*Power(Mag30,2) + RzRbar3*(4.167747255712611*Power(Mag30,2) + RzRbar3*(22.92260990641936*Power(Mag30,2) + RzRbar3*(-23.2203061389702612*Power(Mag30,2) + 6.7725892905329929*Power(Mag30,2)*RzRbar3))))))))/Power(Mag12,4);
  }
  
  double D_7_4_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.134638187028235047*Power(Mag30,3) + RzRbar3*(0.e-17*Power(Mag30,3) + RzRbar3*(3.7698692367905813*Power(Mag30,3) + RzRbar3*(-10.05298463144155*Power(Mag30,3) + RzRbar3*(3.141557697325484*Power(Mag30,3) + RzRbar3*(20.1059692628831*Power(Mag30,3) + RzRbar3*(-31.415576973254844*Power(Mag30,3) + RzRbar3*(18.6698286012485931*Power(Mag30,3) - 4.08402500652312975*Power(Mag30,3)*RzRbar3))))))))/Power(Mag12,5);
  }
  
  double D_7_5_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.112198489190195872*Power(Mag30,4) + RzRbar3*(1.25662307893019377*Power(Mag30,4) + RzRbar3*(-3.1415576973254844*Power(Mag30,4) + RzRbar3*(-1.256623078930194*Power(Mag30,4) + RzRbar3*(17.278567335290164*Power(Mag30,4) + RzRbar3*(-31.415576973254844*Power(Mag30,4) + RzRbar3*(27.017396196999166*Power(Mag30,4) + RzRbar3*(-11.6686428757803707*Power(Mag30,4) + 2.04201250326156488*Power(Mag30,4)*RzRbar3))))))))/Power(Mag12,6);
  }
  
  double D_7_6_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.11442045715528758*Power(Mag30,5) + RzRbar3*(0.e-16*Power(Mag30,5) + RzRbar3*(-3.2037728003480521*Power(Mag30,5) + RzRbar3*(12.815091201392209*Power(Mag30,5) + RzRbar3*(-24.028296002610391*Power(Mag30,5) + RzRbar3*(25.630182402784417*Power(Mag30,5) + RzRbar3*(-16.0188640017402607*Power(Mag30,5) + RzRbar3*(5.4921819434538037*Power(Mag30,5) - 0.80094320008701304*Power(Mag30,5)*RzRbar3))))))))/Power(Mag12,7);
  }
  
  double D_7_7_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.21406107435656652*Power(Mag30,6) + RzRbar3*(-1.7124885948525321*Power(Mag30,6) + RzRbar3*(5.9937100819838625*Power(Mag30,6) + RzRbar3*(-11.987420163967725*Power(Mag30,6) + RzRbar3*(14.9842752049596563*Power(Mag30,6) + RzRbar3*(-11.987420163967725*Power(Mag30,6) + RzRbar3*(5.9937100819838625*Power(Mag30,6) + RzRbar3*(-1.71248859485253215*Power(Mag30,6) + 0.214061074356566519*Power(Mag30,6)*RzRbar3))))))))/Power(Mag12,8);
  }
  
  double D_7_neg7_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.45768182862115031*Power(Mag12,7) + RzRbar3*(-3.2037728003480521*Power(Mag12,7) + RzRbar3*(-9.6113184010441564*Power(Mag12,7) + RzRbar3*(-16.0188640017402607*Power(Mag12,7) + RzRbar3*(-16.0188640017402607*Power(Mag12,7) + RzRbar3*(-9.6113184010441564*Power(Mag12,7) + RzRbar3*(-3.20377280034805215*Power(Mag12,7) - 0.457681828621150307*Power(Mag12,7)*RzRbar3)))))))/Power(Mag30,7);
  }
  
  double D_7_neg6_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(1.7124885948525321*Power(Mag12,6) + RzRbar3*(10.2749315691151929*Power(Mag12,6) + RzRbar3*(25.687328922787982*Power(Mag12,6) + RzRbar3*(34.249771897050643*Power(Mag12,6) + RzRbar3*(25.6873289227879822*Power(Mag12,6) + RzRbar3*(10.2749315691151929*Power(Mag12,6) + 1.71248859485253215*Power(Mag12,6)*RzRbar3)))))))/Power(Mag30,6);
  }
  
  double D_7_neg5_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.33584664469069808*Power(Mag12,5) + RzRbar3*(1.6792332234534904*Power(Mag12,5) + RzRbar3*(-1.0075399340720942*Power(Mag12,5) + RzRbar3*(-18.471565457988394*Power(Mag12,5) + RzRbar3*(-41.98083058633726*Power(Mag12,5) + RzRbar3*(-43.324217165100052*Power(Mag12,5) + RzRbar3*(-21.8300319048953751*Power(Mag12,5) - 4.36600638097907502*Power(Mag12,5)*RzRbar3)))))))/Power(Mag30,5);
  }
  
  double D_7_neg4_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-2.0150798681441885*Power(Mag12,4) + RzRbar3*(-8.0603194725767539*Power(Mag12,4) + RzRbar3*(-3.358466446906981*Power(Mag12,4) + RzRbar3*(26.867731575255846*Power(Mag12,4) + RzRbar3*(50.376996703604712*Power(Mag12,4) + RzRbar3*(34.9280510478326*Power(Mag12,4) + 8.73201276195815*Power(Mag12,4)*RzRbar3)))))))/Power(Mag30,4);
  }
  
  double D_7_neg3_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.30378472023786845*Power(Mag12,3) + RzRbar3*(-0.91135416071360534*Power(Mag12,3) + RzRbar3*(5.7719096845195005*Power(Mag12,3) + RzRbar3*(19.7460068154614491*Power(Mag12,3) + RzRbar3*(5.569386537694255*Power(Mag12,3) + RzRbar3*(-36.757951148782082*Power(Mag12,3) + RzRbar3*(-43.441214994015188*Power(Mag12,3) - 14.4804049980050627*Power(Mag12,3)*RzRbar3)))))))/Power(Mag30,3);
  }
  
  double D_7_neg2_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(2.14808235701055*Power(Mag12,2) + RzRbar3*(4.2961647140211*Power(Mag12,2) + RzRbar3*(-13.60452159440015*Power(Mag12,2) + RzRbar3*(-31.5052079028214*Power(Mag12,2) + RzRbar3*(4.72578118542321*Power(Mag12,2) + RzRbar3*(40.95677027366782*Power(Mag12,2) + 20.47838513683391*Power(Mag12,2)*RzRbar3)))))))/Power(Mag30,2);
  }
  
  double D_7_neg1_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.292316983341714171*Mag12 + RzRbar3*(0.292316983341714171*Mag12 + RzRbar3*(-7.8925585502262826*Mag12 + RzRbar3*(-7.8925585502262826*Mag12 + RzRbar3*(28.9393813508297029*Mag12 + RzRbar3*(28.9393813508297029*Mag12 + RzRbar3*(-25.0807971707190759*Mag12 - 25.0807971707190759*Mag12*RzRbar3)))))))/Mag30;
  }
  
  double D_7_0_0() {
    return RzRbar3*(-2.1875 + Power(RzRbar3,2)*(19.6875 + Power(RzRbar3,2)*(-43.3125 + 26.8125*Power(RzRbar3,2))));
  }
  
  double D_7_1_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.292316983341714171*Mag30 + RzRbar3*(0.292316983341714171*Mag30 + RzRbar3*(7.8925585502262826*Mag30 + RzRbar3*(-7.8925585502262826*Mag30 + RzRbar3*(-28.9393813508297029*Mag30 + RzRbar3*(28.9393813508297029*Mag30 + RzRbar3*(25.0807971707190759*Mag30 - 25.0807971707190759*Mag30*RzRbar3)))))))/Mag12;
  }
  
  double D_7_2_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(2.14808235701055*Power(Mag30,2) + RzRbar3*(-4.2961647140211*Power(Mag30,2) + RzRbar3*(-13.60452159440015*Power(Mag30,2) + RzRbar3*(31.5052079028214*Power(Mag30,2) + RzRbar3*(4.72578118542321*Power(Mag30,2) + RzRbar3*(-40.95677027366782*Power(Mag30,2) + 20.47838513683391*Power(Mag30,2)*RzRbar3)))))))/Power(Mag12,2);
  }
  
  double D_7_3_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.30378472023786845*Power(Mag30,3) + RzRbar3*(-0.91135416071360534*Power(Mag30,3) + RzRbar3*(-5.7719096845195005*Power(Mag30,3) + RzRbar3*(19.7460068154614491*Power(Mag30,3) + RzRbar3*(-5.569386537694255*Power(Mag30,3) + RzRbar3*(-36.757951148782082*Power(Mag30,3) + RzRbar3*(43.441214994015188*Power(Mag30,3) - 14.4804049980050627*Power(Mag30,3)*RzRbar3)))))))/Power(Mag12,3);
  }
  
  double D_7_4_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-2.0150798681441885*Power(Mag30,4) + RzRbar3*(8.0603194725767539*Power(Mag30,4) + RzRbar3*(-3.358466446906981*Power(Mag30,4) + RzRbar3*(-26.867731575255846*Power(Mag30,4) + RzRbar3*(50.376996703604712*Power(Mag30,4) + RzRbar3*(-34.9280510478326*Power(Mag30,4) + 8.73201276195815*Power(Mag30,4)*RzRbar3)))))))/Power(Mag12,4);
  }
  
  double D_7_5_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.33584664469069808*Power(Mag30,5) + RzRbar3*(1.6792332234534904*Power(Mag30,5) + RzRbar3*(1.0075399340720942*Power(Mag30,5) + RzRbar3*(-18.471565457988394*Power(Mag30,5) + RzRbar3*(41.98083058633726*Power(Mag30,5) + RzRbar3*(-43.324217165100052*Power(Mag30,5) + RzRbar3*(21.8300319048953751*Power(Mag30,5) - 4.36600638097907502*Power(Mag30,5)*RzRbar3)))))))/Power(Mag12,5);
  }
  
  double D_7_6_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(1.7124885948525321*Power(Mag30,6) + RzRbar3*(-10.2749315691151929*Power(Mag30,6) + RzRbar3*(25.687328922787982*Power(Mag30,6) + RzRbar3*(-34.249771897050643*Power(Mag30,6) + RzRbar3*(25.6873289227879822*Power(Mag30,6) + RzRbar3*(-10.2749315691151929*Power(Mag30,6) + 1.71248859485253215*Power(Mag30,6)*RzRbar3)))))))/Power(Mag12,6);
  }
  
  double D_7_7_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.45768182862115031*Power(Mag30,7) + RzRbar3*(-3.2037728003480521*Power(Mag30,7) + RzRbar3*(9.6113184010441564*Power(Mag30,7) + RzRbar3*(-16.0188640017402607*Power(Mag30,7) + RzRbar3*(16.0188640017402607*Power(Mag30,7) + RzRbar3*(-9.6113184010441564*Power(Mag30,7) + RzRbar3*(3.20377280034805215*Power(Mag30,7) - 0.457681828621150307*Power(Mag30,7)*RzRbar3)))))))/Power(Mag12,7);
  }
  
  double D_7_neg7_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.85624429742626607*Power(Mag12,8) + RzRbar3*(5.1374657845575964*Power(Mag12,8) + RzRbar3*(12.8436644613939911*Power(Mag12,8) + RzRbar3*(17.1248859485253215*Power(Mag12,8) + RzRbar3*(12.8436644613939911*Power(Mag12,8) + RzRbar3*(5.1374657845575964*Power(Mag12,8) + 0.856244297426266075*Power(Mag12,8)*RzRbar3))))))/Power(Mag30,6);
  }
  
  double D_7_neg6_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.45768182862115031*Power(Mag12,7) + RzRbar3*(-5.4921819434538037*Power(Mag12,7) + RzRbar3*(-20.595682287951764*Power(Mag12,7) + RzRbar3*(-36.614546289692025*Power(Mag12,7) + RzRbar3*(-34.326137146586273*Power(Mag12,7) + RzRbar3*(-16.476545830361411*Power(Mag12,7) - 3.20377280034805215*Power(Mag12,7)*RzRbar3))))))/Power(Mag30,5);
  }
  
  double D_7_neg5_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.44879395676078349*Power(Mag12,6) + RzRbar3*(0.5385527481129402*Power(Mag12,6) + RzRbar3*(14.810200573105855*Power(Mag12,6) + RzRbar3*(44.879395676078349*Power(Mag12,6) + RzRbar3*(57.89442042214107*Power(Mag12,6) + RzRbar3*(35.005928627341112*Power(Mag12,6) + 8.1680500130462595*Power(Mag12,6)*RzRbar3))))))/Power(Mag30,4);
  }
  
  double D_7_neg4_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.53855274811294019*Power(Mag12,5) + RzRbar3*(4.3084219849035215*Power(Mag12,5) + RzRbar3*(2.6927637405647009*Power(Mag12,5) + RzRbar3*(-28.722813232690143*Power(Mag12,5) + RzRbar3*(-67.319093514117523*Power(Mag12,5) + RzRbar3*(-56.009485803745779*Power(Mag12,5) - 16.336100026092519*Power(Mag12,5)*RzRbar3))))))/Power(Mag30,3);
  }
  
  double D_7_neg3_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.243569644814373369*Power(Mag12,4) + RzRbar3*(-3.0852155009820627*Power(Mag12,4) + RzRbar3*(-15.832026912934269*Power(Mag12,4) + RzRbar3*(-5.953924651018016*Power(Mag12,4) + RzRbar3*(49.119878370898629*Power(Mag12,4) + RzRbar3*(69.660918416910784*Power(Mag12,4) + 27.0903571621319714*Power(Mag12,4)*RzRbar3))))))/Power(Mag30,2);
  }
  
  double D_7_neg2_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.57409915846480737*Power(Mag12,3) + RzRbar3*(-2.29639663385922947*Power(Mag12,3) + RzRbar3*(10.90788401083134*Power(Mag12,3) + RzRbar3*(33.6804839632686989*Power(Mag12,3) + RzRbar3*(-6.315090743112881*Power(Mag12,3) + RzRbar3*(-65.676943728373963*Power(Mag12,3) - 38.3115505082181449*Power(Mag12,3)*RzRbar3))))))/Mag30;
  }
  
  double D_7_neg1_1() {
    return -0.078125*Power(Mag12,2) + RzRbar3*(4.21875*Power(Mag12,2) + RzRbar3*(6.328125*Power(Mag12,2) + RzRbar3*(-30.9375*Power(Mag12,2) + RzRbar3*(-38.671875*Power(Mag12,2) + RzRbar3*(40.21875*Power(Mag12,2) + 46.921875*Power(Mag12,2)*RzRbar3)))));
  }
  
  double D_7_0_1() {
    return 0.58463396668342834*Mag12*Mag30 + Power(RzRbar3,2)*(-15.7851171004525652*Mag12*Mag30 + Power(RzRbar3,2)*(57.878762701659406*Mag12*Mag30 - 50.161594341438152*Mag12*Mag30*Power(RzRbar3,2)));
  }
  
  double D_7_1_1() {
    return -0.078125*Power(Mag30,2) + RzRbar3*(-4.21875*Power(Mag30,2) + RzRbar3*(6.328125*Power(Mag30,2) + RzRbar3*(30.9375*Power(Mag30,2) + RzRbar3*(-38.671875*Power(Mag30,2) + RzRbar3*(-40.21875*Power(Mag30,2) + 46.921875*Power(Mag30,2)*RzRbar3)))));
  }
  
  double D_7_2_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.57409915846480737*Power(Mag30,3) + RzRbar3*(2.29639663385922947*Power(Mag30,3) + RzRbar3*(10.90788401083134*Power(Mag30,3) + RzRbar3*(-33.6804839632686989*Power(Mag30,3) + RzRbar3*(-6.315090743112881*Power(Mag30,3) + RzRbar3*(65.676943728373963*Power(Mag30,3) - 38.3115505082181449*Power(Mag30,3)*RzRbar3))))))/Mag12;
  }
  
  double D_7_3_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.243569644814373369*Power(Mag30,4) + RzRbar3*(3.0852155009820627*Power(Mag30,4) + RzRbar3*(-15.832026912934269*Power(Mag30,4) + RzRbar3*(5.953924651018016*Power(Mag30,4) + RzRbar3*(49.119878370898629*Power(Mag30,4) + RzRbar3*(-69.660918416910784*Power(Mag30,4) + 27.0903571621319714*Power(Mag30,4)*RzRbar3))))))/Power(Mag12,2);
  }
  
  double D_7_4_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.53855274811294019*Power(Mag30,5) + RzRbar3*(-4.3084219849035215*Power(Mag30,5) + RzRbar3*(2.6927637405647009*Power(Mag30,5) + RzRbar3*(28.722813232690143*Power(Mag30,5) + RzRbar3*(-67.319093514117523*Power(Mag30,5) + RzRbar3*(56.009485803745779*Power(Mag30,5) - 16.336100026092519*Power(Mag30,5)*RzRbar3))))))/Power(Mag12,3);
  }
  
  double D_7_5_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.44879395676078349*Power(Mag30,6) + RzRbar3*(-0.5385527481129402*Power(Mag30,6) + RzRbar3*(14.810200573105855*Power(Mag30,6) + RzRbar3*(-44.879395676078349*Power(Mag30,6) + RzRbar3*(57.89442042214107*Power(Mag30,6) + RzRbar3*(-35.005928627341112*Power(Mag30,6) + 8.1680500130462595*Power(Mag30,6)*RzRbar3))))))/Power(Mag12,4);
  }
  
  double D_7_6_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.45768182862115031*Power(Mag30,7) + RzRbar3*(5.4921819434538037*Power(Mag30,7) + RzRbar3*(-20.595682287951764*Power(Mag30,7) + RzRbar3*(36.614546289692025*Power(Mag30,7) + RzRbar3*(-34.326137146586273*Power(Mag30,7) + RzRbar3*(16.476545830361411*Power(Mag30,7) - 3.20377280034805215*Power(Mag30,7)*RzRbar3))))))/Power(Mag12,5);
  }
  
  double D_7_7_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.85624429742626607*Power(Mag30,8) + RzRbar3*(-5.1374657845575964*Power(Mag30,8) + RzRbar3*(12.8436644613939911*Power(Mag30,8) + RzRbar3*(-17.1248859485253215*Power(Mag30,8) + RzRbar3*(12.8436644613939911*Power(Mag30,8) + RzRbar3*(-5.1374657845575964*Power(Mag30,8) + 0.856244297426266075*Power(Mag30,8)*RzRbar3))))))/Power(Mag12,6);
  }
  
  double D_7_neg7_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.39824108257481835*Power(Mag12,9) + RzRbar3*(-6.9912054128740918*Power(Mag12,9) + RzRbar3*(-13.9824108257481835*Power(Mag12,9) + RzRbar3*(-13.9824108257481835*Power(Mag12,9) + RzRbar3*(-6.9912054128740918*Power(Mag12,9) - 1.39824108257481835*Power(Mag12,9)*RzRbar3)))))/Power(Mag30,5);
  }
  
  double D_7_neg6_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.49478259288767475*Power(Mag12,8) + RzRbar3*(11.2108694466575606*Power(Mag12,8) + RzRbar3*(29.895651857753495*Power(Mag12,8) + RzRbar3*(37.369564822191869*Power(Mag12,8) + RzRbar3*(22.4217388933151213*Power(Mag12,8) + 5.2317390751068616*Power(Mag12,8)*RzRbar3)))))/Power(Mag30,4);
  }
  
  double D_7_neg5_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.146575492494482174*Power(Mag12,7) + RzRbar3*(-8.0616520871965195*Power(Mag12,7) + RzRbar3*(-36.643873123620543*Power(Mag12,7) + RzRbar3*(-63.027461772627335*Power(Mag12,7) + RzRbar3*(-47.637035060706706*Power(Mag12,7) - 13.3383698169978778*Power(Mag12,7)*RzRbar3)))))/Power(Mag30,3);
  }
  
  double D_7_neg4_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.17260393995585739*Power(Mag12,6) + RzRbar3*(-1.4657549249448217*Power(Mag12,6) + RzRbar3*(23.4520787991171478*Power(Mag12,6) + RzRbar3*(73.287746247241087*Power(Mag12,6) + RzRbar3*(76.21925609713073*Power(Mag12,6) + 26.6767396339957556*Power(Mag12,6)*RzRbar3)))))/Power(Mag30,2);
  }
  
  double D_7_neg3_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.83968930265902519*Power(Mag12,5) + RzRbar3*(8.617863895711048*Power(Mag12,5) + RzRbar3*(4.86135912065751423*Power(Mag12,5) + RzRbar3*(-53.474950327232657*Power(Mag12,5) + RzRbar3*(-94.796502852821527*Power(Mag12,5) - 44.2383679979833795*Power(Mag12,5)*RzRbar3)))))/Mag30;
  }
  
  double D_7_neg2_2() {
    return 0.625*Power(Mag12,4) + RzRbar3*(-5.9375*Power(Mag12,4) + RzRbar3*(-27.5*Power(Mag12,4) + RzRbar3*(6.875*Power(Mag12,4) + RzRbar3*(89.375*Power(Mag12,4) + 62.5625*Power(Mag12,4)*RzRbar3))));
  }
  
  double D_7_neg1_2() {
    return -1.14819831692961473*Power(Mag12,3)*Mag30 + RzRbar3*(-3.4445949507888442*Power(Mag12,3)*Mag30 + RzRbar3*(25.2603629724515241*Power(Mag12,3)*Mag30 + RzRbar3*(42.1006049540858736*Power(Mag12,3)*Mag30 + RzRbar3*(-54.730786440311636*Power(Mag12,3)*Mag30 - 76.62310101643629*Power(Mag12,3)*Mag30*RzRbar3))));
  }
  
  double D_7_0_2() {
    return RzRbar3*(8.5923294280422*Power(Mag12,2)*Power(Mag30,2) + Power(RzRbar3,2)*(-63.0104158056428*Power(Mag12,2)*Power(Mag30,2) + 81.91354054733564*Power(Mag12,2)*Power(Mag30,2)*Power(RzRbar3,2)));
  }
  
  double D_7_1_2() {
    return 1.14819831692961473*Mag12*Power(Mag30,3) + RzRbar3*(-3.4445949507888442*Mag12*Power(Mag30,3) + RzRbar3*(-25.2603629724515241*Mag12*Power(Mag30,3) + RzRbar3*(42.1006049540858736*Mag12*Power(Mag30,3) + RzRbar3*(54.730786440311636*Mag12*Power(Mag30,3) - 76.62310101643629*Mag12*Power(Mag30,3)*RzRbar3))));
  }
  
  double D_7_2_2() {
    return -0.625*Power(Mag30,4) + RzRbar3*(-5.9375*Power(Mag30,4) + RzRbar3*(27.5*Power(Mag30,4) + RzRbar3*(6.875*Power(Mag30,4) + RzRbar3*(-89.375*Power(Mag30,4) + 62.5625*Power(Mag30,4)*RzRbar3))));
  }
  
  double D_7_3_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.83968930265902519*Power(Mag30,5) + RzRbar3*(8.617863895711048*Power(Mag30,5) + RzRbar3*(-4.86135912065751423*Power(Mag30,5) + RzRbar3*(-53.474950327232657*Power(Mag30,5) + RzRbar3*(94.796502852821527*Power(Mag30,5) - 44.2383679979833795*Power(Mag30,5)*RzRbar3)))))/Mag12;
  }
  
  double D_7_4_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.17260393995585739*Power(Mag30,6) + RzRbar3*(-1.4657549249448217*Power(Mag30,6) + RzRbar3*(-23.4520787991171478*Power(Mag30,6) + RzRbar3*(73.287746247241087*Power(Mag30,6) + RzRbar3*(-76.21925609713073*Power(Mag30,6) + 26.6767396339957556*Power(Mag30,6)*RzRbar3)))))/Power(Mag12,2);
  }
  
  double D_7_5_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.146575492494482174*Power(Mag30,7) + RzRbar3*(-8.0616520871965195*Power(Mag30,7) + RzRbar3*(36.643873123620543*Power(Mag30,7) + RzRbar3*(-63.027461772627335*Power(Mag30,7) + RzRbar3*(47.637035060706706*Power(Mag30,7) - 13.3383698169978778*Power(Mag30,7)*RzRbar3)))))/Power(Mag12,3);
  }
  
  double D_7_6_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.49478259288767475*Power(Mag30,8) + RzRbar3*(11.2108694466575606*Power(Mag30,8) + RzRbar3*(-29.895651857753495*Power(Mag30,8) + RzRbar3*(37.369564822191869*Power(Mag30,8) + RzRbar3*(-22.4217388933151213*Power(Mag30,8) + 5.2317390751068616*Power(Mag30,8)*RzRbar3)))))/Power(Mag12,4);
  }
  
  double D_7_7_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.39824108257481835*Power(Mag30,9) + RzRbar3*(-6.9912054128740918*Power(Mag30,9) + RzRbar3*(13.9824108257481835*Power(Mag30,9) + RzRbar3*(-13.9824108257481835*Power(Mag30,9) + RzRbar3*(6.9912054128740918*Power(Mag30,9) - 1.39824108257481835*Power(Mag30,9)*RzRbar3)))))/Power(Mag12,5);
  }
  
  double D_7_neg7_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.97741150244454682*Power(Mag12,10) + RzRbar3*(7.9096460097781873*Power(Mag12,10) + RzRbar3*(11.8644690146672809*Power(Mag12,10) + RzRbar3*(7.9096460097781873*Power(Mag12,10) + 1.97741150244454682*Power(Mag12,10)*RzRbar3))))/Power(Mag30,4);
  }
  
  double D_7_neg6_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-3.1709127234914555*Power(Mag12,9) + RzRbar3*(-16.9115345252877629*Power(Mag12,9) + RzRbar3*(-31.709127234914555*Power(Mag12,9) + RzRbar3*(-25.3673017879316443*Power(Mag12,9) - 7.3987963548133963*Power(Mag12,9)*RzRbar3))))/Power(Mag30,3);
  }
  
  double D_7_neg5_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.2801795433693374*Power(Mag12,8) + RzRbar3*(20.7289049397212491*Power(Mag12,8) + RzRbar3*(53.480574744480823*Power(Mag12,8) + RzRbar3*(53.895152843275248*Power(Mag12,8) + 18.8633034951463366*Power(Mag12,8)*RzRbar3))))/Power(Mag30,2);
  }
  
  double D_7_neg4_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.414578098794424981*Power(Mag12,7) + RzRbar3*(-13.2664991614215994*Power(Mag12,7) + RzRbar3*(-62.186714819163747*Power(Mag12,7) + RzRbar3*(-86.232244549240396*Power(Mag12,7) - 37.7266069902926733*Power(Mag12,7)*RzRbar3))))/Mag30;
  }
  
  double D_7_neg3_3() {
    return -2.4375*Power(Mag12,6) + RzRbar3*(-2.75*Power(Mag12,6) + RzRbar3*(45.375*Power(Mag12,6) + RzRbar3*(107.25*Power(Mag12,6) + 62.5625*Power(Mag12,6)*RzRbar3)));
  }
  
  double D_7_neg2_3() {
    return 1.67937860531805037*Power(Mag12,5)*Mag30 + RzRbar3*(15.5563491861040455*Power(Mag12,5)*Mag30 + RzRbar3*(-5.8336309447890171*Power(Mag12,5)*Mag30 + RzRbar3*(-101.116269709676296*Power(Mag12,5)*Mag30 - 88.476735995966759*Power(Mag12,5)*Mag30*RzRbar3)));
  }
  
  double D_7_neg1_3() {
    return 0.97427857925749348*Power(Mag12,4)*Power(Mag30,2) + RzRbar3*(-14.2894191624432377*Power(Mag12,4)*Power(Mag30,2) + RzRbar3*(-35.7235479061080942*Power(Mag12,4)*Power(Mag30,2) + RzRbar3*(61.920816370587363*Power(Mag12,4)*Power(Mag30,2) + 108.361428648527886*Power(Mag12,4)*Power(Mag30,2)*RzRbar3)));
  }
  
  double D_7_0_3() {
    return -2.43027776190294759*Power(Mag12,3)*Power(Mag30,3) + Power(RzRbar3,2)*(53.466110761864847*Power(Mag12,3)*Power(Mag30,3) - 115.843239984040502*Power(Mag12,3)*Power(Mag30,3)*Power(RzRbar3,2));
  }
  
  double D_7_1_3() {
    return 0.97427857925749348*Power(Mag12,2)*Power(Mag30,4) + RzRbar3*(14.2894191624432377*Power(Mag12,2)*Power(Mag30,4) + RzRbar3*(-35.7235479061080942*Power(Mag12,2)*Power(Mag30,4) + RzRbar3*(-61.920816370587363*Power(Mag12,2)*Power(Mag30,4) + 108.361428648527886*Power(Mag12,2)*Power(Mag30,4)*RzRbar3)));
  }
  
  double D_7_2_3() {
    return 1.67937860531805037*Mag12*Power(Mag30,5) + RzRbar3*(-15.5563491861040455*Mag12*Power(Mag30,5) + RzRbar3*(-5.8336309447890171*Mag12*Power(Mag30,5) + RzRbar3*(101.116269709676296*Mag12*Power(Mag30,5) - 88.476735995966759*Mag12*Power(Mag30,5)*RzRbar3)));
  }
  
  double D_7_3_3() {
    return -2.4375*Power(Mag30,6) + RzRbar3*(2.75*Power(Mag30,6) + RzRbar3*(45.375*Power(Mag30,6) + RzRbar3*(-107.25*Power(Mag30,6) + 62.5625*Power(Mag30,6)*RzRbar3)));
  }
  
  double D_7_4_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.414578098794424981*Power(Mag30,7) + RzRbar3*(13.2664991614215994*Power(Mag30,7) + RzRbar3*(-62.186714819163747*Power(Mag30,7) + RzRbar3*(86.232244549240396*Power(Mag30,7) - 37.7266069902926733*Power(Mag30,7)*RzRbar3))))/Mag12;
  }
  
  double D_7_5_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.2801795433693374*Power(Mag30,8) + RzRbar3*(-20.7289049397212491*Power(Mag30,8) + RzRbar3*(53.480574744480823*Power(Mag30,8) + RzRbar3*(-53.895152843275248*Power(Mag30,8) + 18.8633034951463366*Power(Mag30,8)*RzRbar3))))/Power(Mag12,2);
  }
  
  double D_7_6_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-3.1709127234914555*Power(Mag30,9) + RzRbar3*(16.9115345252877629*Power(Mag30,9) + RzRbar3*(-31.709127234914555*Power(Mag30,9) + RzRbar3*(25.3673017879316443*Power(Mag30,9) - 7.3987963548133963*Power(Mag30,9)*RzRbar3))))/Power(Mag12,3);
  }
  
  double D_7_7_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.97741150244454682*Power(Mag30,10) + RzRbar3*(-7.9096460097781873*Power(Mag30,10) + RzRbar3*(11.8644690146672809*Power(Mag30,10) + RzRbar3*(-7.9096460097781873*Power(Mag30,10) + 1.97741150244454682*Power(Mag30,10)*RzRbar3))))/Power(Mag12,4);
  }
  
  double D_7_neg7_4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-2.38484800354236412*Power(Mag12,11) + RzRbar3*(-7.1545440106270924*Power(Mag12,11) + RzRbar3*(-7.1545440106270924*Power(Mag12,11) - 2.38484800354236412*Power(Mag12,11)*RzRbar3)))/Power(Mag30,3);
  }
  
  double D_7_neg6_4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (5.0990195135927848*Power(Mag12,10) + RzRbar3*(19.1213231759729431*Power(Mag12,10) + RzRbar3*(22.9455878111675317*Power(Mag12,10) + 8.9232841487873735*Power(Mag12,10)*RzRbar3)))/Power(Mag30,2);
  }
  
  double D_7_neg5_4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-6.25*Power(Mag12,9) + RzRbar3*(-32.25*Power(Mag12,9) + RzRbar3*(-48.75*Power(Mag12,9) - 22.75*Power(Mag12,9)*RzRbar3)))/Mag30;
  }
  
  double D_7_neg4_4() {
    return 4.*Power(Mag12,8) + RzRbar3*(37.5*Power(Mag12,8) + RzRbar3*(78.*Power(Mag12,8) + 45.5*Power(Mag12,8)*RzRbar3));
  }
  
  double D_7_neg3_4() {
    return 0.82915619758884996*Power(Mag12,7)*Mag30 + RzRbar3*(-27.3621545204320488*Power(Mag12,7)*Mag30 + RzRbar3*(-97.011275117895446*Power(Mag12,7)*Mag30 - 75.453213980585347*Power(Mag12,7)*Mag30*RzRbar3));
  }
  
  double D_7_neg2_4() {
    return -4.69041575982342955*Power(Mag12,6)*Power(Mag30,2) + RzRbar3*(3.51781181986757217*Power(Mag12,6)*Power(Mag30,2) + RzRbar3*(91.463107316556876*Power(Mag12,6)*Power(Mag30,2) + 106.706958535983022*Power(Mag12,6)*Power(Mag30,2)*RzRbar3));
  }
  
  double D_7_neg1_4() {
    return 4.30842198490352149*Power(Mag12,5)*Power(Mag30,3) + RzRbar3*(21.5421099245176075*Power(Mag12,5)*Power(Mag30,3) + RzRbar3*(-56.009485803745779*Power(Mag12,5)*Power(Mag30,3) - 130.688800208740152*Power(Mag12,5)*Power(Mag30,3)*RzRbar3));
  }
  
  double D_7_0_4() {
    return RzRbar3*(-32.2412778903070156*Power(Mag12,4)*Power(Mag30,4) + 139.712204191330401*Power(Mag12,4)*Power(Mag30,4)*Power(RzRbar3,2));
  }
  
  double D_7_1_4() {
    return -4.30842198490352149*Power(Mag12,3)*Power(Mag30,5) + RzRbar3*(21.5421099245176075*Power(Mag12,3)*Power(Mag30,5) + RzRbar3*(56.009485803745779*Power(Mag12,3)*Power(Mag30,5) - 130.688800208740152*Power(Mag12,3)*Power(Mag30,5)*RzRbar3));
  }
  
  double D_7_2_4() {
    return 4.69041575982342955*Power(Mag12,2)*Power(Mag30,6) + RzRbar3*(3.51781181986757217*Power(Mag12,2)*Power(Mag30,6) + RzRbar3*(-91.463107316556876*Power(Mag12,2)*Power(Mag30,6) + 106.706958535983022*Power(Mag12,2)*Power(Mag30,6)*RzRbar3));
  }
  
  double D_7_3_4() {
    return -0.82915619758884996*Mag12*Power(Mag30,7) + RzRbar3*(-27.3621545204320488*Mag12*Power(Mag30,7) + RzRbar3*(97.011275117895446*Mag12*Power(Mag30,7) - 75.453213980585347*Mag12*Power(Mag30,7)*RzRbar3));
  }
  
  double D_7_4_4() {
    return -4.*Power(Mag30,8) + RzRbar3*(37.5*Power(Mag30,8) + RzRbar3*(-78.*Power(Mag30,8) + 45.5*Power(Mag30,8)*RzRbar3));
  }
  
  double D_7_5_4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (6.25*Power(Mag30,9) + RzRbar3*(-32.25*Power(Mag30,9) + RzRbar3*(48.75*Power(Mag30,9) - 22.75*Power(Mag30,9)*RzRbar3)))/Mag12;
  }
  
  double D_7_6_4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-5.0990195135927848*Power(Mag30,10) + RzRbar3*(19.1213231759729431*Power(Mag30,10) + RzRbar3*(-22.9455878111675317*Power(Mag30,10) + 8.9232841487873735*Power(Mag30,10)*RzRbar3)))/Power(Mag12,2);
  }
  
  double D_7_7_4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.38484800354236412*Power(Mag30,11) + RzRbar3*(-7.1545440106270924*Power(Mag30,11) + RzRbar3*(7.1545440106270924*Power(Mag30,11) - 2.38484800354236412*Power(Mag30,11)*RzRbar3)))/Power(Mag12,3);
  }
  
  double D_7_neg7_5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.38484800354236412*Power(Mag12,12) + RzRbar3*(4.76969600708472825*Power(Mag12,12) + 2.38484800354236412*Power(Mag12,12)*RzRbar3))/Power(Mag30,2);
  }
  
  double D_7_neg6_5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-6.373774391990981*Power(Mag12,11) + RzRbar3*(-15.2970585407783545*Power(Mag12,11) - 8.9232841487873735*Power(Mag12,11)*RzRbar3))/Mag30;
  }
  
  double D_7_neg5_5() {
    return 10.75*Power(Mag12,10) + RzRbar3*(32.5*Power(Mag12,10) + 22.75*Power(Mag12,10)*RzRbar3);
  }
  
  double D_7_neg4_5() {
    return -12.5*Power(Mag12,9)*Mag30 + RzRbar3*(-52.*Power(Mag12,9)*Mag30 - 45.5*Power(Mag12,9)*Mag30*RzRbar3);
  }
  
  double D_7_neg3_5() {
    return 9.1207181734773496*Power(Mag12,8)*Power(Mag30,2) + RzRbar3*(64.674183411930297*Power(Mag12,8)*Power(Mag30,2) + 75.453213980585347*Power(Mag12,8)*Power(Mag30,2)*RzRbar3);
  }
  
  double D_7_neg2_5() {
    return -1.17260393995585739*Power(Mag12,7)*Power(Mag30,3) + RzRbar3*(-60.975404877704584*Power(Mag12,7)*Power(Mag30,3) - 106.706958535983022*Power(Mag12,7)*Power(Mag30,3)*RzRbar3);
  }
  
  double D_7_neg1_5() {
    return -7.1807033081725358*Power(Mag12,6)*Power(Mag30,4) + RzRbar3*(37.3396572024971863*Power(Mag12,6)*Power(Mag30,4) + 130.688800208740152*Power(Mag12,6)*Power(Mag30,4)*RzRbar3);
  }
  
  double D_7_0_5() {
    return 10.7470926301023385*Power(Mag12,5)*Power(Mag30,5) - 139.712204191330401*Power(Mag12,5)*Power(Mag30,5)*Power(RzRbar3,2);
  }
  
  double D_7_1_5() {
    return -7.1807033081725358*Power(Mag12,4)*Power(Mag30,6) + RzRbar3*(-37.3396572024971863*Power(Mag12,4)*Power(Mag30,6) + 130.688800208740152*Power(Mag12,4)*Power(Mag30,6)*RzRbar3);
  }
  
  double D_7_2_5() {
    return -1.17260393995585739*Power(Mag12,3)*Power(Mag30,7) + RzRbar3*(60.975404877704584*Power(Mag12,3)*Power(Mag30,7) - 106.706958535983022*Power(Mag12,3)*Power(Mag30,7)*RzRbar3);
  }
  
  double D_7_3_5() {
    return 9.1207181734773496*Power(Mag12,2)*Power(Mag30,8) + RzRbar3*(-64.674183411930297*Power(Mag12,2)*Power(Mag30,8) + 75.453213980585347*Power(Mag12,2)*Power(Mag30,8)*RzRbar3);
  }
  
  double D_7_4_5() {
    return -12.5*Mag12*Power(Mag30,9) + RzRbar3*(52.*Mag12*Power(Mag30,9) - 45.5*Mag12*Power(Mag30,9)*RzRbar3);
  }
  
  double D_7_5_5() {
    return 10.75*Power(Mag30,10) + RzRbar3*(-32.5*Power(Mag30,10) + 22.75*Power(Mag30,10)*RzRbar3);
  }
  
  double D_7_6_5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-6.373774391990981*Power(Mag30,11) + RzRbar3*(15.2970585407783545*Power(Mag30,11) - 8.9232841487873735*Power(Mag30,11)*RzRbar3))/Mag12;
  }
  
  double D_7_7_5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.38484800354236412*Power(Mag30,12) + RzRbar3*(-4.76969600708472825*Power(Mag30,12) + 2.38484800354236412*Power(Mag30,12)*RzRbar3))/Power(Mag12,2);
  }
  
  double D_7_neg7_6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.87082869338697069*Power(Mag12,13) - 1.87082869338697069*Power(Mag12,13)*RzRbar3)/Mag30;
  }
  
  double D_7_neg6_6() {
    return 6.*Power(Mag12,12) + 7.*Power(Mag12,12)*RzRbar3;
  }
  
  double D_7_neg5_6() {
    return -12.7475487839819621*Power(Mag12,11)*Mag30 - 17.8465682975747469*Power(Mag12,11)*Mag30*RzRbar3;
  }
  
  double D_7_neg4_6() {
    return 20.3960780543711393*Power(Mag12,10)*Power(Mag30,2) + 35.6931365951494938*Power(Mag12,10)*Power(Mag30,2)*RzRbar3;
  }
  
  double D_7_neg3_6() {
    return -25.3673017879316443*Power(Mag12,9)*Power(Mag30,3) - 59.19037083850717*Power(Mag12,9)*Power(Mag30,3)*RzRbar3;
  }
  
  double D_7_neg2_6() {
    return 23.916521486202796*Power(Mag12,8)*Power(Mag30,4) + 83.707825201709786*Power(Mag12,8)*Power(Mag30,4)*RzRbar3;
  }
  
  double D_7_neg1_6() {
    return -14.6458185158768098*Power(Mag12,7)*Power(Mag30,5) - 102.520729611137669*Power(Mag12,7)*Power(Mag30,5)*RzRbar3;
  }
  
  double D_7_0_6() {
    return 109.599270070562058*Power(Mag12,6)*Power(Mag30,6)*RzRbar3;
  }
  
  double D_7_1_6() {
    return 14.6458185158768098*Power(Mag12,5)*Power(Mag30,7) - 102.520729611137669*Power(Mag12,5)*Power(Mag30,7)*RzRbar3;
  }
  
  double D_7_2_6() {
    return -23.916521486202796*Power(Mag12,4)*Power(Mag30,8) + 83.707825201709786*Power(Mag12,4)*Power(Mag30,8)*RzRbar3;
  }
  
  double D_7_3_6() {
    return 25.3673017879316443*Power(Mag12,3)*Power(Mag30,9) - 59.19037083850717*Power(Mag12,3)*Power(Mag30,9)*RzRbar3;
  }
  
  double D_7_4_6() {
    return -20.3960780543711393*Power(Mag12,2)*Power(Mag30,10) + 35.6931365951494938*Power(Mag12,2)*Power(Mag30,10)*RzRbar3;
  }
  
  double D_7_5_6() {
    return 12.7475487839819621*Mag12*Power(Mag30,11) - 17.8465682975747469*Mag12*Power(Mag30,11)*RzRbar3;
  }
  
  double D_7_6_6() {
    return -6.*Power(Mag30,12) + 7.*Power(Mag30,12)*RzRbar3;
  }
  
  double D_7_7_6() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.87082869338697069*Power(Mag30,13) - 1.87082869338697069*Power(Mag30,13)*RzRbar3)/Mag12;
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
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.000244140625 + RzRbar3*(0.0029296875 + RzRbar3*(0.01611328125 + RzRbar3*(0.0537109375 + RzRbar3*(0.120849609375 + RzRbar3*(0.193359375 + RzRbar3*(0.2255859375 + RzRbar3*(0.193359375 + RzRbar3*(0.120849609375 + RzRbar3*(0.0537109375 + RzRbar3*(0.01611328125 + (0.0029296875 + 0.000244140625*RzRbar3)*RzRbar3)))))))))))/Power(Mag30,12);
  }
  
  double D_6_neg5_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0008457279333832409 + RzRbar3*(0.008457279333832409 + RzRbar3*(0.037212029068862598 + RzRbar3*(0.0930300726721565 + RzRbar3*(0.13954510900823474 + RzRbar3*(0.11163608720658779 + RzRbar3*(0.e-17 + RzRbar3*(-0.11163608720658779 + RzRbar3*(-0.13954510900823474 + RzRbar3*(-0.093030072672156495 + RzRbar3*(-0.037212029068862598 + (-0.0084572793338324087 - 0.000845727933383240866*RzRbar3)*RzRbar3)))))))))))/(Mag12*Power(Mag30,11));
  }
  
  double D_6_neg4_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0019834078136318263 + RzRbar3*(0.01586726250905461 + RzRbar3*(0.05156860315442748 + RzRbar3*(0.07933631254527305 + RzRbar3*(0.02975111720447739 + RzRbar3*(-0.0952035750543277 + RzRbar3*(-0.1666062563450734 + RzRbar3*(-0.09520357505432766 + RzRbar3*(0.02975111720447739 + RzRbar3*(0.07933631254527305 + RzRbar3*(0.051568603154427483 + (0.0158672625090546101 + 0.00198340781363182626*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,2)*Power(Mag30,10));
  }
  
  double D_6_neg3_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0036211906675271792 + RzRbar3*(0.021727144005163075 + RzRbar3*(0.04345428801032615 + RzRbar3*(0.00724238133505436 + RzRbar3*(-0.0977721480232338 + RzRbar3*(-0.1303628640309785 + RzRbar3*(0.e-16 + RzRbar3*(0.1303628640309785 + RzRbar3*(0.09777214802323384 + RzRbar3*(-0.00724238133505436 + RzRbar3*(-0.04345428801032615 + (-0.021727144005163075 - 0.00362119066752717917*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,3)*Power(Mag30,9));
  }
  
  double D_6_neg2_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0054317860012907688 + RzRbar3*(0.021727144005163075 + RzRbar3*(0.01086357200258154 + RzRbar3*(-0.0651814320154892 + RzRbar3*(-0.0923403620219431 + RzRbar3*(0.0434542880103262 + RzRbar3*(0.1520900080361415 + RzRbar3*(0.0434542880103262 + RzRbar3*(-0.0923403620219431 + RzRbar3*(-0.06518143201548923 + RzRbar3*(0.01086357200258154 + (0.021727144005163075 + 0.00543178600129076876*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,4)*Power(Mag30,8));
  }
  
  double D_6_neg1_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0068707262106788519 + RzRbar3*(0.013741452421357704 + RzRbar3*(-0.02748290484271541 + RzRbar3*(-0.0687072621067885 + RzRbar3*(0.0343536310533943 + RzRbar3*(0.137414524213577 + RzRbar3*(0.e-16 + RzRbar3*(-0.137414524213577 + RzRbar3*(-0.0343536310533943 + RzRbar3*(0.06870726210678852 + RzRbar3*(0.02748290484271541 + (-0.013741452421357704 - 0.00687072621067885189*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,5)*Power(Mag30,7));
  }
  
  double D_6_0_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0074212324968606756 + Power(RzRbar3,2)*(-0.044527394981164054 + Power(RzRbar3,2)*(0.111318487452910134 + Power(RzRbar3,2)*(-0.148424649937213512 + Power(RzRbar3,2)*(0.111318487452910134 + Power(RzRbar3,2)*(-0.0445273949811640536 + 0.0074212324968606756*Power(RzRbar3,2)))))))/(Power(Mag12,6)*Power(Mag30,6));
  }
  
  double D_6_1_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0068707262106788519 + RzRbar3*(-0.013741452421357704 + RzRbar3*(-0.02748290484271541 + RzRbar3*(0.0687072621067885 + RzRbar3*(0.0343536310533943 + RzRbar3*(-0.137414524213577 + RzRbar3*(0.e-16 + RzRbar3*(0.137414524213577 + RzRbar3*(-0.0343536310533943 + RzRbar3*(-0.06870726210678852 + RzRbar3*(0.02748290484271541 + (0.013741452421357704 - 0.00687072621067885189*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,7)*Power(Mag30,5));
  }
  
  double D_6_2_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0054317860012907688 + RzRbar3*(-0.021727144005163075 + RzRbar3*(0.01086357200258154 + RzRbar3*(0.0651814320154892 + RzRbar3*(-0.0923403620219431 + RzRbar3*(-0.0434542880103262 + RzRbar3*(0.1520900080361415 + RzRbar3*(-0.0434542880103262 + RzRbar3*(-0.0923403620219431 + RzRbar3*(0.06518143201548923 + RzRbar3*(0.01086357200258154 + (-0.021727144005163075 + 0.00543178600129076876*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,8)*Power(Mag30,4));
  }
  
  double D_6_3_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0036211906675271792 + RzRbar3*(-0.021727144005163075 + RzRbar3*(0.04345428801032615 + RzRbar3*(-0.00724238133505436 + RzRbar3*(-0.0977721480232338 + RzRbar3*(0.1303628640309785 + RzRbar3*(0.e-16 + RzRbar3*(-0.1303628640309785 + RzRbar3*(0.09777214802323384 + RzRbar3*(0.00724238133505436 + RzRbar3*(-0.04345428801032615 + (0.021727144005163075 - 0.00362119066752717917*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,9)*Power(Mag30,3));
  }
  
  double D_6_4_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0019834078136318263 + RzRbar3*(-0.01586726250905461 + RzRbar3*(0.05156860315442748 + RzRbar3*(-0.07933631254527305 + RzRbar3*(0.02975111720447739 + RzRbar3*(0.0952035750543277 + RzRbar3*(-0.1666062563450734 + RzRbar3*(0.09520357505432766 + RzRbar3*(0.02975111720447739 + RzRbar3*(-0.07933631254527305 + RzRbar3*(0.051568603154427483 + (-0.0158672625090546101 + 0.00198340781363182626*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,10)*Power(Mag30,2));
  }
  
  double D_6_5_neg6() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0008457279333832409 + RzRbar3*(-0.008457279333832409 + RzRbar3*(0.037212029068862598 + RzRbar3*(-0.0930300726721565 + RzRbar3*(0.13954510900823474 + RzRbar3*(-0.11163608720658779 + RzRbar3*(0.e-17 + RzRbar3*(0.11163608720658779 + RzRbar3*(-0.13954510900823474 + RzRbar3*(0.093030072672156495 + RzRbar3*(-0.037212029068862598 + (0.0084572793338324087 - 0.000845727933383240866*RzRbar3)*RzRbar3)))))))))))/(Power(Mag12,11)*Mag30);
  }
  
  double D_6_6_neg6() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.000244140625 + RzRbar3*(-0.0029296875 + RzRbar3*(0.01611328125 + RzRbar3*(-0.0537109375 + RzRbar3*(0.120849609375 + RzRbar3*(-0.193359375 + RzRbar3*(0.2255859375 + RzRbar3*(-0.193359375 + RzRbar3*(0.120849609375 + RzRbar3*(-0.0537109375 + RzRbar3*(0.01611328125 + (-0.0029296875 + 0.000244140625*RzRbar3)*RzRbar3)))))))))))/Power(Mag12,12);
  }
  
  double D_6_neg6_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0016914558667664817*Mag12 + RzRbar3*(-0.018606014534431299*Mag12 + RzRbar3*(-0.093030072672156495*Mag12 + RzRbar3*(-0.27909021801646949*Mag12 + RzRbar3*(-0.55818043603293897*Mag12 + RzRbar3*(-0.78145261044611456*Mag12 + RzRbar3*(-0.78145261044611456*Mag12 + RzRbar3*(-0.55818043603293897*Mag12 + RzRbar3*(-0.27909021801646949*Mag12 + RzRbar3*(-0.093030072672156495*Mag12 + RzRbar3*(-0.0186060145344312991*Mag12 - 0.00169145586676648173*Mag12*RzRbar3)))))))))))/Power(Mag30,11);
  }
  
  double D_6_neg5_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0048828125 + RzRbar3*(-0.04296875 + RzRbar3*(-0.1611328125 + RzRbar3*(-0.322265625 + RzRbar3*(-0.322265625 + RzRbar3*(0.e-16 + RzRbar3*(0.451171875 + RzRbar3*(0.64453125 + RzRbar3*(0.4833984375 + RzRbar3*(0.21484375 + (0.0537109375 + 0.005859375*RzRbar3)*RzRbar3))))))))))/Power(Mag30,10);
  }
  
  double D_6_neg4_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.009160968280905136 + RzRbar3*(-0.05954629382588338 + RzRbar3*(-0.13741452421357704 + RzRbar3*(-0.0687072621067885 + RzRbar3*(0.2748290484271541 + RzRbar3*(0.5771410016970236 + RzRbar3*(0.3847606677980157 + RzRbar3*(-0.137414524213577 + RzRbar3*(-0.41224357264073111 + RzRbar3*(-0.29773146912941692 + (-0.100770651089956494 - 0.0137414524213577038*RzRbar3)*RzRbar3))))))))))/(Mag12*Power(Mag30,9));
  }
  
  double D_6_neg3_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.012544172440102665 + RzRbar3*(-0.05017668976041066 + RzRbar3*(-0.01254417244010267 + RzRbar3*(0.225795103921848 + RzRbar3*(0.37632517320308 + RzRbar3*(0.e-16 + RzRbar3*(-0.5268552424843119 + RzRbar3*(-0.4515902078436959 + RzRbar3*(0.037632517320308 + RzRbar3*(0.2508834488020533 + (0.137985896841129316 + 0.0250883448802053301*RzRbar3)*RzRbar3))))))))))/(Power(Mag12,2)*Power(Mag30,8));
  }
  
  double D_6_neg2_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.012544172440102665 + RzRbar3*(-0.01254417244010267 + RzRbar3*(0.11289755196092399 + RzRbar3*(0.2132509314817453 + RzRbar3*(-0.1254417244010267 + RzRbar3*(-0.5268552424843119 + RzRbar3*(-0.1756184141614373 + RzRbar3*(0.4265018629634906 + RzRbar3*(0.338692655882772 + RzRbar3*(-0.06272086220051333 + (-0.137985896841129316 - 0.0376325173203079952*RzRbar3)*RzRbar3))))))))))/(Power(Mag12,3)*Power(Mag30,7));
  }
  
  double D_6_neg1_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.007933631254527305 + RzRbar3*(0.03173452501810922 + RzRbar3*(0.11900446881790958 + RzRbar3*(-0.0793363125452731 + RzRbar3*(-0.3966815627263653 + RzRbar3*(0.e-16 + RzRbar3*(0.5553541878169114 + RzRbar3*(0.1586726250905461 + RzRbar3*(-0.3570134064537287 + RzRbar3*(-0.1586726250905461 + (0.08726994379980036 + 0.0476017875271638302*RzRbar3)*RzRbar3))))))))))/(Power(Mag12,4)*Power(Mag30,6));
  }
  
  double D_6_0_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(0.051415806957375715 + Power(RzRbar3,2)*(-0.25707903478687858 + Power(RzRbar3,2)*(0.51415806957375715 + Power(RzRbar3,2)*(-0.51415806957375715 + Power(RzRbar3,2)*(0.257079034786878576 - 0.0514158069573757152*Power(RzRbar3,2)))))))/(Power(Mag12,5)*Power(Mag30,5));
  }
  
  double D_6_1_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.007933631254527305 + RzRbar3*(0.03173452501810922 + RzRbar3*(-0.11900446881790958 + RzRbar3*(-0.0793363125452731 + RzRbar3*(0.3966815627263653 + RzRbar3*(0.e-16 + RzRbar3*(-0.5553541878169114 + RzRbar3*(0.1586726250905461 + RzRbar3*(0.3570134064537287 + RzRbar3*(-0.1586726250905461 + (-0.08726994379980036 + 0.0476017875271638302*RzRbar3)*RzRbar3))))))))))/(Power(Mag12,6)*Power(Mag30,4));
  }
  
  double D_6_2_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.012544172440102665 + RzRbar3*(-0.01254417244010267 + RzRbar3*(-0.11289755196092399 + RzRbar3*(0.2132509314817453 + RzRbar3*(0.1254417244010267 + RzRbar3*(-0.5268552424843119 + RzRbar3*(0.1756184141614373 + RzRbar3*(0.4265018629634906 + RzRbar3*(-0.338692655882772 + RzRbar3*(-0.06272086220051333 + (0.137985896841129316 - 0.0376325173203079952*RzRbar3)*RzRbar3))))))))))/(Power(Mag12,7)*Power(Mag30,3));
  }
  
  double D_6_3_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.012544172440102665 + RzRbar3*(-0.05017668976041066 + RzRbar3*(0.01254417244010267 + RzRbar3*(0.225795103921848 + RzRbar3*(-0.37632517320308 + RzRbar3*(0.e-16 + RzRbar3*(0.5268552424843119 + RzRbar3*(-0.4515902078436959 + RzRbar3*(-0.037632517320308 + RzRbar3*(0.2508834488020533 + (-0.137985896841129316 + 0.0250883448802053301*RzRbar3)*RzRbar3))))))))))/(Power(Mag12,8)*Power(Mag30,2));
  }
  
  double D_6_4_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.009160968280905136 + RzRbar3*(-0.05954629382588338 + RzRbar3*(0.13741452421357704 + RzRbar3*(-0.0687072621067885 + RzRbar3*(-0.2748290484271541 + RzRbar3*(0.5771410016970236 + RzRbar3*(-0.3847606677980157 + RzRbar3*(-0.137414524213577 + RzRbar3*(0.41224357264073111 + RzRbar3*(-0.29773146912941692 + (0.100770651089956494 - 0.0137414524213577038*RzRbar3)*RzRbar3))))))))))/(Power(Mag12,9)*Mag30);
  }
  
  double D_6_5_neg5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0048828125 + RzRbar3*(-0.04296875 + RzRbar3*(0.1611328125 + RzRbar3*(-0.322265625 + RzRbar3*(0.322265625 + RzRbar3*(0.e-16 + RzRbar3*(-0.451171875 + RzRbar3*(0.64453125 + RzRbar3*(-0.4833984375 + RzRbar3*(0.21484375 + (-0.0537109375 + 0.005859375*RzRbar3)*RzRbar3))))))))))/Power(Mag12,10);
  }
  
  double D_6_6_neg5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0016914558667664817*Mag30 + RzRbar3*(-0.018606014534431299*Mag30 + RzRbar3*(0.093030072672156495*Mag30 + RzRbar3*(-0.27909021801646949*Mag30 + RzRbar3*(0.55818043603293897*Mag30 + RzRbar3*(-0.78145261044611456*Mag30 + RzRbar3*(0.78145261044611456*Mag30 + RzRbar3*(-0.55818043603293897*Mag30 + RzRbar3*(0.27909021801646949*Mag30 + RzRbar3*(-0.093030072672156495*Mag30 + RzRbar3*(0.0186060145344312991*Mag30 - 0.00169145586676648173*Mag30*RzRbar3)))))))))))/Power(Mag12,11);
  }
  
  double D_6_neg6_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.007933631254527305*Power(Mag12,2) + RzRbar3*(0.07933631254527305*Power(Mag12,2) + RzRbar3*(0.35701340645372873*Power(Mag12,2) + RzRbar3*(0.9520357505432766*Power(Mag12,2) + RzRbar3*(1.6660625634507341*Power(Mag12,2) + RzRbar3*(1.9992750761408809*Power(Mag12,2) + RzRbar3*(1.66606256345073406*Power(Mag12,2) + RzRbar3*(0.9520357505432766*Power(Mag12,2) + RzRbar3*(0.35701340645372873*Power(Mag12,2) + RzRbar3*(0.07933631254527305*Power(Mag12,2) + 0.00793363125452730504*Power(Mag12,2)*RzRbar3))))))))))/Power(Mag30,10);
  }
  
  double D_6_neg5_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.018321936561810272*Mag12 + RzRbar3*(0.13741452421357704*Mag12 + RzRbar3*(0.41224357264073111*Mag12 + RzRbar3*(0.5496580968543082*Mag12 + RzRbar3*(0.e-16*Mag12 + RzRbar3*(-1.1542820033940471*Mag12 + RzRbar3*(-1.9238033389900785*Mag12 + RzRbar3*(-1.6489742905629245*Mag12 + RzRbar3*(-0.82448714528146223*Mag12 + RzRbar3*(-0.229024207022628396*Mag12 - 0.0274829048427154075*Mag12*RzRbar3))))))))))/Power(Mag30,9);
  }
  
  double D_6_neg4_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.025390625 + RzRbar3*(0.1171875 + RzRbar3*(0.087890625 + RzRbar3*(-0.46875 + RzRbar3*(-1.23046875 + RzRbar3*(-0.984375 + RzRbar3*(0.41015625 + RzRbar3*(1.40625 + RzRbar3*(1.142578125 + (0.4296875 + 0.064453125*RzRbar3)*RzRbar3)))))))))/Power(Mag30,8);
  }
  
  double D_6_neg3_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.021395412402545551 + RzRbar3*(0.01069770620127278 + RzRbar3*(-0.2888380674343649 + RzRbar3*(-0.6418623720763665 + RzRbar3*(0.e-16 + RzRbar3*(1.3479109813603697 + RzRbar3*(1.3479109813603697 + RzRbar3*(-0.1283724744152733 + RzRbar3*(-0.9627935581145498 + (-0.58837384107000266 - 0.117674768214000532*RzRbar3)*RzRbar3)))))))))/(Mag12*Power(Mag30,7));
  }
  
  double D_6_neg2_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0053488531006363878 + RzRbar3*(-0.09627935581145498 + RzRbar3*(-0.2727915081324558 + RzRbar3*(0.2139541240254555 + RzRbar3*(1.1232591511336414 + RzRbar3*(0.449303660453457 + RzRbar3*(-1.2730270379514603 + RzRbar3*(-1.1553522697374598 + RzRbar3*(0.2406983895286375 + (0.58837384107000266 + 0.176512152321000798*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,2)*Power(Mag30,6));
  }
  
  double D_6_neg1_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.013531646934131854 + RzRbar3*(-0.1014873520059889 + RzRbar3*(0.1014873520059889 + RzRbar3*(0.6765823467065927 + RzRbar3*(0.e-16 + RzRbar3*(-1.420822928083845 + RzRbar3*(-0.4736076426946149 + RzRbar3*(1.2178482240718668 + RzRbar3*(0.6089241120359334 + (-0.37212029068862598 - 0.223272174413175589*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,3)*Power(Mag30,5));
  }
  
  double D_6_0_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.021923773750628563 + Power(RzRbar3,2)*(0.32885660625942844 + Power(RzRbar3,2)*(-1.09618868753142814 + Power(RzRbar3,2)*(1.5346641625439994 + Power(RzRbar3,2)*(-0.98656981877828533 + 0.241161511256914191*Power(RzRbar3,2))))))/(Power(Mag12,4)*Power(Mag30,4));
  }
  
  double D_6_1_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.013531646934131854 + RzRbar3*(0.1014873520059889 + RzRbar3*(0.1014873520059889 + RzRbar3*(-0.6765823467065927 + RzRbar3*(0.e-16 + RzRbar3*(1.420822928083845 + RzRbar3*(-0.4736076426946149 + RzRbar3*(-1.2178482240718668 + RzRbar3*(0.6089241120359334 + (0.37212029068862598 - 0.223272174413175589*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,5)*Power(Mag30,3));
  }
  
  double D_6_2_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0053488531006363878 + RzRbar3*(0.09627935581145498 + RzRbar3*(-0.2727915081324558 + RzRbar3*(-0.2139541240254555 + RzRbar3*(1.1232591511336414 + RzRbar3*(-0.449303660453457 + RzRbar3*(-1.2730270379514603 + RzRbar3*(1.1553522697374598 + RzRbar3*(0.2406983895286375 + (-0.58837384107000266 + 0.176512152321000798*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,6)*Power(Mag30,2));
  }
  
  double D_6_3_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.021395412402545551 + RzRbar3*(-0.01069770620127278 + RzRbar3*(-0.2888380674343649 + RzRbar3*(0.6418623720763665 + RzRbar3*(0.e-16 + RzRbar3*(-1.3479109813603697 + RzRbar3*(1.3479109813603697 + RzRbar3*(0.1283724744152733 + RzRbar3*(-0.9627935581145498 + (0.58837384107000266 - 0.117674768214000532*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,7)*Mag30);
  }
  
  double D_6_4_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.025390625 + RzRbar3*(-0.1171875 + RzRbar3*(0.087890625 + RzRbar3*(0.46875 + RzRbar3*(-1.23046875 + RzRbar3*(0.984375 + RzRbar3*(0.41015625 + RzRbar3*(-1.40625 + RzRbar3*(1.142578125 + (-0.4296875 + 0.064453125*RzRbar3)*RzRbar3)))))))))/Power(Mag12,8);
  }
  
  double D_6_5_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.018321936561810272*Mag30 + RzRbar3*(-0.13741452421357704*Mag30 + RzRbar3*(0.41224357264073111*Mag30 + RzRbar3*(-0.5496580968543082*Mag30 + RzRbar3*(0.e-16*Mag30 + RzRbar3*(1.1542820033940471*Mag30 + RzRbar3*(-1.9238033389900785*Mag30 + RzRbar3*(1.6489742905629245*Mag30 + RzRbar3*(-0.82448714528146223*Mag30 + RzRbar3*(0.229024207022628396*Mag30 - 0.0274829048427154075*Mag30*RzRbar3))))))))))/Power(Mag12,9);
  }
  
  double D_6_6_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.007933631254527305*Power(Mag30,2) + RzRbar3*(-0.07933631254527305*Power(Mag30,2) + RzRbar3*(0.35701340645372873*Power(Mag30,2) + RzRbar3*(-0.9520357505432766*Power(Mag30,2) + RzRbar3*(1.6660625634507341*Power(Mag30,2) + RzRbar3*(-1.9992750761408809*Power(Mag30,2) + RzRbar3*(1.66606256345073406*Power(Mag30,2) + RzRbar3*(-0.9520357505432766*Power(Mag30,2) + RzRbar3*(0.35701340645372873*Power(Mag30,2) + RzRbar3*(-0.07933631254527305*Power(Mag30,2) + 0.00793363125452730504*Power(Mag30,2)*RzRbar3))))))))))/Power(Mag12,10);
  }
  
  double D_6_neg6_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.028969525340217433*Power(Mag12,3) + RzRbar3*(-0.2607257280619569*Power(Mag12,3) + RzRbar3*(-1.0429029122478276*Power(Mag12,3) + RzRbar3*(-2.4334401285782644*Power(Mag12,3) + RzRbar3*(-3.6501601928673966*Power(Mag12,3) + RzRbar3*(-3.6501601928673966*Power(Mag12,3) + RzRbar3*(-2.43344012857826441*Power(Mag12,3) + RzRbar3*(-1.0429029122478276*Power(Mag12,3) + RzRbar3*(-0.260725728061956901*Power(Mag12,3) - 0.0289695253402174334*Power(Mag12,3)*RzRbar3)))))))))/Power(Mag30,9);
  }
  
  double D_6_neg5_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.05017668976041066*Power(Mag12,2) + RzRbar3*(-0.30106013856246396*Power(Mag12,2) + RzRbar3*(-0.6021202771249279*Power(Mag12,2) + RzRbar3*(0.e-16*Power(Mag12,2) + RzRbar3*(2.1074209699372477*Power(Mag12,2) + RzRbar3*(4.2148419398744955*Power(Mag12,2) + RzRbar3*(4.2148419398744955*Power(Mag12,2) + RzRbar3*(2.4084811084997117*Power(Mag12,2) + RzRbar3*(0.7526503464061599*Power(Mag12,2) + 0.10035337952082132*Power(Mag12,2)*RzRbar3)))))))))/Power(Mag30,8);
  }
  
  double D_6_neg4_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.042790824805091103*Mag12 + RzRbar3*(-0.06418623720763665*Mag12 + RzRbar3*(0.5134898976610932*Mag12 + RzRbar3*(1.7972146418138263*Mag12 + RzRbar3*(1.7972146418138263*Mag12 + RzRbar3*(-0.8986073209069132*Mag12 + RzRbar3*(-3.5944292836276526*Mag12 + RzRbar3*(-3.337684334797106*Mag12 + RzRbar3*(-1.41209721856800639*Mag12 - 0.235349536428001064*Mag12*RzRbar3)))))))))/Power(Mag30,7);
  }
  
  double D_6_neg3_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.00390625 + RzRbar3*(0.2109375 + RzRbar3*(0.703125 + RzRbar3*(0.e-16 + RzRbar3*(-2.4609375 + RzRbar3*(-2.953125 + RzRbar3*(0.328125 + RzRbar3*(2.8125 + (1.93359375 + 0.4296875*RzRbar3)*RzRbar3))))))))/Power(Mag30,6);
  }
  
  double D_6_neg2_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.03515625 + RzRbar3*(0.19921875 + RzRbar3*(-0.234375 + RzRbar3*(-1.640625 + RzRbar3*(-0.8203125 + RzRbar3*(2.7890625 + RzRbar3*(2.953125 + RzRbar3*(-0.703125 + (-1.93359375 - 0.64453125*RzRbar3)*RzRbar3))))))))/(Mag12*Power(Mag30,5));
  }
  
  double D_6_neg1_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.037057941330098195 + RzRbar3*(-0.07411588266019639 + RzRbar3*(-0.7411588266019639 + RzRbar3*(0.e-16 + RzRbar3*(2.5940558931068737 + RzRbar3*(1.037622357242749 + RzRbar3*(-3.1128670717282484 + RzRbar3*(-1.7787811838447134 + (1.2229120638932404 + 0.8152747092621603*RzRbar3)*RzRbar3))))))))/(Power(Mag12,2)*Power(Mag30,4));
  }
  
  double D_6_0_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-0.24016290857717809 + Power(RzRbar3,2)*(1.60108605718118725 + Power(RzRbar3,2)*(-3.3622807200804932 + Power(RzRbar3,2)*(2.88195490292613705 - 0.88059733144965299*Power(RzRbar3,2))))))/(Power(Mag12,3)*Power(Mag30,3));
  }
  
  double D_6_1_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.037057941330098195 + RzRbar3*(-0.07411588266019639 + RzRbar3*(0.7411588266019639 + RzRbar3*(0.e-16 + RzRbar3*(-2.5940558931068737 + RzRbar3*(1.037622357242749 + RzRbar3*(3.1128670717282484 + RzRbar3*(-1.7787811838447134 + (-1.2229120638932404 + 0.8152747092621603*RzRbar3)*RzRbar3))))))))/(Power(Mag12,4)*Power(Mag30,2));
  }
  
  double D_6_2_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.03515625 + RzRbar3*(0.19921875 + RzRbar3*(0.234375 + RzRbar3*(-1.640625 + RzRbar3*(0.8203125 + RzRbar3*(2.7890625 + RzRbar3*(-2.953125 + RzRbar3*(-0.703125 + (1.93359375 - 0.64453125*RzRbar3)*RzRbar3))))))))/(Power(Mag12,5)*Mag30);
  }
  
  double D_6_3_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00390625 + RzRbar3*(0.2109375 + RzRbar3*(-0.703125 + RzRbar3*(0.e-16 + RzRbar3*(2.4609375 + RzRbar3*(-2.953125 + RzRbar3*(-0.328125 + RzRbar3*(2.8125 + (-1.93359375 + 0.4296875*RzRbar3)*RzRbar3))))))))/Power(Mag12,6);
  }
  
  double D_6_4_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.042790824805091103*Mag30 + RzRbar3*(-0.06418623720763665*Mag30 + RzRbar3*(-0.5134898976610932*Mag30 + RzRbar3*(1.7972146418138263*Mag30 + RzRbar3*(-1.7972146418138263*Mag30 + RzRbar3*(-0.8986073209069132*Mag30 + RzRbar3*(3.5944292836276526*Mag30 + RzRbar3*(-3.337684334797106*Mag30 + RzRbar3*(1.41209721856800639*Mag30 - 0.235349536428001064*Mag30*RzRbar3)))))))))/Power(Mag12,7);
  }
  
  double D_6_5_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.05017668976041066*Power(Mag30,2) + RzRbar3*(-0.30106013856246396*Power(Mag30,2) + RzRbar3*(0.6021202771249279*Power(Mag30,2) + RzRbar3*(0.e-16*Power(Mag30,2) + RzRbar3*(-2.1074209699372477*Power(Mag30,2) + RzRbar3*(4.2148419398744955*Power(Mag30,2) + RzRbar3*(-4.2148419398744955*Power(Mag30,2) + RzRbar3*(2.4084811084997117*Power(Mag30,2) + RzRbar3*(-0.7526503464061599*Power(Mag30,2) + 0.10035337952082132*Power(Mag30,2)*RzRbar3)))))))))/Power(Mag12,8);
  }
  
  double D_6_6_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.028969525340217433*Power(Mag30,3) + RzRbar3*(-0.2607257280619569*Power(Mag30,3) + RzRbar3*(1.0429029122478276*Power(Mag30,3) + RzRbar3*(-2.4334401285782644*Power(Mag30,3) + RzRbar3*(3.6501601928673966*Power(Mag30,3) + RzRbar3*(-3.6501601928673966*Power(Mag30,3) + RzRbar3*(2.43344012857826441*Power(Mag30,3) + RzRbar3*(-1.0429029122478276*Power(Mag30,3) + RzRbar3*(0.260725728061956901*Power(Mag30,3) - 0.0289695253402174334*Power(Mag30,3)*RzRbar3)))))))))/Power(Mag12,9);
  }
  
  double D_6_neg6_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0869085760206523*Power(Mag12,4) + RzRbar3*(0.6952686081652184*Power(Mag12,4) + RzRbar3*(2.4334401285782644*Power(Mag12,4) + RzRbar3*(4.8668802571565288*Power(Mag12,4) + RzRbar3*(6.083600321445661*Power(Mag12,4) + RzRbar3*(4.8668802571565288*Power(Mag12,4) + RzRbar3*(2.43344012857826441*Power(Mag12,4) + RzRbar3*(0.6952686081652184*Power(Mag12,4) + 0.0869085760206523002*Power(Mag12,4)*RzRbar3))))))))/Power(Mag30,8);
  }
  
  double D_6_neg5_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.10035337952082132*Power(Mag12,3) + RzRbar3*(0.40141351808328528*Power(Mag12,3) + RzRbar3*(0.e-16*Power(Mag12,3) + RzRbar3*(-2.809894626582997*Power(Mag12,3) + RzRbar3*(-7.0247365664574924*Power(Mag12,3) + RzRbar3*(-8.4296838797489909*Power(Mag12,3) + RzRbar3*(-5.6197892531659939*Power(Mag12,3) + RzRbar3*(-2.00706759041642641*Power(Mag12,3) - 0.301060138562463961*Power(Mag12,3)*RzRbar3))))))))/Power(Mag30,7);
  }
  
  double D_6_neg4_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.021395412402545551*Power(Mag12,2) + RzRbar3*(-0.34232659844072882*Power(Mag12,2) + RzRbar3*(-1.7972146418138263*Power(Mag12,2) + RzRbar3*(-2.3962861890851017*Power(Mag12,2) + RzRbar3*(1.497678868178189*Power(Mag12,2) + RzRbar3*(7.1888585672553052*Power(Mag12,2) + RzRbar3*(7.7879301145265807*Power(Mag12,2) + RzRbar3*(3.765592582848017*Power(Mag12,2) + 0.70604860928400319*Power(Mag12,2)*RzRbar3))))))))/Power(Mag30,6);
  }
  
  double D_6_neg3_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0703125*Mag12 + RzRbar3*(-0.46875*Mag12 + RzRbar3*(0.e-16*Mag12 + RzRbar3*(3.28125*Mag12 + RzRbar3*(4.921875*Mag12 + RzRbar3*(-0.65625*Mag12 + RzRbar3*(-6.5625*Mag12 + RzRbar3*(-5.15625*Mag12 - 1.2890625*Mag12*RzRbar3))))))))/Power(Mag30,5);
  }
  
  double D_6_neg2_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.06640625 + RzRbar3*(0.15625 + RzRbar3*(1.640625 + RzRbar3*(1.09375 + RzRbar3*(-4.6484375 + RzRbar3*(-5.90625 + RzRbar3*(1.640625 + RzRbar3*(5.15625 + 1.93359375*RzRbar3))))))))/Power(Mag30,4);
  }
  
  double D_6_neg1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.024705294220065464 + RzRbar3*(0.49410588440130927 + RzRbar3*(0.e-16 + RzRbar3*(-3.4587411908091649 + RzRbar3*(-1.7293705954045824 + RzRbar3*(6.2257341434564968 + RzRbar3*(4.1504894289709979 + (-3.2610988370486412 - 2.44582412778648089*RzRbar3)*RzRbar3)))))))/(Mag12*Power(Mag30,3));
  }
  
  double D_6_0_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.080054302859059362 + Power(RzRbar3,2)*(-1.60108605718118725 + Power(RzRbar3,2)*(5.6038012001341554 + Power(RzRbar3,2)*(-6.7245614401609864 + 2.64179199434895896*Power(RzRbar3,2)))))/(Power(Mag12,2)*Power(Mag30,2));
  }
  
  double D_6_1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.024705294220065464 + RzRbar3*(-0.49410588440130927 + RzRbar3*(0.e-16 + RzRbar3*(3.4587411908091649 + RzRbar3*(-1.7293705954045824 + RzRbar3*(-6.2257341434564968 + RzRbar3*(4.1504894289709979 + (3.2610988370486412 - 2.44582412778648089*RzRbar3)*RzRbar3)))))))/(Power(Mag12,3)*Mag30);
  }
  
  double D_6_2_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.06640625 + RzRbar3*(-0.15625 + RzRbar3*(1.640625 + RzRbar3*(-1.09375 + RzRbar3*(-4.6484375 + RzRbar3*(5.90625 + RzRbar3*(1.640625 + RzRbar3*(-5.15625 + 1.93359375*RzRbar3))))))))/Power(Mag12,4);
  }
  
  double D_6_3_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0703125*Mag30 + RzRbar3*(0.46875*Mag30 + RzRbar3*(0.e-16*Mag30 + RzRbar3*(-3.28125*Mag30 + RzRbar3*(4.921875*Mag30 + RzRbar3*(0.65625*Mag30 + RzRbar3*(-6.5625*Mag30 + RzRbar3*(5.15625*Mag30 - 1.2890625*Mag30*RzRbar3))))))))/Power(Mag12,5);
  }
  
  double D_6_4_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.021395412402545551*Power(Mag30,2) + RzRbar3*(0.34232659844072882*Power(Mag30,2) + RzRbar3*(-1.7972146418138263*Power(Mag30,2) + RzRbar3*(2.3962861890851017*Power(Mag30,2) + RzRbar3*(1.497678868178189*Power(Mag30,2) + RzRbar3*(-7.1888585672553052*Power(Mag30,2) + RzRbar3*(7.7879301145265807*Power(Mag30,2) + RzRbar3*(-3.765592582848017*Power(Mag30,2) + 0.70604860928400319*Power(Mag30,2)*RzRbar3))))))))/Power(Mag12,6);
  }
  
  double D_6_5_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.10035337952082132*Power(Mag30,3) + RzRbar3*(-0.40141351808328528*Power(Mag30,3) + RzRbar3*(0.e-16*Power(Mag30,3) + RzRbar3*(2.809894626582997*Power(Mag30,3) + RzRbar3*(-7.0247365664574924*Power(Mag30,3) + RzRbar3*(8.4296838797489909*Power(Mag30,3) + RzRbar3*(-5.6197892531659939*Power(Mag30,3) + RzRbar3*(2.00706759041642641*Power(Mag30,3) - 0.301060138562463961*Power(Mag30,3)*RzRbar3))))))))/Power(Mag12,7);
  }
  
  double D_6_6_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0869085760206523*Power(Mag30,4) + RzRbar3*(-0.6952686081652184*Power(Mag30,4) + RzRbar3*(2.4334401285782644*Power(Mag30,4) + RzRbar3*(-4.8668802571565288*Power(Mag30,4) + RzRbar3*(6.083600321445661*Power(Mag30,4) + RzRbar3*(-4.8668802571565288*Power(Mag30,4) + RzRbar3*(2.43344012857826441*Power(Mag30,4) + RzRbar3*(-0.6952686081652184*Power(Mag30,4) + 0.0869085760206523002*Power(Mag30,4)*RzRbar3))))))))/Power(Mag12,8);
  }
  
  double D_6_neg6_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.21986323874172326*Power(Mag12,5) + RzRbar3*(-1.5390426711920628*Power(Mag12,5) + RzRbar3*(-4.6171280135761885*Power(Mag12,5) + RzRbar3*(-7.6952133559603141*Power(Mag12,5) + RzRbar3*(-7.6952133559603141*Power(Mag12,5) + RzRbar3*(-4.6171280135761885*Power(Mag12,5) + RzRbar3*(-1.53904267119206282*Power(Mag12,5) - 0.21986323874172326*Power(Mag12,5)*RzRbar3)))))))/Power(Mag30,7);
  }
  
  double D_6_neg5_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.12693810007243688*Power(Mag12,4) + RzRbar3*(0.e-16*Power(Mag12,4) + RzRbar3*(2.6657001015211745*Power(Mag12,4) + RzRbar3*(8.8856670050705816*Power(Mag12,4) + RzRbar3*(13.3285005076058725*Power(Mag12,4) + RzRbar3*(10.662800406084698*Power(Mag12,4) + RzRbar3*(4.4428335025352908*Power(Mag12,4) + 0.76162860043462128*Power(Mag12,4)*RzRbar3)))))))/Power(Mag30,6);
  }
  
  double D_6_neg4_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.108253175473054831*Power(Mag12,3) + RzRbar3*(1.13665834246707572*Power(Mag12,3) + RzRbar3*(2.2733166849341514*Power(Mag12,3) + RzRbar3*(-1.8944305707784595*Power(Mag12,3) + RzRbar3*(-11.366583424670757*Power(Mag12,3) + RzRbar3*(-14.7765584520719844*Power(Mag12,3) + RzRbar3*(-8.335494511425222*Power(Mag12,3) - 1.78617739530540471*Power(Mag12,3)*RzRbar3)))))))/Power(Mag30,5);
  }
  
  double D_6_neg3_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.148231765320392781*Power(Mag12,2) + RzRbar3*(0.e-17*Power(Mag12,2) + RzRbar3*(-3.1128670717282484*Power(Mag12,2) + RzRbar3*(-6.2257341434564968*Power(Mag12,2) + RzRbar3*(1.037622357242749*Power(Mag12,2) + RzRbar3*(12.4514682869129936*Power(Mag12,2) + RzRbar3*(11.4138459296702442*Power(Mag12,2) + 3.26109883704864119*Power(Mag12,2)*RzRbar3)))))))/Power(Mag30,4);
  }
  
  double D_6_neg2_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.049410588440130927*Mag12 + RzRbar3*(-1.03762235724274947*Mag12 + RzRbar3*(-1.0376223572427495*Mag12 + RzRbar3*(5.8798600243755803*Mag12 + RzRbar3*(9.3386012151847452*Mag12 + RzRbar3*(-3.1128670717282484*Mag12 + RzRbar3*(-11.4138459296702442*Mag12 - 4.89164825557296178*Mag12*RzRbar3)))))))/Power(Mag30,3);
  }
  
  double D_6_neg1_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.15625 + RzRbar3*(0.e-17 + RzRbar3*(3.28125 + RzRbar3*(2.1875 + RzRbar3*(-9.84375 + RzRbar3*(-7.875 + RzRbar3*(7.21875 + 6.1875*RzRbar3)))))))/Power(Mag30,2);
  }
  
  double D_6_0_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(1.01261573412622816 + Power(RzRbar3,2)*(-7.0883101388835971 + Power(RzRbar3,2)*(12.7589582499904748 - 6.6832638452331059*Power(RzRbar3,2)))))/(Mag12*Mag30);
  }
  
  double D_6_1_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.15625 + RzRbar3*(0.e-17 + RzRbar3*(-3.28125 + RzRbar3*(2.1875 + RzRbar3*(9.84375 + RzRbar3*(-7.875 + RzRbar3*(-7.21875 + 6.1875*RzRbar3)))))))/Power(Mag12,2);
  }
  
  double D_6_2_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.049410588440130927*Mag30 + RzRbar3*(-1.03762235724274947*Mag30 + RzRbar3*(1.0376223572427495*Mag30 + RzRbar3*(5.8798600243755803*Mag30 + RzRbar3*(-9.3386012151847452*Mag30 + RzRbar3*(-3.1128670717282484*Mag30 + RzRbar3*(11.4138459296702442*Mag30 - 4.89164825557296178*Mag30*RzRbar3)))))))/Power(Mag12,3);
  }
  
  double D_6_3_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.148231765320392781*Power(Mag30,2) + RzRbar3*(0.e-17*Power(Mag30,2) + RzRbar3*(3.1128670717282484*Power(Mag30,2) + RzRbar3*(-6.2257341434564968*Power(Mag30,2) + RzRbar3*(-1.037622357242749*Power(Mag30,2) + RzRbar3*(12.4514682869129936*Power(Mag30,2) + RzRbar3*(-11.4138459296702442*Power(Mag30,2) + 3.26109883704864119*Power(Mag30,2)*RzRbar3)))))))/Power(Mag12,4);
  }
  
  double D_6_4_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.108253175473054831*Power(Mag30,3) + RzRbar3*(1.13665834246707572*Power(Mag30,3) + RzRbar3*(-2.2733166849341514*Power(Mag30,3) + RzRbar3*(-1.8944305707784595*Power(Mag30,3) + RzRbar3*(11.366583424670757*Power(Mag30,3) + RzRbar3*(-14.7765584520719844*Power(Mag30,3) + RzRbar3*(8.335494511425222*Power(Mag30,3) - 1.78617739530540471*Power(Mag30,3)*RzRbar3)))))))/Power(Mag12,5);
  }
  
  double D_6_5_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.12693810007243688*Power(Mag30,4) + RzRbar3*(0.e-16*Power(Mag30,4) + RzRbar3*(-2.6657001015211745*Power(Mag30,4) + RzRbar3*(8.8856670050705816*Power(Mag30,4) + RzRbar3*(-13.3285005076058725*Power(Mag30,4) + RzRbar3*(10.662800406084698*Power(Mag30,4) + RzRbar3*(-4.4428335025352908*Power(Mag30,4) + 0.76162860043462128*Power(Mag30,4)*RzRbar3)))))))/Power(Mag12,6);
  }
  
  double D_6_6_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.21986323874172326*Power(Mag30,5) + RzRbar3*(-1.5390426711920628*Power(Mag30,5) + RzRbar3*(4.6171280135761885*Power(Mag30,5) + RzRbar3*(-7.6952133559603141*Power(Mag30,5) + RzRbar3*(7.6952133559603141*Power(Mag30,5) + RzRbar3*(-4.6171280135761885*Power(Mag30,5) + RzRbar3*(1.53904267119206282*Power(Mag30,5) - 0.21986323874172326*Power(Mag30,5)*RzRbar3)))))))/Power(Mag12,7);
  }
  
  double D_6_neg6_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.47495887979908324*Power(Mag12,6) + RzRbar3*(2.8497532787944994*Power(Mag12,6) + RzRbar3*(7.1243831969862486*Power(Mag12,6) + RzRbar3*(9.4991775959816648*Power(Mag12,6) + RzRbar3*(7.1243831969862486*Power(Mag12,6) + RzRbar3*(2.84975327879449943*Power(Mag12,6) + 0.474958879799083238*Power(Mag12,6)*RzRbar3))))))/Power(Mag30,6);
  }
  
  double D_6_neg5_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-1.64530582263602289*Power(Mag12,5) + RzRbar3*(-8.2265291131801144*Power(Mag12,5) + RzRbar3*(-16.4530582263602289*Power(Mag12,5) + RzRbar3*(-16.4530582263602289*Power(Mag12,5) + RzRbar3*(-8.2265291131801144*Power(Mag12,5) - 1.64530582263602289*Power(Mag12,5)*RzRbar3))))))/Power(Mag30,5);
  }
  
  double D_6_neg4_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.350780380010057*Power(Mag12,4) + RzRbar3*(-1.40312152004022802*Power(Mag12,4) + RzRbar3*(1.753901900050285*Power(Mag12,4) + RzRbar3*(14.0312152004022802*Power(Mag12,4) + RzRbar3*(22.8007247006537053*Power(Mag12,4) + RzRbar3*(15.4343367204425082*Power(Mag12,4) + 3.85858418011062705*Power(Mag12,4)*RzRbar3))))))/Power(Mag30,4);
  }
  
  double D_6_neg3_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(1.9213032686174247*Power(Mag12,3) + RzRbar3*(5.7639098058522741*Power(Mag12,3) + RzRbar3*(-1.2808688457449498*Power(Mag12,3) + RzRbar3*(-19.213032686174247*Power(Mag12,3) + RzRbar3*(-21.1343359547916717*Power(Mag12,3) - 7.0447786515972239*Power(Mag12,3)*RzRbar3))))))/Power(Mag30,3);
  }
  
  double D_6_neg2_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.32021721143623745*Power(Mag12,2) + RzRbar3*(0.6404344228724749*Power(Mag12,2) + RzRbar3*(-5.4436925944160366*Power(Mag12,2) + RzRbar3*(-11.5278196117045482*Power(Mag12,2) + RzRbar3*(4.8032581715435617*Power(Mag12,2) + RzRbar3*(21.1343359547916717*Power(Mag12,2) + 10.5671679773958358*Power(Mag12,2)*RzRbar3))))))/Power(Mag30,2);
  }
  
  double D_6_neg1_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-2.02523146825245632*Mag12 + RzRbar3*(-2.02523146825245632*Mag12 + RzRbar3*(12.1513888095147379*Mag12 + RzRbar3*(12.1513888095147379*Mag12 + RzRbar3*(-13.3665276904662117*Mag12 - 13.3665276904662117*Mag12*RzRbar3))))))/Mag30;
  }
  
  double D_6_0_0() {
    return -0.3125 + Power(RzRbar3,2)*(6.5625 + Power(RzRbar3,2)*(-19.6875 + 14.4375*Power(RzRbar3,2)));
  }
  
  double D_6_1_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(2.02523146825245632*Mag30 + RzRbar3*(-2.02523146825245632*Mag30 + RzRbar3*(-12.1513888095147379*Mag30 + RzRbar3*(12.1513888095147379*Mag30 + RzRbar3*(13.3665276904662117*Mag30 - 13.3665276904662117*Mag30*RzRbar3))))))/Mag12;
  }
  
  double D_6_2_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.32021721143623745*Power(Mag30,2) + RzRbar3*(-0.6404344228724749*Power(Mag30,2) + RzRbar3*(-5.4436925944160366*Power(Mag30,2) + RzRbar3*(11.5278196117045482*Power(Mag30,2) + RzRbar3*(4.8032581715435617*Power(Mag30,2) + RzRbar3*(-21.1343359547916717*Power(Mag30,2) + 10.5671679773958358*Power(Mag30,2)*RzRbar3))))))/Power(Mag12,2);
  }
  
  double D_6_3_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-1.9213032686174247*Power(Mag30,3) + RzRbar3*(5.7639098058522741*Power(Mag30,3) + RzRbar3*(1.2808688457449498*Power(Mag30,3) + RzRbar3*(-19.213032686174247*Power(Mag30,3) + RzRbar3*(21.1343359547916717*Power(Mag30,3) - 7.0447786515972239*Power(Mag30,3)*RzRbar3))))))/Power(Mag12,3);
  }
  
  double D_6_4_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.350780380010057*Power(Mag30,4) + RzRbar3*(1.40312152004022802*Power(Mag30,4) + RzRbar3*(1.753901900050285*Power(Mag30,4) + RzRbar3*(-14.0312152004022802*Power(Mag30,4) + RzRbar3*(22.8007247006537053*Power(Mag30,4) + RzRbar3*(-15.4343367204425082*Power(Mag30,4) + 3.85858418011062705*Power(Mag30,4)*RzRbar3))))))/Power(Mag12,4);
  }
  
  double D_6_5_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(1.64530582263602289*Power(Mag30,5) + RzRbar3*(-8.2265291131801144*Power(Mag30,5) + RzRbar3*(16.4530582263602289*Power(Mag30,5) + RzRbar3*(-16.4530582263602289*Power(Mag30,5) + RzRbar3*(8.2265291131801144*Power(Mag30,5) - 1.64530582263602289*Power(Mag30,5)*RzRbar3))))))/Power(Mag12,5);
  }
  
  double D_6_6_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.47495887979908324*Power(Mag30,6) + RzRbar3*(-2.8497532787944994*Power(Mag30,6) + RzRbar3*(7.1243831969862486*Power(Mag30,6) + RzRbar3*(-9.4991775959816648*Power(Mag30,6) + RzRbar3*(7.1243831969862486*Power(Mag30,6) + RzRbar3*(-2.84975327879449943*Power(Mag30,6) + 0.474958879799083238*Power(Mag30,6)*RzRbar3))))))/Power(Mag12,6);
  }
  
  double D_6_neg6_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.87945295496689304*Power(Mag12,7) + RzRbar3*(-4.3972647748344652*Power(Mag12,7) + RzRbar3*(-8.7945295496689304*Power(Mag12,7) + RzRbar3*(-8.7945295496689304*Power(Mag12,7) + RzRbar3*(-4.39726477483446521*Power(Mag12,7) - 0.879452954966893041*Power(Mag12,7)*RzRbar3)))))/Power(Mag30,5);
  }
  
  double D_6_neg5_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.50775240028974752*Power(Mag12,6) + RzRbar3*(5.0775240028974752*Power(Mag12,6) + RzRbar3*(15.2325720086924257*Power(Mag12,6) + RzRbar3*(20.3100960115899009*Power(Mag12,6) + RzRbar3*(12.6938100072436881*Power(Mag12,6) + 3.04651440173848514*Power(Mag12,6)*RzRbar3)))))/Power(Mag30,4);
  }
  
  double D_6_neg4_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.43301270189221932*Power(Mag12,5) + RzRbar3*(-1.0825317547305483*Power(Mag12,5) + RzRbar3*(-12.9903810567665797*Power(Mag12,5) + RzRbar3*(-28.145825622994256*Power(Mag12,5) + RzRbar3*(-23.8156986040720628*Power(Mag12,5) - 7.1447095812216188*Power(Mag12,5)*RzRbar3)))))/Power(Mag30,3);
  }
  
  double D_6_neg3_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.59292706128157112*Power(Mag12,4) + RzRbar3*(-3.5575623676894267*Power(Mag12,4) + RzRbar3*(1.1858541225631422*Power(Mag12,4) + RzRbar3*(23.717082451262845*Power(Mag12,4) + RzRbar3*(32.6109883704864119*Power(Mag12,4) + 13.0443953481945647*Power(Mag12,4)*RzRbar3)))))/Power(Mag30,2);
  }
  
  double D_6_neg2_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.197642353760523708*Power(Mag12,3) + RzRbar3*(3.35992001392890304*Power(Mag12,3) + RzRbar3*(10.6726871030682802*Power(Mag12,3) + RzRbar3*(-5.9292706128157112*Power(Mag12,3) + RzRbar3*(-32.6109883704864119*Power(Mag12,3) - 19.5665930222918471*Power(Mag12,3)*RzRbar3)))))/Mag30;
  }
  
  double D_6_neg1_1() {
    return 0.625*Power(Mag12,2) + RzRbar3*(1.25*Power(Mag12,2) + RzRbar3*(-11.25*Power(Mag12,2) + RzRbar3*(-15.*Power(Mag12,2) + RzRbar3*(20.625*Power(Mag12,2) + 24.75*Power(Mag12,2)*RzRbar3))));
  }
  
  double D_6_0_1() {
    return RzRbar3*(-4.05046293650491264*Mag12*Mag30 + Power(RzRbar3,2)*(24.3027776190294759*Mag12*Mag30 - 26.7330553809324235*Mag12*Mag30*Power(RzRbar3,2)));
  }
  
  double D_6_1_1() {
    return -0.625*Power(Mag30,2) + RzRbar3*(1.25*Power(Mag30,2) + RzRbar3*(11.25*Power(Mag30,2) + RzRbar3*(-15.*Power(Mag30,2) + RzRbar3*(-20.625*Power(Mag30,2) + 24.75*Power(Mag30,2)*RzRbar3))));
  }
  
  double D_6_2_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.197642353760523708*Power(Mag30,3) + RzRbar3*(3.35992001392890304*Power(Mag30,3) + RzRbar3*(-10.6726871030682802*Power(Mag30,3) + RzRbar3*(-5.9292706128157112*Power(Mag30,3) + RzRbar3*(32.6109883704864119*Power(Mag30,3) - 19.5665930222918471*Power(Mag30,3)*RzRbar3)))))/Mag12;
  }
  
  double D_6_3_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.59292706128157112*Power(Mag30,4) + RzRbar3*(-3.5575623676894267*Power(Mag30,4) + RzRbar3*(-1.1858541225631422*Power(Mag30,4) + RzRbar3*(23.717082451262845*Power(Mag30,4) + RzRbar3*(-32.6109883704864119*Power(Mag30,4) + 13.0443953481945647*Power(Mag30,4)*RzRbar3)))))/Power(Mag12,2);
  }
  
  double D_6_4_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.43301270189221932*Power(Mag30,5) + RzRbar3*(-1.0825317547305483*Power(Mag30,5) + RzRbar3*(12.9903810567665797*Power(Mag30,5) + RzRbar3*(-28.145825622994256*Power(Mag30,5) + RzRbar3*(23.8156986040720628*Power(Mag30,5) - 7.1447095812216188*Power(Mag30,5)*RzRbar3)))))/Power(Mag12,3);
  }
  
  double D_6_5_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.50775240028974752*Power(Mag30,6) + RzRbar3*(5.0775240028974752*Power(Mag30,6) + RzRbar3*(-15.2325720086924257*Power(Mag30,6) + RzRbar3*(20.3100960115899009*Power(Mag30,6) + RzRbar3*(-12.6938100072436881*Power(Mag30,6) + 3.04651440173848514*Power(Mag30,6)*RzRbar3)))))/Power(Mag12,4);
  }
  
  double D_6_6_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.87945295496689304*Power(Mag30,7) + RzRbar3*(-4.3972647748344652*Power(Mag30,7) + RzRbar3*(8.7945295496689304*Power(Mag30,7) + RzRbar3*(-8.7945295496689304*Power(Mag30,7) + RzRbar3*(4.39726477483446521*Power(Mag30,7) - 0.879452954966893041*Power(Mag30,7)*RzRbar3)))))/Power(Mag12,5);
  }
  
  double D_6_neg6_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.3905372163304368*Power(Mag12,8) + RzRbar3*(5.5621488653217472*Power(Mag12,8) + RzRbar3*(8.3432232979826208*Power(Mag12,8) + RzRbar3*(5.5621488653217472*Power(Mag12,8) + 1.3905372163304368*Power(Mag12,8)*RzRbar3))))/Power(Mag30,4);
  }
  
  double D_6_neg5_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.60565407233314113*Power(Mag12,7) + RzRbar3*(-9.6339244339988468*Power(Mag12,7) + RzRbar3*(-19.2678488679976935*Power(Mag12,7) + RzRbar3*(-16.0565407233314113*Power(Mag12,7) - 4.81696221699942338*Power(Mag12,7)*RzRbar3))))/Power(Mag30,3);
  }
  
  double D_6_neg4_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.34232659844072882*Power(Mag12,6) + RzRbar3*(8.2158383625774917*Power(Mag12,6) + RzRbar3*(26.701474678376848*Power(Mag12,6) + RzRbar3*(30.1247406627841362*Power(Mag12,6) + 11.2967777485440511*Power(Mag12,6)*RzRbar3))))/Power(Mag30,2);
  }
  
  double D_6_neg3_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.125*Power(Mag12,5) + RzRbar3*(-0.75*Power(Mag12,5) + RzRbar3*(-22.5*Power(Mag12,5) + RzRbar3*(-41.25*Power(Mag12,5) - 20.625*Power(Mag12,5)*RzRbar3))))/Mag30;
  }
  
  double D_6_neg2_2() {
    return -1.0625*Power(Mag12,4) + RzRbar3*(-6.75*Power(Mag12,4) + RzRbar3*(5.625*Power(Mag12,4) + RzRbar3*(41.25*Power(Mag12,4) + 30.9375*Power(Mag12,4)*RzRbar3)));
  }
  
  double D_6_neg1_2() {
    return -0.395284707521047416*Power(Mag12,3)*Mag30 + RzRbar3*(7.1151247353788535*Power(Mag12,3)*Mag30 + RzRbar3*(14.230249470757707*Power(Mag12,3)*Mag30 + RzRbar3*(-26.0887906963891295*Power(Mag12,3)*Mag30 - 39.1331860445836942*Power(Mag12,3)*Mag30*RzRbar3)));
  }
  
  double D_6_0_2() {
    return 1.2808688457449498*Power(Mag12,2)*Power(Mag30,2) + Power(RzRbar3,2)*(-23.0556392234090964*Power(Mag12,2)*Power(Mag30,2) + 42.2686719095833433*Power(Mag12,2)*Power(Mag30,2)*Power(RzRbar3,2));
  }
  
  double D_6_1_2() {
    return -0.395284707521047416*Mag12*Power(Mag30,3) + RzRbar3*(-7.1151247353788535*Mag12*Power(Mag30,3) + RzRbar3*(14.230249470757707*Mag12*Power(Mag30,3) + RzRbar3*(26.0887906963891295*Mag12*Power(Mag30,3) - 39.1331860445836942*Mag12*Power(Mag30,3)*RzRbar3)));
  }
  
  double D_6_2_2() {
    return -1.0625*Power(Mag30,4) + RzRbar3*(6.75*Power(Mag30,4) + RzRbar3*(5.625*Power(Mag30,4) + RzRbar3*(-41.25*Power(Mag30,4) + 30.9375*Power(Mag30,4)*RzRbar3)));
  }
  
  double D_6_3_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.125*Power(Mag30,5) + RzRbar3*(0.75*Power(Mag30,5) + RzRbar3*(-22.5*Power(Mag30,5) + RzRbar3*(41.25*Power(Mag30,5) - 20.625*Power(Mag30,5)*RzRbar3))))/Mag12;
  }
  
  double D_6_4_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.34232659844072882*Power(Mag30,6) + RzRbar3*(-8.2158383625774917*Power(Mag30,6) + RzRbar3*(26.701474678376848*Power(Mag30,6) + RzRbar3*(-30.1247406627841362*Power(Mag30,6) + 11.2967777485440511*Power(Mag30,6)*RzRbar3))))/Power(Mag12,2);
  }
  
  double D_6_5_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.60565407233314113*Power(Mag30,7) + RzRbar3*(9.6339244339988468*Power(Mag30,7) + RzRbar3*(-19.2678488679976935*Power(Mag30,7) + RzRbar3*(16.0565407233314113*Power(Mag30,7) - 4.81696221699942338*Power(Mag30,7)*RzRbar3))))/Power(Mag12,3);
  }
  
  double D_6_6_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.3905372163304368*Power(Mag30,8) + RzRbar3*(-5.5621488653217472*Power(Mag30,8) + RzRbar3*(8.3432232979826208*Power(Mag30,8) + RzRbar3*(-5.5621488653217472*Power(Mag30,8) + 1.3905372163304368*Power(Mag30,8)*RzRbar3))))/Power(Mag12,4);
  }
  
  double D_6_neg6_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.85404962177391574*Power(Mag12,9) + RzRbar3*(-5.5621488653217472*Power(Mag12,9) + RzRbar3*(-5.5621488653217472*Power(Mag12,9) - 1.85404962177391574*Power(Mag12,9)*RzRbar3)))/Power(Mag30,3);
  }
  
  double D_6_neg5_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (3.2113081446662823*Power(Mag12,8) + RzRbar3*(12.845232578665129*Power(Mag12,8) + RzRbar3*(16.0565407233314113*Power(Mag12,8) + 6.4226162893325645*Power(Mag12,8)*RzRbar3)))/Power(Mag30,2);
  }
  
  double D_6_neg4_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-2.73861278752583057*Power(Mag12,7) + RzRbar3*(-17.8009831189178987*Power(Mag12,7) + RzRbar3*(-30.1247406627841362*Power(Mag12,7) - 15.0623703313920681*Power(Mag12,7)*RzRbar3)))/Mag30;
  }
  
  double D_6_neg3_3() {
    return 0.25*Power(Mag12,6) + RzRbar3*(15.*Power(Mag12,6) + RzRbar3*(41.25*Power(Mag12,6) + 27.5*Power(Mag12,6)*RzRbar3));
  }
  
  double D_6_neg2_3() {
    return 2.25*Power(Mag12,5)*Mag30 + RzRbar3*(-3.75*Power(Mag12,5)*Mag30 + RzRbar3*(-41.25*Power(Mag12,5)*Mag30 - 41.25*Power(Mag12,5)*Mag30*RzRbar3));
  }
  
  double D_6_neg1_3() {
    return -2.3717082451262845*Power(Mag12,4)*Power(Mag30,2) + RzRbar3*(-9.486832980505138*Power(Mag12,4)*Power(Mag30,2) + RzRbar3*(26.0887906963891295*Power(Mag12,4)*Power(Mag30,2) + 52.177581392778259*Power(Mag12,4)*Power(Mag30,2)*RzRbar3));
  }
  
  double D_6_0_3() {
    return RzRbar3*(15.3704261489393976*Power(Mag12,3)*Power(Mag30,3) - 56.358229212777791*Power(Mag12,3)*Power(Mag30,3)*Power(RzRbar3,2));
  }
  
  double D_6_1_3() {
    return 2.3717082451262845*Power(Mag12,2)*Power(Mag30,4) + RzRbar3*(-9.486832980505138*Power(Mag12,2)*Power(Mag30,4) + RzRbar3*(-26.0887906963891295*Power(Mag12,2)*Power(Mag30,4) + 52.177581392778259*Power(Mag12,2)*Power(Mag30,4)*RzRbar3));
  }
  
  double D_6_2_3() {
    return -2.25*Mag12*Power(Mag30,5) + RzRbar3*(-3.75*Mag12*Power(Mag30,5) + RzRbar3*(41.25*Mag12*Power(Mag30,5) - 41.25*Mag12*Power(Mag30,5)*RzRbar3));
  }
  
  double D_6_3_3() {
    return -0.25*Power(Mag30,6) + RzRbar3*(15.*Power(Mag30,6) + RzRbar3*(-41.25*Power(Mag30,6) + 27.5*Power(Mag30,6)*RzRbar3));
  }
  
  double D_6_4_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.73861278752583057*Power(Mag30,7) + RzRbar3*(-17.8009831189178987*Power(Mag30,7) + RzRbar3*(30.1247406627841362*Power(Mag30,7) - 15.0623703313920681*Power(Mag30,7)*RzRbar3)))/Mag12;
  }
  
  double D_6_5_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-3.2113081446662823*Power(Mag30,8) + RzRbar3*(12.845232578665129*Power(Mag30,8) + RzRbar3*(-16.0565407233314113*Power(Mag30,8) + 6.4226162893325645*Power(Mag30,8)*RzRbar3)))/Power(Mag12,2);
  }
  
  double D_6_6_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.85404962177391574*Power(Mag30,9) + RzRbar3*(-5.5621488653217472*Power(Mag30,9) + RzRbar3*(5.5621488653217472*Power(Mag30,9) - 1.85404962177391574*Power(Mag30,9)*RzRbar3)))/Power(Mag12,3);
  }
  
  double D_6_neg6_4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.03100960115899009*Power(Mag12,10) + RzRbar3*(4.06201920231798018*Power(Mag12,10) + 2.03100960115899009*Power(Mag12,10)*RzRbar3))/Power(Mag30,2);
  }
  
  double D_6_neg5_4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-4.69041575982342955*Power(Mag12,9) + RzRbar3*(-11.7260393995585739*Power(Mag12,9) - 7.0356236397351443*Power(Mag12,9)*RzRbar3))/Mag30;
  }
  
  double D_6_neg4_4() {
    return 6.5*Power(Mag12,8) + RzRbar3*(22.*Power(Mag12,8) + 16.5*Power(Mag12,8)*RzRbar3);
  }
  
  double D_6_neg3_4() {
    return -5.4772255750516611*Power(Mag12,7)*Mag30 + RzRbar3*(-30.1247406627841362*Power(Mag12,7)*Mag30 - 30.1247406627841362*Power(Mag12,7)*Mag30*RzRbar3);
  }
  
  double D_6_neg2_4() {
    return 1.36930639376291528*Power(Mag12,6)*Power(Mag30,2) + RzRbar3*(30.1247406627841362*Power(Mag12,6)*Power(Mag30,2) + 45.1871109941762044*Power(Mag12,6)*Power(Mag30,2)*RzRbar3);
  }
  
  double D_6_neg1_4() {
    return 3.46410161513775459*Power(Mag12,5)*Power(Mag30,3) + RzRbar3*(-19.0525588832576502*Power(Mag12,5)*Power(Mag30,3) - 57.157676649772951*Power(Mag12,5)*Power(Mag30,3)*RzRbar3);
  }
  
  double D_6_0_4() {
    return -5.6124860801609121*Power(Mag12,4)*Power(Mag30,4) + 61.737346881770033*Power(Mag12,4)*Power(Mag30,4)*Power(RzRbar3,2);
  }
  
  double D_6_1_4() {
    return 3.46410161513775459*Power(Mag12,3)*Power(Mag30,5) + RzRbar3*(19.0525588832576502*Power(Mag12,3)*Power(Mag30,5) - 57.157676649772951*Power(Mag12,3)*Power(Mag30,5)*RzRbar3);
  }
  
  double D_6_2_4() {
    return 1.36930639376291528*Power(Mag12,2)*Power(Mag30,6) + RzRbar3*(-30.1247406627841362*Power(Mag12,2)*Power(Mag30,6) + 45.1871109941762044*Power(Mag12,2)*Power(Mag30,6)*RzRbar3);
  }
  
  double D_6_3_4() {
    return -5.4772255750516611*Mag12*Power(Mag30,7) + RzRbar3*(30.1247406627841362*Mag12*Power(Mag30,7) - 30.1247406627841362*Mag12*Power(Mag30,7)*RzRbar3);
  }
  
  double D_6_4_4() {
    return 6.5*Power(Mag30,8) + RzRbar3*(-22.*Power(Mag30,8) + 16.5*Power(Mag30,8)*RzRbar3);
  }
  
  double D_6_5_4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-4.69041575982342955*Power(Mag30,9) + RzRbar3*(11.7260393995585739*Power(Mag30,9) - 7.0356236397351443*Power(Mag30,9)*RzRbar3))/Mag12;
  }
  
  double D_6_6_4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (2.03100960115899009*Power(Mag30,10) + RzRbar3*(-4.06201920231798018*Power(Mag30,10) + 2.03100960115899009*Power(Mag30,10)*RzRbar3))/Power(Mag12,2);
  }
  
  double D_6_neg6_5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.73205080756887729*Power(Mag12,11) - 1.73205080756887729*Power(Mag12,11)*RzRbar3)/Mag30;
  }
  
  double D_6_neg5_5() {
    return 5.*Power(Mag12,10) + 6.*Power(Mag12,10)*RzRbar3;
  }
  
  double D_6_neg4_5() {
    return -9.3808315196468591*Power(Mag12,9)*Mag30 - 14.0712472794702887*Power(Mag12,9)*Mag30*RzRbar3;
  }
  
  double D_6_neg3_5() {
    return 12.845232578665129*Power(Mag12,8)*Power(Mag30,2) + 25.690465157330258*Power(Mag12,8)*Power(Mag30,2)*RzRbar3;
  }
  
  double D_6_neg2_5() {
    return -12.845232578665129*Power(Mag12,7)*Power(Mag30,3) - 38.5356977359953871*Power(Mag12,7)*Power(Mag30,3)*RzRbar3;
  }
  
  double D_6_neg1_5() {
    return 8.1240384046359604*Power(Mag12,6)*Power(Mag30,4) + 48.7442304278157622*Power(Mag12,6)*Power(Mag30,4)*RzRbar3;
  }
  
  double D_6_0_5() {
    return -52.6497863243527324*Power(Mag12,5)*Power(Mag30,5)*RzRbar3;
  }
  
  double D_6_1_5() {
    return -8.1240384046359604*Power(Mag12,4)*Power(Mag30,6) + 48.7442304278157622*Power(Mag12,4)*Power(Mag30,6)*RzRbar3;
  }
  
  double D_6_2_5() {
    return 12.845232578665129*Power(Mag12,3)*Power(Mag30,7) - 38.5356977359953871*Power(Mag12,3)*Power(Mag30,7)*RzRbar3;
  }
  
  double D_6_3_5() {
    return -12.845232578665129*Power(Mag12,2)*Power(Mag30,8) + 25.690465157330258*Power(Mag12,2)*Power(Mag30,8)*RzRbar3;
  }
  
  double D_6_4_5() {
    return 9.3808315196468591*Mag12*Power(Mag30,9) - 14.0712472794702887*Mag12*Power(Mag30,9)*RzRbar3;
  }
  
  double D_6_5_5() {
    return -5.*Power(Mag30,10) + 6.*Power(Mag30,10)*RzRbar3;
  }
  
  double D_6_6_5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.73205080756887729*Power(Mag30,11) - 1.73205080756887729*Power(Mag30,11)*RzRbar3)/Mag12;
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
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0009765625 + RzRbar3*(0.009765625 + RzRbar3*(0.0439453125 + RzRbar3*(0.1171875 + RzRbar3*(0.205078125 + RzRbar3*(0.24609375 + RzRbar3*(0.205078125 + RzRbar3*(0.1171875 + RzRbar3*(0.0439453125 + (0.009765625 + 0.0009765625*RzRbar3)*RzRbar3)))))))))/Power(Mag30,10);
  }
  
  double D_5_neg4_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0030881617775081829 + RzRbar3*(0.024705294220065464 + RzRbar3*(0.08338036799272094 + RzRbar3*(0.14823176532039278 + RzRbar3*(0.12970279465534368 + RzRbar3*(0.e-17 + RzRbar3*(-0.12970279465534368 + RzRbar3*(-0.14823176532039278 + RzRbar3*(-0.083380367992720939 + (-0.0247052942200654635 - 0.00308816177750818294*RzRbar3)*RzRbar3)))))))))/(Mag12*Power(Mag30,9));
  }
  
  double D_5_neg3_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0065509804028314151 + RzRbar3*(0.039305882416988491 + RzRbar3*(0.0851627452368084 + RzRbar3*(0.05240784322265132 + RzRbar3*(-0.09171372563963981 + RzRbar3*(-0.18342745127927962 + RzRbar3*(-0.09171372563963981 + RzRbar3*(0.05240784322265132 + RzRbar3*(0.085162745236808397 + (0.039305882416988491 + 0.00655098040283141513*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,2)*Power(Mag30,8));
  }
  
  double D_5_neg2_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.010697706201272776 + RzRbar3*(0.0427908248050911 + RzRbar3*(0.03209311860381833 + RzRbar3*(-0.0855816496101822 + RzRbar3*(-0.1497678868178189 + RzRbar3*(0.e-16 + RzRbar3*(0.1497678868178189 + RzRbar3*(0.08558164961018221 + RzRbar3*(-0.03209311860381833 + (-0.042790824805091103 - 0.0106977062012727757*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,3)*Power(Mag30,7));
  }
  
  double D_5_neg1_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.014151735103700624 + RzRbar3*(0.02830347020740125 + RzRbar3*(-0.04245520531110187 + RzRbar3*(-0.113213880829605 + RzRbar3*(0.0283034702074012 + RzRbar3*(0.1698208212444075 + RzRbar3*(0.0283034702074012 + RzRbar3*(-0.11321388082960499 + RzRbar3*(-0.04245520531110187 + (0.028303470207401247 + 0.0141517351037006236*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,4)*Power(Mag30,6));
  }
  
  double D_5_0_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0155024490882690855 + Power(RzRbar3,2)*(-0.077512245441345427 + Power(RzRbar3,2)*(0.155024490882690855 + Power(RzRbar3,2)*(-0.155024490882690855 + Power(RzRbar3,2)*(0.077512245441345427 - 0.0155024490882690855*Power(RzRbar3,2))))))/(Power(Mag12,5)*Power(Mag30,5));
  }
  
  double D_5_1_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.014151735103700624 + RzRbar3*(-0.02830347020740125 + RzRbar3*(-0.04245520531110187 + RzRbar3*(0.113213880829605 + RzRbar3*(0.0283034702074012 + RzRbar3*(-0.1698208212444075 + RzRbar3*(0.0283034702074012 + RzRbar3*(0.11321388082960499 + RzRbar3*(-0.04245520531110187 + (-0.028303470207401247 + 0.0141517351037006236*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,6)*Power(Mag30,4));
  }
  
  double D_5_2_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.010697706201272776 + RzRbar3*(-0.0427908248050911 + RzRbar3*(0.03209311860381833 + RzRbar3*(0.0855816496101822 + RzRbar3*(-0.1497678868178189 + RzRbar3*(0.e-16 + RzRbar3*(0.1497678868178189 + RzRbar3*(-0.08558164961018221 + RzRbar3*(-0.03209311860381833 + (0.042790824805091103 - 0.0106977062012727757*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,7)*Power(Mag30,3));
  }
  
  double D_5_3_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0065509804028314151 + RzRbar3*(-0.039305882416988491 + RzRbar3*(0.0851627452368084 + RzRbar3*(-0.05240784322265132 + RzRbar3*(-0.09171372563963981 + RzRbar3*(0.18342745127927962 + RzRbar3*(-0.09171372563963981 + RzRbar3*(-0.05240784322265132 + RzRbar3*(0.085162745236808397 + (-0.039305882416988491 + 0.00655098040283141513*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,8)*Power(Mag30,2));
  }
  
  double D_5_4_neg5() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0030881617775081829 + RzRbar3*(-0.024705294220065464 + RzRbar3*(0.08338036799272094 + RzRbar3*(-0.14823176532039278 + RzRbar3*(0.12970279465534368 + RzRbar3*(0.e-17 + RzRbar3*(-0.12970279465534368 + RzRbar3*(0.14823176532039278 + RzRbar3*(-0.083380367992720939 + (0.0247052942200654635 - 0.00308816177750818294*RzRbar3)*RzRbar3)))))))))/(Power(Mag12,9)*Mag30);
  }
  
  double D_5_5_neg5() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0009765625 + RzRbar3*(-0.009765625 + RzRbar3*(0.0439453125 + RzRbar3*(-0.1171875 + RzRbar3*(0.205078125 + RzRbar3*(-0.24609375 + RzRbar3*(0.205078125 + RzRbar3*(-0.1171875 + RzRbar3*(0.0439453125 + (-0.009765625 + 0.0009765625*RzRbar3)*RzRbar3)))))))))/Power(Mag12,10);
  }
  
  double D_5_neg5_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0061763235550163659*Mag12 + RzRbar3*(-0.055586911995147293*Mag12 + RzRbar3*(-0.22234764798058917*Mag12 + RzRbar3*(-0.51881117862137473*Mag12 + RzRbar3*(-0.7782167679320621*Mag12 + RzRbar3*(-0.7782167679320621*Mag12 + RzRbar3*(-0.51881117862137473*Mag12 + RzRbar3*(-0.222347647980589172*Mag12 + RzRbar3*(-0.055586911995147293*Mag12 - 0.00617632355501636588*Mag12*RzRbar3)))))))))/Power(Mag30,9);
  }
  
  double D_5_neg4_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.015625 + RzRbar3*(-0.10546875 + RzRbar3*(-0.28125 + RzRbar3*(-0.328125 + RzRbar3*(0.e-16 + RzRbar3*(0.4921875 + RzRbar3*(0.65625 + RzRbar3*(0.421875 + (0.140625 + 0.01953125*RzRbar3)*RzRbar3))))))))/Power(Mag30,8);
  }
  
  double D_5_neg3_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.024859222776089561 + RzRbar3*(-0.1077232986963881 + RzRbar3*(-0.09943689110435825 + RzRbar3*(0.2320194125768359 + RzRbar3*(0.5800485314420898 + RzRbar3*(0.3480291188652539 + RzRbar3*(-0.2320194125768359 + RzRbar3*(-0.4308931947855524 + (-0.22373300498480605 - 0.041432037960149269*RzRbar3)*RzRbar3))))))))/(Mag12*Power(Mag30,7));
  }
  
  double D_5_neg2_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.027063293868263708 + RzRbar3*(-0.04059494080239556 + RzRbar3*(0.1623797632095822 + RzRbar3*(0.3788861141556919 + RzRbar3*(0.e-16 + RzRbar3*(-0.5683291712335379 + RzRbar3*(-0.3788861141556919 + RzRbar3*(0.16237976320958225 + (0.24356964481437337 + 0.067658234670659269*RzRbar3)*RzRbar3))))))))/(Power(Mag12,2)*Power(Mag30,6));
  }
  
  double D_5_neg1_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.01790068630842125 + RzRbar3*(0.05370205892526375 + RzRbar3*(0.214808235701055 + RzRbar3*(-0.071602745233685 + RzRbar3*(-0.5370205892526375 + RzRbar3*(-0.1074041178505275 + RzRbar3*(0.501219216635795 + RzRbar3*(0.214808235701055 + (-0.16110617677579125 - 0.08950343154210625*RzRbar3)*RzRbar3))))))))/(Power(Mag12,3)*Power(Mag30,5));
  }
  
  double D_5_0_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(0.098046096859461978 + Power(RzRbar3,2)*(-0.39218438743784791 + Power(RzRbar3,2)*(0.58827658115677187 + Power(RzRbar3,2)*(-0.392184387437847913 + 0.0980460968594619783*Power(RzRbar3,2))))))/(Power(Mag12,4)*Power(Mag30,4));
  }
  
  double D_5_1_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.01790068630842125 + RzRbar3*(0.05370205892526375 + RzRbar3*(-0.214808235701055 + RzRbar3*(-0.071602745233685 + RzRbar3*(0.5370205892526375 + RzRbar3*(-0.1074041178505275 + RzRbar3*(-0.501219216635795 + RzRbar3*(0.214808235701055 + (0.16110617677579125 - 0.08950343154210625*RzRbar3)*RzRbar3))))))))/(Power(Mag12,5)*Power(Mag30,3));
  }
  
  double D_5_2_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.027063293868263708 + RzRbar3*(-0.04059494080239556 + RzRbar3*(-0.1623797632095822 + RzRbar3*(0.3788861141556919 + RzRbar3*(0.e-16 + RzRbar3*(-0.5683291712335379 + RzRbar3*(0.3788861141556919 + RzRbar3*(0.16237976320958225 + (-0.24356964481437337 + 0.067658234670659269*RzRbar3)*RzRbar3))))))))/(Power(Mag12,6)*Power(Mag30,2));
  }
  
  double D_5_3_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.024859222776089561 + RzRbar3*(-0.1077232986963881 + RzRbar3*(0.09943689110435825 + RzRbar3*(0.2320194125768359 + RzRbar3*(-0.5800485314420898 + RzRbar3*(0.3480291188652539 + RzRbar3*(0.2320194125768359 + RzRbar3*(-0.4308931947855524 + (0.22373300498480605 - 0.041432037960149269*RzRbar3)*RzRbar3))))))))/(Power(Mag12,7)*Mag30);
  }
  
  double D_5_4_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.015625 + RzRbar3*(-0.10546875 + RzRbar3*(0.28125 + RzRbar3*(-0.328125 + RzRbar3*(0.e-16 + RzRbar3*(0.4921875 + RzRbar3*(-0.65625 + RzRbar3*(0.421875 + (-0.140625 + 0.01953125*RzRbar3)*RzRbar3))))))))/Power(Mag12,8);
  }
  
  double D_5_5_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0061763235550163659*Mag30 + RzRbar3*(-0.055586911995147293*Mag30 + RzRbar3*(0.22234764798058917*Mag30 + RzRbar3*(-0.51881117862137473*Mag30 + RzRbar3*(0.7782167679320621*Mag30 + RzRbar3*(-0.7782167679320621*Mag30 + RzRbar3*(0.51881117862137473*Mag30 + RzRbar3*(-0.222347647980589172*Mag30 + RzRbar3*(0.055586911995147293*Mag30 - 0.00617632355501636588*Mag30*RzRbar3)))))))))/Power(Mag12,9);
  }
  
  double D_5_neg5_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.026203921611325661*Power(Mag12,2) + RzRbar3*(0.20963137289060528*Power(Mag12,2) + RzRbar3*(0.73370980511711849*Power(Mag12,2) + RzRbar3*(1.46741961023423699*Power(Mag12,2) + RzRbar3*(1.83427451279279624*Power(Mag12,2) + RzRbar3*(1.46741961023423699*Power(Mag12,2) + RzRbar3*(0.73370980511711849*Power(Mag12,2) + RzRbar3*(0.209631372890605284*Power(Mag12,2) + 0.0262039216113256605*Power(Mag12,2)*RzRbar3))))))))/Power(Mag30,8);
  }
  
  double D_5_neg4_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.049718445552179123*Mag12 + RzRbar3*(0.26516504294495532*Mag12 + RzRbar3*(0.4640388251536718*Mag12 + RzRbar3*(0.e-16*Mag12 + RzRbar3*(-1.1600970628841795*Mag12 + RzRbar3*(-1.8561553006146873*Mag12 + RzRbar3*(-1.39211647546101544*Mag12 + RzRbar3*(-0.53033008588991064*Mag12 - 0.082864075920298538*Mag12*RzRbar3))))))))/Power(Mag30,7);
  }
  
  double D_5_neg3_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.05078125 + RzRbar3*(0.09375 + RzRbar3*(-0.328125 + RzRbar3*(-1.09375 + RzRbar3*(-0.8203125 + RzRbar3*(0.65625 + RzRbar3*(1.421875 + (0.84375 + 0.17578125*RzRbar3)*RzRbar3)))))))/Power(Mag30,6);
  }
  
  double D_5_neg2_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.019136638615493579 + RzRbar3*(-0.15309310892394863 + RzRbar3*(-0.5358258812338202 + RzRbar3*(0.e-16 + RzRbar3*(1.3395647030845505 + RzRbar3*(1.0716517624676404 + RzRbar3*(-0.5358258812338202 + (-0.91855865354369179 - 0.287049579232403683*RzRbar3)*RzRbar3)))))))/(Mag12*Power(Mag30,5));
  }
  
  double D_5_neg1_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.025315393353155704 + RzRbar3*(-0.20252314682524563 + RzRbar3*(0.1012615734126228 + RzRbar3*(1.0126157341262282 + RzRbar3*(0.253153933531557 + RzRbar3*(-1.4176620277767194 + RzRbar3*(-0.7088310138883597 + (0.6075694404757369 + 0.37973090029733556*RzRbar3)*RzRbar3)))))))/(Power(Mag12,2)*Power(Mag30,4));
  }
  
  double D_5_0_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.04621937330546575 + Power(RzRbar3,2)*(0.554632479665589 + Power(RzRbar3,2)*(-1.38658119916397251 + Power(RzRbar3,2)*(1.29414245255304101 - 0.415974359749191753*Power(RzRbar3,2)))))/(Power(Mag12,3)*Power(Mag30,3));
  }
  
  double D_5_1_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.025315393353155704 + RzRbar3*(0.20252314682524563 + RzRbar3*(0.1012615734126228 + RzRbar3*(-1.0126157341262282 + RzRbar3*(0.253153933531557 + RzRbar3*(1.4176620277767194 + RzRbar3*(-0.7088310138883597 + (-0.6075694404757369 + 0.37973090029733556*RzRbar3)*RzRbar3)))))))/(Power(Mag12,4)*Power(Mag30,2));
  }
  
  double D_5_2_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.019136638615493579 + RzRbar3*(0.15309310892394863 + RzRbar3*(-0.5358258812338202 + RzRbar3*(0.e-16 + RzRbar3*(1.3395647030845505 + RzRbar3*(-1.0716517624676404 + RzRbar3*(-0.5358258812338202 + (0.91855865354369179 - 0.287049579232403683*RzRbar3)*RzRbar3)))))))/(Power(Mag12,5)*Mag30);
  }
  
  double D_5_3_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.05078125 + RzRbar3*(-0.09375 + RzRbar3*(-0.328125 + RzRbar3*(1.09375 + RzRbar3*(-0.8203125 + RzRbar3*(-0.65625 + RzRbar3*(1.421875 + (-0.84375 + 0.17578125*RzRbar3)*RzRbar3)))))))/Power(Mag12,6);
  }
  
  double D_5_4_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.049718445552179123*Mag30 + RzRbar3*(-0.26516504294495532*Mag30 + RzRbar3*(0.4640388251536718*Mag30 + RzRbar3*(0.e-16*Mag30 + RzRbar3*(-1.1600970628841795*Mag30 + RzRbar3*(1.8561553006146873*Mag30 + RzRbar3*(-1.39211647546101544*Mag30 + RzRbar3*(0.53033008588991064*Mag30 - 0.082864075920298538*Mag30*RzRbar3))))))))/Power(Mag12,7);
  }
  
  double D_5_5_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.026203921611325661*Power(Mag30,2) + RzRbar3*(-0.20963137289060528*Power(Mag30,2) + RzRbar3*(0.73370980511711849*Power(Mag30,2) + RzRbar3*(-1.46741961023423699*Power(Mag30,2) + RzRbar3*(1.83427451279279624*Power(Mag30,2) + RzRbar3*(-1.46741961023423699*Power(Mag30,2) + RzRbar3*(0.73370980511711849*Power(Mag30,2) + RzRbar3*(-0.209631372890605284*Power(Mag30,2) + 0.0262039216113256605*Power(Mag30,2)*RzRbar3))))))))/Power(Mag12,8);
  }
  
  double D_5_neg5_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.085581649610182205*Power(Mag12,3) + RzRbar3*(-0.59907154727127544*Power(Mag12,3) + RzRbar3*(-1.7972146418138263*Power(Mag12,3) + RzRbar3*(-2.9953577363563772*Power(Mag12,3) + RzRbar3*(-2.9953577363563772*Power(Mag12,3) + RzRbar3*(-1.79721464181382631*Power(Mag12,3) + RzRbar3*(-0.59907154727127544*Power(Mag12,3) - 0.0855816496101822052*Power(Mag12,3)*RzRbar3)))))))/Power(Mag30,7);
  }
  
  double D_5_neg4_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.108253175473054831*Power(Mag12,2) + RzRbar3*(-0.37888611415569191*Power(Mag12,2) + RzRbar3*(0.e-16*Power(Mag12,2) + RzRbar3*(1.8944305707784595*Power(Mag12,2) + RzRbar3*(3.7888611415569191*Power(Mag12,2) + RzRbar3*(3.4099750274012272*Power(Mag12,2) + RzRbar3*(1.51554445662276763*Power(Mag12,2) + 0.270632938682637077*Power(Mag12,2)*RzRbar3)))))))/Power(Mag30,6);
  }
  
  double D_5_neg3_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.038273277230987158*Mag12 + RzRbar3*(0.2679129406169101*Mag12 + RzRbar3*(1.3395647030845505*Mag12 + RzRbar3*(1.3395647030845505*Mag12 + RzRbar3*(-1.3395647030845505*Mag12 + RzRbar3*(-3.4828682280198314*Mag12 + RzRbar3*(-2.41121646555219094*Mag12 - 0.57409915846480737*Mag12*RzRbar3)))))))/Power(Mag30,5);
  }
  
  double D_5_neg2_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0625 + RzRbar3*(0.4375 + RzRbar3*(0.e-16 + RzRbar3*(-2.1875 + RzRbar3*(-2.1875 + RzRbar3*(1.3125 + (2.625 + 0.9375*RzRbar3)*RzRbar3))))))/Power(Mag30,4);
  }
  
  double D_5_neg1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.082679728470768456 + RzRbar3*(-0.08267972847076846 + RzRbar3*(-1.24019592706152684 + RzRbar3*(-0.4133986423538423 + RzRbar3*(2.893790496476896 + RzRbar3*(1.7362742978861376 + (-1.7362742978861376 - 1.24019592706152684*RzRbar3)*RzRbar3))))))/(Mag12*Power(Mag30,3));
  }
  
  double D_5_0_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-0.45285552331841996 + Power(RzRbar3,2)*(2.26427761659209978 + Power(RzRbar3,2)*(-3.16998866322893969 + 1.35856656995525987*Power(RzRbar3,2)))))/(Power(Mag12,2)*Power(Mag30,2));
  }
  
  double D_5_1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.082679728470768456 + RzRbar3*(-0.08267972847076846 + RzRbar3*(1.24019592706152684 + RzRbar3*(-0.4133986423538423 + RzRbar3*(-2.893790496476896 + RzRbar3*(1.7362742978861376 + (1.7362742978861376 - 1.24019592706152684*RzRbar3)*RzRbar3))))))/(Power(Mag12,3)*Mag30);
  }
  
  double D_5_2_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0625 + RzRbar3*(0.4375 + RzRbar3*(0.e-16 + RzRbar3*(-2.1875 + RzRbar3*(2.1875 + RzRbar3*(1.3125 + (-2.625 + 0.9375*RzRbar3)*RzRbar3))))))/Power(Mag12,4);
  }
  
  double D_5_3_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.038273277230987158*Mag30 + RzRbar3*(0.2679129406169101*Mag30 + RzRbar3*(-1.3395647030845505*Mag30 + RzRbar3*(1.3395647030845505*Mag30 + RzRbar3*(1.3395647030845505*Mag30 + RzRbar3*(-3.4828682280198314*Mag30 + RzRbar3*(2.41121646555219094*Mag30 - 0.57409915846480737*Mag30*RzRbar3)))))))/Power(Mag12,5);
  }
  
  double D_5_4_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.108253175473054831*Power(Mag30,2) + RzRbar3*(-0.37888611415569191*Power(Mag30,2) + RzRbar3*(0.e-16*Power(Mag30,2) + RzRbar3*(1.8944305707784595*Power(Mag30,2) + RzRbar3*(-3.7888611415569191*Power(Mag30,2) + RzRbar3*(3.4099750274012272*Power(Mag30,2) + RzRbar3*(-1.51554445662276763*Power(Mag30,2) + 0.270632938682637077*Power(Mag30,2)*RzRbar3)))))))/Power(Mag12,6);
  }
  
  double D_5_5_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.085581649610182205*Power(Mag30,3) + RzRbar3*(-0.59907154727127544*Power(Mag30,3) + RzRbar3*(1.7972146418138263*Power(Mag30,3) + RzRbar3*(-2.9953577363563772*Power(Mag30,3) + RzRbar3*(2.9953577363563772*Power(Mag30,3) + RzRbar3*(-1.79721464181382631*Power(Mag30,3) + RzRbar3*(0.59907154727127544*Power(Mag30,3) - 0.0855816496101822052*Power(Mag30,3)*RzRbar3)))))))/Power(Mag12,7);
  }
  
  double D_5_neg5_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.22642776165920998*Power(Mag12,4) + RzRbar3*(1.35856656995525987*Power(Mag12,4) + RzRbar3*(3.3964164248881497*Power(Mag12,4) + RzRbar3*(4.5285552331841996*Power(Mag12,4) + RzRbar3*(3.3964164248881497*Power(Mag12,4) + RzRbar3*(1.35856656995525987*Power(Mag12,4) + 0.226427761659209978*Power(Mag12,4)*RzRbar3))))))/Power(Mag30,6);
  }
  
  double D_5_neg4_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.14320549046737*Power(Mag12,3) + RzRbar3*(0.e-17*Power(Mag12,3) + RzRbar3*(-2.14808235701055*Power(Mag12,3) + RzRbar3*(-5.7282196186948*Power(Mag12,3) + RzRbar3*(-6.44424707103165*Power(Mag12,3) + RzRbar3*(-3.43693177121688*Power(Mag12,3) - 0.71602745233685*Power(Mag12,3)*RzRbar3))))))/Power(Mag30,5);
  }
  
  double D_5_neg3_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.101261573412622816*Power(Mag12,2) + RzRbar3*(-1.01261573412622816*Power(Mag12,2) + RzRbar3*(-1.5189236011893422*Power(Mag12,2) + RzRbar3*(2.0252314682524563*Power(Mag12,2) + RzRbar3*(6.582002271820483*Power(Mag12,2) + RzRbar3*(5.4681249642816321*Power(Mag12,2) + 1.51892360118934224*Power(Mag12,2)*RzRbar3))))))/Power(Mag30,4);
  }
  
  double D_5_neg2_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.165359456941536912*Mag12 + RzRbar3*(0.e-17*Mag12 + RzRbar3*(2.4803918541230537*Mag12 + RzRbar3*(3.3071891388307382*Mag12 + RzRbar3*(-2.4803918541230537*Mag12 + RzRbar3*(-5.9529404498953288*Mag12 - 2.48039185412305368*Mag12*RzRbar3))))))/Power(Mag30,3);
  }
  
  double D_5_neg1_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.03125 + RzRbar3*(0.9375 + RzRbar3*(0.46875 + RzRbar3*(-4.375 + RzRbar3*(-3.28125 + RzRbar3*(3.9375 + 3.28125*RzRbar3))))))/Power(Mag30,2);
  }
  
  double D_5_0_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.17116329922036441 + Power(RzRbar3,2)*(-2.56744948830546616 + Power(RzRbar3,2)*(5.9907154727127544 - 3.59442928362765262*Power(RzRbar3,2))))/(Mag12*Mag30);
  }
  
  double D_5_1_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.03125 + RzRbar3*(-0.9375 + RzRbar3*(0.46875 + RzRbar3*(4.375 + RzRbar3*(-3.28125 + RzRbar3*(-3.9375 + 3.28125*RzRbar3))))))/Power(Mag12,2);
  }
  
  double D_5_2_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.165359456941536912*Mag30 + RzRbar3*(0.e-17*Mag30 + RzRbar3*(2.4803918541230537*Mag30 + RzRbar3*(-3.3071891388307382*Mag30 + RzRbar3*(-2.4803918541230537*Mag30 + RzRbar3*(5.9529404498953288*Mag30 - 2.48039185412305368*Mag30*RzRbar3))))))/Power(Mag12,3);
  }
  
  double D_5_3_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.101261573412622816*Power(Mag30,2) + RzRbar3*(1.01261573412622816*Power(Mag30,2) + RzRbar3*(-1.5189236011893422*Power(Mag30,2) + RzRbar3*(-2.0252314682524563*Power(Mag30,2) + RzRbar3*(6.582002271820483*Power(Mag30,2) + RzRbar3*(-5.4681249642816321*Power(Mag30,2) + 1.51892360118934224*Power(Mag30,2)*RzRbar3))))))/Power(Mag12,4);
  }
  
  double D_5_4_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.14320549046737*Power(Mag30,3) + RzRbar3*(0.e-17*Power(Mag30,3) + RzRbar3*(-2.14808235701055*Power(Mag30,3) + RzRbar3*(5.7282196186948*Power(Mag30,3) + RzRbar3*(-6.44424707103165*Power(Mag30,3) + RzRbar3*(3.43693177121688*Power(Mag30,3) - 0.71602745233685*Power(Mag30,3)*RzRbar3))))))/Power(Mag12,5);
  }
  
  double D_5_5_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.22642776165920998*Power(Mag30,4) + RzRbar3*(-1.35856656995525987*Power(Mag30,4) + RzRbar3*(3.3964164248881497*Power(Mag30,4) + RzRbar3*(-4.5285552331841996*Power(Mag30,4) + RzRbar3*(3.3964164248881497*Power(Mag30,4) + RzRbar3*(-1.35856656995525987*Power(Mag30,4) + 0.226427761659209978*Power(Mag30,4)*RzRbar3))))))/Power(Mag12,6);
  }
  
  double D_5_neg5_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.49607837082461074*Power(Mag12,5) + RzRbar3*(-2.4803918541230537*Power(Mag12,5) + RzRbar3*(-4.9607837082461074*Power(Mag12,5) + RzRbar3*(-4.9607837082461074*Power(Mag12,5) + RzRbar3*(-2.48039185412305368*Power(Mag12,5) - 0.496078370824610736*Power(Mag12,5)*RzRbar3)))))/Power(Mag30,5);
  }
  
  double D_5_neg4_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(1.56873754975139165*Power(Mag12,4) + RzRbar3*(6.2749501990055666*Power(Mag12,4) + RzRbar3*(9.4124252985083499*Power(Mag12,4) + RzRbar3*(6.2749501990055666*Power(Mag12,4) + 1.56873754975139165*Power(Mag12,4)*RzRbar3)))))/Power(Mag30,4);
  }
  
  double D_5_neg3_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.369754986443726*Power(Mag12,3) + RzRbar3*(1.10926495933117801*Power(Mag12,3) + RzRbar3*(-2.218529918662356*Power(Mag12,3) + RzRbar3*(-9.6136296475368761*Power(Mag12,3) + RzRbar3*(-9.9833846339806021*Power(Mag12,3) - 3.32779487799353402*Power(Mag12,3)*RzRbar3)))))/Power(Mag30,3);
  }
  
  double D_5_neg2_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-1.81142209327367982*Power(Mag12,2) + RzRbar3*(-3.6228441865473596*Power(Mag12,2) + RzRbar3*(3.6228441865473596*Power(Mag12,2) + RzRbar3*(10.8685325596420789*Power(Mag12,2) + 5.4342662798210395*Power(Mag12,2)*RzRbar3)))))/Power(Mag30,2);
  }
  
  double D_5_neg1_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.342326598440728821*Mag12 + RzRbar3*(-0.342326598440728821*Mag12 + RzRbar3*(4.79257237817020349*Mag12 + RzRbar3*(4.79257237817020349*Mag12 + RzRbar3*(-7.1888585672553052*Mag12 - 7.1888585672553052*Mag12*RzRbar3)))))/Mag30;
  }
  
  double D_5_0_0() {
    return RzRbar3*(1.875 + Power(RzRbar3,2)*(-8.75 + 7.875*Power(RzRbar3,2)));
  }
  
  double D_5_1_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.342326598440728821*Mag30 + RzRbar3*(-0.342326598440728821*Mag30 + RzRbar3*(-4.79257237817020349*Mag30 + RzRbar3*(4.79257237817020349*Mag30 + RzRbar3*(7.1888585672553052*Mag30 - 7.1888585672553052*Mag30*RzRbar3)))))/Mag12;
  }
  
  double D_5_2_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-1.81142209327367982*Power(Mag30,2) + RzRbar3*(3.6228441865473596*Power(Mag30,2) + RzRbar3*(3.6228441865473596*Power(Mag30,2) + RzRbar3*(-10.8685325596420789*Power(Mag30,2) + 5.4342662798210395*Power(Mag30,2)*RzRbar3)))))/Power(Mag12,2);
  }
  
  double D_5_3_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.369754986443726*Power(Mag30,3) + RzRbar3*(1.10926495933117801*Power(Mag30,3) + RzRbar3*(2.218529918662356*Power(Mag30,3) + RzRbar3*(-9.6136296475368761*Power(Mag30,3) + RzRbar3*(9.9833846339806021*Power(Mag30,3) - 3.32779487799353402*Power(Mag30,3)*RzRbar3)))))/Power(Mag12,3);
  }
  
  double D_5_4_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(1.56873754975139165*Power(Mag30,4) + RzRbar3*(-6.2749501990055666*Power(Mag30,4) + RzRbar3*(9.4124252985083499*Power(Mag30,4) + RzRbar3*(-6.2749501990055666*Power(Mag30,4) + 1.56873754975139165*Power(Mag30,4)*RzRbar3)))))/Power(Mag12,4);
  }
  
  double D_5_5_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.49607837082461074*Power(Mag30,5) + RzRbar3*(-2.4803918541230537*Power(Mag30,5) + RzRbar3*(4.9607837082461074*Power(Mag30,5) + RzRbar3*(-4.9607837082461074*Power(Mag30,5) + RzRbar3*(2.48039185412305368*Power(Mag30,5) - 0.496078370824610736*Power(Mag30,5)*RzRbar3)))))/Power(Mag12,5);
  }
  
  double D_5_neg5_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.90571104663683991*Power(Mag12,6) + RzRbar3*(3.6228441865473596*Power(Mag12,6) + RzRbar3*(5.4342662798210395*Power(Mag12,6) + RzRbar3*(3.62284418654735964*Power(Mag12,6) + 0.905711046636839911*Power(Mag12,6)*RzRbar3))))/Power(Mag30,4);
  }
  
  double D_5_neg4_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.57282196186948*Power(Mag12,5) + RzRbar3*(-4.58257569495584*Power(Mag12,5) + RzRbar3*(-10.31079531365064*Power(Mag12,5) + RzRbar3*(-9.16515138991168*Power(Mag12,5) - 2.8641098093474*Power(Mag12,5)*RzRbar3))))/Power(Mag30,3);
  }
  
  double D_5_neg3_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.40504629365049126*Power(Mag12,4) + RzRbar3*(1.6201851746019651*Power(Mag12,4) + RzRbar3*(10.5312036349127729*Power(Mag12,4) + RzRbar3*(14.5816665714176855*Power(Mag12,4) + 6.075694404757369*Power(Mag12,4)*RzRbar3))))/Power(Mag30,2);
  }
  
  double D_5_neg2_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.66143782776614765*Power(Mag12,3) + RzRbar3*(2.64575131106459059*Power(Mag12,3) + RzRbar3*(-3.96862696659688589*Power(Mag12,3) + RzRbar3*(-15.8745078663875435*Power(Mag12,3) - 9.9215674164922147*Power(Mag12,3)*RzRbar3))))/Mag30;
  }
  
  double D_5_neg1_1() {
    return 0.125*Power(Mag12,2) + RzRbar3*(-3.5*Power(Mag12,2) + RzRbar3*(-5.25*Power(Mag12,2) + RzRbar3*(10.5*Power(Mag12,2) + 13.125*Power(Mag12,2)*RzRbar3)));
  }
  
  double D_5_0_1() {
    return -0.68465319688145764*Mag12*Mag30 + Power(RzRbar3,2)*(9.585144756340407*Mag12*Mag30 - 14.3777171345106105*Mag12*Mag30*Power(RzRbar3,2));
  }
  
  double D_5_1_1() {
    return 0.125*Power(Mag30,2) + RzRbar3*(3.5*Power(Mag30,2) + RzRbar3*(-5.25*Power(Mag30,2) + RzRbar3*(-10.5*Power(Mag30,2) + 13.125*Power(Mag30,2)*RzRbar3)));
  }
  
  double D_5_2_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.66143782776614765*Power(Mag30,3) + RzRbar3*(-2.64575131106459059*Power(Mag30,3) + RzRbar3*(-3.96862696659688589*Power(Mag30,3) + RzRbar3*(15.8745078663875435*Power(Mag30,3) - 9.9215674164922147*Power(Mag30,3)*RzRbar3))))/Mag12;
  }
  
  double D_5_3_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.40504629365049126*Power(Mag30,4) + RzRbar3*(-1.6201851746019651*Power(Mag30,4) + RzRbar3*(10.5312036349127729*Power(Mag30,4) + RzRbar3*(-14.5816665714176855*Power(Mag30,4) + 6.075694404757369*Power(Mag30,4)*RzRbar3))))/Power(Mag12,2);
  }
  
  double D_5_4_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.57282196186948*Power(Mag30,5) + RzRbar3*(4.58257569495584*Power(Mag30,5) + RzRbar3*(-10.31079531365064*Power(Mag30,5) + RzRbar3*(9.16515138991168*Power(Mag30,5) - 2.8641098093474*Power(Mag30,5)*RzRbar3))))/Power(Mag12,3);
  }
  
  double D_5_5_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.90571104663683991*Power(Mag30,6) + RzRbar3*(-3.6228441865473596*Power(Mag30,6) + RzRbar3*(5.4342662798210395*Power(Mag30,6) + RzRbar3*(-3.62284418654735964*Power(Mag30,6) + 0.905711046636839911*Power(Mag30,6)*RzRbar3))))/Power(Mag12,4);
  }
  
  double D_5_neg5_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.36930639376291528*Power(Mag12,7) + RzRbar3*(-4.1079191812887459*Power(Mag12,7) + RzRbar3*(-4.10791918128874585*Power(Mag12,7) - 1.36930639376291528*Power(Mag12,7)*RzRbar3)))/Power(Mag30,3);
  }
  
  double D_5_neg4_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.73205080756887729*Power(Mag12,6) + RzRbar3*(7.7942286340599478*Power(Mag12,6) + RzRbar3*(10.3923048454132638*Power(Mag12,6) + 4.33012701892219323*Power(Mag12,6)*RzRbar3)))/Power(Mag30,2);
  }
  
  double D_5_neg3_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.61237243569579452*Power(Mag12,5) + RzRbar3*(-7.9608416640453288*Power(Mag12,5) + RzRbar3*(-16.5340557637864522*Power(Mag12,5) - 9.1855865354369179*Power(Mag12,5)*RzRbar3)))/Mag30;
  }
  
  double D_5_neg2_2() {
    return -1.*Power(Mag12,4) + RzRbar3*(3.*Power(Mag12,4) + RzRbar3*(18.*Power(Mag12,4) + 15.*Power(Mag12,4)*RzRbar3));
  }
  
  double D_5_neg1_2() {
    return 1.3228756555322953*Power(Mag12,3)*Mag30 + RzRbar3*(3.96862696659688589*Power(Mag12,3)*Mag30 + RzRbar3*(-11.9058808997906577*Power(Mag12,3)*Mag30 - 19.8431348329844294*Power(Mag12,3)*Mag30*RzRbar3));
  }
  
  double D_5_0_2() {
    return RzRbar3*(-7.2456883730947193*Power(Mag12,2)*Power(Mag30,2) + 21.7370651192841579*Power(Mag12,2)*Power(Mag30,2)*Power(RzRbar3,2));
  }
  
  double D_5_1_2() {
    return -1.3228756555322953*Mag12*Power(Mag30,3) + RzRbar3*(3.96862696659688589*Mag12*Power(Mag30,3) + RzRbar3*(11.9058808997906577*Mag12*Power(Mag30,3) - 19.8431348329844294*Mag12*Power(Mag30,3)*RzRbar3));
  }
  
  double D_5_2_2() {
    return 1.*Power(Mag30,4) + RzRbar3*(3.*Power(Mag30,4) + RzRbar3*(-18.*Power(Mag30,4) + 15.*Power(Mag30,4)*RzRbar3));
  }
  
  double D_5_3_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.61237243569579452*Power(Mag30,5) + RzRbar3*(-7.9608416640453288*Power(Mag30,5) + RzRbar3*(16.5340557637864522*Power(Mag30,5) - 9.1855865354369179*Power(Mag30,5)*RzRbar3)))/Mag12;
  }
  
  double D_5_4_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.73205080756887729*Power(Mag30,6) + RzRbar3*(7.7942286340599478*Power(Mag30,6) + RzRbar3*(-10.3923048454132638*Power(Mag30,6) + 4.33012701892219323*Power(Mag30,6)*RzRbar3)))/Power(Mag12,2);
  }
  
  double D_5_5_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.36930639376291528*Power(Mag30,7) + RzRbar3*(-4.1079191812887459*Power(Mag30,7) + RzRbar3*(4.10791918128874585*Power(Mag30,7) - 1.36930639376291528*Power(Mag30,7)*RzRbar3)))/Power(Mag12,3);
  }
  
  double D_5_neg5_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.67705098312484227*Power(Mag12,8) + RzRbar3*(3.35410196624968454*Power(Mag12,8) + 1.67705098312484227*Power(Mag12,8)*RzRbar3))/Power(Mag30,2);
  }
  
  double D_5_neg4_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-3.18198051533946386*Power(Mag12,7) + RzRbar3*(-8.4852813742385703*Power(Mag12,7) - 5.3033008588991064*Power(Mag12,7)*RzRbar3))/Mag30;
  }
  
  double D_5_neg3_3() {
    return 3.25*Power(Mag12,6) + RzRbar3*(13.5*Power(Mag12,6) + 11.25*Power(Mag12,6)*RzRbar3);
  }
  
  double D_5_neg2_3() {
    return -1.22474487139158905*Power(Mag12,5)*Mag30 + RzRbar3*(-14.6969384566990686*Power(Mag12,5)*Mag30 - 18.3711730708738357*Power(Mag12,5)*Mag30*RzRbar3);
  }
  
  double D_5_neg1_3() {
    return -1.62018517460196506*Power(Mag12,4)*Power(Mag30,2) + RzRbar3*(9.7211110476117903*Power(Mag12,4)*Power(Mag30,2) + 24.3027776190294759*Power(Mag12,4)*Power(Mag30,2)*RzRbar3);
  }
  
  double D_5_0_3() {
    return 2.95803989154980802*Power(Mag12,3)*Power(Mag30,3) - 26.6223590239482722*Power(Mag12,3)*Power(Mag30,3)*Power(RzRbar3,2);
  }
  
  double D_5_1_3() {
    return -1.62018517460196506*Power(Mag12,2)*Power(Mag30,4) + RzRbar3*(-9.7211110476117903*Power(Mag12,2)*Power(Mag30,4) + 24.3027776190294759*Power(Mag12,2)*Power(Mag30,4)*RzRbar3);
  }
  
  double D_5_2_3() {
    return -1.22474487139158905*Mag12*Power(Mag30,5) + RzRbar3*(14.6969384566990686*Mag12*Power(Mag30,5) - 18.3711730708738357*Mag12*Power(Mag30,5)*RzRbar3);
  }
  
  double D_5_3_3() {
    return 3.25*Power(Mag30,6) + RzRbar3*(-13.5*Power(Mag30,6) + 11.25*Power(Mag30,6)*RzRbar3);
  }
  
  double D_5_4_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-3.18198051533946386*Power(Mag30,7) + RzRbar3*(8.4852813742385703*Power(Mag30,7) - 5.3033008588991064*Power(Mag30,7)*RzRbar3))/Mag12;
  }
  
  double D_5_5_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.67705098312484227*Power(Mag30,8) + RzRbar3*(-3.35410196624968454*Power(Mag30,8) + 1.67705098312484227*Power(Mag30,8)*RzRbar3))/Power(Mag12,2);
  }
  
  double D_5_neg5_4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.58113883008418967*Power(Mag12,9) - 1.58113883008418967*Power(Mag12,9)*RzRbar3)/Mag30;
  }
  
  double D_5_neg4_4() {
    return 4.*Power(Mag12,8) + 5.*Power(Mag12,8)*RzRbar3;
  }
  
  double D_5_neg3_4() {
    return -6.3639610306789277*Power(Mag12,7)*Mag30 - 10.6066017177982129*Power(Mag12,7)*Mag30*RzRbar3;
  }
  
  double D_5_neg2_4() {
    return 6.9282032302755092*Power(Mag12,6)*Power(Mag30,2) + 17.3205080756887729*Power(Mag12,6)*Power(Mag30,2)*RzRbar3;
  }
  
  double D_5_neg1_4() {
    return -4.58257569495584001*Power(Mag12,5)*Power(Mag30,3) - 22.9128784747792*Power(Mag12,5)*Power(Mag30,3)*RzRbar3;
  }
  
  double D_5_0_4() {
    return 25.0998007960222664*Power(Mag12,4)*Power(Mag30,4)*RzRbar3;
  }
  
  double D_5_1_4() {
    return 4.58257569495584001*Power(Mag12,3)*Power(Mag30,5) - 22.9128784747792*Power(Mag12,3)*Power(Mag30,5)*RzRbar3;
  }
  
  double D_5_2_4() {
    return -6.9282032302755092*Power(Mag12,2)*Power(Mag30,6) + 17.3205080756887729*Power(Mag12,2)*Power(Mag30,6)*RzRbar3;
  }
  
  double D_5_3_4() {
    return 6.3639610306789277*Mag12*Power(Mag30,7) - 10.6066017177982129*Mag12*Power(Mag30,7)*RzRbar3;
  }
  
  double D_5_4_4() {
    return -4.*Power(Mag30,8) + 5.*Power(Mag30,8)*RzRbar3;
  }
  
  double D_5_5_4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.58113883008418967*Power(Mag30,9) - 1.58113883008418967*Power(Mag30,9)*RzRbar3)/Mag12;
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
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00390625 + RzRbar3*(0.03125 + RzRbar3*(0.109375 + RzRbar3*(0.21875 + RzRbar3*(0.2734375 + RzRbar3*(0.21875 + RzRbar3*(0.109375 + (0.03125 + 0.00390625*RzRbar3)*RzRbar3)))))))/Power(Mag30,8);
  }
  
  double D_4_neg3_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0110485434560398051 + RzRbar3*(0.06629126073623883 + RzRbar3*(0.15467960838455727 + RzRbar3*(0.15467960838455727 + RzRbar3*(0.e-17 + RzRbar3*(-0.15467960838455727 + RzRbar3*(-0.154679608384557271 + (-0.06629126073623883 - 0.0110485434560398051*RzRbar3)*RzRbar3)))))))/(Mag12*Power(Mag30,7));
  }
  
  double D_4_neg2_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.020669932117692114 + RzRbar3*(0.08267972847076846 + RzRbar3*(0.08267972847076846 + RzRbar3*(-0.08267972847076846 + RzRbar3*(-0.20669932117692114 + RzRbar3*(-0.08267972847076846 + RzRbar3*(0.08267972847076846 + (0.082679728470768456 + 0.020669932117692114*RzRbar3)*RzRbar3)))))))/(Power(Mag12,2)*Power(Mag30,6));
  }
  
  double D_4_neg1_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.029231698334171417 + RzRbar3*(0.05846339666834283 + RzRbar3*(-0.05846339666834283 + RzRbar3*(-0.1753901900050285 + RzRbar3*(0.e-16 + RzRbar3*(0.1753901900050285 + RzRbar3*(0.05846339666834283 + (-0.058463396668342834 - 0.0292316983341714171*RzRbar3)*RzRbar3)))))))/(Power(Mag12,3)*Power(Mag30,5));
  }
  
  double D_4_0_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.032682032286487326 + Power(RzRbar3,2)*(-0.130728129145949304 + Power(RzRbar3,2)*(0.196092193718923957 + Power(RzRbar3,2)*(-0.130728129145949304 + 0.0326820322864873261*Power(RzRbar3,2)))))/(Power(Mag12,4)*Power(Mag30,4));
  }
  
  double D_4_1_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.029231698334171417 + RzRbar3*(-0.05846339666834283 + RzRbar3*(-0.05846339666834283 + RzRbar3*(0.1753901900050285 + RzRbar3*(0.e-16 + RzRbar3*(-0.1753901900050285 + RzRbar3*(0.05846339666834283 + (0.058463396668342834 - 0.0292316983341714171*RzRbar3)*RzRbar3)))))))/(Power(Mag12,5)*Power(Mag30,3));
  }
  
  double D_4_2_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.020669932117692114 + RzRbar3*(-0.08267972847076846 + RzRbar3*(0.08267972847076846 + RzRbar3*(0.08267972847076846 + RzRbar3*(-0.20669932117692114 + RzRbar3*(0.08267972847076846 + RzRbar3*(0.08267972847076846 + (-0.082679728470768456 + 0.020669932117692114*RzRbar3)*RzRbar3)))))))/(Power(Mag12,6)*Power(Mag30,2));
  }
  
  double D_4_3_neg4() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0110485434560398051 + RzRbar3*(-0.06629126073623883 + RzRbar3*(0.15467960838455727 + RzRbar3*(-0.15467960838455727 + RzRbar3*(0.e-17 + RzRbar3*(0.15467960838455727 + RzRbar3*(-0.154679608384557271 + (0.06629126073623883 - 0.0110485434560398051*RzRbar3)*RzRbar3)))))))/(Power(Mag12,7)*Mag30);
  }
  
  double D_4_4_neg4() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.00390625 + RzRbar3*(-0.03125 + RzRbar3*(0.109375 + RzRbar3*(-0.21875 + RzRbar3*(0.2734375 + RzRbar3*(-0.21875 + RzRbar3*(0.109375 + (-0.03125 + 0.00390625*RzRbar3)*RzRbar3)))))))/Power(Mag12,8);
  }
  
  double D_4_neg4_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.02209708691207961*Mag12 + RzRbar3*(-0.15467960838455727*Mag12 + RzRbar3*(-0.46403882515367181*Mag12 + RzRbar3*(-0.77339804192278635*Mag12 + RzRbar3*(-0.77339804192278635*Mag12 + RzRbar3*(-0.46403882515367181*Mag12 + RzRbar3*(-0.154679608384557271*Mag12 - 0.0220970869120796101*Mag12*RzRbar3)))))))/Power(Mag30,7);
  }
  
  double D_4_neg3_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.046875 + RzRbar3*(-0.21875 + RzRbar3*(-0.328125 + RzRbar3*(0.e-16 + RzRbar3*(0.546875 + RzRbar3*(0.65625 + (0.328125 + 0.0625*RzRbar3)*RzRbar3))))))/Power(Mag30,6);
  }
  
  double D_4_neg2_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.058463396668342834 + RzRbar3*(-0.11692679333668567 + RzRbar3*(0.1753901900050285 + RzRbar3*(0.5846339666834283 + RzRbar3*(0.2923169833417142 + RzRbar3*(-0.350780380010057 + (-0.40924377667839984 - 0.116926793336685668*RzRbar3)*RzRbar3))))))/(Mag12*Power(Mag30,5));
  }
  
  double D_4_neg1_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.041339864235384228 + RzRbar3*(0.08267972847076846 + RzRbar3*(0.37205877811845805 + RzRbar3*(0.e-16 + RzRbar3*(-0.6200979635307634 + RzRbar3*(-0.24803918541230537 + (0.2893790496476896 + 0.165359456941536912*RzRbar3)*RzRbar3))))))/(Power(Mag12,2)*Power(Mag30,4));
  }
  
  double D_4_0_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(0.184877493221863001 + Power(RzRbar3,2)*(-0.554632479665589 + Power(RzRbar3,2)*(0.554632479665589 - 0.184877493221863001*Power(RzRbar3,2)))))/(Power(Mag12,3)*Power(Mag30,3));
  }
  
  double D_4_1_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.041339864235384228 + RzRbar3*(0.08267972847076846 + RzRbar3*(-0.37205877811845805 + RzRbar3*(0.e-16 + RzRbar3*(0.6200979635307634 + RzRbar3*(-0.24803918541230537 + (-0.2893790496476896 + 0.165359456941536912*RzRbar3)*RzRbar3))))))/(Power(Mag12,4)*Power(Mag30,2));
  }
  
  double D_4_2_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.058463396668342834 + RzRbar3*(-0.11692679333668567 + RzRbar3*(-0.1753901900050285 + RzRbar3*(0.5846339666834283 + RzRbar3*(-0.2923169833417142 + RzRbar3*(-0.350780380010057 + (0.40924377667839984 - 0.116926793336685668*RzRbar3)*RzRbar3))))))/(Power(Mag12,5)*Mag30);
  }
  
  double D_4_3_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.046875 + RzRbar3*(-0.21875 + RzRbar3*(0.328125 + RzRbar3*(0.e-16 + RzRbar3*(-0.546875 + RzRbar3*(0.65625 + (-0.328125 + 0.0625*RzRbar3)*RzRbar3))))))/Power(Mag12,6);
  }
  
  double D_4_4_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.02209708691207961*Mag30 + RzRbar3*(-0.15467960838455727*Mag30 + RzRbar3*(0.46403882515367181*Mag30 + RzRbar3*(-0.77339804192278635*Mag30 + RzRbar3*(0.77339804192278635*Mag30 + RzRbar3*(-0.46403882515367181*Mag30 + RzRbar3*(0.154679608384557271*Mag30 - 0.0220970869120796101*Mag30*RzRbar3)))))))/Power(Mag12,7);
  }
  
  double D_4_neg4_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.082679728470768456*Power(Mag12,2) + RzRbar3*(0.49607837082461074*Power(Mag12,2) + RzRbar3*(1.24019592706152684*Power(Mag12,2) + RzRbar3*(1.65359456941536912*Power(Mag12,2) + RzRbar3*(1.24019592706152684*Power(Mag12,2) + RzRbar3*(0.496078370824610736*Power(Mag12,2) + 0.082679728470768456*Power(Mag12,2)*RzRbar3))))))/Power(Mag30,6);
  }
  
  double D_4_neg3_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.116926793336685668*Mag12 + RzRbar3*(0.350780380010057*Mag12 + RzRbar3*(0.e-16*Mag12 + RzRbar3*(-1.1692679333668567*Mag12 + RzRbar3*(-1.753901900050285*Mag12 + RzRbar3*(-1.05234114003017101*Mag12 - 0.233853586673371337*Mag12*RzRbar3))))))/Power(Mag30,5);
  }
  
  double D_4_neg2_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0625 + RzRbar3*(-0.1875 + RzRbar3*(-0.9375 + RzRbar3*(-0.625 + RzRbar3*(0.9375 + (1.3125 + 0.4375*RzRbar3)*RzRbar3)))))/Power(Mag30,4);
  }
  
  double D_4_neg1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.04419417382415922 + RzRbar3*(-0.39774756441743298 + RzRbar3*(0.e-17 + RzRbar3*(1.3258252147247766 + RzRbar3*(0.6629126073623883 + (-0.92807765030734363 - 0.61871843353822908*RzRbar3)*RzRbar3)))))/(Mag12*Power(Mag30,3));
  }
  
  double D_4_0_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.098821176880261854 + Power(RzRbar3,2)*(0.88939059192235669 + Power(RzRbar3,2)*(-1.48231765320392781 + 0.69174823816183298*Power(RzRbar3,2))))/(Power(Mag12,2)*Power(Mag30,2));
  }
  
  double D_4_1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.04419417382415922 + RzRbar3*(0.39774756441743298 + RzRbar3*(0.e-17 + RzRbar3*(-1.3258252147247766 + RzRbar3*(0.6629126073623883 + (0.92807765030734363 - 0.61871843353822908*RzRbar3)*RzRbar3)))))/(Power(Mag12,3)*Mag30);
  }
  
  double D_4_2_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0625 + RzRbar3*(0.1875 + RzRbar3*(-0.9375 + RzRbar3*(0.625 + RzRbar3*(0.9375 + (-1.3125 + 0.4375*RzRbar3)*RzRbar3)))))/Power(Mag12,4);
  }
  
  double D_4_3_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.116926793336685668*Mag30 + RzRbar3*(-0.350780380010057*Mag30 + RzRbar3*(0.e-16*Mag30 + RzRbar3*(1.1692679333668567*Mag30 + RzRbar3*(-1.753901900050285*Mag30 + RzRbar3*(1.05234114003017101*Mag30 - 0.233853586673371337*Mag30*RzRbar3))))))/Power(Mag12,5);
  }
  
  double D_4_4_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.082679728470768456*Power(Mag30,2) + RzRbar3*(-0.49607837082461074*Power(Mag30,2) + RzRbar3*(1.24019592706152684*Power(Mag30,2) + RzRbar3*(-1.65359456941536912*Power(Mag30,2) + RzRbar3*(1.24019592706152684*Power(Mag30,2) + RzRbar3*(-0.496078370824610736*Power(Mag30,2) + 0.082679728470768456*Power(Mag30,2)*RzRbar3))))))/Power(Mag12,6);
  }
  
  double D_4_neg4_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.23385358667337134*Power(Mag12,3) + RzRbar3*(-1.16926793336685668*Power(Mag12,3) + RzRbar3*(-2.33853586673371337*Power(Mag12,3) + RzRbar3*(-2.33853586673371337*Power(Mag12,3) + RzRbar3*(-1.16926793336685668*Power(Mag12,3) - 0.233853586673371337*Power(Mag12,3)*RzRbar3)))))/Power(Mag30,5);
  }
  
  double D_4_neg3_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.165359456941536912*Power(Mag12,2) + RzRbar3*(0.e-17*Power(Mag12,2) + RzRbar3*(1.6535945694153691*Power(Mag12,2) + RzRbar3*(3.3071891388307382*Power(Mag12,2) + RzRbar3*(2.48039185412305368*Power(Mag12,2) + 0.66143782776614765*Power(Mag12,2)*RzRbar3)))))/Power(Mag30,4);
  }
  
  double D_4_neg2_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.088388347648318441*Mag12 + RzRbar3*(0.88388347648318441*Mag12 + RzRbar3*(0.8838834764831844*Mag12 + RzRbar3*(-1.7677669529663688*Mag12 + RzRbar3*(-3.0935921676911454*Mag12 - 1.23743686707645817*Mag12*RzRbar3)))))/Power(Mag30,3);
  }
  
  double D_4_neg1_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.1875 + RzRbar3*(0.e-17 + RzRbar3*(-1.875 + RzRbar3*(-1.25 + RzRbar3*(2.1875 + 1.75*RzRbar3)))))/Power(Mag30,2);
  }
  
  double D_4_0_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-0.83852549156242114 + Power(RzRbar3,2)*(2.79508497187473712 - 1.95655948031231598*Power(RzRbar3,2))))/(Mag12*Mag30);
  }
  
  double D_4_1_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.1875 + RzRbar3*(0.e-17 + RzRbar3*(1.875 + RzRbar3*(-1.25 + RzRbar3*(-2.1875 + 1.75*RzRbar3)))))/Power(Mag12,2);
  }
  
  double D_4_2_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.088388347648318441*Mag30 + RzRbar3*(0.88388347648318441*Mag30 + RzRbar3*(-0.8838834764831844*Mag30 + RzRbar3*(-1.7677669529663688*Mag30 + RzRbar3*(3.0935921676911454*Mag30 - 1.23743686707645817*Mag30*RzRbar3)))))/Power(Mag12,3);
  }
  
  double D_4_3_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.165359456941536912*Power(Mag30,2) + RzRbar3*(0.e-17*Power(Mag30,2) + RzRbar3*(-1.6535945694153691*Power(Mag30,2) + RzRbar3*(3.3071891388307382*Power(Mag30,2) + RzRbar3*(-2.48039185412305368*Power(Mag30,2) + 0.66143782776614765*Power(Mag30,2)*RzRbar3)))))/Power(Mag12,4);
  }
  
  double D_4_4_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.23385358667337134*Power(Mag30,3) + RzRbar3*(-1.16926793336685668*Power(Mag30,3) + RzRbar3*(2.33853586673371337*Power(Mag30,3) + RzRbar3*(-2.33853586673371337*Power(Mag30,3) + RzRbar3*(1.16926793336685668*Power(Mag30,3) - 0.233853586673371337*Power(Mag30,3)*RzRbar3)))))/Power(Mag12,5);
  }
  
  double D_4_neg4_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.52291251658379722*Power(Mag12,4) + RzRbar3*(2.09165006633518887*Power(Mag12,4) + RzRbar3*(3.1374750995027833*Power(Mag12,4) + RzRbar3*(2.09165006633518887*Power(Mag12,4) + 0.522912516583797217*Power(Mag12,4)*RzRbar3))))/Power(Mag30,4);
  }
  
  double D_4_neg3_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-1.47901994577490401*Power(Mag12,3) + RzRbar3*(-4.437059837324712*Power(Mag12,3) + RzRbar3*(-4.43705983732471203*Power(Mag12,3) - 1.47901994577490401*Power(Mag12,3)*RzRbar3))))/Power(Mag30,3);
  }
  
  double D_4_neg2_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.39528470752104742*Power(Mag12,2) + RzRbar3*(-0.79056941504209483*Power(Mag12,2) + RzRbar3*(2.3717082451262845*Power(Mag12,2) + RzRbar3*(5.5339859052946638*Power(Mag12,2) + 2.76699295264733192*Power(Mag12,2)*RzRbar3))))/Power(Mag30,2);
  }
  
  double D_4_neg1_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(1.67705098312484227*Mag12 + RzRbar3*(1.67705098312484227*Mag12 + RzRbar3*(-3.91311896062463197*Mag12 - 3.91311896062463197*Mag12*RzRbar3))))/Mag30;
  }
  
  double D_4_0_0() {
    return 0.375 + Power(RzRbar3,2)*(-3.75 + 4.375*Power(RzRbar3,2));
  }
  
  double D_4_1_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-1.67705098312484227*Mag30 + RzRbar3*(1.67705098312484227*Mag30 + RzRbar3*(3.91311896062463197*Mag30 - 3.91311896062463197*Mag30*RzRbar3))))/Mag12;
  }
  
  double D_4_2_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.39528470752104742*Power(Mag30,2) + RzRbar3*(0.79056941504209483*Power(Mag30,2) + RzRbar3*(2.3717082451262845*Power(Mag30,2) + RzRbar3*(-5.5339859052946638*Power(Mag30,2) + 2.76699295264733192*Power(Mag30,2)*RzRbar3))))/Power(Mag12,2);
  }
  
  double D_4_3_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(1.47901994577490401*Power(Mag30,3) + RzRbar3*(-4.437059837324712*Power(Mag30,3) + RzRbar3*(4.43705983732471203*Power(Mag30,3) - 1.47901994577490401*Power(Mag30,3)*RzRbar3))))/Power(Mag12,3);
  }
  
  double D_4_4_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.52291251658379722*Power(Mag30,4) + RzRbar3*(-2.09165006633518887*Power(Mag30,4) + RzRbar3*(3.1374750995027833*Power(Mag30,4) + RzRbar3*(-2.09165006633518887*Power(Mag30,4) + 0.522912516583797217*Power(Mag30,4)*RzRbar3))))/Power(Mag12,4);
  }
  
  double D_4_neg4_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.93541434669348535*Power(Mag12,5) + RzRbar3*(-2.80624304008045604*Power(Mag12,5) + RzRbar3*(-2.80624304008045604*Power(Mag12,5) - 0.935414346693485346*Power(Mag12,5)*RzRbar3)))/Power(Mag30,3);
  }
  
  double D_4_neg3_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.66143782776614765*Power(Mag12,4) + RzRbar3*(3.9686269665968859*Power(Mag12,4) + RzRbar3*(5.9529404498953288*Power(Mag12,4) + 2.64575131106459059*Power(Mag12,4)*RzRbar3)))/Power(Mag30,2);
  }
  
  double D_4_neg2_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.353553390593273762*Power(Mag12,3) + RzRbar3*(-2.12132034355964257*Power(Mag12,3) + RzRbar3*(-7.424621202458749*Power(Mag12,3) - 4.94974746830583267*Power(Mag12,3)*RzRbar3)))/Mag30;
  }
  
  double D_4_neg1_1() {
    return -0.75*Power(Mag12,2) + RzRbar3*(-1.5*Power(Mag12,2) + RzRbar3*(5.25*Power(Mag12,2) + 7.*Power(Mag12,2)*RzRbar3));
  }
  
  double D_4_0_1() {
    return RzRbar3*(3.35410196624968454*Mag12*Mag30 - 7.8262379212492639*Mag12*Mag30*Power(RzRbar3,2));
  }
  
  double D_4_1_1() {
    return 0.75*Power(Mag30,2) + RzRbar3*(-1.5*Power(Mag30,2) + RzRbar3*(-5.25*Power(Mag30,2) + 7.*Power(Mag30,2)*RzRbar3));
  }
  
  double D_4_2_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.353553390593273762*Power(Mag30,3) + RzRbar3*(-2.12132034355964257*Power(Mag30,3) + RzRbar3*(7.424621202458749*Power(Mag30,3) - 4.94974746830583267*Power(Mag30,3)*RzRbar3)))/Mag12;
  }
  
  double D_4_3_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.66143782776614765*Power(Mag30,4) + RzRbar3*(3.9686269665968859*Power(Mag30,4) + RzRbar3*(-5.9529404498953288*Power(Mag30,4) + 2.64575131106459059*Power(Mag30,4)*RzRbar3)))/Power(Mag12,2);
  }
  
  double D_4_4_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.93541434669348535*Power(Mag30,5) + RzRbar3*(-2.80624304008045604*Power(Mag30,5) + RzRbar3*(2.80624304008045604*Power(Mag30,5) - 0.935414346693485346*Power(Mag30,5)*RzRbar3)))/Power(Mag12,3);
  }
  
  double D_4_neg4_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.3228756555322953*Power(Mag12,6) + RzRbar3*(2.64575131106459059*Power(Mag12,6) + 1.3228756555322953*Power(Mag12,6)*RzRbar3))/Power(Mag30,2);
  }
  
  double D_4_neg3_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.87082869338697069*Power(Mag12,5) + RzRbar3*(-5.6124860801609121*Power(Mag12,5) - 3.74165738677394139*Power(Mag12,5)*RzRbar3))/Mag30;
  }
  
  double D_4_neg2_2() {
    return 1.*Power(Mag12,4) + RzRbar3*(7.*Power(Mag12,4) + 7.*Power(Mag12,4)*RzRbar3);
  }
  
  double D_4_neg1_2() {
    return 0.70710678118654752*Power(Mag12,3)*Mag30 + RzRbar3*(-4.94974746830583267*Power(Mag12,3)*Mag30 - 9.8994949366116653*Power(Mag12,3)*Mag30*RzRbar3);
  }
  
  double D_4_0_2() {
    return -1.58113883008418967*Power(Mag12,2)*Power(Mag30,2) + 11.0679718105893277*Power(Mag12,2)*Power(Mag30,2)*Power(RzRbar3,2);
  }
  
  double D_4_1_2() {
    return 0.70710678118654752*Mag12*Power(Mag30,3) + RzRbar3*(4.94974746830583267*Mag12*Power(Mag30,3) - 9.8994949366116653*Mag12*Power(Mag30,3)*RzRbar3);
  }
  
  double D_4_2_2() {
    return 1.*Power(Mag30,4) + RzRbar3*(-7.*Power(Mag30,4) + 7.*Power(Mag30,4)*RzRbar3);
  }
  
  double D_4_3_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.87082869338697069*Power(Mag30,5) + RzRbar3*(5.6124860801609121*Power(Mag30,5) - 3.74165738677394139*Power(Mag30,5)*RzRbar3))/Mag12;
  }
  
  double D_4_4_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.3228756555322953*Power(Mag30,6) + RzRbar3*(-2.64575131106459059*Power(Mag30,6) + 1.3228756555322953*Power(Mag30,6)*RzRbar3))/Power(Mag12,2);
  }
  
  double D_4_neg4_3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.41421356237309505*Power(Mag12,7) - 1.41421356237309505*Power(Mag12,7)*RzRbar3)/Mag30;
  }
  
  double D_4_neg3_3() {
    return 3.*Power(Mag12,6) + 4.*Power(Mag12,6)*RzRbar3;
  }
  
  double D_4_neg2_3() {
    return -3.74165738677394139*Power(Mag12,5)*Mag30 - 7.4833147735478828*Power(Mag12,5)*Mag30*RzRbar3;
  }
  
  double D_4_neg1_3() {
    return 2.64575131106459059*Power(Mag12,4)*Power(Mag30,2) + 10.5830052442583624*Power(Mag12,4)*Power(Mag30,2)*RzRbar3;
  }
  
  double D_4_0_3() {
    return -11.8321595661992321*Power(Mag12,3)*Power(Mag30,3)*RzRbar3;
  }
  
  double D_4_1_3() {
    return -2.64575131106459059*Power(Mag12,2)*Power(Mag30,4) + 10.5830052442583624*Power(Mag12,2)*Power(Mag30,4)*RzRbar3;
  }
  
  double D_4_2_3() {
    return 3.74165738677394139*Mag12*Power(Mag30,5) - 7.4833147735478828*Mag12*Power(Mag30,5)*RzRbar3;
  }
  
  double D_4_3_3() {
    return -3.*Power(Mag30,6) + 4.*Power(Mag30,6)*RzRbar3;
  }
  
  double D_4_4_3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.41421356237309505*Power(Mag30,7) - 1.41421356237309505*Power(Mag30,7)*RzRbar3)/Mag12;
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
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.015625 + RzRbar3*(0.09375 + RzRbar3*(0.234375 + RzRbar3*(0.3125 + RzRbar3*(0.234375 + (0.09375 + 0.015625*RzRbar3)*RzRbar3)))))/Power(Mag30,6);
  }
  
  double D_3_neg2_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.038273277230987158 + RzRbar3*(0.15309310892394863 + RzRbar3*(0.19136638615493579 + RzRbar3*(0.e-17 + RzRbar3*(-0.19136638615493579 + (-0.153093108923948631 - 0.0382732772309871578*RzRbar3)*RzRbar3)))))/(Mag12*Power(Mag30,5));
  }
  
  double D_3_neg1_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.060515364784490889 + RzRbar3*(0.12103072956898178 + RzRbar3*(-0.06051536478449089 + RzRbar3*(-0.24206145913796356 + RzRbar3*(-0.06051536478449089 + (0.121030729568981778 + 0.0605153647844908888*RzRbar3)*RzRbar3)))))/(Power(Mag12,2)*Power(Mag30,4));
  }
  
  double D_3_0_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.069877124296868428 + Power(RzRbar3,2)*(-0.209631372890605284 + Power(RzRbar3,2)*(0.209631372890605284 - 0.069877124296868428*Power(RzRbar3,2))))/(Power(Mag12,3)*Power(Mag30,3));
  }
  
  double D_3_1_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.060515364784490889 + RzRbar3*(-0.12103072956898178 + RzRbar3*(-0.06051536478449089 + RzRbar3*(0.24206145913796356 + RzRbar3*(-0.06051536478449089 + (-0.121030729568981778 + 0.0605153647844908888*RzRbar3)*RzRbar3)))))/(Power(Mag12,4)*Power(Mag30,2));
  }
  
  double D_3_2_neg3() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.038273277230987158 + RzRbar3*(-0.15309310892394863 + RzRbar3*(0.19136638615493579 + RzRbar3*(0.e-17 + RzRbar3*(-0.19136638615493579 + (0.153093108923948631 - 0.0382732772309871578*RzRbar3)*RzRbar3)))))/(Power(Mag12,5)*Mag30);
  }
  
  double D_3_3_neg3() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.015625 + RzRbar3*(-0.09375 + RzRbar3*(0.234375 + RzRbar3*(-0.3125 + RzRbar3*(0.234375 + (-0.09375 + 0.015625*RzRbar3)*RzRbar3)))))/Power(Mag12,6);
  }
  
  double D_3_neg3_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.076546554461974316*Mag12 + RzRbar3*(-0.38273277230987158*Mag12 + RzRbar3*(-0.76546554461974316*Mag12 + RzRbar3*(-0.76546554461974316*Mag12 + RzRbar3*(-0.382732772309871578*Mag12 - 0.0765465544619743156*Mag12*RzRbar3)))))/Power(Mag30,5);
  }
  
  double D_3_neg2_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.125 + RzRbar3*(-0.3125 + RzRbar3*(0.e-17 + RzRbar3*(0.625 + (0.625 + 0.1875*RzRbar3)*RzRbar3))))/Power(Mag30,4);
  }
  
  double D_3_neg1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.098821176880261854 + RzRbar3*(0.09882117688026185 + RzRbar3*(0.59292706128157112 + RzRbar3*(0.19764235376052371 + (-0.49410588440130927 - 0.296463530640785562*RzRbar3)*RzRbar3))))/(Mag12*Power(Mag30,3));
  }
  
  double D_3_0_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(0.34232659844072882 + Power(RzRbar3,2)*(-0.68465319688145764 + 0.342326598440728821*Power(RzRbar3,2))))/(Power(Mag12,2)*Power(Mag30,2));
  }
  
  double D_3_1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.098821176880261854 + RzRbar3*(0.09882117688026185 + RzRbar3*(-0.59292706128157112 + RzRbar3*(0.19764235376052371 + (0.49410588440130927 - 0.296463530640785562*RzRbar3)*RzRbar3))))/(Power(Mag12,3)*Mag30);
  }
  
  double D_3_2_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.125 + RzRbar3*(-0.3125 + RzRbar3*(0.e-17 + RzRbar3*(0.625 + (-0.625 + 0.1875*RzRbar3)*RzRbar3))))/Power(Mag12,4);
  }
  
  double D_3_3_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.076546554461974316*Mag30 + RzRbar3*(-0.38273277230987158*Mag30 + RzRbar3*(0.76546554461974316*Mag30 + RzRbar3*(-0.76546554461974316*Mag30 + RzRbar3*(0.382732772309871578*Mag30 - 0.0765465544619743156*Mag30*RzRbar3)))))/Power(Mag12,5);
  }
  
  double D_3_neg3_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.24206145913796356*Power(Mag12,2) + RzRbar3*(0.96824583655185422*Power(Mag12,2) + RzRbar3*(1.45236875482778133*Power(Mag12,2) + RzRbar3*(0.96824583655185422*Power(Mag12,2) + 0.242061459137963555*Power(Mag12,2)*RzRbar3))))/Power(Mag30,4);
  }
  
  double D_3_neg2_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.197642353760523708*Mag12 + RzRbar3*(0.e-17*Mag12 + RzRbar3*(-1.18585412256314225*Mag12 + RzRbar3*(-1.58113883008418967*Mag12 - 0.59292706128157112*Mag12*RzRbar3))))/Power(Mag30,3);
  }
  
  double D_3_neg1_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0625 + RzRbar3*(-0.75 + RzRbar3*(-0.375 + (1.25 + 0.9375*RzRbar3)*RzRbar3)))/Power(Mag30,2);
  }
  
  double D_3_0_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.216506350946109662 + Power(RzRbar3,2)*(1.29903810567665797 - 1.08253175473054831*Power(RzRbar3,2)))/(Mag12*Mag30);
  }
  
  double D_3_1_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.0625 + RzRbar3*(0.75 + RzRbar3*(-0.375 + (-1.25 + 0.9375*RzRbar3)*RzRbar3)))/Power(Mag12,2);
  }
  
  double D_3_2_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.197642353760523708*Mag30 + RzRbar3*(0.e-17*Mag30 + RzRbar3*(-1.18585412256314225*Mag30 + RzRbar3*(1.58113883008418967*Mag30 - 0.59292706128157112*Mag30*RzRbar3))))/Power(Mag12,3);
  }
  
  double D_3_3_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.24206145913796356*Power(Mag30,2) + RzRbar3*(-0.96824583655185422*Power(Mag30,2) + RzRbar3*(1.45236875482778133*Power(Mag30,2) + RzRbar3*(-0.96824583655185422*Power(Mag30,2) + 0.242061459137963555*Power(Mag30,2)*RzRbar3))))/Power(Mag12,4);
  }
  
  double D_3_neg3_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.55901699437494742*Power(Mag12,3) + RzRbar3*(-1.67705098312484227*Power(Mag12,3) + RzRbar3*(-1.67705098312484227*Power(Mag12,3) - 0.559016994374947424*Power(Mag12,3)*RzRbar3)))/Power(Mag30,3);
  }
  
  double D_3_neg2_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(1.36930639376291528*Power(Mag12,2) + RzRbar3*(2.73861278752583057*Power(Mag12,2) + 1.36930639376291528*Power(Mag12,2)*RzRbar3)))/Power(Mag30,2);
  }
  
  double D_3_neg1_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.433012701892219323*Mag12 + RzRbar3*(0.433012701892219323*Mag12 + RzRbar3*(-2.16506350946109662*Mag12 - 2.16506350946109662*Mag12*RzRbar3)))/Mag30;
  }
  
  double D_3_0_0() {
    return RzRbar3*(-1.5 + 2.5*Power(RzRbar3,2));
  }
  
  double D_3_1_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.433012701892219323*Mag30 + RzRbar3*(0.433012701892219323*Mag30 + RzRbar3*(2.16506350946109662*Mag30 - 2.16506350946109662*Mag30*RzRbar3)))/Mag12;
  }
  
  double D_3_2_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(1.36930639376291528*Power(Mag30,2) + RzRbar3*(-2.73861278752583057*Power(Mag30,2) + 1.36930639376291528*Power(Mag30,2)*RzRbar3)))/Power(Mag12,2);
  }
  
  double D_3_3_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.55901699437494742*Power(Mag30,3) + RzRbar3*(-1.67705098312484227*Power(Mag30,3) + RzRbar3*(1.67705098312484227*Power(Mag30,3) - 0.559016994374947424*Power(Mag30,3)*RzRbar3)))/Power(Mag12,3);
  }
  
  double D_3_neg3_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.96824583655185422*Power(Mag12,4) + RzRbar3*(1.93649167310370844*Power(Mag12,4) + 0.968245836551854221*Power(Mag12,4)*RzRbar3))/Power(Mag30,2);
  }
  
  double D_3_neg2_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.79056941504209483*Power(Mag12,3) + RzRbar3*(-3.16227766016837933*Power(Mag12,3) - 2.3717082451262845*Power(Mag12,3)*RzRbar3))/Mag30;
  }
  
  double D_3_neg1_1() {
    return -0.25*Power(Mag12,2) + RzRbar3*(2.5*Power(Mag12,2) + 3.75*Power(Mag12,2)*RzRbar3);
  }
  
  double D_3_0_1() {
    return 0.86602540378443865*Mag12*Mag30 - 4.33012701892219323*Mag12*Mag30*Power(RzRbar3,2);
  }
  
  double D_3_1_1() {
    return -0.25*Power(Mag30,2) + RzRbar3*(-2.5*Power(Mag30,2) + 3.75*Power(Mag30,2)*RzRbar3);
  }
  
  double D_3_2_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.79056941504209483*Power(Mag30,3) + RzRbar3*(3.16227766016837933*Power(Mag30,3) - 2.3717082451262845*Power(Mag30,3)*RzRbar3))/Mag12;
  }
  
  double D_3_3_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.96824583655185422*Power(Mag30,4) + RzRbar3*(-1.93649167310370844*Power(Mag30,4) + 0.968245836551854221*Power(Mag30,4)*RzRbar3))/Power(Mag12,2);
  }
  
  double D_3_neg3_2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.22474487139158905*Power(Mag12,5) - 1.22474487139158905*Power(Mag12,5)*RzRbar3)/Mag30;
  }
  
  double D_3_neg2_2() {
    return 2.*Power(Mag12,4) + 3.*Power(Mag12,4)*RzRbar3;
  }
  
  double D_3_neg1_2() {
    return -1.58113883008418967*Power(Mag12,3)*Mag30 - 4.743416490252569*Power(Mag12,3)*Mag30*RzRbar3;
  }
  
  double D_3_0_2() {
    return 5.47722557505166113*Power(Mag12,2)*Power(Mag30,2)*RzRbar3;
  }
  
  double D_3_1_2() {
    return 1.58113883008418967*Mag12*Power(Mag30,3) - 4.743416490252569*Mag12*Power(Mag30,3)*RzRbar3;
  }
  
  double D_3_2_2() {
    return -2.*Power(Mag30,4) + 3.*Power(Mag30,4)*RzRbar3;
  }
  
  double D_3_3_2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.22474487139158905*Power(Mag30,5) - 1.22474487139158905*Power(Mag30,5)*RzRbar3)/Mag12;
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
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0625 + RzRbar3*(0.25 + RzRbar3*(0.375 + (0.25 + 0.0625*RzRbar3)*RzRbar3)))/Power(Mag30,4);
  }
  
  double D_2_neg1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.125 + RzRbar3*(0.25 + RzRbar3*(0.e-17 + (-0.25 - 0.125*RzRbar3)*RzRbar3)))/(Mag12*Power(Mag30,3));
  }
  
  double D_2_0_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.153093108923948631 + Power(RzRbar3,2)*(-0.306186217847897262 + 0.153093108923948631*Power(RzRbar3,2)))/(Power(Mag12,2)*Power(Mag30,2));
  }
  
  double D_2_1_neg2() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.125 + RzRbar3*(-0.25 + RzRbar3*(0.e-17 + (0.25 - 0.125*RzRbar3)*RzRbar3)))/(Power(Mag12,3)*Mag30);
  }
  
  double D_2_2_neg2() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.0625 + RzRbar3*(-0.25 + RzRbar3*(0.375 + (-0.25 + 0.0625*RzRbar3)*RzRbar3)))/Power(Mag12,4);
  }
  
  double D_2_neg2_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.25*Mag12 + RzRbar3*(-0.75*Mag12 + RzRbar3*(-0.75*Mag12 - 0.25*Mag12*RzRbar3)))/Power(Mag30,3);
  }
  
  double D_2_neg1_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.25 + RzRbar3*(0.e-17 + (0.75 + 0.5*RzRbar3)*RzRbar3))/Power(Mag30,2);
  }
  
  double D_2_0_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(0.61237243569579452 - 0.612372435695794525*Power(RzRbar3,2)))/(Mag12*Mag30);
  }
  
  double D_2_1_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.25 + RzRbar3*(0.e-17 + (-0.75 + 0.5*RzRbar3)*RzRbar3))/Power(Mag12,2);
  }
  
  double D_2_2_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.25*Mag30 + RzRbar3*(-0.75*Mag30 + RzRbar3*(0.75*Mag30 - 0.25*Mag30*RzRbar3)))/Power(Mag12,3);
  }
  
  double D_2_neg2_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.61237243569579452*Power(Mag12,2) + RzRbar3*(1.22474487139158905*Power(Mag12,2) + 0.612372435695794525*Power(Mag12,2)*RzRbar3))/Power(Mag30,2);
  }
  
  double D_2_neg1_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(-1.22474487139158905*Mag12 - 1.22474487139158905*Mag12*RzRbar3))/Mag30;
  }
  
  double D_2_0_0() {
    return -0.5 + 1.5*Power(RzRbar3,2);
  }
  
  double D_2_1_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (RzRbar3*(1.22474487139158905*Mag30 - 1.22474487139158905*Mag30*RzRbar3))/Mag12;
  }
  
  double D_2_2_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.61237243569579452*Power(Mag30,2) + RzRbar3*(-1.22474487139158905*Power(Mag30,2) + 0.612372435695794525*Power(Mag30,2)*RzRbar3))/Power(Mag12,2);
  }
  
  double D_2_neg2_1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-1.*Power(Mag12,3) - 1.*Power(Mag12,3)*RzRbar3)/Mag30;
  }
  
  double D_2_neg1_1() {
    return 1.*Power(Mag12,2) + 2.*Power(Mag12,2)*RzRbar3;
  }
  
  double D_2_0_1() {
    return -2.4494897427831781*Mag12*Mag30*RzRbar3;
  }
  
  double D_2_1_1() {
    return -1.*Power(Mag30,2) + 2.*Power(Mag30,2)*RzRbar3;
  }
  
  double D_2_2_1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (1.*Power(Mag30,3) - 1.*Power(Mag30,3)*RzRbar3)/Mag12;
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
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.25 + (0.5 + 0.25*RzRbar3)*RzRbar3)/Power(Mag30,2);
  }
  
  double D_1_0_neg1() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.353553390593273762 - 0.353553390593273762*Power(RzRbar3,2))/(Mag12*Mag30);
  }
  
  double D_1_1_neg1() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.25 + (-0.5 + 0.25*RzRbar3)*RzRbar3)/Power(Mag12,2);
  }
  
  double D_1_neg1_0() {
    if (Mag_Rz_3_0==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (-0.70710678118654752*Mag12 - 0.707106781186547524*Mag12*RzRbar3)/Mag30;
  }
  
  double D_1_0_0() {
    return RzRbar3;
  }
  
  double D_1_1_0() {
    if (Mag_Rz_1_2==0.0) { // Test equality because precise value was set in SetQuaternion
      return 0.0;
    }
    return (0.70710678118654752*Mag30 - 0.707106781186547524*Mag30*RzRbar3)/Mag12;
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
  
