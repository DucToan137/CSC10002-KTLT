#ifndef _MANGTAIKHOAN_H_
#define _MANGTAIKHOAN_H_


#include"TaiKhoan.h"

TaiKhoan* NhapMang(TaiKhoan* tk, int &n);
void XuatMang(TaiKhoan* t,int n);
void chucMungSinhNhat(TaiKhoan* tk, int n);

void LietKeTheoTen(TaiKhoan* tk,int n, char ten[]);
void NhapTaiKhoan(TaiKhoan* tk, int &n);

void XoaTaiKhoan(TaiKhoan* a, int& n, char tenDangNhap[]);

#endif