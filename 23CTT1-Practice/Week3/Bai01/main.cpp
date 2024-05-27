#include<iostream>
#include"MangDiem.h"

void main()
{
	int n;
	printf("Nhap mang cac diem, mang a\n");
	Diem* a = NhapMangDiem(n);
	printf("Mang a vua nhap\n");
	XuatMangDiem(a, n);
	Diem A;
	A.x = 0;
	A.y = 0;

	std::cout << "Diem xa diem A nhat: ";
	XuatDiem(TimXaNhat(a, n, A));
	std::cout << "\n";

	std::cout << "Cac diem co toa do duong: \n";
	LietKeToaDoDuong(a, n);
	std::cout << "\n";

	std::cout << "Mang cac diem khoang cach tang dan: \n";
	SapTangTheoKhoangCach(a, n);
	XuatMangDiem(a, n);
}