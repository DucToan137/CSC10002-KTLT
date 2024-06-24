#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

#pragma warning(disable:4996)


int main() {

	char hoten[] = "Nguyen Van A";

	char a[6] = "12345";
	char *b = new char[6];

	strcpy(b, a);

	int c = atoi(a);
	
	
	//ultoa(123456, b, 10);


	cout << c << endl;



	return 0;
}