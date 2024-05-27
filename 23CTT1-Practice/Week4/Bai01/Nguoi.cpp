#include"Nguoi.h"
#include<cstring>

Nguoi* TaoNguoi(const char* pHt, const char* pDc) 
{
	Nguoi* result = new Nguoi;

	strcpy(result->HoTen, pHt);
	strcpy(result->DiaChi, pDc);

	return result;
}

void ThemKiTu(char* res, char kitu, int pos)
{
	if (strlen(res) >= MAXLEN - 1)
	{
		return;
	}

	if (pos<0 || pos>strlen(res))
	{
		return;
	}

	for (int i = strlen(res); i >= pos; --i) {
		res[i + 1] = res[i];
	}

	res[pos] = kitu;

}

char* XuatNguoi(Nguoi* pN)
{

	strcat(pN->HoTen, "[");
	strcat(pN->DiaChi, "]");

	char* result = strcat(pN->HoTen,pN->DiaChi);

	return result;
}

int is_upper(char c)
{
	if (c >= 'A' && c < -'Z')
	{
		return 1;
	}
	return 0;
}

int is_lowwer(char c)
{
	if (c >= 'a' && c < 'z')
	{
		return 1;
	}
	return 0;
}

void NormalizeWord(char* a)
{
	int n = strlen(a);
	if (is_lowwer(a[0]))
	{
		a[0] = a[0] - 32;
	}

	for (int i = 1; i < n; i++)
	{
		if (is_lowwer(a[i]))
		{
			a[i] = a[i] - 32;
		}
	}
}

int demTu(char *s)
{
	int result = 0;

	
	const char* sep = " ;:,.\n\t";
	char* temp = new char[strlen(s) + 1];
	strcpy(temp, s);
	char* word = strtok(temp, sep);
	while(word!=NULL)
	{
		result++;
		word = strtok(NULL, sep);
	}

	delete[]temp;
	return result;
}

int getToken(char* token, char* s, int& startPos)
{
	int pos = startPos;
	int toPos;
	int n = strlen(s);
	int nToken = 0;

	strcpy(token, "");

	while ((pos < n) && (s[pos] == ' '))
	{
		pos++;
	}
	if (pos == n)
	{
		return nToken;
	}

	toPos = pos + 1;

	nToken = toPos - pos;
	strncpy(token, s + pos, nToken);
	token[nToken] = '\0';

	startPos = toPos;


	return nToken;
}

char* ChuanHoa(char *c)
{
	c[0] = toupper(c[0]);
	for (int i = 1; i < strlen(c); i++)
	{
		c[i] = tolower(c[i]);
	}
	return c;
}

void ChuanHoaTen(Nguoi* pN)
{
	char a[50][50];
	int n = 0;
	
	char* token = strtok(pN->HoTen, " ");
	while (token != NULL)
	{
		strcpy(a[n], token);
		++n;
		token = strtok(NULL, " ");
	}
	for (int i = 0; i < n ; i++)
	{
		if (a[i][0] != '[')
		{
			ChuanHoa(a[i]);
		}
	}
	char hoTenChuanHoa[MAXLEN] = "";
	char DiaChi[MAXLEN] = "";
	for (int i = 0; i < n; i++)
	{
		
		if (a[i][0] != '[') {
			strcat(hoTenChuanHoa, a[i]);
			strcat(hoTenChuanHoa, " ");
		}
	}

	//char *d = a[n - 1];
	char* d = pN->DiaChi;
	
	int index = 0;
	for (int i = 0; i < strlen(d); i++)
	{
		if (d[i] != '[' && d[i] != ']')
		{

			DiaChi[index] = d[i];
			index++;
		}
	}

	strcpy(pN->HoTen, hoTenChuanHoa);
	strcpy(pN->DiaChi, DiaChi);

}