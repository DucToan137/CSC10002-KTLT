#ifndef _NGUOI_H_
#define _NGUOI_H_



#include<iostream>
#include<string.h>
#include<sstream>


#define MAXLEN 100

struct Nguoi {
	char HoTen[MAXLEN];
	char DiaChi[MAXLEN];
};

Nguoi* TaoNguoi(const char* pHt, const char* pDc);
char* XuatNguoi(Nguoi* pN);
void ThemKiTu(char* res, char kitu, int pos);


int is_upper(char c);
int is_lowwer(char c);
void NormalizeWord(char* a);

int demTu(char *s);

int getToken(char* token, char* s, int& startPos);
void ChuanHoaTen(Nguoi* pN);

#endif