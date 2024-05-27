#include<iostream>

using namespace std;

// 1. Đếm số chữ số của số n
int demSoCS(int n) {
	if (n < 10) {
		return 1;
	}
	return 1 + demSoCS(n / 10);
}

// 2. Tính tổng các chữ số của n
int tingTongCS(int n) {
	if (n < 10) {
		return n;
	}
	return n % 10 + tingTongCS(n / 10);
}

// 3. Tính tích các chữ số lẻ của n
int tinhTichCSLe(int n) {
	if (n < 10) {
		if (n % 2 == 0) {
			return 1;
		}
		else {
			return n;
		}
	}
	if (n % 2 == 0) {
		return tinhTichCSLe(n / 10);
	}
	else
	{
		return n % 10 * tinhTichCSLe(n / 10);
	}
}

// 4. Kiểm tra số n có phải số toàn chẵn không
bool laSoToanChan(int n) {
	if (n < 10) {
		if (n % 2 == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	if (n % 2 == 0) {
		return laSoToanChan(n / 10);
	}
	else {
		return false;
	}
}

// 5. Kiểm tra số n có phải số toàn lẻ không
int laSoToanLe(int n) {
	if (n < 10) {
		if (n % 2 == 0)
		{
			return false;
		}
		else {
			return true;
		}
	}
	if (n % 2 == 0) {
		return false;
	}
	else {
		return laSoToanLe(n / 10);
	}
}

int main() {

	cout << tingTongCS(1234) << "\n";
	cout << tinhTichCSLe(1234) << "\n";
	cout << laSoToanChan(8284) << "\n";
	cout << laSoToanLe(1357) << "\n";

	return 0;
}