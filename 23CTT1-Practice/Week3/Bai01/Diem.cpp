#include"Diem.h"
#include<iostream>

void NhapDiem(Diem* d) {
	std::cout << "Nhap x: ";
	std::cin >> d->x;

	std::cout << "Nhap y: ";
	std::cin >> d->y;
}
void XuatDiem(Diem d) {
	std::cout << "(" << d.x << "," << d.y << ")" << " ";
}

float TinhKhoangCach(Diem A, Diem B) {
	float result = 0;

	result = sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));

	return result;
}