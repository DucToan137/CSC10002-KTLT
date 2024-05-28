#include <iostream>
#include "MaDiTuan.h"
using namespace std;


int banco[kichthuoc][kichthuoc] = { 0 }; // Vị trí các nước đi

int dd[] = { -2,-1,1,2,2,1,-1,-1 };
int dc[] = { 1,2,2,1,-1,-2,-2,-1 };

int dx[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[8] = { -1,-2,-2,-1,1,2,2,1 };

bool solutionFound = false;



void xuat(int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << banco[i][j] << " ";
	cout << endl;
}
////////////////////////////////////////////////////////
void NuocDi(int n, int d, int c) { // Nước đi thứ n, tại vị trí dòng d, cột c
	if (solutionFound) return;

	for (int i = 0; i < 8; i++) { // 8 hướng đi của con mã
		// chọn thử hướng đi thứ i trong 8 hướng đi
		int dmoi = d + dd[i];
		int cmoi = c + dc[i];

		// Nếu hướng đi này hợp lệ và tại đó chưa có nước đi nào
		if (dmoi >= 0 && dmoi < kichthuoc && cmoi >= 0
			&& cmoi < kichthuoc && banco[dmoi][cmoi] == 0) {

			banco[dmoi][cmoi] = n; // Ghi nhận nước đi thứ n này
			if (n == kichthuoc * kichthuoc) { // Nước đi cuối cùng
				for (int i = 0; i < kichthuoc; i++) { // In bàn cờ hiện tại
					for (int j = 0; j < kichthuoc; j++) {
						cout << banco[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				solutionFound = true; // Đặt cờ báo hiệu đã tìm thấy lời giải
				return;
			}
			else { // Tìm nước đi kế tiếp
				NuocDi(n + 1, dmoi, cmoi);
			}
			banco[dmoi][cmoi] = 0; // Phục hồi trạng thái
		}
	}
}
////////////////////////////////////////////////////////

void diChuyen(int n, int x, int y) {
	int dem = 0;
	++dem; // Tăng giá trị bước đi
	banco[x][y] = dem; // Đánh dấu đã đi
	// Tìm tất cả các bước đi có thể đi và tiến hành đi thử
	for (int i = 0; i < 8; i++) {
		// Kiểm tra xem mã đã đi hết bàn cờ chưa
		if (dem == n * n) {
			cout << "Cac buoc di la: n";
			xuat(n);
			exit(0); // Kết thúc chương trình
		}
		// Nếu chưa đi hết bàn cờ thì tạo bước đi mới
		int u = x + dd[i]; // Tạo một vị trí x mới
		int v = y + dc[i]; // Tạo một vị trí y mới
		// Nếu hợp lệ thì tiến hành di chuyển
		if (u >= 0 && u < n && v >= 0 && v < n && banco[u][v] == 0)
			diChuyen(n, u, v);
	}
	// Nếu không tìm được bước đi thì ta phải trả lại các giá trị ban đầu
	--dem;
	banco[x][y] = 0;
}

void ThuNuocTiepTheo(int i, int x, int y, int* q) {
	int k, u, v;
	int* q1 = nullptr; // Initialize q1 to nullptr
	k = 0;
	do {
		q1 = new int; // Allocate memory for q1
		u = x + dx[k];
		v = y + dy[k];
		if ((0 <= u) && (u < kichthuoc) && (0 <= v) && (v < kichthuoc) && (banco[u][v] == 0)) {
			banco[u][v] = i;
			if (i < kichthuoc * kichthuoc) {
				ThuNuocTiepTheo(i + 1, u, v, q1);
				if ((*q1) == 0)
					banco[u][v] = 0;
			}
			else
				(*q1) = 1;
		}
		k++;
	} while (((*q1) == 0) && (k < 8));
	*q = *q1;
	delete q1; // Deallocate memory for q1
}

void InBanco(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (banco[i][j] < 10) {
				cout << banco[i][j] << "  ";
			}
			else {
				cout << banco[i][j] << " ";
			}
		}
		cout << "\n\n";
	}
}

void XoaBanco(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			banco[i][j] = 0;
		}
	}
}

