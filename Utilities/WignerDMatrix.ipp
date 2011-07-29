namespace WignerDMatrixLocal {
  
  void Uninitialized(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    std::cerr << "\nThis matrix has not yet been initialized with L,M,MP information." << std::endl;
    throw("Trying to use an uninitialized Wigner D matrix.");
  }
  
  void D_0_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 1.;
    return;
  }
  
  void D_1_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,2);
    return;
  }
  
  void D_1_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -1.41421356237309505*cosbetaovertwo*sinbetaovertwo;
    return;
  }
  
  void D_1_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2);
    return;
  }
  
  void D_1_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 1.41421356237309505*cosbetaovertwo*sinbetaovertwo;
    return;
  }
  
  void D_1_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_1_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -1.41421356237309505*cosbetaovertwo*sinbetaovertwo;
    return;
  }
  
  void D_1_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2);
    return;
  }
  
  void D_1_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 1.41421356237309505*cosbetaovertwo*sinbetaovertwo;
    return;
  }
  
  void D_1_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,2);
    return;
  }
  
  void D_2_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,4);
    return;
  }
  
  void D_2_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.*Power(cosbetaovertwo,3)*sinbetaovertwo;
    return;
  }
  
  void D_2_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_2_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.*cosbetaovertwo*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_2_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4);
    return;
  }
  
  void D_2_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.*Power(cosbetaovertwo,3)*sinbetaovertwo;
    return;
  }
  
  void D_2_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,4) - 3.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_2_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-2.4494897427831781*Power(cosbetaovertwo,3) + 2.4494897427831781*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_2_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(3.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_2_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.*cosbetaovertwo*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_2_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_2_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(2.4494897427831781*Power(cosbetaovertwo,3) - 2.4494897427831781*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_2_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-4.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2));
    return;
  }
  
  void D_2_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-2.4494897427831781*Power(cosbetaovertwo,3) + 2.4494897427831781*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_2_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_2_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.*cosbetaovertwo*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_2_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(3.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_2_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(2.4494897427831781*Power(cosbetaovertwo,3) - 2.4494897427831781*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_2_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,4) - 3.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_2_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.*Power(cosbetaovertwo,3)*sinbetaovertwo;
    return;
  }
  
  void D_2_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4);
    return;
  }
  
  void D_2_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.*cosbetaovertwo*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_2_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_2_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.*Power(cosbetaovertwo,3)*sinbetaovertwo;
    return;
  }
  
  void D_2_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,4);
    return;
  }
  
  void D_3_neg3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,6);
    return;
  }
  
  void D_3_neg2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.4494897427831781*Power(cosbetaovertwo,5)*sinbetaovertwo;
    return;
  }
  
  void D_3_neg1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_3_0_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -4.47213595499957939*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_3_1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_3_2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.4494897427831781*cosbetaovertwo*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_3_3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6);
    return;
  }
  
  void D_3_neg3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*Power(cosbetaovertwo,5)*sinbetaovertwo;
    return;
  }
  
  void D_3_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,6) - 5.*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_3_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-3.16227766016837933*Power(cosbetaovertwo,5) + 6.3245553203367587*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(5.47722557505166113*Power(cosbetaovertwo,4) - 5.4772255750516611*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-6.3245553203367587*Power(cosbetaovertwo,3) + 3.16227766016837933*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(5.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.4494897427831781*cosbetaovertwo*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_3_neg3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_3_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(3.16227766016837933*Power(cosbetaovertwo,5) - 6.3245553203367587*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-8.*Power(cosbetaovertwo,4) + 6.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-3.46410161513775459*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(10.3923048454132638*Power(cosbetaovertwo,3) - 3.46410161513775459*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_3_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(6.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-8.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_3_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-6.3245553203367587*Power(cosbetaovertwo,3) + 3.16227766016837933*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_3_neg3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 4.47213595499957939*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_3_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(5.47722557505166113*Power(cosbetaovertwo,4) - 5.4772255750516611*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(3.46410161513775459*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-10.3923048454132638*Power(cosbetaovertwo,3) + 3.46410161513775459*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_3_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-9.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(9.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_3_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-3.46410161513775459*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(10.3923048454132638*Power(cosbetaovertwo,3) - 3.46410161513775459*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_3_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(5.47722557505166113*Power(cosbetaovertwo,4) - 5.4772255750516611*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -4.47213595499957939*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_3_neg3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_3_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(6.3245553203367587*Power(cosbetaovertwo,3) - 3.16227766016837933*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(6.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-8.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_3_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(3.46410161513775459*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-10.3923048454132638*Power(cosbetaovertwo,3) + 3.46410161513775459*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_3_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-8.*Power(cosbetaovertwo,4) + 6.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-3.16227766016837933*Power(cosbetaovertwo,5) + 6.3245553203367587*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_3_neg3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*cosbetaovertwo*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_3_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(5.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(6.3245553203367587*Power(cosbetaovertwo,3) - 3.16227766016837933*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(5.47722557505166113*Power(cosbetaovertwo,4) - 5.4772255750516611*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(3.16227766016837933*Power(cosbetaovertwo,5) - 6.3245553203367587*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_3_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,6) - 5.*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_3_3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.4494897427831781*Power(cosbetaovertwo,5)*sinbetaovertwo;
    return;
  }
  
  void D_3_neg3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6);
    return;
  }
  
  void D_3_neg2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*cosbetaovertwo*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_3_neg1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_3_0_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 4.47213595499957939*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_3_1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.87298334620741689*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_3_2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.4494897427831781*Power(cosbetaovertwo,5)*sinbetaovertwo;
    return;
  }
  
  void D_3_3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,6);
    return;
  }
  
  void D_4_neg4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,8);
    return;
  }
  
  void D_4_neg3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.8284271247461901*Power(cosbetaovertwo,7)*sinbetaovertwo;
    return;
  }
  
  void D_4_neg2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_4_neg1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -7.48331477354788277*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_4_0_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.36660026534075548*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_4_1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -7.48331477354788277*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_4_2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_4_3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.8284271247461901*cosbetaovertwo*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_4_4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8);
    return;
  }
  
  void D_4_neg4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.8284271247461901*Power(cosbetaovertwo,7)*sinbetaovertwo;
    return;
  }
  
  void D_4_neg3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,8) - 7.*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_4_neg2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-3.74165738677394139*Power(cosbetaovertwo,7) + 11.2249721603218242*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_neg1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(7.9372539331937718*Power(cosbetaovertwo,6) - 13.228756555322953*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_0_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-11.8321595661992321*Power(cosbetaovertwo,5) + 11.8321595661992321*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(13.228756555322953*Power(cosbetaovertwo,4) - 7.9372539331937718*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-11.2249721603218242*Power(cosbetaovertwo,3) + 3.74165738677394139*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(7.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.8284271247461901*cosbetaovertwo*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_4_neg4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_4_neg3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(3.74165738677394139*Power(cosbetaovertwo,7) - 11.2249721603218242*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-12.*Power(cosbetaovertwo,6) + 15.*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.24264068711928515*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(21.2132034355964257*Power(cosbetaovertwo,5) - 14.1421356237309505*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(9.486832980505138*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-25.2982212813470347*Power(cosbetaovertwo,4) + 9.486832980505138*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-14.1421356237309505*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(21.2132034355964257*Power(cosbetaovertwo,3) - 4.24264068711928515*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(15.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-12.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-11.2249721603218242*Power(cosbetaovertwo,3) + 3.74165738677394139*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_4_neg4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 7.48331477354788277*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_4_neg3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(7.9372539331937718*Power(cosbetaovertwo,6) - 13.228756555322953*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.24264068711928515*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-21.2132034355964257*Power(cosbetaovertwo,5) + 14.1421356237309505*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-15.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(30.*Power(cosbetaovertwo,4) - 10.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.47213595499957939*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(26.8328157299974764*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-26.8328157299974764*Power(cosbetaovertwo,3) + 4.47213595499957939*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_4_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(10.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-30.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(15.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_4_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-14.1421356237309505*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(21.2132034355964257*Power(cosbetaovertwo,3) - 4.24264068711928515*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(13.228756555322953*Power(cosbetaovertwo,4) - 7.9372539331937718*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -7.48331477354788277*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_4_neg4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.36660026534075548*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_4_neg3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(11.8321595661992321*Power(cosbetaovertwo,5) - 11.8321595661992321*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(9.486832980505138*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-25.2982212813470347*Power(cosbetaovertwo,4) + 9.486832980505138*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.47213595499957939*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-26.8328157299974764*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(26.8328157299974764*Power(cosbetaovertwo,3) - 4.47213595499957939*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_4_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-16.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(36.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-16.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_4_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.47213595499957939*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(26.8328157299974764*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-26.8328157299974764*Power(cosbetaovertwo,3) + 4.47213595499957939*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_4_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(9.486832980505138*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-25.2982212813470347*Power(cosbetaovertwo,4) + 9.486832980505138*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-11.8321595661992321*Power(cosbetaovertwo,5) + 11.8321595661992321*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.36660026534075548*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_4_neg4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 7.48331477354788277*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_4_neg3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(13.228756555322953*Power(cosbetaovertwo,4) - 7.9372539331937718*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(14.1421356237309505*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-21.2132034355964257*Power(cosbetaovertwo,3) + 4.24264068711928515*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(10.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-30.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(15.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_4_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.47213595499957939*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-26.8328157299974764*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(26.8328157299974764*Power(cosbetaovertwo,3) - 4.47213595499957939*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_4_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-15.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(30.*Power(cosbetaovertwo,4) - 10.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.24264068711928515*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(21.2132034355964257*Power(cosbetaovertwo,5) - 14.1421356237309505*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(7.9372539331937718*Power(cosbetaovertwo,6) - 13.228756555322953*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -7.48331477354788277*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_4_neg4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_4_neg3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(11.2249721603218242*Power(cosbetaovertwo,3) - 3.74165738677394139*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(15.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-12.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(14.1421356237309505*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-21.2132034355964257*Power(cosbetaovertwo,3) + 4.24264068711928515*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(9.486832980505138*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-25.2982212813470347*Power(cosbetaovertwo,4) + 9.486832980505138*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.24264068711928515*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-21.2132034355964257*Power(cosbetaovertwo,5) + 14.1421356237309505*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_4_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-12.*Power(cosbetaovertwo,6) + 15.*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-3.74165738677394139*Power(cosbetaovertwo,7) + 11.2249721603218242*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_4_neg4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.8284271247461901*cosbetaovertwo*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_4_neg3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(7.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_neg2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(11.2249721603218242*Power(cosbetaovertwo,3) - 3.74165738677394139*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_neg1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(13.228756555322953*Power(cosbetaovertwo,4) - 7.9372539331937718*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_0_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(11.8321595661992321*Power(cosbetaovertwo,5) - 11.8321595661992321*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(7.9372539331937718*Power(cosbetaovertwo,6) - 13.228756555322953*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(3.74165738677394139*Power(cosbetaovertwo,7) - 11.2249721603218242*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_4_3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,8) - 7.*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_4_4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -2.8284271247461901*Power(cosbetaovertwo,7)*sinbetaovertwo;
    return;
  }
  
  void D_4_neg4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8);
    return;
  }
  
  void D_4_neg3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.8284271247461901*cosbetaovertwo*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_4_neg2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_4_neg1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 7.48331477354788277*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_4_0_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.36660026534075548*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_4_1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 7.48331477354788277*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_4_2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 5.29150262212918118*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_4_3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 2.8284271247461901*Power(cosbetaovertwo,7)*sinbetaovertwo;
    return;
  }
  
  void D_4_4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,8);
    return;
  }
  
  void D_5_neg5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,10);
    return;
  }
  
  void D_5_neg4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.16227766016837933*Power(cosbetaovertwo,9)*sinbetaovertwo;
    return;
  }
  
  void D_5_neg3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_5_neg2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -10.9544511501033223*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_5_neg1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_5_0_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -15.8745078663875435*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_5_1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_5_2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -10.9544511501033223*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_5_3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_5_4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.16227766016837933*cosbetaovertwo*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_5_5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10);
    return;
  }
  
  void D_5_neg5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.16227766016837933*Power(cosbetaovertwo,9)*sinbetaovertwo;
    return;
  }
  
  void D_5_neg4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,10) - 9.*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_5_neg3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.24264068711928515*Power(cosbetaovertwo,9) + 16.9705627484771406*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_neg2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(10.3923048454132638*Power(cosbetaovertwo,8) - 24.2487113059642821*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_neg1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-18.33030277982336*Power(cosbetaovertwo,7) + 27.49545416973504*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_0_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(25.0998007960222664*Power(cosbetaovertwo,6) - 25.0998007960222664*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-27.49545416973504*Power(cosbetaovertwo,5) + 18.33030277982336*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(24.2487113059642821*Power(cosbetaovertwo,4) - 10.3923048454132638*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-16.9705627484771406*Power(cosbetaovertwo,3) + 4.24264068711928515*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(9.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.16227766016837933*cosbetaovertwo*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_5_neg5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_5_neg4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.24264068711928515*Power(cosbetaovertwo,9) - 16.9705627484771406*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_neg3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-16.*Power(cosbetaovertwo,8) + 28.*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_neg2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.8989794855663562*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(34.2928563989644934*Power(cosbetaovertwo,7) - 34.2928563989644934*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_neg1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(12.9614813968157205*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-51.845925587262882*Power(cosbetaovertwo,6) + 32.4037034920393012*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_0_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-23.6643191323984642*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(59.16079783099616*Power(cosbetaovertwo,5) - 23.6643191323984642*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(32.4037034920393012*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-51.845925587262882*Power(cosbetaovertwo,4) + 12.9614813968157205*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-34.2928563989644934*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(34.2928563989644934*Power(cosbetaovertwo,3) - 4.8989794855663562*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(28.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-16.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-16.9705627484771406*Power(cosbetaovertwo,3) + 4.24264068711928515*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_5_neg5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_5_neg4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(10.3923048454132638*Power(cosbetaovertwo,8) - 24.2487113059642821*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_neg3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.8989794855663562*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-34.2928563989644934*Power(cosbetaovertwo,7) + 34.2928563989644934*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-21.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(63.*Power(cosbetaovertwo,6) - 35.*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.29150262212918118*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(47.6235235991626306*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-79.372539331937718*Power(cosbetaovertwo,5) + 26.4575131106459059*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(14.4913767461894386*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-72.456883730947193*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(72.456883730947193*Power(cosbetaovertwo,4) - 14.4913767461894386*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-26.4575131106459059*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(79.372539331937718*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-47.6235235991626306*Power(cosbetaovertwo,3) + 5.29150262212918118*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(35.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-63.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(21.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-34.2928563989644934*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(34.2928563989644934*Power(cosbetaovertwo,3) - 4.8989794855663562*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(24.2487113059642821*Power(cosbetaovertwo,4) - 10.3923048454132638*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -10.9544511501033223*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_5_neg5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_5_neg4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(18.33030277982336*Power(cosbetaovertwo,7) - 27.49545416973504*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_neg3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(12.9614813968157205*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-51.845925587262882*Power(cosbetaovertwo,6) + 32.4037034920393012*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.29150262212918118*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-47.6235235991626306*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(79.372539331937718*Power(cosbetaovertwo,5) - 26.4575131106459059*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-24.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(90.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-80.*Power(cosbetaovertwo,4) + 15.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.47722557505166113*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(54.772255750516611*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-109.544511501033223*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(54.772255750516611*Power(cosbetaovertwo,3) - 5.47722557505166113*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_5_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(15.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-80.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(90.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-24.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_5_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-26.4575131106459059*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(79.372539331937718*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-47.6235235991626306*Power(cosbetaovertwo,3) + 5.29150262212918118*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(32.4037034920393012*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-51.845925587262882*Power(cosbetaovertwo,4) + 12.9614813968157205*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-27.49545416973504*Power(cosbetaovertwo,5) + 18.33030277982336*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_5_neg5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 15.8745078663875435*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_5_neg4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(25.0998007960222664*Power(cosbetaovertwo,6) - 25.0998007960222664*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_neg3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(23.6643191323984642*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-59.16079783099616*Power(cosbetaovertwo,5) + 23.6643191323984642*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(14.4913767461894386*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-72.456883730947193*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(72.456883730947193*Power(cosbetaovertwo,4) - 14.4913767461894386*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.47722557505166113*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-54.772255750516611*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(109.544511501033223*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-54.772255750516611*Power(cosbetaovertwo,3) + 5.47722557505166113*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_5_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-25.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(100.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-100.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(25.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_5_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.47722557505166113*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(54.772255750516611*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-109.544511501033223*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(54.772255750516611*Power(cosbetaovertwo,3) - 5.47722557505166113*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_5_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(14.4913767461894386*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-72.456883730947193*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(72.456883730947193*Power(cosbetaovertwo,4) - 14.4913767461894386*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-23.6643191323984642*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(59.16079783099616*Power(cosbetaovertwo,5) - 23.6643191323984642*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(25.0998007960222664*Power(cosbetaovertwo,6) - 25.0998007960222664*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -15.8745078663875435*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_5_neg5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_5_neg4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(27.49545416973504*Power(cosbetaovertwo,5) - 18.33030277982336*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_neg3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(32.4037034920393012*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-51.845925587262882*Power(cosbetaovertwo,4) + 12.9614813968157205*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(26.4575131106459059*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-79.372539331937718*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(47.6235235991626306*Power(cosbetaovertwo,3) - 5.2915026221291812*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(15.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-80.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(90.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-24.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_5_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.47722557505166113*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-54.772255750516611*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(109.544511501033223*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-54.772255750516611*Power(cosbetaovertwo,3) + 5.47722557505166113*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_5_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-24.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(90.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-80.*Power(cosbetaovertwo,4) + 15.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.29150262212918118*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(47.6235235991626306*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-79.372539331937718*Power(cosbetaovertwo,5) + 26.4575131106459059*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(12.9614813968157205*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-51.845925587262882*Power(cosbetaovertwo,6) + 32.4037034920393012*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-18.33030277982336*Power(cosbetaovertwo,7) + 27.49545416973504*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_5_neg5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_5_neg4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(24.2487113059642821*Power(cosbetaovertwo,4) - 10.3923048454132638*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_neg3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(34.2928563989644934*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-34.2928563989644934*Power(cosbetaovertwo,3) + 4.8989794855663562*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(35.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-63.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(21.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(26.4575131106459059*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-79.372539331937718*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(47.6235235991626306*Power(cosbetaovertwo,3) - 5.2915026221291812*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(14.4913767461894386*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-72.456883730947193*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(72.456883730947193*Power(cosbetaovertwo,4) - 14.4913767461894386*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.29150262212918118*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-47.6235235991626306*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(79.372539331937718*Power(cosbetaovertwo,5) - 26.4575131106459059*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_5_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-21.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(63.*Power(cosbetaovertwo,6) - 35.*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.8989794855663562*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(34.2928563989644934*Power(cosbetaovertwo,7) - 34.2928563989644934*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(10.3923048454132638*Power(cosbetaovertwo,8) - 24.2487113059642821*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -10.9544511501033223*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_5_neg5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_5_neg4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(16.9705627484771406*Power(cosbetaovertwo,3) - 4.24264068711928515*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_neg3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(28.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-16.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_neg2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(34.2928563989644934*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-34.2928563989644934*Power(cosbetaovertwo,3) + 4.8989794855663562*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_neg1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(32.4037034920393012*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-51.845925587262882*Power(cosbetaovertwo,4) + 12.9614813968157205*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_0_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(23.6643191323984642*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-59.16079783099616*Power(cosbetaovertwo,5) + 23.6643191323984642*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(12.9614813968157205*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-51.845925587262882*Power(cosbetaovertwo,6) + 32.4037034920393012*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.8989794855663562*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-34.2928563989644934*Power(cosbetaovertwo,7) + 34.2928563989644934*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_5_3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-16.*Power(cosbetaovertwo,8) + 28.*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.24264068711928515*Power(cosbetaovertwo,9) + 16.9705627484771406*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_5_neg5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.16227766016837933*cosbetaovertwo*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_5_neg4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(9.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_neg3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(16.9705627484771406*Power(cosbetaovertwo,3) - 4.24264068711928515*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_neg2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(24.2487113059642821*Power(cosbetaovertwo,4) - 10.3923048454132638*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_neg1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(27.49545416973504*Power(cosbetaovertwo,5) - 18.33030277982336*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_0_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(25.0998007960222664*Power(cosbetaovertwo,6) - 25.0998007960222664*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(18.33030277982336*Power(cosbetaovertwo,7) - 27.49545416973504*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(10.3923048454132638*Power(cosbetaovertwo,8) - 24.2487113059642821*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.24264068711928515*Power(cosbetaovertwo,9) - 16.9705627484771406*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_5_4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,10) - 9.*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_5_5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.16227766016837933*Power(cosbetaovertwo,9)*sinbetaovertwo;
    return;
  }
  
  void D_5_neg5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10);
    return;
  }
  
  void D_5_neg4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.16227766016837933*cosbetaovertwo*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_5_neg3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_5_neg2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_5_neg1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_5_0_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 15.8745078663875435*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_5_1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.4913767461894386*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_5_2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_5_3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 6.70820393249936909*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_5_4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.16227766016837933*Power(cosbetaovertwo,9)*sinbetaovertwo;
    return;
  }
  
  void D_5_5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,10);
    return;
  }
  
  void D_6_neg6_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,12);
    return;
  }
  
  void D_6_neg5_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.46410161513775459*Power(cosbetaovertwo,11)*sinbetaovertwo;
    return;
  }
  
  void D_6_neg4_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_6_neg3_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -14.8323969741913259*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_6_neg2_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_6_neg1_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -28.1424945589405773*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_6_0_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 30.3973683071413273*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_6_1_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -28.1424945589405773*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_6_2_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_6_3_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -14.8323969741913259*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_6_4_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,10);
    return;
  }
  
  void D_6_5_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.46410161513775459*cosbetaovertwo*Power(sinbetaovertwo,11);
    return;
  }
  
  void D_6_6_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,12);
    return;
  }
  
  void D_6_neg6_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.46410161513775459*Power(cosbetaovertwo,11)*sinbetaovertwo;
    return;
  }
  
  void D_6_neg5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,12) - 11.*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_6_neg4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.69041575982342955*Power(cosbetaovertwo,11) + 23.4520787991171478*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(12.845232578665129*Power(cosbetaovertwo,10) - 38.5356977359953871*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-25.690465157330258*Power(cosbetaovertwo,9) + 51.380930314660516*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(40.6201920231798018*Power(cosbetaovertwo,8) - 56.868268832451723*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_0_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-52.649786324352732*Power(cosbetaovertwo,7) + 52.649786324352732*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(56.868268832451723*Power(cosbetaovertwo,6) - 40.6201920231798018*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-51.380930314660516*Power(cosbetaovertwo,5) + 25.690465157330258*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(38.5356977359953871*Power(cosbetaovertwo,4) - 12.845232578665129*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(-23.4520787991171478*Power(cosbetaovertwo,3) + 4.69041575982342955*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(11.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_6_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.46410161513775459*cosbetaovertwo*Power(sinbetaovertwo,11);
    return;
  }
  
  void D_6_neg6_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_6_neg5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.69041575982342955*Power(cosbetaovertwo,11) - 23.4520787991171478*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-20.*Power(cosbetaovertwo,10) + 45.*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.47722557505166113*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(49.2950301754649502*Power(cosbetaovertwo,9) - 65.726706900619934*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_neg2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(16.4316767251549834*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-87.635609200826578*Power(cosbetaovertwo,8) + 76.681158050723256*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_neg1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-34.6410161513775459*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(121.243556529821411*Power(cosbetaovertwo,7) - 72.746133917892846*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_0_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(56.124860801609121*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-134.69966592386189*Power(cosbetaovertwo,6) + 56.124860801609121*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-72.746133917892846*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(121.243556529821411*Power(cosbetaovertwo,5) - 34.6410161513775459*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(76.681158050723256*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-87.635609200826578*Power(cosbetaovertwo,4) + 16.4316767251549834*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-65.726706900619934*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(49.2950301754649502*Power(cosbetaovertwo,3) - 5.47722557505166113*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(45.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-20.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(-23.4520787991171478*Power(cosbetaovertwo,3) + 4.69041575982342955*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_6_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,10);
    return;
  }
  
  void D_6_neg6_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.8323969741913259*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_6_neg5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(12.845232578665129*Power(cosbetaovertwo,10) - 38.5356977359953871*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.47722557505166113*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-49.2950301754649502*Power(cosbetaovertwo,9) + 65.726706900619934*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_neg3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-27.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(108.*Power(cosbetaovertwo,8) - 84.*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_neg2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(72.*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-168.*Power(cosbetaovertwo,7) + 84.*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_neg1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(18.973665961010276*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-132.815661727071932*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(199.223492590607898*Power(cosbetaovertwo,6) - 66.407830863535966*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_0_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-40.9878030638383935*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(184.445113787272771*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-184.445113787272771*Power(cosbetaovertwo,5) + 40.9878030638383935*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(66.407830863535966*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-199.223492590607898*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(132.815661727071932*Power(cosbetaovertwo,4) - 18.973665961010276*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-84.*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(168.*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-72.*Power(cosbetaovertwo,3) + 6.*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(84.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-108.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(27.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-65.726706900619934*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(49.2950301754649502*Power(cosbetaovertwo,3) - 5.47722557505166113*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(38.5356977359953871*Power(cosbetaovertwo,4) - 12.845232578665129*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_6_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -14.8323969741913259*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_6_neg6_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_6_neg5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(25.690465157330258*Power(cosbetaovertwo,9) - 51.380930314660516*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(16.4316767251549834*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-87.635609200826578*Power(cosbetaovertwo,8) + 76.681158050723256*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_neg3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-72.*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(168.*Power(cosbetaovertwo,7) - 84.*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-32.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(168.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-224.*Power(cosbetaovertwo,6) + 70.*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.32455532033675866*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(88.543774484714621*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-265.631323454143864*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(221.359436211786553*Power(cosbetaovertwo,5) - 44.2718872423573106*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(20.4939015319191968*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-163.951212255353574*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(307.408522978787951*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-163.951212255353574*Power(cosbetaovertwo,4) + 20.4939015319191968*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-44.2718872423573106*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(221.359436211786553*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-265.631323454143864*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(88.543774484714621*Power(cosbetaovertwo,3) - 6.32455532033675866*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(70.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-224.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(168.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-32.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-84.*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(168.*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-72.*Power(cosbetaovertwo,3) + 6.*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(76.681158050723256*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-87.635609200826578*Power(cosbetaovertwo,4) + 16.4316767251549834*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-51.380930314660516*Power(cosbetaovertwo,5) + 25.690465157330258*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_6_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_6_neg6_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 28.1424945589405773*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_6_neg5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(40.6201920231798018*Power(cosbetaovertwo,8) - 56.868268832451723*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(34.6410161513775459*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-121.243556529821411*Power(cosbetaovertwo,7) + 72.746133917892846*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_neg3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(18.973665961010276*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-132.815661727071932*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(199.223492590607898*Power(cosbetaovertwo,6) - 66.407830863535966*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.32455532033675866*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-88.543774484714621*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(265.631323454143864*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-221.359436211786553*Power(cosbetaovertwo,5) + 44.2718872423573106*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-35.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(210.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-350.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(175.*Power(cosbetaovertwo,4) - 21.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.4807406984078602*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(97.211110476117903*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-324.037034920393012*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(324.037034920393012*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-97.211110476117903*Power(cosbetaovertwo,3) + 6.48074069840786023*cosbetaovertwo*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_6_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(21.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-175.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(350.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-210.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(35.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_6_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-44.2718872423573106*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(221.359436211786553*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-265.631323454143864*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(88.543774484714621*Power(cosbetaovertwo,3) - 6.32455532033675866*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(66.407830863535966*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-199.223492590607898*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(132.815661727071932*Power(cosbetaovertwo,4) - 18.973665961010276*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-72.746133917892846*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(121.243556529821411*Power(cosbetaovertwo,5) - 34.6410161513775459*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(56.868268832451723*Power(cosbetaovertwo,6) - 40.6201920231798018*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_6_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -28.1424945589405773*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_6_neg6_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 30.3973683071413273*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_6_neg5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(52.6497863243527324*Power(cosbetaovertwo,7) - 52.649786324352732*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(56.124860801609121*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-134.69966592386189*Power(cosbetaovertwo,6) + 56.124860801609121*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_neg3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(40.9878030638383935*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-184.445113787272771*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(184.445113787272771*Power(cosbetaovertwo,5) - 40.9878030638383935*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(20.4939015319191968*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-163.951212255353574*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(307.408522978787951*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-163.951212255353574*Power(cosbetaovertwo,4) + 20.4939015319191968*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.48074069840786023*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-97.211110476117903*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(324.037034920393012*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-324.037034920393012*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(97.211110476117903*Power(cosbetaovertwo,3) - 6.4807406984078602*cosbetaovertwo*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_6_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-36.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(225.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-400.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(225.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-36.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_6_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.48074069840786023*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(97.211110476117903*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-324.037034920393012*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(324.037034920393012*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-97.211110476117903*Power(cosbetaovertwo,3) + 6.4807406984078602*cosbetaovertwo*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_6_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(20.4939015319191968*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-163.951212255353574*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(307.408522978787951*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-163.951212255353574*Power(cosbetaovertwo,4) + 20.4939015319191968*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-40.9878030638383935*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(184.445113787272771*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-184.445113787272771*Power(cosbetaovertwo,5) + 40.9878030638383935*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(56.124860801609121*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-134.69966592386189*Power(cosbetaovertwo,6) + 56.124860801609121*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-52.649786324352732*Power(cosbetaovertwo,7) + 52.6497863243527324*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_6_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 30.3973683071413273*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_6_neg6_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 28.1424945589405773*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_6_neg5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(56.868268832451723*Power(cosbetaovertwo,6) - 40.6201920231798018*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(72.746133917892846*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-121.243556529821411*Power(cosbetaovertwo,5) + 34.6410161513775459*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_neg3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(66.407830863535966*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-199.223492590607898*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(132.815661727071932*Power(cosbetaovertwo,4) - 18.973665961010276*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(44.2718872423573106*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-221.359436211786553*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(265.631323454143864*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-88.543774484714621*Power(cosbetaovertwo,3) + 6.32455532033675866*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(21.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-175.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(350.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-210.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(35.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_6_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.48074069840786023*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-97.211110476117903*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(324.037034920393012*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-324.037034920393012*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(97.211110476117903*Power(cosbetaovertwo,3) - 6.4807406984078602*cosbetaovertwo*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_6_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-35.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(210.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-350.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(175.*Power(cosbetaovertwo,4) - 21.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.32455532033675866*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(88.543774484714621*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-265.631323454143864*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(221.359436211786553*Power(cosbetaovertwo,5) - 44.2718872423573106*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(18.973665961010276*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-132.815661727071932*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(199.223492590607898*Power(cosbetaovertwo,6) - 66.407830863535966*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-34.6410161513775459*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(121.243556529821411*Power(cosbetaovertwo,7) - 72.746133917892846*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(40.6201920231798018*Power(cosbetaovertwo,8) - 56.868268832451723*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_6_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -28.1424945589405773*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_6_neg6_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_6_neg5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(51.380930314660516*Power(cosbetaovertwo,5) - 25.690465157330258*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(76.681158050723256*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-87.635609200826578*Power(cosbetaovertwo,4) + 16.4316767251549834*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_neg3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(84.*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-168.*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(72.*Power(cosbetaovertwo,3) - 6.*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(70.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-224.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(168.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-32.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(44.2718872423573106*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-221.359436211786553*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(265.631323454143864*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-88.543774484714621*Power(cosbetaovertwo,3) + 6.32455532033675866*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(20.4939015319191968*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-163.951212255353574*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(307.408522978787951*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-163.951212255353574*Power(cosbetaovertwo,4) + 20.4939015319191968*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.32455532033675866*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-88.543774484714621*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(265.631323454143864*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-221.359436211786553*Power(cosbetaovertwo,5) + 44.2718872423573106*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_6_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-32.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(168.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-224.*Power(cosbetaovertwo,6) + 70.*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(72.*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-168.*Power(cosbetaovertwo,7) + 84.*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(16.4316767251549834*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-87.635609200826578*Power(cosbetaovertwo,8) + 76.681158050723256*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-25.690465157330258*Power(cosbetaovertwo,9) + 51.380930314660516*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_6_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_6_neg6_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.8323969741913259*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_6_neg5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(38.5356977359953871*Power(cosbetaovertwo,4) - 12.845232578665129*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(65.726706900619934*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-49.2950301754649502*Power(cosbetaovertwo,3) + 5.47722557505166113*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_neg3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(84.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-108.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(27.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_neg2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(84.*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-168.*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(72.*Power(cosbetaovertwo,3) - 6.*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_neg1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(66.407830863535966*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-199.223492590607898*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(132.815661727071932*Power(cosbetaovertwo,4) - 18.973665961010276*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_0_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(40.9878030638383935*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-184.445113787272771*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(184.445113787272771*Power(cosbetaovertwo,5) - 40.9878030638383935*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(18.973665961010276*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-132.815661727071932*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(199.223492590607898*Power(cosbetaovertwo,6) - 66.407830863535966*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-72.*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(168.*Power(cosbetaovertwo,7) - 84.*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_6_3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-27.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(108.*Power(cosbetaovertwo,8) - 84.*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.47722557505166113*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(49.2950301754649502*Power(cosbetaovertwo,9) - 65.726706900619934*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(12.845232578665129*Power(cosbetaovertwo,10) - 38.5356977359953871*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_6_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -14.8323969741913259*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_6_neg6_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,10);
    return;
  }
  
  void D_6_neg5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(23.4520787991171478*Power(cosbetaovertwo,3) - 4.69041575982342955*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(45.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-20.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_neg3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(65.726706900619934*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-49.2950301754649502*Power(cosbetaovertwo,3) + 5.47722557505166113*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_neg2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(76.681158050723256*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-87.635609200826578*Power(cosbetaovertwo,4) + 16.4316767251549834*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_neg1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(72.746133917892846*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-121.243556529821411*Power(cosbetaovertwo,5) + 34.6410161513775459*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_0_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(56.124860801609121*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-134.69966592386189*Power(cosbetaovertwo,6) + 56.124860801609121*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(34.6410161513775459*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-121.243556529821411*Power(cosbetaovertwo,7) + 72.746133917892846*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(16.4316767251549834*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-87.635609200826578*Power(cosbetaovertwo,8) + 76.681158050723256*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.47722557505166113*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-49.2950301754649502*Power(cosbetaovertwo,9) + 65.726706900619934*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_6_4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-20.*Power(cosbetaovertwo,10) + 45.*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-4.69041575982342955*Power(cosbetaovertwo,11) + 23.4520787991171478*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_6_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_6_neg6_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.46410161513775459*cosbetaovertwo*Power(sinbetaovertwo,11);
    return;
  }
  
  void D_6_neg5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(11.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(23.4520787991171478*Power(cosbetaovertwo,3) - 4.69041575982342955*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(38.5356977359953871*Power(cosbetaovertwo,4) - 12.845232578665129*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(51.380930314660516*Power(cosbetaovertwo,5) - 25.690465157330258*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_neg1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(56.868268832451723*Power(cosbetaovertwo,6) - 40.6201920231798018*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_0_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(52.6497863243527324*Power(cosbetaovertwo,7) - 52.649786324352732*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(40.6201920231798018*Power(cosbetaovertwo,8) - 56.868268832451723*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(25.690465157330258*Power(cosbetaovertwo,9) - 51.380930314660516*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(12.845232578665129*Power(cosbetaovertwo,10) - 38.5356977359953871*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(4.69041575982342955*Power(cosbetaovertwo,11) - 23.4520787991171478*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_6_5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,12) - 11.*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_6_6_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.46410161513775459*Power(cosbetaovertwo,11)*sinbetaovertwo;
    return;
  }
  
  void D_6_neg6_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,12);
    return;
  }
  
  void D_6_neg5_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.46410161513775459*cosbetaovertwo*Power(sinbetaovertwo,11);
    return;
  }
  
  void D_6_neg4_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,10);
    return;
  }
  
  void D_6_neg3_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.8323969741913259*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_6_neg2_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_6_neg1_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 28.1424945589405773*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_6_0_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 30.3973683071413273*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_6_1_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 28.1424945589405773*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_6_2_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 22.2485954612869888*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_6_3_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 14.8323969741913259*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_6_4_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 8.12403840463596036*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_6_5_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.46410161513775459*Power(cosbetaovertwo,11)*sinbetaovertwo;
    return;
  }
  
  void D_6_6_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,12);
    return;
  }
  
  void D_7_neg7_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14);
    return;
  }
  
  void D_7_neg6_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.74165738677394139*Power(cosbetaovertwo,13)*sinbetaovertwo;
    return;
  }
  
  void D_7_neg5_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_7_neg4_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -19.078784028338913*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_7_neg3_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_7_neg2_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -44.7437146423941873*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_7_neg1_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_7_0_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -58.5832740635072393*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_7_1_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_7_2_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -44.7437146423941873*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_7_3_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,10);
    return;
  }
  
  void D_7_4_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -19.078784028338913*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,11);
    return;
  }
  
  void D_7_5_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,12);
    return;
  }
  
  void D_7_6_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.74165738677394139*cosbetaovertwo*Power(sinbetaovertwo,13);
    return;
  }
  
  void D_7_7_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,14);
    return;
  }
  
  void D_7_neg7_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.74165738677394139*Power(cosbetaovertwo,13)*sinbetaovertwo;
    return;
  }
  
  void D_7_neg6_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14) - 13.*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_7_neg5_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.09901951359278483*Power(cosbetaovertwo,13) + 30.594117081556709*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg4_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(15.2970585407783545*Power(cosbetaovertwo,12) - 56.089214649520633*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg3_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-33.8230690505755258*Power(cosbetaovertwo,11) + 84.557672626438814*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg2_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(59.79130371550699*Power(cosbetaovertwo,10) - 107.624346687912582*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg1_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-87.874911095260859*Power(cosbetaovertwo,9) + 117.166548127014479*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_0_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(109.599270070562058*Power(cosbetaovertwo,8) - 109.599270070562058*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_1_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-117.166548127014479*Power(cosbetaovertwo,7) + 87.874911095260859*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_2_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(107.624346687912582*Power(cosbetaovertwo,6) - 59.79130371550699*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_3_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(-84.557672626438814*Power(cosbetaovertwo,5) + 33.8230690505755258*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_4_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(56.089214649520633*Power(cosbetaovertwo,4) - 15.2970585407783545*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_5_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,11)*(-30.594117081556709*Power(cosbetaovertwo,3) + 5.09901951359278483*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_6_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,12)*(13.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_7_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.74165738677394139*cosbetaovertwo*Power(sinbetaovertwo,13);
    return;
  }
  
  void D_7_neg7_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_7_neg6_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.09901951359278483*Power(cosbetaovertwo,13) - 30.594117081556709*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-24.*Power(cosbetaovertwo,12) + 66.*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(66.*Power(cosbetaovertwo,11) - 110.*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(19.8997487421323991*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-132.664991614215994*Power(cosbetaovertwo,10) + 149.248115565992993*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-46.9041575982342955*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(211.06870919205433*Power(cosbetaovertwo,9) - 168.854967353643464*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(86.16843969807043*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-275.739007033825376*Power(cosbetaovertwo,8) + 160.847754103064802*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_0_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-128.965111561228062*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(300.918593642865479*Power(cosbetaovertwo,7) - 128.965111561228062*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(160.847754103064802*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-275.739007033825376*Power(cosbetaovertwo,6) + 86.16843969807043*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-168.854967353643464*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(211.06870919205433*Power(cosbetaovertwo,5) - 46.9041575982342955*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(149.248115565992993*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-132.664991614215994*Power(cosbetaovertwo,4) + 19.8997487421323991*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(-110.*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(66.*Power(cosbetaovertwo,3) - 6.*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(66.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-24.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_6_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,11)*(-30.594117081556709*Power(cosbetaovertwo,3) + 5.09901951359278483*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_7_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,12);
    return;
  }
  
  void D_7_neg7_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 19.078784028338913*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_7_neg6_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(15.2970585407783545*Power(cosbetaovertwo,12) - 56.089214649520633*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-66.*Power(cosbetaovertwo,11) + 110.*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-33.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(165.*Power(cosbetaovertwo,10) - 165.*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.6332495807107997*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(99.498743710661995*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-298.496231131985986*Power(cosbetaovertwo,9) + 198.997487421323991*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_neg2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(23.4520787991171478*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-211.06870919205433*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(422.13741838410866*Power(cosbetaovertwo,8) - 196.997461912584041*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_neg1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-57.445626465380287*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(344.67375879228172*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-482.543262309194407*Power(cosbetaovertwo,7) + 160.847754103064802*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_0_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(107.470926301023385*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-451.377890464298218*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(451.377890464298218*Power(cosbetaovertwo,6) - 107.470926301023385*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-160.847754103064802*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(482.543262309194407*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-344.67375879228172*Power(cosbetaovertwo,5) + 57.445626465380287*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(196.997461912584041*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-422.13741838410866*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(211.06870919205433*Power(cosbetaovertwo,4) - 23.4520787991171478*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-198.997487421323991*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(298.496231131985986*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-99.498743710661995*Power(cosbetaovertwo,3) + 6.6332495807107997*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(165.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-165.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(33.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(-110.*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(66.*Power(cosbetaovertwo,3) - 6.*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_6_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(56.089214649520633*Power(cosbetaovertwo,4) - 15.2970585407783545*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_7_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -19.078784028338913*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,11);
    return;
  }
  
  void D_7_neg7_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_7_neg6_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(33.8230690505755258*Power(cosbetaovertwo,11) - 84.557672626438814*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(19.8997487421323991*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-132.664991614215994*Power(cosbetaovertwo,10) + 149.248115565992993*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.6332495807107997*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-99.498743710661995*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(298.496231131985986*Power(cosbetaovertwo,9) - 198.997487421323991*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_neg3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-40.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(270.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-480.*Power(cosbetaovertwo,8) + 210.*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_neg2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.0710678118654752*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(127.279220613578554*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-509.11688245431422*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(593.96969619669992*Power(cosbetaovertwo,7) - 178.190908859009976*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_neg1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(25.9807621135331594*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-277.128129211020367*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(727.46133917892846*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-581.96907134314277*Power(cosbetaovertwo,6) + 121.243556529821411*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_0_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-64.807406984078602*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(453.651848888550216*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-816.57332799939039*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(453.651848888550216*Power(cosbetaovertwo,5) - 64.807406984078602*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(121.243556529821411*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-581.96907134314277*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(727.46133917892846*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-277.128129211020367*Power(cosbetaovertwo,4) + 25.9807621135331594*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-178.190908859009976*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(593.96969619669992*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-509.11688245431422*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(127.279220613578554*Power(cosbetaovertwo,3) - 7.0710678118654752*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(210.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-480.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(270.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-40.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-198.997487421323991*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(298.496231131985986*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-99.498743710661995*Power(cosbetaovertwo,3) + 6.6332495807107997*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(149.248115565992993*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-132.664991614215994*Power(cosbetaovertwo,4) + 19.8997487421323991*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_6_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(-84.557672626438814*Power(cosbetaovertwo,5) + 33.8230690505755258*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_7_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,10);
    return;
  }
  
  void D_7_neg7_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 44.7437146423941873*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_7_neg6_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(59.79130371550699*Power(cosbetaovertwo,10) - 107.624346687912582*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(46.9041575982342955*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-211.06870919205433*Power(cosbetaovertwo,9) + 168.854967353643464*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(23.4520787991171478*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-211.06870919205433*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(422.13741838410866*Power(cosbetaovertwo,8) - 196.997461912584041*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_neg3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.0710678118654752*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-127.279220613578554*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(509.11688245431422*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-593.96969619669992*Power(cosbetaovertwo,7) + 178.190908859009976*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-45.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(360.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-840.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(630.*Power(cosbetaovertwo,6) - 126.*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.3484692283495343*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(146.969384566990686*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-685.85712797928987*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1028.7856919689348*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-514.3928459844674*Power(cosbetaovertwo,5) + 68.585712797928987*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(27.49545416973504*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-320.7802986469088*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(962.3408959407264*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-962.3408959407264*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(320.7802986469088*Power(cosbetaovertwo,4) - 27.49545416973504*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-68.585712797928987*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(514.3928459844674*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1028.7856919689348*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(685.85712797928987*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-146.969384566990686*Power(cosbetaovertwo,3) + 7.3484692283495343*cosbetaovertwo*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(126.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-630.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(840.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-360.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(45.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-178.190908859009976*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(593.96969619669992*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-509.11688245431422*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(127.279220613578554*Power(cosbetaovertwo,3) - 7.0710678118654752*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(196.997461912584041*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-422.13741838410866*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(211.06870919205433*Power(cosbetaovertwo,4) - 23.4520787991171478*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-168.854967353643464*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(211.06870919205433*Power(cosbetaovertwo,5) - 46.9041575982342955*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_6_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(107.624346687912582*Power(cosbetaovertwo,6) - 59.79130371550699*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_7_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -44.7437146423941873*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_7_neg7_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_7_neg6_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(87.874911095260859*Power(cosbetaovertwo,9) - 117.166548127014479*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(86.16843969807043*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-275.739007033825376*Power(cosbetaovertwo,8) + 160.847754103064802*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(57.445626465380287*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-344.67375879228172*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(482.543262309194407*Power(cosbetaovertwo,7) - 160.847754103064802*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_neg3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(25.9807621135331594*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-277.128129211020367*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(727.46133917892846*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-581.96907134314277*Power(cosbetaovertwo,6) + 121.243556529821411*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.3484692283495343*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-146.969384566990686*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(685.85712797928987*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1028.7856919689348*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(514.3928459844674*Power(cosbetaovertwo,5) - 68.585712797928987*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-48.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(420.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1120.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(1050.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-336.*Power(cosbetaovertwo,4) + 28.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.48331477354788277*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(157.149610244505538*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-785.74805122252769*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1309.58008537087948*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-785.74805122252769*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(157.149610244505538*Power(cosbetaovertwo,3) - 7.48331477354788277*cosbetaovertwo*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_7_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(28.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-336.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(1050.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-1120.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(420.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-48.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_7_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-68.585712797928987*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(514.3928459844674*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1028.7856919689348*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(685.85712797928987*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-146.969384566990686*Power(cosbetaovertwo,3) + 7.3484692283495343*cosbetaovertwo*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(121.243556529821411*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-581.96907134314277*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(727.46133917892846*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-277.128129211020367*Power(cosbetaovertwo,4) + 25.9807621135331594*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-160.847754103064802*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(482.543262309194407*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-344.67375879228172*Power(cosbetaovertwo,5) + 57.445626465380287*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(160.847754103064802*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-275.739007033825376*Power(cosbetaovertwo,6) + 86.16843969807043*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_6_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-117.166548127014479*Power(cosbetaovertwo,7) + 87.874911095260859*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_7_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_7_neg7_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 58.5832740635072393*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_7_neg6_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(109.599270070562058*Power(cosbetaovertwo,8) - 109.599270070562058*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(128.965111561228062*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-300.918593642865479*Power(cosbetaovertwo,7) + 128.965111561228062*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(107.470926301023385*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-451.377890464298218*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(451.377890464298218*Power(cosbetaovertwo,6) - 107.470926301023385*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_neg3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(64.807406984078602*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-453.651848888550216*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(816.57332799939039*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-453.651848888550216*Power(cosbetaovertwo,5) + 64.807406984078602*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(27.49545416973504*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-320.7802986469088*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(962.3408959407264*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-962.3408959407264*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(320.7802986469088*Power(cosbetaovertwo,4) - 27.49545416973504*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.48331477354788277*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-157.149610244505538*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(785.74805122252769*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1309.58008537087948*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(785.74805122252769*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-157.149610244505538*Power(cosbetaovertwo,3) + 7.48331477354788277*cosbetaovertwo*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_7_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-49.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(441.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1225.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(1225.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-441.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(49.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_7_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.48331477354788277*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(157.149610244505538*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-785.74805122252769*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1309.58008537087948*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-785.74805122252769*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(157.149610244505538*Power(cosbetaovertwo,3) - 7.48331477354788277*cosbetaovertwo*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_7_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(27.49545416973504*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-320.7802986469088*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(962.3408959407264*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-962.3408959407264*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(320.7802986469088*Power(cosbetaovertwo,4) - 27.49545416973504*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-64.807406984078602*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(453.651848888550216*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-816.57332799939039*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(453.651848888550216*Power(cosbetaovertwo,5) - 64.807406984078602*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(107.470926301023385*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-451.377890464298218*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(451.377890464298218*Power(cosbetaovertwo,6) - 107.470926301023385*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-128.965111561228062*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(300.918593642865479*Power(cosbetaovertwo,7) - 128.965111561228062*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_6_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(109.599270070562058*Power(cosbetaovertwo,8) - 109.599270070562058*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_7_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -58.5832740635072393*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_7_neg7_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_7_neg6_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(117.166548127014479*Power(cosbetaovertwo,7) - 87.874911095260859*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(160.847754103064802*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-275.739007033825376*Power(cosbetaovertwo,6) + 86.16843969807043*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(160.847754103064802*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-482.543262309194407*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(344.67375879228172*Power(cosbetaovertwo,5) - 57.445626465380287*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_neg3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(121.243556529821411*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-581.96907134314277*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(727.46133917892846*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-277.128129211020367*Power(cosbetaovertwo,4) + 25.9807621135331594*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(68.585712797928987*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-514.3928459844674*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1028.7856919689348*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-685.85712797928987*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(146.969384566990686*Power(cosbetaovertwo,3) - 7.3484692283495343*cosbetaovertwo*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(28.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-336.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(1050.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-1120.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(420.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-48.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_7_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.48331477354788277*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-157.149610244505538*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(785.74805122252769*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1309.58008537087948*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(785.74805122252769*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-157.149610244505538*Power(cosbetaovertwo,3) + 7.48331477354788277*cosbetaovertwo*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_7_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-48.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(420.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1120.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(1050.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-336.*Power(cosbetaovertwo,4) + 28.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.3484692283495343*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(146.969384566990686*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-685.85712797928987*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1028.7856919689348*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-514.3928459844674*Power(cosbetaovertwo,5) + 68.585712797928987*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(25.9807621135331594*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-277.128129211020367*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(727.46133917892846*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-581.96907134314277*Power(cosbetaovertwo,6) + 121.243556529821411*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-57.445626465380287*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(344.67375879228172*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-482.543262309194407*Power(cosbetaovertwo,7) + 160.847754103064802*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(86.16843969807043*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-275.739007033825376*Power(cosbetaovertwo,8) + 160.847754103064802*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_6_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-87.874911095260859*Power(cosbetaovertwo,9) + 117.166548127014479*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_7_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_7_neg7_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 44.7437146423941873*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_7_neg6_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(107.624346687912582*Power(cosbetaovertwo,6) - 59.79130371550699*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(168.854967353643464*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-211.06870919205433*Power(cosbetaovertwo,5) + 46.9041575982342955*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(196.997461912584041*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-422.13741838410866*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(211.06870919205433*Power(cosbetaovertwo,4) - 23.4520787991171478*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_neg3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(178.190908859009976*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-593.96969619669992*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(509.11688245431422*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-127.279220613578554*Power(cosbetaovertwo,3) + 7.0710678118654752*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(126.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-630.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(840.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-360.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(45.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(68.585712797928987*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-514.3928459844674*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1028.7856919689348*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-685.85712797928987*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(146.969384566990686*Power(cosbetaovertwo,3) - 7.3484692283495343*cosbetaovertwo*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(27.49545416973504*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-320.7802986469088*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(962.3408959407264*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-962.3408959407264*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(320.7802986469088*Power(cosbetaovertwo,4) - 27.49545416973504*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.3484692283495343*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-146.969384566990686*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(685.85712797928987*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1028.7856919689348*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(514.3928459844674*Power(cosbetaovertwo,5) - 68.585712797928987*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_7_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-45.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(360.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-840.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(630.*Power(cosbetaovertwo,6) - 126.*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.0710678118654752*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(127.279220613578554*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-509.11688245431422*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(593.96969619669992*Power(cosbetaovertwo,7) - 178.190908859009976*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(23.4520787991171478*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-211.06870919205433*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(422.13741838410866*Power(cosbetaovertwo,8) - 196.997461912584041*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-46.9041575982342955*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(211.06870919205433*Power(cosbetaovertwo,9) - 168.854967353643464*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_6_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(59.79130371550699*Power(cosbetaovertwo,10) - 107.624346687912582*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_7_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -44.7437146423941873*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_7_neg7_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,10);
    return;
  }
  
  void D_7_neg6_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(84.557672626438814*Power(cosbetaovertwo,5) - 33.8230690505755258*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(149.248115565992993*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-132.664991614215994*Power(cosbetaovertwo,4) + 19.8997487421323991*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(198.997487421323991*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-298.496231131985986*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(99.498743710661995*Power(cosbetaovertwo,3) - 6.6332495807107997*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_neg3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(210.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-480.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(270.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-40.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_neg2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(178.190908859009976*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-593.96969619669992*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(509.11688245431422*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-127.279220613578554*Power(cosbetaovertwo,3) + 7.0710678118654752*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_neg1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(121.243556529821411*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-581.96907134314277*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(727.46133917892846*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-277.128129211020367*Power(cosbetaovertwo,4) + 25.9807621135331594*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_0_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(64.807406984078602*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-453.651848888550216*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(816.57332799939039*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-453.651848888550216*Power(cosbetaovertwo,5) + 64.807406984078602*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(25.9807621135331594*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-277.128129211020367*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(727.46133917892846*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-581.96907134314277*Power(cosbetaovertwo,6) + 121.243556529821411*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.0710678118654752*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-127.279220613578554*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(509.11688245431422*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-593.96969619669992*Power(cosbetaovertwo,7) + 178.190908859009976*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_7_3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-40.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(270.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-480.*Power(cosbetaovertwo,8) + 210.*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.6332495807107997*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(99.498743710661995*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-298.496231131985986*Power(cosbetaovertwo,9) + 198.997487421323991*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(19.8997487421323991*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-132.664991614215994*Power(cosbetaovertwo,10) + 149.248115565992993*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_6_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-33.8230690505755258*Power(cosbetaovertwo,11) + 84.557672626438814*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_7_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_7_neg7_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 19.078784028338913*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,11);
    return;
  }
  
  void D_7_neg6_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(56.089214649520633*Power(cosbetaovertwo,4) - 15.2970585407783545*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(110.*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-66.*Power(cosbetaovertwo,3) + 6.*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(165.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-165.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(33.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_neg3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(198.997487421323991*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-298.496231131985986*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(99.498743710661995*Power(cosbetaovertwo,3) - 6.6332495807107997*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_neg2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(196.997461912584041*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-422.13741838410866*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(211.06870919205433*Power(cosbetaovertwo,4) - 23.4520787991171478*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_neg1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(160.847754103064802*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-482.543262309194407*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(344.67375879228172*Power(cosbetaovertwo,5) - 57.445626465380287*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_0_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(107.470926301023385*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-451.377890464298218*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(451.377890464298218*Power(cosbetaovertwo,6) - 107.470926301023385*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(57.445626465380287*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-344.67375879228172*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(482.543262309194407*Power(cosbetaovertwo,7) - 160.847754103064802*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(23.4520787991171478*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-211.06870919205433*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(422.13741838410866*Power(cosbetaovertwo,8) - 196.997461912584041*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.6332495807107997*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-99.498743710661995*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(298.496231131985986*Power(cosbetaovertwo,9) - 198.997487421323991*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_7_4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-33.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(165.*Power(cosbetaovertwo,10) - 165.*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(66.*Power(cosbetaovertwo,11) - 110.*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_6_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(15.2970585407783545*Power(cosbetaovertwo,12) - 56.089214649520633*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_7_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -19.078784028338913*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_7_neg7_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,12);
    return;
  }
  
  void D_7_neg6_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,11)*(30.594117081556709*Power(cosbetaovertwo,3) - 5.0990195135927848*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(66.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-24.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(110.*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-66.*Power(cosbetaovertwo,3) + 6.*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(149.248115565992993*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-132.664991614215994*Power(cosbetaovertwo,4) + 19.8997487421323991*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(168.854967353643464*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-211.06870919205433*Power(cosbetaovertwo,5) + 46.9041575982342955*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_neg1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(160.847754103064802*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-275.739007033825376*Power(cosbetaovertwo,6) + 86.16843969807043*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_0_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(128.965111561228062*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-300.918593642865479*Power(cosbetaovertwo,7) + 128.965111561228062*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(86.16843969807043*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-275.739007033825376*Power(cosbetaovertwo,8) + 160.847754103064802*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(46.9041575982342955*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-211.06870919205433*Power(cosbetaovertwo,9) + 168.854967353643464*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(19.8997487421323991*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-132.664991614215994*Power(cosbetaovertwo,10) + 149.248115565992993*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-66.*Power(cosbetaovertwo,11) + 110.*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_7_5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-24.*Power(cosbetaovertwo,12) + 66.*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_6_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.09901951359278483*Power(cosbetaovertwo,13) + 30.594117081556709*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_7_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_7_neg7_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.74165738677394139*cosbetaovertwo*Power(sinbetaovertwo,13);
    return;
  }
  
  void D_7_neg6_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,12)*(13.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg5_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,11)*(30.594117081556709*Power(cosbetaovertwo,3) - 5.0990195135927848*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg4_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(56.089214649520633*Power(cosbetaovertwo,4) - 15.2970585407783545*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg3_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(84.557672626438814*Power(cosbetaovertwo,5) - 33.8230690505755258*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg2_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(107.624346687912582*Power(cosbetaovertwo,6) - 59.79130371550699*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_neg1_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(117.166548127014479*Power(cosbetaovertwo,7) - 87.874911095260859*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_0_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(109.599270070562058*Power(cosbetaovertwo,8) - 109.599270070562058*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_1_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(87.874911095260859*Power(cosbetaovertwo,9) - 117.166548127014479*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_2_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(59.79130371550699*Power(cosbetaovertwo,10) - 107.624346687912582*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_3_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(33.8230690505755258*Power(cosbetaovertwo,11) - 84.557672626438814*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_4_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(15.2970585407783545*Power(cosbetaovertwo,12) - 56.089214649520633*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_5_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.09901951359278483*Power(cosbetaovertwo,13) - 30.594117081556709*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_7_6_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14) - 13.*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_7_7_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -3.74165738677394139*Power(cosbetaovertwo,13)*sinbetaovertwo;
    return;
  }
  
  void D_7_neg7_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,14);
    return;
  }
  
  void D_7_neg6_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.74165738677394139*cosbetaovertwo*Power(sinbetaovertwo,13);
    return;
  }
  
  void D_7_neg5_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,12);
    return;
  }
  
  void D_7_neg4_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 19.078784028338913*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,11);
    return;
  }
  
  void D_7_neg3_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,10);
    return;
  }
  
  void D_7_neg2_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 44.7437146423941873*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_7_neg1_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_7_0_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 58.5832740635072393*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_7_1_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 54.7996350352810288*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_7_2_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 44.7437146423941873*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_7_3_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 31.6385840391127491*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_7_4_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 19.078784028338913*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_7_5_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 9.53939201416945649*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_7_6_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 3.74165738677394139*Power(cosbetaovertwo,13)*sinbetaovertwo;
    return;
  }
  
  void D_7_7_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,14);
    return;
  }
  
  void D_8_neg8_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16);
    return;
  }
  
  void D_8_neg7_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -4.*Power(cosbetaovertwo,15)*sinbetaovertwo;
    return;
  }
  
  void D_8_neg6_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*Power(cosbetaovertwo,14)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_8_neg5_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -23.6643191323984642*Power(cosbetaovertwo,13)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_8_neg4_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_8_neg3_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -66.0908465674332242*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_8_neg2_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_8_neg1_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -106.957935656967501*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_8_0_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 113.446022407134222*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_8_1_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -106.957935656967501*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_8_2_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,10);
    return;
  }
  
  void D_8_3_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -66.0908465674332242*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,11);
    return;
  }
  
  void D_8_4_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,12);
    return;
  }
  
  void D_8_5_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -23.6643191323984642*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,13);
    return;
  }
  
  void D_8_6_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,14);
    return;
  }
  
  void D_8_7_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -4.*cosbetaovertwo*Power(sinbetaovertwo,15);
    return;
  }
  
  void D_8_8_neg8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,16);
    return;
  }
  
  void D_8_neg8_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 4.*Power(cosbetaovertwo,15)*sinbetaovertwo;
    return;
  }
  
  void D_8_neg7_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) - 15.*Power(cosbetaovertwo,14)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_8_neg6_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.47722557505166113*Power(cosbetaovertwo,15) + 38.3405790253616279*Power(cosbetaovertwo,13)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg5_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(17.7482393492988481*Power(cosbetaovertwo,14) - 76.909037180295009*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg4_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-42.6614580154030835*Power(cosbetaovertwo,13) + 127.984374046209251*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg3_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(82.61355820929153*Power(cosbetaovertwo,12) - 181.749828060441367*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg2_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-134.231143927182562*Power(cosbetaovertwo,11) + 223.718573211970937*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg1_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(187.176387399693127*Power(cosbetaovertwo,10) - 240.655355228176878*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_0_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-226.892044814268444*Power(cosbetaovertwo,9) + 226.892044814268444*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_1_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(240.655355228176878*Power(cosbetaovertwo,8) - 187.176387399693127*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_2_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(-223.718573211970937*Power(cosbetaovertwo,7) + 134.231143927182562*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_3_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(181.749828060441367*Power(cosbetaovertwo,6) - 82.61355820929153*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_4_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,11)*(-127.984374046209251*Power(cosbetaovertwo,5) + 42.6614580154030835*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_5_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,12)*(76.909037180295009*Power(cosbetaovertwo,4) - 17.7482393492988481*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_6_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,13)*(-38.3405790253616279*Power(cosbetaovertwo,3) + 5.47722557505166113*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_7_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,14)*(15.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_neg7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -4.*cosbetaovertwo*Power(sinbetaovertwo,15);
    return;
  }
  
  void D_8_neg8_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*Power(cosbetaovertwo,14)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_8_neg7_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.47722557505166113*Power(cosbetaovertwo,15) - 38.3405790253616279*Power(cosbetaovertwo,13)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) + Power(sinbetaovertwo,2)*(-28.*Power(cosbetaovertwo,14) + 91.*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg5_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.48074069840786023*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(84.249629079302183*Power(cosbetaovertwo,13) - 168.499258158604366*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg4_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(23.3666428910958452*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-186.933143128766762*Power(cosbetaovertwo,12) + 257.033071802054297*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg3_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-60.332412515993424*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(331.828268837963834*Power(cosbetaovertwo,11) - 331.828268837963834*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg2_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(122.535709081067467*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-490.142836324269866*Power(cosbetaovertwo,10) + 367.6071272432024*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg1_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-205.041459222275337*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(615.12437766682601*Power(cosbetaovertwo,9) - 351.499644381043436*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_0_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(289.972412480911708*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-662.79408567065533*Power(cosbetaovertwo,8) + 289.972412480911708*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_1_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-351.499644381043436*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(615.12437766682601*Power(cosbetaovertwo,7) - 205.041459222275337*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_2_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(367.6071272432024*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-490.142836324269866*Power(cosbetaovertwo,6) + 122.535709081067467*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_3_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(-331.828268837963834*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(331.828268837963834*Power(cosbetaovertwo,5) - 60.332412515993424*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_4_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(257.033071802054297*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-186.933143128766762*Power(cosbetaovertwo,4) + 23.3666428910958452*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_5_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,11)*(-168.499258158604366*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(84.249629079302183*Power(cosbetaovertwo,3) - 6.48074069840786023*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_6_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,12)*(91.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-28.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_7_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,13)*(-38.3405790253616279*Power(cosbetaovertwo,3) + 5.47722557505166113*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_neg6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,14);
    return;
  }
  
  void D_8_neg8_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 23.6643191323984642*Power(cosbetaovertwo,13)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_8_neg7_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(17.7482393492988481*Power(cosbetaovertwo,14) - 76.909037180295009*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.48074069840786023*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(-84.249629079302183*Power(cosbetaovertwo,13) + 168.499258158604366*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) + Power(sinbetaovertwo,2)*(-39.*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(234.*Power(cosbetaovertwo,12) - 286.*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.21110255092797859*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(129.799845916703615*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-475.932768361246587*Power(cosbetaovertwo,11) + 396.610640301038822*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(27.9284800875378823*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-307.213280962916706*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(768.03320240729176*Power(cosbetaovertwo,10) - 460.819921444375059*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-75.630681604756148*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(567.23011203567111*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-1021.014201664208*Power(cosbetaovertwo,9) + 453.784089628536888*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(158.192920195563746*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-854.24176905604423*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(1138.98902540805897*Power(cosbetaovertwo,8) - 379.66300846935299*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_0_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-268.462287854365124*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(1073.8491514174605*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1073.8491514174605*Power(cosbetaovertwo,7) + 268.462287854365124*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_1_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(379.66300846935299*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1138.98902540805897*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(854.24176905604423*Power(cosbetaovertwo,6) - 158.192920195563746*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_2_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-453.784089628536888*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1021.014201664208*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-567.23011203567111*Power(cosbetaovertwo,5) + 75.630681604756148*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_3_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(460.819921444375059*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-768.03320240729176*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(307.213280962916706*Power(cosbetaovertwo,4) - 27.9284800875378823*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_4_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(-396.610640301038822*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(475.932768361246587*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-129.799845916703615*Power(cosbetaovertwo,3) + 7.21110255092797859*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_5_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(286.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-234.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(39.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_6_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,11)*(-168.499258158604366*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(84.249629079302183*Power(cosbetaovertwo,3) - 6.48074069840786023*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_7_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,12)*(76.909037180295009*Power(cosbetaovertwo,4) - 17.7482393492988481*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_neg5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -23.6643191323984642*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,13);
    return;
  }
  
  void D_8_neg8_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_8_neg7_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(42.6614580154030835*Power(cosbetaovertwo,13) - 127.984374046209251*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(23.3666428910958452*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-186.933143128766762*Power(cosbetaovertwo,12) + 257.033071802054297*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.21110255092797859*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(-129.799845916703615*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(475.932768361246587*Power(cosbetaovertwo,11) - 396.610640301038822*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) + Power(sinbetaovertwo,2)*(-48.*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(396.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-880.*Power(cosbetaovertwo,10) + 495.*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.74596669241483377*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(170.411267233126343*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-852.05633616563171*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(1278.08450424844757*Power(cosbetaovertwo,9) - 511.23380169937903*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_neg2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(31.4642654451045464*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-419.523539268060619*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(1415.89194502970459*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1510.28474136501823*Power(cosbetaovertwo,8) + 440.49971623146365*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_neg1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-87.749643873921221*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(789.74679486529099*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-1895.39230767669837*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1474.19401708187651*Power(cosbetaovertwo,7) - 315.898717946116394*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_0_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(186.145104689862849*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-1191.32867001512223*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(2084.82517252646391*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-1191.32867001512223*Power(cosbetaovertwo,6) + 186.145104689862849*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_1_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-315.898717946116394*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(1474.19401708187651*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1895.39230767669837*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(789.74679486529099*Power(cosbetaovertwo,5) - 87.749643873921221*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_2_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(440.49971623146365*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1510.28474136501823*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(1415.89194502970459*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-419.523539268060619*Power(cosbetaovertwo,4) + 31.4642654451045464*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_3_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-511.23380169937903*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1278.08450424844757*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-852.05633616563171*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(170.411267233126343*Power(cosbetaovertwo,3) - 7.74596669241483377*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_4_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(495.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-880.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(396.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-48.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_5_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(-396.610640301038822*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(475.932768361246587*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-129.799845916703615*Power(cosbetaovertwo,3) + 7.21110255092797859*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_6_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(257.033071802054297*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-186.933143128766762*Power(cosbetaovertwo,4) + 23.3666428910958452*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_7_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,11)*(-127.984374046209251*Power(cosbetaovertwo,5) + 42.6614580154030835*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_neg4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,12);
    return;
  }
  
  void D_8_neg8_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 66.0908465674332242*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_8_neg7_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(82.61355820929153*Power(cosbetaovertwo,12) - 181.749828060441367*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(60.332412515993424*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-331.828268837963834*Power(cosbetaovertwo,11) + 331.828268837963834*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(27.9284800875378823*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-307.213280962916706*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(768.03320240729176*Power(cosbetaovertwo,10) - 460.819921444375059*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.74596669241483377*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(-170.411267233126343*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(852.05633616563171*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-1278.08450424844757*Power(cosbetaovertwo,9) + 511.23380169937903*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_neg3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) + Power(sinbetaovertwo,2)*(-55.*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(550.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-1650.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(1650.*Power(cosbetaovertwo,8) - 462.*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_neg2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-8.12403840463596036*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(203.100960115899009*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-1218.60576069539405*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(2437.21152139078811*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1706.04806497355168*Power(cosbetaovertwo,7) + 341.209612994710335*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_neg1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(33.9852909359328569*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-509.77936403899285*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(2039.11745615597141*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-2854.76443861835998*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(1427.38221930917999*Power(cosbetaovertwo,6) - 203.911745615597141*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_0_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-96.1249187255833262*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(961.24918725583326*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-2691.49772431633313*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(2691.49772431633313*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-961.24918725583326*Power(cosbetaovertwo,5) + 96.124918725583326*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_1_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(203.911745615597141*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-1427.38221930917999*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(2854.76443861835998*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-2039.11745615597141*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(509.77936403899285*Power(cosbetaovertwo,4) - 33.9852909359328569*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_2_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-341.209612994710335*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(1706.04806497355168*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-2437.21152139078811*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(1218.60576069539405*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-203.100960115899009*Power(cosbetaovertwo,3) + 8.1240384046359604*cosbetaovertwo*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_3_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(462.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1650.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(1650.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-550.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(55.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_4_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-511.23380169937903*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1278.08450424844757*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-852.05633616563171*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(170.411267233126343*Power(cosbetaovertwo,3) - 7.74596669241483377*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_5_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(460.819921444375059*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-768.03320240729176*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(307.213280962916706*Power(cosbetaovertwo,4) - 27.9284800875378823*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_6_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(-331.828268837963834*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(331.828268837963834*Power(cosbetaovertwo,5) - 60.332412515993424*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_7_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(181.749828060441367*Power(cosbetaovertwo,6) - 82.61355820929153*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_neg3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -66.0908465674332242*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,11);
    return;
  }
  
  void D_8_neg8_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_8_neg7_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(134.231143927182562*Power(cosbetaovertwo,11) - 223.718573211970937*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(122.535709081067467*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-490.142836324269866*Power(cosbetaovertwo,10) + 367.6071272432024*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(75.630681604756148*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-567.23011203567111*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(1021.014201664208*Power(cosbetaovertwo,9) - 453.784089628536888*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(31.4642654451045464*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-419.523539268060619*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(1415.89194502970459*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1510.28474136501823*Power(cosbetaovertwo,8) + 440.49971623146365*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_neg3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(8.12403840463596036*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(-203.100960115899009*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(1218.60576069539405*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-2437.21152139078811*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1706.04806497355168*Power(cosbetaovertwo,7) - 341.209612994710335*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_neg2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) + Power(sinbetaovertwo,2)*(-60.*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(675.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-2400.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(3150.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-1512.*Power(cosbetaovertwo,6) + 210.*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_neg1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-8.36660026534075548*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(225.898207164200398*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-1505.98804776133599*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(3513.9721114431173*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-3162.57490029880557*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(1054.19163343293519*Power(cosbetaovertwo,5) - 100.399203184089066*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_0_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(35.4964786985976963*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-567.94365917756314*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(2484.75350890183874*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-3975.60561424294198*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(2484.75350890183874*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-567.94365917756314*Power(cosbetaovertwo,4) + 35.4964786985976963*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_1_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-100.399203184089066*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(1054.19163343293519*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-3162.57490029880557*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(3513.9721114431173*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-1505.98804776133599*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(225.898207164200398*Power(cosbetaovertwo,3) - 8.36660026534075548*cosbetaovertwo*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_2_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(210.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-1512.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(3150.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-2400.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(675.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-60.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_3_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-341.209612994710335*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(1706.04806497355168*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-2437.21152139078811*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(1218.60576069539405*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-203.100960115899009*Power(cosbetaovertwo,3) + 8.1240384046359604*cosbetaovertwo*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_4_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(440.49971623146365*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1510.28474136501823*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(1415.89194502970459*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-419.523539268060619*Power(cosbetaovertwo,4) + 31.4642654451045464*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_5_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-453.784089628536888*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1021.014201664208*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-567.23011203567111*Power(cosbetaovertwo,5) + 75.630681604756148*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_6_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(367.6071272432024*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-490.142836324269866*Power(cosbetaovertwo,6) + 122.535709081067467*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_7_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(-223.718573211970937*Power(cosbetaovertwo,7) + 134.231143927182562*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_neg2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,10);
    return;
  }
  
  void D_8_neg8_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 106.957935656967501*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_8_neg7_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(187.176387399693127*Power(cosbetaovertwo,10) - 240.655355228176878*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(205.041459222275337*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-615.12437766682601*Power(cosbetaovertwo,9) + 351.499644381043436*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(158.192920195563746*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-854.24176905604423*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(1138.98902540805897*Power(cosbetaovertwo,8) - 379.66300846935299*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(87.749643873921221*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-789.74679486529099*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(1895.39230767669837*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1474.19401708187651*Power(cosbetaovertwo,7) + 315.898717946116394*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_neg3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(33.9852909359328569*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-509.77936403899285*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(2039.11745615597141*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-2854.76443861835998*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(1427.38221930917999*Power(cosbetaovertwo,6) - 203.911745615597141*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_neg2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(8.36660026534075548*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(-225.898207164200398*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(1505.98804776133599*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-3513.9721114431173*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(3162.57490029880557*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-1054.19163343293519*Power(cosbetaovertwo,5) + 100.399203184089066*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_neg1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) + Power(sinbetaovertwo,2)*(-63.*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(756.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-2940.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(4410.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-2646.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(588.*Power(cosbetaovertwo,4) - 36.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_0_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-8.48528137423857029*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(237.587878478679968*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-1663.11514935075978*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(4157.78787337689944*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-4157.78787337689944*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(1663.11514935075978*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-237.587878478679968*Power(cosbetaovertwo,3) + 8.4852813742385703*cosbetaovertwo*Power(sinbetaovertwo,2))))))));
    return;
  }
  
  void D_8_1_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(36.*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-588.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(2646.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-4410.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(2940.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-756.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(63.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))))))));
    return;
  }
  
  void D_8_2_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-100.399203184089066*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(1054.19163343293519*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-3162.57490029880557*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(3513.9721114431173*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-1505.98804776133599*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(225.898207164200398*Power(cosbetaovertwo,3) - 8.36660026534075548*cosbetaovertwo*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_3_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(203.911745615597141*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-1427.38221930917999*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(2854.76443861835998*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-2039.11745615597141*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(509.77936403899285*Power(cosbetaovertwo,4) - 33.9852909359328569*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_4_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-315.898717946116394*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(1474.19401708187651*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1895.39230767669837*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(789.74679486529099*Power(cosbetaovertwo,5) - 87.749643873921221*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_5_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(379.66300846935299*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1138.98902540805897*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(854.24176905604423*Power(cosbetaovertwo,6) - 158.192920195563746*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_6_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-351.499644381043436*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(615.12437766682601*Power(cosbetaovertwo,7) - 205.041459222275337*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_7_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(240.655355228176878*Power(cosbetaovertwo,8) - 187.176387399693127*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_neg1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -106.957935656967501*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_8_neg8_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 113.446022407134222*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_8_neg7_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(226.892044814268444*Power(cosbetaovertwo,9) - 226.892044814268444*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(289.972412480911708*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-662.79408567065533*Power(cosbetaovertwo,8) + 289.972412480911708*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(268.462287854365124*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-1073.8491514174605*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1073.8491514174605*Power(cosbetaovertwo,7) - 268.462287854365124*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(186.145104689862849*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-1191.32867001512223*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(2084.82517252646391*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-1191.32867001512223*Power(cosbetaovertwo,6) + 186.145104689862849*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_neg3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(96.1249187255833262*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-961.24918725583326*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(2691.49772431633313*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-2691.49772431633313*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(961.24918725583326*Power(cosbetaovertwo,5) - 96.124918725583326*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_neg2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(35.4964786985976963*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-567.94365917756314*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(2484.75350890183874*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-3975.60561424294198*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(2484.75350890183874*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-567.94365917756314*Power(cosbetaovertwo,4) + 35.4964786985976963*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_neg1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(8.48528137423857029*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(-237.587878478679968*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(1663.11514935075978*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-4157.78787337689944*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(4157.78787337689944*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-1663.11514935075978*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(237.587878478679968*Power(cosbetaovertwo,3) - 8.4852813742385703*cosbetaovertwo*Power(sinbetaovertwo,2))))))));
    return;
  }
  
  void D_8_0_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) + Power(sinbetaovertwo,2)*(-64.*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(784.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-3136.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(4900.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-3136.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(784.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-64.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2))))))));
    return;
  }
  
  void D_8_1_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-8.48528137423857029*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(237.587878478679968*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-1663.11514935075978*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(4157.78787337689944*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-4157.78787337689944*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(1663.11514935075978*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-237.587878478679968*Power(cosbetaovertwo,3) + 8.4852813742385703*cosbetaovertwo*Power(sinbetaovertwo,2))))))));
    return;
  }
  
  void D_8_2_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(35.4964786985976963*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-567.94365917756314*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(2484.75350890183874*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-3975.60561424294198*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(2484.75350890183874*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-567.94365917756314*Power(cosbetaovertwo,4) + 35.4964786985976963*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_3_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-96.1249187255833262*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(961.24918725583326*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-2691.49772431633313*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(2691.49772431633313*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-961.24918725583326*Power(cosbetaovertwo,5) + 96.124918725583326*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_4_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(186.145104689862849*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-1191.32867001512223*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(2084.82517252646391*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-1191.32867001512223*Power(cosbetaovertwo,6) + 186.145104689862849*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_5_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-268.462287854365124*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(1073.8491514174605*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1073.8491514174605*Power(cosbetaovertwo,7) + 268.462287854365124*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_6_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(289.972412480911708*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-662.79408567065533*Power(cosbetaovertwo,8) + 289.972412480911708*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_7_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(-226.892044814268444*Power(cosbetaovertwo,9) + 226.892044814268444*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_0(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 113.446022407134222*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_8_neg8_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 106.957935656967501*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_8_neg7_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(240.655355228176878*Power(cosbetaovertwo,8) - 187.176387399693127*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(351.499644381043436*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-615.12437766682601*Power(cosbetaovertwo,7) + 205.041459222275337*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(379.66300846935299*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1138.98902540805897*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(854.24176905604423*Power(cosbetaovertwo,6) - 158.192920195563746*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(315.898717946116394*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-1474.19401708187651*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1895.39230767669837*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-789.74679486529099*Power(cosbetaovertwo,5) + 87.749643873921221*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_neg3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(203.911745615597141*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-1427.38221930917999*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(2854.76443861835998*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-2039.11745615597141*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(509.77936403899285*Power(cosbetaovertwo,4) - 33.9852909359328569*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_neg2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(100.399203184089066*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-1054.19163343293519*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(3162.57490029880557*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-3513.9721114431173*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(1505.98804776133599*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-225.898207164200398*Power(cosbetaovertwo,3) + 8.36660026534075548*cosbetaovertwo*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_neg1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(36.*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-588.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(2646.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-4410.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(2940.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-756.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(63.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))))))));
    return;
  }
  
  void D_8_0_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(8.48528137423857029*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(-237.587878478679968*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(1663.11514935075978*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-4157.78787337689944*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(4157.78787337689944*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-1663.11514935075978*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(237.587878478679968*Power(cosbetaovertwo,3) - 8.4852813742385703*cosbetaovertwo*Power(sinbetaovertwo,2))))))));
    return;
  }
  
  void D_8_1_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) + Power(sinbetaovertwo,2)*(-63.*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(756.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-2940.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(4410.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-2646.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(588.*Power(cosbetaovertwo,4) - 36.*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_2_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-8.36660026534075548*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(225.898207164200398*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-1505.98804776133599*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(3513.9721114431173*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-3162.57490029880557*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(1054.19163343293519*Power(cosbetaovertwo,5) - 100.399203184089066*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_3_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(33.9852909359328569*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-509.77936403899285*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(2039.11745615597141*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-2854.76443861835998*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(1427.38221930917999*Power(cosbetaovertwo,6) - 203.911745615597141*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_4_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-87.749643873921221*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(789.74679486529099*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-1895.39230767669837*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1474.19401708187651*Power(cosbetaovertwo,7) - 315.898717946116394*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_5_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(158.192920195563746*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-854.24176905604423*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(1138.98902540805897*Power(cosbetaovertwo,8) - 379.66300846935299*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_6_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-205.041459222275337*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(615.12437766682601*Power(cosbetaovertwo,9) - 351.499644381043436*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_7_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(187.176387399693127*Power(cosbetaovertwo,10) - 240.655355228176878*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_1(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -106.957935656967501*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_8_neg8_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,10);
    return;
  }
  
  void D_8_neg7_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(223.718573211970937*Power(cosbetaovertwo,7) - 134.231143927182562*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(367.6071272432024*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-490.142836324269866*Power(cosbetaovertwo,6) + 122.535709081067467*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(453.784089628536888*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1021.014201664208*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(567.23011203567111*Power(cosbetaovertwo,5) - 75.630681604756148*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(440.49971623146365*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1510.28474136501823*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(1415.89194502970459*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-419.523539268060619*Power(cosbetaovertwo,4) + 31.4642654451045464*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_neg3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(341.209612994710335*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-1706.04806497355168*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(2437.21152139078811*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-1218.60576069539405*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(203.100960115899009*Power(cosbetaovertwo,3) - 8.1240384046359604*cosbetaovertwo*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_neg2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(210.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-1512.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(3150.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-2400.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(675.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-60.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_neg1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(100.399203184089066*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-1054.19163343293519*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(3162.57490029880557*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-3513.9721114431173*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(1505.98804776133599*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-225.898207164200398*Power(cosbetaovertwo,3) + 8.36660026534075548*cosbetaovertwo*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_0_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(35.4964786985976963*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-567.94365917756314*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(2484.75350890183874*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-3975.60561424294198*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(2484.75350890183874*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-567.94365917756314*Power(cosbetaovertwo,4) + 35.4964786985976963*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_1_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(8.36660026534075548*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(-225.898207164200398*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(1505.98804776133599*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-3513.9721114431173*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(3162.57490029880557*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-1054.19163343293519*Power(cosbetaovertwo,5) + 100.399203184089066*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))))));
    return;
  }
  
  void D_8_2_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) + Power(sinbetaovertwo,2)*(-60.*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(675.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-2400.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(3150.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-1512.*Power(cosbetaovertwo,6) + 210.*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_3_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-8.12403840463596036*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(203.100960115899009*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-1218.60576069539405*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(2437.21152139078811*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1706.04806497355168*Power(cosbetaovertwo,7) + 341.209612994710335*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_4_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(31.4642654451045464*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-419.523539268060619*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(1415.89194502970459*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1510.28474136501823*Power(cosbetaovertwo,8) + 440.49971623146365*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_5_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-75.630681604756148*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(567.23011203567111*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-1021.014201664208*Power(cosbetaovertwo,9) + 453.784089628536888*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_6_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(122.535709081067467*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-490.142836324269866*Power(cosbetaovertwo,10) + 367.6071272432024*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_7_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(-134.231143927182562*Power(cosbetaovertwo,11) + 223.718573211970937*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_2(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_8_neg8_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 66.0908465674332242*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,11);
    return;
  }
  
  void D_8_neg7_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(181.749828060441367*Power(cosbetaovertwo,6) - 82.61355820929153*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(331.828268837963834*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-331.828268837963834*Power(cosbetaovertwo,5) + 60.332412515993424*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(460.819921444375059*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-768.03320240729176*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(307.213280962916706*Power(cosbetaovertwo,4) - 27.9284800875378823*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(511.23380169937903*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1278.08450424844757*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(852.05633616563171*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-170.411267233126343*Power(cosbetaovertwo,3) + 7.74596669241483377*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_neg3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(462.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1650.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(1650.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-550.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(55.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_neg2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(341.209612994710335*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-1706.04806497355168*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(2437.21152139078811*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-1218.60576069539405*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(203.100960115899009*Power(cosbetaovertwo,3) - 8.1240384046359604*cosbetaovertwo*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_neg1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(203.911745615597141*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-1427.38221930917999*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(2854.76443861835998*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-2039.11745615597141*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(509.77936403899285*Power(cosbetaovertwo,4) - 33.9852909359328569*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_0_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(96.1249187255833262*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-961.24918725583326*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(2691.49772431633313*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-2691.49772431633313*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(961.24918725583326*Power(cosbetaovertwo,5) - 96.124918725583326*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_1_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(33.9852909359328569*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-509.77936403899285*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(2039.11745615597141*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-2854.76443861835998*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(1427.38221930917999*Power(cosbetaovertwo,6) - 203.911745615597141*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_2_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(8.12403840463596036*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(-203.100960115899009*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(1218.60576069539405*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-2437.21152139078811*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1706.04806497355168*Power(cosbetaovertwo,7) - 341.209612994710335*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))))));
    return;
  }
  
  void D_8_3_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) + Power(sinbetaovertwo,2)*(-55.*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(550.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-1650.*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(1650.*Power(cosbetaovertwo,8) - 462.*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_4_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.74596669241483377*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(170.411267233126343*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-852.05633616563171*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(1278.08450424844757*Power(cosbetaovertwo,9) - 511.23380169937903*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_5_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(27.9284800875378823*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-307.213280962916706*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(768.03320240729176*Power(cosbetaovertwo,10) - 460.819921444375059*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_6_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-60.332412515993424*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(331.828268837963834*Power(cosbetaovertwo,11) - 331.828268837963834*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_7_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(82.61355820929153*Power(cosbetaovertwo,12) - 181.749828060441367*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_3(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -66.0908465674332242*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_8_neg8_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,12);
    return;
  }
  
  void D_8_neg7_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,11)*(127.984374046209251*Power(cosbetaovertwo,5) - 42.6614580154030835*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(257.033071802054297*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-186.933143128766762*Power(cosbetaovertwo,4) + 23.3666428910958452*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(396.610640301038822*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-475.932768361246587*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(129.799845916703615*Power(cosbetaovertwo,3) - 7.2111025509279786*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(495.*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-880.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(396.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-48.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_neg3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(511.23380169937903*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1278.08450424844757*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(852.05633616563171*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-170.411267233126343*Power(cosbetaovertwo,3) + 7.74596669241483377*cosbetaovertwo*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_neg2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(440.49971623146365*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1510.28474136501823*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(1415.89194502970459*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-419.523539268060619*Power(cosbetaovertwo,4) + 31.4642654451045464*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_neg1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(315.898717946116394*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-1474.19401708187651*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1895.39230767669837*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-789.74679486529099*Power(cosbetaovertwo,5) + 87.749643873921221*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_0_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(186.145104689862849*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-1191.32867001512223*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(2084.82517252646391*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-1191.32867001512223*Power(cosbetaovertwo,6) + 186.145104689862849*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_1_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(87.749643873921221*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-789.74679486529099*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(1895.39230767669837*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1474.19401708187651*Power(cosbetaovertwo,7) + 315.898717946116394*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_2_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(31.4642654451045464*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-419.523539268060619*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(1415.89194502970459*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1510.28474136501823*Power(cosbetaovertwo,8) + 440.49971623146365*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_3_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.74596669241483377*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(-170.411267233126343*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(852.05633616563171*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-1278.08450424844757*Power(cosbetaovertwo,9) + 511.23380169937903*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)))));
    return;
  }
  
  void D_8_4_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) + Power(sinbetaovertwo,2)*(-48.*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(396.*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-880.*Power(cosbetaovertwo,10) + 495.*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_5_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-7.21110255092797859*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(129.799845916703615*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-475.932768361246587*Power(cosbetaovertwo,11) + 396.610640301038822*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_6_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(23.3666428910958452*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-186.933143128766762*Power(cosbetaovertwo,12) + 257.033071802054297*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_7_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(-42.6614580154030835*Power(cosbetaovertwo,13) + 127.984374046209251*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_4(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_8_neg8_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 23.6643191323984642*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,13);
    return;
  }
  
  void D_8_neg7_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,12)*(76.909037180295009*Power(cosbetaovertwo,4) - 17.7482393492988481*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,11)*(168.499258158604366*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-84.249629079302183*Power(cosbetaovertwo,3) + 6.48074069840786023*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(286.*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-234.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(39.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(396.610640301038822*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-475.932768361246587*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(129.799845916703615*Power(cosbetaovertwo,3) - 7.2111025509279786*cosbetaovertwo*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(460.819921444375059*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-768.03320240729176*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(307.213280962916706*Power(cosbetaovertwo,4) - 27.9284800875378823*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(453.784089628536888*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-1021.014201664208*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(567.23011203567111*Power(cosbetaovertwo,5) - 75.630681604756148*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_neg1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(379.66300846935299*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-1138.98902540805897*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(854.24176905604423*Power(cosbetaovertwo,6) - 158.192920195563746*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_0_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(268.462287854365124*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-1073.8491514174605*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(1073.8491514174605*Power(cosbetaovertwo,7) - 268.462287854365124*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_1_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(158.192920195563746*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-854.24176905604423*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(1138.98902540805897*Power(cosbetaovertwo,8) - 379.66300846935299*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_2_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(75.630681604756148*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-567.23011203567111*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(1021.014201664208*Power(cosbetaovertwo,9) - 453.784089628536888*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_3_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(27.9284800875378823*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-307.213280962916706*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(768.03320240729176*Power(cosbetaovertwo,10) - 460.819921444375059*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_4_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(7.21110255092797859*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(-129.799845916703615*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(475.932768361246587*Power(cosbetaovertwo,11) - 396.610640301038822*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2))));
    return;
  }
  
  void D_8_5_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) + Power(sinbetaovertwo,2)*(-39.*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(234.*Power(cosbetaovertwo,12) - 286.*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_6_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-6.48074069840786023*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(84.249629079302183*Power(cosbetaovertwo,13) - 168.499258158604366*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_7_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(17.7482393492988481*Power(cosbetaovertwo,14) - 76.909037180295009*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_5(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -23.6643191323984642*Power(cosbetaovertwo,13)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_8_neg8_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,14);
    return;
  }
  
  void D_8_neg7_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,13)*(38.3405790253616279*Power(cosbetaovertwo,3) - 5.4772255750516611*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,12)*(91.*Power(cosbetaovertwo,4) + Power(sinbetaovertwo,2)*(-28.*Power(cosbetaovertwo,2) + Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg5_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,11)*(168.499258158604366*Power(cosbetaovertwo,5) + Power(sinbetaovertwo,2)*(-84.249629079302183*Power(cosbetaovertwo,3) + 6.48074069840786023*cosbetaovertwo*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg4_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(257.033071802054297*Power(cosbetaovertwo,6) + Power(sinbetaovertwo,2)*(-186.933143128766762*Power(cosbetaovertwo,4) + 23.3666428910958452*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg3_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(331.828268837963834*Power(cosbetaovertwo,7) + Power(sinbetaovertwo,2)*(-331.828268837963834*Power(cosbetaovertwo,5) + 60.332412515993424*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg2_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(367.6071272432024*Power(cosbetaovertwo,8) + Power(sinbetaovertwo,2)*(-490.142836324269866*Power(cosbetaovertwo,6) + 122.535709081067467*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_neg1_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(351.499644381043436*Power(cosbetaovertwo,9) + Power(sinbetaovertwo,2)*(-615.12437766682601*Power(cosbetaovertwo,7) + 205.041459222275337*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_0_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(289.972412480911708*Power(cosbetaovertwo,10) + Power(sinbetaovertwo,2)*(-662.79408567065533*Power(cosbetaovertwo,8) + 289.972412480911708*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_1_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(205.041459222275337*Power(cosbetaovertwo,11) + Power(sinbetaovertwo,2)*(-615.12437766682601*Power(cosbetaovertwo,9) + 351.499644381043436*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_2_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(122.535709081067467*Power(cosbetaovertwo,12) + Power(sinbetaovertwo,2)*(-490.142836324269866*Power(cosbetaovertwo,10) + 367.6071272432024*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_3_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(60.332412515993424*Power(cosbetaovertwo,13) + Power(sinbetaovertwo,2)*(-331.828268837963834*Power(cosbetaovertwo,11) + 331.828268837963834*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_4_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(23.3666428910958452*Power(cosbetaovertwo,14) + Power(sinbetaovertwo,2)*(-186.933143128766762*Power(cosbetaovertwo,12) + 257.033071802054297*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_5_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(6.48074069840786023*Power(cosbetaovertwo,15) + Power(sinbetaovertwo,2)*(-84.249629079302183*Power(cosbetaovertwo,13) + 168.499258158604366*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,2)));
    return;
  }
  
  void D_8_6_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) + Power(sinbetaovertwo,2)*(-28.*Power(cosbetaovertwo,14) + 91.*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_7_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(-5.47722557505166113*Power(cosbetaovertwo,15) + 38.3405790253616279*Power(cosbetaovertwo,13)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_8_6(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*Power(cosbetaovertwo,14)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_8_neg8_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 4.*cosbetaovertwo*Power(sinbetaovertwo,15);
    return;
  }
  
  void D_8_neg7_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,14)*(15.*Power(cosbetaovertwo,2) - 1.*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg6_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,13)*(38.3405790253616279*Power(cosbetaovertwo,3) - 5.4772255750516611*cosbetaovertwo*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg5_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,12)*(76.909037180295009*Power(cosbetaovertwo,4) - 17.7482393492988481*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg4_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,11)*(127.984374046209251*Power(cosbetaovertwo,5) - 42.6614580154030835*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg3_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,10)*(181.749828060441367*Power(cosbetaovertwo,6) - 82.61355820929153*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg2_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,9)*(223.718573211970937*Power(cosbetaovertwo,7) - 134.231143927182562*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_neg1_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,8)*(240.655355228176878*Power(cosbetaovertwo,8) - 187.176387399693127*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_0_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,7)*(226.892044814268444*Power(cosbetaovertwo,9) - 226.892044814268444*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_1_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,6)*(187.176387399693127*Power(cosbetaovertwo,10) - 240.655355228176878*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_2_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,5)*(134.231143927182562*Power(cosbetaovertwo,11) - 223.718573211970937*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_3_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,4)*(82.61355820929153*Power(cosbetaovertwo,12) - 181.749828060441367*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_4_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,3)*(42.6614580154030835*Power(cosbetaovertwo,13) - 127.984374046209251*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_5_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,2)*(17.7482393492988481*Power(cosbetaovertwo,14) - 76.909037180295009*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_6_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = sinbetaovertwo*(5.47722557505166113*Power(cosbetaovertwo,15) - 38.3405790253616279*Power(cosbetaovertwo,13)*Power(sinbetaovertwo,2));
    return;
  }
  
  void D_8_7_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16) - 15.*Power(cosbetaovertwo,14)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_8_8_7(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = -4.*Power(cosbetaovertwo,15)*sinbetaovertwo;
    return;
  }
  
  void D_8_neg8_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(sinbetaovertwo,16);
    return;
  }
  
  void D_8_neg7_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 4.*cosbetaovertwo*Power(sinbetaovertwo,15);
    return;
  }
  
  void D_8_neg6_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*Power(cosbetaovertwo,2)*Power(sinbetaovertwo,14);
    return;
  }
  
  void D_8_neg5_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 23.6643191323984642*Power(cosbetaovertwo,3)*Power(sinbetaovertwo,13);
    return;
  }
  
  void D_8_neg4_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*Power(cosbetaovertwo,4)*Power(sinbetaovertwo,12);
    return;
  }
  
  void D_8_neg3_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 66.0908465674332242*Power(cosbetaovertwo,5)*Power(sinbetaovertwo,11);
    return;
  }
  
  void D_8_neg2_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*Power(cosbetaovertwo,6)*Power(sinbetaovertwo,10);
    return;
  }
  
  void D_8_neg1_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 106.957935656967501*Power(cosbetaovertwo,7)*Power(sinbetaovertwo,9);
    return;
  }
  
  void D_8_0_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 113.446022407134222*Power(cosbetaovertwo,8)*Power(sinbetaovertwo,8);
    return;
  }
  
  void D_8_1_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 106.957935656967501*Power(cosbetaovertwo,9)*Power(sinbetaovertwo,7);
    return;
  }
  
  void D_8_2_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 89.4874292847883747*Power(cosbetaovertwo,10)*Power(sinbetaovertwo,6);
    return;
  }
  
  void D_8_3_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 66.0908465674332242*Power(cosbetaovertwo,11)*Power(sinbetaovertwo,5);
    return;
  }
  
  void D_8_4_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 42.6614580154030835*Power(cosbetaovertwo,12)*Power(sinbetaovertwo,4);
    return;
  }
  
  void D_8_5_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 23.6643191323984642*Power(cosbetaovertwo,13)*Power(sinbetaovertwo,3);
    return;
  }
  
  void D_8_6_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 10.9544511501033223*Power(cosbetaovertwo,14)*Power(sinbetaovertwo,2);
    return;
  }
  
  void D_8_7_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = 4.*Power(cosbetaovertwo,15)*sinbetaovertwo;
    return;
  }
  
  void D_8_8_8(const double sinbetaovertwo, const double cosbetaovertwo, double& Mag) {
    Mag = Power(cosbetaovertwo,16);
    return;
  }
  
}
