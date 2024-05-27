#include<iostream>
#include<cstdlib>
#include<time.h>
#include<math.h>
using namespace std;

// BAI 2
// phat sinh mang
int* phatsinhMang(int &n)
{
	srand(time(0));
	int left = 10;

	int min = -1000;
	int max = 2000;

	n = rand() % left + 10;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (min - max + 1) + min;
	}
	return a;
}

// xuat mang
void xuatMang(int* a, int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

// tim so chinh phuong dau tien
bool ktraSoChinhPhuong(int n)
{
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		if (n == i * i)
		{
			flag = true;
		}
	}
	return flag;
}

int timSoChinhPhuong(int* a, int n)
{
	int so = -1001;
	for (int i = 0; i < n; i++)
	{
		if (ktraSoChinhPhuong(a[i])==true)
		{
			so = a[i];
			return so;
		}
	}
	if (so == -1001)
	{
		return -1001;
	}
}

// mang con
bool ktraSoNguyenTo(int n)
{
	int dem = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			dem++;
		}
	}
	if (dem == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void mangSoNguyenTo(int* a,int n)
{
	int j = 0;
	int* b = new int[n];
	for(int i = 0; i < n;i++)
	{
		if (ktraSoNguyenTo(a[i]))
		{
			b[j]=a[i];
			j++;
		}
	}
	cout << "\nMang so nguyen to: ";
	for (int i = 0; i < j; i++)
	{
		cout << b[i] << " ";
	}
	delete[]b;
}

int main()
{
	int n = 0;
	int *a = phatsinhMang(n);
	xuatMang(a, n);
	if (timSoChinhPhuong(a, n) != -1001)
	{
		cout << "\nSo chinh phuong dau tien: " << timSoChinhPhuong(a, n);
	}
	else
	{
		cout << "\nMang da cho khong co so chinh phuong";
	}
	mangSoNguyenTo(a, n);
	delete[]a;
	return 0;
}