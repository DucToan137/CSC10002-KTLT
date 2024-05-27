#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string>
#include<iostream>
using namespace std;
#define MAXLEN 100

// BAI 3
// nhap ma tran
void nhapMaTran(int a[][MAXLEN], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
		}
	}
}
// in ma tran
void inMaTran(int a[][MAXLEN], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
// tim kiem 
bool timKiem(int a[][MAXLEN], int r, int c, int n)
{
	bool flag = false;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == n)
			{
				flag = true;
			}
		}
	}
	return flag;
}
// dao ma tran
void daoMaTran(int a[][MAXLEN], int r, int c)
{
	int temp[MAXLEN][MAXLEN];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			temp[j][i] = a[i][j];
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			temp[i][j] = a[i][j];
		}
	}
}
// tong cac phan tu bien
int tongCacPhanTuBien(int a[][MAXLEN], int r, int c)
{
	int tong = 0;
	for (int i = 0; i < r; i++)
	{
		tong += a[i][0] + a[i][c - 1];
	}
	for (int j = 1; j < c - 1; j++)
	{
		tong += a[0][j] + a[r - 1][j];
	}
	return tong;
}
// xoay ma tran
void rotateMatrix(int matrix[][MAXLEN], int r, int c) {
	int result[MAXLEN][MAXLEN];

	// Dịch xoay vòng cột của ma trận
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			result[j][r - 1 - i] = matrix[i][j];
		}
	}

	// In ma trận đã dịch xoay
	for (int i = 0; i < c; ++i) {
		for (int j = 0; j < r; ++j) {
			std::cout << result[i][j] << " ";
		}
		cout << endl;
	}
}

void main()
{
	srand((unsigned int)time(NULL));
	long d = 163 + rand() % 10000;
	int mang[MAXLEN];
	int n = 0;
	/* chuyển đổi sang nhị phân
	DtoB(d, mang, n);
	printf("Chuyen doi d= %d sang nhi phan: ", d);
	XuatMang(mang, n);
	printf("\n");
	 chuyển đổi sang thập phân
	DaoMang(mang, n);
	long dKq = BtoD(mang, n);
	printf("Chuyen doi b= ");
	XuatMang(mang, n);
	printf(" sang thap phan: %d\n", dKq);*/
}
