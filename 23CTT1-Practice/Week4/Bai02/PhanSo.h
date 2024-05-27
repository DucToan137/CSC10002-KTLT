#ifndef _PHANSO_H_
#define _PHANSO_H_



#define MAXLEN 100

struct PhanSo {
	int tu;
	int mau;
};

char* XuatPhanSo(PhanSo* pPS);
PhanSo* TongPhanSoTuChuoi(const char* s);
int demSoChuSo(int n);

PhanSo* tachPS(char* c);
PhanSo* tinhTongPS(PhanSo* Ps1, PhanSo* Ps2);
int gcd(int a, int b);
void RutGon(PhanSo* Ps);


#endif 