#include"TamGiac.h"
#include<cmath>

void NhapTamGiac(TamGiac* t) {
	std::cout << "Nhap dinh A\n";
	t->A = new Diem;
	NhapDiem(t->A);

	std::cout << "Nhap dinh B\n";
	t->B = new Diem;
	NhapDiem(t->B);

	std::cout << "Nhap dinh C\n";
	t->C = new Diem;
	NhapDiem(t->C);

	while (!check(t))
	{
		std::cout << "Tam giac khong hop le. Nhap lai tam giac\n";
		NhapTamGiac(t);
	}
}

bool check(TamGiac* t) {
	float AB = TinhKhoangCach(t->A, t->B);
	float AC = TinhKhoangCach(t->A, t->C);
	float BC = TinhKhoangCach(t->B, t->C);

	if (0 == AB || 0 == AC || 0 == BC) {
		return false;
	}
	if (AB + AC < BC || AB + BC < AC || AC + BC < AB)
	{
		return false;
	}
	return true;
}

void XuatTamGiac(TamGiac *t) {
	std::cout << "Dinh A: ";
	XuatDiem(t->A);
	std::cout << "\n";

	std::cout << "Dinh B: ";
	XuatDiem(t->B);
	std::cout << "\n";


	std::cout << "Dinh C: ";
	XuatDiem(t->C);
	std::cout << "\n";

	//std::cout << "CV: " << TinhChuVi(t) << " " << "S: " << TinhDienTich(t) << "\n";
}

void XuatTamGiac(TamGiac t) {
	std::cout << "Dinh A: ";
	XuatDiem(t.A);
	std::cout << "\n";

	std::cout << "Dinh B: ";
	XuatDiem(t.B);
	std::cout << "\n";


	std::cout << "Dinh C: ";
	XuatDiem(t.C);
	std::cout << "\n";

}

float TinhChuVi(TamGiac t) {
	float AB = TinhKhoangCach(t.A, t.B);
	float AC = TinhKhoangCach(t.A, t.C);
	float BC = TinhKhoangCach(t.B, t.C);

	float result = AB + AC + BC;

	return result;
}

float TinhChuVi(TamGiac* t) {
	float AB = TinhKhoangCach(t->A, t->B);
	float AC = TinhKhoangCach(t->A, t->C);
	float BC = TinhKhoangCach(t->B, t->C);

	float result = AB + AC + BC;

	return result;
}

float TinhDienTich(TamGiac t) {
	float AB = TinhKhoangCach(t.A, t.B);
	float AC = TinhKhoangCach(t.A, t.C);
	float BC = TinhKhoangCach(t.B, t.C);

	float p = (AB + BC + AC) / 2;

	float result = sqrt(p * (p - AB) * (p - BC) * (p - AC));

	return result;
}

float TinhDienTich(TamGiac* t) {
	float AB = TinhKhoangCach(t->A, t->B);
	float AC = TinhKhoangCach(t->A, t->C);
	float BC = TinhKhoangCach(t->B, t->C);

	float p = (AB + BC + AC) / 2;

	float result = sqrt(p * (p - AB) * (p - BC) * (p - AC));

	return result;
}