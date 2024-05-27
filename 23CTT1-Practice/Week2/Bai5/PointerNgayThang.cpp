#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
using namespace std;

struct ThoiGian {
	int ngay;
	int thang;
	int nam;
};


ThoiGian* TaoThoiGian(int day, int month, int year)
{
	ThoiGian* pTG = new ThoiGian;
	pTG->ngay = day;
	pTG->thang = month;
	pTG->nam = year;

	return pTG;
}

// so ngay nhieu nhat co the co cua thang
int maxDayofMonth(int month, int year)
{
	if (month == 2)
	{
		if (year % 4 == 0 && year % 100 != 0)
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;
	}
	else
	{
		return 31;
	}
}

// so ngay nhieu nhat co the co cua nam
int maxDayofYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		return 366;
	}
	return 365;
}

// kiem tra tinh hop le cua ngay nhap vao
bool kiemtraHopLe(ThoiGian *pTG)
{
	if (pTG->thang < 1 || pTG->thang>12)
	{
		cout << "Thang khong hop le\n";
		return false;
	}
	if (pTG->thang == 4 || pTG->thang == 6 || pTG->thang == 9 || pTG->thang == 11)
	{
		if (pTG->ngay > 30)
		{
			cout << "Ngay khong hop le\n";
			return false;
		}
	}
	else if (pTG->thang == 1 || pTG->thang == 3 || pTG->thang == 5 || pTG->thang == 7 || pTG->thang == 8 || pTG->thang == 10 || pTG->thang == 12)
	{
		if (pTG->ngay > 31)
		{
			cout << "Ngay khong hop le\n";
			return false;
		}
	}
	else
	{
		if (pTG->nam % 4 == 0 && pTG->nam % 100 != 0)
		{
			if (pTG->ngay > 29)
			{
				cout << "Ngay khong hop le\n";
				return false;
			}
		}
		else
		{
			if (pTG->ngay > 28)
			{
				cout << "Ngay khong hop le\n";
				return false;
			}
		}
	}
	return true;
}

// nhap thoi gian
void nhapThoiGian(int &day, int &month, int &year)
{
	cout << "Nhap ngay: ";
	cin >> day;
	cout << "Nhap thang: ";
	cin >> month;
	cout << "Nhap nam: ";
	cin >> year;
}

// xuat thoi gian
void xuatThoiGian(ThoiGian* pTG)
{
	string result = "";
	stringstream out;
	out << setw(2) << setfill('0') << pTG->ngay << "/" << setw(2) << setfill('0') << pTG->thang << "/" << pTG->nam;
	result = out.str();
	cout << result;
}

// tim ngay do la ngay thu may trong nam
int NgayTrongNam(ThoiGian* pTG)
{
	int result = 0;
	for (int i = 1; i < pTG->thang; i++)
	{
		result += maxDayofMonth(i,pTG->nam);
	}
	result += pTG->ngay;

	return result;
}

// tinh khoang cach giua 2 ngay
int tinhKhoangCach2Ngay(ThoiGian* pTG1, ThoiGian* pTG2)
{
	int result = 0;

	// cung nam
	if (pTG1->nam == pTG2->nam)
	{
		int temp1 = NgayTrongNam(pTG1);
		int temp2 = NgayTrongNam(pTG2);
		result = abs(temp1 - temp2);
	}

	// khac nam
	if (pTG1->nam < pTG2->nam)
	{
		int temp1 = maxDayofYear(pTG1->nam) - NgayTrongNam(pTG1) + 1;
		int temp2 = NgayTrongNam(pTG2);

		for (int i = pTG1->nam + 1; i < pTG2->nam; i++)
		{
			result += maxDayofYear(i);
		}
		result += temp1 + temp2;
	}

	return result;
}

int main() {
	
	int day = 0;
	int month = 0;
	int year = 0;
	
	cout << "Thoi gian 1: \n";
	nhapThoiGian(day, month, year);
	ThoiGian* pTG1 = TaoThoiGian(day, month, year);

	while (!kiemtraHopLe(pTG1))
	{
		cout << "Nhap lai thoi gian\n";
		nhapThoiGian(day, month, year);
		ThoiGian* pTG1 = TaoThoiGian(day, month, year);
	}
	

	cout << "Thoi gian 2: \n";
	nhapThoiGian(day, month, year);
	ThoiGian* pTG2 = TaoThoiGian(day, month, year);
	while (!kiemtraHopLe(pTG2))
	{
		cout << "Nhap lai thoi gian\n";
		nhapThoiGian(day, month, year);
		ThoiGian* pTG1 = TaoThoiGian(day, month, year);
	}

	cout << "Thoi gian 1: ";
	xuatThoiGian(pTG1);
	cout << endl;
	cout << "Thoi gian 2: ";
	xuatThoiGian(pTG2);
	cout << endl;

	cout << "Khoang cach giua 2 ngay: " << tinhKhoangCach2Ngay(pTG1, pTG2) << " ngay\n";

	delete pTG1;
	delete pTG2;

	return 0;
}