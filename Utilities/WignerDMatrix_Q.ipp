namespace WignerDMatrixQLocal {
  
  void Uninitialized(const double QzQbar_z, double& Mag) {
    std::cerr << "\nThis matrix has not yet been initialized with L,M,MP information." << std::endl;
    throw("Trying to use an uninitialized Wigner D matrix.");
  }
  
  void D_0_0_0(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_1_neg1_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.25 + (0.5 + 0.25*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_1_0_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.353553390593273762 - 0.353553390593273762*pow(QzQbar_z,2);
    return;
  }
  
  void D_1_1_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.25 + (-0.5 + 0.25*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_1_neg1_0(const double QzQbar_z, double& Mag) {
    Mag = -0.70710678118654752 - 0.707106781186547524*QzQbar_z;
    return;
  }
  
  void D_1_0_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z;
    return;
  }
  
  void D_1_1_0(const double QzQbar_z, double& Mag) {
    Mag = 0.70710678118654752 - 0.707106781186547524*QzQbar_z;
    return;
  }
  
  void D_1_neg1_1(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_1_0_1(const double QzQbar_z, double& Mag) {
    Mag = -1.41421356237309505;
    return;
  }
  
  void D_1_1_1(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_2_neg2_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.0625 + QzQbar_z*(0.25 + QzQbar_z*(0.375 + (0.25 + 0.0625*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_2_neg1_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.125 + QzQbar_z*(0.25 + QzQbar_z*(0.e-17 + (-0.25 - 0.125*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_2_0_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.153093108923948631 + pow(QzQbar_z,2)*(-0.306186217847897262 + 0.153093108923948631*pow(QzQbar_z,2));
    return;
  }
  
  void D_2_1_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.125 + QzQbar_z*(-0.25 + QzQbar_z*(0.e-17 + (0.25 - 0.125*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_2_2_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.0625 + QzQbar_z*(-0.25 + QzQbar_z*(0.375 + (-0.25 + 0.0625*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_2_neg2_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.25 + QzQbar_z*(-0.75 + (-0.75 - 0.25*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_2_neg1_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.25 + QzQbar_z*(0.e-17 + (0.75 + 0.5*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_2_0_neg1(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(0.61237243569579452 - 0.612372435695794525*pow(QzQbar_z,2));
    return;
  }
  
  void D_2_1_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.25 + QzQbar_z*(0.e-17 + (-0.75 + 0.5*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_2_2_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.25 + QzQbar_z*(-0.75 + (0.75 - 0.25*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_2_neg2_0(const double QzQbar_z, double& Mag) {
    Mag = 0.61237243569579452 + (1.22474487139158905 + 0.612372435695794525*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_2_neg1_0(const double QzQbar_z, double& Mag) {
    Mag = (-1.22474487139158905 - 1.22474487139158905*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_2_0_0(const double QzQbar_z, double& Mag) {
    Mag = -0.5 + 1.5*pow(QzQbar_z,2);
    return;
  }
  
  void D_2_1_0(const double QzQbar_z, double& Mag) {
    Mag = (1.22474487139158905 - 1.22474487139158905*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_2_2_0(const double QzQbar_z, double& Mag) {
    Mag = 0.61237243569579452 + (-1.22474487139158905 + 0.612372435695794525*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_2_neg2_1(const double QzQbar_z, double& Mag) {
    Mag = -1. - 1.*QzQbar_z;
    return;
  }
  
  void D_2_neg1_1(const double QzQbar_z, double& Mag) {
    Mag = 1. + 2.*QzQbar_z;
    return;
  }
  
  void D_2_0_1(const double QzQbar_z, double& Mag) {
    Mag = -2.4494897427831781*QzQbar_z;
    return;
  }
  
  void D_2_1_1(const double QzQbar_z, double& Mag) {
    Mag = -1. + 2.*QzQbar_z;
    return;
  }
  
  void D_2_2_1(const double QzQbar_z, double& Mag) {
    Mag = 1. - 1.*QzQbar_z;
    return;
  }
  
  void D_2_neg2_2(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_2_neg1_2(const double QzQbar_z, double& Mag) {
    Mag = -2.;
    return;
  }
  
  void D_2_0_2(const double QzQbar_z, double& Mag) {
    Mag = 2.4494897427831781;
    return;
  }
  
  void D_2_1_2(const double QzQbar_z, double& Mag) {
    Mag = -2.;
    return;
  }
  
  void D_2_2_2(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_3_neg3_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.015625 + QzQbar_z*(0.09375 + QzQbar_z*(0.234375 + QzQbar_z*(0.3125 + QzQbar_z*(0.234375 + (0.09375 + 0.015625*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_3_neg2_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.038273277230987158 + QzQbar_z*(0.15309310892394863 + QzQbar_z*(0.19136638615493579 + QzQbar_z*(0.e-17 + QzQbar_z*(-0.19136638615493579 + (-0.153093108923948631 - 0.0382732772309871578*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_3_neg1_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.060515364784490889 + QzQbar_z*(0.12103072956898178 + QzQbar_z*(-0.06051536478449089 + QzQbar_z*(-0.24206145913796356 + QzQbar_z*(-0.06051536478449089 + (0.121030729568981778 + 0.0605153647844908888*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_3_0_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.069877124296868428 + pow(QzQbar_z,2)*(-0.209631372890605284 + pow(QzQbar_z,2)*(0.209631372890605284 - 0.069877124296868428*pow(QzQbar_z,2)));
    return;
  }
  
  void D_3_1_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.060515364784490889 + QzQbar_z*(-0.12103072956898178 + QzQbar_z*(-0.06051536478449089 + QzQbar_z*(0.24206145913796356 + QzQbar_z*(-0.06051536478449089 + (-0.121030729568981778 + 0.0605153647844908888*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_3_2_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.038273277230987158 + QzQbar_z*(-0.15309310892394863 + QzQbar_z*(0.19136638615493579 + QzQbar_z*(0.e-17 + QzQbar_z*(-0.19136638615493579 + (0.153093108923948631 - 0.0382732772309871578*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_3_3_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.015625 + QzQbar_z*(-0.09375 + QzQbar_z*(0.234375 + QzQbar_z*(-0.3125 + QzQbar_z*(0.234375 + (-0.09375 + 0.015625*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_3_neg3_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.076546554461974316 + QzQbar_z*(-0.38273277230987158 + QzQbar_z*(-0.76546554461974316 + QzQbar_z*(-0.76546554461974316 + (-0.382732772309871578 - 0.0765465544619743156*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_3_neg2_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.125 + QzQbar_z*(-0.3125 + QzQbar_z*(0.e-17 + QzQbar_z*(0.625 + (0.625 + 0.1875*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_3_neg1_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.098821176880261854 + QzQbar_z*(0.09882117688026185 + QzQbar_z*(0.59292706128157112 + QzQbar_z*(0.19764235376052371 + (-0.49410588440130927 - 0.296463530640785562*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_3_0_neg2(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(0.34232659844072882 + pow(QzQbar_z,2)*(-0.68465319688145764 + 0.342326598440728821*pow(QzQbar_z,2)));
    return;
  }
  
  void D_3_1_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.098821176880261854 + QzQbar_z*(0.09882117688026185 + QzQbar_z*(-0.59292706128157112 + QzQbar_z*(0.19764235376052371 + (0.49410588440130927 - 0.296463530640785562*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_3_2_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.125 + QzQbar_z*(-0.3125 + QzQbar_z*(0.e-17 + QzQbar_z*(0.625 + (-0.625 + 0.1875*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_3_3_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.076546554461974316 + QzQbar_z*(-0.38273277230987158 + QzQbar_z*(0.76546554461974316 + QzQbar_z*(-0.76546554461974316 + (0.382732772309871578 - 0.0765465544619743156*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_3_neg3_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.24206145913796356 + QzQbar_z*(0.96824583655185422 + QzQbar_z*(1.45236875482778133 + (0.96824583655185422 + 0.242061459137963555*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_3_neg2_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.197642353760523708 + QzQbar_z*(0.e-17 + QzQbar_z*(-1.18585412256314225 + (-1.58113883008418967 - 0.59292706128157112*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_3_neg1_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.0625 + QzQbar_z*(-0.75 + QzQbar_z*(-0.375 + (1.25 + 0.9375*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_3_0_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.216506350946109662 + pow(QzQbar_z,2)*(1.29903810567665797 - 1.08253175473054831*pow(QzQbar_z,2));
    return;
  }
  
  void D_3_1_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.0625 + QzQbar_z*(0.75 + QzQbar_z*(-0.375 + (-1.25 + 0.9375*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_3_2_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.197642353760523708 + QzQbar_z*(0.e-17 + QzQbar_z*(-1.18585412256314225 + (1.58113883008418967 - 0.59292706128157112*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_3_3_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.24206145913796356 + QzQbar_z*(-0.96824583655185422 + QzQbar_z*(1.45236875482778133 + (-0.96824583655185422 + 0.242061459137963555*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_3_neg3_0(const double QzQbar_z, double& Mag) {
    Mag = -0.55901699437494742 + QzQbar_z*(-1.67705098312484227 + (-1.67705098312484227 - 0.559016994374947424*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_3_neg2_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(1.36930639376291528 + QzQbar_z*(2.73861278752583057 + 1.36930639376291528*QzQbar_z));
    return;
  }
  
  void D_3_neg1_0(const double QzQbar_z, double& Mag) {
    Mag = 0.433012701892219323 + QzQbar_z*(0.433012701892219323 + (-2.16506350946109662 - 2.16506350946109662*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_3_0_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-1.5 + 2.5*pow(QzQbar_z,2));
    return;
  }
  
  void D_3_1_0(const double QzQbar_z, double& Mag) {
    Mag = -0.433012701892219323 + QzQbar_z*(0.433012701892219323 + (2.16506350946109662 - 2.16506350946109662*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_3_2_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(1.36930639376291528 + QzQbar_z*(-2.73861278752583057 + 1.36930639376291528*QzQbar_z));
    return;
  }
  
  void D_3_3_0(const double QzQbar_z, double& Mag) {
    Mag = 0.55901699437494742 + QzQbar_z*(-1.67705098312484227 + (1.67705098312484227 - 0.559016994374947424*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_3_neg3_1(const double QzQbar_z, double& Mag) {
    Mag = 0.96824583655185422 + (1.93649167310370844 + 0.968245836551854221*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_3_neg2_1(const double QzQbar_z, double& Mag) {
    Mag = -0.79056941504209483 + (-3.16227766016837933 - 2.3717082451262845*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_3_neg1_1(const double QzQbar_z, double& Mag) {
    Mag = -0.25 + QzQbar_z*(2.5 + 3.75*QzQbar_z);
    return;
  }
  
  void D_3_0_1(const double QzQbar_z, double& Mag) {
    Mag = 0.86602540378443865 - 4.33012701892219323*pow(QzQbar_z,2);
    return;
  }
  
  void D_3_1_1(const double QzQbar_z, double& Mag) {
    Mag = -0.25 + QzQbar_z*(-2.5 + 3.75*QzQbar_z);
    return;
  }
  
  void D_3_2_1(const double QzQbar_z, double& Mag) {
    Mag = -0.79056941504209483 + (3.16227766016837933 - 2.3717082451262845*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_3_3_1(const double QzQbar_z, double& Mag) {
    Mag = 0.96824583655185422 + (-1.93649167310370844 + 0.968245836551854221*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_3_neg3_2(const double QzQbar_z, double& Mag) {
    Mag = -1.22474487139158905 - 1.22474487139158905*QzQbar_z;
    return;
  }
  
  void D_3_neg2_2(const double QzQbar_z, double& Mag) {
    Mag = 2. + 3.*QzQbar_z;
    return;
  }
  
  void D_3_neg1_2(const double QzQbar_z, double& Mag) {
    Mag = -1.58113883008418967 - 4.743416490252569*QzQbar_z;
    return;
  }
  
  void D_3_0_2(const double QzQbar_z, double& Mag) {
    Mag = 5.47722557505166113*QzQbar_z;
    return;
  }
  
  void D_3_1_2(const double QzQbar_z, double& Mag) {
    Mag = 1.58113883008418967 - 4.743416490252569*QzQbar_z;
    return;
  }
  
  void D_3_2_2(const double QzQbar_z, double& Mag) {
    Mag = -2. + 3.*QzQbar_z;
    return;
  }
  
  void D_3_3_2(const double QzQbar_z, double& Mag) {
    Mag = 1.22474487139158905 - 1.22474487139158905*QzQbar_z;
    return;
  }
  
  void D_3_neg3_3(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_3_neg2_3(const double QzQbar_z, double& Mag) {
    Mag = -2.4494897427831781;
    return;
  }
  
  void D_3_neg1_3(const double QzQbar_z, double& Mag) {
    Mag = 3.87298334620741689;
    return;
  }
  
  void D_3_0_3(const double QzQbar_z, double& Mag) {
    Mag = -4.47213595499957939;
    return;
  }
  
  void D_3_1_3(const double QzQbar_z, double& Mag) {
    Mag = 3.87298334620741689;
    return;
  }
  
  void D_3_2_3(const double QzQbar_z, double& Mag) {
    Mag = -2.4494897427831781;
    return;
  }
  
  void D_3_3_3(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_4_neg4_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.00390625 + QzQbar_z*(0.03125 + QzQbar_z*(0.109375 + QzQbar_z*(0.21875 + QzQbar_z*(0.2734375 + QzQbar_z*(0.21875 + QzQbar_z*(0.109375 + (0.03125 + 0.00390625*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_4_neg3_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.0110485434560398051 + QzQbar_z*(0.06629126073623883 + QzQbar_z*(0.15467960838455727 + QzQbar_z*(0.15467960838455727 + QzQbar_z*(0.e-17 + QzQbar_z*(-0.15467960838455727 + QzQbar_z*(-0.154679608384557271 + (-0.06629126073623883 - 0.0110485434560398051*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_4_neg2_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.020669932117692114 + QzQbar_z*(0.08267972847076846 + QzQbar_z*(0.08267972847076846 + QzQbar_z*(-0.08267972847076846 + QzQbar_z*(-0.20669932117692114 + QzQbar_z*(-0.08267972847076846 + QzQbar_z*(0.08267972847076846 + (0.082679728470768456 + 0.020669932117692114*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_4_neg1_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.029231698334171417 + QzQbar_z*(0.05846339666834283 + QzQbar_z*(-0.05846339666834283 + QzQbar_z*(-0.1753901900050285 + QzQbar_z*(0.e-16 + QzQbar_z*(0.1753901900050285 + QzQbar_z*(0.05846339666834283 + (-0.058463396668342834 - 0.0292316983341714171*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_4_0_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.032682032286487326 + pow(QzQbar_z,2)*(-0.130728129145949304 + pow(QzQbar_z,2)*(0.196092193718923957 + pow(QzQbar_z,2)*(-0.130728129145949304 + 0.0326820322864873261*pow(QzQbar_z,2))));
    return;
  }
  
  void D_4_1_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.029231698334171417 + QzQbar_z*(-0.05846339666834283 + QzQbar_z*(-0.05846339666834283 + QzQbar_z*(0.1753901900050285 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.1753901900050285 + QzQbar_z*(0.05846339666834283 + (0.058463396668342834 - 0.0292316983341714171*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_4_2_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.020669932117692114 + QzQbar_z*(-0.08267972847076846 + QzQbar_z*(0.08267972847076846 + QzQbar_z*(0.08267972847076846 + QzQbar_z*(-0.20669932117692114 + QzQbar_z*(0.08267972847076846 + QzQbar_z*(0.08267972847076846 + (-0.082679728470768456 + 0.020669932117692114*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_4_3_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.0110485434560398051 + QzQbar_z*(-0.06629126073623883 + QzQbar_z*(0.15467960838455727 + QzQbar_z*(-0.15467960838455727 + QzQbar_z*(0.e-17 + QzQbar_z*(0.15467960838455727 + QzQbar_z*(-0.154679608384557271 + (0.06629126073623883 - 0.0110485434560398051*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_4_4_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.00390625 + QzQbar_z*(-0.03125 + QzQbar_z*(0.109375 + QzQbar_z*(-0.21875 + QzQbar_z*(0.2734375 + QzQbar_z*(-0.21875 + QzQbar_z*(0.109375 + (-0.03125 + 0.00390625*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_4_neg4_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.02209708691207961 + QzQbar_z*(-0.15467960838455727 + QzQbar_z*(-0.46403882515367181 + QzQbar_z*(-0.77339804192278635 + QzQbar_z*(-0.77339804192278635 + QzQbar_z*(-0.46403882515367181 + (-0.154679608384557271 - 0.0220970869120796101*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_4_neg3_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.046875 + QzQbar_z*(-0.21875 + QzQbar_z*(-0.328125 + QzQbar_z*(0.e-16 + QzQbar_z*(0.546875 + QzQbar_z*(0.65625 + (0.328125 + 0.0625*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_4_neg2_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.058463396668342834 + QzQbar_z*(-0.11692679333668567 + QzQbar_z*(0.1753901900050285 + QzQbar_z*(0.5846339666834283 + QzQbar_z*(0.2923169833417142 + QzQbar_z*(-0.350780380010057 + (-0.40924377667839984 - 0.116926793336685668*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_4_neg1_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.041339864235384228 + QzQbar_z*(0.08267972847076846 + QzQbar_z*(0.37205877811845805 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.6200979635307634 + QzQbar_z*(-0.24803918541230537 + (0.2893790496476896 + 0.165359456941536912*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_4_0_neg3(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(0.184877493221863001 + pow(QzQbar_z,2)*(-0.554632479665589 + pow(QzQbar_z,2)*(0.554632479665589 - 0.184877493221863001*pow(QzQbar_z,2))));
    return;
  }
  
  void D_4_1_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.041339864235384228 + QzQbar_z*(0.08267972847076846 + QzQbar_z*(-0.37205877811845805 + QzQbar_z*(0.e-16 + QzQbar_z*(0.6200979635307634 + QzQbar_z*(-0.24803918541230537 + (-0.2893790496476896 + 0.165359456941536912*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_4_2_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.058463396668342834 + QzQbar_z*(-0.11692679333668567 + QzQbar_z*(-0.1753901900050285 + QzQbar_z*(0.5846339666834283 + QzQbar_z*(-0.2923169833417142 + QzQbar_z*(-0.350780380010057 + (0.40924377667839984 - 0.116926793336685668*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_4_3_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.046875 + QzQbar_z*(-0.21875 + QzQbar_z*(0.328125 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.546875 + QzQbar_z*(0.65625 + (-0.328125 + 0.0625*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_4_4_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.02209708691207961 + QzQbar_z*(-0.15467960838455727 + QzQbar_z*(0.46403882515367181 + QzQbar_z*(-0.77339804192278635 + QzQbar_z*(0.77339804192278635 + QzQbar_z*(-0.46403882515367181 + (0.154679608384557271 - 0.0220970869120796101*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_4_neg4_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.082679728470768456 + QzQbar_z*(0.49607837082461074 + QzQbar_z*(1.24019592706152684 + QzQbar_z*(1.65359456941536912 + QzQbar_z*(1.24019592706152684 + (0.496078370824610736 + 0.082679728470768456*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_4_neg3_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.116926793336685668 + QzQbar_z*(0.350780380010057 + QzQbar_z*(0.e-16 + QzQbar_z*(-1.1692679333668567 + QzQbar_z*(-1.753901900050285 + (-1.05234114003017101 - 0.233853586673371337*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_4_neg2_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.0625 + QzQbar_z*(-0.1875 + QzQbar_z*(-0.9375 + QzQbar_z*(-0.625 + QzQbar_z*(0.9375 + (1.3125 + 0.4375*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_4_neg1_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.04419417382415922 + QzQbar_z*(-0.39774756441743298 + QzQbar_z*(0.e-17 + QzQbar_z*(1.3258252147247766 + QzQbar_z*(0.6629126073623883 + (-0.92807765030734363 - 0.61871843353822908*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_4_0_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.098821176880261854 + pow(QzQbar_z,2)*(0.88939059192235669 + pow(QzQbar_z,2)*(-1.48231765320392781 + 0.69174823816183298*pow(QzQbar_z,2)));
    return;
  }
  
  void D_4_1_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.04419417382415922 + QzQbar_z*(0.39774756441743298 + QzQbar_z*(0.e-17 + QzQbar_z*(-1.3258252147247766 + QzQbar_z*(0.6629126073623883 + (0.92807765030734363 - 0.61871843353822908*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_4_2_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.0625 + QzQbar_z*(0.1875 + QzQbar_z*(-0.9375 + QzQbar_z*(0.625 + QzQbar_z*(0.9375 + (-1.3125 + 0.4375*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_4_3_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.116926793336685668 + QzQbar_z*(-0.350780380010057 + QzQbar_z*(0.e-16 + QzQbar_z*(1.1692679333668567 + QzQbar_z*(-1.753901900050285 + (1.05234114003017101 - 0.233853586673371337*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_4_4_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.082679728470768456 + QzQbar_z*(-0.49607837082461074 + QzQbar_z*(1.24019592706152684 + QzQbar_z*(-1.65359456941536912 + QzQbar_z*(1.24019592706152684 + (-0.496078370824610736 + 0.082679728470768456*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_4_neg4_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.23385358667337134 + QzQbar_z*(-1.16926793336685668 + QzQbar_z*(-2.33853586673371337 + QzQbar_z*(-2.33853586673371337 + (-1.16926793336685668 - 0.233853586673371337*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_4_neg3_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.165359456941536912 + QzQbar_z*(0.e-17 + QzQbar_z*(1.6535945694153691 + QzQbar_z*(3.3071891388307382 + (2.48039185412305368 + 0.66143782776614765*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_4_neg2_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.088388347648318441 + QzQbar_z*(0.88388347648318441 + QzQbar_z*(0.8838834764831844 + QzQbar_z*(-1.7677669529663688 + (-3.0935921676911454 - 1.23743686707645817*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_4_neg1_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.1875 + QzQbar_z*(0.e-17 + QzQbar_z*(-1.875 + QzQbar_z*(-1.25 + QzQbar_z*(2.1875 + 1.75*QzQbar_z))));
    return;
  }
  
  void D_4_0_neg1(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-0.83852549156242114 + pow(QzQbar_z,2)*(2.79508497187473712 - 1.95655948031231598*pow(QzQbar_z,2)));
    return;
  }
  
  void D_4_1_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.1875 + QzQbar_z*(0.e-17 + QzQbar_z*(1.875 + QzQbar_z*(-1.25 + QzQbar_z*(-2.1875 + 1.75*QzQbar_z))));
    return;
  }
  
  void D_4_2_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.088388347648318441 + QzQbar_z*(0.88388347648318441 + QzQbar_z*(-0.8838834764831844 + QzQbar_z*(-1.7677669529663688 + (3.0935921676911454 - 1.23743686707645817*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_4_3_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.165359456941536912 + QzQbar_z*(0.e-17 + QzQbar_z*(-1.6535945694153691 + QzQbar_z*(3.3071891388307382 + (-2.48039185412305368 + 0.66143782776614765*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_4_4_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.23385358667337134 + QzQbar_z*(-1.16926793336685668 + QzQbar_z*(2.33853586673371337 + QzQbar_z*(-2.33853586673371337 + (1.16926793336685668 - 0.233853586673371337*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_4_neg4_0(const double QzQbar_z, double& Mag) {
    Mag = 0.52291251658379722 + QzQbar_z*(2.09165006633518887 + QzQbar_z*(3.1374750995027833 + (2.09165006633518887 + 0.522912516583797217*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_4_neg3_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-1.47901994577490401 + QzQbar_z*(-4.437059837324712 + (-4.43705983732471203 - 1.47901994577490401*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_4_neg2_0(const double QzQbar_z, double& Mag) {
    Mag = -0.39528470752104742 + QzQbar_z*(-0.79056941504209483 + QzQbar_z*(2.3717082451262845 + QzQbar_z*(5.5339859052946638 + 2.76699295264733192*QzQbar_z)));
    return;
  }
  
  void D_4_neg1_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(1.67705098312484227 + QzQbar_z*(1.67705098312484227 + (-3.91311896062463197 - 3.91311896062463197*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_4_0_0(const double QzQbar_z, double& Mag) {
    Mag = 0.375 + pow(QzQbar_z,2)*(-3.75 + 4.375*pow(QzQbar_z,2));
    return;
  }
  
  void D_4_1_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-1.67705098312484227 + QzQbar_z*(1.67705098312484227 + (3.91311896062463197 - 3.91311896062463197*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_4_2_0(const double QzQbar_z, double& Mag) {
    Mag = -0.39528470752104742 + QzQbar_z*(0.79056941504209483 + QzQbar_z*(2.3717082451262845 + QzQbar_z*(-5.5339859052946638 + 2.76699295264733192*QzQbar_z)));
    return;
  }
  
  void D_4_3_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(1.47901994577490401 + QzQbar_z*(-4.437059837324712 + (4.43705983732471203 - 1.47901994577490401*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_4_4_0(const double QzQbar_z, double& Mag) {
    Mag = 0.52291251658379722 + QzQbar_z*(-2.09165006633518887 + QzQbar_z*(3.1374750995027833 + (-2.09165006633518887 + 0.522912516583797217*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_4_neg4_1(const double QzQbar_z, double& Mag) {
    Mag = -0.93541434669348535 + QzQbar_z*(-2.80624304008045604 + (-2.80624304008045604 - 0.935414346693485346*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_4_neg3_1(const double QzQbar_z, double& Mag) {
    Mag = 0.66143782776614765 + QzQbar_z*(3.9686269665968859 + QzQbar_z*(5.9529404498953288 + 2.64575131106459059*QzQbar_z));
    return;
  }
  
  void D_4_neg2_1(const double QzQbar_z, double& Mag) {
    Mag = 0.353553390593273762 + QzQbar_z*(-2.12132034355964257 + (-7.424621202458749 - 4.94974746830583267*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_4_neg1_1(const double QzQbar_z, double& Mag) {
    Mag = -0.75 + QzQbar_z*(-1.5 + QzQbar_z*(5.25 + 7.*QzQbar_z));
    return;
  }
  
  void D_4_0_1(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(3.35410196624968454 - 7.8262379212492639*pow(QzQbar_z,2));
    return;
  }
  
  void D_4_1_1(const double QzQbar_z, double& Mag) {
    Mag = 0.75 + QzQbar_z*(-1.5 + QzQbar_z*(-5.25 + 7.*QzQbar_z));
    return;
  }
  
  void D_4_2_1(const double QzQbar_z, double& Mag) {
    Mag = -0.353553390593273762 + QzQbar_z*(-2.12132034355964257 + (7.424621202458749 - 4.94974746830583267*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_4_3_1(const double QzQbar_z, double& Mag) {
    Mag = -0.66143782776614765 + QzQbar_z*(3.9686269665968859 + QzQbar_z*(-5.9529404498953288 + 2.64575131106459059*QzQbar_z));
    return;
  }
  
  void D_4_4_1(const double QzQbar_z, double& Mag) {
    Mag = 0.93541434669348535 + QzQbar_z*(-2.80624304008045604 + (2.80624304008045604 - 0.935414346693485346*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_4_neg4_2(const double QzQbar_z, double& Mag) {
    Mag = 1.3228756555322953 + QzQbar_z*(2.64575131106459059 + 1.3228756555322953*QzQbar_z);
    return;
  }
  
  void D_4_neg3_2(const double QzQbar_z, double& Mag) {
    Mag = -1.87082869338697069 + (-5.6124860801609121 - 3.74165738677394139*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_4_neg2_2(const double QzQbar_z, double& Mag) {
    Mag = 1. + QzQbar_z*(7. + 7.*QzQbar_z);
    return;
  }
  
  void D_4_neg1_2(const double QzQbar_z, double& Mag) {
    Mag = 0.70710678118654752 + (-4.94974746830583267 - 9.8994949366116653*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_4_0_2(const double QzQbar_z, double& Mag) {
    Mag = -1.58113883008418967 + 11.0679718105893277*pow(QzQbar_z,2);
    return;
  }
  
  void D_4_1_2(const double QzQbar_z, double& Mag) {
    Mag = 0.70710678118654752 + (4.94974746830583267 - 9.8994949366116653*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_4_2_2(const double QzQbar_z, double& Mag) {
    Mag = 1. + QzQbar_z*(-7. + 7.*QzQbar_z);
    return;
  }
  
  void D_4_3_2(const double QzQbar_z, double& Mag) {
    Mag = -1.87082869338697069 + (5.6124860801609121 - 3.74165738677394139*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_4_4_2(const double QzQbar_z, double& Mag) {
    Mag = 1.3228756555322953 + QzQbar_z*(-2.64575131106459059 + 1.3228756555322953*QzQbar_z);
    return;
  }
  
  void D_4_neg4_3(const double QzQbar_z, double& Mag) {
    Mag = -1.41421356237309505 - 1.41421356237309505*QzQbar_z;
    return;
  }
  
  void D_4_neg3_3(const double QzQbar_z, double& Mag) {
    Mag = 3. + 4.*QzQbar_z;
    return;
  }
  
  void D_4_neg2_3(const double QzQbar_z, double& Mag) {
    Mag = -3.74165738677394139 - 7.4833147735478828*QzQbar_z;
    return;
  }
  
  void D_4_neg1_3(const double QzQbar_z, double& Mag) {
    Mag = 2.64575131106459059 + 10.5830052442583624*QzQbar_z;
    return;
  }
  
  void D_4_0_3(const double QzQbar_z, double& Mag) {
    Mag = -11.8321595661992321*QzQbar_z;
    return;
  }
  
  void D_4_1_3(const double QzQbar_z, double& Mag) {
    Mag = -2.64575131106459059 + 10.5830052442583624*QzQbar_z;
    return;
  }
  
  void D_4_2_3(const double QzQbar_z, double& Mag) {
    Mag = 3.74165738677394139 - 7.4833147735478828*QzQbar_z;
    return;
  }
  
  void D_4_3_3(const double QzQbar_z, double& Mag) {
    Mag = -3. + 4.*QzQbar_z;
    return;
  }
  
  void D_4_4_3(const double QzQbar_z, double& Mag) {
    Mag = 1.41421356237309505 - 1.41421356237309505*QzQbar_z;
    return;
  }
  
  void D_4_neg4_4(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_4_neg3_4(const double QzQbar_z, double& Mag) {
    Mag = -2.8284271247461901;
    return;
  }
  
  void D_4_neg2_4(const double QzQbar_z, double& Mag) {
    Mag = 5.29150262212918118;
    return;
  }
  
  void D_4_neg1_4(const double QzQbar_z, double& Mag) {
    Mag = -7.48331477354788277;
    return;
  }
  
  void D_4_0_4(const double QzQbar_z, double& Mag) {
    Mag = 8.36660026534075548;
    return;
  }
  
  void D_4_1_4(const double QzQbar_z, double& Mag) {
    Mag = -7.48331477354788277;
    return;
  }
  
  void D_4_2_4(const double QzQbar_z, double& Mag) {
    Mag = 5.29150262212918118;
    return;
  }
  
  void D_4_3_4(const double QzQbar_z, double& Mag) {
    Mag = -2.8284271247461901;
    return;
  }
  
  void D_4_4_4(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_5_neg5_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0009765625 + QzQbar_z*(0.009765625 + QzQbar_z*(0.0439453125 + QzQbar_z*(0.1171875 + QzQbar_z*(0.205078125 + QzQbar_z*(0.24609375 + QzQbar_z*(0.205078125 + QzQbar_z*(0.1171875 + QzQbar_z*(0.0439453125 + (0.009765625 + 0.0009765625*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_5_neg4_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0030881617775081829 + QzQbar_z*(0.024705294220065464 + QzQbar_z*(0.08338036799272094 + QzQbar_z*(0.14823176532039278 + QzQbar_z*(0.12970279465534368 + QzQbar_z*(0.e-17 + QzQbar_z*(-0.12970279465534368 + QzQbar_z*(-0.14823176532039278 + QzQbar_z*(-0.083380367992720939 + (-0.0247052942200654635 - 0.00308816177750818294*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_5_neg3_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0065509804028314151 + QzQbar_z*(0.039305882416988491 + QzQbar_z*(0.0851627452368084 + QzQbar_z*(0.05240784322265132 + QzQbar_z*(-0.09171372563963981 + QzQbar_z*(-0.18342745127927962 + QzQbar_z*(-0.09171372563963981 + QzQbar_z*(0.05240784322265132 + QzQbar_z*(0.085162745236808397 + (0.039305882416988491 + 0.00655098040283141513*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_5_neg2_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.010697706201272776 + QzQbar_z*(0.0427908248050911 + QzQbar_z*(0.03209311860381833 + QzQbar_z*(-0.0855816496101822 + QzQbar_z*(-0.1497678868178189 + QzQbar_z*(0.e-16 + QzQbar_z*(0.1497678868178189 + QzQbar_z*(0.08558164961018221 + QzQbar_z*(-0.03209311860381833 + (-0.042790824805091103 - 0.0106977062012727757*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_5_neg1_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.014151735103700624 + QzQbar_z*(0.02830347020740125 + QzQbar_z*(-0.04245520531110187 + QzQbar_z*(-0.113213880829605 + QzQbar_z*(0.0283034702074012 + QzQbar_z*(0.1698208212444075 + QzQbar_z*(0.0283034702074012 + QzQbar_z*(-0.11321388082960499 + QzQbar_z*(-0.04245520531110187 + (0.028303470207401247 + 0.0141517351037006236*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_5_0_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0155024490882690855 + pow(QzQbar_z,2)*(-0.077512245441345427 + pow(QzQbar_z,2)*(0.155024490882690855 + pow(QzQbar_z,2)*(-0.155024490882690855 + pow(QzQbar_z,2)*(0.077512245441345427 - 0.0155024490882690855*pow(QzQbar_z,2)))));
    return;
  }
  
  void D_5_1_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.014151735103700624 + QzQbar_z*(-0.02830347020740125 + QzQbar_z*(-0.04245520531110187 + QzQbar_z*(0.113213880829605 + QzQbar_z*(0.0283034702074012 + QzQbar_z*(-0.1698208212444075 + QzQbar_z*(0.0283034702074012 + QzQbar_z*(0.11321388082960499 + QzQbar_z*(-0.04245520531110187 + (-0.028303470207401247 + 0.0141517351037006236*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_5_2_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.010697706201272776 + QzQbar_z*(-0.0427908248050911 + QzQbar_z*(0.03209311860381833 + QzQbar_z*(0.0855816496101822 + QzQbar_z*(-0.1497678868178189 + QzQbar_z*(0.e-16 + QzQbar_z*(0.1497678868178189 + QzQbar_z*(-0.08558164961018221 + QzQbar_z*(-0.03209311860381833 + (0.042790824805091103 - 0.0106977062012727757*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_5_3_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0065509804028314151 + QzQbar_z*(-0.039305882416988491 + QzQbar_z*(0.0851627452368084 + QzQbar_z*(-0.05240784322265132 + QzQbar_z*(-0.09171372563963981 + QzQbar_z*(0.18342745127927962 + QzQbar_z*(-0.09171372563963981 + QzQbar_z*(-0.05240784322265132 + QzQbar_z*(0.085162745236808397 + (-0.039305882416988491 + 0.00655098040283141513*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_5_4_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0030881617775081829 + QzQbar_z*(-0.024705294220065464 + QzQbar_z*(0.08338036799272094 + QzQbar_z*(-0.14823176532039278 + QzQbar_z*(0.12970279465534368 + QzQbar_z*(0.e-17 + QzQbar_z*(-0.12970279465534368 + QzQbar_z*(0.14823176532039278 + QzQbar_z*(-0.083380367992720939 + (0.0247052942200654635 - 0.00308816177750818294*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_5_5_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0009765625 + QzQbar_z*(-0.009765625 + QzQbar_z*(0.0439453125 + QzQbar_z*(-0.1171875 + QzQbar_z*(0.205078125 + QzQbar_z*(-0.24609375 + QzQbar_z*(0.205078125 + QzQbar_z*(-0.1171875 + QzQbar_z*(0.0439453125 + (-0.009765625 + 0.0009765625*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_5_neg5_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.0061763235550163659 + QzQbar_z*(-0.055586911995147293 + QzQbar_z*(-0.22234764798058917 + QzQbar_z*(-0.51881117862137473 + QzQbar_z*(-0.7782167679320621 + QzQbar_z*(-0.7782167679320621 + QzQbar_z*(-0.51881117862137473 + QzQbar_z*(-0.222347647980589172 + (-0.055586911995147293 - 0.00617632355501636588*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_5_neg4_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.015625 + QzQbar_z*(-0.10546875 + QzQbar_z*(-0.28125 + QzQbar_z*(-0.328125 + QzQbar_z*(0.e-16 + QzQbar_z*(0.4921875 + QzQbar_z*(0.65625 + QzQbar_z*(0.421875 + (0.140625 + 0.01953125*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_5_neg3_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.024859222776089561 + QzQbar_z*(-0.1077232986963881 + QzQbar_z*(-0.09943689110435825 + QzQbar_z*(0.2320194125768359 + QzQbar_z*(0.5800485314420898 + QzQbar_z*(0.3480291188652539 + QzQbar_z*(-0.2320194125768359 + QzQbar_z*(-0.4308931947855524 + (-0.223733004984806053 - 0.041432037960149269*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_5_neg2_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.027063293868263708 + QzQbar_z*(-0.04059494080239556 + QzQbar_z*(0.1623797632095822 + QzQbar_z*(0.3788861141556919 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.5683291712335379 + QzQbar_z*(-0.3788861141556919 + QzQbar_z*(0.16237976320958225 + (0.24356964481437337 + 0.067658234670659269*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_5_neg1_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.01790068630842125 + QzQbar_z*(0.05370205892526375 + QzQbar_z*(0.214808235701055 + QzQbar_z*(-0.071602745233685 + QzQbar_z*(-0.5370205892526375 + QzQbar_z*(-0.1074041178505275 + QzQbar_z*(0.501219216635795 + QzQbar_z*(0.214808235701055 + (-0.16110617677579125 - 0.08950343154210625*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_5_0_neg4(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(0.098046096859461978 + pow(QzQbar_z,2)*(-0.39218438743784791 + pow(QzQbar_z,2)*(0.58827658115677187 + pow(QzQbar_z,2)*(-0.392184387437847913 + 0.0980460968594619783*pow(QzQbar_z,2)))));
    return;
  }
  
  void D_5_1_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.01790068630842125 + QzQbar_z*(0.05370205892526375 + QzQbar_z*(-0.214808235701055 + QzQbar_z*(-0.071602745233685 + QzQbar_z*(0.5370205892526375 + QzQbar_z*(-0.1074041178505275 + QzQbar_z*(-0.501219216635795 + QzQbar_z*(0.214808235701055 + (0.16110617677579125 - 0.08950343154210625*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_5_2_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.027063293868263708 + QzQbar_z*(-0.04059494080239556 + QzQbar_z*(-0.1623797632095822 + QzQbar_z*(0.3788861141556919 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.5683291712335379 + QzQbar_z*(0.3788861141556919 + QzQbar_z*(0.16237976320958225 + (-0.24356964481437337 + 0.067658234670659269*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_5_3_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.024859222776089561 + QzQbar_z*(-0.1077232986963881 + QzQbar_z*(0.09943689110435825 + QzQbar_z*(0.2320194125768359 + QzQbar_z*(-0.5800485314420898 + QzQbar_z*(0.3480291188652539 + QzQbar_z*(0.2320194125768359 + QzQbar_z*(-0.4308931947855524 + (0.223733004984806053 - 0.041432037960149269*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_5_4_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.015625 + QzQbar_z*(-0.10546875 + QzQbar_z*(0.28125 + QzQbar_z*(-0.328125 + QzQbar_z*(0.e-16 + QzQbar_z*(0.4921875 + QzQbar_z*(-0.65625 + QzQbar_z*(0.421875 + (-0.140625 + 0.01953125*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_5_5_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.0061763235550163659 + QzQbar_z*(-0.055586911995147293 + QzQbar_z*(0.22234764798058917 + QzQbar_z*(-0.51881117862137473 + QzQbar_z*(0.7782167679320621 + QzQbar_z*(-0.7782167679320621 + QzQbar_z*(0.51881117862137473 + QzQbar_z*(-0.222347647980589172 + (0.055586911995147293 - 0.00617632355501636588*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_5_neg5_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.026203921611325661 + QzQbar_z*(0.20963137289060528 + QzQbar_z*(0.73370980511711849 + QzQbar_z*(1.46741961023423699 + QzQbar_z*(1.83427451279279624 + QzQbar_z*(1.46741961023423699 + QzQbar_z*(0.73370980511711849 + (0.209631372890605284 + 0.0262039216113256605*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_5_neg4_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.049718445552179123 + QzQbar_z*(0.26516504294495532 + QzQbar_z*(0.4640388251536718 + QzQbar_z*(0.e-16 + QzQbar_z*(-1.1600970628841795 + QzQbar_z*(-1.8561553006146873 + QzQbar_z*(-1.39211647546101544 + (-0.53033008588991064 - 0.082864075920298538*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_5_neg3_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.05078125 + QzQbar_z*(0.09375 + QzQbar_z*(-0.328125 + QzQbar_z*(-1.09375 + QzQbar_z*(-0.8203125 + QzQbar_z*(0.65625 + QzQbar_z*(1.421875 + (0.84375 + 0.17578125*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_5_neg2_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.019136638615493579 + QzQbar_z*(-0.15309310892394863 + QzQbar_z*(-0.5358258812338202 + QzQbar_z*(0.e-16 + QzQbar_z*(1.3395647030845505 + QzQbar_z*(1.0716517624676404 + QzQbar_z*(-0.5358258812338202 + (-0.91855865354369179 - 0.287049579232403683*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_5_neg1_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.025315393353155704 + QzQbar_z*(-0.20252314682524563 + QzQbar_z*(0.1012615734126228 + QzQbar_z*(1.0126157341262282 + QzQbar_z*(0.253153933531557 + QzQbar_z*(-1.4176620277767194 + QzQbar_z*(-0.7088310138883597 + (0.6075694404757369 + 0.37973090029733556*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_5_0_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.04621937330546575 + pow(QzQbar_z,2)*(0.554632479665589 + pow(QzQbar_z,2)*(-1.38658119916397251 + pow(QzQbar_z,2)*(1.29414245255304101 - 0.415974359749191753*pow(QzQbar_z,2))));
    return;
  }
  
  void D_5_1_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.025315393353155704 + QzQbar_z*(0.20252314682524563 + QzQbar_z*(0.1012615734126228 + QzQbar_z*(-1.0126157341262282 + QzQbar_z*(0.253153933531557 + QzQbar_z*(1.4176620277767194 + QzQbar_z*(-0.7088310138883597 + (-0.6075694404757369 + 0.37973090029733556*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_5_2_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.019136638615493579 + QzQbar_z*(0.15309310892394863 + QzQbar_z*(-0.5358258812338202 + QzQbar_z*(0.e-16 + QzQbar_z*(1.3395647030845505 + QzQbar_z*(-1.0716517624676404 + QzQbar_z*(-0.5358258812338202 + (0.91855865354369179 - 0.287049579232403683*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_5_3_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.05078125 + QzQbar_z*(-0.09375 + QzQbar_z*(-0.328125 + QzQbar_z*(1.09375 + QzQbar_z*(-0.8203125 + QzQbar_z*(-0.65625 + QzQbar_z*(1.421875 + (-0.84375 + 0.17578125*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_5_4_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.049718445552179123 + QzQbar_z*(-0.26516504294495532 + QzQbar_z*(0.4640388251536718 + QzQbar_z*(0.e-16 + QzQbar_z*(-1.1600970628841795 + QzQbar_z*(1.8561553006146873 + QzQbar_z*(-1.39211647546101544 + (0.53033008588991064 - 0.082864075920298538*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_5_5_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.026203921611325661 + QzQbar_z*(-0.20963137289060528 + QzQbar_z*(0.73370980511711849 + QzQbar_z*(-1.46741961023423699 + QzQbar_z*(1.83427451279279624 + QzQbar_z*(-1.46741961023423699 + QzQbar_z*(0.73370980511711849 + (-0.209631372890605284 + 0.0262039216113256605*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_5_neg5_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.085581649610182205 + QzQbar_z*(-0.59907154727127544 + QzQbar_z*(-1.7972146418138263 + QzQbar_z*(-2.9953577363563772 + QzQbar_z*(-2.9953577363563772 + QzQbar_z*(-1.79721464181382631 + (-0.59907154727127544 - 0.0855816496101822052*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_5_neg4_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.108253175473054831 + QzQbar_z*(-0.37888611415569191 + QzQbar_z*(0.e-16 + QzQbar_z*(1.8944305707784595 + QzQbar_z*(3.7888611415569191 + QzQbar_z*(3.4099750274012272 + (1.51554445662276763 + 0.270632938682637077*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_5_neg3_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.038273277230987158 + QzQbar_z*(0.2679129406169101 + QzQbar_z*(1.3395647030845505 + QzQbar_z*(1.3395647030845505 + QzQbar_z*(-1.3395647030845505 + QzQbar_z*(-3.4828682280198314 + (-2.41121646555219094 - 0.57409915846480737*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_5_neg2_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.0625 + QzQbar_z*(0.4375 + QzQbar_z*(0.e-16 + QzQbar_z*(-2.1875 + QzQbar_z*(-2.1875 + QzQbar_z*(1.3125 + (2.625 + 0.9375*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_5_neg1_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.082679728470768456 + QzQbar_z*(-0.08267972847076846 + QzQbar_z*(-1.24019592706152684 + QzQbar_z*(-0.4133986423538423 + QzQbar_z*(2.893790496476896 + QzQbar_z*(1.7362742978861376 + (-1.7362742978861376 - 1.24019592706152684*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_5_0_neg2(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-0.45285552331841996 + pow(QzQbar_z,2)*(2.26427761659209978 + pow(QzQbar_z,2)*(-3.16998866322893969 + 1.35856656995525987*pow(QzQbar_z,2))));
    return;
  }
  
  void D_5_1_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.082679728470768456 + QzQbar_z*(-0.08267972847076846 + QzQbar_z*(1.24019592706152684 + QzQbar_z*(-0.4133986423538423 + QzQbar_z*(-2.893790496476896 + QzQbar_z*(1.7362742978861376 + (1.7362742978861376 - 1.24019592706152684*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_5_2_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.0625 + QzQbar_z*(0.4375 + QzQbar_z*(0.e-16 + QzQbar_z*(-2.1875 + QzQbar_z*(2.1875 + QzQbar_z*(1.3125 + (-2.625 + 0.9375*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_5_3_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.038273277230987158 + QzQbar_z*(0.2679129406169101 + QzQbar_z*(-1.3395647030845505 + QzQbar_z*(1.3395647030845505 + QzQbar_z*(1.3395647030845505 + QzQbar_z*(-3.4828682280198314 + (2.41121646555219094 - 0.57409915846480737*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_5_4_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.108253175473054831 + QzQbar_z*(-0.37888611415569191 + QzQbar_z*(0.e-16 + QzQbar_z*(1.8944305707784595 + QzQbar_z*(-3.7888611415569191 + QzQbar_z*(3.4099750274012272 + (-1.51554445662276763 + 0.270632938682637077*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_5_5_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.085581649610182205 + QzQbar_z*(-0.59907154727127544 + QzQbar_z*(1.7972146418138263 + QzQbar_z*(-2.9953577363563772 + QzQbar_z*(2.9953577363563772 + QzQbar_z*(-1.79721464181382631 + (0.59907154727127544 - 0.0855816496101822052*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_5_neg5_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.22642776165920998 + QzQbar_z*(1.35856656995525987 + QzQbar_z*(3.3964164248881497 + QzQbar_z*(4.5285552331841996 + QzQbar_z*(3.3964164248881497 + (1.35856656995525987 + 0.226427761659209978*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_5_neg4_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.14320549046737 + QzQbar_z*(0.e-17 + QzQbar_z*(-2.14808235701055 + QzQbar_z*(-5.7282196186948 + QzQbar_z*(-6.44424707103165 + (-3.43693177121688 - 0.71602745233685*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_5_neg3_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.101261573412622816 + QzQbar_z*(-1.01261573412622816 + QzQbar_z*(-1.5189236011893422 + QzQbar_z*(2.0252314682524563 + QzQbar_z*(6.582002271820483 + QzQbar_z*(5.4681249642816321 + 1.51892360118934224*QzQbar_z)))));
    return;
  }
  
  void D_5_neg2_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.165359456941536912 + QzQbar_z*(0.e-17 + QzQbar_z*(2.4803918541230537 + QzQbar_z*(3.3071891388307382 + QzQbar_z*(-2.4803918541230537 + (-5.9529404498953288 - 2.48039185412305368*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_5_neg1_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.03125 + QzQbar_z*(0.9375 + QzQbar_z*(0.46875 + QzQbar_z*(-4.375 + QzQbar_z*(-3.28125 + QzQbar_z*(3.9375 + 3.28125*QzQbar_z)))));
    return;
  }
  
  void D_5_0_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.17116329922036441 + pow(QzQbar_z,2)*(-2.56744948830546616 + pow(QzQbar_z,2)*(5.9907154727127544 - 3.59442928362765262*pow(QzQbar_z,2)));
    return;
  }
  
  void D_5_1_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.03125 + QzQbar_z*(-0.9375 + QzQbar_z*(0.46875 + QzQbar_z*(4.375 + QzQbar_z*(-3.28125 + QzQbar_z*(-3.9375 + 3.28125*QzQbar_z)))));
    return;
  }
  
  void D_5_2_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.165359456941536912 + QzQbar_z*(0.e-17 + QzQbar_z*(2.4803918541230537 + QzQbar_z*(-3.3071891388307382 + QzQbar_z*(-2.4803918541230537 + (5.9529404498953288 - 2.48039185412305368*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_5_3_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.101261573412622816 + QzQbar_z*(1.01261573412622816 + QzQbar_z*(-1.5189236011893422 + QzQbar_z*(-2.0252314682524563 + QzQbar_z*(6.582002271820483 + QzQbar_z*(-5.4681249642816321 + 1.51892360118934224*QzQbar_z)))));
    return;
  }
  
  void D_5_4_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.14320549046737 + QzQbar_z*(0.e-17 + QzQbar_z*(-2.14808235701055 + QzQbar_z*(5.7282196186948 + QzQbar_z*(-6.44424707103165 + (3.43693177121688 - 0.71602745233685*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_5_5_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.22642776165920998 + QzQbar_z*(-1.35856656995525987 + QzQbar_z*(3.3964164248881497 + QzQbar_z*(-4.5285552331841996 + QzQbar_z*(3.3964164248881497 + (-1.35856656995525987 + 0.226427761659209978*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_5_neg5_0(const double QzQbar_z, double& Mag) {
    Mag = -0.49607837082461074 + QzQbar_z*(-2.4803918541230537 + QzQbar_z*(-4.9607837082461074 + QzQbar_z*(-4.9607837082461074 + (-2.48039185412305368 - 0.496078370824610736*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_5_neg4_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(1.56873754975139165 + QzQbar_z*(6.2749501990055666 + QzQbar_z*(9.4124252985083499 + QzQbar_z*(6.2749501990055666 + 1.56873754975139165*QzQbar_z))));
    return;
  }
  
  void D_5_neg3_0(const double QzQbar_z, double& Mag) {
    Mag = 0.369754986443726 + QzQbar_z*(1.10926495933117801 + QzQbar_z*(-2.218529918662356 + QzQbar_z*(-9.6136296475368761 + (-9.9833846339806021 - 3.32779487799353402*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_5_neg2_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-1.81142209327367982 + QzQbar_z*(-3.6228441865473596 + QzQbar_z*(3.6228441865473596 + QzQbar_z*(10.8685325596420789 + 5.4342662798210395*QzQbar_z))));
    return;
  }
  
  void D_5_neg1_0(const double QzQbar_z, double& Mag) {
    Mag = -0.342326598440728821 + QzQbar_z*(-0.342326598440728821 + QzQbar_z*(4.79257237817020349 + QzQbar_z*(4.79257237817020349 + (-7.1888585672553052 - 7.1888585672553052*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_5_0_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(1.875 + pow(QzQbar_z,2)*(-8.75 + 7.875*pow(QzQbar_z,2)));
    return;
  }
  
  void D_5_1_0(const double QzQbar_z, double& Mag) {
    Mag = 0.342326598440728821 + QzQbar_z*(-0.342326598440728821 + QzQbar_z*(-4.79257237817020349 + QzQbar_z*(4.79257237817020349 + (7.1888585672553052 - 7.1888585672553052*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_5_2_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-1.81142209327367982 + QzQbar_z*(3.6228441865473596 + QzQbar_z*(3.6228441865473596 + QzQbar_z*(-10.8685325596420789 + 5.4342662798210395*QzQbar_z))));
    return;
  }
  
  void D_5_3_0(const double QzQbar_z, double& Mag) {
    Mag = -0.369754986443726 + QzQbar_z*(1.10926495933117801 + QzQbar_z*(2.218529918662356 + QzQbar_z*(-9.6136296475368761 + (9.9833846339806021 - 3.32779487799353402*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_5_4_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(1.56873754975139165 + QzQbar_z*(-6.2749501990055666 + QzQbar_z*(9.4124252985083499 + QzQbar_z*(-6.2749501990055666 + 1.56873754975139165*QzQbar_z))));
    return;
  }
  
  void D_5_5_0(const double QzQbar_z, double& Mag) {
    Mag = 0.49607837082461074 + QzQbar_z*(-2.4803918541230537 + QzQbar_z*(4.9607837082461074 + QzQbar_z*(-4.9607837082461074 + (2.48039185412305368 - 0.496078370824610736*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_5_neg5_1(const double QzQbar_z, double& Mag) {
    Mag = 0.90571104663683991 + QzQbar_z*(3.6228441865473596 + QzQbar_z*(5.4342662798210395 + (3.62284418654735964 + 0.905711046636839911*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_5_neg4_1(const double QzQbar_z, double& Mag) {
    Mag = -0.57282196186948 + QzQbar_z*(-4.58257569495584 + QzQbar_z*(-10.31079531365064 + (-9.16515138991168 - 2.8641098093474*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_5_neg3_1(const double QzQbar_z, double& Mag) {
    Mag = -0.40504629365049126 + QzQbar_z*(1.6201851746019651 + QzQbar_z*(10.5312036349127729 + QzQbar_z*(14.5816665714176855 + 6.075694404757369*QzQbar_z)));
    return;
  }
  
  void D_5_neg2_1(const double QzQbar_z, double& Mag) {
    Mag = 0.66143782776614765 + QzQbar_z*(2.64575131106459059 + QzQbar_z*(-3.96862696659688589 + (-15.8745078663875435 - 9.9215674164922147*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_5_neg1_1(const double QzQbar_z, double& Mag) {
    Mag = 0.125 + QzQbar_z*(-3.5 + QzQbar_z*(-5.25 + QzQbar_z*(10.5 + 13.125*QzQbar_z)));
    return;
  }
  
  void D_5_0_1(const double QzQbar_z, double& Mag) {
    Mag = -0.68465319688145764 + pow(QzQbar_z,2)*(9.585144756340407 - 14.3777171345106105*pow(QzQbar_z,2));
    return;
  }
  
  void D_5_1_1(const double QzQbar_z, double& Mag) {
    Mag = 0.125 + QzQbar_z*(3.5 + QzQbar_z*(-5.25 + QzQbar_z*(-10.5 + 13.125*QzQbar_z)));
    return;
  }
  
  void D_5_2_1(const double QzQbar_z, double& Mag) {
    Mag = 0.66143782776614765 + QzQbar_z*(-2.64575131106459059 + QzQbar_z*(-3.96862696659688589 + (15.8745078663875435 - 9.9215674164922147*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_5_3_1(const double QzQbar_z, double& Mag) {
    Mag = -0.40504629365049126 + QzQbar_z*(-1.6201851746019651 + QzQbar_z*(10.5312036349127729 + QzQbar_z*(-14.5816665714176855 + 6.075694404757369*QzQbar_z)));
    return;
  }
  
  void D_5_4_1(const double QzQbar_z, double& Mag) {
    Mag = -0.57282196186948 + QzQbar_z*(4.58257569495584 + QzQbar_z*(-10.31079531365064 + (9.16515138991168 - 2.8641098093474*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_5_5_1(const double QzQbar_z, double& Mag) {
    Mag = 0.90571104663683991 + QzQbar_z*(-3.6228441865473596 + QzQbar_z*(5.4342662798210395 + (-3.62284418654735964 + 0.905711046636839911*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_5_neg5_2(const double QzQbar_z, double& Mag) {
    Mag = -1.36930639376291528 + QzQbar_z*(-4.1079191812887459 + (-4.10791918128874585 - 1.36930639376291528*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_5_neg4_2(const double QzQbar_z, double& Mag) {
    Mag = 1.73205080756887729 + QzQbar_z*(7.7942286340599478 + QzQbar_z*(10.3923048454132638 + 4.33012701892219323*QzQbar_z));
    return;
  }
  
  void D_5_neg3_2(const double QzQbar_z, double& Mag) {
    Mag = -0.61237243569579452 + QzQbar_z*(-7.9608416640453288 + (-16.5340557637864522 - 9.1855865354369179*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_5_neg2_2(const double QzQbar_z, double& Mag) {
    Mag = -1. + QzQbar_z*(3. + QzQbar_z*(18. + 15.*QzQbar_z));
    return;
  }
  
  void D_5_neg1_2(const double QzQbar_z, double& Mag) {
    Mag = 1.3228756555322953 + QzQbar_z*(3.96862696659688589 + (-11.9058808997906577 - 19.8431348329844294*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_5_0_2(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-7.2456883730947193 + 21.7370651192841579*pow(QzQbar_z,2));
    return;
  }
  
  void D_5_1_2(const double QzQbar_z, double& Mag) {
    Mag = -1.3228756555322953 + QzQbar_z*(3.96862696659688589 + (11.9058808997906577 - 19.8431348329844294*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_5_2_2(const double QzQbar_z, double& Mag) {
    Mag = 1. + QzQbar_z*(3. + QzQbar_z*(-18. + 15.*QzQbar_z));
    return;
  }
  
  void D_5_3_2(const double QzQbar_z, double& Mag) {
    Mag = 0.61237243569579452 + QzQbar_z*(-7.9608416640453288 + (16.5340557637864522 - 9.1855865354369179*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_5_4_2(const double QzQbar_z, double& Mag) {
    Mag = -1.73205080756887729 + QzQbar_z*(7.7942286340599478 + QzQbar_z*(-10.3923048454132638 + 4.33012701892219323*QzQbar_z));
    return;
  }
  
  void D_5_5_2(const double QzQbar_z, double& Mag) {
    Mag = 1.36930639376291528 + QzQbar_z*(-4.1079191812887459 + (4.10791918128874585 - 1.36930639376291528*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_5_neg5_3(const double QzQbar_z, double& Mag) {
    Mag = 1.67705098312484227 + QzQbar_z*(3.35410196624968454 + 1.67705098312484227*QzQbar_z);
    return;
  }
  
  void D_5_neg4_3(const double QzQbar_z, double& Mag) {
    Mag = -3.18198051533946386 + (-8.4852813742385703 - 5.3033008588991064*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_5_neg3_3(const double QzQbar_z, double& Mag) {
    Mag = 3.25 + QzQbar_z*(13.5 + 11.25*QzQbar_z);
    return;
  }
  
  void D_5_neg2_3(const double QzQbar_z, double& Mag) {
    Mag = -1.22474487139158905 + (-14.6969384566990686 - 18.3711730708738357*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_5_neg1_3(const double QzQbar_z, double& Mag) {
    Mag = -1.62018517460196506 + QzQbar_z*(9.7211110476117903 + 24.3027776190294759*QzQbar_z);
    return;
  }
  
  void D_5_0_3(const double QzQbar_z, double& Mag) {
    Mag = 2.95803989154980802 - 26.6223590239482722*pow(QzQbar_z,2);
    return;
  }
  
  void D_5_1_3(const double QzQbar_z, double& Mag) {
    Mag = -1.62018517460196506 + QzQbar_z*(-9.7211110476117903 + 24.3027776190294759*QzQbar_z);
    return;
  }
  
  void D_5_2_3(const double QzQbar_z, double& Mag) {
    Mag = -1.22474487139158905 + (14.6969384566990686 - 18.3711730708738357*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_5_3_3(const double QzQbar_z, double& Mag) {
    Mag = 3.25 + QzQbar_z*(-13.5 + 11.25*QzQbar_z);
    return;
  }
  
  void D_5_4_3(const double QzQbar_z, double& Mag) {
    Mag = -3.18198051533946386 + (8.4852813742385703 - 5.3033008588991064*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_5_5_3(const double QzQbar_z, double& Mag) {
    Mag = 1.67705098312484227 + QzQbar_z*(-3.35410196624968454 + 1.67705098312484227*QzQbar_z);
    return;
  }
  
  void D_5_neg5_4(const double QzQbar_z, double& Mag) {
    Mag = -1.58113883008418967 - 1.58113883008418967*QzQbar_z;
    return;
  }
  
  void D_5_neg4_4(const double QzQbar_z, double& Mag) {
    Mag = 4. + 5.*QzQbar_z;
    return;
  }
  
  void D_5_neg3_4(const double QzQbar_z, double& Mag) {
    Mag = -6.3639610306789277 - 10.6066017177982129*QzQbar_z;
    return;
  }
  
  void D_5_neg2_4(const double QzQbar_z, double& Mag) {
    Mag = 6.9282032302755092 + 17.3205080756887729*QzQbar_z;
    return;
  }
  
  void D_5_neg1_4(const double QzQbar_z, double& Mag) {
    Mag = -4.58257569495584001 - 22.9128784747792*QzQbar_z;
    return;
  }
  
  void D_5_0_4(const double QzQbar_z, double& Mag) {
    Mag = 25.0998007960222664*QzQbar_z;
    return;
  }
  
  void D_5_1_4(const double QzQbar_z, double& Mag) {
    Mag = 4.58257569495584001 - 22.9128784747792*QzQbar_z;
    return;
  }
  
  void D_5_2_4(const double QzQbar_z, double& Mag) {
    Mag = -6.9282032302755092 + 17.3205080756887729*QzQbar_z;
    return;
  }
  
  void D_5_3_4(const double QzQbar_z, double& Mag) {
    Mag = 6.3639610306789277 - 10.6066017177982129*QzQbar_z;
    return;
  }
  
  void D_5_4_4(const double QzQbar_z, double& Mag) {
    Mag = -4. + 5.*QzQbar_z;
    return;
  }
  
  void D_5_5_4(const double QzQbar_z, double& Mag) {
    Mag = 1.58113883008418967 - 1.58113883008418967*QzQbar_z;
    return;
  }
  
  void D_5_neg5_5(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_5_neg4_5(const double QzQbar_z, double& Mag) {
    Mag = -3.16227766016837933;
    return;
  }
  
  void D_5_neg3_5(const double QzQbar_z, double& Mag) {
    Mag = 6.70820393249936909;
    return;
  }
  
  void D_5_neg2_5(const double QzQbar_z, double& Mag) {
    Mag = -10.9544511501033223;
    return;
  }
  
  void D_5_neg1_5(const double QzQbar_z, double& Mag) {
    Mag = 14.4913767461894386;
    return;
  }
  
  void D_5_0_5(const double QzQbar_z, double& Mag) {
    Mag = -15.8745078663875435;
    return;
  }
  
  void D_5_1_5(const double QzQbar_z, double& Mag) {
    Mag = 14.4913767461894386;
    return;
  }
  
  void D_5_2_5(const double QzQbar_z, double& Mag) {
    Mag = -10.9544511501033223;
    return;
  }
  
  void D_5_3_5(const double QzQbar_z, double& Mag) {
    Mag = 6.70820393249936909;
    return;
  }
  
  void D_5_4_5(const double QzQbar_z, double& Mag) {
    Mag = -3.16227766016837933;
    return;
  }
  
  void D_5_5_5(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_6_neg6_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.000244140625 + QzQbar_z*(0.0029296875 + QzQbar_z*(0.01611328125 + QzQbar_z*(0.0537109375 + QzQbar_z*(0.120849609375 + QzQbar_z*(0.193359375 + QzQbar_z*(0.2255859375 + QzQbar_z*(0.193359375 + QzQbar_z*(0.120849609375 + QzQbar_z*(0.0537109375 + QzQbar_z*(0.01611328125 + (0.0029296875 + 0.000244140625*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_6_neg5_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0008457279333832409 + QzQbar_z*(0.008457279333832409 + QzQbar_z*(0.037212029068862598 + QzQbar_z*(0.0930300726721565 + QzQbar_z*(0.13954510900823474 + QzQbar_z*(0.11163608720658779 + QzQbar_z*(0.e-17 + QzQbar_z*(-0.11163608720658779 + QzQbar_z*(-0.13954510900823474 + QzQbar_z*(-0.093030072672156495 + QzQbar_z*(-0.037212029068862598 + (-0.0084572793338324087 - 0.000845727933383240866*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_6_neg4_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0019834078136318263 + QzQbar_z*(0.01586726250905461 + QzQbar_z*(0.05156860315442748 + QzQbar_z*(0.07933631254527305 + QzQbar_z*(0.02975111720447739 + QzQbar_z*(-0.0952035750543277 + QzQbar_z*(-0.1666062563450734 + QzQbar_z*(-0.09520357505432766 + QzQbar_z*(0.02975111720447739 + QzQbar_z*(0.07933631254527305 + QzQbar_z*(0.051568603154427483 + (0.0158672625090546101 + 0.00198340781363182626*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_6_neg3_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0036211906675271792 + QzQbar_z*(0.021727144005163075 + QzQbar_z*(0.04345428801032615 + QzQbar_z*(0.00724238133505436 + QzQbar_z*(-0.0977721480232338 + QzQbar_z*(-0.1303628640309785 + QzQbar_z*(0.e-16 + QzQbar_z*(0.1303628640309785 + QzQbar_z*(0.09777214802323384 + QzQbar_z*(-0.00724238133505436 + QzQbar_z*(-0.04345428801032615 + (-0.021727144005163075 - 0.00362119066752717917*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_6_neg2_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0054317860012907688 + QzQbar_z*(0.021727144005163075 + QzQbar_z*(0.01086357200258154 + QzQbar_z*(-0.0651814320154892 + QzQbar_z*(-0.0923403620219431 + QzQbar_z*(0.0434542880103262 + QzQbar_z*(0.1520900080361415 + QzQbar_z*(0.0434542880103262 + QzQbar_z*(-0.0923403620219431 + QzQbar_z*(-0.06518143201548923 + QzQbar_z*(0.01086357200258154 + (0.021727144005163075 + 0.00543178600129076876*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_6_neg1_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0068707262106788519 + QzQbar_z*(0.013741452421357704 + QzQbar_z*(-0.02748290484271541 + QzQbar_z*(-0.0687072621067885 + QzQbar_z*(0.0343536310533943 + QzQbar_z*(0.137414524213577 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.137414524213577 + QzQbar_z*(-0.0343536310533943 + QzQbar_z*(0.06870726210678852 + QzQbar_z*(0.02748290484271541 + (-0.013741452421357704 - 0.00687072621067885189*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_6_0_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0074212324968606756 + pow(QzQbar_z,2)*(-0.044527394981164054 + pow(QzQbar_z,2)*(0.111318487452910134 + pow(QzQbar_z,2)*(-0.148424649937213512 + pow(QzQbar_z,2)*(0.111318487452910134 + pow(QzQbar_z,2)*(-0.0445273949811640536 + 0.0074212324968606756*pow(QzQbar_z,2))))));
    return;
  }
  
  void D_6_1_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0068707262106788519 + QzQbar_z*(-0.013741452421357704 + QzQbar_z*(-0.02748290484271541 + QzQbar_z*(0.0687072621067885 + QzQbar_z*(0.0343536310533943 + QzQbar_z*(-0.137414524213577 + QzQbar_z*(0.e-16 + QzQbar_z*(0.137414524213577 + QzQbar_z*(-0.0343536310533943 + QzQbar_z*(-0.06870726210678852 + QzQbar_z*(0.02748290484271541 + (0.013741452421357704 - 0.00687072621067885189*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_6_2_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0054317860012907688 + QzQbar_z*(-0.021727144005163075 + QzQbar_z*(0.01086357200258154 + QzQbar_z*(0.0651814320154892 + QzQbar_z*(-0.0923403620219431 + QzQbar_z*(-0.0434542880103262 + QzQbar_z*(0.1520900080361415 + QzQbar_z*(-0.0434542880103262 + QzQbar_z*(-0.0923403620219431 + QzQbar_z*(0.06518143201548923 + QzQbar_z*(0.01086357200258154 + (-0.021727144005163075 + 0.00543178600129076876*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_6_3_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0036211906675271792 + QzQbar_z*(-0.021727144005163075 + QzQbar_z*(0.04345428801032615 + QzQbar_z*(-0.00724238133505436 + QzQbar_z*(-0.0977721480232338 + QzQbar_z*(0.1303628640309785 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.1303628640309785 + QzQbar_z*(0.09777214802323384 + QzQbar_z*(0.00724238133505436 + QzQbar_z*(-0.04345428801032615 + (0.021727144005163075 - 0.00362119066752717917*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_6_4_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0019834078136318263 + QzQbar_z*(-0.01586726250905461 + QzQbar_z*(0.05156860315442748 + QzQbar_z*(-0.07933631254527305 + QzQbar_z*(0.02975111720447739 + QzQbar_z*(0.0952035750543277 + QzQbar_z*(-0.1666062563450734 + QzQbar_z*(0.09520357505432766 + QzQbar_z*(0.02975111720447739 + QzQbar_z*(-0.07933631254527305 + QzQbar_z*(0.051568603154427483 + (-0.0158672625090546101 + 0.00198340781363182626*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_6_5_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0008457279333832409 + QzQbar_z*(-0.008457279333832409 + QzQbar_z*(0.037212029068862598 + QzQbar_z*(-0.0930300726721565 + QzQbar_z*(0.13954510900823474 + QzQbar_z*(-0.11163608720658779 + QzQbar_z*(0.e-17 + QzQbar_z*(0.11163608720658779 + QzQbar_z*(-0.13954510900823474 + QzQbar_z*(0.093030072672156495 + QzQbar_z*(-0.037212029068862598 + (0.0084572793338324087 - 0.000845727933383240866*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_6_6_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.000244140625 + QzQbar_z*(-0.0029296875 + QzQbar_z*(0.01611328125 + QzQbar_z*(-0.0537109375 + QzQbar_z*(0.120849609375 + QzQbar_z*(-0.193359375 + QzQbar_z*(0.2255859375 + QzQbar_z*(-0.193359375 + QzQbar_z*(0.120849609375 + QzQbar_z*(-0.0537109375 + QzQbar_z*(0.01611328125 + (-0.0029296875 + 0.000244140625*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_6_neg6_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.0016914558667664817 + QzQbar_z*(-0.018606014534431299 + QzQbar_z*(-0.093030072672156495 + QzQbar_z*(-0.27909021801646949 + QzQbar_z*(-0.55818043603293897 + QzQbar_z*(-0.78145261044611456 + QzQbar_z*(-0.78145261044611456 + QzQbar_z*(-0.55818043603293897 + QzQbar_z*(-0.27909021801646949 + QzQbar_z*(-0.093030072672156495 + (-0.0186060145344312991 - 0.00169145586676648173*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_6_neg5_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.0048828125 + QzQbar_z*(-0.04296875 + QzQbar_z*(-0.1611328125 + QzQbar_z*(-0.322265625 + QzQbar_z*(-0.322265625 + QzQbar_z*(0.e-16 + QzQbar_z*(0.451171875 + QzQbar_z*(0.64453125 + QzQbar_z*(0.4833984375 + QzQbar_z*(0.21484375 + (0.0537109375 + 0.005859375*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_6_neg4_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.009160968280905136 + QzQbar_z*(-0.05954629382588338 + QzQbar_z*(-0.13741452421357704 + QzQbar_z*(-0.0687072621067885 + QzQbar_z*(0.2748290484271541 + QzQbar_z*(0.5771410016970236 + QzQbar_z*(0.3847606677980157 + QzQbar_z*(-0.137414524213577 + QzQbar_z*(-0.41224357264073111 + QzQbar_z*(-0.29773146912941692 + (-0.100770651089956494 - 0.0137414524213577038*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_6_neg3_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.012544172440102665 + QzQbar_z*(-0.05017668976041066 + QzQbar_z*(-0.01254417244010267 + QzQbar_z*(0.225795103921848 + QzQbar_z*(0.37632517320308 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.5268552424843119 + QzQbar_z*(-0.4515902078436959 + QzQbar_z*(0.037632517320308 + QzQbar_z*(0.2508834488020533 + (0.137985896841129316 + 0.0250883448802053301*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_6_neg2_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.012544172440102665 + QzQbar_z*(-0.01254417244010267 + QzQbar_z*(0.11289755196092399 + QzQbar_z*(0.2132509314817453 + QzQbar_z*(-0.1254417244010267 + QzQbar_z*(-0.5268552424843119 + QzQbar_z*(-0.1756184141614373 + QzQbar_z*(0.4265018629634906 + QzQbar_z*(0.338692655882772 + QzQbar_z*(-0.06272086220051333 + (-0.137985896841129316 - 0.0376325173203079952*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_6_neg1_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.007933631254527305 + QzQbar_z*(0.03173452501810922 + QzQbar_z*(0.11900446881790958 + QzQbar_z*(-0.0793363125452731 + QzQbar_z*(-0.3966815627263653 + QzQbar_z*(0.e-16 + QzQbar_z*(0.5553541878169114 + QzQbar_z*(0.1586726250905461 + QzQbar_z*(-0.3570134064537287 + QzQbar_z*(-0.1586726250905461 + (0.08726994379980036 + 0.0476017875271638302*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_6_0_neg5(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(0.051415806957375715 + pow(QzQbar_z,2)*(-0.25707903478687858 + pow(QzQbar_z,2)*(0.51415806957375715 + pow(QzQbar_z,2)*(-0.51415806957375715 + pow(QzQbar_z,2)*(0.257079034786878576 - 0.0514158069573757152*pow(QzQbar_z,2))))));
    return;
  }
  
  void D_6_1_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.007933631254527305 + QzQbar_z*(0.03173452501810922 + QzQbar_z*(-0.11900446881790958 + QzQbar_z*(-0.0793363125452731 + QzQbar_z*(0.3966815627263653 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.5553541878169114 + QzQbar_z*(0.1586726250905461 + QzQbar_z*(0.3570134064537287 + QzQbar_z*(-0.1586726250905461 + (-0.08726994379980036 + 0.0476017875271638302*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_6_2_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.012544172440102665 + QzQbar_z*(-0.01254417244010267 + QzQbar_z*(-0.11289755196092399 + QzQbar_z*(0.2132509314817453 + QzQbar_z*(0.1254417244010267 + QzQbar_z*(-0.5268552424843119 + QzQbar_z*(0.1756184141614373 + QzQbar_z*(0.4265018629634906 + QzQbar_z*(-0.338692655882772 + QzQbar_z*(-0.06272086220051333 + (0.137985896841129316 - 0.0376325173203079952*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_6_3_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.012544172440102665 + QzQbar_z*(-0.05017668976041066 + QzQbar_z*(0.01254417244010267 + QzQbar_z*(0.225795103921848 + QzQbar_z*(-0.37632517320308 + QzQbar_z*(0.e-16 + QzQbar_z*(0.5268552424843119 + QzQbar_z*(-0.4515902078436959 + QzQbar_z*(-0.037632517320308 + QzQbar_z*(0.2508834488020533 + (-0.137985896841129316 + 0.0250883448802053301*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_6_4_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.009160968280905136 + QzQbar_z*(-0.05954629382588338 + QzQbar_z*(0.13741452421357704 + QzQbar_z*(-0.0687072621067885 + QzQbar_z*(-0.2748290484271541 + QzQbar_z*(0.5771410016970236 + QzQbar_z*(-0.3847606677980157 + QzQbar_z*(-0.137414524213577 + QzQbar_z*(0.41224357264073111 + QzQbar_z*(-0.29773146912941692 + (0.100770651089956494 - 0.0137414524213577038*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_6_5_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0048828125 + QzQbar_z*(-0.04296875 + QzQbar_z*(0.1611328125 + QzQbar_z*(-0.322265625 + QzQbar_z*(0.322265625 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.451171875 + QzQbar_z*(0.64453125 + QzQbar_z*(-0.4833984375 + QzQbar_z*(0.21484375 + (-0.0537109375 + 0.005859375*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_6_6_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0016914558667664817 + QzQbar_z*(-0.018606014534431299 + QzQbar_z*(0.093030072672156495 + QzQbar_z*(-0.27909021801646949 + QzQbar_z*(0.55818043603293897 + QzQbar_z*(-0.78145261044611456 + QzQbar_z*(0.78145261044611456 + QzQbar_z*(-0.55818043603293897 + QzQbar_z*(0.27909021801646949 + QzQbar_z*(-0.093030072672156495 + (0.0186060145344312991 - 0.00169145586676648173*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_6_neg6_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.007933631254527305 + QzQbar_z*(0.07933631254527305 + QzQbar_z*(0.35701340645372873 + QzQbar_z*(0.9520357505432766 + QzQbar_z*(1.6660625634507341 + QzQbar_z*(1.9992750761408809 + QzQbar_z*(1.66606256345073406 + QzQbar_z*(0.9520357505432766 + QzQbar_z*(0.35701340645372873 + (0.07933631254527305 + 0.00793363125452730504*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_6_neg5_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.018321936561810272 + QzQbar_z*(0.13741452421357704 + QzQbar_z*(0.41224357264073111 + QzQbar_z*(0.5496580968543082 + QzQbar_z*(0.e-16 + QzQbar_z*(-1.1542820033940471 + QzQbar_z*(-1.9238033389900785 + QzQbar_z*(-1.6489742905629245 + QzQbar_z*(-0.82448714528146223 + (-0.229024207022628396 - 0.0274829048427154075*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_6_neg4_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.025390625 + QzQbar_z*(0.1171875 + QzQbar_z*(0.087890625 + QzQbar_z*(-0.46875 + QzQbar_z*(-1.23046875 + QzQbar_z*(-0.984375 + QzQbar_z*(0.41015625 + QzQbar_z*(1.40625 + QzQbar_z*(1.142578125 + (0.4296875 + 0.064453125*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_6_neg3_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.021395412402545551 + QzQbar_z*(0.01069770620127278 + QzQbar_z*(-0.2888380674343649 + QzQbar_z*(-0.6418623720763665 + QzQbar_z*(0.e-16 + QzQbar_z*(1.3479109813603697 + QzQbar_z*(1.3479109813603697 + QzQbar_z*(-0.1283724744152733 + QzQbar_z*(-0.9627935581145498 + (-0.58837384107000266 - 0.117674768214000532*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_6_neg2_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.0053488531006363878 + QzQbar_z*(-0.09627935581145498 + QzQbar_z*(-0.2727915081324558 + QzQbar_z*(0.2139541240254555 + QzQbar_z*(1.1232591511336414 + QzQbar_z*(0.449303660453457 + QzQbar_z*(-1.2730270379514603 + QzQbar_z*(-1.1553522697374598 + QzQbar_z*(0.2406983895286375 + (0.58837384107000266 + 0.176512152321000798*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_6_neg1_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.013531646934131854 + QzQbar_z*(-0.1014873520059889 + QzQbar_z*(0.1014873520059889 + QzQbar_z*(0.6765823467065927 + QzQbar_z*(0.e-16 + QzQbar_z*(-1.420822928083845 + QzQbar_z*(-0.4736076426946149 + QzQbar_z*(1.2178482240718668 + QzQbar_z*(0.6089241120359334 + (-0.37212029068862598 - 0.223272174413175589*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_6_0_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.021923773750628563 + pow(QzQbar_z,2)*(0.32885660625942844 + pow(QzQbar_z,2)*(-1.09618868753142814 + pow(QzQbar_z,2)*(1.5346641625439994 + pow(QzQbar_z,2)*(-0.98656981877828533 + 0.241161511256914191*pow(QzQbar_z,2)))));
    return;
  }
  
  void D_6_1_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.013531646934131854 + QzQbar_z*(0.1014873520059889 + QzQbar_z*(0.1014873520059889 + QzQbar_z*(-0.6765823467065927 + QzQbar_z*(0.e-16 + QzQbar_z*(1.420822928083845 + QzQbar_z*(-0.4736076426946149 + QzQbar_z*(-1.2178482240718668 + QzQbar_z*(0.6089241120359334 + (0.37212029068862598 - 0.223272174413175589*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_6_2_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.0053488531006363878 + QzQbar_z*(0.09627935581145498 + QzQbar_z*(-0.2727915081324558 + QzQbar_z*(-0.2139541240254555 + QzQbar_z*(1.1232591511336414 + QzQbar_z*(-0.449303660453457 + QzQbar_z*(-1.2730270379514603 + QzQbar_z*(1.1553522697374598 + QzQbar_z*(0.2406983895286375 + (-0.58837384107000266 + 0.176512152321000798*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_6_3_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.021395412402545551 + QzQbar_z*(-0.01069770620127278 + QzQbar_z*(-0.2888380674343649 + QzQbar_z*(0.6418623720763665 + QzQbar_z*(0.e-16 + QzQbar_z*(-1.3479109813603697 + QzQbar_z*(1.3479109813603697 + QzQbar_z*(0.1283724744152733 + QzQbar_z*(-0.9627935581145498 + (0.58837384107000266 - 0.117674768214000532*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_6_4_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.025390625 + QzQbar_z*(-0.1171875 + QzQbar_z*(0.087890625 + QzQbar_z*(0.46875 + QzQbar_z*(-1.23046875 + QzQbar_z*(0.984375 + QzQbar_z*(0.41015625 + QzQbar_z*(-1.40625 + QzQbar_z*(1.142578125 + (-0.4296875 + 0.064453125*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_6_5_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.018321936561810272 + QzQbar_z*(-0.13741452421357704 + QzQbar_z*(0.41224357264073111 + QzQbar_z*(-0.5496580968543082 + QzQbar_z*(0.e-16 + QzQbar_z*(1.1542820033940471 + QzQbar_z*(-1.9238033389900785 + QzQbar_z*(1.6489742905629245 + QzQbar_z*(-0.82448714528146223 + (0.229024207022628396 - 0.0274829048427154075*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_6_6_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.007933631254527305 + QzQbar_z*(-0.07933631254527305 + QzQbar_z*(0.35701340645372873 + QzQbar_z*(-0.9520357505432766 + QzQbar_z*(1.6660625634507341 + QzQbar_z*(-1.9992750761408809 + QzQbar_z*(1.66606256345073406 + QzQbar_z*(-0.9520357505432766 + QzQbar_z*(0.35701340645372873 + (-0.07933631254527305 + 0.00793363125452730504*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_6_neg6_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.028969525340217433 + QzQbar_z*(-0.2607257280619569 + QzQbar_z*(-1.0429029122478276 + QzQbar_z*(-2.4334401285782644 + QzQbar_z*(-3.6501601928673966 + QzQbar_z*(-3.6501601928673966 + QzQbar_z*(-2.43344012857826441 + QzQbar_z*(-1.0429029122478276 + (-0.260725728061956901 - 0.0289695253402174334*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_6_neg5_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.05017668976041066 + QzQbar_z*(-0.30106013856246396 + QzQbar_z*(-0.6021202771249279 + QzQbar_z*(0.e-16 + QzQbar_z*(2.1074209699372477 + QzQbar_z*(4.2148419398744955 + QzQbar_z*(4.2148419398744955 + QzQbar_z*(2.4084811084997117 + (0.7526503464061599 + 0.10035337952082132*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_6_neg4_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.042790824805091103 + QzQbar_z*(-0.06418623720763665 + QzQbar_z*(0.5134898976610932 + QzQbar_z*(1.7972146418138263 + QzQbar_z*(1.7972146418138263 + QzQbar_z*(-0.8986073209069132 + QzQbar_z*(-3.5944292836276526 + QzQbar_z*(-3.337684334797106 + (-1.41209721856800639 - 0.235349536428001064*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_6_neg3_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.00390625 + QzQbar_z*(0.2109375 + QzQbar_z*(0.703125 + QzQbar_z*(0.e-16 + QzQbar_z*(-2.4609375 + QzQbar_z*(-2.953125 + QzQbar_z*(0.328125 + QzQbar_z*(2.8125 + (1.93359375 + 0.4296875*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_6_neg2_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.03515625 + QzQbar_z*(0.19921875 + QzQbar_z*(-0.234375 + QzQbar_z*(-1.640625 + QzQbar_z*(-0.8203125 + QzQbar_z*(2.7890625 + QzQbar_z*(2.953125 + QzQbar_z*(-0.703125 + (-1.93359375 - 0.64453125*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_6_neg1_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.037057941330098195 + QzQbar_z*(-0.07411588266019639 + QzQbar_z*(-0.7411588266019639 + QzQbar_z*(0.e-16 + QzQbar_z*(2.5940558931068737 + QzQbar_z*(1.037622357242749 + QzQbar_z*(-3.1128670717282484 + QzQbar_z*(-1.7787811838447134 + (1.2229120638932404 + 0.8152747092621603*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_6_0_neg3(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-0.24016290857717809 + pow(QzQbar_z,2)*(1.60108605718118725 + pow(QzQbar_z,2)*(-3.3622807200804932 + pow(QzQbar_z,2)*(2.88195490292613705 - 0.88059733144965299*pow(QzQbar_z,2)))));
    return;
  }
  
  void D_6_1_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.037057941330098195 + QzQbar_z*(-0.07411588266019639 + QzQbar_z*(0.7411588266019639 + QzQbar_z*(0.e-16 + QzQbar_z*(-2.5940558931068737 + QzQbar_z*(1.037622357242749 + QzQbar_z*(3.1128670717282484 + QzQbar_z*(-1.7787811838447134 + (-1.2229120638932404 + 0.8152747092621603*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_6_2_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.03515625 + QzQbar_z*(0.19921875 + QzQbar_z*(0.234375 + QzQbar_z*(-1.640625 + QzQbar_z*(0.8203125 + QzQbar_z*(2.7890625 + QzQbar_z*(-2.953125 + QzQbar_z*(-0.703125 + (1.93359375 - 0.64453125*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_6_3_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.00390625 + QzQbar_z*(0.2109375 + QzQbar_z*(-0.703125 + QzQbar_z*(0.e-16 + QzQbar_z*(2.4609375 + QzQbar_z*(-2.953125 + QzQbar_z*(-0.328125 + QzQbar_z*(2.8125 + (-1.93359375 + 0.4296875*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_6_4_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.042790824805091103 + QzQbar_z*(-0.06418623720763665 + QzQbar_z*(-0.5134898976610932 + QzQbar_z*(1.7972146418138263 + QzQbar_z*(-1.7972146418138263 + QzQbar_z*(-0.8986073209069132 + QzQbar_z*(3.5944292836276526 + QzQbar_z*(-3.337684334797106 + (1.41209721856800639 - 0.235349536428001064*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_6_5_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.05017668976041066 + QzQbar_z*(-0.30106013856246396 + QzQbar_z*(0.6021202771249279 + QzQbar_z*(0.e-16 + QzQbar_z*(-2.1074209699372477 + QzQbar_z*(4.2148419398744955 + QzQbar_z*(-4.2148419398744955 + QzQbar_z*(2.4084811084997117 + (-0.7526503464061599 + 0.10035337952082132*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_6_6_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.028969525340217433 + QzQbar_z*(-0.2607257280619569 + QzQbar_z*(1.0429029122478276 + QzQbar_z*(-2.4334401285782644 + QzQbar_z*(3.6501601928673966 + QzQbar_z*(-3.6501601928673966 + QzQbar_z*(2.43344012857826441 + QzQbar_z*(-1.0429029122478276 + (0.260725728061956901 - 0.0289695253402174334*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_6_neg6_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.0869085760206523 + QzQbar_z*(0.6952686081652184 + QzQbar_z*(2.4334401285782644 + QzQbar_z*(4.8668802571565288 + QzQbar_z*(6.083600321445661 + QzQbar_z*(4.8668802571565288 + QzQbar_z*(2.43344012857826441 + (0.6952686081652184 + 0.0869085760206523002*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_6_neg5_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.10035337952082132 + QzQbar_z*(0.40141351808328528 + QzQbar_z*(0.e-16 + QzQbar_z*(-2.809894626582997 + QzQbar_z*(-7.0247365664574924 + QzQbar_z*(-8.4296838797489909 + QzQbar_z*(-5.6197892531659939 + (-2.00706759041642641 - 0.301060138562463961*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_6_neg4_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.021395412402545551 + QzQbar_z*(-0.34232659844072882 + QzQbar_z*(-1.7972146418138263 + QzQbar_z*(-2.3962861890851017 + QzQbar_z*(1.497678868178189 + QzQbar_z*(7.1888585672553052 + QzQbar_z*(7.7879301145265807 + (3.765592582848017 + 0.70604860928400319*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_6_neg3_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.0703125 + QzQbar_z*(-0.46875 + QzQbar_z*(0.e-16 + QzQbar_z*(3.28125 + QzQbar_z*(4.921875 + QzQbar_z*(-0.65625 + QzQbar_z*(-6.5625 + (-5.15625 - 1.2890625*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_6_neg2_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.06640625 + QzQbar_z*(0.15625 + QzQbar_z*(1.640625 + QzQbar_z*(1.09375 + QzQbar_z*(-4.6484375 + QzQbar_z*(-5.90625 + QzQbar_z*(1.640625 + QzQbar_z*(5.15625 + 1.93359375*QzQbar_z)))))));
    return;
  }
  
  void D_6_neg1_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.024705294220065464 + QzQbar_z*(0.49410588440130927 + QzQbar_z*(0.e-16 + QzQbar_z*(-3.4587411908091649 + QzQbar_z*(-1.7293705954045824 + QzQbar_z*(6.2257341434564968 + QzQbar_z*(4.1504894289709979 + (-3.2610988370486412 - 2.44582412778648089*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_6_0_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.080054302859059362 + pow(QzQbar_z,2)*(-1.60108605718118725 + pow(QzQbar_z,2)*(5.6038012001341554 + pow(QzQbar_z,2)*(-6.7245614401609864 + 2.64179199434895896*pow(QzQbar_z,2))));
    return;
  }
  
  void D_6_1_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.024705294220065464 + QzQbar_z*(-0.49410588440130927 + QzQbar_z*(0.e-16 + QzQbar_z*(3.4587411908091649 + QzQbar_z*(-1.7293705954045824 + QzQbar_z*(-6.2257341434564968 + QzQbar_z*(4.1504894289709979 + (3.2610988370486412 - 2.44582412778648089*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_6_2_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.06640625 + QzQbar_z*(-0.15625 + QzQbar_z*(1.640625 + QzQbar_z*(-1.09375 + QzQbar_z*(-4.6484375 + QzQbar_z*(5.90625 + QzQbar_z*(1.640625 + QzQbar_z*(-5.15625 + 1.93359375*QzQbar_z)))))));
    return;
  }
  
  void D_6_3_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.0703125 + QzQbar_z*(0.46875 + QzQbar_z*(0.e-16 + QzQbar_z*(-3.28125 + QzQbar_z*(4.921875 + QzQbar_z*(0.65625 + QzQbar_z*(-6.5625 + (5.15625 - 1.2890625*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_6_4_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.021395412402545551 + QzQbar_z*(0.34232659844072882 + QzQbar_z*(-1.7972146418138263 + QzQbar_z*(2.3962861890851017 + QzQbar_z*(1.497678868178189 + QzQbar_z*(-7.1888585672553052 + QzQbar_z*(7.7879301145265807 + (-3.765592582848017 + 0.70604860928400319*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_6_5_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.10035337952082132 + QzQbar_z*(-0.40141351808328528 + QzQbar_z*(0.e-16 + QzQbar_z*(2.809894626582997 + QzQbar_z*(-7.0247365664574924 + QzQbar_z*(8.4296838797489909 + QzQbar_z*(-5.6197892531659939 + (2.00706759041642641 - 0.301060138562463961*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_6_6_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.0869085760206523 + QzQbar_z*(-0.6952686081652184 + QzQbar_z*(2.4334401285782644 + QzQbar_z*(-4.8668802571565288 + QzQbar_z*(6.083600321445661 + QzQbar_z*(-4.8668802571565288 + QzQbar_z*(2.43344012857826441 + (-0.6952686081652184 + 0.0869085760206523002*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_6_neg6_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.21986323874172326 + QzQbar_z*(-1.5390426711920628 + QzQbar_z*(-4.6171280135761885 + QzQbar_z*(-7.6952133559603141 + QzQbar_z*(-7.6952133559603141 + QzQbar_z*(-4.6171280135761885 + (-1.53904267119206282 - 0.21986323874172326*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_6_neg5_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.12693810007243688 + QzQbar_z*(0.e-16 + QzQbar_z*(2.6657001015211745 + QzQbar_z*(8.8856670050705816 + QzQbar_z*(13.3285005076058725 + QzQbar_z*(10.662800406084698 + (4.4428335025352908 + 0.76162860043462128*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_6_neg4_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.108253175473054831 + QzQbar_z*(1.13665834246707572 + QzQbar_z*(2.2733166849341514 + QzQbar_z*(-1.8944305707784595 + QzQbar_z*(-11.366583424670757 + QzQbar_z*(-14.7765584520719844 + (-8.335494511425222 - 1.78617739530540471*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_6_neg3_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.148231765320392781 + QzQbar_z*(0.e-17 + QzQbar_z*(-3.1128670717282484 + QzQbar_z*(-6.2257341434564968 + QzQbar_z*(1.037622357242749 + QzQbar_z*(12.4514682869129936 + QzQbar_z*(11.4138459296702442 + 3.26109883704864119*QzQbar_z))))));
    return;
  }
  
  void D_6_neg2_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.049410588440130927 + QzQbar_z*(-1.03762235724274947 + QzQbar_z*(-1.0376223572427495 + QzQbar_z*(5.8798600243755803 + QzQbar_z*(9.3386012151847452 + QzQbar_z*(-3.1128670717282484 + (-11.4138459296702442 - 4.89164825557296178*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_6_neg1_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.15625 + QzQbar_z*(0.e-17 + QzQbar_z*(3.28125 + QzQbar_z*(2.1875 + QzQbar_z*(-9.84375 + QzQbar_z*(-7.875 + QzQbar_z*(7.21875 + 6.1875*QzQbar_z))))));
    return;
  }
  
  void D_6_0_neg1(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(1.01261573412622816 + pow(QzQbar_z,2)*(-7.0883101388835971 + pow(QzQbar_z,2)*(12.7589582499904748 - 6.6832638452331059*pow(QzQbar_z,2))));
    return;
  }
  
  void D_6_1_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.15625 + QzQbar_z*(0.e-17 + QzQbar_z*(-3.28125 + QzQbar_z*(2.1875 + QzQbar_z*(9.84375 + QzQbar_z*(-7.875 + QzQbar_z*(-7.21875 + 6.1875*QzQbar_z))))));
    return;
  }
  
  void D_6_2_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.049410588440130927 + QzQbar_z*(-1.03762235724274947 + QzQbar_z*(1.0376223572427495 + QzQbar_z*(5.8798600243755803 + QzQbar_z*(-9.3386012151847452 + QzQbar_z*(-3.1128670717282484 + (11.4138459296702442 - 4.89164825557296178*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_6_3_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.148231765320392781 + QzQbar_z*(0.e-17 + QzQbar_z*(3.1128670717282484 + QzQbar_z*(-6.2257341434564968 + QzQbar_z*(-1.037622357242749 + QzQbar_z*(12.4514682869129936 + QzQbar_z*(-11.4138459296702442 + 3.26109883704864119*QzQbar_z))))));
    return;
  }
  
  void D_6_4_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.108253175473054831 + QzQbar_z*(1.13665834246707572 + QzQbar_z*(-2.2733166849341514 + QzQbar_z*(-1.8944305707784595 + QzQbar_z*(11.366583424670757 + QzQbar_z*(-14.7765584520719844 + (8.335494511425222 - 1.78617739530540471*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_6_5_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.12693810007243688 + QzQbar_z*(0.e-16 + QzQbar_z*(-2.6657001015211745 + QzQbar_z*(8.8856670050705816 + QzQbar_z*(-13.3285005076058725 + QzQbar_z*(10.662800406084698 + (-4.4428335025352908 + 0.76162860043462128*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_6_6_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.21986323874172326 + QzQbar_z*(-1.5390426711920628 + QzQbar_z*(4.6171280135761885 + QzQbar_z*(-7.6952133559603141 + QzQbar_z*(7.6952133559603141 + QzQbar_z*(-4.6171280135761885 + (1.53904267119206282 - 0.21986323874172326*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_6_neg6_0(const double QzQbar_z, double& Mag) {
    Mag = 0.47495887979908324 + QzQbar_z*(2.8497532787944994 + QzQbar_z*(7.1243831969862486 + QzQbar_z*(9.4991775959816648 + QzQbar_z*(7.1243831969862486 + (2.84975327879449943 + 0.474958879799083238*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_6_neg5_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-1.64530582263602289 + QzQbar_z*(-8.2265291131801144 + QzQbar_z*(-16.4530582263602289 + QzQbar_z*(-16.4530582263602289 + (-8.2265291131801144 - 1.64530582263602289*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_6_neg4_0(const double QzQbar_z, double& Mag) {
    Mag = -0.350780380010057 + QzQbar_z*(-1.40312152004022802 + QzQbar_z*(1.753901900050285 + QzQbar_z*(14.0312152004022802 + QzQbar_z*(22.8007247006537053 + QzQbar_z*(15.4343367204425082 + 3.85858418011062705*QzQbar_z)))));
    return;
  }
  
  void D_6_neg3_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(1.9213032686174247 + QzQbar_z*(5.7639098058522741 + QzQbar_z*(-1.2808688457449498 + QzQbar_z*(-19.213032686174247 + (-21.1343359547916717 - 7.0447786515972239*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_6_neg2_0(const double QzQbar_z, double& Mag) {
    Mag = 0.32021721143623745 + QzQbar_z*(0.6404344228724749 + QzQbar_z*(-5.4436925944160366 + QzQbar_z*(-11.5278196117045482 + QzQbar_z*(4.8032581715435617 + QzQbar_z*(21.1343359547916717 + 10.5671679773958358*QzQbar_z)))));
    return;
  }
  
  void D_6_neg1_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-2.02523146825245632 + QzQbar_z*(-2.02523146825245632 + QzQbar_z*(12.1513888095147379 + QzQbar_z*(12.1513888095147379 + (-13.3665276904662117 - 13.3665276904662117*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_6_0_0(const double QzQbar_z, double& Mag) {
    Mag = -0.3125 + pow(QzQbar_z,2)*(6.5625 + pow(QzQbar_z,2)*(-19.6875 + 14.4375*pow(QzQbar_z,2)));
    return;
  }
  
  void D_6_1_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(2.02523146825245632 + QzQbar_z*(-2.02523146825245632 + QzQbar_z*(-12.1513888095147379 + QzQbar_z*(12.1513888095147379 + (13.3665276904662117 - 13.3665276904662117*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_6_2_0(const double QzQbar_z, double& Mag) {
    Mag = 0.32021721143623745 + QzQbar_z*(-0.6404344228724749 + QzQbar_z*(-5.4436925944160366 + QzQbar_z*(11.5278196117045482 + QzQbar_z*(4.8032581715435617 + QzQbar_z*(-21.1343359547916717 + 10.5671679773958358*QzQbar_z)))));
    return;
  }
  
  void D_6_3_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-1.9213032686174247 + QzQbar_z*(5.7639098058522741 + QzQbar_z*(1.2808688457449498 + QzQbar_z*(-19.213032686174247 + (21.1343359547916717 - 7.0447786515972239*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_6_4_0(const double QzQbar_z, double& Mag) {
    Mag = -0.350780380010057 + QzQbar_z*(1.40312152004022802 + QzQbar_z*(1.753901900050285 + QzQbar_z*(-14.0312152004022802 + QzQbar_z*(22.8007247006537053 + QzQbar_z*(-15.4343367204425082 + 3.85858418011062705*QzQbar_z)))));
    return;
  }
  
  void D_6_5_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(1.64530582263602289 + QzQbar_z*(-8.2265291131801144 + QzQbar_z*(16.4530582263602289 + QzQbar_z*(-16.4530582263602289 + (8.2265291131801144 - 1.64530582263602289*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_6_6_0(const double QzQbar_z, double& Mag) {
    Mag = 0.47495887979908324 + QzQbar_z*(-2.8497532787944994 + QzQbar_z*(7.1243831969862486 + QzQbar_z*(-9.4991775959816648 + QzQbar_z*(7.1243831969862486 + (-2.84975327879449943 + 0.474958879799083238*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_6_neg6_1(const double QzQbar_z, double& Mag) {
    Mag = -0.87945295496689304 + QzQbar_z*(-4.3972647748344652 + QzQbar_z*(-8.7945295496689304 + QzQbar_z*(-8.7945295496689304 + (-4.39726477483446521 - 0.879452954966893041*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_6_neg5_1(const double QzQbar_z, double& Mag) {
    Mag = 0.50775240028974752 + QzQbar_z*(5.0775240028974752 + QzQbar_z*(15.2325720086924257 + QzQbar_z*(20.3100960115899009 + QzQbar_z*(12.6938100072436881 + 3.04651440173848514*QzQbar_z))));
    return;
  }
  
  void D_6_neg4_1(const double QzQbar_z, double& Mag) {
    Mag = 0.43301270189221932 + QzQbar_z*(-1.0825317547305483 + QzQbar_z*(-12.9903810567665797 + QzQbar_z*(-28.145825622994256 + (-23.8156986040720628 - 7.1447095812216188*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_6_neg3_1(const double QzQbar_z, double& Mag) {
    Mag = -0.59292706128157112 + QzQbar_z*(-3.5575623676894267 + QzQbar_z*(1.1858541225631422 + QzQbar_z*(23.717082451262845 + QzQbar_z*(32.6109883704864119 + 13.0443953481945647*QzQbar_z))));
    return;
  }
  
  void D_6_neg2_1(const double QzQbar_z, double& Mag) {
    Mag = -0.197642353760523708 + QzQbar_z*(3.35992001392890304 + QzQbar_z*(10.6726871030682802 + QzQbar_z*(-5.9292706128157112 + (-32.6109883704864119 - 19.5665930222918471*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_6_neg1_1(const double QzQbar_z, double& Mag) {
    Mag = 0.625 + QzQbar_z*(1.25 + QzQbar_z*(-11.25 + QzQbar_z*(-15. + QzQbar_z*(20.625 + 24.75*QzQbar_z))));
    return;
  }
  
  void D_6_0_1(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-4.05046293650491264 + pow(QzQbar_z,2)*(24.3027776190294759 - 26.7330553809324235*pow(QzQbar_z,2)));
    return;
  }
  
  void D_6_1_1(const double QzQbar_z, double& Mag) {
    Mag = -0.625 + QzQbar_z*(1.25 + QzQbar_z*(11.25 + QzQbar_z*(-15. + QzQbar_z*(-20.625 + 24.75*QzQbar_z))));
    return;
  }
  
  void D_6_2_1(const double QzQbar_z, double& Mag) {
    Mag = 0.197642353760523708 + QzQbar_z*(3.35992001392890304 + QzQbar_z*(-10.6726871030682802 + QzQbar_z*(-5.9292706128157112 + (32.6109883704864119 - 19.5665930222918471*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_6_3_1(const double QzQbar_z, double& Mag) {
    Mag = 0.59292706128157112 + QzQbar_z*(-3.5575623676894267 + QzQbar_z*(-1.1858541225631422 + QzQbar_z*(23.717082451262845 + QzQbar_z*(-32.6109883704864119 + 13.0443953481945647*QzQbar_z))));
    return;
  }
  
  void D_6_4_1(const double QzQbar_z, double& Mag) {
    Mag = -0.43301270189221932 + QzQbar_z*(-1.0825317547305483 + QzQbar_z*(12.9903810567665797 + QzQbar_z*(-28.145825622994256 + (23.8156986040720628 - 7.1447095812216188*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_6_5_1(const double QzQbar_z, double& Mag) {
    Mag = -0.50775240028974752 + QzQbar_z*(5.0775240028974752 + QzQbar_z*(-15.2325720086924257 + QzQbar_z*(20.3100960115899009 + QzQbar_z*(-12.6938100072436881 + 3.04651440173848514*QzQbar_z))));
    return;
  }
  
  void D_6_6_1(const double QzQbar_z, double& Mag) {
    Mag = 0.87945295496689304 + QzQbar_z*(-4.3972647748344652 + QzQbar_z*(8.7945295496689304 + QzQbar_z*(-8.7945295496689304 + (4.39726477483446521 - 0.879452954966893041*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_6_neg6_2(const double QzQbar_z, double& Mag) {
    Mag = 1.3905372163304368 + QzQbar_z*(5.5621488653217472 + QzQbar_z*(8.3432232979826208 + QzQbar_z*(5.5621488653217472 + 1.3905372163304368*QzQbar_z)));
    return;
  }
  
  void D_6_neg5_2(const double QzQbar_z, double& Mag) {
    Mag = -1.60565407233314113 + QzQbar_z*(-9.6339244339988468 + QzQbar_z*(-19.2678488679976935 + (-16.0565407233314113 - 4.81696221699942338*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_6_neg4_2(const double QzQbar_z, double& Mag) {
    Mag = 0.34232659844072882 + QzQbar_z*(8.2158383625774917 + QzQbar_z*(26.701474678376848 + QzQbar_z*(30.1247406627841362 + 11.2967777485440511*QzQbar_z)));
    return;
  }
  
  void D_6_neg3_2(const double QzQbar_z, double& Mag) {
    Mag = 1.125 + QzQbar_z*(-0.75 + QzQbar_z*(-22.5 + (-41.25 - 20.625*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_6_neg2_2(const double QzQbar_z, double& Mag) {
    Mag = -1.0625 + QzQbar_z*(-6.75 + QzQbar_z*(5.625 + QzQbar_z*(41.25 + 30.9375*QzQbar_z)));
    return;
  }
  
  void D_6_neg1_2(const double QzQbar_z, double& Mag) {
    Mag = -0.395284707521047416 + QzQbar_z*(7.1151247353788535 + QzQbar_z*(14.230249470757707 + (-26.0887906963891295 - 39.1331860445836942*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_6_0_2(const double QzQbar_z, double& Mag) {
    Mag = 1.2808688457449498 + pow(QzQbar_z,2)*(-23.0556392234090964 + 42.2686719095833433*pow(QzQbar_z,2));
    return;
  }
  
  void D_6_1_2(const double QzQbar_z, double& Mag) {
    Mag = -0.395284707521047416 + QzQbar_z*(-7.1151247353788535 + QzQbar_z*(14.230249470757707 + (26.0887906963891295 - 39.1331860445836942*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_6_2_2(const double QzQbar_z, double& Mag) {
    Mag = -1.0625 + QzQbar_z*(6.75 + QzQbar_z*(5.625 + QzQbar_z*(-41.25 + 30.9375*QzQbar_z)));
    return;
  }
  
  void D_6_3_2(const double QzQbar_z, double& Mag) {
    Mag = 1.125 + QzQbar_z*(0.75 + QzQbar_z*(-22.5 + (41.25 - 20.625*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_6_4_2(const double QzQbar_z, double& Mag) {
    Mag = 0.34232659844072882 + QzQbar_z*(-8.2158383625774917 + QzQbar_z*(26.701474678376848 + QzQbar_z*(-30.1247406627841362 + 11.2967777485440511*QzQbar_z)));
    return;
  }
  
  void D_6_5_2(const double QzQbar_z, double& Mag) {
    Mag = -1.60565407233314113 + QzQbar_z*(9.6339244339988468 + QzQbar_z*(-19.2678488679976935 + (16.0565407233314113 - 4.81696221699942338*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_6_6_2(const double QzQbar_z, double& Mag) {
    Mag = 1.3905372163304368 + QzQbar_z*(-5.5621488653217472 + QzQbar_z*(8.3432232979826208 + QzQbar_z*(-5.5621488653217472 + 1.3905372163304368*QzQbar_z)));
    return;
  }
  
  void D_6_neg6_3(const double QzQbar_z, double& Mag) {
    Mag = -1.85404962177391574 + QzQbar_z*(-5.5621488653217472 + (-5.5621488653217472 - 1.85404962177391574*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_6_neg5_3(const double QzQbar_z, double& Mag) {
    Mag = 3.2113081446662823 + QzQbar_z*(12.845232578665129 + QzQbar_z*(16.0565407233314113 + 6.4226162893325645*QzQbar_z));
    return;
  }
  
  void D_6_neg4_3(const double QzQbar_z, double& Mag) {
    Mag = -2.73861278752583057 + QzQbar_z*(-17.8009831189178987 + (-30.1247406627841362 - 15.0623703313920681*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_6_neg3_3(const double QzQbar_z, double& Mag) {
    Mag = 0.25 + QzQbar_z*(15. + QzQbar_z*(41.25 + 27.5*QzQbar_z));
    return;
  }
  
  void D_6_neg2_3(const double QzQbar_z, double& Mag) {
    Mag = 2.25 + QzQbar_z*(-3.75 + (-41.25 - 41.25*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_6_neg1_3(const double QzQbar_z, double& Mag) {
    Mag = -2.3717082451262845 + QzQbar_z*(-9.486832980505138 + QzQbar_z*(26.0887906963891295 + 52.177581392778259*QzQbar_z));
    return;
  }
  
  void D_6_0_3(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(15.3704261489393976 - 56.358229212777791*pow(QzQbar_z,2));
    return;
  }
  
  void D_6_1_3(const double QzQbar_z, double& Mag) {
    Mag = 2.3717082451262845 + QzQbar_z*(-9.486832980505138 + QzQbar_z*(-26.0887906963891295 + 52.177581392778259*QzQbar_z));
    return;
  }
  
  void D_6_2_3(const double QzQbar_z, double& Mag) {
    Mag = -2.25 + QzQbar_z*(-3.75 + (41.25 - 41.25*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_6_3_3(const double QzQbar_z, double& Mag) {
    Mag = -0.25 + QzQbar_z*(15. + QzQbar_z*(-41.25 + 27.5*QzQbar_z));
    return;
  }
  
  void D_6_4_3(const double QzQbar_z, double& Mag) {
    Mag = 2.73861278752583057 + QzQbar_z*(-17.8009831189178987 + (30.1247406627841362 - 15.0623703313920681*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_6_5_3(const double QzQbar_z, double& Mag) {
    Mag = -3.2113081446662823 + QzQbar_z*(12.845232578665129 + QzQbar_z*(-16.0565407233314113 + 6.4226162893325645*QzQbar_z));
    return;
  }
  
  void D_6_6_3(const double QzQbar_z, double& Mag) {
    Mag = 1.85404962177391574 + QzQbar_z*(-5.5621488653217472 + (5.5621488653217472 - 1.85404962177391574*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_6_neg6_4(const double QzQbar_z, double& Mag) {
    Mag = 2.03100960115899009 + QzQbar_z*(4.06201920231798018 + 2.03100960115899009*QzQbar_z);
    return;
  }
  
  void D_6_neg5_4(const double QzQbar_z, double& Mag) {
    Mag = -4.69041575982342955 + (-11.7260393995585739 - 7.0356236397351443*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_6_neg4_4(const double QzQbar_z, double& Mag) {
    Mag = 6.5 + QzQbar_z*(22. + 16.5*QzQbar_z);
    return;
  }
  
  void D_6_neg3_4(const double QzQbar_z, double& Mag) {
    Mag = -5.4772255750516611 + (-30.1247406627841362 - 30.1247406627841362*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_6_neg2_4(const double QzQbar_z, double& Mag) {
    Mag = 1.36930639376291528 + QzQbar_z*(30.1247406627841362 + 45.1871109941762044*QzQbar_z);
    return;
  }
  
  void D_6_neg1_4(const double QzQbar_z, double& Mag) {
    Mag = 3.46410161513775459 + (-19.0525588832576502 - 57.157676649772951*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_6_0_4(const double QzQbar_z, double& Mag) {
    Mag = -5.6124860801609121 + 61.737346881770033*pow(QzQbar_z,2);
    return;
  }
  
  void D_6_1_4(const double QzQbar_z, double& Mag) {
    Mag = 3.46410161513775459 + (19.0525588832576502 - 57.157676649772951*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_6_2_4(const double QzQbar_z, double& Mag) {
    Mag = 1.36930639376291528 + QzQbar_z*(-30.1247406627841362 + 45.1871109941762044*QzQbar_z);
    return;
  }
  
  void D_6_3_4(const double QzQbar_z, double& Mag) {
    Mag = -5.4772255750516611 + (30.1247406627841362 - 30.1247406627841362*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_6_4_4(const double QzQbar_z, double& Mag) {
    Mag = 6.5 + QzQbar_z*(-22. + 16.5*QzQbar_z);
    return;
  }
  
  void D_6_5_4(const double QzQbar_z, double& Mag) {
    Mag = -4.69041575982342955 + (11.7260393995585739 - 7.0356236397351443*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_6_6_4(const double QzQbar_z, double& Mag) {
    Mag = 2.03100960115899009 + QzQbar_z*(-4.06201920231798018 + 2.03100960115899009*QzQbar_z);
    return;
  }
  
  void D_6_neg6_5(const double QzQbar_z, double& Mag) {
    Mag = -1.73205080756887729 - 1.73205080756887729*QzQbar_z;
    return;
  }
  
  void D_6_neg5_5(const double QzQbar_z, double& Mag) {
    Mag = 5. + 6.*QzQbar_z;
    return;
  }
  
  void D_6_neg4_5(const double QzQbar_z, double& Mag) {
    Mag = -9.3808315196468591 - 14.0712472794702887*QzQbar_z;
    return;
  }
  
  void D_6_neg3_5(const double QzQbar_z, double& Mag) {
    Mag = 12.845232578665129 + 25.690465157330258*QzQbar_z;
    return;
  }
  
  void D_6_neg2_5(const double QzQbar_z, double& Mag) {
    Mag = -12.845232578665129 - 38.5356977359953871*QzQbar_z;
    return;
  }
  
  void D_6_neg1_5(const double QzQbar_z, double& Mag) {
    Mag = 8.1240384046359604 + 48.7442304278157622*QzQbar_z;
    return;
  }
  
  void D_6_0_5(const double QzQbar_z, double& Mag) {
    Mag = -52.6497863243527324*QzQbar_z;
    return;
  }
  
  void D_6_1_5(const double QzQbar_z, double& Mag) {
    Mag = -8.1240384046359604 + 48.7442304278157622*QzQbar_z;
    return;
  }
  
  void D_6_2_5(const double QzQbar_z, double& Mag) {
    Mag = 12.845232578665129 - 38.5356977359953871*QzQbar_z;
    return;
  }
  
  void D_6_3_5(const double QzQbar_z, double& Mag) {
    Mag = -12.845232578665129 + 25.690465157330258*QzQbar_z;
    return;
  }
  
  void D_6_4_5(const double QzQbar_z, double& Mag) {
    Mag = 9.3808315196468591 - 14.0712472794702887*QzQbar_z;
    return;
  }
  
  void D_6_5_5(const double QzQbar_z, double& Mag) {
    Mag = -5. + 6.*QzQbar_z;
    return;
  }
  
  void D_6_6_5(const double QzQbar_z, double& Mag) {
    Mag = 1.73205080756887729 - 1.73205080756887729*QzQbar_z;
    return;
  }
  
  void D_6_neg6_6(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_6_neg5_6(const double QzQbar_z, double& Mag) {
    Mag = -3.46410161513775459;
    return;
  }
  
  void D_6_neg4_6(const double QzQbar_z, double& Mag) {
    Mag = 8.12403840463596036;
    return;
  }
  
  void D_6_neg3_6(const double QzQbar_z, double& Mag) {
    Mag = -14.8323969741913259;
    return;
  }
  
  void D_6_neg2_6(const double QzQbar_z, double& Mag) {
    Mag = 22.2485954612869888;
    return;
  }
  
  void D_6_neg1_6(const double QzQbar_z, double& Mag) {
    Mag = -28.1424945589405773;
    return;
  }
  
  void D_6_0_6(const double QzQbar_z, double& Mag) {
    Mag = 30.3973683071413273;
    return;
  }
  
  void D_6_1_6(const double QzQbar_z, double& Mag) {
    Mag = -28.1424945589405773;
    return;
  }
  
  void D_6_2_6(const double QzQbar_z, double& Mag) {
    Mag = 22.2485954612869888;
    return;
  }
  
  void D_6_3_6(const double QzQbar_z, double& Mag) {
    Mag = -14.8323969741913259;
    return;
  }
  
  void D_6_4_6(const double QzQbar_z, double& Mag) {
    Mag = 8.12403840463596036;
    return;
  }
  
  void D_6_5_6(const double QzQbar_z, double& Mag) {
    Mag = -3.46410161513775459;
    return;
  }
  
  void D_6_6_6(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_7_neg7_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.00006103515625 + QzQbar_z*(0.0008544921875 + QzQbar_z*(0.00555419921875 + QzQbar_z*(0.022216796875 + QzQbar_z*(0.06109619140625 + QzQbar_z*(0.1221923828125 + QzQbar_z*(0.18328857421875 + QzQbar_z*(0.20947265625 + QzQbar_z*(0.18328857421875 + QzQbar_z*(0.1221923828125 + QzQbar_z*(0.06109619140625 + QzQbar_z*(0.022216796875 + QzQbar_z*(0.00555419921875 + (0.0008544921875 + 0.00006103515625*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_neg6_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0002283726432357142 + QzQbar_z*(0.0027404717188285704 + QzQbar_z*(0.014844221810321423 + QzQbar_z*(0.047501509793028553 + QzQbar_z*(0.09797186394812139 + QzQbar_z*(0.13062915193082852 + QzQbar_z*(0.09797186394812139 + QzQbar_z*(0.e-17 + QzQbar_z*(-0.09797186394812139 + QzQbar_z*(-0.13062915193082852 + QzQbar_z*(-0.09797186394812139 + QzQbar_z*(-0.047501509793028553 + QzQbar_z*(-0.0148442218103214227 + (-0.00274047171882857035 - 0.000228372643235714196*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_neg5_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.00058223828211483499 + QzQbar_z*(0.00582238282114835 + QzQbar_z*(0.025036246130937905 + QzQbar_z*(0.0582238282114835 + QzQbar_z*(0.07045083213589503 + QzQbar_z*(0.0128092422065264 + QzQbar_z*(-0.0960693165489478 + QzQbar_z*(-0.1537109064783164 + QzQbar_z*(-0.0960693165489478 + QzQbar_z*(0.01280924220652637 + QzQbar_z*(0.07045083213589503 + QzQbar_z*(0.058223828211483499 + QzQbar_z*(0.025036246130937905 + (0.0058223828211483499 + 0.000582238282114834991*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_neg4_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.00116447656422967 + QzQbar_z*(0.00931581251383736 + QzQbar_z*(0.02911191410574175 + QzQbar_z*(0.03726325005534944 + QzQbar_z*(-0.0128092422065264 + QzQbar_z*(-0.102473937652211 + QzQbar_z*(-0.1152831798587373 + QzQbar_z*(0.e-16 + QzQbar_z*(0.1152831798587373 + QzQbar_z*(0.102473937652211 + QzQbar_z*(0.01280924220652637 + QzQbar_z*(-0.03726325005534944 + QzQbar_z*(-0.02911191410574175 + (-0.0093158125138373599 - 0.00116447656422966998*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_neg3_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0019310659203560028 + QzQbar_z*(0.011586395522136017 + QzQbar_z*(0.02124172512391603 + QzQbar_z*(-0.00772426368142401 + QzQbar_z*(-0.0753115708938841 + QzQbar_z*(-0.0733805049735281 + QzQbar_z*(0.0521387798496121 + QzQbar_z*(0.1390367462656322 + QzQbar_z*(0.0521387798496121 + QzQbar_z*(-0.0733805049735281 + QzQbar_z*(-0.07531157089388411 + QzQbar_z*(-0.00772426368142401 + QzQbar_z*(0.02124172512391603 + (0.0115863955221360165 + 0.00193106592035600276*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_neg2_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0027309396144039421 + QzQbar_z*(0.010923758457615768 + QzQbar_z*(0.00273093961440394 + QzQbar_z*(-0.0436950338304631 + QzQbar_z*(-0.0518878526736749 + QzQbar_z*(0.0546187922880788 + QzQbar_z*(0.1228922826481774 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.1228922826481774 + QzQbar_z*(-0.0546187922880788 + QzQbar_z*(0.0518878526736749 + QzQbar_z*(0.04369503383046307 + QzQbar_z*(-0.002730939614403942 + (-0.0109237584576157684 - 0.0027309396144039421*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_neg1_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0033447042868213519 + QzQbar_z*(0.006689408573642704 + QzQbar_z*(-0.01672352143410676 + QzQbar_z*(-0.0401364514418562 + QzQbar_z*(0.0301023385813922 + QzQbar_z*(0.1003411286046406 + QzQbar_z*(-0.0167235214341068 + QzQbar_z*(-0.1337881714728541 + QzQbar_z*(-0.0167235214341068 + QzQbar_z*(0.1003411286046406 + QzQbar_z*(0.0301023385813922 + QzQbar_z*(-0.04013645144185622 + QzQbar_z*(-0.016723521434106759 + (0.0066894085736427037 + 0.00334470428682135185*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_0_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0035756392861027368 + pow(QzQbar_z,2)*(-0.025029475002719157 + pow(QzQbar_z,2)*(0.075088425008157472 + pow(QzQbar_z,2)*(-0.125147375013595787 + pow(QzQbar_z,2)*(0.125147375013595787 + pow(QzQbar_z,2)*(-0.075088425008157472 + pow(QzQbar_z,2)*(0.0250294750027191574 - 0.00357563928610273677*pow(QzQbar_z,2)))))));
    return;
  }
  
  void D_7_1_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0033447042868213519 + QzQbar_z*(-0.006689408573642704 + QzQbar_z*(-0.01672352143410676 + QzQbar_z*(0.0401364514418562 + QzQbar_z*(0.0301023385813922 + QzQbar_z*(-0.1003411286046406 + QzQbar_z*(-0.0167235214341068 + QzQbar_z*(0.1337881714728541 + QzQbar_z*(-0.0167235214341068 + QzQbar_z*(-0.1003411286046406 + QzQbar_z*(0.0301023385813922 + QzQbar_z*(0.04013645144185622 + QzQbar_z*(-0.016723521434106759 + (-0.0066894085736427037 + 0.00334470428682135185*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_2_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0027309396144039421 + QzQbar_z*(-0.010923758457615768 + QzQbar_z*(0.00273093961440394 + QzQbar_z*(0.0436950338304631 + QzQbar_z*(-0.0518878526736749 + QzQbar_z*(-0.0546187922880788 + QzQbar_z*(0.1228922826481774 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.1228922826481774 + QzQbar_z*(0.0546187922880788 + QzQbar_z*(0.0518878526736749 + QzQbar_z*(-0.04369503383046307 + QzQbar_z*(-0.002730939614403942 + (0.0109237584576157684 - 0.0027309396144039421*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_3_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0019310659203560028 + QzQbar_z*(-0.011586395522136017 + QzQbar_z*(0.02124172512391603 + QzQbar_z*(0.00772426368142401 + QzQbar_z*(-0.0753115708938841 + QzQbar_z*(0.0733805049735281 + QzQbar_z*(0.0521387798496121 + QzQbar_z*(-0.1390367462656322 + QzQbar_z*(0.0521387798496121 + QzQbar_z*(0.0733805049735281 + QzQbar_z*(-0.07531157089388411 + QzQbar_z*(0.00772426368142401 + QzQbar_z*(0.02124172512391603 + (-0.0115863955221360165 + 0.00193106592035600276*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_4_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.00116447656422967 + QzQbar_z*(-0.00931581251383736 + QzQbar_z*(0.02911191410574175 + QzQbar_z*(-0.03726325005534944 + QzQbar_z*(-0.0128092422065264 + QzQbar_z*(0.102473937652211 + QzQbar_z*(-0.1152831798587373 + QzQbar_z*(0.e-16 + QzQbar_z*(0.1152831798587373 + QzQbar_z*(-0.102473937652211 + QzQbar_z*(0.01280924220652637 + QzQbar_z*(0.03726325005534944 + QzQbar_z*(-0.02911191410574175 + (0.0093158125138373599 - 0.00116447656422966998*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_5_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.00058223828211483499 + QzQbar_z*(-0.00582238282114835 + QzQbar_z*(0.025036246130937905 + QzQbar_z*(-0.0582238282114835 + QzQbar_z*(0.07045083213589503 + QzQbar_z*(-0.0128092422065264 + QzQbar_z*(-0.0960693165489478 + QzQbar_z*(0.1537109064783164 + QzQbar_z*(-0.0960693165489478 + QzQbar_z*(-0.01280924220652637 + QzQbar_z*(0.07045083213589503 + QzQbar_z*(-0.058223828211483499 + QzQbar_z*(0.025036246130937905 + (-0.0058223828211483499 + 0.000582238282114834991*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_6_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0002283726432357142 + QzQbar_z*(-0.0027404717188285704 + QzQbar_z*(0.014844221810321423 + QzQbar_z*(-0.047501509793028553 + QzQbar_z*(0.09797186394812139 + QzQbar_z*(-0.13062915193082852 + QzQbar_z*(0.09797186394812139 + QzQbar_z*(0.e-17 + QzQbar_z*(-0.09797186394812139 + QzQbar_z*(0.13062915193082852 + QzQbar_z*(-0.09797186394812139 + QzQbar_z*(0.047501509793028553 + QzQbar_z*(-0.0148442218103214227 + (0.00274047171882857035 - 0.000228372643235714196*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_7_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.00006103515625 + QzQbar_z*(-0.0008544921875 + QzQbar_z*(0.00555419921875 + QzQbar_z*(-0.022216796875 + QzQbar_z*(0.06109619140625 + QzQbar_z*(-0.1221923828125 + QzQbar_z*(0.18328857421875 + QzQbar_z*(-0.20947265625 + QzQbar_z*(0.18328857421875 + QzQbar_z*(-0.1221923828125 + QzQbar_z*(0.06109619140625 + QzQbar_z*(-0.022216796875 + QzQbar_z*(0.00555419921875 + (-0.0008544921875 + 0.00006103515625*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_7_neg7_neg6(const double QzQbar_z, double& Mag) {
    Mag = -0.00045674528647142839 + QzQbar_z*(-0.0059376887241285691 + QzQbar_z*(-0.035626132344771415 + QzQbar_z*(-0.13062915193082852 + QzQbar_z*(-0.3265728798270713 + QzQbar_z*(-0.58783118368872834 + QzQbar_z*(-0.78377491158497112 + QzQbar_z*(-0.78377491158497112 + QzQbar_z*(-0.58783118368872834 + QzQbar_z*(-0.3265728798270713 + QzQbar_z*(-0.13062915193082852 + QzQbar_z*(-0.035626132344771415 + (-0.0059376887241285691 - 0.000456745286471428392*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_neg6_neg6(const double QzQbar_z, double& Mag) {
    Mag = -0.00146484375 + QzQbar_z*(-0.015869140625 + QzQbar_z*(-0.076171875 + QzQbar_z*(-0.20947265625 + QzQbar_z*(-0.34912109375 + QzQbar_z*(-0.314208984375 + QzQbar_z*(0.e-16 + QzQbar_z*(0.4189453125 + QzQbar_z*(0.62841796875 + QzQbar_z*(0.523681640625 + QzQbar_z*(0.279296875 + QzQbar_z*(0.09521484375 + (0.01904296875 + 0.001708984375*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_neg5_neg6(const double QzQbar_z, double& Mag) {
    Mag = -0.0031121945273393462 + QzQbar_z*(-0.026764872935118377 + QzQbar_z*(-0.09336583582018039 + QzQbar_z*(-0.1506302151232244 + QzQbar_z*(-0.0342341398007328 + QzQbar_z*(0.3081072582065953 + QzQbar_z*(0.5751335486523112 + QzQbar_z*(0.4108096776087937 + QzQbar_z*(-0.0616214516413191 + QzQbar_z*(-0.3765755378080609 + QzQbar_z*(-0.34234139800732808 + QzQbar_z*(-0.16058923761071026 + (-0.040458528855411501 - 0.00435707233827508469*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_neg4_neg6(const double QzQbar_z, double& Mag) {
    Mag = -0.0049795112437429539 + QzQbar_z*(-0.031121945273393462 + QzQbar_z*(-0.05975413492491545 + QzQbar_z*(0.0273873118405862 + QzQbar_z*(0.2738731184058625 + QzQbar_z*(0.3697287098479143 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.4929716131305524 + QzQbar_z*(-0.4929716131305524 + QzQbar_z*(-0.0684682796014656 + QzQbar_z*(0.21909849472468997 + QzQbar_z*(0.18673167164036077 + (0.064733646168658401 + 0.0087141446765501694*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_neg3_neg6(const double QzQbar_z, double& Mag) {
    Mag = -0.0061931889130692491 + QzQbar_z*(-0.02270835934792058 + QzQbar_z*(0.0123863778261385 + QzQbar_z*(0.1610229117398005 + QzQbar_z*(0.1961176489138596 + QzQbar_z*(-0.16721610065287 + QzQbar_z*(-0.520227868697817 + QzQbar_z*(-0.222954800870493 + QzQbar_z*(0.3530117680449472 + QzQbar_z*(0.4025572793495012 + QzQbar_z*(0.0454167186958412 + QzQbar_z*(-0.13625015608752348 + (-0.080511455869900238 - 0.0144507741304949146*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_neg2_neg6(const double QzQbar_z, double& Mag) {
    Mag = -0.0058389945034674795 + QzQbar_z*(-0.00291949725173374 + QzQbar_z*(0.07006793404160975 + QzQbar_z*(0.1109408955658821 + QzQbar_z*(-0.145974862586687 + QzQbar_z*(-0.394132128984055 + QzQbar_z*(0.e-15 + QzQbar_z*(0.525509505312073 + QzQbar_z*(0.262754752656037 + QzQbar_z*(-0.2773522389147053 + QzQbar_z*(-0.2569157581525691 + QzQbar_z*(0.01751698351040244 + (0.075906928545077234 + 0.0204364807621361783*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_neg1_neg6(const double QzQbar_z, double& Mag) {
    Mag = -0.0035756392861027368 + QzQbar_z*(0.017878196430513684 + QzQbar_z*(0.06436150714984926 + QzQbar_z*(-0.0643615071498493 + QzQbar_z*(-0.2681729464577053 + QzQbar_z*(0.053634589291541 + QzQbar_z*(0.500589500054383 + QzQbar_z*(0.071512785722055 + QzQbar_z*(-0.482711303623869 + QzQbar_z*(-0.1609037678746232 + QzQbar_z*(0.2359921928827806 + QzQbar_z*(0.1072691785830821 + (-0.046483310719335578 - 0.0250294750027191574*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_0_neg6(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(0.026757634294570815 + pow(QzQbar_z,2)*(-0.160545805767424889 + pow(QzQbar_z,2)*(0.40136451441856222 + pow(QzQbar_z,2)*(-0.5351526858914163 + pow(QzQbar_z,2)*(0.40136451441856222 + pow(QzQbar_z,2)*(-0.160545805767424889 + 0.0267576342945708148*pow(QzQbar_z,2)))))));
    return;
  }
  
  void D_7_1_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0035756392861027368 + QzQbar_z*(0.017878196430513684 + QzQbar_z*(-0.06436150714984926 + QzQbar_z*(-0.0643615071498493 + QzQbar_z*(0.2681729464577053 + QzQbar_z*(0.053634589291541 + QzQbar_z*(-0.500589500054383 + QzQbar_z*(0.071512785722055 + QzQbar_z*(0.482711303623869 + QzQbar_z*(-0.1609037678746232 + QzQbar_z*(-0.2359921928827806 + QzQbar_z*(0.1072691785830821 + (0.046483310719335578 - 0.0250294750027191574*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_2_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0058389945034674795 + QzQbar_z*(-0.00291949725173374 + QzQbar_z*(-0.07006793404160975 + QzQbar_z*(0.1109408955658821 + QzQbar_z*(0.145974862586687 + QzQbar_z*(-0.394132128984055 + QzQbar_z*(0.e-15 + QzQbar_z*(0.525509505312073 + QzQbar_z*(-0.262754752656037 + QzQbar_z*(-0.2773522389147053 + QzQbar_z*(0.2569157581525691 + QzQbar_z*(0.01751698351040244 + (-0.075906928545077234 + 0.0204364807621361783*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_3_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0061931889130692491 + QzQbar_z*(-0.02270835934792058 + QzQbar_z*(-0.0123863778261385 + QzQbar_z*(0.1610229117398005 + QzQbar_z*(-0.1961176489138596 + QzQbar_z*(-0.16721610065287 + QzQbar_z*(0.520227868697817 + QzQbar_z*(-0.222954800870493 + QzQbar_z*(-0.3530117680449472 + QzQbar_z*(0.4025572793495012 + QzQbar_z*(-0.0454167186958412 + QzQbar_z*(-0.13625015608752348 + (0.080511455869900238 - 0.0144507741304949146*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_4_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0049795112437429539 + QzQbar_z*(-0.031121945273393462 + QzQbar_z*(0.05975413492491545 + QzQbar_z*(0.0273873118405862 + QzQbar_z*(-0.2738731184058625 + QzQbar_z*(0.3697287098479143 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.4929716131305524 + QzQbar_z*(0.4929716131305524 + QzQbar_z*(-0.0684682796014656 + QzQbar_z*(-0.21909849472468997 + QzQbar_z*(0.18673167164036077 + (-0.064733646168658401 + 0.0087141446765501694*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_5_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0031121945273393462 + QzQbar_z*(-0.026764872935118377 + QzQbar_z*(0.09336583582018039 + QzQbar_z*(-0.1506302151232244 + QzQbar_z*(0.0342341398007328 + QzQbar_z*(0.3081072582065953 + QzQbar_z*(-0.5751335486523112 + QzQbar_z*(0.4108096776087937 + QzQbar_z*(0.0616214516413191 + QzQbar_z*(-0.3765755378080609 + QzQbar_z*(0.34234139800732808 + QzQbar_z*(-0.16058923761071026 + (0.040458528855411501 - 0.00435707233827508469*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_6_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.00146484375 + QzQbar_z*(-0.015869140625 + QzQbar_z*(0.076171875 + QzQbar_z*(-0.20947265625 + QzQbar_z*(0.34912109375 + QzQbar_z*(-0.314208984375 + QzQbar_z*(0.e-16 + QzQbar_z*(0.4189453125 + QzQbar_z*(-0.62841796875 + QzQbar_z*(0.523681640625 + QzQbar_z*(-0.279296875 + QzQbar_z*(0.09521484375 + (-0.01904296875 + 0.001708984375*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_7_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.00045674528647142839 + QzQbar_z*(-0.0059376887241285691 + QzQbar_z*(0.035626132344771415 + QzQbar_z*(-0.13062915193082852 + QzQbar_z*(0.3265728798270713 + QzQbar_z*(-0.58783118368872834 + QzQbar_z*(0.78377491158497112 + QzQbar_z*(-0.78377491158497112 + QzQbar_z*(0.58783118368872834 + QzQbar_z*(-0.3265728798270713 + QzQbar_z*(0.13062915193082852 + QzQbar_z*(-0.035626132344771415 + (0.0059376887241285691 - 0.000456745286471428392*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_7_neg7_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.00232895312845934 + QzQbar_z*(0.02794743754151208 + QzQbar_z*(0.15371090647831644 + QzQbar_z*(0.51236968826105479 + QzQbar_z*(1.1528317985873733 + QzQbar_z*(1.8445308777397973 + QzQbar_z*(2.1519526906964301 + QzQbar_z*(1.8445308777397973 + QzQbar_z*(1.15283179858737328 + QzQbar_z*(0.51236968826105479 + QzQbar_z*(0.153710906478316438 + (0.0279474375415120796 + 0.00232895312845933996*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_neg6_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0062243890546786924 + QzQbar_z*(0.059754134924915447 + QzQbar_z*(0.24648580656527622 + QzQbar_z*(0.5477462368117249 + QzQbar_z*(0.6162145164131905 + QzQbar_z*(0.e-16 + QzQbar_z*(-1.1502670973046224 + QzQbar_z*(-1.9718864525222098 + QzQbar_z*(-1.8486435492395716 + QzQbar_z*(-1.09549247362344987 + QzQbar_z*(-0.4108096776087937 + (-0.089631202387373171 - 0.0087141446765501694*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_neg5_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.010498046875 + QzQbar_z*(0.0732421875 + QzQbar_z*(0.17724609375 + QzQbar_z*(0.0537109375 + QzQbar_z*(-0.604248046875 + QzQbar_z*(-1.353515625 + QzQbar_z*(-1.1279296875 + QzQbar_z*(0.193359375 + QzQbar_z*(1.329345703125 + QzQbar_z*(1.3427734375 + QzQbar_z*(0.69287109375 + (0.1904296875 + 0.022216796875*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_neg4_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.01220703125 + QzQbar_z*(0.046875 + QzQbar_z*(-0.0322265625 + QzQbar_z*(-0.4296875 + QzQbar_z*(-0.72509765625 + QzQbar_z*(0.e-15 + QzQbar_z*(1.353515625 + QzQbar_z*(1.546875 + QzQbar_z*(0.24169921875 + QzQbar_z*(-0.859375 + QzQbar_z*(-0.8056640625 + (-0.3046875 - 0.04443359375*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_neg3_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.008906951341286474 + QzQbar_z*(-0.00971667419049434 + QzQbar_z*(-0.1894751467146395 + QzQbar_z*(-0.3076946826989873 + QzQbar_z*(0.327937753929184 + QzQbar_z*(1.224300948002286 + QzQbar_z*(0.612150474001143 + QzQbar_z*(-1.107700857716354 + QzQbar_z*(-1.421063600359797 + QzQbar_z*(-0.1781390268257295 + QzQbar_z*(0.5878587885249073 + (0.37895029342927908 + 0.073684779277915378*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_neg2_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.001145121035113142 + QzQbar_z*(-0.054965809685430815 + QzQbar_z*(-0.13054379800289819 + QzQbar_z*(0.2290242070226284 + QzQbar_z*(0.772956698701371 + QzQbar_z*(0.e-15 + QzQbar_z*(-1.442852504242559 + QzQbar_z*(-0.824487145281462 + QzQbar_z*(0.979078485021736 + QzQbar_z*(1.0077065108995649 + QzQbar_z*(-0.0755779883174674 + (-0.3572777629553003 - 0.10420601419529592*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_neg1_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.007012405574387242 + QzQbar_z*(-0.05048932013558814 + QzQbar_z*(0.07573398020338221 + QzQbar_z*(0.4207443344632345 + QzQbar_z*(-0.1051860836158086 + QzQbar_z*(-1.178084136497057 + QzQbar_z*(-0.196347356082843 + QzQbar_z*(1.514679604067644 + QzQbar_z*(0.568004851525367 + QzQbar_z*(-0.9256375358191159 + QzQbar_z*(-0.462818767909558 + (0.21878705392088195 + 0.127625781453847805*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_0_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.010495207646584315 + pow(QzQbar_z,2)*(0.18891373763851767 + pow(QzQbar_z,2)*(-0.78714057349382362 + pow(QzQbar_z,2)*(1.46932907052180409 + pow(QzQbar_z,2)*(-1.41685303228888252 + pow(QzQbar_z,2)*(0.69268370467456479 - 0.136437699405596094*pow(QzQbar_z,2))))));
    return;
  }
  
  void D_7_1_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.007012405574387242 + QzQbar_z*(0.05048932013558814 + QzQbar_z*(0.07573398020338221 + QzQbar_z*(-0.4207443344632345 + QzQbar_z*(-0.1051860836158086 + QzQbar_z*(1.178084136497057 + QzQbar_z*(-0.196347356082843 + QzQbar_z*(-1.514679604067644 + QzQbar_z*(0.568004851525367 + QzQbar_z*(0.9256375358191159 + QzQbar_z*(-0.462818767909558 + (-0.21878705392088195 + 0.127625781453847805*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_2_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.001145121035113142 + QzQbar_z*(0.054965809685430815 + QzQbar_z*(-0.13054379800289819 + QzQbar_z*(-0.2290242070226284 + QzQbar_z*(0.772956698701371 + QzQbar_z*(0.e-15 + QzQbar_z*(-1.442852504242559 + QzQbar_z*(0.824487145281462 + QzQbar_z*(0.979078485021736 + QzQbar_z*(-1.0077065108995649 + QzQbar_z*(-0.0755779883174674 + (0.3572777629553003 - 0.10420601419529592*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_3_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.008906951341286474 + QzQbar_z*(0.00971667419049434 + QzQbar_z*(-0.1894751467146395 + QzQbar_z*(0.3076946826989873 + QzQbar_z*(0.327937753929184 + QzQbar_z*(-1.224300948002286 + QzQbar_z*(0.612150474001143 + QzQbar_z*(1.107700857716354 + QzQbar_z*(-1.421063600359797 + QzQbar_z*(0.1781390268257295 + QzQbar_z*(0.5878587885249073 + (-0.37895029342927908 + 0.073684779277915378*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_4_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.01220703125 + QzQbar_z*(-0.046875 + QzQbar_z*(-0.0322265625 + QzQbar_z*(0.4296875 + QzQbar_z*(-0.72509765625 + QzQbar_z*(0.e-15 + QzQbar_z*(1.353515625 + QzQbar_z*(-1.546875 + QzQbar_z*(0.24169921875 + QzQbar_z*(0.859375 + QzQbar_z*(-0.8056640625 + (0.3046875 - 0.04443359375*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_5_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.010498046875 + QzQbar_z*(-0.0732421875 + QzQbar_z*(0.17724609375 + QzQbar_z*(-0.0537109375 + QzQbar_z*(-0.604248046875 + QzQbar_z*(1.353515625 + QzQbar_z*(-1.1279296875 + QzQbar_z*(-0.193359375 + QzQbar_z*(1.329345703125 + QzQbar_z*(-1.3427734375 + QzQbar_z*(0.69287109375 + (-0.1904296875 + 0.022216796875*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_6_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0062243890546786924 + QzQbar_z*(-0.059754134924915447 + QzQbar_z*(0.24648580656527622 + QzQbar_z*(-0.5477462368117249 + QzQbar_z*(0.6162145164131905 + QzQbar_z*(0.e-16 + QzQbar_z*(-1.1502670973046224 + QzQbar_z*(1.9718864525222098 + QzQbar_z*(-1.8486435492395716 + QzQbar_z*(1.09549247362344987 + QzQbar_z*(-0.4108096776087937 + (0.089631202387373171 - 0.0087141446765501694*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_7_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.00232895312845934 + QzQbar_z*(-0.02794743754151208 + QzQbar_z*(0.15371090647831644 + QzQbar_z*(-0.51236968826105479 + QzQbar_z*(1.1528317985873733 + QzQbar_z*(-1.8445308777397973 + QzQbar_z*(2.1519526906964301 + QzQbar_z*(-1.8445308777397973 + QzQbar_z*(1.15283179858737328 + QzQbar_z*(-0.51236968826105479 + QzQbar_z*(0.153710906478316438 + (-0.0279474375415120796 + 0.00232895312845933996*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_7_neg7_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.00931581251383736 + QzQbar_z*(-0.10247393765221096 + QzQbar_z*(-0.51236968826105479 + QzQbar_z*(-1.5371090647831644 + QzQbar_z*(-3.0742181295663288 + QzQbar_z*(-4.3039053813928603 + QzQbar_z*(-4.3039053813928603 + QzQbar_z*(-3.0742181295663288 + QzQbar_z*(-1.53710906478316438 + QzQbar_z*(-0.51236968826105479 + (-0.102473937652210958 - 0.00931581251383735986*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_neg6_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.019918044974971816 + QzQbar_z*(-0.16432387104351748 + QzQbar_z*(-0.5477462368117249 + QzQbar_z*(-0.8216193552175874 + QzQbar_z*(0.e-16 + QzQbar_z*(2.3005341946092447 + QzQbar_z*(4.6010683892184894 + QzQbar_z*(4.9297161313055244 + QzQbar_z*(3.2864774208703496 + QzQbar_z*(1.36936559202931233 + (0.32864774208703496 + 0.0348565787062006775*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_neg5_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.0244140625 + QzQbar_z*(-0.1181640625 + QzQbar_z*(-0.0537109375 + QzQbar_z*(0.8056640625 + QzQbar_z*(2.255859375 + QzQbar_z*(2.255859375 + QzQbar_z*(-0.451171875 + QzQbar_z*(-3.544921875 + QzQbar_z*(-4.0283203125 + QzQbar_z*(-2.3095703125 + (-0.6982421875 - 0.0888671875*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_neg4_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.015625 + QzQbar_z*(0.021484375 + QzQbar_z*(0.4296875 + QzQbar_z*(0.966796875 + QzQbar_z*(0.e-15 + QzQbar_z*(-2.70703125 + QzQbar_z*(-3.609375 + QzQbar_z*(-0.64453125 + QzQbar_z*(2.578125 + QzQbar_z*(2.685546875 + (1.1171875 + 0.177734375*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_neg3_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.0032388913968314452 + QzQbar_z*(0.12631676447642636 + QzQbar_z*(0.3076946826989873 + QzQbar_z*(-0.4372503385722451 + QzQbar_z*(-2.04050158000381 + QzQbar_z*(-1.224300948002286 + QzQbar_z*(2.584635334671493 + QzQbar_z*(3.789502934292791 + QzQbar_z*(0.534417080477188 + QzQbar_z*(-1.9595292950830243 + (-1.38948440924068998 - 0.29473911711166151*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_neg2_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.018321936561810272 + QzQbar_z*(0.08702919866859879 + QzQbar_z*(-0.2290242070226284 + QzQbar_z*(-1.0306089316018278 + QzQbar_z*(0.e-15 + QzQbar_z*(2.885705008485118 + QzQbar_z*(1.923803338990079 + QzQbar_z*(-2.610875960057964 + QzQbar_z*(-3.023119532698695 + QzQbar_z*(0.2519266277248912 + (1.31001846416943443 + 0.416824056781183681*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_neg1_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.016829773378529381 + QzQbar_z*(-0.05048932013558814 + QzQbar_z*(-0.4207443344632345 + QzQbar_z*(0.1402481114877448 + QzQbar_z*(1.963473560828428 + QzQbar_z*(0.392694712165686 + QzQbar_z*(-3.53425240949117 + QzQbar_z*(-1.514679604067644 + QzQbar_z*(2.776912607457348 + QzQbar_z*(1.5427292263651932 + (-0.80221919770990049 - 0.51050312581539122*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_0_neg4(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-0.12594249175901178 + pow(QzQbar_z,2)*(1.0495207646584315 + pow(QzQbar_z,2)*(-2.9386581410436082 + pow(QzQbar_z,2)*(3.7782747527703534 + pow(QzQbar_z,2)*(-2.30894568224854929 + 0.54575079762238438*pow(QzQbar_z,2))))));
    return;
  }
  
  void D_7_1_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.016829773378529381 + QzQbar_z*(-0.05048932013558814 + QzQbar_z*(0.4207443344632345 + QzQbar_z*(0.1402481114877448 + QzQbar_z*(-1.963473560828428 + QzQbar_z*(0.392694712165686 + QzQbar_z*(3.53425240949117 + QzQbar_z*(-1.514679604067644 + QzQbar_z*(-2.776912607457348 + QzQbar_z*(1.5427292263651932 + (0.80221919770990049 - 0.51050312581539122*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_2_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.018321936561810272 + QzQbar_z*(0.08702919866859879 + QzQbar_z*(0.2290242070226284 + QzQbar_z*(-1.0306089316018278 + QzQbar_z*(0.e-15 + QzQbar_z*(2.885705008485118 + QzQbar_z*(-1.923803338990079 + QzQbar_z*(-2.610875960057964 + QzQbar_z*(3.023119532698695 + QzQbar_z*(0.2519266277248912 + (-1.31001846416943443 + 0.416824056781183681*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_3_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.0032388913968314452 + QzQbar_z*(0.12631676447642636 + QzQbar_z*(-0.3076946826989873 + QzQbar_z*(-0.4372503385722451 + QzQbar_z*(2.04050158000381 + QzQbar_z*(-1.224300948002286 + QzQbar_z*(-2.584635334671493 + QzQbar_z*(3.789502934292791 + QzQbar_z*(-0.534417080477188 + QzQbar_z*(-1.9595292950830243 + (1.38948440924068998 - 0.29473911711166151*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_4_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.015625 + QzQbar_z*(0.021484375 + QzQbar_z*(-0.4296875 + QzQbar_z*(0.966796875 + QzQbar_z*(0.e-15 + QzQbar_z*(-2.70703125 + QzQbar_z*(3.609375 + QzQbar_z*(-0.64453125 + QzQbar_z*(-2.578125 + QzQbar_z*(2.685546875 + (-1.1171875 + 0.177734375*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_5_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.0244140625 + QzQbar_z*(-0.1181640625 + QzQbar_z*(0.0537109375 + QzQbar_z*(0.8056640625 + QzQbar_z*(-2.255859375 + QzQbar_z*(2.255859375 + QzQbar_z*(0.451171875 + QzQbar_z*(-3.544921875 + QzQbar_z*(4.0283203125 + QzQbar_z*(-2.3095703125 + (0.6982421875 - 0.0888671875*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_6_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.019918044974971816 + QzQbar_z*(-0.16432387104351748 + QzQbar_z*(0.5477462368117249 + QzQbar_z*(-0.8216193552175874 + QzQbar_z*(0.e-16 + QzQbar_z*(2.3005341946092447 + QzQbar_z*(-4.6010683892184894 + QzQbar_z*(4.9297161313055244 + QzQbar_z*(-3.2864774208703496 + QzQbar_z*(1.36936559202931233 + (-0.32864774208703496 + 0.0348565787062006775*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_7_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.00931581251383736 + QzQbar_z*(-0.10247393765221096 + QzQbar_z*(0.51236968826105479 + QzQbar_z*(-1.5371090647831644 + QzQbar_z*(3.0742181295663288 + QzQbar_z*(-4.3039053813928603 + QzQbar_z*(4.3039053813928603 + QzQbar_z*(-3.0742181295663288 + QzQbar_z*(1.53710906478316438 + QzQbar_z*(-0.51236968826105479 + (0.102473937652210958 - 0.00931581251383735986*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_7_neg7_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.030897054725696044 + QzQbar_z*(0.30897054725696044 + QzQbar_z*(1.390367462656322 + QzQbar_z*(3.7076465670835253 + QzQbar_z*(6.4883814923961693 + QzQbar_z*(7.7860577908754031 + QzQbar_z*(6.4883814923961693 + QzQbar_z*(3.7076465670835253 + QzQbar_z*(1.39036746265632198 + (0.308970547256960441 + 0.0308970547256960441*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_7_neg6_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.049545511304553993 + QzQbar_z*(0.33030340869702662 + QzQbar_z*(0.7431826695683099 + QzQbar_z*(0.e-16 + QzQbar_z*(-3.46818579131878 + QzQbar_z*(-8.323645899165071 + QzQbar_z*(-10.404557373956339 + QzQbar_z*(-7.9272818087286389 + QzQbar_z*(-3.7159133478415495 + (-0.99091022609107986 - 0.115606193043959317*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_7_neg5_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.035627805365145897 + QzQbar_z*(0.03238891396831445 + QzQbar_z*(-0.7287505642870752 + QzQbar_z*(-2.7206687733384139 + QzQbar_z*(-3.400835966673017 + QzQbar_z*(0.816200632001524 + QzQbar_z*(7.481839126680638 + QzQbar_z*(9.716674190494335 + QzQbar_z*(6.2672548528688464 + (2.10527940794043936 + 0.29473911711166151*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_7_neg4_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.0064777827936628903 + QzQbar_z*(-0.25911131174651561 + QzQbar_z*(-0.8745006771444902 + QzQbar_z*(0.e-16 + QzQbar_z*(4.081003160007621 + QzQbar_z*(6.529605056012193 + QzQbar_z*(1.360334386669207 + QzQbar_z*(-6.218671481916375 + QzQbar_z*(-7.2875056428707516 + (-3.368447052704703 - 0.58947823422332302*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_7_neg3_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.0380859375 + QzQbar_z*(-0.185546875 + QzQbar_z*(0.3955078125 + QzQbar_z*(2.4609375 + QzQbar_z*(1.845703125 + QzQbar_z*(-4.67578125 + QzQbar_z*(-7.998046875 + QzQbar_z*(-1.2890625 + QzQbar_z*(5.3173828125 + (4.189453125 + 0.9775390625*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_7_neg2_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.026240290708094537 + QzQbar_z*(0.13810679320049756 + QzQbar_z*(0.9322208541033586 + QzQbar_z*(0.e-16 + QzQbar_z*(-4.3503639858156732 + QzQbar_z*(-3.480291188652539 + QzQbar_z*(5.510461048699853 + QzQbar_z*(7.292038680986271 + QzQbar_z*(-0.683628626342463 + (-3.9498542855342303 - 1.38244899993698061*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_7_neg1_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.015223102800898336 + QzQbar_z*(0.25371838001497226 + QzQbar_z*(-0.1268591900074861 + QzQbar_z*(-2.3680382134730744 + QzQbar_z*(-0.592009553368269 + QzQbar_z*(6.393703176377301 + QzQbar_z*(3.19685158818865 + QzQbar_z*(-6.698165232395268 + QzQbar_z*(-4.1863532702470423 + QzQbar_z*(2.4187818894760689 + 1.69314732263324821*QzQbar_z)))))))));
    return;
  }
  
  void D_7_0_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.037973090029733556 + pow(QzQbar_z,2)*(-0.9493272507433389 + pow(QzQbar_z,2)*(4.4301938368022482 + pow(QzQbar_z,2)*(-7.9743489062440468 + pow(QzQbar_z,2)*(6.2655598549060367 - 1.81005062475063284*pow(QzQbar_z,2)))));
    return;
  }
  
  void D_7_1_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.015223102800898336 + QzQbar_z*(-0.25371838001497226 + QzQbar_z*(-0.1268591900074861 + QzQbar_z*(2.3680382134730744 + QzQbar_z*(-0.592009553368269 + QzQbar_z*(-6.393703176377301 + QzQbar_z*(3.19685158818865 + QzQbar_z*(6.698165232395268 + QzQbar_z*(-4.1863532702470423 + QzQbar_z*(-2.4187818894760689 + 1.69314732263324821*QzQbar_z)))))))));
    return;
  }
  
  void D_7_2_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.026240290708094537 + QzQbar_z*(-0.13810679320049756 + QzQbar_z*(0.9322208541033586 + QzQbar_z*(0.e-16 + QzQbar_z*(-4.3503639858156732 + QzQbar_z*(3.480291188652539 + QzQbar_z*(5.510461048699853 + QzQbar_z*(-7.292038680986271 + QzQbar_z*(-0.683628626342463 + (3.9498542855342303 - 1.38244899993698061*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_7_3_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.0380859375 + QzQbar_z*(0.185546875 + QzQbar_z*(0.3955078125 + QzQbar_z*(-2.4609375 + QzQbar_z*(1.845703125 + QzQbar_z*(4.67578125 + QzQbar_z*(-7.998046875 + QzQbar_z*(1.2890625 + QzQbar_z*(5.3173828125 + (-4.189453125 + 0.9775390625*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_7_4_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.0064777827936628903 + QzQbar_z*(0.25911131174651561 + QzQbar_z*(-0.8745006771444902 + QzQbar_z*(0.e-16 + QzQbar_z*(4.081003160007621 + QzQbar_z*(-6.529605056012193 + QzQbar_z*(1.360334386669207 + QzQbar_z*(6.218671481916375 + QzQbar_z*(-7.2875056428707516 + (3.368447052704703 - 0.58947823422332302*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_7_5_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.035627805365145897 + QzQbar_z*(-0.03238891396831445 + QzQbar_z*(-0.7287505642870752 + QzQbar_z*(2.7206687733384139 + QzQbar_z*(-3.400835966673017 + QzQbar_z*(-0.816200632001524 + QzQbar_z*(7.481839126680638 + QzQbar_z*(-9.716674190494335 + QzQbar_z*(6.2672548528688464 + (-2.10527940794043936 + 0.29473911711166151*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_7_6_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.049545511304553993 + QzQbar_z*(-0.33030340869702662 + QzQbar_z*(0.7431826695683099 + QzQbar_z*(0.e-16 + QzQbar_z*(-3.46818579131878 + QzQbar_z*(8.323645899165071 + QzQbar_z*(-10.404557373956339 + QzQbar_z*(7.9272818087286389 + QzQbar_z*(-3.7159133478415495 + (0.99091022609107986 - 0.115606193043959317*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_7_7_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.030897054725696044 + QzQbar_z*(-0.30897054725696044 + QzQbar_z*(1.390367462656322 + QzQbar_z*(-3.7076465670835253 + QzQbar_z*(6.4883814923961693 + QzQbar_z*(-7.7860577908754031 + QzQbar_z*(6.4883814923961693 + QzQbar_z*(-3.7076465670835253 + QzQbar_z*(1.39036746265632198 + (-0.308970547256960441 + 0.0308970547256960441*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_7_neg7_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.087390067660926147 + QzQbar_z*(-0.78651060894833532 + QzQbar_z*(-3.1460424357933413 + QzQbar_z*(-7.3407656835177964 + QzQbar_z*(-11.0111485252766945 + QzQbar_z*(-11.0111485252766945 + QzQbar_z*(-7.3407656835177964 + QzQbar_z*(-3.1460424357933413 + (-0.78651060894833532 - 0.0873900676609261472*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_7_neg6_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.093423912055479672 + QzQbar_z*(-0.42040760424965852 + QzQbar_z*(0.e-16 + QzQbar_z*(3.923804306330146 + QzQbar_z*(11.771412918990439 + QzQbar_z*(17.657119378485658 + QzQbar_z*(15.695217225320585 + QzQbar_z*(8.4081520849931705 + (2.52244562549795115 + 0.326983692194178852*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_7_neg5_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.0091609682809051358 + QzQbar_z*(0.41224357264073111 + QzQbar_z*(2.3085640067880942 + QzQbar_z*(3.847606677980157 + QzQbar_z*(-1.154282003394047 + QzQbar_z*(-12.697102037334518 + QzQbar_z*(-19.238033389900785 + QzQbar_z*(-14.1811788988411503 + (-5.3591664443295045 - 0.83364811356236736*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_7_neg4_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.073287746247241087 + QzQbar_z*(0.49469228716887734 + QzQbar_z*(0.e-16 + QzQbar_z*(-4.6171280135761885 + QzQbar_z*(-9.234256027152377 + QzQbar_z*(-2.308564006788094 + QzQbar_z*(12.312341369536503 + QzQbar_z*(16.489742905629245 + QzQbar_z*(8.5746663109272072 + 1.66729622712473472*QzQbar_z))))))));
    return;
  }
  
  void D_7_neg3_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.052480581416189074 + QzQbar_z*(-0.22373300498480605 + QzQbar_z*(-2.0881747131915232 + QzQbar_z*(-2.0881747131915232 + QzQbar_z*(6.612553258439823 + QzQbar_z*(13.573135635744901 + QzQbar_z*(2.552213538345195 + QzQbar_z*(-12.031863823627348 + (-10.6646065709424218 - 2.76489799987396122*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_7_neg2_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.0390625 + QzQbar_z*(-0.52734375 + QzQbar_z*(0.e-16 + QzQbar_z*(4.921875 + QzQbar_z*(4.921875 + QzQbar_z*(-9.3515625 + QzQbar_z*(-14.4375 + QzQbar_z*(1.546875 + QzQbar_z*(10.0546875 + 3.91015625*QzQbar_z))))))));
    return;
  }
  
  void D_7_neg1_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.071762394808100921 + QzQbar_z*(0.07176239480810092 + QzQbar_z*(2.0093470546268258 + QzQbar_z*(0.6697823515422753 + QzQbar_z*(-9.042061745820716 + QzQbar_z*(-5.4252370474924296 + QzQbar_z*(13.26169056053705 + QzQbar_z*(9.472636114669322 + (-6.157213474535059 - 4.78894381352726812*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_7_0_neg2(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(0.5370205892526375 + pow(QzQbar_z,2)*(-5.01219216635795 + pow(QzQbar_z,2)*(13.532918849166465 + pow(QzQbar_z,2)*(-14.17734355626963 + 5.1195962842084775*pow(QzQbar_z,2)))));
    return;
  }
  
  void D_7_1_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.071762394808100921 + QzQbar_z*(0.07176239480810092 + QzQbar_z*(-2.0093470546268258 + QzQbar_z*(0.6697823515422753 + QzQbar_z*(9.042061745820716 + QzQbar_z*(-5.4252370474924296 + QzQbar_z*(-13.26169056053705 + QzQbar_z*(9.472636114669322 + (6.157213474535059 - 4.78894381352726812*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_7_2_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.0390625 + QzQbar_z*(-0.52734375 + QzQbar_z*(0.e-16 + QzQbar_z*(4.921875 + QzQbar_z*(-4.921875 + QzQbar_z*(-9.3515625 + QzQbar_z*(14.4375 + QzQbar_z*(1.546875 + QzQbar_z*(-10.0546875 + 3.91015625*QzQbar_z))))))));
    return;
  }
  
  void D_7_3_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.052480581416189074 + QzQbar_z*(-0.22373300498480605 + QzQbar_z*(2.0881747131915232 + QzQbar_z*(-2.0881747131915232 + QzQbar_z*(-6.612553258439823 + QzQbar_z*(13.573135635744901 + QzQbar_z*(-2.552213538345195 + QzQbar_z*(-12.031863823627348 + (10.6646065709424218 - 2.76489799987396122*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_7_4_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.073287746247241087 + QzQbar_z*(0.49469228716887734 + QzQbar_z*(0.e-16 + QzQbar_z*(-4.6171280135761885 + QzQbar_z*(9.234256027152377 + QzQbar_z*(-2.308564006788094 + QzQbar_z*(-12.312341369536503 + QzQbar_z*(16.489742905629245 + QzQbar_z*(-8.5746663109272072 + 1.66729622712473472*QzQbar_z))))))));
    return;
  }
  
  void D_7_5_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.0091609682809051358 + QzQbar_z*(0.41224357264073111 + QzQbar_z*(-2.3085640067880942 + QzQbar_z*(3.847606677980157 + QzQbar_z*(1.154282003394047 + QzQbar_z*(-12.697102037334518 + QzQbar_z*(19.238033389900785 + QzQbar_z*(-14.1811788988411503 + (5.3591664443295045 - 0.83364811356236736*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_7_6_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.093423912055479672 + QzQbar_z*(-0.42040760424965852 + QzQbar_z*(0.e-16 + QzQbar_z*(3.923804306330146 + QzQbar_z*(-11.771412918990439 + QzQbar_z*(17.657119378485658 + QzQbar_z*(-15.695217225320585 + QzQbar_z*(8.4081520849931705 + (-2.52244562549795115 + 0.326983692194178852*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_7_7_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.087390067660926147 + QzQbar_z*(-0.78651060894833532 + QzQbar_z*(3.1460424357933413 + QzQbar_z*(-7.3407656835177964 + QzQbar_z*(11.0111485252766945 + QzQbar_z*(-11.0111485252766945 + QzQbar_z*(7.3407656835177964 + QzQbar_z*(-3.1460424357933413 + (0.78651060894833532 - 0.0873900676609261472*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_7_neg7_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.21406107435656652 + QzQbar_z*(1.7124885948525321 + QzQbar_z*(5.9937100819838625 + QzQbar_z*(11.987420163967725 + QzQbar_z*(14.9842752049596563 + QzQbar_z*(11.987420163967725 + QzQbar_z*(5.9937100819838625 + (1.71248859485253215 + 0.214061074356566519*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_7_neg6_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.11442045715528758 + QzQbar_z*(0.e-16 + QzQbar_z*(-3.2037728003480521 + QzQbar_z*(-12.815091201392209 + QzQbar_z*(-24.028296002610391 + QzQbar_z*(-25.630182402784417 + QzQbar_z*(-16.0188640017402607 + (-5.4921819434538037 - 0.80094320008701304*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_7_neg5_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.112198489190195872 + QzQbar_z*(-1.25662307893019377 + QzQbar_z*(-3.1415576973254844 + QzQbar_z*(1.256623078930194 + QzQbar_z*(17.278567335290164 + QzQbar_z*(31.415576973254844 + QzQbar_z*(27.017396196999166 + QzQbar_z*(11.6686428757803707 + 2.04201250326156488*QzQbar_z)))))));
    return;
  }
  
  void D_7_neg4_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.134638187028235047 + QzQbar_z*(0.e-17 + QzQbar_z*(3.7698692367905813 + QzQbar_z*(10.05298463144155 + QzQbar_z*(3.141557697325484 + QzQbar_z*(-20.1059692628831 + QzQbar_z*(-31.415576973254844 + (-18.6698286012485931 - 4.08402500652312975*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_7_neg3_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.060892411203593342 + QzQbar_z*(1.13665834246707572 + QzQbar_z*(1.7049875137006136 + QzQbar_z*(-7.1988361689581463 + QzQbar_z*(-18.470698065089981 + QzQbar_z*(-4.167747255712611 + QzQbar_z*(22.92260990641936 + QzQbar_z*(23.2203061389702612 + 6.7725892905329929*QzQbar_z)))))));
    return;
  }
  
  void D_7_neg2_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.143524789616201842 + QzQbar_z*(0.e-17 + QzQbar_z*(-4.0186941092536516 + QzQbar_z*(-5.3582588123382021 + QzQbar_z*(12.72586467930323 + QzQbar_z*(23.576338774288089 + QzQbar_z*(-2.947042346786011 + (-21.8923145761246543 - 9.5778876270545362*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_7_neg1_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.01953125 + QzQbar_z*(-1.09375 + QzQbar_z*(-0.546875 + QzQbar_z*(9.84375 + QzQbar_z*(7.3828125 + QzQbar_z*(-21.65625 + QzQbar_z*(-18.046875 + QzQbar_z*(13.40625 + 11.73046875*QzQbar_z)))))));
    return;
  }
  
  void D_7_0_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.146158491670857085 + pow(QzQbar_z,2)*(4.09243776678399839 + pow(QzQbar_z,2)*(-18.4159699505279928 + pow(QzQbar_z,2)*(27.0100892607743894 - 12.5403985853595379*pow(QzQbar_z,2))));
    return;
  }
  
  void D_7_1_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.01953125 + QzQbar_z*(1.09375 + QzQbar_z*(-0.546875 + QzQbar_z*(-9.84375 + QzQbar_z*(7.3828125 + QzQbar_z*(21.65625 + QzQbar_z*(-18.046875 + QzQbar_z*(-13.40625 + 11.73046875*QzQbar_z)))))));
    return;
  }
  
  void D_7_2_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.143524789616201842 + QzQbar_z*(0.e-17 + QzQbar_z*(-4.0186941092536516 + QzQbar_z*(5.3582588123382021 + QzQbar_z*(12.72586467930323 + QzQbar_z*(-23.576338774288089 + QzQbar_z*(-2.947042346786011 + (21.8923145761246543 - 9.5778876270545362*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_7_3_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.060892411203593342 + QzQbar_z*(-1.13665834246707572 + QzQbar_z*(1.7049875137006136 + QzQbar_z*(7.1988361689581463 + QzQbar_z*(-18.470698065089981 + QzQbar_z*(4.167747255712611 + QzQbar_z*(22.92260990641936 + QzQbar_z*(-23.2203061389702612 + 6.7725892905329929*QzQbar_z)))))));
    return;
  }
  
  void D_7_4_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.134638187028235047 + QzQbar_z*(0.e-17 + QzQbar_z*(3.7698692367905813 + QzQbar_z*(-10.05298463144155 + QzQbar_z*(3.141557697325484 + QzQbar_z*(20.1059692628831 + QzQbar_z*(-31.415576973254844 + (18.6698286012485931 - 4.08402500652312975*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_7_5_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.112198489190195872 + QzQbar_z*(1.25662307893019377 + QzQbar_z*(-3.1415576973254844 + QzQbar_z*(-1.256623078930194 + QzQbar_z*(17.278567335290164 + QzQbar_z*(-31.415576973254844 + QzQbar_z*(27.017396196999166 + QzQbar_z*(-11.6686428757803707 + 2.04201250326156488*QzQbar_z)))))));
    return;
  }
  
  void D_7_6_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.11442045715528758 + QzQbar_z*(0.e-16 + QzQbar_z*(-3.2037728003480521 + QzQbar_z*(12.815091201392209 + QzQbar_z*(-24.028296002610391 + QzQbar_z*(25.630182402784417 + QzQbar_z*(-16.0188640017402607 + (5.4921819434538037 - 0.80094320008701304*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_7_7_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.21406107435656652 + QzQbar_z*(-1.7124885948525321 + QzQbar_z*(5.9937100819838625 + QzQbar_z*(-11.987420163967725 + QzQbar_z*(14.9842752049596563 + QzQbar_z*(-11.987420163967725 + QzQbar_z*(5.9937100819838625 + (-1.71248859485253215 + 0.214061074356566519*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_7_neg7_0(const double QzQbar_z, double& Mag) {
    Mag = -0.45768182862115031 + QzQbar_z*(-3.2037728003480521 + QzQbar_z*(-9.6113184010441564 + QzQbar_z*(-16.0188640017402607 + QzQbar_z*(-16.0188640017402607 + QzQbar_z*(-9.6113184010441564 + (-3.20377280034805215 - 0.457681828621150307*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_7_neg6_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(1.7124885948525321 + QzQbar_z*(10.2749315691151929 + QzQbar_z*(25.687328922787982 + QzQbar_z*(34.249771897050643 + QzQbar_z*(25.6873289227879822 + QzQbar_z*(10.2749315691151929 + 1.71248859485253215*QzQbar_z))))));
    return;
  }
  
  void D_7_neg5_0(const double QzQbar_z, double& Mag) {
    Mag = 0.33584664469069808 + QzQbar_z*(1.6792332234534904 + QzQbar_z*(-1.0075399340720942 + QzQbar_z*(-18.471565457988394 + QzQbar_z*(-41.98083058633726 + QzQbar_z*(-43.324217165100052 + (-21.8300319048953751 - 4.36600638097907502*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_7_neg4_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-2.0150798681441885 + QzQbar_z*(-8.0603194725767539 + QzQbar_z*(-3.358466446906981 + QzQbar_z*(26.867731575255846 + QzQbar_z*(50.376996703604712 + QzQbar_z*(34.9280510478326 + 8.73201276195815*QzQbar_z))))));
    return;
  }
  
  void D_7_neg3_0(const double QzQbar_z, double& Mag) {
    Mag = -0.30378472023786845 + QzQbar_z*(-0.91135416071360534 + QzQbar_z*(5.7719096845195005 + QzQbar_z*(19.7460068154614491 + QzQbar_z*(5.569386537694255 + QzQbar_z*(-36.757951148782082 + (-43.441214994015188 - 14.4804049980050627*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_7_neg2_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(2.14808235701055 + QzQbar_z*(4.2961647140211 + QzQbar_z*(-13.60452159440015 + QzQbar_z*(-31.5052079028214 + QzQbar_z*(4.72578118542321 + QzQbar_z*(40.95677027366782 + 20.47838513683391*QzQbar_z))))));
    return;
  }
  
  void D_7_neg1_0(const double QzQbar_z, double& Mag) {
    Mag = 0.292316983341714171 + QzQbar_z*(0.292316983341714171 + QzQbar_z*(-7.8925585502262826 + QzQbar_z*(-7.8925585502262826 + QzQbar_z*(28.9393813508297029 + QzQbar_z*(28.9393813508297029 + (-25.0807971707190759 - 25.0807971707190759*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_7_0_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-2.1875 + pow(QzQbar_z,2)*(19.6875 + pow(QzQbar_z,2)*(-43.3125 + 26.8125*pow(QzQbar_z,2))));
    return;
  }
  
  void D_7_1_0(const double QzQbar_z, double& Mag) {
    Mag = -0.292316983341714171 + QzQbar_z*(0.292316983341714171 + QzQbar_z*(7.8925585502262826 + QzQbar_z*(-7.8925585502262826 + QzQbar_z*(-28.9393813508297029 + QzQbar_z*(28.9393813508297029 + (25.0807971707190759 - 25.0807971707190759*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_7_2_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(2.14808235701055 + QzQbar_z*(-4.2961647140211 + QzQbar_z*(-13.60452159440015 + QzQbar_z*(31.5052079028214 + QzQbar_z*(4.72578118542321 + QzQbar_z*(-40.95677027366782 + 20.47838513683391*QzQbar_z))))));
    return;
  }
  
  void D_7_3_0(const double QzQbar_z, double& Mag) {
    Mag = 0.30378472023786845 + QzQbar_z*(-0.91135416071360534 + QzQbar_z*(-5.7719096845195005 + QzQbar_z*(19.7460068154614491 + QzQbar_z*(-5.569386537694255 + QzQbar_z*(-36.757951148782082 + (43.441214994015188 - 14.4804049980050627*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_7_4_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-2.0150798681441885 + QzQbar_z*(8.0603194725767539 + QzQbar_z*(-3.358466446906981 + QzQbar_z*(-26.867731575255846 + QzQbar_z*(50.376996703604712 + QzQbar_z*(-34.9280510478326 + 8.73201276195815*QzQbar_z))))));
    return;
  }
  
  void D_7_5_0(const double QzQbar_z, double& Mag) {
    Mag = -0.33584664469069808 + QzQbar_z*(1.6792332234534904 + QzQbar_z*(1.0075399340720942 + QzQbar_z*(-18.471565457988394 + QzQbar_z*(41.98083058633726 + QzQbar_z*(-43.324217165100052 + (21.8300319048953751 - 4.36600638097907502*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_7_6_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(1.7124885948525321 + QzQbar_z*(-10.2749315691151929 + QzQbar_z*(25.687328922787982 + QzQbar_z*(-34.249771897050643 + QzQbar_z*(25.6873289227879822 + QzQbar_z*(-10.2749315691151929 + 1.71248859485253215*QzQbar_z))))));
    return;
  }
  
  void D_7_7_0(const double QzQbar_z, double& Mag) {
    Mag = 0.45768182862115031 + QzQbar_z*(-3.2037728003480521 + QzQbar_z*(9.6113184010441564 + QzQbar_z*(-16.0188640017402607 + QzQbar_z*(16.0188640017402607 + QzQbar_z*(-9.6113184010441564 + (3.20377280034805215 - 0.457681828621150307*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_7_neg7_1(const double QzQbar_z, double& Mag) {
    Mag = 0.85624429742626607 + QzQbar_z*(5.1374657845575964 + QzQbar_z*(12.8436644613939911 + QzQbar_z*(17.1248859485253215 + QzQbar_z*(12.8436644613939911 + (5.1374657845575964 + 0.856244297426266075*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_7_neg6_1(const double QzQbar_z, double& Mag) {
    Mag = -0.45768182862115031 + QzQbar_z*(-5.4921819434538037 + QzQbar_z*(-20.595682287951764 + QzQbar_z*(-36.614546289692025 + QzQbar_z*(-34.326137146586273 + (-16.476545830361411 - 3.20377280034805215*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_7_neg5_1(const double QzQbar_z, double& Mag) {
    Mag = -0.44879395676078349 + QzQbar_z*(0.5385527481129402 + QzQbar_z*(14.810200573105855 + QzQbar_z*(44.879395676078349 + QzQbar_z*(57.89442042214107 + QzQbar_z*(35.005928627341112 + 8.1680500130462595*QzQbar_z)))));
    return;
  }
  
  void D_7_neg4_1(const double QzQbar_z, double& Mag) {
    Mag = 0.53855274811294019 + QzQbar_z*(4.3084219849035215 + QzQbar_z*(2.6927637405647009 + QzQbar_z*(-28.722813232690143 + QzQbar_z*(-67.319093514117523 + (-56.009485803745779 - 16.336100026092519*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_7_neg3_1(const double QzQbar_z, double& Mag) {
    Mag = 0.243569644814373369 + QzQbar_z*(-3.0852155009820627 + QzQbar_z*(-15.832026912934269 + QzQbar_z*(-5.953924651018016 + QzQbar_z*(49.119878370898629 + QzQbar_z*(69.660918416910784 + 27.0903571621319714*QzQbar_z)))));
    return;
  }
  
  void D_7_neg2_1(const double QzQbar_z, double& Mag) {
    Mag = -0.57409915846480737 + QzQbar_z*(-2.29639663385922947 + QzQbar_z*(10.90788401083134 + QzQbar_z*(33.6804839632686989 + QzQbar_z*(-6.315090743112881 + (-65.676943728373963 - 38.3115505082181449*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_7_neg1_1(const double QzQbar_z, double& Mag) {
    Mag = -0.078125 + QzQbar_z*(4.21875 + QzQbar_z*(6.328125 + QzQbar_z*(-30.9375 + QzQbar_z*(-38.671875 + QzQbar_z*(40.21875 + 46.921875*QzQbar_z)))));
    return;
  }
  
  void D_7_0_1(const double QzQbar_z, double& Mag) {
    Mag = 0.58463396668342834 + pow(QzQbar_z,2)*(-15.7851171004525652 + pow(QzQbar_z,2)*(57.878762701659406 - 50.161594341438152*pow(QzQbar_z,2)));
    return;
  }
  
  void D_7_1_1(const double QzQbar_z, double& Mag) {
    Mag = -0.078125 + QzQbar_z*(-4.21875 + QzQbar_z*(6.328125 + QzQbar_z*(30.9375 + QzQbar_z*(-38.671875 + QzQbar_z*(-40.21875 + 46.921875*QzQbar_z)))));
    return;
  }
  
  void D_7_2_1(const double QzQbar_z, double& Mag) {
    Mag = -0.57409915846480737 + QzQbar_z*(2.29639663385922947 + QzQbar_z*(10.90788401083134 + QzQbar_z*(-33.6804839632686989 + QzQbar_z*(-6.315090743112881 + (65.676943728373963 - 38.3115505082181449*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_7_3_1(const double QzQbar_z, double& Mag) {
    Mag = 0.243569644814373369 + QzQbar_z*(3.0852155009820627 + QzQbar_z*(-15.832026912934269 + QzQbar_z*(5.953924651018016 + QzQbar_z*(49.119878370898629 + QzQbar_z*(-69.660918416910784 + 27.0903571621319714*QzQbar_z)))));
    return;
  }
  
  void D_7_4_1(const double QzQbar_z, double& Mag) {
    Mag = 0.53855274811294019 + QzQbar_z*(-4.3084219849035215 + QzQbar_z*(2.6927637405647009 + QzQbar_z*(28.722813232690143 + QzQbar_z*(-67.319093514117523 + (56.009485803745779 - 16.336100026092519*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_7_5_1(const double QzQbar_z, double& Mag) {
    Mag = -0.44879395676078349 + QzQbar_z*(-0.5385527481129402 + QzQbar_z*(14.810200573105855 + QzQbar_z*(-44.879395676078349 + QzQbar_z*(57.89442042214107 + QzQbar_z*(-35.005928627341112 + 8.1680500130462595*QzQbar_z)))));
    return;
  }
  
  void D_7_6_1(const double QzQbar_z, double& Mag) {
    Mag = -0.45768182862115031 + QzQbar_z*(5.4921819434538037 + QzQbar_z*(-20.595682287951764 + QzQbar_z*(36.614546289692025 + QzQbar_z*(-34.326137146586273 + (16.476545830361411 - 3.20377280034805215*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_7_7_1(const double QzQbar_z, double& Mag) {
    Mag = 0.85624429742626607 + QzQbar_z*(-5.1374657845575964 + QzQbar_z*(12.8436644613939911 + QzQbar_z*(-17.1248859485253215 + QzQbar_z*(12.8436644613939911 + (-5.1374657845575964 + 0.856244297426266075*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_7_neg7_2(const double QzQbar_z, double& Mag) {
    Mag = -1.39824108257481835 + QzQbar_z*(-6.9912054128740918 + QzQbar_z*(-13.9824108257481835 + QzQbar_z*(-13.9824108257481835 + (-6.9912054128740918 - 1.39824108257481835*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_7_neg6_2(const double QzQbar_z, double& Mag) {
    Mag = 1.49478259288767475 + QzQbar_z*(11.2108694466575606 + QzQbar_z*(29.895651857753495 + QzQbar_z*(37.369564822191869 + QzQbar_z*(22.4217388933151213 + 5.2317390751068616*QzQbar_z))));
    return;
  }
  
  void D_7_neg5_2(const double QzQbar_z, double& Mag) {
    Mag = -0.146575492494482174 + QzQbar_z*(-8.0616520871965195 + QzQbar_z*(-36.643873123620543 + QzQbar_z*(-63.027461772627335 + (-47.637035060706706 - 13.3383698169978778*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_7_neg4_2(const double QzQbar_z, double& Mag) {
    Mag = -1.17260393995585739 + QzQbar_z*(-1.4657549249448217 + QzQbar_z*(23.4520787991171478 + QzQbar_z*(73.287746247241087 + QzQbar_z*(76.21925609713073 + 26.6767396339957556*QzQbar_z))));
    return;
  }
  
  void D_7_neg3_2(const double QzQbar_z, double& Mag) {
    Mag = 0.83968930265902519 + QzQbar_z*(8.617863895711048 + QzQbar_z*(4.86135912065751423 + QzQbar_z*(-53.474950327232657 + (-94.796502852821527 - 44.2383679979833795*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_7_neg2_2(const double QzQbar_z, double& Mag) {
    Mag = 0.625 + QzQbar_z*(-5.9375 + QzQbar_z*(-27.5 + QzQbar_z*(6.875 + QzQbar_z*(89.375 + 62.5625*QzQbar_z))));
    return;
  }
  
  void D_7_neg1_2(const double QzQbar_z, double& Mag) {
    Mag = -1.14819831692961473 + QzQbar_z*(-3.4445949507888442 + QzQbar_z*(25.2603629724515241 + QzQbar_z*(42.1006049540858736 + (-54.730786440311636 - 76.62310101643629*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_7_0_2(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(8.5923294280422 + pow(QzQbar_z,2)*(-63.0104158056428 + 81.91354054733564*pow(QzQbar_z,2)));
    return;
  }
  
  void D_7_1_2(const double QzQbar_z, double& Mag) {
    Mag = 1.14819831692961473 + QzQbar_z*(-3.4445949507888442 + QzQbar_z*(-25.2603629724515241 + QzQbar_z*(42.1006049540858736 + (54.730786440311636 - 76.62310101643629*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_7_2_2(const double QzQbar_z, double& Mag) {
    Mag = -0.625 + QzQbar_z*(-5.9375 + QzQbar_z*(27.5 + QzQbar_z*(6.875 + QzQbar_z*(-89.375 + 62.5625*QzQbar_z))));
    return;
  }
  
  void D_7_3_2(const double QzQbar_z, double& Mag) {
    Mag = -0.83968930265902519 + QzQbar_z*(8.617863895711048 + QzQbar_z*(-4.86135912065751423 + QzQbar_z*(-53.474950327232657 + (94.796502852821527 - 44.2383679979833795*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_7_4_2(const double QzQbar_z, double& Mag) {
    Mag = 1.17260393995585739 + QzQbar_z*(-1.4657549249448217 + QzQbar_z*(-23.4520787991171478 + QzQbar_z*(73.287746247241087 + QzQbar_z*(-76.21925609713073 + 26.6767396339957556*QzQbar_z))));
    return;
  }
  
  void D_7_5_2(const double QzQbar_z, double& Mag) {
    Mag = 0.146575492494482174 + QzQbar_z*(-8.0616520871965195 + QzQbar_z*(36.643873123620543 + QzQbar_z*(-63.027461772627335 + (47.637035060706706 - 13.3383698169978778*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_7_6_2(const double QzQbar_z, double& Mag) {
    Mag = -1.49478259288767475 + QzQbar_z*(11.2108694466575606 + QzQbar_z*(-29.895651857753495 + QzQbar_z*(37.369564822191869 + QzQbar_z*(-22.4217388933151213 + 5.2317390751068616*QzQbar_z))));
    return;
  }
  
  void D_7_7_2(const double QzQbar_z, double& Mag) {
    Mag = 1.39824108257481835 + QzQbar_z*(-6.9912054128740918 + QzQbar_z*(13.9824108257481835 + QzQbar_z*(-13.9824108257481835 + (6.9912054128740918 - 1.39824108257481835*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_7_neg7_3(const double QzQbar_z, double& Mag) {
    Mag = 1.97741150244454682 + QzQbar_z*(7.9096460097781873 + QzQbar_z*(11.8644690146672809 + QzQbar_z*(7.9096460097781873 + 1.97741150244454682*QzQbar_z)));
    return;
  }
  
  void D_7_neg6_3(const double QzQbar_z, double& Mag) {
    Mag = -3.1709127234914555 + QzQbar_z*(-16.9115345252877629 + QzQbar_z*(-31.709127234914555 + (-25.3673017879316443 - 7.3987963548133963*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_7_neg5_3(const double QzQbar_z, double& Mag) {
    Mag = 2.2801795433693374 + QzQbar_z*(20.7289049397212491 + QzQbar_z*(53.480574744480823 + QzQbar_z*(53.895152843275248 + 18.8633034951463366*QzQbar_z)));
    return;
  }
  
  void D_7_neg4_3(const double QzQbar_z, double& Mag) {
    Mag = 0.414578098794424981 + QzQbar_z*(-13.2664991614215994 + QzQbar_z*(-62.186714819163747 + (-86.232244549240396 - 37.7266069902926733*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_7_neg3_3(const double QzQbar_z, double& Mag) {
    Mag = -2.4375 + QzQbar_z*(-2.75 + QzQbar_z*(45.375 + QzQbar_z*(107.25 + 62.5625*QzQbar_z)));
    return;
  }
  
  void D_7_neg2_3(const double QzQbar_z, double& Mag) {
    Mag = 1.67937860531805037 + QzQbar_z*(15.5563491861040455 + QzQbar_z*(-5.8336309447890171 + (-101.116269709676296 - 88.476735995966759*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_7_neg1_3(const double QzQbar_z, double& Mag) {
    Mag = 0.97427857925749348 + QzQbar_z*(-14.2894191624432377 + QzQbar_z*(-35.7235479061080942 + QzQbar_z*(61.920816370587363 + 108.361428648527886*QzQbar_z)));
    return;
  }
  
  void D_7_0_3(const double QzQbar_z, double& Mag) {
    Mag = -2.43027776190294759 + pow(QzQbar_z,2)*(53.466110761864847 - 115.843239984040502*pow(QzQbar_z,2));
    return;
  }
  
  void D_7_1_3(const double QzQbar_z, double& Mag) {
    Mag = 0.97427857925749348 + QzQbar_z*(14.2894191624432377 + QzQbar_z*(-35.7235479061080942 + QzQbar_z*(-61.920816370587363 + 108.361428648527886*QzQbar_z)));
    return;
  }
  
  void D_7_2_3(const double QzQbar_z, double& Mag) {
    Mag = 1.67937860531805037 + QzQbar_z*(-15.5563491861040455 + QzQbar_z*(-5.8336309447890171 + (101.116269709676296 - 88.476735995966759*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_7_3_3(const double QzQbar_z, double& Mag) {
    Mag = -2.4375 + QzQbar_z*(2.75 + QzQbar_z*(45.375 + QzQbar_z*(-107.25 + 62.5625*QzQbar_z)));
    return;
  }
  
  void D_7_4_3(const double QzQbar_z, double& Mag) {
    Mag = 0.414578098794424981 + QzQbar_z*(13.2664991614215994 + QzQbar_z*(-62.186714819163747 + (86.232244549240396 - 37.7266069902926733*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_7_5_3(const double QzQbar_z, double& Mag) {
    Mag = 2.2801795433693374 + QzQbar_z*(-20.7289049397212491 + QzQbar_z*(53.480574744480823 + QzQbar_z*(-53.895152843275248 + 18.8633034951463366*QzQbar_z)));
    return;
  }
  
  void D_7_6_3(const double QzQbar_z, double& Mag) {
    Mag = -3.1709127234914555 + QzQbar_z*(16.9115345252877629 + QzQbar_z*(-31.709127234914555 + (25.3673017879316443 - 7.3987963548133963*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_7_7_3(const double QzQbar_z, double& Mag) {
    Mag = 1.97741150244454682 + QzQbar_z*(-7.9096460097781873 + QzQbar_z*(11.8644690146672809 + QzQbar_z*(-7.9096460097781873 + 1.97741150244454682*QzQbar_z)));
    return;
  }
  
  void D_7_neg7_4(const double QzQbar_z, double& Mag) {
    Mag = -2.38484800354236412 + QzQbar_z*(-7.1545440106270924 + (-7.1545440106270924 - 2.38484800354236412*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_7_neg6_4(const double QzQbar_z, double& Mag) {
    Mag = 5.0990195135927848 + QzQbar_z*(19.1213231759729431 + QzQbar_z*(22.9455878111675317 + 8.9232841487873735*QzQbar_z));
    return;
  }
  
  void D_7_neg5_4(const double QzQbar_z, double& Mag) {
    Mag = -6.25 + QzQbar_z*(-32.25 + (-48.75 - 22.75*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_7_neg4_4(const double QzQbar_z, double& Mag) {
    Mag = 4. + QzQbar_z*(37.5 + QzQbar_z*(78. + 45.5*QzQbar_z));
    return;
  }
  
  void D_7_neg3_4(const double QzQbar_z, double& Mag) {
    Mag = 0.82915619758884996 + QzQbar_z*(-27.3621545204320488 + (-97.011275117895446 - 75.453213980585347*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_7_neg2_4(const double QzQbar_z, double& Mag) {
    Mag = -4.69041575982342955 + QzQbar_z*(3.51781181986757217 + QzQbar_z*(91.463107316556876 + 106.706958535983022*QzQbar_z));
    return;
  }
  
  void D_7_neg1_4(const double QzQbar_z, double& Mag) {
    Mag = 4.30842198490352149 + QzQbar_z*(21.5421099245176075 + (-56.009485803745779 - 130.688800208740152*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_7_0_4(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-32.2412778903070156 + 139.712204191330401*pow(QzQbar_z,2));
    return;
  }
  
  void D_7_1_4(const double QzQbar_z, double& Mag) {
    Mag = -4.30842198490352149 + QzQbar_z*(21.5421099245176075 + (56.009485803745779 - 130.688800208740152*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_7_2_4(const double QzQbar_z, double& Mag) {
    Mag = 4.69041575982342955 + QzQbar_z*(3.51781181986757217 + QzQbar_z*(-91.463107316556876 + 106.706958535983022*QzQbar_z));
    return;
  }
  
  void D_7_3_4(const double QzQbar_z, double& Mag) {
    Mag = -0.82915619758884996 + QzQbar_z*(-27.3621545204320488 + (97.011275117895446 - 75.453213980585347*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_7_4_4(const double QzQbar_z, double& Mag) {
    Mag = -4. + QzQbar_z*(37.5 + QzQbar_z*(-78. + 45.5*QzQbar_z));
    return;
  }
  
  void D_7_5_4(const double QzQbar_z, double& Mag) {
    Mag = 6.25 + QzQbar_z*(-32.25 + (48.75 - 22.75*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_7_6_4(const double QzQbar_z, double& Mag) {
    Mag = -5.0990195135927848 + QzQbar_z*(19.1213231759729431 + QzQbar_z*(-22.9455878111675317 + 8.9232841487873735*QzQbar_z));
    return;
  }
  
  void D_7_7_4(const double QzQbar_z, double& Mag) {
    Mag = 2.38484800354236412 + QzQbar_z*(-7.1545440106270924 + (7.1545440106270924 - 2.38484800354236412*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_7_neg7_5(const double QzQbar_z, double& Mag) {
    Mag = 2.38484800354236412 + QzQbar_z*(4.76969600708472825 + 2.38484800354236412*QzQbar_z);
    return;
  }
  
  void D_7_neg6_5(const double QzQbar_z, double& Mag) {
    Mag = -6.373774391990981 + (-15.2970585407783545 - 8.9232841487873735*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_7_neg5_5(const double QzQbar_z, double& Mag) {
    Mag = 10.75 + QzQbar_z*(32.5 + 22.75*QzQbar_z);
    return;
  }
  
  void D_7_neg4_5(const double QzQbar_z, double& Mag) {
    Mag = -12.5 + (-52. - 45.5*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_7_neg3_5(const double QzQbar_z, double& Mag) {
    Mag = 9.1207181734773496 + QzQbar_z*(64.674183411930297 + 75.453213980585347*QzQbar_z);
    return;
  }
  
  void D_7_neg2_5(const double QzQbar_z, double& Mag) {
    Mag = -1.17260393995585739 + (-60.975404877704584 - 106.706958535983022*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_7_neg1_5(const double QzQbar_z, double& Mag) {
    Mag = -7.1807033081725358 + QzQbar_z*(37.3396572024971863 + 130.688800208740152*QzQbar_z);
    return;
  }
  
  void D_7_0_5(const double QzQbar_z, double& Mag) {
    Mag = 10.7470926301023385 - 139.712204191330401*pow(QzQbar_z,2);
    return;
  }
  
  void D_7_1_5(const double QzQbar_z, double& Mag) {
    Mag = -7.1807033081725358 + QzQbar_z*(-37.3396572024971863 + 130.688800208740152*QzQbar_z);
    return;
  }
  
  void D_7_2_5(const double QzQbar_z, double& Mag) {
    Mag = -1.17260393995585739 + (60.975404877704584 - 106.706958535983022*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_7_3_5(const double QzQbar_z, double& Mag) {
    Mag = 9.1207181734773496 + QzQbar_z*(-64.674183411930297 + 75.453213980585347*QzQbar_z);
    return;
  }
  
  void D_7_4_5(const double QzQbar_z, double& Mag) {
    Mag = -12.5 + (52. - 45.5*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_7_5_5(const double QzQbar_z, double& Mag) {
    Mag = 10.75 + QzQbar_z*(-32.5 + 22.75*QzQbar_z);
    return;
  }
  
  void D_7_6_5(const double QzQbar_z, double& Mag) {
    Mag = -6.373774391990981 + (15.2970585407783545 - 8.9232841487873735*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_7_7_5(const double QzQbar_z, double& Mag) {
    Mag = 2.38484800354236412 + QzQbar_z*(-4.76969600708472825 + 2.38484800354236412*QzQbar_z);
    return;
  }
  
  void D_7_neg7_6(const double QzQbar_z, double& Mag) {
    Mag = -1.87082869338697069 - 1.87082869338697069*QzQbar_z;
    return;
  }
  
  void D_7_neg6_6(const double QzQbar_z, double& Mag) {
    Mag = 6. + 7.*QzQbar_z;
    return;
  }
  
  void D_7_neg5_6(const double QzQbar_z, double& Mag) {
    Mag = -12.7475487839819621 - 17.8465682975747469*QzQbar_z;
    return;
  }
  
  void D_7_neg4_6(const double QzQbar_z, double& Mag) {
    Mag = 20.3960780543711393 + 35.6931365951494938*QzQbar_z;
    return;
  }
  
  void D_7_neg3_6(const double QzQbar_z, double& Mag) {
    Mag = -25.3673017879316443 - 59.19037083850717*QzQbar_z;
    return;
  }
  
  void D_7_neg2_6(const double QzQbar_z, double& Mag) {
    Mag = 23.916521486202796 + 83.707825201709786*QzQbar_z;
    return;
  }
  
  void D_7_neg1_6(const double QzQbar_z, double& Mag) {
    Mag = -14.6458185158768098 - 102.520729611137669*QzQbar_z;
    return;
  }
  
  void D_7_0_6(const double QzQbar_z, double& Mag) {
    Mag = 109.599270070562058*QzQbar_z;
    return;
  }
  
  void D_7_1_6(const double QzQbar_z, double& Mag) {
    Mag = 14.6458185158768098 - 102.520729611137669*QzQbar_z;
    return;
  }
  
  void D_7_2_6(const double QzQbar_z, double& Mag) {
    Mag = -23.916521486202796 + 83.707825201709786*QzQbar_z;
    return;
  }
  
  void D_7_3_6(const double QzQbar_z, double& Mag) {
    Mag = 25.3673017879316443 - 59.19037083850717*QzQbar_z;
    return;
  }
  
  void D_7_4_6(const double QzQbar_z, double& Mag) {
    Mag = -20.3960780543711393 + 35.6931365951494938*QzQbar_z;
    return;
  }
  
  void D_7_5_6(const double QzQbar_z, double& Mag) {
    Mag = 12.7475487839819621 - 17.8465682975747469*QzQbar_z;
    return;
  }
  
  void D_7_6_6(const double QzQbar_z, double& Mag) {
    Mag = -6. + 7.*QzQbar_z;
    return;
  }
  
  void D_7_7_6(const double QzQbar_z, double& Mag) {
    Mag = 1.87082869338697069 - 1.87082869338697069*QzQbar_z;
    return;
  }
  
  void D_7_neg7_7(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_7_neg6_7(const double QzQbar_z, double& Mag) {
    Mag = -3.74165738677394139;
    return;
  }
  
  void D_7_neg5_7(const double QzQbar_z, double& Mag) {
    Mag = 9.53939201416945649;
    return;
  }
  
  void D_7_neg4_7(const double QzQbar_z, double& Mag) {
    Mag = -19.078784028338913;
    return;
  }
  
  void D_7_neg3_7(const double QzQbar_z, double& Mag) {
    Mag = 31.6385840391127491;
    return;
  }
  
  void D_7_neg2_7(const double QzQbar_z, double& Mag) {
    Mag = -44.7437146423941873;
    return;
  }
  
  void D_7_neg1_7(const double QzQbar_z, double& Mag) {
    Mag = 54.7996350352810288;
    return;
  }
  
  void D_7_0_7(const double QzQbar_z, double& Mag) {
    Mag = -58.5832740635072393;
    return;
  }
  
  void D_7_1_7(const double QzQbar_z, double& Mag) {
    Mag = 54.7996350352810288;
    return;
  }
  
  void D_7_2_7(const double QzQbar_z, double& Mag) {
    Mag = -44.7437146423941873;
    return;
  }
  
  void D_7_3_7(const double QzQbar_z, double& Mag) {
    Mag = 31.6385840391127491;
    return;
  }
  
  void D_7_4_7(const double QzQbar_z, double& Mag) {
    Mag = -19.078784028338913;
    return;
  }
  
  void D_7_5_7(const double QzQbar_z, double& Mag) {
    Mag = 9.53939201416945649;
    return;
  }
  
  void D_7_6_7(const double QzQbar_z, double& Mag) {
    Mag = -3.74165738677394139;
    return;
  }
  
  void D_7_7_7(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_8_neg8_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.0000152587890625 + QzQbar_z*(0.000244140625 + QzQbar_z*(0.0018310546875 + QzQbar_z*(0.008544921875 + QzQbar_z*(0.02777099609375 + QzQbar_z*(0.066650390625 + QzQbar_z*(0.1221923828125 + QzQbar_z*(0.174560546875 + QzQbar_z*(0.196380615234375 + QzQbar_z*(0.174560546875 + QzQbar_z*(0.1221923828125 + QzQbar_z*(0.066650390625 + QzQbar_z*(0.02777099609375 + QzQbar_z*(0.008544921875 + QzQbar_z*(0.0018310546875 + (0.000244140625 + 0.0000152587890625*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_neg7_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.00006103515625 + QzQbar_z*(0.0008544921875 + QzQbar_z*(0.0054931640625 + QzQbar_z*(0.0213623046875 + QzQbar_z*(0.0555419921875 + QzQbar_z*(0.0999755859375 + QzQbar_z*(0.1221923828125 + QzQbar_z*(0.0872802734375 + QzQbar_z*(0.e-17 + QzQbar_z*(-0.0872802734375 + QzQbar_z*(-0.1221923828125 + QzQbar_z*(-0.0999755859375 + QzQbar_z*(-0.0555419921875 + QzQbar_z*(-0.0213623046875 + QzQbar_z*(-0.0054931640625 + (-0.0008544921875 - 0.00006103515625*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_neg6_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.00016715165939488712 + QzQbar_z*(0.0020058199127386454 + QzQbar_z*(0.010697706201272776 + QzQbar_z*(0.03276172524139788 + QzQbar_z*(0.06084320401973891 + QzQbar_z*(0.06084320401973891 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.0956107491738754 + QzQbar_z*(-0.1434161237608131 + QzQbar_z*(-0.0956107491738754 + QzQbar_z*(0.e-17 + QzQbar_z*(0.06084320401973891 + QzQbar_z*(0.06084320401973891 + QzQbar_z*(0.032761725241397875 + QzQbar_z*(0.0106977062012727757 + (0.00200581991273864544 + 0.00016715165939488712*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_neg5_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.00036108885394895117 + QzQbar_z*(0.0036108885394895117 + QzQbar_z*(0.015165731865855949 + QzQbar_z*(0.03249799685540561 + QzQbar_z*(0.02816493060801819 + QzQbar_z*(-0.0281649306080182 + QzQbar_z*(-0.1032714122294 + QzQbar_z*(-0.1032714122294 + QzQbar_z*(0.e-16 + QzQbar_z*(0.1032714122294 + QzQbar_z*(0.1032714122294 + QzQbar_z*(0.02816493060801819 + QzQbar_z*(-0.02816493060801819 + QzQbar_z*(-0.032497996855405606 + QzQbar_z*(-0.015165731865855949 + (-0.0036108885394895117 - 0.000361088853948951174*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_neg4_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.0006509621889557355 + QzQbar_z*(0.005207697511645884 + QzQbar_z*(0.01562309253493765 + QzQbar_z*(0.01562309253493765 + QzQbar_z*(-0.0234346388024065 + QzQbar_z*(-0.0781154626746883 + QzQbar_z*(-0.0572846726281047 + QzQbar_z*(0.0572846726281047 + QzQbar_z*(0.1288905134132356 + QzQbar_z*(0.0572846726281047 + QzQbar_z*(-0.0572846726281047 + QzQbar_z*(-0.0781154626746883 + QzQbar_z*(-0.02343463880240648 + QzQbar_z*(0.01562309253493765 + QzQbar_z*(0.015623092534937653 + (0.0052076975116458842 + 0.000650962188955735527*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_neg3_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.0010084662867345158 + QzQbar_z*(0.006050797720407095 + QzQbar_z*(0.01008466286734516 + QzQbar_z*(-0.01008466286734516 + QzQbar_z*(-0.0504233143367258 + QzQbar_z*(-0.0342878537489735 + QzQbar_z*(0.066558774924478 + QzQbar_z*(0.110931291540797 + QzQbar_z*(0.e-15 + QzQbar_z*(-0.1109312915407967 + QzQbar_z*(-0.066558774924478 + QzQbar_z*(0.0342878537489735 + QzQbar_z*(0.05042331433672579 + QzQbar_z*(0.01008466286734516 + QzQbar_z*(-0.010084662867345157 + (-0.0060507977204070945 - 0.00100846628673451575*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_neg2_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.001365469807201971 + QzQbar_z*(0.005461879228807884 + QzQbar_z*(0.e-17 + QzQbar_z*(-0.0273093961440394 + QzQbar_z*(-0.0273093961440394 + QzQbar_z*(0.049156913059271 + QzQbar_z*(0.087390067660926 + QzQbar_z*(-0.027309396144039 + QzQbar_z*(-0.122892282648177 + QzQbar_z*(-0.027309396144039 + QzQbar_z*(0.0873900676609261 + QzQbar_z*(0.049156913059271 + QzQbar_z*(-0.0273093961440394 + QzQbar_z*(-0.02730939614403942 + QzQbar_z*(0.e-18 + (0.0054618792288078842 + 0.00136546980720197105*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_neg1_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.0016320485787501145 + QzQbar_z*(0.003264097157500229 + QzQbar_z*(-0.00979229147250069 + QzQbar_z*(-0.0228486801025016 + QzQbar_z*(0.0228486801025016 + QzQbar_z*(0.0685460403075048 + QzQbar_z*(-0.022848680102502 + QzQbar_z*(-0.114243400512508 + QzQbar_z*(0.e-15 + QzQbar_z*(0.114243400512508 + QzQbar_z*(0.0228486801025016 + QzQbar_z*(-0.0685460403075048 + QzQbar_z*(-0.0228486801025016 + QzQbar_z*(0.0228486801025016 + QzQbar_z*(0.009792291472500687 + (-0.0032640971575002289 - 0.00163204857875011446*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_0_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.0017310489258901096 + pow(QzQbar_z,2)*(-0.013848391407120877 + pow(QzQbar_z,2)*(0.048469369924923069 + pow(QzQbar_z,2)*(-0.096938739849846137 + pow(QzQbar_z,2)*(0.121173424812307671 + pow(QzQbar_z,2)*(-0.096938739849846137 + pow(QzQbar_z,2)*(0.048469369924923069 + pow(QzQbar_z,2)*(-0.0138483914071208767 + 0.00173104892589010959*pow(QzQbar_z,2))))))));
    return;
  }
  
  void D_8_1_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.0016320485787501145 + QzQbar_z*(-0.003264097157500229 + QzQbar_z*(-0.00979229147250069 + QzQbar_z*(0.0228486801025016 + QzQbar_z*(0.0228486801025016 + QzQbar_z*(-0.0685460403075048 + QzQbar_z*(-0.022848680102502 + QzQbar_z*(0.114243400512508 + QzQbar_z*(0.e-15 + QzQbar_z*(-0.114243400512508 + QzQbar_z*(0.0228486801025016 + QzQbar_z*(0.0685460403075048 + QzQbar_z*(-0.0228486801025016 + QzQbar_z*(-0.0228486801025016 + QzQbar_z*(0.009792291472500687 + (0.0032640971575002289 - 0.00163204857875011446*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_2_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.001365469807201971 + QzQbar_z*(-0.005461879228807884 + QzQbar_z*(0.e-17 + QzQbar_z*(0.0273093961440394 + QzQbar_z*(-0.0273093961440394 + QzQbar_z*(-0.049156913059271 + QzQbar_z*(0.087390067660926 + QzQbar_z*(0.027309396144039 + QzQbar_z*(-0.122892282648177 + QzQbar_z*(0.027309396144039 + QzQbar_z*(0.0873900676609261 + QzQbar_z*(-0.049156913059271 + QzQbar_z*(-0.0273093961440394 + QzQbar_z*(0.02730939614403942 + QzQbar_z*(0.e-18 + (-0.0054618792288078842 + 0.00136546980720197105*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_3_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.0010084662867345158 + QzQbar_z*(-0.006050797720407095 + QzQbar_z*(0.01008466286734516 + QzQbar_z*(0.01008466286734516 + QzQbar_z*(-0.0504233143367258 + QzQbar_z*(0.0342878537489735 + QzQbar_z*(0.066558774924478 + QzQbar_z*(-0.110931291540797 + QzQbar_z*(0.e-15 + QzQbar_z*(0.1109312915407967 + QzQbar_z*(-0.066558774924478 + QzQbar_z*(-0.0342878537489735 + QzQbar_z*(0.05042331433672579 + QzQbar_z*(-0.01008466286734516 + QzQbar_z*(-0.010084662867345157 + (0.0060507977204070945 - 0.00100846628673451575*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_4_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.0006509621889557355 + QzQbar_z*(-0.005207697511645884 + QzQbar_z*(0.01562309253493765 + QzQbar_z*(-0.01562309253493765 + QzQbar_z*(-0.0234346388024065 + QzQbar_z*(0.0781154626746883 + QzQbar_z*(-0.0572846726281047 + QzQbar_z*(-0.0572846726281047 + QzQbar_z*(0.1288905134132356 + QzQbar_z*(-0.0572846726281047 + QzQbar_z*(-0.0572846726281047 + QzQbar_z*(0.0781154626746883 + QzQbar_z*(-0.02343463880240648 + QzQbar_z*(-0.01562309253493765 + QzQbar_z*(0.015623092534937653 + (-0.0052076975116458842 + 0.000650962188955735527*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_5_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.00036108885394895117 + QzQbar_z*(-0.0036108885394895117 + QzQbar_z*(0.015165731865855949 + QzQbar_z*(-0.03249799685540561 + QzQbar_z*(0.02816493060801819 + QzQbar_z*(0.0281649306080182 + QzQbar_z*(-0.1032714122294 + QzQbar_z*(0.1032714122294 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.1032714122294 + QzQbar_z*(0.1032714122294 + QzQbar_z*(-0.02816493060801819 + QzQbar_z*(-0.02816493060801819 + QzQbar_z*(0.032497996855405606 + QzQbar_z*(-0.015165731865855949 + (0.0036108885394895117 - 0.000361088853948951174*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_6_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.00016715165939488712 + QzQbar_z*(-0.0020058199127386454 + QzQbar_z*(0.010697706201272776 + QzQbar_z*(-0.03276172524139788 + QzQbar_z*(0.06084320401973891 + QzQbar_z*(-0.06084320401973891 + QzQbar_z*(0.e-16 + QzQbar_z*(0.0956107491738754 + QzQbar_z*(-0.1434161237608131 + QzQbar_z*(0.0956107491738754 + QzQbar_z*(0.e-17 + QzQbar_z*(-0.06084320401973891 + QzQbar_z*(0.06084320401973891 + QzQbar_z*(-0.032761725241397875 + QzQbar_z*(0.0106977062012727757 + (-0.00200581991273864544 + 0.00016715165939488712*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_7_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.00006103515625 + QzQbar_z*(-0.0008544921875 + QzQbar_z*(0.0054931640625 + QzQbar_z*(-0.0213623046875 + QzQbar_z*(0.0555419921875 + QzQbar_z*(-0.0999755859375 + QzQbar_z*(0.1221923828125 + QzQbar_z*(-0.0872802734375 + QzQbar_z*(0.e-17 + QzQbar_z*(0.0872802734375 + QzQbar_z*(-0.1221923828125 + QzQbar_z*(0.0999755859375 + QzQbar_z*(-0.0555419921875 + QzQbar_z*(0.0213623046875 + QzQbar_z*(-0.0054931640625 + (0.0008544921875 - 0.00006103515625*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_8_neg8(const double QzQbar_z, double& Mag) {
    Mag = 0.0000152587890625 + QzQbar_z*(-0.000244140625 + QzQbar_z*(0.0018310546875 + QzQbar_z*(-0.008544921875 + QzQbar_z*(0.02777099609375 + QzQbar_z*(-0.066650390625 + QzQbar_z*(0.1221923828125 + QzQbar_z*(-0.174560546875 + QzQbar_z*(0.196380615234375 + QzQbar_z*(-0.174560546875 + QzQbar_z*(0.1221923828125 + QzQbar_z*(-0.066650390625 + QzQbar_z*(0.02777099609375 + QzQbar_z*(-0.008544921875 + QzQbar_z*(0.0018310546875 + (-0.000244140625 + 0.0000152587890625*QzQbar_z)*QzQbar_z))))))))))))));
    return;
  }
  
  void D_8_neg8_neg7(const double QzQbar_z, double& Mag) {
    Mag = -0.0001220703125 + QzQbar_z*(-0.0018310546875 + QzQbar_z*(-0.0128173828125 + QzQbar_z*(-0.0555419921875 + QzQbar_z*(-0.1666259765625 + QzQbar_z*(-0.3665771484375 + QzQbar_z*(-0.6109619140625 + QzQbar_z*(-0.7855224609375 + QzQbar_z*(-0.7855224609375 + QzQbar_z*(-0.6109619140625 + QzQbar_z*(-0.3665771484375 + QzQbar_z*(-0.1666259765625 + QzQbar_z*(-0.0555419921875 + QzQbar_z*(-0.0128173828125 + (-0.0018310546875 - 0.0001220703125*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_neg7_neg7(const double QzQbar_z, double& Mag) {
    Mag = -0.00042724609375 + QzQbar_z*(-0.0054931640625 + QzQbar_z*(-0.03204345703125 + QzQbar_z*(-0.111083984375 + QzQbar_z*(-0.24993896484375 + QzQbar_z*(-0.3665771484375 + QzQbar_z*(-0.30548095703125 + QzQbar_z*(0.e-16 + QzQbar_z*(0.39276123046875 + QzQbar_z*(0.6109619140625 + QzQbar_z*(0.54986572265625 + QzQbar_z*(0.333251953125 + QzQbar_z*(0.13885498046875 + QzQbar_z*(0.0384521484375 + (0.00640869140625 + 0.00048828125*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_neg6_neg7(const double QzQbar_z, double& Mag) {
    Mag = -0.0010029099563693227 + QzQbar_z*(-0.010697706201272776 + QzQbar_z*(-0.04914258786209681 + QzQbar_z*(-0.12168640803947782 + QzQbar_z*(-0.1521080100493473 + QzQbar_z*(0.e-16 + QzQbar_z*(0.334637622108564 + QzQbar_z*(0.5736644950432526 + QzQbar_z*(0.4302483712824394 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.334637622108564 + QzQbar_z*(-0.36505922411843347 + QzQbar_z*(-0.21295121406908619 + QzQbar_z*(-0.07488394340890943 + (-0.0150436493455398408 - 0.00133721327515909696*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_neg5_neg7(const double QzQbar_z, double& Mag) {
    Mag = -0.0018054442697447559 + QzQbar_z*(-0.015165731865855949 + QzQbar_z*(-0.04874699528310841 + QzQbar_z*(-0.0563298612160364 + QzQbar_z*(0.0704123265200455 + QzQbar_z*(0.3098142366882001 + QzQbar_z*(0.3614499428029 + QzQbar_z*(0.e-15 + QzQbar_z*(-0.4647213550323 + QzQbar_z*(-0.5163570611470002 + QzQbar_z*(-0.1549071183441001 + QzQbar_z*(0.1689895836481091 + QzQbar_z*(0.21123697956013644 + QzQbar_z*(0.106160123060991645 + (0.027081664046171338 + 0.0028887108315916094*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_neg4_neg7(const double QzQbar_z, double& Mag) {
    Mag = -0.0026038487558229421 + QzQbar_z*(-0.015623092534937653 + QzQbar_z*(-0.02343463880240648 + QzQbar_z*(0.046869277604813 + QzQbar_z*(0.1952886566867207 + QzQbar_z*(0.171854017884314 + QzQbar_z*(-0.200496354198367 + QzQbar_z*(-0.515562053652943 + QzQbar_z*(-0.257781026826471 + QzQbar_z*(0.286423363140524 + QzQbar_z*(0.4296350447107854 + QzQbar_z*(0.1406078328144389 + QzQbar_z*(-0.10155010147709474 + QzQbar_z*(-0.10936164774456357 + (-0.039057731337344132 - 0.0052076975116458842*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_neg3_neg7(const double QzQbar_z, double& Mag) {
    Mag = -0.0030253988602035473 + QzQbar_z*(-0.010084662867345158 + QzQbar_z*(0.01512699430101774 + QzQbar_z*(0.1008466286734516 + QzQbar_z*(0.0857196343724338 + QzQbar_z*(-0.199676324773434 + QzQbar_z*(-0.388259520392789 + QzQbar_z*(0.e-15 + QzQbar_z*(0.499190811933585 + QzQbar_z*(0.33279387462239 + QzQbar_z*(-0.188583195619354 + QzQbar_z*(-0.3025398860203547 + QzQbar_z*(-0.0655503086377435 + QzQbar_z*(0.0705926400714161 + (0.045380982903053209 + 0.008067730293876126*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_neg2_neg7(const double QzQbar_z, double& Mag) {
    Mag = -0.0027309396144039421 + QzQbar_z*(0.e-18 + QzQbar_z*(0.04096409421605913 + QzQbar_z*(0.0546187922880788 + QzQbar_z*(-0.1228922826481774 + QzQbar_z*(-0.262170202982778 + QzQbar_z*(0.095582886504138 + QzQbar_z*(0.49156913059271 + QzQbar_z*(0.122892282648177 + QzQbar_z*(-0.436950338304631 + QzQbar_z*(-0.27036302182599 + QzQbar_z*(0.1638563768642365 + QzQbar_z*(0.1775110749362562 + QzQbar_z*(0.e-17 + (-0.040964094216059131 - 0.0109237584576157684*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_neg1_neg7(const double QzQbar_z, double& Mag) {
    Mag = -0.0016320485787501145 + QzQbar_z*(0.009792291472500687 + QzQbar_z*(0.0342730201537524 + QzQbar_z*(-0.0456973602050032 + QzQbar_z*(-0.171365100768762 + QzQbar_z*(0.068546040307505 + QzQbar_z*(0.399851901793778 + QzQbar_z*(0.e-15 + QzQbar_z*(-0.514095302306286 + QzQbar_z*(-0.114243400512508 + QzQbar_z*(0.377003221691276 + QzQbar_z*(0.1370920806150096 + QzQbar_z*(-0.1485164206662604 + QzQbar_z*(-0.06854604030750481 + (0.024480728681251717 + 0.0130563886300009157*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_0_neg7(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(0.013848391407120877 + pow(QzQbar_z,2)*(-0.096938739849846137 + pow(QzQbar_z,2)*(0.29081621954953841 + pow(QzQbar_z,2)*(-0.48469369924923069 + pow(QzQbar_z,2)*(0.48469369924923069 + pow(QzQbar_z,2)*(-0.290816219549538411 + pow(QzQbar_z,2)*(0.096938739849846137 - 0.0138483914071208767*pow(QzQbar_z,2))))))));
    return;
  }
  
  void D_8_1_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0016320485787501145 + QzQbar_z*(0.009792291472500687 + QzQbar_z*(-0.0342730201537524 + QzQbar_z*(-0.0456973602050032 + QzQbar_z*(0.171365100768762 + QzQbar_z*(0.068546040307505 + QzQbar_z*(-0.399851901793778 + QzQbar_z*(0.e-15 + QzQbar_z*(0.514095302306286 + QzQbar_z*(-0.114243400512508 + QzQbar_z*(-0.377003221691276 + QzQbar_z*(0.1370920806150096 + QzQbar_z*(0.1485164206662604 + QzQbar_z*(-0.06854604030750481 + (-0.024480728681251717 + 0.0130563886300009157*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_2_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0027309396144039421 + QzQbar_z*(0.e-18 + QzQbar_z*(-0.04096409421605913 + QzQbar_z*(0.0546187922880788 + QzQbar_z*(0.1228922826481774 + QzQbar_z*(-0.262170202982778 + QzQbar_z*(-0.095582886504138 + QzQbar_z*(0.49156913059271 + QzQbar_z*(-0.122892282648177 + QzQbar_z*(-0.436950338304631 + QzQbar_z*(0.27036302182599 + QzQbar_z*(0.1638563768642365 + QzQbar_z*(-0.1775110749362562 + QzQbar_z*(0.e-17 + (0.040964094216059131 - 0.0109237584576157684*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_3_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0030253988602035473 + QzQbar_z*(-0.010084662867345158 + QzQbar_z*(-0.01512699430101774 + QzQbar_z*(0.1008466286734516 + QzQbar_z*(-0.0857196343724338 + QzQbar_z*(-0.199676324773434 + QzQbar_z*(0.388259520392789 + QzQbar_z*(0.e-15 + QzQbar_z*(-0.499190811933585 + QzQbar_z*(0.33279387462239 + QzQbar_z*(0.188583195619354 + QzQbar_z*(-0.3025398860203547 + QzQbar_z*(0.0655503086377435 + QzQbar_z*(0.0705926400714161 + (-0.045380982903053209 + 0.008067730293876126*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_4_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0026038487558229421 + QzQbar_z*(-0.015623092534937653 + QzQbar_z*(0.02343463880240648 + QzQbar_z*(0.046869277604813 + QzQbar_z*(-0.1952886566867207 + QzQbar_z*(0.171854017884314 + QzQbar_z*(0.200496354198367 + QzQbar_z*(-0.515562053652943 + QzQbar_z*(0.257781026826471 + QzQbar_z*(0.286423363140524 + QzQbar_z*(-0.4296350447107854 + QzQbar_z*(0.1406078328144389 + QzQbar_z*(0.10155010147709474 + QzQbar_z*(-0.10936164774456357 + (0.039057731337344132 - 0.0052076975116458842*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_5_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0018054442697447559 + QzQbar_z*(-0.015165731865855949 + QzQbar_z*(0.04874699528310841 + QzQbar_z*(-0.0563298612160364 + QzQbar_z*(-0.0704123265200455 + QzQbar_z*(0.3098142366882001 + QzQbar_z*(-0.3614499428029 + QzQbar_z*(0.e-15 + QzQbar_z*(0.4647213550323 + QzQbar_z*(-0.5163570611470002 + QzQbar_z*(0.1549071183441001 + QzQbar_z*(0.1689895836481091 + QzQbar_z*(-0.21123697956013644 + QzQbar_z*(0.106160123060991645 + (-0.027081664046171338 + 0.0028887108315916094*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_6_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0010029099563693227 + QzQbar_z*(-0.010697706201272776 + QzQbar_z*(0.04914258786209681 + QzQbar_z*(-0.12168640803947782 + QzQbar_z*(0.1521080100493473 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.334637622108564 + QzQbar_z*(0.5736644950432526 + QzQbar_z*(-0.4302483712824394 + QzQbar_z*(0.e-16 + QzQbar_z*(0.334637622108564 + QzQbar_z*(-0.36505922411843347 + QzQbar_z*(0.21295121406908619 + QzQbar_z*(-0.07488394340890943 + (0.0150436493455398408 - 0.00133721327515909696*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_7_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.00042724609375 + QzQbar_z*(-0.0054931640625 + QzQbar_z*(0.03204345703125 + QzQbar_z*(-0.111083984375 + QzQbar_z*(0.24993896484375 + QzQbar_z*(-0.3665771484375 + QzQbar_z*(0.30548095703125 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.39276123046875 + QzQbar_z*(0.6109619140625 + QzQbar_z*(-0.54986572265625 + QzQbar_z*(0.333251953125 + QzQbar_z*(-0.13885498046875 + QzQbar_z*(0.0384521484375 + (-0.00640869140625 + 0.00048828125*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_8_neg7(const double QzQbar_z, double& Mag) {
    Mag = 0.0001220703125 + QzQbar_z*(-0.0018310546875 + QzQbar_z*(0.0128173828125 + QzQbar_z*(-0.0555419921875 + QzQbar_z*(0.1666259765625 + QzQbar_z*(-0.3665771484375 + QzQbar_z*(0.6109619140625 + QzQbar_z*(-0.7855224609375 + QzQbar_z*(0.7855224609375 + QzQbar_z*(-0.6109619140625 + QzQbar_z*(0.3665771484375 + QzQbar_z*(-0.1666259765625 + QzQbar_z*(0.0555419921875 + QzQbar_z*(-0.0128173828125 + (0.0018310546875 - 0.0001220703125*QzQbar_z)*QzQbar_z)))))))))))));
    return;
  }
  
  void D_8_neg8_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0006686066375795485 + QzQbar_z*(0.009360492926113679 + QzQbar_z*(0.060843204019738912 + QzQbar_z*(0.24337281607895565 + QzQbar_z*(0.66927524421712803 + QzQbar_z*(1.3385504884342561 + QzQbar_z*(2.0078257326513841 + QzQbar_z*(2.2946579801730104 + QzQbar_z*(2.0078257326513841 + QzQbar_z*(1.33855048843425605 + QzQbar_z*(0.66927524421712803 + QzQbar_z*(0.243372816078955646 + QzQbar_z*(0.060843204019738912 + (0.0093604929261136787 + 0.000668606637579548478*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_neg7_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0020058199127386454 + QzQbar_z*(0.023401232315284197 + QzQbar_z*(0.12168640803947782 + QzQbar_z*(0.36505922411843347 + QzQbar_z*(0.669275244217128 + QzQbar_z*(0.669275244217128 + QzQbar_z*(0.e-16 + QzQbar_z*(-1.1473289900865052 + QzQbar_z*(-2.0078257326513841 + QzQbar_z*(-2.0078257326513841 + QzQbar_z*(-1.3385504884342561 + QzQbar_z*(-0.60843204019738912 + QzQbar_z*(-0.182529612059216735 + (-0.032761725241397875 - 0.00267442655031819391*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_neg6_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.00390625 + QzQbar_z*(0.035888671875 + QzQbar_z*(0.13330078125 + QzQbar_z*(0.22216796875 + QzQbar_z*(0.e-16 + QzQbar_z*(-0.733154296875 + QzQbar_z*(-1.46630859375 + QzQbar_z*(-1.2568359375 + QzQbar_z*(0.e-15 + QzQbar_z*(1.221923828125 + QzQbar_z*(1.46630859375 + QzQbar_z*(0.93310546875 + QzQbar_z*(0.35546875 + (0.076904296875 + 0.00732421875*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_neg5_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0055377422960028103 + QzQbar_z*(0.03559977190287521 + QzQbar_z*(0.06170627129831703 + QzQbar_z*(-0.102843785497195 + QzQbar_z*(-0.5656408202345728 + QzQbar_z*(-0.791897148328402 + QzQbar_z*(0.e-15 + QzQbar_z*(1.357537968562975 + QzQbar_z*(1.696922460703718 + QzQbar_z*(0.565640820234573 + QzQbar_z*(-0.6787689842814873 + QzQbar_z*(-0.9255940694747554 + QzQbar_z*(-0.50393454893625573 + (-0.138443557400070256 - 0.015822120845722315*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_neg4_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0057047467995839466 + QzQbar_z*(0.01711424039875184 + QzQbar_z*(-0.05134272119625552 + QzQbar_z*(-0.2852373399791973 + QzQbar_z*(-0.313761073977117 + QzQbar_z*(0.439265503567964 + QzQbar_z*(1.317796510703892 + QzQbar_z*(0.753026577545081 + QzQbar_z*(-0.941283221931351 + QzQbar_z*(-1.568805369885585 + QzQbar_z*(-0.5647699331588107 + QzQbar_z*(0.4449702503675478 + QzQbar_z*(0.51913195876213914 + (0.199666137985438131 + 0.0285237339979197329*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_neg3_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0036823982248531143 + QzQbar_z*(-0.01104719467455934 + QzQbar_z*(-0.11047194674559343 + QzQbar_z*(-0.1252015396450059 + QzQbar_z*(0.364557424260458 + QzQbar_z*(0.850633989941069 + QzQbar_z*(0.e-15 + QzQbar_z*(-1.458229697041833 + QzQbar_z*(-1.093672272781375 + QzQbar_z*(0.688608468047532 + QzQbar_z*(1.215191414201528 + QzQbar_z*(0.2872270615385429 + QzQbar_z*(-0.3350982384616334 + (-0.2319910881657462 - 0.0441887786982373713*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_neg2_neg6(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-0.029915944599869987 + QzQbar_z*(-0.05983188919973997 + QzQbar_z*(0.1794956675992199 + QzQbar_z*(0.47865511359792 + QzQbar_z*(-0.20941161219909 + QzQbar_z*(-1.256469673194539 + QzQbar_z*(-0.35899133519844 + QzQbar_z*(1.435965340793759 + QzQbar_z*(0.98722617179571 + QzQbar_z*(-0.65815078119714 + QzQbar_z*(-0.7778145595966197 + QzQbar_z*(0.e-16 + (0.20941161219908991 + 0.059831889199739974*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_neg1_neg6(const double QzQbar_z, double& Mag) {
    Mag = -0.0035756392861027368 + QzQbar_z*(-0.025029475002719157 + QzQbar_z*(0.05005895000543831 + QzQbar_z*(0.2502947500271916 + QzQbar_z*(-0.125147375013596 + QzQbar_z*(-0.876031625095171 + QzQbar_z*(0.e-15 + QzQbar_z*(1.501768500163149 + QzQbar_z*(0.375442125040787 + QzQbar_z*(-1.376621125149554 + QzQbar_z*(-0.550648450059821 + QzQbar_z*(0.6507663500706981 + QzQbar_z*(0.325383175035349 + (-0.12514737501359579 - 0.071512785722054735*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_0_neg6(const double QzQbar_z, double& Mag) {
    Mag = -0.0050567175725605418 + pow(QzQbar_z,2)*(0.106191069023771377 + pow(QzQbar_z,2)*(-0.53095534511885689 + pow(QzQbar_z,2)*(1.23889580527733274 + pow(QzQbar_z,2)*(-1.59286603535657066 + pow(QzQbar_z,2)*(1.16810175926148515 + pow(QzQbar_z,2)*(-0.4601612991030093 + 0.075850763588408127*pow(QzQbar_z,2)))))));
    return;
  }
  
  void D_8_1_neg6(const double QzQbar_z, double& Mag) {
    Mag = -0.0035756392861027368 + QzQbar_z*(0.025029475002719157 + QzQbar_z*(0.05005895000543831 + QzQbar_z*(-0.2502947500271916 + QzQbar_z*(-0.125147375013596 + QzQbar_z*(0.876031625095171 + QzQbar_z*(0.e-15 + QzQbar_z*(-1.501768500163149 + QzQbar_z*(0.375442125040787 + QzQbar_z*(1.376621125149554 + QzQbar_z*(-0.550648450059821 + QzQbar_z*(-0.6507663500706981 + QzQbar_z*(0.325383175035349 + (0.12514737501359579 - 0.071512785722054735*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_2_neg6(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(0.029915944599869987 + QzQbar_z*(-0.05983188919973997 + QzQbar_z*(-0.1794956675992199 + QzQbar_z*(0.47865511359792 + QzQbar_z*(0.20941161219909 + QzQbar_z*(-1.256469673194539 + QzQbar_z*(0.35899133519844 + QzQbar_z*(1.435965340793759 + QzQbar_z*(-0.98722617179571 + QzQbar_z*(-0.65815078119714 + QzQbar_z*(0.7778145595966197 + QzQbar_z*(0.e-16 + (-0.20941161219908991 + 0.059831889199739974*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_3_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0036823982248531143 + QzQbar_z*(0.01104719467455934 + QzQbar_z*(-0.11047194674559343 + QzQbar_z*(0.1252015396450059 + QzQbar_z*(0.364557424260458 + QzQbar_z*(-0.850633989941069 + QzQbar_z*(0.e-15 + QzQbar_z*(1.458229697041833 + QzQbar_z*(-1.093672272781375 + QzQbar_z*(-0.688608468047532 + QzQbar_z*(1.215191414201528 + QzQbar_z*(-0.2872270615385429 + QzQbar_z*(-0.3350982384616334 + (0.2319910881657462 - 0.0441887786982373713*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_4_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0057047467995839466 + QzQbar_z*(-0.01711424039875184 + QzQbar_z*(-0.05134272119625552 + QzQbar_z*(0.2852373399791973 + QzQbar_z*(-0.313761073977117 + QzQbar_z*(-0.439265503567964 + QzQbar_z*(1.317796510703892 + QzQbar_z*(-0.753026577545081 + QzQbar_z*(-0.941283221931351 + QzQbar_z*(1.568805369885585 + QzQbar_z*(-0.5647699331588107 + QzQbar_z*(-0.4449702503675478 + QzQbar_z*(0.51913195876213914 + (-0.199666137985438131 + 0.0285237339979197329*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_5_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0055377422960028103 + QzQbar_z*(-0.03559977190287521 + QzQbar_z*(0.06170627129831703 + QzQbar_z*(0.102843785497195 + QzQbar_z*(-0.5656408202345728 + QzQbar_z*(0.791897148328402 + QzQbar_z*(0.e-15 + QzQbar_z*(-1.357537968562975 + QzQbar_z*(1.696922460703718 + QzQbar_z*(-0.565640820234573 + QzQbar_z*(-0.6787689842814873 + QzQbar_z*(0.9255940694747554 + QzQbar_z*(-0.50393454893625573 + (0.138443557400070256 - 0.015822120845722315*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_6_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.00390625 + QzQbar_z*(-0.035888671875 + QzQbar_z*(0.13330078125 + QzQbar_z*(-0.22216796875 + QzQbar_z*(0.e-16 + QzQbar_z*(0.733154296875 + QzQbar_z*(-1.46630859375 + QzQbar_z*(1.2568359375 + QzQbar_z*(0.e-15 + QzQbar_z*(-1.221923828125 + QzQbar_z*(1.46630859375 + QzQbar_z*(-0.93310546875 + QzQbar_z*(0.35546875 + (-0.076904296875 + 0.00732421875*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_7_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0020058199127386454 + QzQbar_z*(-0.023401232315284197 + QzQbar_z*(0.12168640803947782 + QzQbar_z*(-0.36505922411843347 + QzQbar_z*(0.669275244217128 + QzQbar_z*(-0.669275244217128 + QzQbar_z*(0.e-16 + QzQbar_z*(1.1473289900865052 + QzQbar_z*(-2.0078257326513841 + QzQbar_z*(2.0078257326513841 + QzQbar_z*(-1.3385504884342561 + QzQbar_z*(0.60843204019738912 + QzQbar_z*(-0.182529612059216735 + (0.032761725241397875 - 0.00267442655031819391*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_8_neg6(const double QzQbar_z, double& Mag) {
    Mag = 0.0006686066375795485 + QzQbar_z*(-0.009360492926113679 + QzQbar_z*(0.060843204019738912 + QzQbar_z*(-0.24337281607895565 + QzQbar_z*(0.66927524421712803 + QzQbar_z*(-1.3385504884342561 + QzQbar_z*(2.0078257326513841 + QzQbar_z*(-2.2946579801730104 + QzQbar_z*(2.0078257326513841 + QzQbar_z*(-1.33855048843425605 + QzQbar_z*(0.66927524421712803 + QzQbar_z*(-0.243372816078955646 + QzQbar_z*(0.060843204019738912 + (-0.0093604929261136787 + 0.000668606637579548478*QzQbar_z)*QzQbar_z))))))))))));
    return;
  }
  
  void D_8_neg8_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.0028887108315916094 + QzQbar_z*(-0.037553240810690922 + QzQbar_z*(-0.22531944486414553 + QzQbar_z*(-0.82617129783520029 + QzQbar_z*(-2.0654282445880007 + QzQbar_z*(-3.7177708402584013 + QzQbar_z*(-4.9570277870112017 + QzQbar_z*(-4.9570277870112017 + QzQbar_z*(-3.7177708402584013 + QzQbar_z*(-2.0654282445880007 + QzQbar_z*(-0.82617129783520029 + QzQbar_z*(-0.225319444864145533 + (-0.0375532408106909221 - 0.0028887108315916094*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_neg7_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.007221777078979023 + QzQbar_z*(-0.07510648162138184 + QzQbar_z*(-0.3379791672962183 + QzQbar_z*(-0.8261712978352003 + QzQbar_z*(-1.0327141222940004 + QzQbar_z*(0.e-15 + QzQbar_z*(2.478513893505601 + QzQbar_z*(4.957027787011202 + QzQbar_z*(5.5766562603876019 + QzQbar_z*(4.1308564891760014 + QzQbar_z*(2.0654282445880007 + QzQbar_z*(0.6759583345924366 + (0.131436342837418228 + 0.0115548433263664376*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_neg6_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.011075484592005621 + QzQbar_z*(-0.08227502839775604 + QzQbar_z*(-0.2056875709943901 + QzQbar_z*(0.e-16 + QzQbar_z*(1.131281640469146 + QzQbar_z*(2.715075937125949 + QzQbar_z*(2.715075937125949 + QzQbar_z*(0.e-15 + QzQbar_z*(-3.393844921407437 + QzQbar_z*(-4.5251265618765821 + QzQbar_z*(-3.1675885933136075 + QzQbar_z*(-1.31640045436409661 + (-0.30853135649158514 - 0.03164424169144463*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_neg5_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.010986328125 + QzQbar_z*(-0.0380859375 + QzQbar_z*(0.09521484375 + QzQbar_z*(0.6982421875 + QzQbar_z*(1.221923828125 + QzQbar_z*(0.e-15 + QzQbar_z*(-2.9326171875 + QzQbar_z*(-4.189453125 + QzQbar_z*(-1.571044921875 + QzQbar_z*(2.0947265625 + QzQbar_z*(3.14208984375 + QzQbar_z*(1.8662109375 + (0.555419921875 + 0.068359375*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_neg4_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.0052815692511679531 + QzQbar_z*(0.03168941550700772 + QzQbar_z*(0.2640784625583977 + QzQbar_z*(0.3873150784189832 + QzQbar_z*(-0.677801387233221 + QzQbar_z*(-2.440084994039594 + QzQbar_z*(-1.62672332935973 + QzQbar_z*(2.323890470513899 + QzQbar_z*(4.357294632213561 + QzQbar_z*(1.742917852885425 + QzQbar_z*(-1.5105288058340346 + QzQbar_z*(-1.9224912074251349 + (-0.80103800309380622 - 0.123236615860585572*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_neg3_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0034092382919357767 + QzQbar_z*(0.068184765838715533 + QzQbar_z*(0.11591410192581641 + QzQbar_z*(-0.4500194545355225 + QzQbar_z*(-1.312556742395274 + QzQbar_z*(0.e-15 + QzQbar_z*(3.150136181748658 + QzQbar_z*(2.700116727213135 + QzQbar_z*(-1.912582681775971 + QzQbar_z*(-3.750162121129354 + QzQbar_z*(-0.975042151493632 + QzQbar_z*(1.2409627382646227 + (0.93072205369846703 + 0.190917344348403493*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_neg2_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.009232260938080584 + QzQbar_z*(0.036929043752322338 + QzQbar_z*(-0.16618069688545052 + QzQbar_z*(-0.5908647000371574 + QzQbar_z*(0.32312913283282 + QzQbar_z*(2.326529756396307 + QzQbar_z*(0.775509918798769 + QzQbar_z*(-3.545188200222944 + QzQbar_z*(-2.741981498609934 + QzQbar_z*(2.031097406377729 + QzQbar_z*(2.640426628291047 + QzQbar_z*(0.e-16 + (-0.84013574536533319 - 0.258503306266256365*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_neg1_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.007724263681424011 + QzQbar_z*(-0.03089705472569604 + QzQbar_z*(-0.23172791044272033 + QzQbar_z*(0.1544852736284802 + QzQbar_z*(1.351746144249202 + QzQbar_z*(0.e-15 + QzQbar_z*(-3.244190746198085 + QzQbar_z*(-0.926911641770881 + QzQbar_z*(3.823510522304885 + QzQbar_z*(1.699338009913282 + QzQbar_z*(-2.209139412887267 + QzQbar_z*(-1.2049851343021457 + (0.50207713929256072 + 0.308970547256960441*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_0_neg5(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-0.06554255074569461 + pow(QzQbar_z,2)*(0.6554255074569461 + pow(QzQbar_z,2)*(-2.2939892760993114 + pow(QzQbar_z,2)*(3.9325530447416766 + pow(QzQbar_z,2)*(-3.6048402910132036 + pow(QzQbar_z,2)*(1.70410631938805987 - 0.327712753728473052*pow(QzQbar_z,2)))))));
    return;
  }
  
  void D_8_1_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.007724263681424011 + QzQbar_z*(-0.03089705472569604 + QzQbar_z*(0.23172791044272033 + QzQbar_z*(0.1544852736284802 + QzQbar_z*(-1.351746144249202 + QzQbar_z*(0.e-15 + QzQbar_z*(3.244190746198085 + QzQbar_z*(-0.926911641770881 + QzQbar_z*(-3.823510522304885 + QzQbar_z*(1.699338009913282 + QzQbar_z*(2.209139412887267 + QzQbar_z*(-1.2049851343021457 + (-0.50207713929256072 + 0.308970547256960441*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_2_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.009232260938080584 + QzQbar_z*(0.036929043752322338 + QzQbar_z*(0.16618069688545052 + QzQbar_z*(-0.5908647000371574 + QzQbar_z*(-0.32312913283282 + QzQbar_z*(2.326529756396307 + QzQbar_z*(-0.775509918798769 + QzQbar_z*(-3.545188200222944 + QzQbar_z*(2.741981498609934 + QzQbar_z*(2.031097406377729 + QzQbar_z*(-2.640426628291047 + QzQbar_z*(0.e-16 + (0.84013574536533319 - 0.258503306266256365*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_3_neg5(const double QzQbar_z, double& Mag) {
    Mag = -0.0034092382919357767 + QzQbar_z*(0.068184765838715533 + QzQbar_z*(-0.11591410192581641 + QzQbar_z*(-0.4500194545355225 + QzQbar_z*(1.312556742395274 + QzQbar_z*(0.e-15 + QzQbar_z*(-3.150136181748658 + QzQbar_z*(2.700116727213135 + QzQbar_z*(1.912582681775971 + QzQbar_z*(-3.750162121129354 + QzQbar_z*(0.975042151493632 + QzQbar_z*(1.2409627382646227 + (-0.93072205369846703 + 0.190917344348403493*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_4_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0052815692511679531 + QzQbar_z*(0.03168941550700772 + QzQbar_z*(-0.2640784625583977 + QzQbar_z*(0.3873150784189832 + QzQbar_z*(0.677801387233221 + QzQbar_z*(-2.440084994039594 + QzQbar_z*(1.62672332935973 + QzQbar_z*(2.323890470513899 + QzQbar_z*(-4.357294632213561 + QzQbar_z*(1.742917852885425 + QzQbar_z*(1.5105288058340346 + QzQbar_z*(-1.9224912074251349 + (0.80103800309380622 - 0.123236615860585572*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_5_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.010986328125 + QzQbar_z*(-0.0380859375 + QzQbar_z*(-0.09521484375 + QzQbar_z*(0.6982421875 + QzQbar_z*(-1.221923828125 + QzQbar_z*(0.e-15 + QzQbar_z*(2.9326171875 + QzQbar_z*(-4.189453125 + QzQbar_z*(1.571044921875 + QzQbar_z*(2.0947265625 + QzQbar_z*(-3.14208984375 + QzQbar_z*(1.8662109375 + (-0.555419921875 + 0.068359375*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_6_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.011075484592005621 + QzQbar_z*(-0.08227502839775604 + QzQbar_z*(0.2056875709943901 + QzQbar_z*(0.e-16 + QzQbar_z*(-1.131281640469146 + QzQbar_z*(2.715075937125949 + QzQbar_z*(-2.715075937125949 + QzQbar_z*(0.e-15 + QzQbar_z*(3.393844921407437 + QzQbar_z*(-4.5251265618765821 + QzQbar_z*(3.1675885933136075 + QzQbar_z*(-1.31640045436409661 + (0.30853135649158514 - 0.03164424169144463*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_7_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.007221777078979023 + QzQbar_z*(-0.07510648162138184 + QzQbar_z*(0.3379791672962183 + QzQbar_z*(-0.8261712978352003 + QzQbar_z*(1.0327141222940004 + QzQbar_z*(0.e-15 + QzQbar_z*(-2.478513893505601 + QzQbar_z*(4.957027787011202 + QzQbar_z*(-5.5766562603876019 + QzQbar_z*(4.1308564891760014 + QzQbar_z*(-2.0654282445880007 + QzQbar_z*(0.6759583345924366 + (-0.131436342837418228 + 0.0115548433263664376*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_8_neg5(const double QzQbar_z, double& Mag) {
    Mag = 0.0028887108315916094 + QzQbar_z*(-0.037553240810690922 + QzQbar_z*(0.22531944486414553 + QzQbar_z*(-0.82617129783520029 + QzQbar_z*(2.0654282445880007 + QzQbar_z*(-3.7177708402584013 + QzQbar_z*(4.9570277870112017 + QzQbar_z*(-4.9570277870112017 + QzQbar_z*(3.7177708402584013 + QzQbar_z*(-2.0654282445880007 + QzQbar_z*(0.82617129783520029 + QzQbar_z*(-0.225319444864145533 + (0.0375532408106909221 - 0.0028887108315916094*QzQbar_z)*QzQbar_z)))))))))));
    return;
  }
  
  void D_8_neg8_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.010415395023291768 + QzQbar_z*(0.12498474027950122 + QzQbar_z*(0.68741607153725672 + QzQbar_z*(2.2913869051241891 + QzQbar_z*(5.1556205365294254 + QzQbar_z*(8.2489928584470806 + QzQbar_z*(9.623825001521594 + QzQbar_z*(8.2489928584470806 + QzQbar_z*(5.1556205365294254 + QzQbar_z*(2.29138690512418906 + QzQbar_z*(0.68741607153725672 + (0.124984740279501221 + 0.0104153950232917684*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_neg7_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.020830790046583537 + QzQbar_z*(0.18747711041925183 + QzQbar_z*(0.6874160715372567 + QzQbar_z*(1.1456934525620945 + QzQbar_z*(0.e-15 + QzQbar_z*(-4.12449642922354 + QzQbar_z*(-9.623825001521594 + QzQbar_z*(-12.373489287670621 + QzQbar_z*(-10.3112410730588507 + QzQbar_z*(-5.7284672628104726 + QzQbar_z*(-2.06224821461177015 + (-0.43744659097825427 - 0.0416615800931670737*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_neg6_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.022818987198335786 + QzQbar_z*(0.11409493599167893 + QzQbar_z*(0.e-16 + QzQbar_z*(-1.2550442959084682 + QzQbar_z*(-3.765132887725405 + QzQbar_z*(-4.518159465270486 + QzQbar_z*(0.e-15 + QzQbar_z*(7.530265775450809 + QzQbar_z*(11.295398663176214 + QzQbar_z*(8.7853100713592777 + QzQbar_z*(4.0161417469070984 + (1.02685442392511039 + 0.114094935991678932*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_neg5_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.010563138502335906 + QzQbar_z*(-0.05281569251167953 + QzQbar_z*(-0.5809726176284748 + QzQbar_z*(-1.3556027744664413 + QzQbar_z*(0.e-15 + QzQbar_z*(4.880169988079189 + QzQbar_z*(8.133616646798648 + QzQbar_z*(3.485835705770849 + QzQbar_z*(-5.228753558656274 + QzQbar_z*(-8.714589264427123 + QzQbar_z*(-5.6935316527590534 + (-1.84854923790878357 - 0.246473231721171143*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_neg4_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.0087890625 + QzQbar_z*(-0.146484375 + QzQbar_z*(-0.322265625 + QzQbar_z*(0.751953125 + QzQbar_z*(3.3837890625 + QzQbar_z*(2.70703125 + QzQbar_z*(-4.51171875 + QzQbar_z*(-9.66796875 + QzQbar_z*(-4.3505859375 + QzQbar_z*(4.189453125 + QzQbar_z*(5.865234375 + (2.666015625 + 0.4443359375*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_neg3_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.018911051495153403 + QzQbar_z*(-0.06429757508352157 + QzQbar_z*(0.3744388196040374 + QzQbar_z*(1.456150965126812 + QzQbar_z*(0.e-15 + QzQbar_z*(-5.242143474456523 + QzQbar_z*(-5.242143474456523 + QzQbar_z*(4.243639955512424 + QzQbar_z*(9.360970490100934 + QzQbar_z*(2.704280363806937 + QzQbar_z*(-3.7859925093297112 + (-3.0976302349061274 - 0.68836227442358386*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_neg2_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.010242273907911636 + QzQbar_z*(0.09218046517120473 + QzQbar_z*(0.4916291475797585 + QzQbar_z*(-0.3584795867769073 + QzQbar_z*(-3.226316280992165 + QzQbar_z*(-1.290526512396866 + QzQbar_z*(6.88280806611662 + QzQbar_z*(6.083910701299512 + QzQbar_z*(-5.06992558441626 + QzQbar_z*(-7.32322584415682 + QzQbar_z*(0.e-15 + (2.7961407768598767 + 0.93204692561995889*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_neg1_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.0085693011595626192 + QzQbar_z*(0.12853951739343929 + QzQbar_z*(-0.1285395173934393 + QzQbar_z*(-1.4996277029234584 + QzQbar_z*(0.e-15 + QzQbar_z*(5.39865973052445 + QzQbar_z*(1.79955324350815 + QzQbar_z*(-8.483608147966993 + QzQbar_z*(-4.241804073983497 + QzQbar_z*(6.127050329087273 + QzQbar_z*(3.676230197452364 + (-1.6710137261147107 - 1.1140091507431405*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_0_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.018178232879869419 + pow(QzQbar_z,2)*(-0.54534698639608257 + pow(QzQbar_z,2)*(3.1811907539771483 + pow(QzQbar_z,2)*(-7.6348578095451559 + pow(QzQbar_z,2)*(8.9982252755353623 + pow(QzQbar_z,2)*(-5.1989746036426538 + 1.18158513719151222*pow(QzQbar_z,2))))));
    return;
  }
  
  void D_8_1_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.0085693011595626192 + QzQbar_z*(-0.12853951739343929 + QzQbar_z*(-0.1285395173934393 + QzQbar_z*(1.4996277029234584 + QzQbar_z*(0.e-15 + QzQbar_z*(-5.39865973052445 + QzQbar_z*(1.79955324350815 + QzQbar_z*(8.483608147966993 + QzQbar_z*(-4.241804073983497 + QzQbar_z*(-6.127050329087273 + QzQbar_z*(3.676230197452364 + (1.6710137261147107 - 1.1140091507431405*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_2_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.010242273907911636 + QzQbar_z*(-0.09218046517120473 + QzQbar_z*(0.4916291475797585 + QzQbar_z*(0.3584795867769073 + QzQbar_z*(-3.226316280992165 + QzQbar_z*(1.290526512396866 + QzQbar_z*(6.88280806611662 + QzQbar_z*(-6.083910701299512 + QzQbar_z*(-5.06992558441626 + QzQbar_z*(7.32322584415682 + QzQbar_z*(0.e-15 + (-2.7961407768598767 + 0.93204692561995889*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_3_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.018911051495153403 + QzQbar_z*(0.06429757508352157 + QzQbar_z*(0.3744388196040374 + QzQbar_z*(-1.456150965126812 + QzQbar_z*(0.e-15 + QzQbar_z*(5.242143474456523 + QzQbar_z*(-5.242143474456523 + QzQbar_z*(-4.243639955512424 + QzQbar_z*(9.360970490100934 + QzQbar_z*(-2.704280363806937 + QzQbar_z*(-3.7859925093297112 + (3.0976302349061274 - 0.68836227442358386*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_4_neg4(const double QzQbar_z, double& Mag) {
    Mag = -0.0087890625 + QzQbar_z*(0.146484375 + QzQbar_z*(-0.322265625 + QzQbar_z*(-0.751953125 + QzQbar_z*(3.3837890625 + QzQbar_z*(-2.70703125 + QzQbar_z*(-4.51171875 + QzQbar_z*(9.66796875 + QzQbar_z*(-4.3505859375 + QzQbar_z*(-4.189453125 + QzQbar_z*(5.865234375 + (-2.666015625 + 0.4443359375*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_5_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.010563138502335906 + QzQbar_z*(0.05281569251167953 + QzQbar_z*(-0.5809726176284748 + QzQbar_z*(1.3556027744664413 + QzQbar_z*(0.e-15 + QzQbar_z*(-4.880169988079189 + QzQbar_z*(8.133616646798648 + QzQbar_z*(-3.485835705770849 + QzQbar_z*(-5.228753558656274 + QzQbar_z*(8.714589264427123 + QzQbar_z*(-5.6935316527590534 + (1.84854923790878357 - 0.246473231721171143*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_6_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.022818987198335786 + QzQbar_z*(-0.11409493599167893 + QzQbar_z*(0.e-16 + QzQbar_z*(1.2550442959084682 + QzQbar_z*(-3.765132887725405 + QzQbar_z*(4.518159465270486 + QzQbar_z*(0.e-15 + QzQbar_z*(-7.530265775450809 + QzQbar_z*(11.295398663176214 + QzQbar_z*(-8.7853100713592777 + QzQbar_z*(4.0161417469070984 + (-1.02685442392511039 + 0.114094935991678932*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_7_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.020830790046583537 + QzQbar_z*(-0.18747711041925183 + QzQbar_z*(0.6874160715372567 + QzQbar_z*(-1.1456934525620945 + QzQbar_z*(0.e-15 + QzQbar_z*(4.12449642922354 + QzQbar_z*(-9.623825001521594 + QzQbar_z*(12.373489287670621 + QzQbar_z*(-10.3112410730588507 + QzQbar_z*(5.7284672628104726 + QzQbar_z*(-2.06224821461177015 + (0.43744659097825427 - 0.0416615800931670737*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_8_neg4(const double QzQbar_z, double& Mag) {
    Mag = 0.010415395023291768 + QzQbar_z*(-0.12498474027950122 + QzQbar_z*(0.68741607153725672 + QzQbar_z*(-2.2913869051241891 + QzQbar_z*(5.1556205365294254 + QzQbar_z*(-8.2489928584470806 + QzQbar_z*(9.623825001521594 + QzQbar_z*(-8.2489928584470806 + QzQbar_z*(5.1556205365294254 + QzQbar_z*(-2.29138690512418906 + QzQbar_z*(0.68741607153725672 + (-0.124984740279501221 + 0.0104153950232917684*QzQbar_z)*QzQbar_z))))))))));
    return;
  }
  
  void D_8_neg8_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.032270921175504504 + QzQbar_z*(-0.35498013293054954 + QzQbar_z*(-1.7749006646527477 + QzQbar_z*(-5.3247019939582432 + QzQbar_z*(-10.6494039879164863 + QzQbar_z*(-14.909165583083081 + QzQbar_z*(-14.9091655830830809 + QzQbar_z*(-10.6494039879164863 + QzQbar_z*(-5.3247019939582432 + QzQbar_z*(-1.77490066465274772 + (-0.354980132930549544 - 0.032270921175504504*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_8_neg7_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.048406381763256756 + QzQbar_z*(-0.35498013293054954 + QzQbar_z*(-0.8874503323263739 + QzQbar_z*(0.e-15 + QzQbar_z*(5.324701993958243 + QzQbar_z*(14.909165583083081 + QzQbar_z*(22.363748374624621 + QzQbar_z*(21.298807975832973 + QzQbar_z*(13.3117549848956079 + QzQbar_z*(5.3247019939582432 + (1.24243046525692341 + 0.129083684702018016*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_8_neg6_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.029459185798824914 + QzQbar_z*(0.e-17 + QzQbar_z*(0.9721531313612222 + QzQbar_z*(3.888612525444889 + QzQbar_z*(5.832918788167333 + QzQbar_z*(0.e-15 + QzQbar_z*(-13.61014383905711 + QzQbar_z*(-23.331675152669332 + QzQbar_z*(-20.415215758585666 + QzQbar_z*(-10.3696334011863698 + (-2.9164593940836665 - 0.353510229585898971*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_8_neg5_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.013636953167743107 + QzQbar_z*(0.30001296969034835 + QzQbar_z*(1.0500453939162192 + QzQbar_z*(0.e-15 + QzQbar_z*(-6.300272363497315 + QzQbar_z*(-12.600544726994631 + QzQbar_z*(-6.300272363497315 + QzQbar_z*(10.80046690885254 + QzQbar_z*(20.250875454098513 + QzQbar_z*(14.700635514827069 + (5.250226969581096 + 0.76366937739361397*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_8_neg4_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.037822102990306806 + QzQbar_z*(0.16641725315734994 + QzQbar_z*(-0.5824603860507248 + QzQbar_z*(-3.4947623163043488 + QzQbar_z*(-3.494762316304349 + QzQbar_z*(6.989524632608698 + QzQbar_z*(17.473811581521744 + QzQbar_z*(8.986531670496897 + QzQbar_z*(-9.735409309704972 + QzQbar_z*(-15.143970037318845 + (-7.5719850186594225 - 1.37672454884716772*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_8_neg3_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.0166015625 + QzQbar_z*(-0.193359375 + QzQbar_z*(-1.1279296875 + QzQbar_z*(0.e-16 + QzQbar_z*(6.767578125 + QzQbar_z*(8.12109375 + QzQbar_z*(-7.669921875 + QzQbar_z*(-19.3359375 + QzQbar_z*(-6.2841796875 + QzQbar_z*(9.775390625 + QzQbar_z*(8.7978515625 + 2.1328125*QzQbar_z))))))))));
    return;
  }
  
  void D_8_neg2_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.023800893763581915 + QzQbar_z*(-0.25387620014487376 + QzQbar_z*(0.2776770939084557 + QzQbar_z*(3.3321251269014681 + QzQbar_z*(1.666062563450734 + QzQbar_z*(-10.662800406084698 + QzQbar_z*(-10.996012918774845 + QzQbar_z*(10.472393255976043 + QzQbar_z*(17.017639040961069 + QzQbar_z*(0.e-15 + (-7.9415648857818323 - 2.88784177664793903*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_8_neg1_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.033188760679621931 + QzQbar_z*(0.06637752135924386 + QzQbar_z*(1.1616066237867676 + QzQbar_z*(0.e-16 + QzQbar_z*(-6.969639742720605 + QzQbar_z*(-2.787855897088242 + QzQbar_z*(15.333207433985332 + QzQbar_z*(8.76183281942019 + QzQbar_z*(-14.237978331557808 + QzQbar_z*(-9.491985554371872 + QzQbar_z*(4.7459927771859361 + 3.45163111068068078*QzQbar_z))))))))));
    return;
  }
  
  void D_8_0_neg3(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(0.2816159728288574 + pow(QzQbar_z,2)*(-3.2855196830033363 + pow(QzQbar_z,2)*(11.8278708588120108 + pow(QzQbar_z,2)*(-18.5866542067045885 + pow(QzQbar_z,2)*(13.4236947048422028 - 3.66100764677514621*pow(QzQbar_z,2))))));
    return;
  }
  
  void D_8_1_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.033188760679621931 + QzQbar_z*(0.06637752135924386 + QzQbar_z*(-1.1616066237867676 + QzQbar_z*(0.e-16 + QzQbar_z*(6.969639742720605 + QzQbar_z*(-2.787855897088242 + QzQbar_z*(-15.333207433985332 + QzQbar_z*(8.76183281942019 + QzQbar_z*(14.237978331557808 + QzQbar_z*(-9.491985554371872 + QzQbar_z*(-4.7459927771859361 + 3.45163111068068078*QzQbar_z))))))))));
    return;
  }
  
  void D_8_2_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.023800893763581915 + QzQbar_z*(-0.25387620014487376 + QzQbar_z*(-0.2776770939084557 + QzQbar_z*(3.3321251269014681 + QzQbar_z*(-1.666062563450734 + QzQbar_z*(-10.662800406084698 + QzQbar_z*(10.996012918774845 + QzQbar_z*(10.472393255976043 + QzQbar_z*(-17.017639040961069 + QzQbar_z*(0.e-15 + (7.9415648857818323 - 2.88784177664793903*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_8_3_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.0166015625 + QzQbar_z*(-0.193359375 + QzQbar_z*(1.1279296875 + QzQbar_z*(0.e-16 + QzQbar_z*(-6.767578125 + QzQbar_z*(8.12109375 + QzQbar_z*(7.669921875 + QzQbar_z*(-19.3359375 + QzQbar_z*(6.2841796875 + QzQbar_z*(9.775390625 + QzQbar_z*(-8.7978515625 + 2.1328125*QzQbar_z))))))))));
    return;
  }
  
  void D_8_4_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.037822102990306806 + QzQbar_z*(0.16641725315734994 + QzQbar_z*(0.5824603860507248 + QzQbar_z*(-3.4947623163043488 + QzQbar_z*(3.494762316304349 + QzQbar_z*(6.989524632608698 + QzQbar_z*(-17.473811581521744 + QzQbar_z*(8.986531670496897 + QzQbar_z*(9.735409309704972 + QzQbar_z*(-15.143970037318845 + (7.5719850186594225 - 1.37672454884716772*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_8_5_neg3(const double QzQbar_z, double& Mag) {
    Mag = -0.013636953167743107 + QzQbar_z*(0.30001296969034835 + QzQbar_z*(-1.0500453939162192 + QzQbar_z*(0.e-15 + QzQbar_z*(6.300272363497315 + QzQbar_z*(-12.600544726994631 + QzQbar_z*(6.300272363497315 + QzQbar_z*(10.80046690885254 + QzQbar_z*(-20.250875454098513 + QzQbar_z*(14.700635514827069 + (-5.250226969581096 + 0.76366937739361397*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_8_6_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.029459185798824914 + QzQbar_z*(0.e-17 + QzQbar_z*(-0.9721531313612222 + QzQbar_z*(3.888612525444889 + QzQbar_z*(-5.832918788167333 + QzQbar_z*(0.e-15 + QzQbar_z*(13.61014383905711 + QzQbar_z*(-23.331675152669332 + QzQbar_z*(20.415215758585666 + QzQbar_z*(-10.3696334011863698 + (2.9164593940836665 - 0.353510229585898971*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_8_7_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.048406381763256756 + QzQbar_z*(-0.35498013293054954 + QzQbar_z*(0.8874503323263739 + QzQbar_z*(0.e-15 + QzQbar_z*(-5.324701993958243 + QzQbar_z*(14.909165583083081 + QzQbar_z*(-22.363748374624621 + QzQbar_z*(21.298807975832973 + QzQbar_z*(-13.3117549848956079 + QzQbar_z*(5.3247019939582432 + (-1.24243046525692341 + 0.129083684702018016*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_8_8_neg3(const double QzQbar_z, double& Mag) {
    Mag = 0.032270921175504504 + QzQbar_z*(-0.35498013293054954 + QzQbar_z*(1.7749006646527477 + QzQbar_z*(-5.3247019939582432 + QzQbar_z*(10.6494039879164863 + QzQbar_z*(-14.909165583083081 + QzQbar_z*(14.9091655830830809 + QzQbar_z*(-10.6494039879164863 + QzQbar_z*(5.3247019939582432 + QzQbar_z*(-1.77490066465274772 + (0.354980132930549544 - 0.032270921175504504*QzQbar_z)*QzQbar_z)))))))));
    return;
  }
  
  void D_8_neg8_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.087390067660926147 + QzQbar_z*(0.87390067660926147 + QzQbar_z*(3.9325530447416766 + QzQbar_z*(10.4868081193111377 + QzQbar_z*(18.351914208794491 + QzQbar_z*(22.022297050553389 + QzQbar_z*(18.3519142087944909 + QzQbar_z*(10.4868081193111377 + QzQbar_z*(3.9325530447416766 + (0.87390067660926147 + 0.0873900676609261472*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_8_neg7_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.087390067660926147 + QzQbar_z*(0.4369503383046307 + QzQbar_z*(0.e-16 + QzQbar_z*(-5.243404059655569 + QzQbar_z*(-18.351914208794491 + QzQbar_z*(-33.033445575830084 + QzQbar_z*(-36.703828417588982 + QzQbar_z*(-26.217020298277844 + QzQbar_z*(-11.7976591342250299 + (-3.05865236813241515 - 0.349560270643704589*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_8_neg6_neg2(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-0.47865511359791979 + QzQbar_z*(-2.8719306815875187 + QzQbar_z*(-5.743861363175037 + QzQbar_z*(0.e-15 + QzQbar_z*(20.103514771112631 + QzQbar_z*(40.207029542225262 + QzQbar_z*(40.207029542225262 + QzQbar_z*(22.97544545270015 + (7.1798267039687969 + 0.95731022719583958*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_8_neg5_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.073858087504644676 + QzQbar_z*(-0.51700661253251273 + QzQbar_z*(0.e-16 + QzQbar_z*(6.204079350390153 + QzQbar_z*(15.510198375975382 + QzQbar_z*(9.306119025585229 + QzQbar_z*(-18.612238051170458 + QzQbar_z*(-39.883367252508125 + QzQbar_z*(-32.571416589548302 + (-12.9251653133128183 - 2.06802645013005092*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_8_neg4_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.040969095631646545 + QzQbar_z*(0.28678366942152581 + QzQbar_z*(2.5810530247937323 + QzQbar_z*(3.4414040330583098 + QzQbar_z*(-8.603510082645774 + QzQbar_z*(-25.810530247937323 + QzQbar_z*(-15.486318148762394 + QzQbar_z*(19.173536755610583 + QzQbar_z*(33.55368932231852 + QzQbar_z*(18.6409385123991779 + 3.72818770247983558*QzQbar_z)))))))));
    return;
  }
  
  void D_8_neg3_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.04760178752716383 + QzQbar_z*(0.55535418781691135 + QzQbar_z*(0.e-16 + QzQbar_z*(-6.6642502538029362 + QzQbar_z*(-9.996375380704404 + QzQbar_z*(11.329225431464992 + QzQbar_z*(33.321251269014681 + QzQbar_z*(12.376464757062596 + QzQbar_z*(-21.658813324859543 + (-21.658813324859543 - 5.7756835532958781*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_8_neg2_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.0625 + QzQbar_z*(-0.13671875 + QzQbar_z*(-2.4609375 + QzQbar_z*(-1.640625 + QzQbar_z*(13.125 + QzQbar_z*(16.2421875 + QzQbar_z*(-18.046875 + QzQbar_z*(-33.515625 + QzQbar_z*(0.e-15 + QzQbar_z*(19.55078125 + 7.8203125*QzQbar_z)))))))));
    return;
  }
  
  void D_8_neg1_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.016341016143243663 + QzQbar_z*(-0.57193556501352821 + QzQbar_z*(0.e-16 + QzQbar_z*(6.8632267801623385 + QzQbar_z*(3.431613390081169 + QzQbar_z*(-22.648648374535717 + QzQbar_z*(-15.099098916357145 + QzQbar_z*(28.041183701806126 + QzQbar_z*(21.030887776354594 + (-11.683826542419219 - 9.3470612339353753*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_8_0_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.069329059958198625 + pow(QzQbar_z,2)*(2.42651709853695189 + pow(QzQbar_z,2)*(-14.5591025912217114 + pow(QzQbar_z,2)*(32.030025700687765 + pow(QzQbar_z,2)*(-29.7421667220672103 + 9.9140555740224034*pow(QzQbar_z,2)))));
    return;
  }
  
  void D_8_1_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.016341016143243663 + QzQbar_z*(0.57193556501352821 + QzQbar_z*(0.e-16 + QzQbar_z*(-6.8632267801623385 + QzQbar_z*(3.431613390081169 + QzQbar_z*(22.648648374535717 + QzQbar_z*(-15.099098916357145 + QzQbar_z*(-28.041183701806126 + QzQbar_z*(21.030887776354594 + (11.683826542419219 - 9.3470612339353753*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_8_2_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.0625 + QzQbar_z*(0.13671875 + QzQbar_z*(-2.4609375 + QzQbar_z*(1.640625 + QzQbar_z*(13.125 + QzQbar_z*(-16.2421875 + QzQbar_z*(-18.046875 + QzQbar_z*(33.515625 + QzQbar_z*(0.e-15 + QzQbar_z*(-19.55078125 + 7.8203125*QzQbar_z)))))))));
    return;
  }
  
  void D_8_3_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.04760178752716383 + QzQbar_z*(-0.55535418781691135 + QzQbar_z*(0.e-16 + QzQbar_z*(6.6642502538029362 + QzQbar_z*(-9.996375380704404 + QzQbar_z*(-11.329225431464992 + QzQbar_z*(33.321251269014681 + QzQbar_z*(-12.376464757062596 + QzQbar_z*(-21.658813324859543 + (21.658813324859543 - 5.7756835532958781*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_8_4_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.040969095631646545 + QzQbar_z*(-0.28678366942152581 + QzQbar_z*(2.5810530247937323 + QzQbar_z*(-3.4414040330583098 + QzQbar_z*(-8.603510082645774 + QzQbar_z*(25.810530247937323 + QzQbar_z*(-15.486318148762394 + QzQbar_z*(-19.173536755610583 + QzQbar_z*(33.55368932231852 + QzQbar_z*(-18.6409385123991779 + 3.72818770247983558*QzQbar_z)))))))));
    return;
  }
  
  void D_8_5_neg2(const double QzQbar_z, double& Mag) {
    Mag = -0.073858087504644676 + QzQbar_z*(0.51700661253251273 + QzQbar_z*(0.e-16 + QzQbar_z*(-6.204079350390153 + QzQbar_z*(15.510198375975382 + QzQbar_z*(-9.306119025585229 + QzQbar_z*(-18.612238051170458 + QzQbar_z*(39.883367252508125 + QzQbar_z*(-32.571416589548302 + (12.9251653133128183 - 2.06802645013005092*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_8_6_neg2(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(0.47865511359791979 + QzQbar_z*(-2.8719306815875187 + QzQbar_z*(5.743861363175037 + QzQbar_z*(0.e-15 + QzQbar_z*(-20.103514771112631 + QzQbar_z*(40.207029542225262 + QzQbar_z*(-40.207029542225262 + QzQbar_z*(22.97544545270015 + (-7.1798267039687969 + 0.95731022719583958*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_8_7_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.087390067660926147 + QzQbar_z*(-0.4369503383046307 + QzQbar_z*(0.e-16 + QzQbar_z*(5.243404059655569 + QzQbar_z*(-18.351914208794491 + QzQbar_z*(33.033445575830084 + QzQbar_z*(-36.703828417588982 + QzQbar_z*(26.217020298277844 + QzQbar_z*(-11.7976591342250299 + (3.05865236813241515 - 0.349560270643704589*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_8_8_neg2(const double QzQbar_z, double& Mag) {
    Mag = 0.087390067660926147 + QzQbar_z*(-0.87390067660926147 + QzQbar_z*(3.9325530447416766 + QzQbar_z*(-10.4868081193111377 + QzQbar_z*(18.351914208794491 + QzQbar_z*(-22.022297050553389 + QzQbar_z*(18.3519142087944909 + QzQbar_z*(-10.4868081193111377 + QzQbar_z*(3.9325530447416766 + (-0.87390067660926147 + 0.0873900676609261472*QzQbar_z)*QzQbar_z))))))));
    return;
  }
  
  void D_8_neg8_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.20890221808001465 + QzQbar_z*(-1.8801199627201319 + QzQbar_z*(-7.5204798508805274 + QzQbar_z*(-17.547786318721231 + QzQbar_z*(-26.321679478081846 + QzQbar_z*(-26.321679478081846 + QzQbar_z*(-17.5477863187212307 + QzQbar_z*(-7.5204798508805274 + (-1.88011996272013186 - 0.208902218080014651*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_8_neg7_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.10445110904000733 + QzQbar_z*(0.e-16 + QzQbar_z*(3.7602399254402637 + QzQbar_z*(17.547786318721231 + QzQbar_z*(39.482519217122769 + QzQbar_z*(52.643358956163692 + QzQbar_z*(43.869465796803077 + QzQbar_z*(22.5614395526415823 + (6.5804198695204615 + 0.8356088723200586*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_8_neg6_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.11442045715528758 + QzQbar_z*(1.3730454858634509 + QzQbar_z*(4.1191364575903528 + QzQbar_z*(0.e-15 + QzQbar_z*(-24.028296002610391 + QzQbar_z*(-57.667910406264939 + QzQbar_z*(-67.279228807309095 + QzQbar_z*(-43.937455547630429 + (-15.4467617159638228 - 2.28840914310575153*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_8_neg5_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.123588218902784176 + QzQbar_z*(0.e-16 + QzQbar_z*(-4.4491758805002303 + QzQbar_z*(-14.830586268334101 + QzQbar_z*(-11.122939701250576 + QzQbar_z*(26.695055283001382 + QzQbar_z*(66.737638207503455 + QzQbar_z*(62.288462327003225 + QzQbar_z*(27.8073492531264397 + 4.94352875611136705*QzQbar_z))))))));
    return;
  }
  
  void D_8_neg4_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.068554409276500954 + QzQbar_z*(-1.23397936697701716 + QzQbar_z*(-2.4679587339540343 + QzQbar_z*(8.226529113180114 + QzQbar_z*(30.849484174425429 + QzQbar_z*(22.211628605586309 + QzQbar_z*(-32.083463541402446 + QzQbar_z*(-64.166927082804893 + (-40.104329426753058 - 8.912073205945124*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_8_neg3_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.132755042718487722 + QzQbar_z*(0.e-17 + QzQbar_z*(4.779181537865558 + QzQbar_z*(9.558363075731116 + QzQbar_z*(-13.541014357285748 + QzQbar_z*(-47.79181537865558 + QzQbar_z*(-20.709786664084085 + QzQbar_z*(41.419573328168169 + QzQbar_z*(46.597019994189191 + 13.8065244427227231*QzQbar_z))))))));
    return;
  }
  
  void D_8_neg2_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.032682032286487326 + QzQbar_z*(1.17655316231354374 + QzQbar_z*(1.1765531623135437 + QzQbar_z*(-12.5499003980111332 + QzQbar_z*(-19.413127178173472 + QzQbar_z*(25.884169570897962 + QzQbar_z*(56.082367403612252 + QzQbar_z*(0.e-15 + (-42.061775552709189 - 18.6941224678707505*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_8_neg1_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.13671875 + QzQbar_z*(0.e-17 + QzQbar_z*(-4.921875 + QzQbar_z*(-3.28125 + QzQbar_z*(27.0703125 + QzQbar_z*(21.65625 + QzQbar_z*(-46.921875 + QzQbar_z*(-40.21875 + QzQbar_z*(25.13671875 + 22.34375*QzQbar_z))))))));
    return;
  }
  
  void D_8_0_neg1(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-1.16009706288417953 + pow(QzQbar_z,2)*(13.9211647546101544 + pow(QzQbar_z,2)*(-45.9398436902135095 + pow(QzQbar_z,2)*(56.877901711692916 - 23.6991257132053819*pow(QzQbar_z,2)))));
    return;
  }
  
  void D_8_1_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.13671875 + QzQbar_z*(0.e-17 + QzQbar_z*(4.921875 + QzQbar_z*(-3.28125 + QzQbar_z*(-27.0703125 + QzQbar_z*(21.65625 + QzQbar_z*(46.921875 + QzQbar_z*(-40.21875 + QzQbar_z*(-25.13671875 + 22.34375*QzQbar_z))))))));
    return;
  }
  
  void D_8_2_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.032682032286487326 + QzQbar_z*(1.17655316231354374 + QzQbar_z*(-1.1765531623135437 + QzQbar_z*(-12.5499003980111332 + QzQbar_z*(19.413127178173472 + QzQbar_z*(25.884169570897962 + QzQbar_z*(-56.082367403612252 + QzQbar_z*(0.e-15 + (42.061775552709189 - 18.6941224678707505*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_8_3_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.132755042718487722 + QzQbar_z*(0.e-17 + QzQbar_z*(-4.779181537865558 + QzQbar_z*(9.558363075731116 + QzQbar_z*(13.541014357285748 + QzQbar_z*(-47.79181537865558 + QzQbar_z*(20.709786664084085 + QzQbar_z*(41.419573328168169 + QzQbar_z*(-46.597019994189191 + 13.8065244427227231*QzQbar_z))))))));
    return;
  }
  
  void D_8_4_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.068554409276500954 + QzQbar_z*(-1.23397936697701716 + QzQbar_z*(2.4679587339540343 + QzQbar_z*(8.226529113180114 + QzQbar_z*(-30.849484174425429 + QzQbar_z*(22.211628605586309 + QzQbar_z*(32.083463541402446 + QzQbar_z*(-64.166927082804893 + (40.104329426753058 - 8.912073205945124*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_8_5_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.123588218902784176 + QzQbar_z*(0.e-16 + QzQbar_z*(4.4491758805002303 + QzQbar_z*(-14.830586268334101 + QzQbar_z*(11.122939701250576 + QzQbar_z*(26.695055283001382 + QzQbar_z*(-66.737638207503455 + QzQbar_z*(62.288462327003225 + QzQbar_z*(-27.8073492531264397 + 4.94352875611136705*QzQbar_z))))))));
    return;
  }
  
  void D_8_6_neg1(const double QzQbar_z, double& Mag) {
    Mag = -0.11442045715528758 + QzQbar_z*(1.3730454858634509 + QzQbar_z*(-4.1191364575903528 + QzQbar_z*(0.e-15 + QzQbar_z*(24.028296002610391 + QzQbar_z*(-57.667910406264939 + QzQbar_z*(67.279228807309095 + QzQbar_z*(-43.937455547630429 + (15.4467617159638228 - 2.28840914310575153*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_8_7_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.10445110904000733 + QzQbar_z*(0.e-16 + QzQbar_z*(-3.7602399254402637 + QzQbar_z*(17.547786318721231 + QzQbar_z*(-39.482519217122769 + QzQbar_z*(52.643358956163692 + QzQbar_z*(-43.869465796803077 + QzQbar_z*(22.5614395526415823 + (-6.5804198695204615 + 0.8356088723200586*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_8_8_neg1(const double QzQbar_z, double& Mag) {
    Mag = 0.20890221808001465 + QzQbar_z*(-1.8801199627201319 + QzQbar_z*(7.5204798508805274 + QzQbar_z*(-17.547786318721231 + QzQbar_z*(26.321679478081846 + QzQbar_z*(-26.321679478081846 + QzQbar_z*(17.5477863187212307 + QzQbar_z*(-7.5204798508805274 + (1.88011996272013186 - 0.208902218080014651*QzQbar_z)*QzQbar_z)))))));
    return;
  }
  
  void D_8_neg8_0(const double QzQbar_z, double& Mag) {
    Mag = 0.44314852502786806 + QzQbar_z*(3.5451882002229444 + QzQbar_z*(12.4081587007803055 + QzQbar_z*(24.816317401560611 + QzQbar_z*(31.020396751950764 + QzQbar_z*(24.8163174015606111 + QzQbar_z*(12.4081587007803055 + (3.54518820022294444 + 0.443148525027868055*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_8_neg7_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-1.7725941001114722 + QzQbar_z*(-12.4081587007803055 + QzQbar_z*(-37.224476102340917 + QzQbar_z*(-62.040793503901528 + QzQbar_z*(-62.040793503901528 + QzQbar_z*(-37.224476102340917 + (-12.4081587007803055 - 1.77259410011147222*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_8_neg6_0(const double QzQbar_z, double& Mag) {
    Mag = -0.32362992464387467 + QzQbar_z*(-1.941779547863248 + QzQbar_z*(0.e-16 + QzQbar_z*(22.654094725071227 + QzQbar_z*(67.962284175213682 + QzQbar_z*(95.147197845299154 + QzQbar_z*(72.493103120227927 + QzQbar_z*(29.1266932179487207 + 4.85444886965812011*QzQbar_z)))))));
    return;
  }
  
  void D_8_neg5_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(2.0973616238622275 + QzQbar_z*(10.4868081193111377 + QzQbar_z*(10.486808119311138 + QzQbar_z*(-31.460424357933413 + QzQbar_z*(-94.381273073800239 + QzQbar_z*(-102.770719569249149 + (-52.434040596555688 - 10.4868081193111377*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_8_neg4_0(const double QzQbar_z, double& Mag) {
    Mag = 0.2908517260779107 + QzQbar_z*(1.16340690431164281 + QzQbar_z*(-5.817034521558214 + QzQbar_z*(-29.08517260779107 + QzQbar_z*(-26.176655347011963 + QzQbar_z*(45.372869268154069 + QzQbar_z*(105.870028292359495 + QzQbar_z*(75.621448780256782 + 18.9053621950641956*QzQbar_z)))))));
    return;
  }
  
  void D_8_neg3_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-2.2529277826308592 + QzQbar_z*(-6.7587833478925776 + QzQbar_z*(12.766590768241536 + QzQbar_z*(56.32319456577148 + QzQbar_z*(29.28806117420117 + QzQbar_z*(-68.338809406469396 + (-87.864183522603509 - 29.2880611742011697*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_8_neg2_0(const double QzQbar_z, double& Mag) {
    Mag = -0.2773162398327945 + QzQbar_z*(-0.554632479665589 + QzQbar_z*(8.8741196746494241 + QzQbar_z*(18.3028718289644371 + QzQbar_z*(-30.504786381607395 + QzQbar_z*(-79.312444592179228 + QzQbar_z*(0.e-15 + QzQbar_z*(79.312444592179228 + 39.6562222960896138*QzQbar_z)))))));
    return;
  }
  
  void D_8_neg1_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(2.32019412576835906 + QzQbar_z*(2.32019412576835906 + QzQbar_z*(-25.5221353834519497 + QzQbar_z*(-25.5221353834519497 + QzQbar_z*(66.357551996975069 + QzQbar_z*(66.357551996975069 + (-47.3982514264107637 - 47.3982514264107637*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_8_0_0(const double QzQbar_z, double& Mag) {
    Mag = 0.2734375 + pow(QzQbar_z,2)*(-9.84375 + pow(QzQbar_z,2)*(54.140625 + pow(QzQbar_z,2)*(-93.84375 + 50.2734375*pow(QzQbar_z,2))));
    return;
  }
  
  void D_8_1_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-2.32019412576835906 + QzQbar_z*(2.32019412576835906 + QzQbar_z*(25.5221353834519497 + QzQbar_z*(-25.5221353834519497 + QzQbar_z*(-66.357551996975069 + QzQbar_z*(66.357551996975069 + (47.3982514264107637 - 47.3982514264107637*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_8_2_0(const double QzQbar_z, double& Mag) {
    Mag = -0.2773162398327945 + QzQbar_z*(0.554632479665589 + QzQbar_z*(8.8741196746494241 + QzQbar_z*(-18.3028718289644371 + QzQbar_z*(-30.504786381607395 + QzQbar_z*(79.312444592179228 + QzQbar_z*(0.e-15 + QzQbar_z*(-79.312444592179228 + 39.6562222960896138*QzQbar_z)))))));
    return;
  }
  
  void D_8_3_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(2.2529277826308592 + QzQbar_z*(-6.7587833478925776 + QzQbar_z*(-12.766590768241536 + QzQbar_z*(56.32319456577148 + QzQbar_z*(-29.28806117420117 + QzQbar_z*(-68.338809406469396 + (87.864183522603509 - 29.2880611742011697*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_8_4_0(const double QzQbar_z, double& Mag) {
    Mag = 0.2908517260779107 + QzQbar_z*(-1.16340690431164281 + QzQbar_z*(-5.817034521558214 + QzQbar_z*(29.08517260779107 + QzQbar_z*(-26.176655347011963 + QzQbar_z*(-45.372869268154069 + QzQbar_z*(105.870028292359495 + QzQbar_z*(-75.621448780256782 + 18.9053621950641956*QzQbar_z)))))));
    return;
  }
  
  void D_8_5_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-2.0973616238622275 + QzQbar_z*(10.4868081193111377 + QzQbar_z*(-10.486808119311138 + QzQbar_z*(-31.460424357933413 + QzQbar_z*(94.381273073800239 + QzQbar_z*(-102.770719569249149 + (52.434040596555688 - 10.4868081193111377*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_8_6_0(const double QzQbar_z, double& Mag) {
    Mag = -0.32362992464387467 + QzQbar_z*(1.941779547863248 + QzQbar_z*(0.e-16 + QzQbar_z*(-22.654094725071227 + QzQbar_z*(67.962284175213682 + QzQbar_z*(-95.147197845299154 + QzQbar_z*(72.493103120227927 + QzQbar_z*(-29.1266932179487207 + 4.85444886965812011*QzQbar_z)))))));
    return;
  }
  
  void D_8_7_0(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(1.7725941001114722 + QzQbar_z*(-12.4081587007803055 + QzQbar_z*(37.224476102340917 + QzQbar_z*(-62.040793503901528 + QzQbar_z*(62.040793503901528 + QzQbar_z*(-37.224476102340917 + (12.4081587007803055 - 1.77259410011147222*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_8_8_0(const double QzQbar_z, double& Mag) {
    Mag = 0.44314852502786806 + QzQbar_z*(-3.5451882002229444 + QzQbar_z*(12.4081587007803055 + QzQbar_z*(-24.816317401560611 + QzQbar_z*(31.020396751950764 + QzQbar_z*(-24.8163174015606111 + QzQbar_z*(12.4081587007803055 + (-3.54518820022294444 + 0.443148525027868055*QzQbar_z)*QzQbar_z))))));
    return;
  }
  
  void D_8_neg8_1(const double QzQbar_z, double& Mag) {
    Mag = -0.8356088723200586 + QzQbar_z*(-5.8492621062404102 + QzQbar_z*(-17.547786318721231 + QzQbar_z*(-29.246310531202051 + QzQbar_z*(-29.246310531202051 + QzQbar_z*(-17.5477863187212307 + (-5.8492621062404102 - 0.835608872320058603*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_8_neg7_1(const double QzQbar_z, double& Mag) {
    Mag = 0.4178044361600293 + QzQbar_z*(5.8492621062404102 + QzQbar_z*(26.321679478081846 + QzQbar_z*(58.492621062404102 + QzQbar_z*(73.115776328005128 + QzQbar_z*(52.643358956163692 + QzQbar_z*(20.4724173718414358 + 3.34243548928023441*QzQbar_z))))));
    return;
  }
  
  void D_8_neg6_1(const double QzQbar_z, double& Mag) {
    Mag = 0.45768182862115031 + QzQbar_z*(0.e-16 + QzQbar_z*(-16.018864001740261 + QzQbar_z*(-64.075456006961043 + QzQbar_z*(-112.132048012181825 + QzQbar_z*(-102.520729611137669 + (-48.056592005220782 - 9.1536365724230061*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_8_neg5_1(const double QzQbar_z, double& Mag) {
    Mag = -0.49435287561113671 + QzQbar_z*(-4.9435287561113671 + QzQbar_z*(-7.415293134167051 + QzQbar_z*(29.661172536668202 + QzQbar_z*(111.229397012505759 + QzQbar_z*(145.339745429674191 + QzQbar_z*(86.511753231948923 + 19.7741150244454682*QzQbar_z))))));
    return;
  }
  
  void D_8_neg4_1(const double QzQbar_z, double& Mag) {
    Mag = -0.27421763710600381 + QzQbar_z*(2.7421763710600381 + QzQbar_z*(20.5663227829502861 + QzQbar_z*(24.679587339540343 + QzQbar_z*(-53.472439235670744 + QzQbar_z*(-149.722829859878083 + (-124.769024883231736 - 35.6482928237804959*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_8_neg3_1(const double QzQbar_z, double& Mag) {
    Mag = 0.53102017087395089 + QzQbar_z*(3.1861210252437053 + QzQbar_z*(-9.0273429048571651 + QzQbar_z*(-53.102017087395089 + QzQbar_z*(-34.516311106806808 + QzQbar_z*(96.645671099059062 + QzQbar_z*(144.968506648588593 + 55.226097770890892*QzQbar_z))))));
    return;
  }
  
  void D_8_neg2_1(const double QzQbar_z, double& Mag) {
    Mag = 0.130728129145949304 + QzQbar_z*(-4.18330013267037774 + QzQbar_z*(-12.9420847854489811 + QzQbar_z*(28.760188412108847 + QzQbar_z*(93.470612339353753 + (-130.858857275095254 - 74.776489871483002*QzQbar_z)*pow(QzQbar_z,2)))));
    return;
  }
  
  void D_8_neg1_1(const double QzQbar_z, double& Mag) {
    Mag = -0.546875 + QzQbar_z*(-1.09375 + QzQbar_z*(18.046875 + QzQbar_z*(24.0625 + QzQbar_z*(-78.203125 + QzQbar_z*(-93.84375 + QzQbar_z*(78.203125 + 89.375*QzQbar_z))))));
    return;
  }
  
  void D_8_0_1(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(4.64038825153671813 + pow(QzQbar_z,2)*(-51.044270766903899 + pow(QzQbar_z,2)*(132.715103993950138 - 94.796502852821527*pow(QzQbar_z,2))));
    return;
  }
  
  void D_8_1_1(const double QzQbar_z, double& Mag) {
    Mag = 0.546875 + QzQbar_z*(-1.09375 + QzQbar_z*(-18.046875 + QzQbar_z*(24.0625 + QzQbar_z*(78.203125 + QzQbar_z*(-93.84375 + QzQbar_z*(-78.203125 + 89.375*QzQbar_z))))));
    return;
  }
  
  void D_8_2_1(const double QzQbar_z, double& Mag) {
    Mag = -0.130728129145949304 + QzQbar_z*(-4.18330013267037774 + QzQbar_z*(12.9420847854489811 + QzQbar_z*(28.760188412108847 + QzQbar_z*(-93.470612339353753 + (130.858857275095254 - 74.776489871483002*QzQbar_z)*pow(QzQbar_z,2)))));
    return;
  }
  
  void D_8_3_1(const double QzQbar_z, double& Mag) {
    Mag = -0.53102017087395089 + QzQbar_z*(3.1861210252437053 + QzQbar_z*(9.0273429048571651 + QzQbar_z*(-53.102017087395089 + QzQbar_z*(34.516311106806808 + QzQbar_z*(96.645671099059062 + QzQbar_z*(-144.968506648588593 + 55.226097770890892*QzQbar_z))))));
    return;
  }
  
  void D_8_4_1(const double QzQbar_z, double& Mag) {
    Mag = 0.27421763710600381 + QzQbar_z*(2.7421763710600381 + QzQbar_z*(-20.5663227829502861 + QzQbar_z*(24.679587339540343 + QzQbar_z*(53.472439235670744 + QzQbar_z*(-149.722829859878083 + (124.769024883231736 - 35.6482928237804959*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_8_5_1(const double QzQbar_z, double& Mag) {
    Mag = 0.49435287561113671 + QzQbar_z*(-4.9435287561113671 + QzQbar_z*(7.415293134167051 + QzQbar_z*(29.661172536668202 + QzQbar_z*(-111.229397012505759 + QzQbar_z*(145.339745429674191 + QzQbar_z*(-86.511753231948923 + 19.7741150244454682*QzQbar_z))))));
    return;
  }
  
  void D_8_6_1(const double QzQbar_z, double& Mag) {
    Mag = -0.45768182862115031 + QzQbar_z*(0.e-16 + QzQbar_z*(16.018864001740261 + QzQbar_z*(-64.075456006961043 + QzQbar_z*(112.132048012181825 + QzQbar_z*(-102.520729611137669 + (48.056592005220782 - 9.1536365724230061*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_8_7_1(const double QzQbar_z, double& Mag) {
    Mag = -0.4178044361600293 + QzQbar_z*(5.8492621062404102 + QzQbar_z*(-26.321679478081846 + QzQbar_z*(58.492621062404102 + QzQbar_z*(-73.115776328005128 + QzQbar_z*(52.643358956163692 + QzQbar_z*(-20.4724173718414358 + 3.34243548928023441*QzQbar_z))))));
    return;
  }
  
  void D_8_8_1(const double QzQbar_z, double& Mag) {
    Mag = 0.8356088723200586 + QzQbar_z*(-5.8492621062404102 + QzQbar_z*(17.547786318721231 + QzQbar_z*(-29.246310531202051 + QzQbar_z*(29.246310531202051 + QzQbar_z*(-17.5477863187212307 + (5.8492621062404102 - 0.835608872320058603*QzQbar_z)*QzQbar_z)))));
    return;
  }
  
  void D_8_neg8_2(const double QzQbar_z, double& Mag) {
    Mag = 1.39824108257481835 + QzQbar_z*(8.3894464954489101 + QzQbar_z*(20.973616238622275 + QzQbar_z*(27.964821651496367 + QzQbar_z*(20.9736162386222753 + QzQbar_z*(8.3894464954489101 + 1.39824108257481835*QzQbar_z)))));
    return;
  }
  
  void D_8_neg7_2(const double QzQbar_z, double& Mag) {
    Mag = -1.39824108257481835 + QzQbar_z*(-12.5841697431733652 + QzQbar_z*(-41.947232477244551 + QzQbar_z*(-69.912054128740918 + QzQbar_z*(-62.920848715866826 + (-29.3630627340711854 - 5.5929643302992734*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_8_neg6_2(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(7.6584818175667167 + QzQbar_z*(45.9508909054003 + QzQbar_z*(107.218745445934033 + QzQbar_z*(122.535709081067467 + QzQbar_z*(68.92633635810045 + 15.3169636351334333*QzQbar_z)))));
    return;
  }
  
  void D_8_neg5_2(const double QzQbar_z, double& Mag) {
    Mag = 1.18172940007431481 + QzQbar_z*(3.5451882002229444 + QzQbar_z*(-21.271129201337667 + QzQbar_z*(-106.355646006688333 + QzQbar_z*(-173.714221810924278 + (-124.081587007803055 - 33.0884232020808148*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_8_neg4_2(const double QzQbar_z, double& Mag) {
    Mag = -0.65550553010634472 + QzQbar_z*(-9.8325829515951708 + QzQbar_z*(-17.6986493128713074 + QzQbar_z*(51.129431348294888 + QzQbar_z*(178.953009719032108 + QzQbar_z*(178.953009719032108 + 59.651003239677369*QzQbar_z)))));
    return;
  }
  
  void D_8_neg3_2(const double QzQbar_z, double& Mag) {
    Mag = -0.76162860043462128 + QzQbar_z*(4.31589540246285394 + QzQbar_z*(38.0814300217310642 + QzQbar_z*(33.003906018833589 + QzQbar_z*(-115.513671065917561 + (-207.92460791865161 - 92.410936852734049*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_8_neg2_2(const double QzQbar_z, double& Mag) {
    Mag = 1. + QzQbar_z*(6.1875 + QzQbar_z*(-20.625 + QzQbar_z*(-89.375 + pow(QzQbar_z,2)*(187.6875 + 125.125*QzQbar_z))));
    return;
  }
  
  void D_8_neg1_2(const double QzQbar_z, double& Mag) {
    Mag = 0.261456258291898609 + QzQbar_z*(-8.6280565236326541 + QzQbar_z*(-17.2561130472653082 + QzQbar_z*(74.776489871483002 + QzQbar_z*(112.164734807224503 + (-112.164734807224503 - 149.552979742966004*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_8_0_2(const double QzQbar_z, double& Mag) {
    Mag = -1.10926495933117801 + pow(QzQbar_z,2)*(36.6057436579288743 + pow(QzQbar_z,2)*(-158.624889184358455 + 158.624889184358455*pow(QzQbar_z,2)));
    return;
  }
  
  void D_8_1_2(const double QzQbar_z, double& Mag) {
    Mag = 0.261456258291898609 + QzQbar_z*(8.6280565236326541 + QzQbar_z*(-17.2561130472653082 + QzQbar_z*(-74.776489871483002 + QzQbar_z*(112.164734807224503 + (112.164734807224503 - 149.552979742966004*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_8_2_2(const double QzQbar_z, double& Mag) {
    Mag = 1. + QzQbar_z*(-6.1875 + QzQbar_z*(-20.625 + QzQbar_z*(89.375 + pow(QzQbar_z,2)*(-187.6875 + 125.125*QzQbar_z))));
    return;
  }
  
  void D_8_3_2(const double QzQbar_z, double& Mag) {
    Mag = -0.76162860043462128 + QzQbar_z*(-4.31589540246285394 + QzQbar_z*(38.0814300217310642 + QzQbar_z*(-33.003906018833589 + QzQbar_z*(-115.513671065917561 + (207.92460791865161 - 92.410936852734049*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_8_4_2(const double QzQbar_z, double& Mag) {
    Mag = -0.65550553010634472 + QzQbar_z*(9.8325829515951708 + QzQbar_z*(-17.6986493128713074 + QzQbar_z*(-51.129431348294888 + QzQbar_z*(178.953009719032108 + QzQbar_z*(-178.953009719032108 + 59.651003239677369*QzQbar_z)))));
    return;
  }
  
  void D_8_5_2(const double QzQbar_z, double& Mag) {
    Mag = 1.18172940007431481 + QzQbar_z*(-3.5451882002229444 + QzQbar_z*(-21.271129201337667 + QzQbar_z*(106.355646006688333 + QzQbar_z*(-173.714221810924278 + (124.081587007803055 - 33.0884232020808148*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_8_6_2(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-7.6584818175667167 + QzQbar_z*(45.9508909054003 + QzQbar_z*(-107.218745445934033 + QzQbar_z*(122.535709081067467 + QzQbar_z*(-68.92633635810045 + 15.3169636351334333*QzQbar_z)))));
    return;
  }
  
  void D_8_7_2(const double QzQbar_z, double& Mag) {
    Mag = -1.39824108257481835 + QzQbar_z*(12.5841697431733652 + QzQbar_z*(-41.947232477244551 + QzQbar_z*(69.912054128740918 + QzQbar_z*(-62.920848715866826 + (29.3630627340711854 - 5.5929643302992734*QzQbar_z)*QzQbar_z))));
    return;
  }
  
  void D_8_8_2(const double QzQbar_z, double& Mag) {
    Mag = 1.39824108257481835 + QzQbar_z*(-8.3894464954489101 + QzQbar_z*(20.973616238622275 + QzQbar_z*(-27.964821651496367 + QzQbar_z*(20.9736162386222753 + QzQbar_z*(-8.3894464954489101 + 1.39824108257481835*QzQbar_z)))));
    return;
  }
  
  void D_8_neg8_3(const double QzQbar_z, double& Mag) {
    Mag = -2.0653389552322883 + QzQbar_z*(-10.3266947761614413 + QzQbar_z*(-20.6533895523228826 + QzQbar_z*(-20.6533895523228826 + (-10.3266947761614413 - 2.06533895523228826*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_8_neg7_3(const double QzQbar_z, double& Mag) {
    Mag = 3.0980084328484324 + QzQbar_z*(20.653389552322883 + QzQbar_z*(51.633473880807206 + QzQbar_z*(61.960168656968648 + QzQbar_z*(36.143431716565045 + 8.261355820929153*QzQbar_z))));
    return;
  }
  
  void D_8_neg6_3(const double QzQbar_z, double& Mag) {
    Mag = -1.88538789112479451 + QzQbar_z*(-22.624654693497534 + QzQbar_z*(-79.186291427241369 + QzQbar_z*(-120.664825031986849 + (-84.842455100615753 - 22.6246546934975341*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_8_neg5_3(const double QzQbar_z, double& Mag) {
    Mag = -0.87276500273555882 + QzQbar_z*(10.4731800328267059 + QzQbar_z*(78.548850246200294 + QzQbar_z*(171.061940536169529 + QzQbar_z*(152.733875478722794 + 48.8748401531912941*QzQbar_z))));
    return;
  }
  
  void D_8_neg4_3(const double QzQbar_z, double& Mag) {
    Mag = 2.42061459137963555 + QzQbar_z*(8.714212528966688 + QzQbar_z*(-37.7615876255223146 + QzQbar_z*(-176.220742252437468 + (-220.275927815546835 - 88.110371126218734*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_8_neg3_3(const double QzQbar_z, double& Mag) {
    Mag = -1.0625 + QzQbar_z*(-18.75 + QzQbar_z*(-24.375 + QzQbar_z*(113.75 + QzQbar_z*(255.9375 + 136.5*QzQbar_z))));
    return;
  }
  
  void D_8_neg2_3(const double QzQbar_z, double& Mag) {
    Mag = -1.52325720086924257 + QzQbar_z*(10.1550480057949505 + QzQbar_z*(66.007812037667178 + (-231.027342131835123 - 184.821873705468098*QzQbar_z)*pow(QzQbar_z,2)));
    return;
  }
  
  void D_8_neg1_3(const double QzQbar_z, double& Mag) {
    Mag = 2.12408068349580356 + QzQbar_z*(8.4963227339832142 + QzQbar_z*(-55.226097770890892 + QzQbar_z*(-110.452195541781785 + QzQbar_z*(138.065244427227231 + 220.90439108356357*QzQbar_z))));
    return;
  }
  
  void D_8_0_3(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-18.0234222610468737 + pow(QzQbar_z,2)*(156.202992929072905 - 234.304489393609358*pow(QzQbar_z,2)));
    return;
  }
  
  void D_8_1_3(const double QzQbar_z, double& Mag) {
    Mag = -2.12408068349580356 + QzQbar_z*(8.4963227339832142 + QzQbar_z*(55.226097770890892 + QzQbar_z*(-110.452195541781785 + QzQbar_z*(-138.065244427227231 + 220.90439108356357*QzQbar_z))));
    return;
  }
  
  void D_8_2_3(const double QzQbar_z, double& Mag) {
    Mag = 1.52325720086924257 + QzQbar_z*(10.1550480057949505 + QzQbar_z*(-66.007812037667178 + (231.027342131835123 - 184.821873705468098*QzQbar_z)*pow(QzQbar_z,2)));
    return;
  }
  
  void D_8_3_3(const double QzQbar_z, double& Mag) {
    Mag = 1.0625 + QzQbar_z*(-18.75 + QzQbar_z*(24.375 + QzQbar_z*(113.75 + QzQbar_z*(-255.9375 + 136.5*QzQbar_z))));
    return;
  }
  
  void D_8_4_3(const double QzQbar_z, double& Mag) {
    Mag = -2.42061459137963555 + QzQbar_z*(8.714212528966688 + QzQbar_z*(37.7615876255223146 + QzQbar_z*(-176.220742252437468 + (220.275927815546835 - 88.110371126218734*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_8_5_3(const double QzQbar_z, double& Mag) {
    Mag = 0.87276500273555882 + QzQbar_z*(10.4731800328267059 + QzQbar_z*(-78.548850246200294 + QzQbar_z*(171.061940536169529 + QzQbar_z*(-152.733875478722794 + 48.8748401531912941*QzQbar_z))));
    return;
  }
  
  void D_8_6_3(const double QzQbar_z, double& Mag) {
    Mag = 1.88538789112479451 + QzQbar_z*(-22.624654693497534 + QzQbar_z*(79.186291427241369 + QzQbar_z*(-120.664825031986849 + (84.842455100615753 - 22.6246546934975341*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_8_7_3(const double QzQbar_z, double& Mag) {
    Mag = -3.0980084328484324 + QzQbar_z*(20.653389552322883 + QzQbar_z*(-51.633473880807206 + QzQbar_z*(61.960168656968648 + QzQbar_z*(-36.143431716565045 + 8.261355820929153*QzQbar_z))));
    return;
  }
  
  void D_8_8_3(const double QzQbar_z, double& Mag) {
    Mag = 2.0653389552322883 + QzQbar_z*(-10.3266947761614413 + QzQbar_z*(20.6533895523228826 + QzQbar_z*(-20.6533895523228826 + (10.3266947761614413 - 2.06533895523228826*QzQbar_z)*QzQbar_z)));
    return;
  }
  
  void D_8_neg8_4(const double QzQbar_z, double& Mag) {
    Mag = 2.6663411259626927 + QzQbar_z*(10.6653645038507709 + QzQbar_z*(15.9980467557761563 + QzQbar_z*(10.6653645038507709 + 2.66634112596269272*QzQbar_z)));
    return;
  }
  
  void D_8_neg7_4(const double QzQbar_z, double& Mag) {
    Mag = -5.3326822519253854 + QzQbar_z*(-26.663411259626927 + QzQbar_z*(-47.994140267328469 + (-37.328775763477698 - 10.6653645038507709*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_8_neg6_4(const double QzQbar_z, double& Mag) {
    Mag = 5.8416607227739613 + QzQbar_z*(40.891625059417729 + QzQbar_z*(93.466571564383381 + QzQbar_z*(87.62491084160942 + 29.2083036138698065*QzQbar_z)));
    return;
  }
  
  void D_8_neg5_4(const double QzQbar_z, double& Mag) {
    Mag = -2.70416345659799197 + QzQbar_z*(-40.5624518489698795 + QzQbar_z*(-132.504009373301607 + (-157.742868301549532 - 63.097147320619813*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_8_neg4_4(const double QzQbar_z, double& Mag) {
    Mag = -2.25 + QzQbar_z*(19.5 + QzQbar_z*(136.5 + QzQbar_z*(227.5 + 113.75*QzQbar_z)));
    return;
  }
  
  void D_8_neg3_4(const double QzQbar_z, double& Mag) {
    Mag = 4.84122918275927111 + QzQbar_z*(12.5871958751741049 + QzQbar_z*(-88.110371126218734 + (-264.331113378656202 - 176.220742252437468*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_8_neg2_4(const double QzQbar_z, double& Mag) {
    Mag = -2.62202212042537887 + QzQbar_z*(-34.0862875655299253 + pow(QzQbar_z,2)*(238.604012958709477 + 238.604012958709477*QzQbar_z));
    return;
  }
  
  void D_8_neg1_4(const double QzQbar_z, double& Mag) {
    Mag = -2.19374109684803052 + QzQbar_z*(28.5186342590243967 + QzQbar_z*(85.55590277707319 + (-142.593171295121983 - 285.186342590243967*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_8_0_4(const double QzQbar_z, double& Mag) {
    Mag = 4.65362761724657122 + pow(QzQbar_z,2)*(-120.994318048410852 + 302.48579512102713*pow(QzQbar_z,2));
    return;
  }
  
  void D_8_1_4(const double QzQbar_z, double& Mag) {
    Mag = -2.19374109684803052 + QzQbar_z*(-28.5186342590243967 + QzQbar_z*(85.55590277707319 + (142.593171295121983 - 285.186342590243967*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_8_2_4(const double QzQbar_z, double& Mag) {
    Mag = -2.62202212042537887 + QzQbar_z*(34.0862875655299253 + pow(QzQbar_z,2)*(-238.604012958709477 + 238.604012958709477*QzQbar_z));
    return;
  }
  
  void D_8_3_4(const double QzQbar_z, double& Mag) {
    Mag = 4.84122918275927111 + QzQbar_z*(-12.5871958751741049 + QzQbar_z*(-88.110371126218734 + (264.331113378656202 - 176.220742252437468*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_8_4_4(const double QzQbar_z, double& Mag) {
    Mag = -2.25 + QzQbar_z*(-19.5 + QzQbar_z*(136.5 + QzQbar_z*(-227.5 + 113.75*QzQbar_z)));
    return;
  }
  
  void D_8_5_4(const double QzQbar_z, double& Mag) {
    Mag = -2.70416345659799197 + QzQbar_z*(40.5624518489698795 + QzQbar_z*(-132.504009373301607 + (157.742868301549532 - 63.097147320619813*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_8_6_4(const double QzQbar_z, double& Mag) {
    Mag = 5.8416607227739613 + QzQbar_z*(-40.891625059417729 + QzQbar_z*(93.466571564383381 + QzQbar_z*(-87.62491084160942 + 29.2083036138698065*QzQbar_z)));
    return;
  }
  
  void D_8_7_4(const double QzQbar_z, double& Mag) {
    Mag = -5.3326822519253854 + QzQbar_z*(26.663411259626927 + QzQbar_z*(-47.994140267328469 + (37.328775763477698 - 10.6653645038507709*QzQbar_z)*QzQbar_z));
    return;
  }
  
  void D_8_8_4(const double QzQbar_z, double& Mag) {
    Mag = 2.6663411259626927 + QzQbar_z*(-10.6653645038507709 + QzQbar_z*(15.9980467557761563 + QzQbar_z*(-10.6653645038507709 + 2.66634112596269272*QzQbar_z)));
    return;
  }
  
  void D_8_neg8_5(const double QzQbar_z, double& Mag) {
    Mag = -2.958039891549808 + QzQbar_z*(-8.8741196746494241 + (-8.8741196746494241 - 2.95803989154980802*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_8_neg7_5(const double QzQbar_z, double& Mag) {
    Mag = 7.3950997288745201 + QzQbar_z*(26.6223590239482722 + QzQbar_z*(31.0594188612729842 + 11.8321595661992321*QzQbar_z));
    return;
  }
  
  void D_8_neg6_5(const double QzQbar_z, double& Mag) {
    Mag = -11.3412962222137554 + QzQbar_z*(-51.845925587262882 + (-72.908332857088428 - 32.4037034920393012*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_8_neg5_5(const double QzQbar_z, double& Mag) {
    Mag = 11.25 + QzQbar_z*(73.5 + QzQbar_z*(131.25 + 70.*QzQbar_z));
    return;
  }
  
  void D_8_neg4_5(const double QzQbar_z, double& Mag) {
    Mag = -5.4083269131959839 + QzQbar_z*(-75.716576784743775 + (-189.291441961859438 - 126.194294641239625*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_8_neg3_5(const double QzQbar_z, double& Mag) {
    Mag = -3.49106001094223529 + QzQbar_z*(48.8748401531912941 + QzQbar_z*(219.936780689360823 + 195.499360612765176*QzQbar_z));
    return;
  }
  
  void D_8_neg2_5(const double QzQbar_z, double& Mag) {
    Mag = 9.4538352005945185 + (-198.530539212484889 - 264.707385616646518*QzQbar_z)*pow(QzQbar_z,2);
    return;
  }
  
  void D_8_neg1_5(const double QzQbar_z, double& Mag) {
    Mag = -7.9096460097781873 + QzQbar_z*(-47.4578760586691237 + QzQbar_z*(118.644690146672809 + 316.385840391127491*QzQbar_z));
    return;
  }
  
  void D_8_0_5(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(67.115571963591281 - 335.577859817956405*pow(QzQbar_z,2));
    return;
  }
  
  void D_8_1_5(const double QzQbar_z, double& Mag) {
    Mag = 7.9096460097781873 + QzQbar_z*(-47.4578760586691237 + QzQbar_z*(-118.644690146672809 + 316.385840391127491*QzQbar_z));
    return;
  }
  
  void D_8_2_5(const double QzQbar_z, double& Mag) {
    Mag = -9.4538352005945185 + (198.530539212484889 - 264.707385616646518*QzQbar_z)*pow(QzQbar_z,2);
    return;
  }
  
  void D_8_3_5(const double QzQbar_z, double& Mag) {
    Mag = 3.49106001094223529 + QzQbar_z*(48.8748401531912941 + QzQbar_z*(-219.936780689360823 + 195.499360612765176*QzQbar_z));
    return;
  }
  
  void D_8_4_5(const double QzQbar_z, double& Mag) {
    Mag = 5.4083269131959839 + QzQbar_z*(-75.716576784743775 + (189.291441961859438 - 126.194294641239625*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_8_5_5(const double QzQbar_z, double& Mag) {
    Mag = -11.25 + QzQbar_z*(73.5 + QzQbar_z*(-131.25 + 70.*QzQbar_z));
    return;
  }
  
  void D_8_6_5(const double QzQbar_z, double& Mag) {
    Mag = 11.3412962222137554 + QzQbar_z*(-51.845925587262882 + (72.908332857088428 - 32.4037034920393012*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_8_7_5(const double QzQbar_z, double& Mag) {
    Mag = -7.3950997288745201 + QzQbar_z*(26.6223590239482722 + QzQbar_z*(-31.0594188612729842 + 11.8321595661992321*QzQbar_z));
    return;
  }
  
  void D_8_8_5(const double QzQbar_z, double& Mag) {
    Mag = 2.958039891549808 + QzQbar_z*(-8.8741196746494241 + (8.8741196746494241 - 2.95803989154980802*QzQbar_z)*QzQbar_z);
    return;
  }
  
  void D_8_neg8_6(const double QzQbar_z, double& Mag) {
    Mag = 2.73861278752583057 + QzQbar_z*(5.4772255750516611 + 2.73861278752583057*QzQbar_z);
    return;
  }
  
  void D_8_neg7_6(const double QzQbar_z, double& Mag) {
    Mag = -8.2158383625774917 + (-19.170289512680814 - 10.9544511501033223*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_8_neg6_6(const double QzQbar_z, double& Mag) {
    Mag = 16. + QzQbar_z*(45. + 30.*QzQbar_z);
    return;
  }
  
  void D_8_neg5_6(const double QzQbar_z, double& Mag) {
    Mag = -22.6825924444275108 + (-81.009258730098253 - 64.807406984078602*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_8_neg4_6(const double QzQbar_z, double& Mag) {
    Mag = 23.3666428910958452 + QzQbar_z*(116.833214455479226 + 116.833214455479226*QzQbar_z);
    return;
  }
  
  void D_8_neg3_6(const double QzQbar_z, double& Mag) {
    Mag = -15.0831031289983561 + (-135.747928160985205 - 180.997237547980273*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_8_neg2_6(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(122.535709081067467 + 245.071418162134933*QzQbar_z);
    return;
  }
  
  void D_8_neg1_6(const double QzQbar_z, double& Mag) {
    Mag = 14.6458185158768098 + (-73.229092579384049 - 292.916370317536196*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_8_0_6(const double QzQbar_z, double& Mag) {
    Mag = -20.7123151772079791 + 310.684727658119687*pow(QzQbar_z,2);
    return;
  }
  
  void D_8_1_6(const double QzQbar_z, double& Mag) {
    Mag = 14.6458185158768098 + (73.229092579384049 - 292.916370317536196*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_8_2_6(const double QzQbar_z, double& Mag) {
    Mag = QzQbar_z*(-122.535709081067467 + 245.071418162134933*QzQbar_z);
    return;
  }
  
  void D_8_3_6(const double QzQbar_z, double& Mag) {
    Mag = -15.0831031289983561 + (135.747928160985205 - 180.997237547980273*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_8_4_6(const double QzQbar_z, double& Mag) {
    Mag = 23.3666428910958452 + QzQbar_z*(-116.833214455479226 + 116.833214455479226*QzQbar_z);
    return;
  }
  
  void D_8_5_6(const double QzQbar_z, double& Mag) {
    Mag = -22.6825924444275108 + (81.009258730098253 - 64.807406984078602*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_8_6_6(const double QzQbar_z, double& Mag) {
    Mag = 16. + QzQbar_z*(-45. + 30.*QzQbar_z);
    return;
  }
  
  void D_8_7_6(const double QzQbar_z, double& Mag) {
    Mag = -8.2158383625774917 + (19.170289512680814 - 10.9544511501033223*QzQbar_z)*QzQbar_z;
    return;
  }
  
  void D_8_8_6(const double QzQbar_z, double& Mag) {
    Mag = 2.73861278752583057 + QzQbar_z*(-5.4772255750516611 + 2.73861278752583057*QzQbar_z);
    return;
  }
  
  void D_8_neg8_7(const double QzQbar_z, double& Mag) {
    Mag = -2. - 2.*QzQbar_z;
    return;
  }
  
  void D_8_neg7_7(const double QzQbar_z, double& Mag) {
    Mag = 7. + 8.*QzQbar_z;
    return;
  }
  
  void D_8_neg6_7(const double QzQbar_z, double& Mag) {
    Mag = -16.4316767251549834 - 21.9089023002066445*QzQbar_z;
    return;
  }
  
  void D_8_neg5_7(const double QzQbar_z, double& Mag) {
    Mag = 29.5803989154980802 + 47.3286382647969283*QzQbar_z;
    return;
  }
  
  void D_8_neg4_7(const double QzQbar_z, double& Mag) {
    Mag = -42.6614580154030835 - 85.322916030806167*QzQbar_z;
    return;
  }
  
  void D_8_neg3_7(const double QzQbar_z, double& Mag) {
    Mag = 49.5681349255749182 + 132.181693134866448*QzQbar_z;
    return;
  }
  
  void D_8_neg2_7(const double QzQbar_z, double& Mag) {
    Mag = -44.7437146423941873 - 178.974858569576749*QzQbar_z;
    return;
  }
  
  void D_8_neg1_7(const double QzQbar_z, double& Mag) {
    Mag = 26.7394839142418753 + 213.915871313935002*QzQbar_z;
    return;
  }
  
  void D_8_0_7(const double QzQbar_z, double& Mag) {
    Mag = -226.892044814268444*QzQbar_z;
    return;
  }
  
  void D_8_1_7(const double QzQbar_z, double& Mag) {
    Mag = -26.7394839142418753 + 213.915871313935002*QzQbar_z;
    return;
  }
  
  void D_8_2_7(const double QzQbar_z, double& Mag) {
    Mag = 44.7437146423941873 - 178.974858569576749*QzQbar_z;
    return;
  }
  
  void D_8_3_7(const double QzQbar_z, double& Mag) {
    Mag = -49.5681349255749182 + 132.181693134866448*QzQbar_z;
    return;
  }
  
  void D_8_4_7(const double QzQbar_z, double& Mag) {
    Mag = 42.6614580154030835 - 85.322916030806167*QzQbar_z;
    return;
  }
  
  void D_8_5_7(const double QzQbar_z, double& Mag) {
    Mag = -29.5803989154980802 + 47.3286382647969283*QzQbar_z;
    return;
  }
  
  void D_8_6_7(const double QzQbar_z, double& Mag) {
    Mag = 16.4316767251549834 - 21.9089023002066445*QzQbar_z;
    return;
  }
  
  void D_8_7_7(const double QzQbar_z, double& Mag) {
    Mag = -7. + 8.*QzQbar_z;
    return;
  }
  
  void D_8_8_7(const double QzQbar_z, double& Mag) {
    Mag = 2. - 2.*QzQbar_z;
    return;
  }
  
  void D_8_neg8_8(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_8_neg7_8(const double QzQbar_z, double& Mag) {
    Mag = -4.;
    return;
  }
  
  void D_8_neg6_8(const double QzQbar_z, double& Mag) {
    Mag = 10.9544511501033223;
    return;
  }
  
  void D_8_neg5_8(const double QzQbar_z, double& Mag) {
    Mag = -23.6643191323984642;
    return;
  }
  
  void D_8_neg4_8(const double QzQbar_z, double& Mag) {
    Mag = 42.6614580154030835;
    return;
  }
  
  void D_8_neg3_8(const double QzQbar_z, double& Mag) {
    Mag = -66.0908465674332242;
    return;
  }
  
  void D_8_neg2_8(const double QzQbar_z, double& Mag) {
    Mag = 89.4874292847883747;
    return;
  }
  
  void D_8_neg1_8(const double QzQbar_z, double& Mag) {
    Mag = -106.957935656967501;
    return;
  }
  
  void D_8_0_8(const double QzQbar_z, double& Mag) {
    Mag = 113.446022407134222;
    return;
  }
  
  void D_8_1_8(const double QzQbar_z, double& Mag) {
    Mag = -106.957935656967501;
    return;
  }
  
  void D_8_2_8(const double QzQbar_z, double& Mag) {
    Mag = 89.4874292847883747;
    return;
  }
  
  void D_8_3_8(const double QzQbar_z, double& Mag) {
    Mag = -66.0908465674332242;
    return;
  }
  
  void D_8_4_8(const double QzQbar_z, double& Mag) {
    Mag = 42.6614580154030835;
    return;
  }
  
  void D_8_5_8(const double QzQbar_z, double& Mag) {
    Mag = -23.6643191323984642;
    return;
  }
  
  void D_8_6_8(const double QzQbar_z, double& Mag) {
    Mag = 10.9544511501033223;
    return;
  }
  
  void D_8_7_8(const double QzQbar_z, double& Mag) {
    Mag = -4.;
    return;
  }
  
  void D_8_8_8(const double QzQbar_z, double& Mag) {
    Mag = 1.;
    return;
  }
  
}
