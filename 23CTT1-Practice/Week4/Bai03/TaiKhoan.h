
#ifndef TAIKHOAN_H_
#define TAIKHOAN_H_
#include<iostream>


struct Ngay {
	int ngay;
	int thang;
	int nam;
};

struct TaiKhoan {
	char tenDangNhap[31];
	char matKhau[31];
	char hoTen[51];
	char email[51];
	Ngay ntns;
};

void Nhap(TaiKhoan& tk);
int KiemTraTenDangNhap(char tenDangNhap[]);
int KiemTraMatKhau(char matKhau[]);
int KiemTraHoTen(char hoTen[]);
int KiemTraEmail(char email[]);
void NhapNTNS(Ngay& ng);
void Xuat(TaiKhoan tk);
int KiemTraNgay(Ngay ng);
void xuatHoTen(TaiKhoan tk);
int tinhTuoi(TaiKhoan tk);
int chuoiCon(TaiKhoan tk, char *tmp);


#endif