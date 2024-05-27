#pragma once




struct Diem {
	float x;
	float y;
};

struct DuongTron {
	Diem* tam;
	float bankinh;
};

DuongTron* TaoDuongTron(float xV, float yV, float rV);
void XoaDuongTron(DuongTron* p);
void PrintDuongTron(DuongTron* p);
float TinhChuVi(DuongTron* p);
float TinhDienTich(DuongTron* p);