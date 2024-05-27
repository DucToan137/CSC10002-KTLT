#ifndef _MANGTAIKHOAN_H_
#define _MANGTAIKHOAN_H_


#include"TaiKhoan.h"

TaiKhoan* NhapMang(TaiKhoan* tk, int& n);
void XuatMang(TaiKhoan* t, int n);
void chucMungSinhNhat(TaiKhoan* tk, int n);

void LietKeTheoTen(TaiKhoan* tk, int n, char ten[]);
void NhapTaiKhoan(TaiKhoan* tk, int& n);

void XoaTaiKhoan(TaiKhoan* a, int& n, char tenDangNhap[]);

int TKC1(TaiKhoan tk1, TaiKhoan tk2);
int TKC2(TaiKhoan tk1, TaiKhoan tk2);
int TKC3(TaiKhoan tk1, TaiKhoan tk2);
void sortAsc(TaiKhoan* tk, int n, int (*tkSoSanh)(TaiKhoan tk1, TaiKhoan tk2));
void sortDesc(TaiKhoan* tk, int n, int (*tkSoSanh)(TaiKhoan tk1, TaiKhoan tk2));


#endif