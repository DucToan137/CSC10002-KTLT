#include<iostream>
#include"DuongTron.h"

#define PI 3.14156

DuongTron* TaoDuongTron(float xV, float yV, float rV) {
	DuongTron* p = new DuongTron;
	p->tam = new Diem;

	p->tam->x = xV;
	p->tam->y = yV;
	p->bankinh = rV;

	return p;
}

void XoaDuongTron(DuongTron* p) {
	delete p;
}

void PrintDuongTron(DuongTron* p) {
	std::cout << "[(" << p->tam->x << "," << p->tam->y << ")," << p->bankinh << ")]";
}

float TinhChuVi(DuongTron *p) {
	float result = (float)(p->bankinh * 2 * PI);

	return result;
}

float TinhDienTich(DuongTron *p) {
	float result = (float)(p->bankinh * p->bankinh * PI);

	return result;
}