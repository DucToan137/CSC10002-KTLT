#include"TaiKhoan.h"
#include<ctime>
#include<string.h>


void Nhap(TaiKhoan& tk)
{
	do
	{

		std::cout << "Nhap ten dang nhap: ";
		std::cin.get(tk.tenDangNhap, 30);

		std::cin.ignore();

	} while (KiemTraTenDangNhap(tk.tenDangNhap) == 0);

	do
	{
		std::cout << "Nhap mat khau: ";
		std::cin.get(tk.matKhau, 30, '\n');
		std::cin.ignore();

	} while (KiemTraMatKhau(tk.matKhau) == 0);

	char c[31] = "";
	do
	{

		std::cout << "Xac nhan mat khau: ";
		std::cin.get(c, 30, '\n');
		std::cin.ignore();
	} while (strcmp(tk.matKhau, c) != 0);

	do
	{
		std::cout << "Nhap ho ten: ";
		std::cin.get(tk.hoTen, 50, '\n');
		std::cin.ignore();

	} while (KiemTraHoTen(tk.hoTen) == 0);

	do
	{
		std::cout << "Nhap email: ";
		std::cin.get(tk.email, 50, '\n');
		std::cin.ignore();

	} while (KiemTraEmail(tk.email) == 0);

	do {
		std::cout << "Nhap ngay thang nam sinh\n";
		NhapNTNS(tk.ntns);
	} while (KiemTraNgay(tk.ntns) == 0);

}

void NhapNTNS(Ngay& ng)
{
	std::cout << "Nhap ngay: ";
	std::cin >> ng.ngay;

	std::cout << "Nhap thang: ";
	std::cin >> ng.thang;

	std::cout << "Nhap nam: ";
	std::cin >> ng.nam;
}

int KiemTraTenDangNhap(char tenDangNhap[])
{
	char s[31];
	strcpy(s, tenDangNhap);
	
	strlwr(s);
	
	char* p = strstr(s, "admin");
	if (p == NULL)
		return 1;
	return 0;
}

int KiemTraMatKhau(char matKhau[])
{
	int doDai = strlen(matKhau);
	if(doDai < 6)
		return 0;
	
	int coKiTuHoa = 0;
	for (int i = 0; i < doDai; i++)
	{
		if (matKhau[i] >= 'A' && matKhau[i] <= 'Z')
			coKiTuHoa = 1;
	}
	if (coKiTuHoa == 0)
		return 0;

	int coKiTu = 0;
	for (int i = 0; i < doDai; i++)
	{
		if (matKhau[i] >= 'a' && matKhau[i] <= 'z')
			coKiTu = 1;
		if (matKhau[i] >= 'A' && matKhau[i] <= 'Z')
			coKiTu = 1;
	}
	if (coKiTu == 0)
		return 0;

	int coSo = 0;
	for (int i = 0; i < doDai; i++)
	{
		if (matKhau[i] >= '0' && matKhau[i] <= '9')
			coSo = 1;
	}
	if (coSo == 0)
		return 0;

	int coDau = 0;
	for (int i = 0; i <= doDai; i++)
	{
		if (matKhau[i] == ',' || matKhau[i] == '.' || matKhau[i] == ':' || matKhau[i]==';'||matKhau[i]=='~'||matKhau[i]=='-'||matKhau[i]=='_')
			coDau = 1;
	}
	if (coDau == 0)
		return 0;

	return 1;
}

int KiemTraHoTen(char hoTen[])
{
	int coKhoangTrang = 0;
	int doDai = strlen(hoTen);
	for (int i = 0; i < doDai; i++)
	{
		if (hoTen[i] == ' ')
			coKhoangTrang = 1;
	}
	if (coKhoangTrang == 0)
		return 0;

	return 1;
}

int KiemTraEmail(char email[])
{
	int coKiTu = 0;
	int coDau = 0;
	int doDai = strlen(email);
	
	for (int i = 0; i < doDai; i++)
	{
		if (email[i] == '@')
			coKiTu = 1;
	}
	if (coKiTu == 0)
		return 0;
	for (int i = 0; i < doDai; i++)
	{
		if (email[i] == '.')
			coDau = 1;
	}
	if (coDau == 0)
		return 0;
	
	return 1;
}

int tinhTuoi(TaiKhoan tk)
{
	time_t now = time(0);

	tm* ltm = localtime(&now);

	int y = ltm->tm_year + 1900;
	int m = ltm->tm_mon + 1;
	int d = ltm->tm_mday;

	int tuoi = 0;

	if (tk.ntns.nam == y)
	{
		return tuoi;
	}
	else if (tk.ntns.nam < y)
	{
		if (tk.ntns.thang < m)
		{
			tuoi = y - tk.ntns.nam + 1;
		}
		else if (tk.ntns.thang > m)
		{
			tuoi = y - tk.ntns.nam - 1;
		}
		else
		{
			if(tk.ntns.ngay<=d)
			{
				tuoi = y - tk.ntns.nam;
			}
			else
			{
				tuoi = y - tk.ntns.nam - 1;
			}
		}


	}
	return tuoi;
}


