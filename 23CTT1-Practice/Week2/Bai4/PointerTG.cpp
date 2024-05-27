#include<iostream>
#include<string>
#include<sstream>
#include<stdio.h>
#include<iomanip>
#include<cmath>
#include<conio.h>

using namespace std;

struct ThoiGian {
	int gio;
	int phut;
	int giay;
};

ThoiGian* TaoThoiGian(int h, int m, int s)
{
	ThoiGian* pTG = new ThoiGian;

	pTG->giay = s;
	pTG->phut = m;
	pTG->gio = h;

	return pTG;
}

void HopLeThoiGian(ThoiGian* pTG)
{
	if (pTG->giay >= 60)
	{
		pTG->giay = pTG->giay - 60;
		pTG->phut++;
	}
	if (pTG->phut >= 60)
	{
		pTG->phut = pTG->phut - 60;
		pTG->gio++;
	}
}

void PrintTG(ThoiGian *pTG)
{
	string result = "";
	stringstream out;
	out << pTG->gio << ":" << setw(2) << setfill('0') << pTG->phut <<  ":" << setw(2) << setfill('0') << pTG->giay;
	result = out.str();
	cout << result;
}

ThoiGian* KhoangCachThoiGian(ThoiGian* pTG1, ThoiGian* pTG2)
{
	ThoiGian* result = new ThoiGian;

	int tg1 = pTG1->gio * 3600 + pTG1->phut * 60 + pTG1->giay;
	int tg2 = pTG2->gio * 3600 + pTG2->phut * 60 + pTG2->giay;
	int res = abs(tg2 - tg1);

	result->gio = res / 3600;
	result->phut = (res % 3600) / 60;
	result->giay = (res % 3600) % 60;

	HopLeThoiGian(result);


	return result;
}

void main()
{
	// khởi động random
	srand(3072);
	// khai báo con trỏ ThoiGian
	ThoiGian* pTG1, * pTG2;
	// tạo giá trị
	pTG1 = TaoThoiGian(rand() % 100, rand() % 100, rand() % 100);
	pTG2 = TaoThoiGian(rand() % 100, rand() % 100, rand() % 100);
	// xuất ra màn hình
	printf("Thoi gian 1: ");
	PrintTG(pTG1);
	printf("\n");
	printf("Thoi gian 2: ");
	PrintTG(pTG2);
	printf("\n\n");
	// làm hợp lệ thời gian
	HopLeThoiGian(pTG1);
	HopLeThoiGian(pTG2);
	printf("Thoi gian sau khi hop le\n");
	printf("Thoi gian 1: ");
	PrintTG(pTG1);
	printf("\n");
	printf("Thoi gian 2: ");
	PrintTG(pTG2);
	printf("\n\n");
	// tính khoảng cách
	ThoiGian* p = KhoangCachThoiGian(pTG1, pTG2);
	printf("Khoang cach 2 thoi gian tren: ");
	PrintTG(p);
	printf("\n");
	//getch();
}
