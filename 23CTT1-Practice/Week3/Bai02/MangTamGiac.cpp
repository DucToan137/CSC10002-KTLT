#include"MangTamGiac.h"
#include<iostream>


TamGiac* NhapMangTamGiac(int& n) {
	std::cout << "Nhap so luong tam giac: ";
	std::cin >> n;

	TamGiac* t = new TamGiac[n];

	for (int i = 0; i < n; i++) {
		std::cout << "Nhap tam giac thu " << i + 1 << "\n";
		NhapTamGiac(&t[i]);
	}

	return t;
}

void XuatMangTamGiac(TamGiac* t, int n) {
	for (int i = 0; i < n; i++)
	{
		std::cout << "Tam giac thu " << i + 1 << "\n";
		XuatTamGiac(&t[i]);
		std::cout << "P=" << TinhChuVi(t[i]) << " S=" << TinhDienTich(t[i]);
		std::cout << "\n";
	}
}

TamGiac TimChuViNhoNhat(TamGiac* t, int n) {
	TamGiac result = t[0];
	
	for (int i = 0; i < n; i++)
	{
		if (TinhChuVi(t[i]) < TinhChuVi(result))
		{
			result = t[i];
		}
	}

	return result;
}

float TinhTongDienTich(TamGiac* t, int n) {
	float result = 0;

	for (int i = 0; i < n; i++)
	{
		result += TinhDienTich(t[i]);
	}

	return result;
}

int DemTamGiacLonHonDTichBinh(TamGiac* t, int n) {
	float tb = TinhTongDienTich(t, n) / n;
	
	int result = 0;

	for (int i = 0; i < n; i++) {
		if (TinhDienTich(t[i]) > tb)
		{
			result++;
		}
	}

	return result;
}


void SapGiamTheoChuVi(TamGiac* t, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (TinhChuVi(t[i]) < TinhChuVi(t[j])) {
				std::swap(t[i], t[j]);
			}
		}
	}
}
