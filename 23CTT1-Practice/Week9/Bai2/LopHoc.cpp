#include"LopHoc.h"


// 1/Khởi tạo lớp học
void init(LopHoc& l)
{
	l.pHead = l.pTail = NULL;
}

// Tạo node
Node* createNode(SinhVien sv)
{
	Node* p = new Node;
	if (p == NULL)
	{
		return NULL;
	}
	p->data = sv;
	p->pNext = NULL;
	return p;
}

// 2/Thêm sinh viên vào lớp học
void addTail(LopHoc& l, SinhVien sv)
{
	Node* p = createNode(sv);
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

// 3/Xuất danh sách sinh viên
typedef int (*YeuCau)(LopHoc l);

void printList(LopHoc l, YeuCau yeuCau)
{
	cout << "Danh sach sinh vien theo yeu cau:\n";
	if (l.pHead == nullptr)
	{
		cout << "Lop hoc rong\n";
		return;
	}
	for (Node* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (yeuCau(l) == 0)
		{
			cout << "Ten: " << k->data.ten << endl;
		}
		else if (yeuCau(l) == 1)
		{
			cout << "Ten: " << k->data.ten << endl;
			cout << "Ma SV: " << k->data.mssv << endl;
		}
		else if (yeuCau(l) == 2)
		{
			cout << "Ten: " << k->data.ten << endl;
			cout << "Ma SV: " << k->data.mssv << endl;
			cout << "Diem TB: " << k->data.diemTB << endl;
		}
	}
}

int YeuCauTen(LopHoc l)
{
	return 0;
}

int YeuCauTen_MSSV(LopHoc l)
{
	return 1;
}

int YeuCauTatCa(LopHoc l)
{
	return 2;
}

// 4/Đọc ghi dữ liệu ra file nhị phân (chưa xong)
void ghiFile(LopHoc l, const char* fileName) {
	ofstream in(fileName, ios::binary);

	if (!in) {
		cout << "Khong the mo file\n";
		return;
	}

	Node* tmp = l.pHead;
	while (tmp != NULL) {
		in.write(reinterpret_cast<char*>(&tmp->data), sizeof(SinhVien));
		tmp = tmp->pNext;
	}

	in.close();
}

void docFile(LopHoc& l, const char* fileName)
{
	ifstream out(fileName, ios::binary);

	if (!out) {
		cout << "Khong the mo file\n";
		return;
	}

	while (!out.eof()) {
		SinhVien sv;
		out.read(reinterpret_cast<char*>(&sv), sizeof(SinhVien));
		addTail(l, sv);
	}
}

// 5/Sắp xếp sinh viên theo yêu cầu
typedef int (*SoSanh)(const SinhVien&, const SinhVien&);

void SapXep(LopHoc& l, SoSanh ss)
{
	if (l.pHead == nullptr)
	{
		return;
	}
	for (Node* i = l.pHead; i != l.pTail; i = i->pNext)
	{
		for (Node* j = i->pNext; j != NULL; j = j->pNext)
		{
			if (ss(i->data, j->data) > 0)
			{
				SinhVien temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}

int SoSanhMSSV(const SinhVien& sv1, const SinhVien& sv2)
{
	return strcmp(sv1.mssv, sv2.mssv) > 0;
}

int SoSanhDiem(const SinhVien& sv1, const SinhVien& sv2)
{
	return sv1.diemTB > sv2.diemTB;
}

int SoSanhTen(const SinhVien& sv1, const SinhVien& sv2)
{
	return strcmp(sv1.ten, sv2.ten) > 0;
}

// 6/Đuổi sinh viên theo yêu cầu
void XoaNode(LopHoc& l, Node* p)
{
	if (l.pHead == nullptr)
	{
		return;
	}
	if (l.pHead == l.pTail)
	{
		delete l.pHead;
		l.pHead = l.pTail = nullptr;
	}
	else
	{
		if (p == l.pHead)
		{
			Node* k = l.pHead;
			l.pHead = l.pHead->pNext;
			delete k;
		}
		else
		{
			Node* g = l.pHead;
			while (g->pNext != p)
			{
				g = g->pNext;
			}
			if (p == l.pTail)
			{
				l.pTail = g;
				g->pNext = nullptr;
				delete p;
			}
			else
			{
				g->pNext = p->pNext;
				delete p;
			}
		}
	}
}

void DuoiSinhVienDuoi5(LopHoc& l)
{
	if (l.pHead == nullptr)
	{
		return;
	}
	for (Node* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.diemTB < 5)
		{
			Node* tmp = k;
			k = k->pNext;
			XoaNode(l, tmp);
		}
	}
}

void DuoiSinhVienTheoMSSV(LopHoc& l, char* mssv)
{
	if (l.pHead == nullptr)
	{
		return;
	}
	if (strcmp(l.pHead->data.mssv, mssv) == 0)
	{
		Node* tmp = l.pHead;
		l.pHead = l.pHead->pNext;
		delete tmp;
	}
	if (strcmp(l.pTail->data.mssv, mssv) == 0)
	{
		Node* tmp = l.pTail;
		Node* k = l.pHead;
		while (k->pNext != l.pTail)
		{
			k = k->pNext;
		}
		l.pTail = k;
		k->pNext = nullptr;
		delete tmp;
	}
	for (Node* k = l.pHead; k != l.pTail; k = k->pNext)
	{
		if (strcmp(k->data.mssv, mssv) == 0)
		{
			Node* tmp = k;
			k = k->pNext;
			XoaNode(l, tmp);
			return;
		}
	}

}

// 7/Xóa lớp học
void deleteList(LopHoc& l)
{
	Node* k = l.pHead;
	while (k != NULL)
	{
		l.pHead = l.pHead->pNext;
		delete k;
		k = l.pHead;
	}
}

// 8/Thêm một sinh viên vào lớp học đã được sắp xếp theo tiêu chí cụ thể 
void ThemSinhVien(LopHoc& l, SinhVien sv, SoSanh ss)
{
	Node* p = createNode(sv);
	if (l.pHead == nullptr)
	{
		l.pHead = l.pTail = p;
		p->pNext = nullptr;
		return;
	}

	if (ss(l.pHead->data, sv))
	{
		p->pNext = l.pHead;
		l.pHead = p;
		return;
	}

	Node* tmp = l.pHead;
	while (tmp->pNext != nullptr && ss(tmp->pNext->data, sv) < 1)
	{
		tmp = tmp->pNext;
	}

	p->pNext = tmp->pNext;
	tmp->pNext = p;

	if (p->pNext == nullptr)
	{
		l.pTail = p;
	}
}

// 9/Tách 1 lớp học thành 2 lớp có số lượng sinh viên gần bằng nhau
int soLuongPhanTu(LopHoc l)
{
	if (l.pHead == NULL)
	{
		return 0;
	}
	int dem = 0;
	Node* tmp = l.pHead;
	while (tmp != NULL)
	{
		dem++;
		tmp = tmp->pNext;
	}
	return dem;
}

void chiaLopHoc(LopHoc l, LopHoc& l1, LopHoc& l2)
{
	if (l.pHead == NULL)
	{
		return;
	}

	int dem = soLuongPhanTu(l);
	int i = 0;
	Node* tmp = l.pHead;

	while (tmp != NULL)
	{
		if (i > dem / 2)
		{
			addTail(l2, tmp->data);
		}
		else
		{
			addTail(l1, tmp->data);
		}
		i++;
		tmp = tmp->pNext;
	}
}

// 10/Gộp 2 lớp học thành 1 lớp
void gopLopHoc(LopHoc& l, LopHoc l1)
{
	if (l1.pHead == NULL)
	{
		return;
	}
	if (l.pHead == NULL)
	{
		l = l1;
		return;
	}
	for (Node* i = l1.pHead; i != NULL; i = i->pNext)
	{
		addTail(l, i->data);
	}
}



