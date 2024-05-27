#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string>
#include<iostream>
using namespace std;
#define MAXLEN 100

// BAI 2
// thap phan sang nhi phan
void DtoB(long d, int mangKySo[], int& soKySo)
{
	int n = 0;
	int mangPhu[MAXLEN];
	while (d > 0)
	{
		mangPhu[n] = d % 2;
		n++;
		d /= 2;
	}
	for (int i = 0; i < n; i++)
	{
		mangKySo[i] = mangPhu[n - i - 1];
	}
	soKySo = n;
}
// nhi phan sang thap phan
long BtoD(int mangKySo[], int soKySo)
{
	long d = 0;
	int tempP = 1;
	for (int i = soKySo - 1; i >= 0; i--)
	{
		d += mangKySo[i] * tempP;
		tempP *= 2;
	}
	return d;
}
// thap phan sang thap luc phan
int HtoD(string a)
{
	int result = 0;
	int c = 1;
	for (int i = a.length(); i >= 0; i--)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			result += (a[i] - '0') * c;
		}
		else if (a[i] >= 'A' && a[i] <= 'F')
		{
			result += (a[i] - 'A') * c;
		}
		c *= 16;
	}
	return result;
}
// thap luc phan sang thap phan
string DtoH(int a)
{
	string result = "";
	while (a != 0)
	{
		int b = a % 16;
		char c;
		if (b < 10)
		{
			c = b + '0';
		}
		else
		{
			c = b - 10 + 'A';
		}
		result += c;
		a /= 16;
	}
	return result;
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
	// chuyển đổi sang thập phân
	DaoMang(mang, n);
	long dKq = BtoD(mang, n);
	printf("Chuyen doi b= ");
	XuatMang(mang, n);
	printf(" sang thap phan: %d\n", dKq);*/
}
