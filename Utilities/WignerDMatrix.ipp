namespace WignerDMatrixLocal {

  void Uninitialized(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    std::cerr << "\nThis matrix has not yet been initialized with L,M,MP information." << std::endl;
    Throw1WithMessage("Trying to use an uninitialized Wigner D matrix.");
  }

  void D_0_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 1.;
    return;
  }

  void D_1_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,2);
    return;
  }

  void D_1_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 1.41421356237309505*cosbetaovertwo*sinbetaovertwo;
    return;
  }

  void D_1_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2);
    return;
  }

  void D_1_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -1.41421356237309505*cosbetaovertwo*sinbetaovertwo;
    return;
  }

  void D_1_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2);
    return;
  }

  void D_1_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 1.41421356237309505*cosbetaovertwo*sinbetaovertwo;
    return;
  }

  void D_1_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2);
    return;
  }

  void D_1_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -1.41421356237309505*cosbetaovertwo*sinbetaovertwo;
    return;
  }

  void D_1_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,2);
    return;
  }

  void D_2_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,4);
    return;
  }

  void D_2_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.*pow(cosbetaovertwo,3)*sinbetaovertwo;
    return;
  }

  void D_2_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2);
    return;
  }

  void D_2_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.*cosbetaovertwo*pow(sinbetaovertwo,3);
    return;
  }

  void D_2_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4);
    return;
  }

  void D_2_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.*pow(cosbetaovertwo,3)*sinbetaovertwo;
    return;
  }

  void D_2_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,4) - 3.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2);
    return;
  }

  void D_2_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(2.4494897427831781*pow(cosbetaovertwo,3) - 2.4494897427831781*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_2_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(3.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_2_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.*cosbetaovertwo*pow(sinbetaovertwo,3);
    return;
  }

  void D_2_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2);
    return;
  }

  void D_2_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-2.4494897427831781*pow(cosbetaovertwo,3) + 2.4494897427831781*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_2_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-4.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2));
    return;
  }

  void D_2_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(2.4494897427831781*pow(cosbetaovertwo,3) - 2.4494897427831781*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_2_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2);
    return;
  }

  void D_2_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.*cosbetaovertwo*pow(sinbetaovertwo,3);
    return;
  }

  void D_2_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(3.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_2_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-2.4494897427831781*pow(cosbetaovertwo,3) + 2.4494897427831781*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_2_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,4) - 3.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2);
    return;
  }

  void D_2_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.*pow(cosbetaovertwo,3)*sinbetaovertwo;
    return;
  }

  void D_2_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4);
    return;
  }

  void D_2_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.*cosbetaovertwo*pow(sinbetaovertwo,3);
    return;
  }

  void D_2_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2);
    return;
  }

  void D_2_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.*pow(cosbetaovertwo,3)*sinbetaovertwo;
    return;
  }

  void D_2_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,4);
    return;
  }

  void D_3_neg3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,6);
    return;
  }

  void D_3_neg2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*pow(cosbetaovertwo,5)*sinbetaovertwo;
    return;
  }

  void D_3_neg1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2);
    return;
  }

  void D_3_0_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 4.47213595499957939*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,3);
    return;
  }

  void D_3_1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,4);
    return;
  }

  void D_3_2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*cosbetaovertwo*pow(sinbetaovertwo,5);
    return;
  }

  void D_3_3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6);
    return;
  }

  void D_3_neg3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.4494897427831781*pow(cosbetaovertwo,5)*sinbetaovertwo;
    return;
  }

  void D_3_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,6) - 5.*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2);
    return;
  }

  void D_3_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(3.16227766016837933*pow(cosbetaovertwo,5) - 6.3245553203367587*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(5.47722557505166113*pow(cosbetaovertwo,4) - 5.4772255750516611*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(6.3245553203367587*pow(cosbetaovertwo,3) - 3.16227766016837933*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(5.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*cosbetaovertwo*pow(sinbetaovertwo,5);
    return;
  }

  void D_3_neg3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2);
    return;
  }

  void D_3_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-3.16227766016837933*pow(cosbetaovertwo,5) + 6.3245553203367587*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-8.*pow(cosbetaovertwo,4) + 6.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(3.46410161513775459*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-10.3923048454132638*pow(cosbetaovertwo,3) + 3.46410161513775459*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_3_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(6.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-8.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)));
    return;
  }

  void D_3_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(6.3245553203367587*pow(cosbetaovertwo,3) - 3.16227766016837933*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,4);
    return;
  }

  void D_3_neg3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -4.47213595499957939*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,3);
    return;
  }

  void D_3_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(5.47722557505166113*pow(cosbetaovertwo,4) - 5.4772255750516611*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-3.46410161513775459*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(10.3923048454132638*pow(cosbetaovertwo,3) - 3.46410161513775459*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_3_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-9.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(9.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2)));
    return;
  }

  void D_3_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(3.46410161513775459*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-10.3923048454132638*pow(cosbetaovertwo,3) + 3.46410161513775459*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_3_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(5.47722557505166113*pow(cosbetaovertwo,4) - 5.4772255750516611*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 4.47213595499957939*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,3);
    return;
  }

  void D_3_neg3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,4);
    return;
  }

  void D_3_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-6.3245553203367587*pow(cosbetaovertwo,3) + 3.16227766016837933*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(6.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-8.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)));
    return;
  }

  void D_3_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-3.46410161513775459*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(10.3923048454132638*pow(cosbetaovertwo,3) - 3.46410161513775459*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_3_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-8.*pow(cosbetaovertwo,4) + 6.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(3.16227766016837933*pow(cosbetaovertwo,5) - 6.3245553203367587*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2);
    return;
  }

  void D_3_neg3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.4494897427831781*cosbetaovertwo*pow(sinbetaovertwo,5);
    return;
  }

  void D_3_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(5.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-6.3245553203367587*pow(cosbetaovertwo,3) + 3.16227766016837933*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(5.47722557505166113*pow(cosbetaovertwo,4) - 5.4772255750516611*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-3.16227766016837933*pow(cosbetaovertwo,5) + 6.3245553203367587*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_3_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,6) - 5.*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2);
    return;
  }

  void D_3_3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*pow(cosbetaovertwo,5)*sinbetaovertwo;
    return;
  }

  void D_3_neg3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6);
    return;
  }

  void D_3_neg2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.4494897427831781*cosbetaovertwo*pow(sinbetaovertwo,5);
    return;
  }

  void D_3_neg1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,4);
    return;
  }

  void D_3_0_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -4.47213595499957939*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,3);
    return;
  }

  void D_3_1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2);
    return;
  }

  void D_3_2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.4494897427831781*pow(cosbetaovertwo,5)*sinbetaovertwo;
    return;
  }

  void D_3_3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,6);
    return;
  }

  void D_4_neg4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,8);
    return;
  }

  void D_4_neg3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.8284271247461901*pow(cosbetaovertwo,7)*sinbetaovertwo;
    return;
  }

  void D_4_neg2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2);
    return;
  }

  void D_4_neg1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 7.48331477354788277*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,3);
    return;
  }

  void D_4_0_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.36660026534075548*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,4);
    return;
  }

  void D_4_1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 7.48331477354788277*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,5);
    return;
  }

  void D_4_2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,6);
    return;
  }

  void D_4_3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.8284271247461901*cosbetaovertwo*pow(sinbetaovertwo,7);
    return;
  }

  void D_4_4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8);
    return;
  }

  void D_4_neg4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.8284271247461901*pow(cosbetaovertwo,7)*sinbetaovertwo;
    return;
  }

  void D_4_neg3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,8) - 7.*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2);
    return;
  }

  void D_4_neg2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(3.74165738677394139*pow(cosbetaovertwo,7) - 11.2249721603218242*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_neg1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(7.9372539331937718*pow(cosbetaovertwo,6) - 13.228756555322953*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_0_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(11.8321595661992321*pow(cosbetaovertwo,5) - 11.8321595661992321*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(13.228756555322953*pow(cosbetaovertwo,4) - 7.9372539331937718*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(11.2249721603218242*pow(cosbetaovertwo,3) - 3.74165738677394139*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(7.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.8284271247461901*cosbetaovertwo*pow(sinbetaovertwo,7);
    return;
  }

  void D_4_neg4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2);
    return;
  }

  void D_4_neg3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-3.74165738677394139*pow(cosbetaovertwo,7) + 11.2249721603218242*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-12.*pow(cosbetaovertwo,6) + 15.*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.24264068711928515*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-21.2132034355964257*pow(cosbetaovertwo,5) + 14.1421356237309505*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(9.486832980505138*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-25.2982212813470347*pow(cosbetaovertwo,4) + 9.486832980505138*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(14.1421356237309505*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-21.2132034355964257*pow(cosbetaovertwo,3) + 4.24264068711928515*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(15.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-12.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(11.2249721603218242*pow(cosbetaovertwo,3) - 3.74165738677394139*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,6);
    return;
  }

  void D_4_neg4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -7.48331477354788277*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,3);
    return;
  }

  void D_4_neg3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(7.9372539331937718*pow(cosbetaovertwo,6) - 13.228756555322953*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.24264068711928515*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(21.2132034355964257*pow(cosbetaovertwo,5) - 14.1421356237309505*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-15.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(30.*pow(cosbetaovertwo,4) - 10.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.47213595499957939*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-26.8328157299974764*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(26.8328157299974764*pow(cosbetaovertwo,3) - 4.47213595499957939*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_4_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(10.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-30.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(15.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))));
    return;
  }

  void D_4_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(14.1421356237309505*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-21.2132034355964257*pow(cosbetaovertwo,3) + 4.24264068711928515*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(13.228756555322953*pow(cosbetaovertwo,4) - 7.9372539331937718*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 7.48331477354788277*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,5);
    return;
  }

  void D_4_neg4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.36660026534075548*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,4);
    return;
  }

  void D_4_neg3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-11.8321595661992321*pow(cosbetaovertwo,5) + 11.8321595661992321*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(9.486832980505138*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-25.2982212813470347*pow(cosbetaovertwo,4) + 9.486832980505138*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.47213595499957939*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(26.8328157299974764*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-26.8328157299974764*pow(cosbetaovertwo,3) + 4.47213595499957939*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_4_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-16.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(36.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-16.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2))));
    return;
  }

  void D_4_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.47213595499957939*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-26.8328157299974764*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(26.8328157299974764*pow(cosbetaovertwo,3) - 4.47213595499957939*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_4_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(9.486832980505138*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-25.2982212813470347*pow(cosbetaovertwo,4) + 9.486832980505138*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(11.8321595661992321*pow(cosbetaovertwo,5) - 11.8321595661992321*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.36660026534075548*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,4);
    return;
  }

  void D_4_neg4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -7.48331477354788277*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,5);
    return;
  }

  void D_4_neg3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(13.228756555322953*pow(cosbetaovertwo,4) - 7.9372539331937718*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-14.1421356237309505*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(21.2132034355964257*pow(cosbetaovertwo,3) - 4.24264068711928515*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(10.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-30.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(15.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))));
    return;
  }

  void D_4_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.47213595499957939*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(26.8328157299974764*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-26.8328157299974764*pow(cosbetaovertwo,3) + 4.47213595499957939*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_4_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-15.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(30.*pow(cosbetaovertwo,4) - 10.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.24264068711928515*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-21.2132034355964257*pow(cosbetaovertwo,5) + 14.1421356237309505*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(7.9372539331937718*pow(cosbetaovertwo,6) - 13.228756555322953*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 7.48331477354788277*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,3);
    return;
  }

  void D_4_neg4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,6);
    return;
  }

  void D_4_neg3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-11.2249721603218242*pow(cosbetaovertwo,3) + 3.74165738677394139*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(15.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-12.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-14.1421356237309505*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(21.2132034355964257*pow(cosbetaovertwo,3) - 4.24264068711928515*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(9.486832980505138*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-25.2982212813470347*pow(cosbetaovertwo,4) + 9.486832980505138*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.24264068711928515*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(21.2132034355964257*pow(cosbetaovertwo,5) - 14.1421356237309505*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_4_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-12.*pow(cosbetaovertwo,6) + 15.*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(3.74165738677394139*pow(cosbetaovertwo,7) - 11.2249721603218242*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2);
    return;
  }

  void D_4_neg4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.8284271247461901*cosbetaovertwo*pow(sinbetaovertwo,7);
    return;
  }

  void D_4_neg3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(7.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_neg2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-11.2249721603218242*pow(cosbetaovertwo,3) + 3.74165738677394139*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_neg1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(13.228756555322953*pow(cosbetaovertwo,4) - 7.9372539331937718*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_0_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-11.8321595661992321*pow(cosbetaovertwo,5) + 11.8321595661992321*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(7.9372539331937718*pow(cosbetaovertwo,6) - 13.228756555322953*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-3.74165738677394139*pow(cosbetaovertwo,7) + 11.2249721603218242*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_4_3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,8) - 7.*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2);
    return;
  }

  void D_4_4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.8284271247461901*pow(cosbetaovertwo,7)*sinbetaovertwo;
    return;
  }

  void D_4_neg4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8);
    return;
  }

  void D_4_neg3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.8284271247461901*cosbetaovertwo*pow(sinbetaovertwo,7);
    return;
  }

  void D_4_neg2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,6);
    return;
  }

  void D_4_neg1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -7.48331477354788277*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,5);
    return;
  }

  void D_4_0_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.36660026534075548*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,4);
    return;
  }

  void D_4_1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -7.48331477354788277*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,3);
    return;
  }

  void D_4_2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2);
    return;
  }

  void D_4_3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.8284271247461901*pow(cosbetaovertwo,7)*sinbetaovertwo;
    return;
  }

  void D_4_4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,8);
    return;
  }

  void D_5_neg5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,10);
    return;
  }

  void D_5_neg4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.16227766016837933*pow(cosbetaovertwo,9)*sinbetaovertwo;
    return;
  }

  void D_5_neg3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2);
    return;
  }

  void D_5_neg2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,3);
    return;
  }

  void D_5_neg1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,4);
    return;
  }

  void D_5_0_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 15.8745078663875435*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,5);
    return;
  }

  void D_5_1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,6);
    return;
  }

  void D_5_2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,7);
    return;
  }

  void D_5_3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,8);
    return;
  }

  void D_5_4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.16227766016837933*cosbetaovertwo*pow(sinbetaovertwo,9);
    return;
  }

  void D_5_5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10);
    return;
  }

  void D_5_neg5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.16227766016837933*pow(cosbetaovertwo,9)*sinbetaovertwo;
    return;
  }

  void D_5_neg4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,10) - 9.*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2);
    return;
  }

  void D_5_neg3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.24264068711928515*pow(cosbetaovertwo,9) - 16.9705627484771406*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_neg2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(10.3923048454132638*pow(cosbetaovertwo,8) - 24.2487113059642821*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_neg1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(18.33030277982336*pow(cosbetaovertwo,7) - 27.49545416973504*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_0_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(25.0998007960222664*pow(cosbetaovertwo,6) - 25.0998007960222664*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(27.49545416973504*pow(cosbetaovertwo,5) - 18.33030277982336*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(24.2487113059642821*pow(cosbetaovertwo,4) - 10.3923048454132638*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(16.9705627484771406*pow(cosbetaovertwo,3) - 4.24264068711928515*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(9.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.16227766016837933*cosbetaovertwo*pow(sinbetaovertwo,9);
    return;
  }

  void D_5_neg5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2);
    return;
  }

  void D_5_neg4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.24264068711928515*pow(cosbetaovertwo,9) + 16.9705627484771406*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_neg3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-16.*pow(cosbetaovertwo,8) + 28.*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_neg2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.8989794855663562*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-34.2928563989644934*pow(cosbetaovertwo,7) + 34.2928563989644934*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_neg1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(12.9614813968157205*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-51.845925587262882*pow(cosbetaovertwo,6) + 32.4037034920393012*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_0_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(23.6643191323984642*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-59.16079783099616*pow(cosbetaovertwo,5) + 23.6643191323984642*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(32.4037034920393012*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-51.845925587262882*pow(cosbetaovertwo,4) + 12.9614813968157205*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(34.2928563989644934*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-34.2928563989644934*pow(cosbetaovertwo,3) + 4.8989794855663562*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(28.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-16.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(16.9705627484771406*pow(cosbetaovertwo,3) - 4.24264068711928515*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,8);
    return;
  }

  void D_5_neg5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -10.9544511501033223*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,3);
    return;
  }

  void D_5_neg4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(10.3923048454132638*pow(cosbetaovertwo,8) - 24.2487113059642821*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_neg3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.8989794855663562*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(34.2928563989644934*pow(cosbetaovertwo,7) - 34.2928563989644934*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-21.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(63.*pow(cosbetaovertwo,6) - 35.*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.29150262212918118*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-47.6235235991626306*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(79.372539331937718*pow(cosbetaovertwo,5) - 26.4575131106459059*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(14.4913767461894386*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-72.456883730947193*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(72.456883730947193*pow(cosbetaovertwo,4) - 14.4913767461894386*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(26.4575131106459059*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-79.372539331937718*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(47.6235235991626306*pow(cosbetaovertwo,3) - 5.2915026221291812*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(35.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-63.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(21.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(34.2928563989644934*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-34.2928563989644934*pow(cosbetaovertwo,3) + 4.8989794855663562*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(24.2487113059642821*pow(cosbetaovertwo,4) - 10.3923048454132638*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,7);
    return;
  }

  void D_5_neg5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,4);
    return;
  }

  void D_5_neg4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-18.33030277982336*pow(cosbetaovertwo,7) + 27.49545416973504*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_neg3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(12.9614813968157205*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-51.845925587262882*pow(cosbetaovertwo,6) + 32.4037034920393012*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.29150262212918118*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(47.6235235991626306*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-79.372539331937718*pow(cosbetaovertwo,5) + 26.4575131106459059*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-24.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(90.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-80.*pow(cosbetaovertwo,4) + 15.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.47722557505166113*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-54.772255750516611*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(109.544511501033223*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-54.772255750516611*pow(cosbetaovertwo,3) + 5.47722557505166113*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_5_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(15.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-80.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(90.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-24.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)))));
    return;
  }

  void D_5_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(26.4575131106459059*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-79.372539331937718*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(47.6235235991626306*pow(cosbetaovertwo,3) - 5.2915026221291812*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(32.4037034920393012*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-51.845925587262882*pow(cosbetaovertwo,4) + 12.9614813968157205*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(27.49545416973504*pow(cosbetaovertwo,5) - 18.33030277982336*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,6);
    return;
  }

  void D_5_neg5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -15.8745078663875435*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,5);
    return;
  }

  void D_5_neg4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(25.0998007960222664*pow(cosbetaovertwo,6) - 25.0998007960222664*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_neg3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-23.6643191323984642*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(59.16079783099616*pow(cosbetaovertwo,5) - 23.6643191323984642*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(14.4913767461894386*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-72.456883730947193*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(72.456883730947193*pow(cosbetaovertwo,4) - 14.4913767461894386*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.47722557505166113*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(54.772255750516611*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-109.544511501033223*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(54.772255750516611*pow(cosbetaovertwo,3) - 5.47722557505166113*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_5_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-25.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(100.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-100.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(25.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_5_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.47722557505166113*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-54.772255750516611*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(109.544511501033223*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-54.772255750516611*pow(cosbetaovertwo,3) + 5.47722557505166113*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_5_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(14.4913767461894386*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-72.456883730947193*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(72.456883730947193*pow(cosbetaovertwo,4) - 14.4913767461894386*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(23.6643191323984642*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-59.16079783099616*pow(cosbetaovertwo,5) + 23.6643191323984642*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(25.0998007960222664*pow(cosbetaovertwo,6) - 25.0998007960222664*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 15.8745078663875435*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,5);
    return;
  }

  void D_5_neg5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,6);
    return;
  }

  void D_5_neg4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-27.49545416973504*pow(cosbetaovertwo,5) + 18.33030277982336*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_neg3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(32.4037034920393012*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-51.845925587262882*pow(cosbetaovertwo,4) + 12.9614813968157205*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-26.4575131106459059*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(79.372539331937718*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-47.6235235991626306*pow(cosbetaovertwo,3) + 5.29150262212918118*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(15.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-80.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(90.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-24.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)))));
    return;
  }

  void D_5_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.47722557505166113*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(54.772255750516611*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-109.544511501033223*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(54.772255750516611*pow(cosbetaovertwo,3) - 5.47722557505166113*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_5_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-24.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(90.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-80.*pow(cosbetaovertwo,4) + 15.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.29150262212918118*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-47.6235235991626306*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(79.372539331937718*pow(cosbetaovertwo,5) - 26.4575131106459059*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(12.9614813968157205*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-51.845925587262882*pow(cosbetaovertwo,6) + 32.4037034920393012*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(18.33030277982336*pow(cosbetaovertwo,7) - 27.49545416973504*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,4);
    return;
  }

  void D_5_neg5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -10.9544511501033223*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,7);
    return;
  }

  void D_5_neg4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(24.2487113059642821*pow(cosbetaovertwo,4) - 10.3923048454132638*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_neg3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-34.2928563989644934*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(34.2928563989644934*pow(cosbetaovertwo,3) - 4.8989794855663562*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(35.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-63.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(21.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-26.4575131106459059*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(79.372539331937718*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-47.6235235991626306*pow(cosbetaovertwo,3) + 5.29150262212918118*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(14.4913767461894386*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-72.456883730947193*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(72.456883730947193*pow(cosbetaovertwo,4) - 14.4913767461894386*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.29150262212918118*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(47.6235235991626306*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-79.372539331937718*pow(cosbetaovertwo,5) + 26.4575131106459059*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_5_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-21.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(63.*pow(cosbetaovertwo,6) - 35.*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.8989794855663562*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-34.2928563989644934*pow(cosbetaovertwo,7) + 34.2928563989644934*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(10.3923048454132638*pow(cosbetaovertwo,8) - 24.2487113059642821*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,3);
    return;
  }

  void D_5_neg5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,8);
    return;
  }

  void D_5_neg4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-16.9705627484771406*pow(cosbetaovertwo,3) + 4.24264068711928515*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_neg3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(28.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-16.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_neg2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-34.2928563989644934*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(34.2928563989644934*pow(cosbetaovertwo,3) - 4.8989794855663562*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_neg1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(32.4037034920393012*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-51.845925587262882*pow(cosbetaovertwo,4) + 12.9614813968157205*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_0_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-23.6643191323984642*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(59.16079783099616*pow(cosbetaovertwo,5) - 23.6643191323984642*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(12.9614813968157205*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-51.845925587262882*pow(cosbetaovertwo,6) + 32.4037034920393012*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.8989794855663562*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(34.2928563989644934*pow(cosbetaovertwo,7) - 34.2928563989644934*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_5_3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-16.*pow(cosbetaovertwo,8) + 28.*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.24264068711928515*pow(cosbetaovertwo,9) - 16.9705627484771406*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2);
    return;
  }

  void D_5_neg5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.16227766016837933*cosbetaovertwo*pow(sinbetaovertwo,9);
    return;
  }

  void D_5_neg4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(9.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_neg3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-16.9705627484771406*pow(cosbetaovertwo,3) + 4.24264068711928515*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_neg2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(24.2487113059642821*pow(cosbetaovertwo,4) - 10.3923048454132638*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_neg1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-27.49545416973504*pow(cosbetaovertwo,5) + 18.33030277982336*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_0_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(25.0998007960222664*pow(cosbetaovertwo,6) - 25.0998007960222664*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-18.33030277982336*pow(cosbetaovertwo,7) + 27.49545416973504*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(10.3923048454132638*pow(cosbetaovertwo,8) - 24.2487113059642821*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.24264068711928515*pow(cosbetaovertwo,9) + 16.9705627484771406*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_5_4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,10) - 9.*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2);
    return;
  }

  void D_5_5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.16227766016837933*pow(cosbetaovertwo,9)*sinbetaovertwo;
    return;
  }

  void D_5_neg5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10);
    return;
  }

  void D_5_neg4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.16227766016837933*cosbetaovertwo*pow(sinbetaovertwo,9);
    return;
  }

  void D_5_neg3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,8);
    return;
  }

  void D_5_neg2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -10.9544511501033223*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,7);
    return;
  }

  void D_5_neg1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,6);
    return;
  }

  void D_5_0_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -15.8745078663875435*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,5);
    return;
  }

  void D_5_1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,4);
    return;
  }

  void D_5_2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -10.9544511501033223*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,3);
    return;
  }

  void D_5_3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2);
    return;
  }

  void D_5_4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.16227766016837933*pow(cosbetaovertwo,9)*sinbetaovertwo;
    return;
  }

  void D_5_5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,10);
    return;
  }

  void D_6_neg6_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,12);
    return;
  }

  void D_6_neg5_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.46410161513775459*pow(cosbetaovertwo,11)*sinbetaovertwo;
    return;
  }

  void D_6_neg4_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2);
    return;
  }

  void D_6_neg3_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.8323969741913259*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,3);
    return;
  }

  void D_6_neg2_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,4);
    return;
  }

  void D_6_neg1_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 28.1424945589405773*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,5);
    return;
  }

  void D_6_0_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 30.3973683071413273*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,6);
    return;
  }

  void D_6_1_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 28.1424945589405773*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,7);
    return;
  }

  void D_6_2_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,8);
    return;
  }

  void D_6_3_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.8323969741913259*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,9);
    return;
  }

  void D_6_4_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,10);
    return;
  }

  void D_6_5_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.46410161513775459*cosbetaovertwo*pow(sinbetaovertwo,11);
    return;
  }

  void D_6_6_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,12);
    return;
  }

  void D_6_neg6_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.46410161513775459*pow(cosbetaovertwo,11)*sinbetaovertwo;
    return;
  }

  void D_6_neg5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,12) - 11.*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2);
    return;
  }

  void D_6_neg4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.69041575982342955*pow(cosbetaovertwo,11) - 23.4520787991171478*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(12.845232578665129*pow(cosbetaovertwo,10) - 38.5356977359953871*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(25.690465157330258*pow(cosbetaovertwo,9) - 51.380930314660516*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(40.6201920231798018*pow(cosbetaovertwo,8) - 56.868268832451723*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_0_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(52.6497863243527324*pow(cosbetaovertwo,7) - 52.649786324352732*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(56.868268832451723*pow(cosbetaovertwo,6) - 40.6201920231798018*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(51.380930314660516*pow(cosbetaovertwo,5) - 25.690465157330258*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(38.5356977359953871*pow(cosbetaovertwo,4) - 12.845232578665129*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(23.4520787991171478*pow(cosbetaovertwo,3) - 4.69041575982342955*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(11.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_6_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.46410161513775459*cosbetaovertwo*pow(sinbetaovertwo,11);
    return;
  }

  void D_6_neg6_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2);
    return;
  }

  void D_6_neg5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.69041575982342955*pow(cosbetaovertwo,11) + 23.4520787991171478*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-20.*pow(cosbetaovertwo,10) + 45.*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.47722557505166113*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-49.2950301754649502*pow(cosbetaovertwo,9) + 65.726706900619934*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_neg2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(16.4316767251549834*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-87.635609200826578*pow(cosbetaovertwo,8) + 76.681158050723256*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_neg1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(34.6410161513775459*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-121.243556529821411*pow(cosbetaovertwo,7) + 72.746133917892846*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_0_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(56.124860801609121*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-134.69966592386189*pow(cosbetaovertwo,6) + 56.124860801609121*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(72.746133917892846*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-121.243556529821411*pow(cosbetaovertwo,5) + 34.6410161513775459*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(76.681158050723256*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-87.635609200826578*pow(cosbetaovertwo,4) + 16.4316767251549834*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(65.726706900619934*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-49.2950301754649502*pow(cosbetaovertwo,3) + 5.47722557505166113*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(45.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-20.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(23.4520787991171478*pow(cosbetaovertwo,3) - 4.69041575982342955*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_6_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,10);
    return;
  }

  void D_6_neg6_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -14.8323969741913259*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,3);
    return;
  }

  void D_6_neg5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(12.845232578665129*pow(cosbetaovertwo,10) - 38.5356977359953871*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.47722557505166113*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(49.2950301754649502*pow(cosbetaovertwo,9) - 65.726706900619934*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_neg3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-27.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(108.*pow(cosbetaovertwo,8) - 84.*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_neg2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-72.*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(168.*pow(cosbetaovertwo,7) - 84.*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_neg1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(18.973665961010276*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-132.815661727071932*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(199.223492590607898*pow(cosbetaovertwo,6) - 66.407830863535966*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_0_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(40.9878030638383935*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-184.445113787272771*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(184.445113787272771*pow(cosbetaovertwo,5) - 40.9878030638383935*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(66.407830863535966*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-199.223492590607898*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(132.815661727071932*pow(cosbetaovertwo,4) - 18.973665961010276*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(84.*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-168.*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(72.*pow(cosbetaovertwo,3) - 6.*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(84.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-108.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(27.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(65.726706900619934*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-49.2950301754649502*pow(cosbetaovertwo,3) + 5.47722557505166113*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(38.5356977359953871*pow(cosbetaovertwo,4) - 12.845232578665129*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_6_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.8323969741913259*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,9);
    return;
  }

  void D_6_neg6_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,4);
    return;
  }

  void D_6_neg5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-25.690465157330258*pow(cosbetaovertwo,9) + 51.380930314660516*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(16.4316767251549834*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-87.635609200826578*pow(cosbetaovertwo,8) + 76.681158050723256*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_neg3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(72.*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-168.*pow(cosbetaovertwo,7) + 84.*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-32.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(168.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-224.*pow(cosbetaovertwo,6) + 70.*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.32455532033675866*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-88.543774484714621*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(265.631323454143864*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-221.359436211786553*pow(cosbetaovertwo,5) + 44.2718872423573106*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(20.4939015319191968*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-163.951212255353574*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(307.408522978787951*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-163.951212255353574*pow(cosbetaovertwo,4) + 20.4939015319191968*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(44.2718872423573106*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-221.359436211786553*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(265.631323454143864*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-88.543774484714621*pow(cosbetaovertwo,3) + 6.32455532033675866*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(70.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-224.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(168.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-32.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(84.*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-168.*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(72.*pow(cosbetaovertwo,3) - 6.*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(76.681158050723256*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-87.635609200826578*pow(cosbetaovertwo,4) + 16.4316767251549834*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(51.380930314660516*pow(cosbetaovertwo,5) - 25.690465157330258*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_6_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,8);
    return;
  }

  void D_6_neg6_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -28.1424945589405773*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,5);
    return;
  }

  void D_6_neg5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(40.6201920231798018*pow(cosbetaovertwo,8) - 56.868268832451723*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-34.6410161513775459*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(121.243556529821411*pow(cosbetaovertwo,7) - 72.746133917892846*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_neg3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(18.973665961010276*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-132.815661727071932*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(199.223492590607898*pow(cosbetaovertwo,6) - 66.407830863535966*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.32455532033675866*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(88.543774484714621*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-265.631323454143864*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(221.359436211786553*pow(cosbetaovertwo,5) - 44.2718872423573106*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-35.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(210.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-350.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(175.*pow(cosbetaovertwo,4) - 21.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.48074069840786023*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-97.211110476117903*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(324.037034920393012*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-324.037034920393012*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(97.211110476117903*pow(cosbetaovertwo,3) - 6.4807406984078602*cosbetaovertwo*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_6_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(21.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-175.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(350.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-210.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(35.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_6_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(44.2718872423573106*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-221.359436211786553*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(265.631323454143864*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-88.543774484714621*pow(cosbetaovertwo,3) + 6.32455532033675866*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(66.407830863535966*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-199.223492590607898*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(132.815661727071932*pow(cosbetaovertwo,4) - 18.973665961010276*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(72.746133917892846*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-121.243556529821411*pow(cosbetaovertwo,5) + 34.6410161513775459*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(56.868268832451723*pow(cosbetaovertwo,6) - 40.6201920231798018*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_6_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 28.1424945589405773*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,7);
    return;
  }

  void D_6_neg6_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 30.3973683071413273*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,6);
    return;
  }

  void D_6_neg5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-52.649786324352732*pow(cosbetaovertwo,7) + 52.6497863243527324*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(56.124860801609121*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-134.69966592386189*pow(cosbetaovertwo,6) + 56.124860801609121*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_neg3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-40.9878030638383935*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(184.445113787272771*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-184.445113787272771*pow(cosbetaovertwo,5) + 40.9878030638383935*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(20.4939015319191968*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-163.951212255353574*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(307.408522978787951*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-163.951212255353574*pow(cosbetaovertwo,4) + 20.4939015319191968*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.48074069840786023*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(97.211110476117903*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-324.037034920393012*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(324.037034920393012*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-97.211110476117903*pow(cosbetaovertwo,3) + 6.4807406984078602*cosbetaovertwo*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_6_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-36.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(225.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-400.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(225.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-36.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2))))));
    return;
  }

  void D_6_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.48074069840786023*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-97.211110476117903*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(324.037034920393012*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-324.037034920393012*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(97.211110476117903*pow(cosbetaovertwo,3) - 6.4807406984078602*cosbetaovertwo*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_6_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(20.4939015319191968*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-163.951212255353574*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(307.408522978787951*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-163.951212255353574*pow(cosbetaovertwo,4) + 20.4939015319191968*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(40.9878030638383935*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-184.445113787272771*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(184.445113787272771*pow(cosbetaovertwo,5) - 40.9878030638383935*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(56.124860801609121*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-134.69966592386189*pow(cosbetaovertwo,6) + 56.124860801609121*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(52.6497863243527324*pow(cosbetaovertwo,7) - 52.649786324352732*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_6_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 30.3973683071413273*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,6);
    return;
  }

  void D_6_neg6_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -28.1424945589405773*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,7);
    return;
  }

  void D_6_neg5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(56.868268832451723*pow(cosbetaovertwo,6) - 40.6201920231798018*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-72.746133917892846*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(121.243556529821411*pow(cosbetaovertwo,5) - 34.6410161513775459*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_neg3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(66.407830863535966*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-199.223492590607898*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(132.815661727071932*pow(cosbetaovertwo,4) - 18.973665961010276*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-44.2718872423573106*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(221.359436211786553*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-265.631323454143864*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(88.543774484714621*pow(cosbetaovertwo,3) - 6.32455532033675866*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(21.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-175.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(350.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-210.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(35.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_6_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.4807406984078602*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(97.211110476117903*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-324.037034920393012*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(324.037034920393012*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-97.211110476117903*pow(cosbetaovertwo,3) + 6.48074069840786023*cosbetaovertwo*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_6_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-35.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(210.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-350.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(175.*pow(cosbetaovertwo,4) - 21.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.32455532033675866*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-88.543774484714621*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(265.631323454143864*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-221.359436211786553*pow(cosbetaovertwo,5) + 44.2718872423573106*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(18.973665961010276*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-132.815661727071932*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(199.223492590607898*pow(cosbetaovertwo,6) - 66.407830863535966*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(34.6410161513775459*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-121.243556529821411*pow(cosbetaovertwo,7) + 72.746133917892846*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(40.6201920231798018*pow(cosbetaovertwo,8) - 56.868268832451723*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_6_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 28.1424945589405773*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,5);
    return;
  }

  void D_6_neg6_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,8);
    return;
  }

  void D_6_neg5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-51.380930314660516*pow(cosbetaovertwo,5) + 25.690465157330258*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(76.681158050723256*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-87.635609200826578*pow(cosbetaovertwo,4) + 16.4316767251549834*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_neg3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-84.*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(168.*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-72.*pow(cosbetaovertwo,3) + 6.*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(70.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-224.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(168.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-32.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-44.2718872423573106*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(221.359436211786553*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-265.631323454143864*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(88.543774484714621*pow(cosbetaovertwo,3) - 6.32455532033675866*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(20.4939015319191968*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-163.951212255353574*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(307.408522978787951*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-163.951212255353574*pow(cosbetaovertwo,4) + 20.4939015319191968*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.32455532033675866*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(88.543774484714621*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-265.631323454143864*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(221.359436211786553*pow(cosbetaovertwo,5) - 44.2718872423573106*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_6_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-32.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(168.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-224.*pow(cosbetaovertwo,6) + 70.*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-72.*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(168.*pow(cosbetaovertwo,7) - 84.*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(16.4316767251549834*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-87.635609200826578*pow(cosbetaovertwo,8) + 76.681158050723256*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(25.690465157330258*pow(cosbetaovertwo,9) - 51.380930314660516*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_6_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,4);
    return;
  }

  void D_6_neg6_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -14.8323969741913259*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,9);
    return;
  }

  void D_6_neg5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(38.5356977359953871*pow(cosbetaovertwo,4) - 12.845232578665129*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-65.726706900619934*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(49.2950301754649502*pow(cosbetaovertwo,3) - 5.47722557505166113*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_neg3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(84.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-108.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(27.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_neg2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-84.*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(168.*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-72.*pow(cosbetaovertwo,3) + 6.*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_neg1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(66.407830863535966*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-199.223492590607898*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(132.815661727071932*pow(cosbetaovertwo,4) - 18.973665961010276*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_0_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-40.9878030638383935*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(184.445113787272771*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-184.445113787272771*pow(cosbetaovertwo,5) + 40.9878030638383935*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(18.973665961010276*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-132.815661727071932*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(199.223492590607898*pow(cosbetaovertwo,6) - 66.407830863535966*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(72.*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-168.*pow(cosbetaovertwo,7) + 84.*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_6_3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-27.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(108.*pow(cosbetaovertwo,8) - 84.*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.47722557505166113*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-49.2950301754649502*pow(cosbetaovertwo,9) + 65.726706900619934*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(12.845232578665129*pow(cosbetaovertwo,10) - 38.5356977359953871*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_6_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.8323969741913259*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,3);
    return;
  }

  void D_6_neg6_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,10);
    return;
  }

  void D_6_neg5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(-23.4520787991171478*pow(cosbetaovertwo,3) + 4.69041575982342955*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(45.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-20.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_neg3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-65.726706900619934*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(49.2950301754649502*pow(cosbetaovertwo,3) - 5.47722557505166113*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_neg2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(76.681158050723256*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-87.635609200826578*pow(cosbetaovertwo,4) + 16.4316767251549834*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_neg1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-72.746133917892846*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(121.243556529821411*pow(cosbetaovertwo,5) - 34.6410161513775459*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_0_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(56.124860801609121*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-134.69966592386189*pow(cosbetaovertwo,6) + 56.124860801609121*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-34.6410161513775459*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(121.243556529821411*pow(cosbetaovertwo,7) - 72.746133917892846*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(16.4316767251549834*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-87.635609200826578*pow(cosbetaovertwo,8) + 76.681158050723256*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.47722557505166113*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(49.2950301754649502*pow(cosbetaovertwo,9) - 65.726706900619934*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_6_4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-20.*pow(cosbetaovertwo,10) + 45.*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.69041575982342955*pow(cosbetaovertwo,11) - 23.4520787991171478*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_6_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2);
    return;
  }

  void D_6_neg6_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.46410161513775459*cosbetaovertwo*pow(sinbetaovertwo,11);
    return;
  }

  void D_6_neg5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(11.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(-23.4520787991171478*pow(cosbetaovertwo,3) + 4.69041575982342955*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(38.5356977359953871*pow(cosbetaovertwo,4) - 12.845232578665129*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-51.380930314660516*pow(cosbetaovertwo,5) + 25.690465157330258*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_neg1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(56.868268832451723*pow(cosbetaovertwo,6) - 40.6201920231798018*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_0_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-52.649786324352732*pow(cosbetaovertwo,7) + 52.649786324352732*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(40.6201920231798018*pow(cosbetaovertwo,8) - 56.868268832451723*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-25.690465157330258*pow(cosbetaovertwo,9) + 51.380930314660516*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(12.845232578665129*pow(cosbetaovertwo,10) - 38.5356977359953871*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.69041575982342955*pow(cosbetaovertwo,11) + 23.4520787991171478*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2));
    return;
  }

  void D_6_5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,12) - 11.*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2);
    return;
  }

  void D_6_6_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.46410161513775459*pow(cosbetaovertwo,11)*sinbetaovertwo;
    return;
  }

  void D_6_neg6_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,12);
    return;
  }

  void D_6_neg5_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.46410161513775459*cosbetaovertwo*pow(sinbetaovertwo,11);
    return;
  }

  void D_6_neg4_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,10);
    return;
  }

  void D_6_neg3_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -14.8323969741913259*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,9);
    return;
  }

  void D_6_neg2_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,8);
    return;
  }

  void D_6_neg1_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -28.1424945589405773*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,7);
    return;
  }

  void D_6_0_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 30.3973683071413273*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,6);
    return;
  }

  void D_6_1_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -28.1424945589405773*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,5);
    return;
  }

  void D_6_2_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,4);
    return;
  }

  void D_6_3_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -14.8323969741913259*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,3);
    return;
  }

  void D_6_4_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2);
    return;
  }

  void D_6_5_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.46410161513775459*pow(cosbetaovertwo,11)*sinbetaovertwo;
    return;
  }

  void D_6_6_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,12);
    return;
  }

  void D_7_neg7_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14);
    return;
  }

  void D_7_neg6_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.74165738677394139*pow(cosbetaovertwo,13)*sinbetaovertwo;
    return;
  }

  void D_7_neg5_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,2);
    return;
  }

  void D_7_neg4_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 19.078784028338913*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,3);
    return;
  }

  void D_7_neg3_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,4);
    return;
  }

  void D_7_neg2_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 44.7437146423941873*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,5);
    return;
  }

  void D_7_neg1_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,6);
    return;
  }

  void D_7_0_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 58.5832740635072393*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,7);
    return;
  }

  void D_7_1_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,8);
    return;
  }

  void D_7_2_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 44.7437146423941873*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,9);
    return;
  }

  void D_7_3_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,10);
    return;
  }

  void D_7_4_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 19.078784028338913*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,11);
    return;
  }

  void D_7_5_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,12);
    return;
  }

  void D_7_6_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.74165738677394139*cosbetaovertwo*pow(sinbetaovertwo,13);
    return;
  }

  void D_7_7_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,14);
    return;
  }

  void D_7_neg7_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.74165738677394139*pow(cosbetaovertwo,13)*sinbetaovertwo;
    return;
  }

  void D_7_neg6_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14) - 13.*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,2);
    return;
  }

  void D_7_neg5_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.09901951359278483*pow(cosbetaovertwo,13) - 30.594117081556709*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg4_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(15.2970585407783545*pow(cosbetaovertwo,12) - 56.089214649520633*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg3_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(33.8230690505755258*pow(cosbetaovertwo,11) - 84.557672626438814*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg2_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(59.79130371550699*pow(cosbetaovertwo,10) - 107.624346687912582*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg1_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(87.874911095260859*pow(cosbetaovertwo,9) - 117.166548127014479*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_0_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(109.599270070562058*pow(cosbetaovertwo,8) - 109.599270070562058*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_1_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(117.166548127014479*pow(cosbetaovertwo,7) - 87.874911095260859*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_2_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(107.624346687912582*pow(cosbetaovertwo,6) - 59.79130371550699*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_3_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(84.557672626438814*pow(cosbetaovertwo,5) - 33.8230690505755258*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_4_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(56.089214649520633*pow(cosbetaovertwo,4) - 15.2970585407783545*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_5_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,11)*(30.594117081556709*pow(cosbetaovertwo,3) - 5.0990195135927848*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_6_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,12)*(13.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_7_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.74165738677394139*cosbetaovertwo*pow(sinbetaovertwo,13);
    return;
  }

  void D_7_neg7_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,2);
    return;
  }

  void D_7_neg6_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.09901951359278483*pow(cosbetaovertwo,13) + 30.594117081556709*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-24.*pow(cosbetaovertwo,12) + 66.*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-66.*pow(cosbetaovertwo,11) + 110.*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(19.8997487421323991*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-132.664991614215994*pow(cosbetaovertwo,10) + 149.248115565992993*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(46.9041575982342955*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-211.06870919205433*pow(cosbetaovertwo,9) + 168.854967353643464*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(86.16843969807043*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-275.739007033825376*pow(cosbetaovertwo,8) + 160.847754103064802*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_0_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(128.965111561228062*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-300.918593642865479*pow(cosbetaovertwo,7) + 128.965111561228062*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(160.847754103064802*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-275.739007033825376*pow(cosbetaovertwo,6) + 86.16843969807043*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(168.854967353643464*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-211.06870919205433*pow(cosbetaovertwo,5) + 46.9041575982342955*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(149.248115565992993*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-132.664991614215994*pow(cosbetaovertwo,4) + 19.8997487421323991*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(110.*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-66.*pow(cosbetaovertwo,3) + 6.*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(66.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-24.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_6_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,11)*(30.594117081556709*pow(cosbetaovertwo,3) - 5.0990195135927848*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_7_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,12);
    return;
  }

  void D_7_neg7_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -19.078784028338913*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,3);
    return;
  }

  void D_7_neg6_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(15.2970585407783545*pow(cosbetaovertwo,12) - 56.089214649520633*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(66.*pow(cosbetaovertwo,11) - 110.*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-33.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(165.*pow(cosbetaovertwo,10) - 165.*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.6332495807107997*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-99.498743710661995*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(298.496231131985986*pow(cosbetaovertwo,9) - 198.997487421323991*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_neg2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(23.4520787991171478*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-211.06870919205433*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(422.13741838410866*pow(cosbetaovertwo,8) - 196.997461912584041*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_neg1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(57.445626465380287*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-344.67375879228172*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(482.543262309194407*pow(cosbetaovertwo,7) - 160.847754103064802*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_0_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(107.470926301023385*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-451.377890464298218*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(451.377890464298218*pow(cosbetaovertwo,6) - 107.470926301023385*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(160.847754103064802*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-482.543262309194407*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(344.67375879228172*pow(cosbetaovertwo,5) - 57.445626465380287*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(196.997461912584041*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-422.13741838410866*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(211.06870919205433*pow(cosbetaovertwo,4) - 23.4520787991171478*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(198.997487421323991*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-298.496231131985986*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(99.498743710661995*pow(cosbetaovertwo,3) - 6.6332495807107997*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(165.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-165.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(33.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(110.*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-66.*pow(cosbetaovertwo,3) + 6.*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_6_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(56.089214649520633*pow(cosbetaovertwo,4) - 15.2970585407783545*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_7_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 19.078784028338913*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,11);
    return;
  }

  void D_7_neg7_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,4);
    return;
  }

  void D_7_neg6_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-33.8230690505755258*pow(cosbetaovertwo,11) + 84.557672626438814*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(19.8997487421323991*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-132.664991614215994*pow(cosbetaovertwo,10) + 149.248115565992993*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.6332495807107997*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(99.498743710661995*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-298.496231131985986*pow(cosbetaovertwo,9) + 198.997487421323991*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_neg3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-40.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(270.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-480.*pow(cosbetaovertwo,8) + 210.*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_neg2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.0710678118654752*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-127.279220613578554*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(509.11688245431422*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-593.96969619669992*pow(cosbetaovertwo,7) + 178.190908859009976*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_neg1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(25.9807621135331594*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-277.128129211020367*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(727.46133917892846*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-581.96907134314277*pow(cosbetaovertwo,6) + 121.243556529821411*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_0_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(64.807406984078602*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-453.651848888550216*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(816.57332799939039*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-453.651848888550216*pow(cosbetaovertwo,5) + 64.807406984078602*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(121.243556529821411*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-581.96907134314277*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(727.46133917892846*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-277.128129211020367*pow(cosbetaovertwo,4) + 25.9807621135331594*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(178.190908859009976*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-593.96969619669992*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(509.11688245431422*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-127.279220613578554*pow(cosbetaovertwo,3) + 7.0710678118654752*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(210.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-480.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(270.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-40.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(198.997487421323991*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-298.496231131985986*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(99.498743710661995*pow(cosbetaovertwo,3) - 6.6332495807107997*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(149.248115565992993*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-132.664991614215994*pow(cosbetaovertwo,4) + 19.8997487421323991*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_6_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(84.557672626438814*pow(cosbetaovertwo,5) - 33.8230690505755258*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_7_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,10);
    return;
  }

  void D_7_neg7_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -44.7437146423941873*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,5);
    return;
  }

  void D_7_neg6_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(59.79130371550699*pow(cosbetaovertwo,10) - 107.624346687912582*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-46.9041575982342955*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(211.06870919205433*pow(cosbetaovertwo,9) - 168.854967353643464*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(23.4520787991171478*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-211.06870919205433*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(422.13741838410866*pow(cosbetaovertwo,8) - 196.997461912584041*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_neg3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.0710678118654752*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(127.279220613578554*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-509.11688245431422*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(593.96969619669992*pow(cosbetaovertwo,7) - 178.190908859009976*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-45.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(360.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-840.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(630.*pow(cosbetaovertwo,6) - 126.*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.3484692283495343*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-146.969384566990686*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(685.85712797928987*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1028.7856919689348*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(514.3928459844674*pow(cosbetaovertwo,5) - 68.585712797928987*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(27.49545416973504*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-320.7802986469088*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(962.3408959407264*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-962.3408959407264*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(320.7802986469088*pow(cosbetaovertwo,4) - 27.49545416973504*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(68.585712797928987*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-514.3928459844674*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1028.7856919689348*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-685.85712797928987*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(146.969384566990686*pow(cosbetaovertwo,3) - 7.3484692283495343*cosbetaovertwo*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(126.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-630.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(840.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-360.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(45.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(178.190908859009976*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-593.96969619669992*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(509.11688245431422*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-127.279220613578554*pow(cosbetaovertwo,3) + 7.0710678118654752*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(196.997461912584041*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-422.13741838410866*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(211.06870919205433*pow(cosbetaovertwo,4) - 23.4520787991171478*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(168.854967353643464*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-211.06870919205433*pow(cosbetaovertwo,5) + 46.9041575982342955*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_6_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(107.624346687912582*pow(cosbetaovertwo,6) - 59.79130371550699*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_7_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 44.7437146423941873*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,9);
    return;
  }

  void D_7_neg7_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,6);
    return;
  }

  void D_7_neg6_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-87.874911095260859*pow(cosbetaovertwo,9) + 117.166548127014479*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(86.16843969807043*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-275.739007033825376*pow(cosbetaovertwo,8) + 160.847754103064802*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-57.445626465380287*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(344.67375879228172*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-482.543262309194407*pow(cosbetaovertwo,7) + 160.847754103064802*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_neg3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(25.9807621135331594*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-277.128129211020367*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(727.46133917892846*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-581.96907134314277*pow(cosbetaovertwo,6) + 121.243556529821411*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.3484692283495343*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(146.969384566990686*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-685.85712797928987*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1028.7856919689348*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-514.3928459844674*pow(cosbetaovertwo,5) + 68.585712797928987*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-48.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(420.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1120.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(1050.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-336.*pow(cosbetaovertwo,4) + 28.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.48331477354788277*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-157.149610244505538*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(785.74805122252769*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1309.58008537087948*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(785.74805122252769*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-157.149610244505538*pow(cosbetaovertwo,3) + 7.48331477354788277*cosbetaovertwo*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_7_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(28.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-336.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(1050.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-1120.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(420.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-48.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_7_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(68.585712797928987*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-514.3928459844674*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1028.7856919689348*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-685.85712797928987*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(146.969384566990686*pow(cosbetaovertwo,3) - 7.3484692283495343*cosbetaovertwo*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(121.243556529821411*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-581.96907134314277*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(727.46133917892846*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-277.128129211020367*pow(cosbetaovertwo,4) + 25.9807621135331594*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(160.847754103064802*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-482.543262309194407*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(344.67375879228172*pow(cosbetaovertwo,5) - 57.445626465380287*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(160.847754103064802*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-275.739007033825376*pow(cosbetaovertwo,6) + 86.16843969807043*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_6_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(117.166548127014479*pow(cosbetaovertwo,7) - 87.874911095260859*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_7_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,8);
    return;
  }

  void D_7_neg7_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -58.5832740635072393*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,7);
    return;
  }

  void D_7_neg6_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(109.599270070562058*pow(cosbetaovertwo,8) - 109.599270070562058*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-128.965111561228062*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(300.918593642865479*pow(cosbetaovertwo,7) - 128.965111561228062*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(107.470926301023385*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-451.377890464298218*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(451.377890464298218*pow(cosbetaovertwo,6) - 107.470926301023385*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_neg3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-64.807406984078602*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(453.651848888550216*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-816.57332799939039*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(453.651848888550216*pow(cosbetaovertwo,5) - 64.807406984078602*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(27.49545416973504*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-320.7802986469088*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(962.3408959407264*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-962.3408959407264*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(320.7802986469088*pow(cosbetaovertwo,4) - 27.49545416973504*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.48331477354788277*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(157.149610244505538*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-785.74805122252769*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1309.58008537087948*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-785.74805122252769*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(157.149610244505538*pow(cosbetaovertwo,3) - 7.48331477354788277*cosbetaovertwo*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_7_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-49.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(441.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1225.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(1225.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-441.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(49.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_7_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.48331477354788277*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-157.149610244505538*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(785.74805122252769*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1309.58008537087948*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(785.74805122252769*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-157.149610244505538*pow(cosbetaovertwo,3) + 7.48331477354788277*cosbetaovertwo*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_7_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(27.49545416973504*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-320.7802986469088*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(962.3408959407264*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-962.3408959407264*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(320.7802986469088*pow(cosbetaovertwo,4) - 27.49545416973504*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(64.807406984078602*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-453.651848888550216*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(816.57332799939039*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-453.651848888550216*pow(cosbetaovertwo,5) + 64.807406984078602*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(107.470926301023385*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-451.377890464298218*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(451.377890464298218*pow(cosbetaovertwo,6) - 107.470926301023385*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(128.965111561228062*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-300.918593642865479*pow(cosbetaovertwo,7) + 128.965111561228062*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_6_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(109.599270070562058*pow(cosbetaovertwo,8) - 109.599270070562058*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_7_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 58.5832740635072393*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,7);
    return;
  }

  void D_7_neg7_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,8);
    return;
  }

  void D_7_neg6_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-117.166548127014479*pow(cosbetaovertwo,7) + 87.874911095260859*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(160.847754103064802*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-275.739007033825376*pow(cosbetaovertwo,6) + 86.16843969807043*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-160.847754103064802*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(482.543262309194407*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-344.67375879228172*pow(cosbetaovertwo,5) + 57.445626465380287*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_neg3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(121.243556529821411*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-581.96907134314277*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(727.46133917892846*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-277.128129211020367*pow(cosbetaovertwo,4) + 25.9807621135331594*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-68.585712797928987*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(514.3928459844674*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1028.7856919689348*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(685.85712797928987*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-146.969384566990686*pow(cosbetaovertwo,3) + 7.3484692283495343*cosbetaovertwo*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(28.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-336.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(1050.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-1120.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(420.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-48.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_7_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.48331477354788277*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(157.149610244505538*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-785.74805122252769*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1309.58008537087948*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-785.74805122252769*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(157.149610244505538*pow(cosbetaovertwo,3) - 7.48331477354788277*cosbetaovertwo*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_7_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-48.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(420.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1120.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(1050.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-336.*pow(cosbetaovertwo,4) + 28.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.3484692283495343*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-146.969384566990686*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(685.85712797928987*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1028.7856919689348*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(514.3928459844674*pow(cosbetaovertwo,5) - 68.585712797928987*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(25.9807621135331594*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-277.128129211020367*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(727.46133917892846*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-581.96907134314277*pow(cosbetaovertwo,6) + 121.243556529821411*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(57.445626465380287*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-344.67375879228172*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(482.543262309194407*pow(cosbetaovertwo,7) - 160.847754103064802*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(86.16843969807043*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-275.739007033825376*pow(cosbetaovertwo,8) + 160.847754103064802*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_6_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(87.874911095260859*pow(cosbetaovertwo,9) - 117.166548127014479*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_7_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,6);
    return;
  }

  void D_7_neg7_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -44.7437146423941873*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,9);
    return;
  }

  void D_7_neg6_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(107.624346687912582*pow(cosbetaovertwo,6) - 59.79130371550699*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-168.854967353643464*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(211.06870919205433*pow(cosbetaovertwo,5) - 46.9041575982342955*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(196.997461912584041*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-422.13741838410866*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(211.06870919205433*pow(cosbetaovertwo,4) - 23.4520787991171478*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_neg3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-178.190908859009976*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(593.96969619669992*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-509.11688245431422*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(127.279220613578554*pow(cosbetaovertwo,3) - 7.0710678118654752*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(126.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-630.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(840.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-360.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(45.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-68.585712797928987*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(514.3928459844674*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1028.7856919689348*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(685.85712797928987*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-146.969384566990686*pow(cosbetaovertwo,3) + 7.3484692283495343*cosbetaovertwo*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(27.49545416973504*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-320.7802986469088*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(962.3408959407264*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-962.3408959407264*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(320.7802986469088*pow(cosbetaovertwo,4) - 27.49545416973504*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.3484692283495343*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(146.969384566990686*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-685.85712797928987*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1028.7856919689348*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-514.3928459844674*pow(cosbetaovertwo,5) + 68.585712797928987*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_7_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-45.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(360.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-840.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(630.*pow(cosbetaovertwo,6) - 126.*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.0710678118654752*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-127.279220613578554*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(509.11688245431422*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-593.96969619669992*pow(cosbetaovertwo,7) + 178.190908859009976*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(23.4520787991171478*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-211.06870919205433*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(422.13741838410866*pow(cosbetaovertwo,8) - 196.997461912584041*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(46.9041575982342955*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-211.06870919205433*pow(cosbetaovertwo,9) + 168.854967353643464*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_6_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(59.79130371550699*pow(cosbetaovertwo,10) - 107.624346687912582*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_7_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 44.7437146423941873*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,5);
    return;
  }

  void D_7_neg7_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,10);
    return;
  }

  void D_7_neg6_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(-84.557672626438814*pow(cosbetaovertwo,5) + 33.8230690505755258*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(149.248115565992993*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-132.664991614215994*pow(cosbetaovertwo,4) + 19.8997487421323991*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-198.997487421323991*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(298.496231131985986*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-99.498743710661995*pow(cosbetaovertwo,3) + 6.6332495807107997*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_neg3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(210.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-480.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(270.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-40.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_neg2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-178.190908859009976*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(593.96969619669992*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-509.11688245431422*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(127.279220613578554*pow(cosbetaovertwo,3) - 7.0710678118654752*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_neg1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(121.243556529821411*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-581.96907134314277*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(727.46133917892846*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-277.128129211020367*pow(cosbetaovertwo,4) + 25.9807621135331594*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_0_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-64.807406984078602*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(453.651848888550216*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-816.57332799939039*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(453.651848888550216*pow(cosbetaovertwo,5) - 64.807406984078602*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(25.9807621135331594*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-277.128129211020367*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(727.46133917892846*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-581.96907134314277*pow(cosbetaovertwo,6) + 121.243556529821411*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.0710678118654752*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(127.279220613578554*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-509.11688245431422*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(593.96969619669992*pow(cosbetaovertwo,7) - 178.190908859009976*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_7_3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-40.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(270.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-480.*pow(cosbetaovertwo,8) + 210.*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.6332495807107997*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-99.498743710661995*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(298.496231131985986*pow(cosbetaovertwo,9) - 198.997487421323991*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(19.8997487421323991*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-132.664991614215994*pow(cosbetaovertwo,10) + 149.248115565992993*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_6_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(33.8230690505755258*pow(cosbetaovertwo,11) - 84.557672626438814*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_7_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,4);
    return;
  }

  void D_7_neg7_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -19.078784028338913*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,11);
    return;
  }

  void D_7_neg6_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(56.089214649520633*pow(cosbetaovertwo,4) - 15.2970585407783545*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(-110.*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(66.*pow(cosbetaovertwo,3) - 6.*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(165.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-165.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(33.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_neg3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-198.997487421323991*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(298.496231131985986*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-99.498743710661995*pow(cosbetaovertwo,3) + 6.6332495807107997*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_neg2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(196.997461912584041*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-422.13741838410866*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(211.06870919205433*pow(cosbetaovertwo,4) - 23.4520787991171478*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_neg1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-160.847754103064802*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(482.543262309194407*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-344.67375879228172*pow(cosbetaovertwo,5) + 57.445626465380287*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_0_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(107.470926301023385*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-451.377890464298218*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(451.377890464298218*pow(cosbetaovertwo,6) - 107.470926301023385*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-57.445626465380287*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(344.67375879228172*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-482.543262309194407*pow(cosbetaovertwo,7) + 160.847754103064802*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(23.4520787991171478*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-211.06870919205433*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(422.13741838410866*pow(cosbetaovertwo,8) - 196.997461912584041*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.6332495807107997*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(99.498743710661995*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-298.496231131985986*pow(cosbetaovertwo,9) + 198.997487421323991*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_7_4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-33.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(165.*pow(cosbetaovertwo,10) - 165.*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-66.*pow(cosbetaovertwo,11) + 110.*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_6_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(15.2970585407783545*pow(cosbetaovertwo,12) - 56.089214649520633*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_7_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 19.078784028338913*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,3);
    return;
  }

  void D_7_neg7_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,12);
    return;
  }

  void D_7_neg6_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,11)*(-30.594117081556709*pow(cosbetaovertwo,3) + 5.09901951359278483*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(66.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-24.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(-110.*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(66.*pow(cosbetaovertwo,3) - 6.*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(149.248115565992993*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-132.664991614215994*pow(cosbetaovertwo,4) + 19.8997487421323991*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-168.854967353643464*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(211.06870919205433*pow(cosbetaovertwo,5) - 46.9041575982342955*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_neg1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(160.847754103064802*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-275.739007033825376*pow(cosbetaovertwo,6) + 86.16843969807043*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_0_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-128.965111561228062*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(300.918593642865479*pow(cosbetaovertwo,7) - 128.965111561228062*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(86.16843969807043*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-275.739007033825376*pow(cosbetaovertwo,8) + 160.847754103064802*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-46.9041575982342955*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(211.06870919205433*pow(cosbetaovertwo,9) - 168.854967353643464*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(19.8997487421323991*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-132.664991614215994*pow(cosbetaovertwo,10) + 149.248115565992993*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(66.*pow(cosbetaovertwo,11) - 110.*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_7_5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-24.*pow(cosbetaovertwo,12) + 66.*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_6_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.09901951359278483*pow(cosbetaovertwo,13) - 30.594117081556709*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_7_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,2);
    return;
  }

  void D_7_neg7_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.74165738677394139*cosbetaovertwo*pow(sinbetaovertwo,13);
    return;
  }

  void D_7_neg6_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,12)*(13.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg5_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,11)*(-30.594117081556709*pow(cosbetaovertwo,3) + 5.09901951359278483*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg4_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(56.089214649520633*pow(cosbetaovertwo,4) - 15.2970585407783545*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg3_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(-84.557672626438814*pow(cosbetaovertwo,5) + 33.8230690505755258*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg2_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(107.624346687912582*pow(cosbetaovertwo,6) - 59.79130371550699*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_neg1_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-117.166548127014479*pow(cosbetaovertwo,7) + 87.874911095260859*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_0_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(109.599270070562058*pow(cosbetaovertwo,8) - 109.599270070562058*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_1_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-87.874911095260859*pow(cosbetaovertwo,9) + 117.166548127014479*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_2_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(59.79130371550699*pow(cosbetaovertwo,10) - 107.624346687912582*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_3_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-33.8230690505755258*pow(cosbetaovertwo,11) + 84.557672626438814*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_4_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(15.2970585407783545*pow(cosbetaovertwo,12) - 56.089214649520633*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_5_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.09901951359278483*pow(cosbetaovertwo,13) + 30.594117081556709*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,2));
    return;
  }

  void D_7_6_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14) - 13.*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,2);
    return;
  }

  void D_7_7_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.74165738677394139*pow(cosbetaovertwo,13)*sinbetaovertwo;
    return;
  }

  void D_7_neg7_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,14);
    return;
  }

  void D_7_neg6_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.74165738677394139*cosbetaovertwo*pow(sinbetaovertwo,13);
    return;
  }

  void D_7_neg5_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,12);
    return;
  }

  void D_7_neg4_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -19.078784028338913*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,11);
    return;
  }

  void D_7_neg3_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,10);
    return;
  }

  void D_7_neg2_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -44.7437146423941873*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,9);
    return;
  }

  void D_7_neg1_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,8);
    return;
  }

  void D_7_0_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -58.5832740635072393*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,7);
    return;
  }

  void D_7_1_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,6);
    return;
  }

  void D_7_2_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -44.7437146423941873*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,5);
    return;
  }

  void D_7_3_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,4);
    return;
  }

  void D_7_4_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -19.078784028338913*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,3);
    return;
  }

  void D_7_5_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,2);
    return;
  }

  void D_7_6_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.74165738677394139*pow(cosbetaovertwo,13)*sinbetaovertwo;
    return;
  }

  void D_7_7_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,14);
    return;
  }

  void D_8_neg8_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16);
    return;
  }

  void D_8_neg7_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 4.*pow(cosbetaovertwo,15)*sinbetaovertwo;
    return;
  }

  void D_8_neg6_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*pow(cosbetaovertwo,14)*pow(sinbetaovertwo,2);
    return;
  }

  void D_8_neg5_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 23.6643191323984642*pow(cosbetaovertwo,13)*pow(sinbetaovertwo,3);
    return;
  }

  void D_8_neg4_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,4);
    return;
  }

  void D_8_neg3_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 66.0908465674332242*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,5);
    return;
  }

  void D_8_neg2_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,6);
    return;
  }

  void D_8_neg1_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 106.957935656967501*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,7);
    return;
  }

  void D_8_0_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 113.446022407134222*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,8);
    return;
  }

  void D_8_1_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 106.957935656967501*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,9);
    return;
  }

  void D_8_2_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,10);
    return;
  }

  void D_8_3_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 66.0908465674332242*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,11);
    return;
  }

  void D_8_4_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,12);
    return;
  }

  void D_8_5_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 23.6643191323984642*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,13);
    return;
  }

  void D_8_6_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,14);
    return;
  }

  void D_8_7_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 4.*cosbetaovertwo*pow(sinbetaovertwo,15);
    return;
  }

  void D_8_8_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,16);
    return;
  }

  void D_8_neg8_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -4.*pow(cosbetaovertwo,15)*sinbetaovertwo;
    return;
  }

  void D_8_neg7_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) - 15.*pow(cosbetaovertwo,14)*pow(sinbetaovertwo,2);
    return;
  }

  void D_8_neg6_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.47722557505166113*pow(cosbetaovertwo,15) - 38.3405790253616279*pow(cosbetaovertwo,13)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg5_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(17.7482393492988481*pow(cosbetaovertwo,14) - 76.909037180295009*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg4_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(42.6614580154030835*pow(cosbetaovertwo,13) - 127.984374046209251*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg3_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(82.61355820929153*pow(cosbetaovertwo,12) - 181.749828060441367*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg2_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(134.231143927182562*pow(cosbetaovertwo,11) - 223.718573211970937*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg1_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(187.176387399693127*pow(cosbetaovertwo,10) - 240.655355228176878*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_0_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(226.892044814268444*pow(cosbetaovertwo,9) - 226.892044814268444*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_1_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(240.655355228176878*pow(cosbetaovertwo,8) - 187.176387399693127*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_2_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(223.718573211970937*pow(cosbetaovertwo,7) - 134.231143927182562*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_3_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(181.749828060441367*pow(cosbetaovertwo,6) - 82.61355820929153*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_4_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,11)*(127.984374046209251*pow(cosbetaovertwo,5) - 42.6614580154030835*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_5_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,12)*(76.909037180295009*pow(cosbetaovertwo,4) - 17.7482393492988481*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_6_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,13)*(38.3405790253616279*pow(cosbetaovertwo,3) - 5.4772255750516611*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_7_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,14)*(15.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 4.*cosbetaovertwo*pow(sinbetaovertwo,15);
    return;
  }

  void D_8_neg8_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*pow(cosbetaovertwo,14)*pow(sinbetaovertwo,2);
    return;
  }

  void D_8_neg7_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.47722557505166113*pow(cosbetaovertwo,15) + 38.3405790253616279*pow(cosbetaovertwo,13)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) + pow(sinbetaovertwo,2)*(-28.*pow(cosbetaovertwo,14) + 91.*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg5_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.48074069840786023*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(-84.249629079302183*pow(cosbetaovertwo,13) + 168.499258158604366*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg4_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(23.3666428910958452*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-186.933143128766762*pow(cosbetaovertwo,12) + 257.033071802054297*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg3_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(60.332412515993424*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-331.828268837963834*pow(cosbetaovertwo,11) + 331.828268837963834*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg2_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(122.535709081067467*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-490.142836324269866*pow(cosbetaovertwo,10) + 367.6071272432024*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg1_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(205.041459222275337*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-615.12437766682601*pow(cosbetaovertwo,9) + 351.499644381043436*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_0_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(289.972412480911708*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-662.79408567065533*pow(cosbetaovertwo,8) + 289.972412480911708*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_1_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(351.499644381043436*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-615.12437766682601*pow(cosbetaovertwo,7) + 205.041459222275337*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_2_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(367.6071272432024*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-490.142836324269866*pow(cosbetaovertwo,6) + 122.535709081067467*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_3_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(331.828268837963834*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-331.828268837963834*pow(cosbetaovertwo,5) + 60.332412515993424*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_4_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(257.033071802054297*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-186.933143128766762*pow(cosbetaovertwo,4) + 23.3666428910958452*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_5_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,11)*(168.499258158604366*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-84.249629079302183*pow(cosbetaovertwo,3) + 6.48074069840786023*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_6_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,12)*(91.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-28.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_7_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,13)*(38.3405790253616279*pow(cosbetaovertwo,3) - 5.4772255750516611*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,14);
    return;
  }

  void D_8_neg8_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -23.6643191323984642*pow(cosbetaovertwo,13)*pow(sinbetaovertwo,3);
    return;
  }

  void D_8_neg7_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(17.7482393492988481*pow(cosbetaovertwo,14) - 76.909037180295009*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.48074069840786023*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(84.249629079302183*pow(cosbetaovertwo,13) - 168.499258158604366*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) + pow(sinbetaovertwo,2)*(-39.*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(234.*pow(cosbetaovertwo,12) - 286.*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.21110255092797859*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(-129.799845916703615*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(475.932768361246587*pow(cosbetaovertwo,11) - 396.610640301038822*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(27.9284800875378823*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-307.213280962916706*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(768.03320240729176*pow(cosbetaovertwo,10) - 460.819921444375059*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(75.630681604756148*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-567.23011203567111*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(1021.014201664208*pow(cosbetaovertwo,9) - 453.784089628536888*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(158.192920195563746*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-854.24176905604423*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(1138.98902540805897*pow(cosbetaovertwo,8) - 379.66300846935299*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_0_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(268.462287854365124*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-1073.8491514174605*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1073.8491514174605*pow(cosbetaovertwo,7) - 268.462287854365124*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(379.66300846935299*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1138.98902540805897*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(854.24176905604423*pow(cosbetaovertwo,6) - 158.192920195563746*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(453.784089628536888*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1021.014201664208*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(567.23011203567111*pow(cosbetaovertwo,5) - 75.630681604756148*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(460.819921444375059*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-768.03320240729176*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(307.213280962916706*pow(cosbetaovertwo,4) - 27.9284800875378823*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(396.610640301038822*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-475.932768361246587*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(129.799845916703615*pow(cosbetaovertwo,3) - 7.2111025509279786*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(286.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-234.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(39.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_6_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,11)*(168.499258158604366*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-84.249629079302183*pow(cosbetaovertwo,3) + 6.48074069840786023*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_7_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,12)*(76.909037180295009*pow(cosbetaovertwo,4) - 17.7482393492988481*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 23.6643191323984642*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,13);
    return;
  }

  void D_8_neg8_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,4);
    return;
  }

  void D_8_neg7_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-42.6614580154030835*pow(cosbetaovertwo,13) + 127.984374046209251*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(23.3666428910958452*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-186.933143128766762*pow(cosbetaovertwo,12) + 257.033071802054297*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.21110255092797859*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(129.799845916703615*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-475.932768361246587*pow(cosbetaovertwo,11) + 396.610640301038822*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) + pow(sinbetaovertwo,2)*(-48.*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(396.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-880.*pow(cosbetaovertwo,10) + 495.*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.74596669241483377*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(-170.411267233126343*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(852.05633616563171*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-1278.08450424844757*pow(cosbetaovertwo,9) + 511.23380169937903*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_neg2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(31.4642654451045464*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-419.523539268060619*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(1415.89194502970459*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1510.28474136501823*pow(cosbetaovertwo,8) + 440.49971623146365*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_neg1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(87.749643873921221*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-789.74679486529099*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(1895.39230767669837*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1474.19401708187651*pow(cosbetaovertwo,7) + 315.898717946116394*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_0_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(186.145104689862849*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-1191.32867001512223*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(2084.82517252646391*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-1191.32867001512223*pow(cosbetaovertwo,6) + 186.145104689862849*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(315.898717946116394*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-1474.19401708187651*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1895.39230767669837*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-789.74679486529099*pow(cosbetaovertwo,5) + 87.749643873921221*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(440.49971623146365*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1510.28474136501823*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(1415.89194502970459*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-419.523539268060619*pow(cosbetaovertwo,4) + 31.4642654451045464*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(511.23380169937903*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1278.08450424844757*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(852.05633616563171*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-170.411267233126343*pow(cosbetaovertwo,3) + 7.74596669241483377*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(495.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-880.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(396.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-48.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(396.610640301038822*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-475.932768361246587*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(129.799845916703615*pow(cosbetaovertwo,3) - 7.2111025509279786*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_6_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(257.033071802054297*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-186.933143128766762*pow(cosbetaovertwo,4) + 23.3666428910958452*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_7_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,11)*(127.984374046209251*pow(cosbetaovertwo,5) - 42.6614580154030835*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,12);
    return;
  }

  void D_8_neg8_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -66.0908465674332242*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,5);
    return;
  }

  void D_8_neg7_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(82.61355820929153*pow(cosbetaovertwo,12) - 181.749828060441367*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-60.332412515993424*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(331.828268837963834*pow(cosbetaovertwo,11) - 331.828268837963834*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(27.9284800875378823*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-307.213280962916706*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(768.03320240729176*pow(cosbetaovertwo,10) - 460.819921444375059*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.74596669241483377*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(170.411267233126343*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-852.05633616563171*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(1278.08450424844757*pow(cosbetaovertwo,9) - 511.23380169937903*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_neg3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) + pow(sinbetaovertwo,2)*(-55.*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(550.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-1650.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(1650.*pow(cosbetaovertwo,8) - 462.*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_neg2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(8.12403840463596036*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(-203.100960115899009*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(1218.60576069539405*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-2437.21152139078811*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1706.04806497355168*pow(cosbetaovertwo,7) - 341.209612994710335*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_neg1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(33.9852909359328569*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-509.77936403899285*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(2039.11745615597141*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-2854.76443861835998*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(1427.38221930917999*pow(cosbetaovertwo,6) - 203.911745615597141*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_0_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(96.1249187255833262*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-961.24918725583326*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(2691.49772431633313*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-2691.49772431633313*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(961.24918725583326*pow(cosbetaovertwo,5) - 96.124918725583326*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(203.911745615597141*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-1427.38221930917999*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(2854.76443861835998*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-2039.11745615597141*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(509.77936403899285*pow(cosbetaovertwo,4) - 33.9852909359328569*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(341.209612994710335*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-1706.04806497355168*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(2437.21152139078811*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-1218.60576069539405*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(203.100960115899009*pow(cosbetaovertwo,3) - 8.1240384046359604*cosbetaovertwo*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(462.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1650.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(1650.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-550.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(55.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(511.23380169937903*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1278.08450424844757*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(852.05633616563171*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-170.411267233126343*pow(cosbetaovertwo,3) + 7.74596669241483377*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(460.819921444375059*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-768.03320240729176*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(307.213280962916706*pow(cosbetaovertwo,4) - 27.9284800875378823*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_6_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(331.828268837963834*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-331.828268837963834*pow(cosbetaovertwo,5) + 60.332412515993424*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_7_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(181.749828060441367*pow(cosbetaovertwo,6) - 82.61355820929153*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 66.0908465674332242*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,11);
    return;
  }

  void D_8_neg8_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,6);
    return;
  }

  void D_8_neg7_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-134.231143927182562*pow(cosbetaovertwo,11) + 223.718573211970937*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(122.535709081067467*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-490.142836324269866*pow(cosbetaovertwo,10) + 367.6071272432024*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-75.630681604756148*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(567.23011203567111*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-1021.014201664208*pow(cosbetaovertwo,9) + 453.784089628536888*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(31.4642654451045464*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-419.523539268060619*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(1415.89194502970459*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1510.28474136501823*pow(cosbetaovertwo,8) + 440.49971623146365*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_neg3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-8.12403840463596036*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(203.100960115899009*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-1218.60576069539405*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(2437.21152139078811*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1706.04806497355168*pow(cosbetaovertwo,7) + 341.209612994710335*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) + pow(sinbetaovertwo,2)*(-60.*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(675.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-2400.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(3150.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-1512.*pow(cosbetaovertwo,6) + 210.*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(8.36660026534075548*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(-225.898207164200398*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(1505.98804776133599*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-3513.9721114431173*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(3162.57490029880557*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-1054.19163343293519*pow(cosbetaovertwo,5) + 100.399203184089066*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(35.4964786985976963*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-567.94365917756314*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(2484.75350890183874*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-3975.60561424294198*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(2484.75350890183874*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-567.94365917756314*pow(cosbetaovertwo,4) + 35.4964786985976963*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(100.399203184089066*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-1054.19163343293519*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(3162.57490029880557*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-3513.9721114431173*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(1505.98804776133599*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-225.898207164200398*pow(cosbetaovertwo,3) + 8.36660026534075548*cosbetaovertwo*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(210.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-1512.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(3150.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-2400.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(675.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-60.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(341.209612994710335*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-1706.04806497355168*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(2437.21152139078811*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-1218.60576069539405*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(203.100960115899009*pow(cosbetaovertwo,3) - 8.1240384046359604*cosbetaovertwo*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(440.49971623146365*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1510.28474136501823*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(1415.89194502970459*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-419.523539268060619*pow(cosbetaovertwo,4) + 31.4642654451045464*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(453.784089628536888*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1021.014201664208*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(567.23011203567111*pow(cosbetaovertwo,5) - 75.630681604756148*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_6_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(367.6071272432024*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-490.142836324269866*pow(cosbetaovertwo,6) + 122.535709081067467*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_7_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(223.718573211970937*pow(cosbetaovertwo,7) - 134.231143927182562*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,10);
    return;
  }

  void D_8_neg8_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -106.957935656967501*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,7);
    return;
  }

  void D_8_neg7_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(187.176387399693127*pow(cosbetaovertwo,10) - 240.655355228176878*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-205.041459222275337*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(615.12437766682601*pow(cosbetaovertwo,9) - 351.499644381043436*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(158.192920195563746*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-854.24176905604423*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(1138.98902540805897*pow(cosbetaovertwo,8) - 379.66300846935299*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-87.749643873921221*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(789.74679486529099*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-1895.39230767669837*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1474.19401708187651*pow(cosbetaovertwo,7) - 315.898717946116394*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_neg3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(33.9852909359328569*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-509.77936403899285*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(2039.11745615597141*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-2854.76443861835998*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(1427.38221930917999*pow(cosbetaovertwo,6) - 203.911745615597141*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-8.36660026534075548*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(225.898207164200398*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-1505.98804776133599*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(3513.9721114431173*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-3162.57490029880557*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(1054.19163343293519*pow(cosbetaovertwo,5) - 100.399203184089066*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) + pow(sinbetaovertwo,2)*(-63.*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(756.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-2940.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(4410.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-2646.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(588.*pow(cosbetaovertwo,4) - 36.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(8.48528137423857029*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(-237.587878478679968*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(1663.11514935075978*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-4157.78787337689944*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(4157.78787337689944*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-1663.11514935075978*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(237.587878478679968*pow(cosbetaovertwo,3) - 8.4852813742385703*cosbetaovertwo*pow(sinbetaovertwo,2))))))));
    return;
  }

  void D_8_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(36.*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-588.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(2646.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-4410.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(2940.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-756.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(63.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))))))));
    return;
  }

  void D_8_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(100.399203184089066*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-1054.19163343293519*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(3162.57490029880557*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-3513.9721114431173*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(1505.98804776133599*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-225.898207164200398*pow(cosbetaovertwo,3) + 8.36660026534075548*cosbetaovertwo*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(203.911745615597141*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-1427.38221930917999*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(2854.76443861835998*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-2039.11745615597141*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(509.77936403899285*pow(cosbetaovertwo,4) - 33.9852909359328569*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(315.898717946116394*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-1474.19401708187651*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1895.39230767669837*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-789.74679486529099*pow(cosbetaovertwo,5) + 87.749643873921221*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(379.66300846935299*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1138.98902540805897*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(854.24176905604423*pow(cosbetaovertwo,6) - 158.192920195563746*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_6_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(351.499644381043436*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-615.12437766682601*pow(cosbetaovertwo,7) + 205.041459222275337*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_7_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(240.655355228176878*pow(cosbetaovertwo,8) - 187.176387399693127*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 106.957935656967501*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,9);
    return;
  }

  void D_8_neg8_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 113.446022407134222*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,8);
    return;
  }

  void D_8_neg7_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-226.892044814268444*pow(cosbetaovertwo,9) + 226.892044814268444*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(289.972412480911708*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-662.79408567065533*pow(cosbetaovertwo,8) + 289.972412480911708*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-268.462287854365124*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(1073.8491514174605*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1073.8491514174605*pow(cosbetaovertwo,7) + 268.462287854365124*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(186.145104689862849*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-1191.32867001512223*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(2084.82517252646391*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-1191.32867001512223*pow(cosbetaovertwo,6) + 186.145104689862849*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_neg3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-96.1249187255833262*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(961.24918725583326*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-2691.49772431633313*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(2691.49772431633313*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-961.24918725583326*pow(cosbetaovertwo,5) + 96.124918725583326*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(35.4964786985976963*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-567.94365917756314*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(2484.75350890183874*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-3975.60561424294198*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(2484.75350890183874*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-567.94365917756314*pow(cosbetaovertwo,4) + 35.4964786985976963*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-8.48528137423857029*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(237.587878478679968*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-1663.11514935075978*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(4157.78787337689944*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-4157.78787337689944*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(1663.11514935075978*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-237.587878478679968*pow(cosbetaovertwo,3) + 8.4852813742385703*cosbetaovertwo*pow(sinbetaovertwo,2))))))));
    return;
  }

  void D_8_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) + pow(sinbetaovertwo,2)*(-64.*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(784.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-3136.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(4900.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-3136.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(784.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-64.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2))))))));
    return;
  }

  void D_8_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(8.48528137423857029*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(-237.587878478679968*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(1663.11514935075978*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-4157.78787337689944*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(4157.78787337689944*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-1663.11514935075978*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(237.587878478679968*pow(cosbetaovertwo,3) - 8.4852813742385703*cosbetaovertwo*pow(sinbetaovertwo,2))))))));
    return;
  }

  void D_8_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(35.4964786985976963*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-567.94365917756314*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(2484.75350890183874*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-3975.60561424294198*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(2484.75350890183874*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-567.94365917756314*pow(cosbetaovertwo,4) + 35.4964786985976963*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(96.1249187255833262*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-961.24918725583326*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(2691.49772431633313*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-2691.49772431633313*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(961.24918725583326*pow(cosbetaovertwo,5) - 96.124918725583326*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(186.145104689862849*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-1191.32867001512223*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(2084.82517252646391*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-1191.32867001512223*pow(cosbetaovertwo,6) + 186.145104689862849*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(268.462287854365124*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-1073.8491514174605*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1073.8491514174605*pow(cosbetaovertwo,7) - 268.462287854365124*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_6_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(289.972412480911708*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-662.79408567065533*pow(cosbetaovertwo,8) + 289.972412480911708*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_7_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(226.892044814268444*pow(cosbetaovertwo,9) - 226.892044814268444*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 113.446022407134222*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,8);
    return;
  }

  void D_8_neg8_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -106.957935656967501*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,9);
    return;
  }

  void D_8_neg7_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(240.655355228176878*pow(cosbetaovertwo,8) - 187.176387399693127*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-351.499644381043436*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(615.12437766682601*pow(cosbetaovertwo,7) - 205.041459222275337*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(379.66300846935299*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1138.98902540805897*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(854.24176905604423*pow(cosbetaovertwo,6) - 158.192920195563746*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-315.898717946116394*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(1474.19401708187651*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1895.39230767669837*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(789.74679486529099*pow(cosbetaovertwo,5) - 87.749643873921221*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_neg3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(203.911745615597141*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-1427.38221930917999*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(2854.76443861835998*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-2039.11745615597141*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(509.77936403899285*pow(cosbetaovertwo,4) - 33.9852909359328569*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-100.399203184089066*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(1054.19163343293519*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-3162.57490029880557*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(3513.9721114431173*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-1505.98804776133599*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(225.898207164200398*pow(cosbetaovertwo,3) - 8.36660026534075548*cosbetaovertwo*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(36.*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-588.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(2646.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-4410.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(2940.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-756.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(63.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))))))));
    return;
  }

  void D_8_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-8.48528137423857029*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(237.587878478679968*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-1663.11514935075978*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(4157.78787337689944*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-4157.78787337689944*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(1663.11514935075978*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-237.587878478679968*pow(cosbetaovertwo,3) + 8.4852813742385703*cosbetaovertwo*pow(sinbetaovertwo,2))))))));
    return;
  }

  void D_8_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) + pow(sinbetaovertwo,2)*(-63.*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(756.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-2940.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(4410.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-2646.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(588.*pow(cosbetaovertwo,4) - 36.*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(8.36660026534075548*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(-225.898207164200398*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(1505.98804776133599*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-3513.9721114431173*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(3162.57490029880557*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-1054.19163343293519*pow(cosbetaovertwo,5) + 100.399203184089066*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(33.9852909359328569*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-509.77936403899285*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(2039.11745615597141*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-2854.76443861835998*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(1427.38221930917999*pow(cosbetaovertwo,6) - 203.911745615597141*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(87.749643873921221*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-789.74679486529099*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(1895.39230767669837*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1474.19401708187651*pow(cosbetaovertwo,7) + 315.898717946116394*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(158.192920195563746*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-854.24176905604423*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(1138.98902540805897*pow(cosbetaovertwo,8) - 379.66300846935299*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_6_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(205.041459222275337*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-615.12437766682601*pow(cosbetaovertwo,9) + 351.499644381043436*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_7_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(187.176387399693127*pow(cosbetaovertwo,10) - 240.655355228176878*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 106.957935656967501*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,7);
    return;
  }

  void D_8_neg8_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,10);
    return;
  }

  void D_8_neg7_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(-223.718573211970937*pow(cosbetaovertwo,7) + 134.231143927182562*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(367.6071272432024*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-490.142836324269866*pow(cosbetaovertwo,6) + 122.535709081067467*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-453.784089628536888*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1021.014201664208*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-567.23011203567111*pow(cosbetaovertwo,5) + 75.630681604756148*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(440.49971623146365*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1510.28474136501823*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(1415.89194502970459*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-419.523539268060619*pow(cosbetaovertwo,4) + 31.4642654451045464*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_neg3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-341.209612994710335*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(1706.04806497355168*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-2437.21152139078811*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(1218.60576069539405*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-203.100960115899009*pow(cosbetaovertwo,3) + 8.1240384046359604*cosbetaovertwo*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(210.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-1512.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(3150.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-2400.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(675.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-60.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-100.399203184089066*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(1054.19163343293519*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-3162.57490029880557*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(3513.9721114431173*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-1505.98804776133599*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(225.898207164200398*pow(cosbetaovertwo,3) - 8.36660026534075548*cosbetaovertwo*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(35.4964786985976963*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-567.94365917756314*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(2484.75350890183874*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-3975.60561424294198*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(2484.75350890183874*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-567.94365917756314*pow(cosbetaovertwo,4) + 35.4964786985976963*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-8.36660026534075548*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(225.898207164200398*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-1505.98804776133599*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(3513.9721114431173*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-3162.57490029880557*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(1054.19163343293519*pow(cosbetaovertwo,5) - 100.399203184089066*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))))));
    return;
  }

  void D_8_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) + pow(sinbetaovertwo,2)*(-60.*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(675.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-2400.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(3150.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-1512.*pow(cosbetaovertwo,6) + 210.*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(8.12403840463596036*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(-203.100960115899009*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(1218.60576069539405*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-2437.21152139078811*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1706.04806497355168*pow(cosbetaovertwo,7) - 341.209612994710335*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(31.4642654451045464*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-419.523539268060619*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(1415.89194502970459*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1510.28474136501823*pow(cosbetaovertwo,8) + 440.49971623146365*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(75.630681604756148*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-567.23011203567111*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(1021.014201664208*pow(cosbetaovertwo,9) - 453.784089628536888*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_6_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(122.535709081067467*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-490.142836324269866*pow(cosbetaovertwo,10) + 367.6071272432024*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_7_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(134.231143927182562*pow(cosbetaovertwo,11) - 223.718573211970937*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,6);
    return;
  }

  void D_8_neg8_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -66.0908465674332242*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,11);
    return;
  }

  void D_8_neg7_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(181.749828060441367*pow(cosbetaovertwo,6) - 82.61355820929153*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(-331.828268837963834*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(331.828268837963834*pow(cosbetaovertwo,5) - 60.332412515993424*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(460.819921444375059*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-768.03320240729176*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(307.213280962916706*pow(cosbetaovertwo,4) - 27.9284800875378823*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-511.23380169937903*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1278.08450424844757*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-852.05633616563171*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(170.411267233126343*pow(cosbetaovertwo,3) - 7.74596669241483377*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_neg3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(462.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1650.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(1650.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-550.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(55.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_neg2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-341.209612994710335*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(1706.04806497355168*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-2437.21152139078811*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(1218.60576069539405*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-203.100960115899009*pow(cosbetaovertwo,3) + 8.1240384046359604*cosbetaovertwo*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_neg1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(203.911745615597141*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-1427.38221930917999*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(2854.76443861835998*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-2039.11745615597141*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(509.77936403899285*pow(cosbetaovertwo,4) - 33.9852909359328569*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_0_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-96.1249187255833262*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(961.24918725583326*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-2691.49772431633313*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(2691.49772431633313*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-961.24918725583326*pow(cosbetaovertwo,5) + 96.124918725583326*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(33.9852909359328569*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-509.77936403899285*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(2039.11745615597141*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-2854.76443861835998*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(1427.38221930917999*pow(cosbetaovertwo,6) - 203.911745615597141*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-8.12403840463596036*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(203.100960115899009*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-1218.60576069539405*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(2437.21152139078811*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1706.04806497355168*pow(cosbetaovertwo,7) + 341.209612994710335*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))))));
    return;
  }

  void D_8_3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) + pow(sinbetaovertwo,2)*(-55.*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(550.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-1650.*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(1650.*pow(cosbetaovertwo,8) - 462.*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.74596669241483377*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(-170.411267233126343*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(852.05633616563171*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-1278.08450424844757*pow(cosbetaovertwo,9) + 511.23380169937903*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(27.9284800875378823*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-307.213280962916706*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(768.03320240729176*pow(cosbetaovertwo,10) - 460.819921444375059*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_6_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(60.332412515993424*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-331.828268837963834*pow(cosbetaovertwo,11) + 331.828268837963834*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_7_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(82.61355820929153*pow(cosbetaovertwo,12) - 181.749828060441367*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 66.0908465674332242*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,5);
    return;
  }

  void D_8_neg8_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,12);
    return;
  }

  void D_8_neg7_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,11)*(-127.984374046209251*pow(cosbetaovertwo,5) + 42.6614580154030835*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(257.033071802054297*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-186.933143128766762*pow(cosbetaovertwo,4) + 23.3666428910958452*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(-396.610640301038822*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(475.932768361246587*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-129.799845916703615*pow(cosbetaovertwo,3) + 7.21110255092797859*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(495.*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-880.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(396.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-48.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_neg3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-511.23380169937903*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1278.08450424844757*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-852.05633616563171*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(170.411267233126343*pow(cosbetaovertwo,3) - 7.74596669241483377*cosbetaovertwo*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_neg2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(440.49971623146365*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1510.28474136501823*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(1415.89194502970459*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-419.523539268060619*pow(cosbetaovertwo,4) + 31.4642654451045464*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_neg1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-315.898717946116394*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(1474.19401708187651*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1895.39230767669837*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(789.74679486529099*pow(cosbetaovertwo,5) - 87.749643873921221*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_0_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(186.145104689862849*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-1191.32867001512223*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(2084.82517252646391*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-1191.32867001512223*pow(cosbetaovertwo,6) + 186.145104689862849*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-87.749643873921221*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(789.74679486529099*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-1895.39230767669837*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1474.19401708187651*pow(cosbetaovertwo,7) - 315.898717946116394*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(31.4642654451045464*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-419.523539268060619*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(1415.89194502970459*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1510.28474136501823*pow(cosbetaovertwo,8) + 440.49971623146365*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.74596669241483377*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(170.411267233126343*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-852.05633616563171*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(1278.08450424844757*pow(cosbetaovertwo,9) - 511.23380169937903*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)))));
    return;
  }

  void D_8_4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) + pow(sinbetaovertwo,2)*(-48.*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(396.*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-880.*pow(cosbetaovertwo,10) + 495.*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.21110255092797859*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(-129.799845916703615*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(475.932768361246587*pow(cosbetaovertwo,11) - 396.610640301038822*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_6_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(23.3666428910958452*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-186.933143128766762*pow(cosbetaovertwo,12) + 257.033071802054297*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_7_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(42.6614580154030835*pow(cosbetaovertwo,13) - 127.984374046209251*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,4);
    return;
  }

  void D_8_neg8_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -23.6643191323984642*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,13);
    return;
  }

  void D_8_neg7_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,12)*(76.909037180295009*pow(cosbetaovertwo,4) - 17.7482393492988481*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,11)*(-168.499258158604366*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(84.249629079302183*pow(cosbetaovertwo,3) - 6.48074069840786023*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(286.*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-234.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(39.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(-396.610640301038822*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(475.932768361246587*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(-129.799845916703615*pow(cosbetaovertwo,3) + 7.21110255092797859*cosbetaovertwo*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(460.819921444375059*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-768.03320240729176*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(307.213280962916706*pow(cosbetaovertwo,4) - 27.9284800875378823*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-453.784089628536888*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(1021.014201664208*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(-567.23011203567111*pow(cosbetaovertwo,5) + 75.630681604756148*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_neg1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(379.66300846935299*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-1138.98902540805897*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(854.24176905604423*pow(cosbetaovertwo,6) - 158.192920195563746*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_0_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-268.462287854365124*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(1073.8491514174605*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(-1073.8491514174605*pow(cosbetaovertwo,7) + 268.462287854365124*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(158.192920195563746*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-854.24176905604423*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(1138.98902540805897*pow(cosbetaovertwo,8) - 379.66300846935299*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-75.630681604756148*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(567.23011203567111*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(-1021.014201664208*pow(cosbetaovertwo,9) + 453.784089628536888*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(27.9284800875378823*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-307.213280962916706*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(768.03320240729176*pow(cosbetaovertwo,10) - 460.819921444375059*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.21110255092797859*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(129.799845916703615*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(-475.932768361246587*pow(cosbetaovertwo,11) + 396.610640301038822*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2))));
    return;
  }

  void D_8_5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) + pow(sinbetaovertwo,2)*(-39.*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(234.*pow(cosbetaovertwo,12) - 286.*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_6_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.48074069840786023*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(-84.249629079302183*pow(cosbetaovertwo,13) + 168.499258158604366*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_7_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(17.7482393492988481*pow(cosbetaovertwo,14) - 76.909037180295009*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 23.6643191323984642*pow(cosbetaovertwo,13)*pow(sinbetaovertwo,3);
    return;
  }

  void D_8_neg8_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,14);
    return;
  }

  void D_8_neg7_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,13)*(-38.3405790253616279*pow(cosbetaovertwo,3) + 5.47722557505166113*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,12)*(91.*pow(cosbetaovertwo,4) + pow(sinbetaovertwo,2)*(-28.*pow(cosbetaovertwo,2) + pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg5_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,11)*(-168.499258158604366*pow(cosbetaovertwo,5) + pow(sinbetaovertwo,2)*(84.249629079302183*pow(cosbetaovertwo,3) - 6.48074069840786023*cosbetaovertwo*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg4_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(257.033071802054297*pow(cosbetaovertwo,6) + pow(sinbetaovertwo,2)*(-186.933143128766762*pow(cosbetaovertwo,4) + 23.3666428910958452*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg3_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(-331.828268837963834*pow(cosbetaovertwo,7) + pow(sinbetaovertwo,2)*(331.828268837963834*pow(cosbetaovertwo,5) - 60.332412515993424*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg2_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(367.6071272432024*pow(cosbetaovertwo,8) + pow(sinbetaovertwo,2)*(-490.142836324269866*pow(cosbetaovertwo,6) + 122.535709081067467*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_neg1_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-351.499644381043436*pow(cosbetaovertwo,9) + pow(sinbetaovertwo,2)*(615.12437766682601*pow(cosbetaovertwo,7) - 205.041459222275337*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_0_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(289.972412480911708*pow(cosbetaovertwo,10) + pow(sinbetaovertwo,2)*(-662.79408567065533*pow(cosbetaovertwo,8) + 289.972412480911708*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_1_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-205.041459222275337*pow(cosbetaovertwo,11) + pow(sinbetaovertwo,2)*(615.12437766682601*pow(cosbetaovertwo,9) - 351.499644381043436*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_2_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(122.535709081067467*pow(cosbetaovertwo,12) + pow(sinbetaovertwo,2)*(-490.142836324269866*pow(cosbetaovertwo,10) + 367.6071272432024*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_3_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-60.332412515993424*pow(cosbetaovertwo,13) + pow(sinbetaovertwo,2)*(331.828268837963834*pow(cosbetaovertwo,11) - 331.828268837963834*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_4_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(23.3666428910958452*pow(cosbetaovertwo,14) + pow(sinbetaovertwo,2)*(-186.933143128766762*pow(cosbetaovertwo,12) + 257.033071802054297*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_5_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.48074069840786023*pow(cosbetaovertwo,15) + pow(sinbetaovertwo,2)*(84.249629079302183*pow(cosbetaovertwo,13) - 168.499258158604366*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,2)));
    return;
  }

  void D_8_6_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) + pow(sinbetaovertwo,2)*(-28.*pow(cosbetaovertwo,14) + 91.*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_7_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.47722557505166113*pow(cosbetaovertwo,15) - 38.3405790253616279*pow(cosbetaovertwo,13)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_8_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*pow(cosbetaovertwo,14)*pow(sinbetaovertwo,2);
    return;
  }

  void D_8_neg8_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -4.*cosbetaovertwo*pow(sinbetaovertwo,15);
    return;
  }

  void D_8_neg7_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,14)*(15.*pow(cosbetaovertwo,2) - 1.*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg6_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,13)*(-38.3405790253616279*pow(cosbetaovertwo,3) + 5.47722557505166113*cosbetaovertwo*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg5_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,12)*(76.909037180295009*pow(cosbetaovertwo,4) - 17.7482393492988481*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg4_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,11)*(-127.984374046209251*pow(cosbetaovertwo,5) + 42.6614580154030835*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg3_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,10)*(181.749828060441367*pow(cosbetaovertwo,6) - 82.61355820929153*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg2_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,9)*(-223.718573211970937*pow(cosbetaovertwo,7) + 134.231143927182562*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_neg1_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,8)*(240.655355228176878*pow(cosbetaovertwo,8) - 187.176387399693127*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_0_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,7)*(-226.892044814268444*pow(cosbetaovertwo,9) + 226.892044814268444*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_1_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,6)*(187.176387399693127*pow(cosbetaovertwo,10) - 240.655355228176878*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_2_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,5)*(-134.231143927182562*pow(cosbetaovertwo,11) + 223.718573211970937*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_3_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,4)*(82.61355820929153*pow(cosbetaovertwo,12) - 181.749828060441367*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_4_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,3)*(-42.6614580154030835*pow(cosbetaovertwo,13) + 127.984374046209251*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_5_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,2)*(17.7482393492988481*pow(cosbetaovertwo,14) - 76.909037180295009*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_6_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.47722557505166113*pow(cosbetaovertwo,15) + 38.3405790253616279*pow(cosbetaovertwo,13)*pow(sinbetaovertwo,2));
    return;
  }

  void D_8_7_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16) - 15.*pow(cosbetaovertwo,14)*pow(sinbetaovertwo,2);
    return;
  }

  void D_8_8_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 4.*pow(cosbetaovertwo,15)*sinbetaovertwo;
    return;
  }

  void D_8_neg8_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(sinbetaovertwo,16);
    return;
  }

  void D_8_neg7_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -4.*cosbetaovertwo*pow(sinbetaovertwo,15);
    return;
  }

  void D_8_neg6_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*pow(cosbetaovertwo,2)*pow(sinbetaovertwo,14);
    return;
  }

  void D_8_neg5_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -23.6643191323984642*pow(cosbetaovertwo,3)*pow(sinbetaovertwo,13);
    return;
  }

  void D_8_neg4_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*pow(cosbetaovertwo,4)*pow(sinbetaovertwo,12);
    return;
  }

  void D_8_neg3_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -66.0908465674332242*pow(cosbetaovertwo,5)*pow(sinbetaovertwo,11);
    return;
  }

  void D_8_neg2_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*pow(cosbetaovertwo,6)*pow(sinbetaovertwo,10);
    return;
  }

  void D_8_neg1_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -106.957935656967501*pow(cosbetaovertwo,7)*pow(sinbetaovertwo,9);
    return;
  }

  void D_8_0_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 113.446022407134222*pow(cosbetaovertwo,8)*pow(sinbetaovertwo,8);
    return;
  }

  void D_8_1_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -106.957935656967501*pow(cosbetaovertwo,9)*pow(sinbetaovertwo,7);
    return;
  }

  void D_8_2_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*pow(cosbetaovertwo,10)*pow(sinbetaovertwo,6);
    return;
  }

  void D_8_3_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -66.0908465674332242*pow(cosbetaovertwo,11)*pow(sinbetaovertwo,5);
    return;
  }

  void D_8_4_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*pow(cosbetaovertwo,12)*pow(sinbetaovertwo,4);
    return;
  }

  void D_8_5_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -23.6643191323984642*pow(cosbetaovertwo,13)*pow(sinbetaovertwo,3);
    return;
  }

  void D_8_6_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*pow(cosbetaovertwo,14)*pow(sinbetaovertwo,2);
    return;
  }

  void D_8_7_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -4.*pow(cosbetaovertwo,15)*sinbetaovertwo;
    return;
  }

  void D_8_8_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = pow(cosbetaovertwo,16);
    return;
  }

}
