#include"PhanSo.h"
#include<iostream>
#include<string.h>



int demSoChuSo(int n)
{
	int dem = 0;

	while (n > 0)
	{
		n /= 10;
		dem++;
	}

	return dem;
}

char* XuatPhanSo(PhanSo* pPS)
{
	char num[MAXLEN];
	char denom[MAXLEN];

	sprintf(num, "%d", pPS->tu);
	sprintf(denom, "%d", pPS->mau);

	strcat(num, "/");
	
	char* result = strcat(num, denom);

	return result;
}

PhanSo* tachPS(char* c)
{
	PhanSo *a = new PhanSo;

	char* token = strtok(c, "/");
	a->tu = atoi(token);

	token = strtok(NULL, "/");
	a->mau = atoi(token);

	return a;
}

PhanSo* tinhTongPS(PhanSo* Ps1, PhanSo* Ps2)
{
	PhanSo* result = new PhanSo;

	result->tu = Ps1->tu * Ps2->mau + Ps1->mau * Ps2->tu;
	result->mau = Ps1->mau * Ps2->mau;

	RutGon(result);

	return result;
}

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void RutGon(PhanSo* Ps)
{
	int common = gcd(Ps->tu, Ps->mau);

	Ps->tu = Ps->tu / common;
	Ps->mau = Ps->mau / common;
}

PhanSo* TongPhanSoTuChuoi(const char* s)
{
	char* tmp = new char[MAXLEN];
	tmp = strcpy(tmp, s);

	char* token1 = strtok(tmp, "+");

	char *token2 = strtok(NULL, "+");
	
	PhanSo* PS1 = new PhanSo;
	PS1 = tachPS(token1);

	PhanSo* PS2 = new PhanSo;
	PS2 = tachPS(token2);

	PhanSo *result = tinhTongPS(PS1,PS2);

	return result;
}