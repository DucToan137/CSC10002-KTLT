#include<iostream>
#include"DuongTron.h"
#include<iomanip>

DuongTron* ChuViLonNhat(DuongTron** l, int n) {
	DuongTron* result = l[0];

	for (int i = 0; i < n; i++)
	{
		if (TinhChuVi(l[i]) > TinhChuVi(result))
		{
			result = l[i];
		}
	}

	return result;
}

float TongDienTich(DuongTron** l, int n) {
	float result = 0;

	for (int i = 0; i < n; i++)
	{
		result += TinhDienTich(l[i]);
	}

	return result;
}

int XuatCacDuongTronDTLonHonTB(DuongTron** l, int n) {
	int result = 0;

	float tb = TongDienTich(l, n) / n;

	for (int i = 0; i < n; i++)
	{
		if (TinhDienTich(l[i]) > tb)
		{
			PrintDuongTron(l[i]);
			std::cout << " voi S=" << std::fixed << std::setprecision(2) << TinhDienTich(l[i]) << "\n";
			result++;
		}
	}
	
	return result;
}

void XuatDuongTronChuViGiam(DuongTron** l, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (TinhChuVi(l[i]) < TinhChuVi(l[j]))
			{
				std::swap(l[i], l[j]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		PrintDuongTron(l[i]);
		std::cout << " voi P=" << std::fixed << std::setprecision(2) << TinhChuVi(l[i]) << "\n";
	}
}

void XoaDsDuongTron(DuongTron** l, int n) {
	for (int i = 0; i < n; i++)
	{
		delete l[i];
	}

	delete[]l;
}