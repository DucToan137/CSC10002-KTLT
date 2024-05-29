#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

struct SinhVien {
	char hoTen[31];
	char maSV[9];
	float diemTB;
};

struct GheNgoi {
	SinhVien sv;
	int hang;
	int cot;
};

struct Node {
	GheNgoi data;
	Node* pNext;
};

struct List {
	Node* pHead;
	Node* pTail;
};

void Init(List* l) {
	l->pHead = l->pTail = NULL;

}

void AddTail(List *l, GheNgoi x) {
	Node* p = new Node;
	p->data = x;
	p->pNext = NULL;

	if (l->pHead == NULL) {
		l->pHead = l->pTail = p;
	}
	else {
		l->pTail->pNext = p;
		l->pTail = p;
	}
}


// Xuất sinh vien theo định dạng
// "<họ tên>" (<mssv>); <họ tên> (<mssv>);...."

void XuatSinhVien(List* lrs) {
	Node* p = lrs->pHead;
	while (p != NULL) {
		cout << p->data.sv.hoTen << " (" << p->data.sv.maSV << "); ";
		p = p->pNext;
	}
}


// đọc dữ liệu từ file data.bin
// 4 byte đầu là số lượng hàng của vị trí ghế ngồi
// 4 byte tiếp theo là số lượng cột của vị trí ghế ngồi
// các byte còn lại là khối dữ liệu của 1 GheNgoi liên tiếp nhau

List* LoadData(const char* path) {
	int n;
	int m;
	List* lgn = new List;
	Init(lgn);

	ifstream ifs(path, ios::binary);

	ifs.read((char*)&n, sizeof(int));
	ifs.read((char*)&m, sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			GheNgoi gn;
			ifs.read((char*)&gn, sizeof(GheNgoi));
			AddTail(lgn, gn);
		}
	}
	return lgn;
}

// Viết hàm sắp xếp ghế ngồi trong danh sách liên kết
void SapXepListGheNgoi(List* lgn, int (*sosanh)(GheNgoi, GheNgoi)) {
	Node* p = lgn->pHead;
	while (p != NULL) {
		Node* q = p->pNext;
		while (q != NULL) {
			if (sosanh(p->data, q->data) > 0) {
				GheNgoi temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			q = q->pNext;
		}
		p = p->pNext;
	}
}

// Viết hàm so sách 2 ghê ngồi với mục tiêu sắp xếp ghế ngồi đúng vị trí tăng dần theo hàng và cột
int SoSanhGheNgoi(GheNgoi gn1, GheNgoi gn2) {
	if (gn1.hang > gn2.hang) {
		return 1;
	}
	if (gn1.hang < gn2.hang) {
		return -1;
	}
	if (gn1.cot > gn2.cot) {
		return 1;
	}
	if (gn1.cot < gn2.cot) {
		return -1;
	}
	return 0;
}

// Viết hàm tìm các sinh viên có họ cho trước bằng kỹ thuật đệ quy với khai báo hàm như sau 
List* TimDeQuyTheoHo(List *lgn, const char* ho) {
	List* l = new List;
	Init(l);

	Node* p = lgn->pHead;
	while (p != NULL) {
		if (strstr(p->data.sv.hoTen, ho) != NULL) {
			AddTail(l, p->data);
		}
		p = p->pNext;
	}
	return l;
}

// Viết hàm khử đệ quy cho hàm trên 
List *TimTheoHoKhuDeQuy(List* lgn, const char* ho) {
	List* l = new List;
	Init(l);

	Node* p = lgn->pHead;
	while (p != NULL) {
		if (strstr(p->data.sv.hoTen, ho) != NULL) {
			AddTail(l, p->data);
		}
		p = p->pNext;
	}
	return l;
}

int main() {

	
	/*int n = 3;
	int m = 4;
	GheNgoi gn[3][4] = {
		{
			{"Nguyen Van A", "SV001", 8.5, 1, 1},
			{"Nguyen Van B", "SV002", 7.5, 1, 2},
			{"Nguyen Van C", "SV003", 6.5, 1, 3},
			{"Nguyen Van D", "SV004", 5.5, 1, 4}
		},
		{
			{"Nguyen Van E", "SV005", 8.5, 2, 1},
			{"Nguyen Van F", "SV006", 7.5, 2, 2},
			{"Nguyen Van G", "SV007", 6.5, 2, 3},
			{"Nguyen Van H", "SV008", 5.5, 2, 4}
		},
		{
			{"Nguyen Van I", "SV009", 8.5, 3, 1},
			{"Nguyen Van K", "SV010", 7.5, 3, 2},
			{"Nguyen Van L", "SV011", 6.5, 3, 3},
			{"Nguyen Van M", "SV012", 5.5, 3, 4}
		}
	};

	ofstream ofs("data.bin", ios::binary);
	ofs.write((char*)&n, sizeof(int));
	ofs.write((char*)&m, sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ofs.write((char*)&gn[i][j], sizeof(GheNgoi));
		}
	}*/


	const char *path = "data.bin";
	ifstream ifs(path, ios::binary);

	List* lgn = LoadData(path);
	cout << "Danh sach sinh vien: ";
	XuatSinhVien(lgn);
	cout << "\n";
	
	SapXepListGheNgoi(lgn, SoSanhGheNgoi);
	cout << "Danh sach sinh vien sau khi sap xep: ";
	XuatSinhVien(lgn);
	cout << "\n";


	// Tìm các sinh viên theo họ sử dụng đệ quy
	List* l = TimDeQuyTheoHo(lgn, "Nguyen");

	// Xuất sinh vien theo định dạng
	// "<họ tên>" (<mssv>); <họ tên> (<mssv>);...."
	cout << "Danh sach sinh vien co ho Nguyen: ";
	XuatSinhVien(l);
	cout << "\n";

	// Tìm các sinh viên theo họ bằng cách khử đệ quy
	l = TimTheoHoKhuDeQuy(lgn, "Nguyen");
	XuatSinhVien(l);
	cout << "\n";

	system("pause");






	return 0;
}