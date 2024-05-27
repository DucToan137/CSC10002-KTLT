#include<iostream>
#include<string.h>
#include"Nguoi.h"



void main() {
	int n = 3;
	Nguoi** pDsNguoi = (Nguoi**)malloc(n * sizeof(Nguoi*));
	pDsNguoi[0] = TaoNguoi(" lE tHI duNG ", "HCM");
	pDsNguoi[1] = TaoNguoi(" ngUYen VAN ngUyEn ", "HN");
	pDsNguoi[2] = TaoNguoi(" tRan trung trUc ", "DN");
	printf("Danh sach Nguoi moi tao:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%s\n", XuatNguoi(pDsNguoi[i]));
	}
	printf("\nDanh sach Nguoi sau khi chuan hoa ten:\n");
	for (int i = 0; i < n; ++i)
	{
		ChuanHoaTen(pDsNguoi[i]);
		printf("%s\n", XuatNguoi(pDsNguoi[i]));
	}
	for (int i = 0; i < n; ++i)
	{
		free(pDsNguoi[i]);
	}
	free(pDsNguoi);

}