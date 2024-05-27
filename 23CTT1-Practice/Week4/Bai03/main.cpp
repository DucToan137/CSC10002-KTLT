#include<iostream>
#include"MangTaiKhoan.h"
#define maxlen 100

int main() {

	
	///////////////////////////// main

	int n = 0;
	std::cout << "Nhap so luong tai khoan: ";
	std::cin >> n;
	TaiKhoan* t = new TaiKhoan[n];

	t = NhapMang(t, n);
	
	NhapTaiKhoan(t, n);

	XuatMang(t, n);

	//XuatMang(t, n);
	//char* c = new char[maxlen];
	//std::cout << "Nhap ten dang nhap tai khoan muon xoa\n";
	//std::cin.getline(c, maxlen);
	//XoaTaiKhoan(t, n, c);
	//XuatMang(t, n);

	////////////////////////////




	/*TaiKhoan tk;
	
	char* c = new char[maxlen];
	std::cin.getline(c, maxlen);

	Nhap(tk);
	std::cout << chuoiCon(tk,c);*/

	
	return 0;
}