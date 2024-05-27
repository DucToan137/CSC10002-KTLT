#include<iostream>
#include<conio.h>
#include"PhanSo.h"

void main() {
	PhanSo* pPS = TongPhanSoTuChuoi("14/56+24/45");
	printf("Tong cua Phan so duoc tu chuoi '14/56+24/45' la:\n");
	printf("\t%s\n", XuatPhanSo(pPS));
	free(pPS);

	getch();
}