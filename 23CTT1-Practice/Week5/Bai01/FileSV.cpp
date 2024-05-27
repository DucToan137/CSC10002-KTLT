#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<stdio.h>
using namespace std;

#define MAXLEN 100

struct SinhVien
{
	int MSSV;
	char HoTen[51];
};
char* SVToString(const SinhVien& sv)
{
	/// xuất thông tin sinh viên ra chuỗi
	/// định dạng: <MSSV> - <HoTen>
	
	
	char c[MAXLEN];
	sprintf(c, "%d", sv.MSSV);
	
	char* result = new char;
	strcpy(result, c);
	strcat(result, " - ");
	strcat(result, sv.HoTen);
	

	return result;
}
void PrintArr(SinhVien* arr, const int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << SVToString(arr[i]) << endl;
	}
}
/// định nghĩa con trỏ hàm
typedef int(*SVComparer)(SinhVien, SinhVien);
/// hàm so sánh sinh viên dựa vào mssv
int SVC1(SinhVien sv1, SinhVien sv2)
{
	if (sv1.MSSV > sv2.MSSV)
	{
		return 1;
	}
	if (sv1.MSSV < sv2.MSSV)
	{
		return -1;
	}
	return 0;
}
/// hàm so sánh sinh viên dựa vào họ tên
int SVC2(SinhVien sv1, SinhVien sv2)
{
	return strcmp(sv1.HoTen, sv2.HoTen);
}
/// hàm sắp xếp sinh viên
void SortAsc(SinhVien* arrSV, const int& n, SVComparer svc)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (svc(arrSV[i], arrSV[j]) > 0)
			{
				SinhVien svTemp = arrSV[i];
				arrSV[i] = arrSV[j];
				arrSV[j] = svTemp;
			}
		}
	}
}
/// có thể sử dụng con trỏ hàm không cần định nghĩa trước
void SortDesc(SinhVien* arrSV, const int& n, int (*svSoSanh)(SinhVien, SinhVien))
{
	/// sắp xếp giảm dần
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (svSoSanh(arrSV[i], arrSV[j]) < 0)
			{
				SinhVien svTemp = arrSV[i];
				arrSV[i] = arrSV[j];
				arrSV[j] = svTemp;
			}
		}
	}
}
SinhVien* LoadSV(const char* path, int& n)
{
	/// đọc danh sách sinh viên từ file
	/// trả về pointer trỏ đến mảng sinhvien đọc được
	/// n là số sinh viên đọc được
	SinhVien* sv = new SinhVien[MAXLEN];
	n = 0;

	char c[MAXLEN];
	char d[MAXLEN] = "";
	ifstream read;
	read.open(path, ios::in);
	if (read.good())
	{
		while (!read.eof())
		{
			
			read.getline(c, 100);

			//cout << c << "\n";

			char* token = strtok(c, ";");
			int mssv = atoi(token);
			sv[n].MSSV = mssv;

			token = strtok(NULL, ";");
			char hoten[50]; 
			strcpy(hoten, token);

			strcpy(sv[n].HoTen, token);
			n++;
		}
		
	}
	read.close();
	return sv;
}

int main()
{
	const char* path = "data.txt";
	int n = 0;
	SinhVien* arrSV1 = LoadSV(path, n);
	SinhVien* arrSV2 = LoadSV(path, n);
	cout << "***************Arr begin**************" << endl;
	PrintArr(arrSV1, n);
	PrintArr(arrSV1, n);
	SortAsc(arrSV1, n, SVC1);
	cout << "**********Arr sorted mode 1***********" << endl;
	PrintArr(arrSV1, n);
	SortDesc(arrSV2, n, SVC2);
	cout << "**********Arr sorted mode 2***********" << endl;
	PrintArr(arrSV2, n);
	system("pause");

	
	return 0;
}
