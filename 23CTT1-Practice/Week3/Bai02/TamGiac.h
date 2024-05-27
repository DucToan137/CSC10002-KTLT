#pragma once
#include"Diem.h"
#include<iostream>

struct TamGiac {
	Diem* A;
	Diem* B;
	Diem* C;
};

void NhapTamGiac(TamGiac* t);
void XuatTamGiac(TamGiac* t);
bool check(TamGiac* t);
float TinhChuVi(TamGiac t);
//float TinhChuVi(TamGiac* t);
float TinhDienTich(TamGiac t);
//float TinhDienTich(TamGiac* t);
void XuatTamGiac(TamGiac t);
