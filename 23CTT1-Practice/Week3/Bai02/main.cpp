#include<iostream>
#include"MangTamGiac.h"

int main() {


	int n = 0;
	TamGiac* t = NhapMangTamGiac(n);

	XuatMangTamGiac(t, n);

	std::cout << "Tam giac co chu vi nho nhat: \n";
	XuatTamGiac(TimChuViNhoNhat(t, n));

	std::cout << "So tam giac lon hon dien tich trung binh: " << DemTamGiacLonHonDTichBinh(t, n) << "\n";
	

	std::cout << "Mang tam giac giam dan theo chu vi\n";
	SapGiamTheoChuVi(t,n);
	XuatMangTamGiac(t, n);

	return 0;
}