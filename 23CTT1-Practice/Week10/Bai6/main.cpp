#include<iostream>
#include"TowerofHanoi.h"

using namespace std;



int main() {

	cout << "Nhap so dia: ";
	int n;
	cin >> n;

	Tower(n, 1, 2, 3);

	return 0;
}