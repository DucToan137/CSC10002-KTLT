#include"MangTaiKhoan.h"

TaiKhoan* NhapMang(TaiKhoan* tk, int& n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Nhap tai khoan thu " << i + 1 << ":\n";
		std::cin.ignore();
		Nhap(tk[i]);
	}

	return tk;
}

void XuatMang(TaiKhoan* tk, int n)
{
	std::cout << "\n\nDanh sach tai khoan\n";
	for (int i = 0; i < n; i++)
	{
		std::cout << "Thong tin tai khoan " << i + 1 << ":\n";
		Xuat(tk[i]);
	}
}


void chucMungSinhNhat(TaiKhoan* tk, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (tk->ntns.thang == 4)
		{
			std::cout << "Chuc mung sinh nhat tai khoan " << tk->tenDangNhap << "\n";
		}
	}
}

void LietKeTheoTen(TaiKhoan* tk, int n, char ten[])
{
	if (n == 0)
	{
		std::cout << "Danh sach trong" << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (chuoiCon(tk[i], ten) == 1)
		{
			Xuat(tk[i]);
		}
	}
}

void NhapTaiKhoan(TaiKhoan* tk, int& n)
{

	TaiKhoan tk1;

	std::cin.ignore();
	Nhap(tk1);


	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(tk1.tenDangNhap, tk[i].tenDangNhap) == 0)
		{
			std::cout << "Tai khoan da ton tai" << "\n";
			return;
		}
	}

	strcpy(tk[n].tenDangNhap, tk1.tenDangNhap);
	strcpy(tk[n].matKhau, tk1.matKhau);
	strcpy(tk[n].hoTen, tk1.hoTen);
	strcpy(tk[n].email, tk1.email);

	tk[n].ntns = tk1.ntns;
	n++;
}

void XoaTaiKhoan(TaiKhoan* a, int& n, char tenDangNhap[])
{
	int pos = -1;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].tenDangNhap, tenDangNhap) == 0)
		{
			pos = i;
		}
	}
	if (pos == -1)
	{
		std::cout << "Khong tim thay tai khoan can xoa\n";
		return;
	}
	if (pos == n)
	{
		pos = n - 1;
	}
	for (int i = pos; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	--n;
}

typedef int(*SVComparer)(TaiKhoan, TaiKhoan);

// so sanh ten dang nhap
int TKC1(TaiKhoan tk1, TaiKhoan tk2)
{
	return strcmp(tk1.tenDangNhap, tk2.tenDangNhap);
}

// so sanh tuoi
int TKC2(TaiKhoan tk1, TaiKhoan tk2)
{
	if (tk1.ntns.nam > tk2.ntns.nam)
	{
		return -1;
	}
	if (tk1.ntns.nam < tk2.ntns.nam)
	{
		return 1;
	}
	return 0;
}

// so sanh ho ten
int TKC3(TaiKhoan tk1, TaiKhoan tk2)
{
	return strcmp(tk1.hoTen, tk2.hoTen);
}

void sortAsc(TaiKhoan* tk, int n, int (*tkSoSanh)(TaiKhoan tk1, TaiKhoan tk2))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (tkSoSanh(tk[i], tk[j]) > 0)
			{
				TaiKhoan svTemp = tk[i];
				tk[i] = tk[j];
				tk[j] = svTemp;
			}
		}
	}
}

void sortDesc(TaiKhoan* tk, int n, int (*tkSoSanh)(TaiKhoan tk1, TaiKhoan tk2))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (tkSoSanh(tk[i], tk[j]) < 0)
			{
				TaiKhoan svTemp = tk[i];
				tk[i] = tk[j];
				tk[j] = svTemp;
			}
		}
	}
}



