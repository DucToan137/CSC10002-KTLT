#pragma once
#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

struct SinhVien {
	char ten[30];
	char mssv[8];
	float diemTB;
};

struct Node {
	SinhVien data;
	Node*pNext;
};

struct LopHoc {
	Node* pHead;
	Node* pTail;
};


// Tạo node
Node* createNode(SinhVien sv);

// 1/Khởi tạo lớp học
void init(LopHoc& l);

// 2/Thêm sinh viên vào lớp học
void addTail(LopHoc& l, SinhVien sv);

// 3/Xuất danh sách sinh viên
typedef int (*YeuCau)(LopHoc l);

// 4/Đọc ghi dữ liệu ra file nhị phân (chưa xong)
void ghiFile(LopHoc l, const char* fileName);

void docFile(LopHoc& l, const char* fileName);

void printList(LopHoc l, YeuCau yeuCau);

int YeuCauTen(LopHoc l);

int YeuCauTen_MSSV(LopHoc l);

int YeuCauTatCa(LopHoc l);

// 5/Sắp xếp sinh viên theo yêu cầu
typedef int (*SoSanh)(const SinhVien&, const SinhVien&);

void SapXep(LopHoc& l, SoSanh ss);

int SoSanhMSSV(const SinhVien& sv1, const SinhVien& sv2);

int SoSanhDiem(const SinhVien& sv1, const SinhVien& sv2);

int SoSanhTen(const SinhVien& sv1, const SinhVien& sv2);

// 6/Đuổi sinh viên theo yêu cầu
void XoaNode(LopHoc& l, Node* p);

void DuoiSinhVienDuoi5(LopHoc& l);

void DuoiSinhVienTheoMSSV(LopHoc& l, char* mssv);

// 7/Xóa lớp học
void deleteList(LopHoc& l);

// 8/Thêm một sinh viên vào lớp học đã được sắp xếp theo tiêu chí cụ thể 
void ThemSinhVien(LopHoc& l, SinhVien sv, SoSanh ss);

// 9/Tách 1 lớp học thành 2 lớp có số lượng sinh viên gần bằng nhau
int soLuongPhanTu(LopHoc l);

void chiaLopHoc(LopHoc l, LopHoc& l1, LopHoc& l2);\
// 10/Gộp 2 lớp học thành 1 lớp
void gopLopHoc(LopHoc& l, LopHoc l1);


