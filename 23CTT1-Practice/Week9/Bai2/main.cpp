#include<iostream>
#include<string.h>
#include"LopHoc.h"

using namespace std;

int main() { 

	LopHoc l;
	init(l);

	SinhVien sv1 = { "Nguyen Van A", "SV001", 8.5 };
	SinhVien sv2 = { "Nguyen Van B", "SV002", 7.5 };
	SinhVien sv3 = { "Nguyen Van C", "SV003", 9.5 };
	SinhVien sv4 = { "Nguyen Van D", "SV004", 6.5 };
	SinhVien sv5 = { "Nguyen Van E", "SV005", 5.5 };
	SinhVien sv6 = { "Nguyen Van F", "SV006", 4.5 };
	SinhVien sv7 = { "Nguyen Van G", "SV007", 7.5 };

	/*addTail(l, sv1);
	addTail(l, sv2);
	addTail(l, sv3);*/
	addTail(l, sv4);
	addTail(l, sv5);
	addTail(l, sv6);
	addTail(l, sv1);
	addTail(l, sv2);
	addTail(l, sv3);
	
	// Thêm sinh viên vào danh sách đã sắp xếp
	ThemSinhVien(l, sv7, SoSanhTen);

	// Đọc ghi file nhị phân
	char f[100]="data.bin";
	ghiFile(l, f);

	LopHoc l3;
	init(l3);

	docFile(l3, f);
	printList(l3,YeuCauTatCa);

	// Sắp xếp lớp học theo yêu cầu
	//SapXep(l, SoSanhMaSV);
	//SapXep(l, SoSanhTen);
	//SapXep(l, SoSanhDiem);
	
	// Đuổi sinh viên theo mã số
	//DuoiSinhVienDuoi5(l);
	//char c[8] = "SV002";
	//DuoiSinhVienTheoMSSV(l, c);

	// In danh sách sinh viên theo yêu cầu
	//printList(l, YeuCauTen);
	//printList(l, YeuCauTen_MSSV);
	//printList(l, YeuCauTatCa);


	// Chia - gộp lớp học
	LopHoc l1;
	init(l1);

	LopHoc l2;
	init(l2);

	chiaLopHoc(l, l1, l2);
	cout <<"\nLop 1: \n";
	printList(l1, YeuCauTatCa);
	cout << "\nLop 2: \n";
	printList(l2, YeuCauTatCa);

	gopLopHoc(l1, l2);
	cout <<"\nGop lop: \n";
	printList(l1,YeuCauTatCa);

	// Xóa lớp học
	cout << "\nXoa lop\n";
	deleteList(l);
	printList(l, YeuCauTatCa);


	return 0;
}