int KiemTraNgay(Ngay ng)
{
	if (ng.thang < 1 || ng.thang>12)
	{
		std::cout << "Thang khong hop le\n";
		return 0;
	}
	if (ng.thang == 4 || ng.thang == 6 || ng.thang == 9 || ng.thang == 11)
	{
		if (ng.ngay > 30)
		{
			std::cout << "Ngay khong hop le\n";
			return 0;
		}
	}
	else if (ng.thang == 1 || ng.thang == 3 || ng.thang == 5 || ng.thang == 7 || ng.thang == 8 || ng.thang == 10 || ng.thang == 12)
	{
		if (ng.ngay > 31)
		{
			std::cout << "Ngay khong hop le\n";
			return 0;
		}
	}
	else
	{
		if (ng.nam % 4 == 0 && ng.nam % 100 != 0)
		{
			if (ng.ngay > 29)
			{
				std::cout << "Ngay khong hop le\n";
				return 0;
			}
		}
		else
		{
			if (ng.ngay > 28)
			{
				std::cout << "Ngay khong hop le\n";
				return 0;
			}
		}
	}
	return 1;
}

int sosanhChuoi(char s0[], char s1[])
{
	int n0 = strlen(s0);
	int n1 = strlen(s1);
	if (n0 == n1)
	{
		for (int i = 0; i < n0; i++)
		{
			if (s0[i] != s1[i])
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	return 1;
}

void Xuat(TaiKhoan tk)
{
	std::cout << "Ten dang nhap: ";
	std::cout << tk.tenDangNhap << "\n";

	std::cout << "Mat khau: ";
	std::cout << tk.matKhau << "\n";

	std::cout << "Ho ten: \n";
	xuatHoTen(tk);

	std::cout << "Emmail: ";
	std::cout << tk.email << "\n";

	std::cout << "Tuoi: ";
	std::cout << 2024 - tk.ntns.nam << "\n";

}

void xuatHoTen(TaiKhoan tk)
{
	int doDaiHoTen = strlen(tk.hoTen)+1;
	
	int dem = 0;
	char kitu[] = " ";
	char* tmp = new char[doDaiHoTen];
	strcpy(tmp, tk.hoTen);
	
	char c[51][51];

	char* token = strtok(tmp, kitu);
	
	while (token != NULL)
	{
		strcpy(c[dem], token);
		dem++;
		token = strtok(NULL, kitu);
	}
	if (dem == 2)
	{
		int doDaiHo = strlen(c[0]) + 1;
		int doDaiTen = strlen(c[1]) + 1;

		char* Ho = new char[doDaiHo];
		char* Ten = new char[doDaiTen];

		strcpy(Ho, c[0]);
		strcpy(Ten, c[1]);

		std::cout << "Ho: " << Ho << "\n";
		std::cout << "Ten: " << Ten << "\n";

		delete[] Ho;
		delete[] Ten;
		delete[]token;
		
	}
	else
	{
		int doDaiHo = strlen(c[0]) + 1;
		int doDaiTen = strlen(c[dem - 1]) + 1;
		int doDaiTenLot = 0;

		for (int i = 1; i < dem - 1; i++)
		{
			doDaiTenLot += strlen(c[i]);
		}

		char* Ho = new char[doDaiHo];
		char* Ten = new char[doDaiTen];
		//char* TenLot = new char[doDaiTenLot+2];
		
		char TenLot[51];


		strcpy(Ho, c[0]);
		strcpy(TenLot, "");
		strcpy(Ten, c[dem - 1]);


		for (int i = 1; i < dem - 1; i++)
		{
			strcat(TenLot, c[i]);
			strcat(TenLot, " ");
		}

		std::cout << "Ho: " << Ho << "\n";
		std::cout << "Ten lot: " << TenLot << "\n";
		std::cout << "Ten: " << Ten << "\n";

		delete[] Ho;
		delete[] Ten;
		delete[]token;
		
	}
	delete[] tmp;
}


int chuoiCon(TaiKhoan tk, char *tmp)
{
	char kitu[] = " ";
	char c[51][51];
	int dem = 0;

	char* token = strtok(tk.hoTen, kitu);
	
	
	while (token != NULL)
	{
		strcpy(c[dem], token);
		dem++;
		token = strtok(NULL, kitu);
		
	}

	for (int i = 0; i < dem; i++)
	{
		strlwr(c[i]);
		if (strcmp(c[i], strlwr(tmp)) == 0)
		{
			return 1;
		}
	}

	return 0;
}