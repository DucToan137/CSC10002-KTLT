#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string>
#include<iostream>
using namespace std;
#define MAXLEN 100

// BAI 1
// phat sinh mang
int* phatSinhMang(int &n)
{
	srand(time(0));
	n = rand() % (3 - 100 + 1) + 3;
	int* a = new int[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
	return a;
}

// nhap, xuat mang
void NhapMang(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

void XuatMang(int *mang, int n)
{
	// code ở đây
	for (int i = 0; i < n; i++)
	{
		cout << mang[i] << " ";
	}
}

// phan tu lon nhat
int Max(int *a, int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

// phan tu nho nhat
int Min(int *a, int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}

// tinh tong tat cac phan tu mang
int tinhTong(int *a, int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += a[i];
	}
	return tong;
}

// tinh tong cac phan tu xuat hien nhieu nhat
int soLanXuatHien(int *a, int n, int b)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b)
		{
			dem++;
		}
	}
	return dem;
}

int tongCacPhanTuXuatHienNN(int *a, int n)
{
	int max = soLanXuatHien(a, n, a[0]);
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (soLanXuatHien(a, n, a[i]) > max)
		{
			max = soLanXuatHien(a, n, a[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (soLanXuatHien(a, n, a[i]) == max)
		{
			tong += a[i];
		}
	}
	return tong;
}

// tim phan tu trung vi
void bubbleSort(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int phanTuTrungVi(int *a, int n)
{
	bubbleSort(a, n);
	if (n % 2 != 0)
	{
		return a[n / 2 + 1];
	}
	else
	{
		int tv = ((n / 2) + (n / 2 + 1)) / 2;
		return a[tv];
	}

}
// mang con
bool checkMangCon(int *a, int n, int b[], int m)
{
	if (m > n)
	{
		return false;
	}
	for (int i = 0; i < n - m; i++)
	{
		int j;
		for (j = 0; j < m; ++j)
		{
			if (a[i + j] != b[i])
			{
				break;
			}
		}
		if (j == m)
		{
			return true;
		}
	}
	return false;
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
	int *a = phatSinhMang(n);
	XuatMang(a,n);

}
