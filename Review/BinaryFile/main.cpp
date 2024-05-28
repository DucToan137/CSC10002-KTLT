#include<iostream>
#include<fstream>

using namespace std;

// DEMO0: Lí thuyết
void demo0() {
	ifstream in("input.bin", ios::binary);
	ofstream out("output.bin", ios::binary);


	if (!in.is_open()) {
		cout << "Khong the mo file\n";
	}
	if (!out.is_open()) {
		cout << "Khong the mo file\n";
	}

	// 1.ĐỌC FILE
	int n = 0;
	in.read((char*)&n, sizeof(int)); // Đọc 4 byte từ file input.bin

	int m = 0;
	in.read(reinterpret_cast<char*>(&m), sizeof(int)); // Đọc 4 byte từ file input.bin

	// 2.GHI FILE
	out.write((char*)&n, sizeof(int)); // Ghi 4 byte từ file output.bin
	out.write(reinterpret_cast<char*>(&m), sizeof(int)); // Ghi 4 byte tu file output.bin

	// 3.SEEKP/SEEKG
	// seekg: dịch chuyển con trỏ đọc file
	// seekq(offset, start): reading
	// seekp: dịch chuyển con trỏ ghi file
	// seekp(offset, start): writing

	// start có thể nhận các giá trị sau:
	// ios::beg: vị trí đầu tiên của con trỏ file
	// ios::cur: vị trí hiện tại của con trỏ
	// ios::end: vị trí cuối cùng của con trỏ file

	// VD
	in.seekg(8, ios::cur); // Bỏ qua 8 byte từ vị trí hiện tại của con trỏ đọc file

	in.seekg(-1, ios::end); // Dịch chuyển con trỏ đọc file về phía cuối file 1 byte
	char c;
	in.read(&c, sizeof(char)); // Đọc 1 byte từ file input.bin
	cout << c << "\n";

	// 4.TELLG/TELLP
	// tellg: trả vệ vị trí hiện tại của đầu đọc/ghi tính theo byte và tính từ đầu file (đầu file = 0)

	int pos = in.tellg(); // Trả về vị trí hiện tại của con trỏ đọc file
	cout << pos << "\n";
	int pos1 = out.tellp(); // Trả về vị trí hiện tại của con trỏ ghi file
	cout << pos1 << "\n";


	in.close();
	out.close();
}

// DEMO1: Ghi file nhị phân
void demo1() {
	ofstream out("demo1.dat", ios::binary);
	int A = 123;
	double B = 9.6;
	char s[] = "Nguyen Duc Toan";

	if (!out.is_open()) {
		cout << "Khong the mo file\n";
	}

	out.write((char*)&A, sizeof(int));
	out.write((char*)&B, sizeof(double));
	out.write(s, sizeof(s));

	out.close();
}

// DEMO2: Đọc file nhị phân
void demo2() {
	ifstream in("demo1.dat", ios::binary);
	int A;
	double B;
	char s[100];

	if (!in.is_open()) {
		cout << "Khong the mo file\n";
	}

	in.read((char*)&A, sizeof(int));
	in.read((char*)&B, sizeof(double));
	in.read(s, sizeof(s));

	cout << A << "\n";
	cout << B << "\n";
	cout << s << "\n";
}


// DEMO3: Ghi file nhị phân struct
struct SinhVien {
	char ten[100];
	int tuoi;
	double diem;
};

void demo3() {
	SinhVien sv[] = {
		{"Nguyen Van A", 20, 8.5},
		{"Nguyen Van B", 21, 9.5},
		{"Nguyen Van C", 22, 7.5}
	};

	int n = 3;
	ofstream out("demo3.dat", ios::binary);

	out.write((char*)&n, sizeof(int));
	for (int i = 0; i < n; i++) {
		// CÁCH 1: Coi 1 biến SinhVien là khối liên tục
		out.write((char*)&sv[i], sizeof(SinhVien));
		
		// CÁCH 2: Ghi từng thành phần của struct
		/*out.write(sv[i].ten, sizeof(sv[i].ten));
		out.write((char*)&sv[i].tuoi, sizeof(int));
		out.write((char*)&sv[i].diem, sizeof(double));*/
	}

	out.close();
}

// DEMO4: Đọc file nhị phân struct
void demo4() {
	ifstream in("demo3.dat", ios::binary);
	int n;

	SinhVien sv[3];
	in.read((char*)&n, sizeof(int));

	for (int i = 0; i < n; i++) {
		// CÁCH 1: Coi 1 biến SinhVien là khối liên tục
		in.read((char*)&sv[i], sizeof(SinhVien));

		// CÁCH 2: Đọc từng thành phần của struct
		/*in.read(sv[i].ten, sizeof(sv[i].ten));
		in.read((char*)&sv[i].tuoi, sizeof(int));
		in.read((char*)&sv[i].diem, sizeof(double));*/
	}

	for (int i = 0; i < n; i++) {
		cout << sv[i].ten << "\n";
		cout << sv[i].tuoi << "\n";
		cout << sv[i].diem << "\n";
	}

	in.close();
}




int main() {
	
	//demo1();
	//demo2();

	demo3();
	demo4();

	return 0;
}