#include<iostream>
#include<random>
#include"MangDuongTron.h"


void main()
{
	srand(4003);
	// số lượng đường tròn
	int n = 5 + rand() % 20;
	// tạo mảng các đường tròn
	DuongTron** listDT = (DuongTron**)malloc(n * sizeof(DuongTron*));
	if (listDT == NULL)
	{
		return;
	}
	float xV, yV, rV;
	for (int i = 0; i < n; ++i)
	{
		xV = (rand() % 1000) * 1.0f / 50;
		yV = (rand() % 1000) * 1.0f / 50;
		rV = (rand() % 1000 + 1) * 1.0f / 50;
		listDT[i] = TaoDuongTron(xV, yV, rV);
	}
	// Xuất đường tròn có chu vi lớn nhất
	printf("Duong tron co chu vi lon nhat: ");
	DuongTron* pDTPMax = ChuViLonNhat(listDT, n);
	PrintDuongTron(pDTPMax);
	printf("\n\n");
	// Tổng diện tích các đường tròn
	printf("Tong dien tich: %0.2f", TongDienTich(listDT, n));
	printf("\n\n");
	// Xuất các đường tròn có diện tích lớn hơn diện tích trung bình
	printf("Cac duong tron co dien tich lon hon TB:\n");
	int dem = XuatCacDuongTronDTLonHonTB(listDT, n);
	printf("So luong: %d", dem);
	printf("\n\n");
	// Xuất ds đường tròn giảm dần theo chu vi
	printf("Ds duong tron chu vi giam dan:\n");
	XuatDuongTronChuViGiam(listDT, n);
	printf("\n\n");
	XoaDsDuongTron(listDT, n);
}