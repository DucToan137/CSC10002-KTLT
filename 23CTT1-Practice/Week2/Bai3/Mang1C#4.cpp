#include<iostream>
using namespace std;

// phat sinh mang
int* phatsinhMang(int& n)
{
	srand(time(NULL) + clock());
	int left = 10;

	int min = -50;
	int max = 50;

	n = rand() % left + 10;
	//n = m;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (min - max + 1) + min;
	}

	return a;
}

// xuat mang
void xuatMang(int* a, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

// kiem tra 1 phan tu co ton tai trong mang khong
bool kiemtraTonTai(int* a, int n, int value) {
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == value)
		{
			flag = true;
		}
	}
	return flag;
}

void kiemtraPhanTuKhacNhau(int* a, int n, int* b, int m)
{
	for (int i = 0; i < n; i++)
	{
		if (!kiemtraTonTai(b, m, a[i]))
		{

			cout << a[i] << " ";
		}
	}
}

void KhacNhauDoiMot(int* a, int n, int* b, int m)
{
	int* c = new int[m + n];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (!kiemtraTonTai(b, m, a[i]))
		{
			c[j] = a[i];
			j++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (!kiemtraTonTai(a, n, b[i]))
		{
			c[j] = b[i];
			j++;
		}
	}
	for (int i = 0; i < j; i++)
	{
		cout << c[i] << " ";
	}
}

int main() {
	int n = 0;
	int* p = phatsinhMang(n);
	//cout << n << endl;
	cout << "Mang p:\n";
	xuatMang(p, n);

	int m = 0;
	int* q = phatsinhMang(m);
	//cout << endl << m << endl;
	cout << "\nMang q:\n";
	xuatMang(q, m);

	cout << "\nCac phan chi co trong mang p ma khong co trong mang q: \n";
	kiemtraPhanTuKhacNhau(p, n, q, m);
	cout << "\nMang cac ohan tu khac nhau tung doi mot:\n";
	KhacNhauDoiMot(p, n, q, m);


	return 0;
}