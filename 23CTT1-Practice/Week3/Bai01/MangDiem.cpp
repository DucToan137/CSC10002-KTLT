#include"MangDiem.h"


Diem* NhapMangDiem(int& n) {
	std::cout << "Nhap n: ";
	std::cin >> n;
	Diem* a = new Diem[n];
	for (int i = 0; i < n; i++)
	{
		std::cout << "Nhap diem thu a[" << i << "]\n";
		NhapDiem(&a[i]);
	}
	return a;
}

void XuatMangDiem(Diem* a, int n) {
	for (int i = 0; i < n; i++)
	{
		std::cout << "Diem a[" << i << "]: ";
		XuatDiem(a[i]);
		std::cout << "\n";
	}
}

Diem TimXaNhat(Diem* a, int n, Diem A) {
	Diem kq = a[0];
	float kc = TinhKhoangCach(a[0], A);
	for (int i = 1; i < n; i++)
	{
		float kc2 = TinhKhoangCach(a[i], A);
		if (kc2 > kc)
		{
			kq = a[i];
			kc = kc2;
		}
	}
	return kq;
}

void LietKeToaDoDuong(Diem* a, int n)
{
	for (int i = 0; i < n; i++) {
		if (a[i].x > 0 && a[i].y > 0)
		{
			XuatDiem(a[i]);
		}
	}
}

void SapTangTheoKhoangCach(Diem* a, int n)
{
	Diem O;
	O.x = 0;
	O.y = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (TinhKhoangCach(a[i], O) > TinhKhoangCach(a[j], O)) {
				std::swap(a[i], a[j]);			}
		}
	}
}