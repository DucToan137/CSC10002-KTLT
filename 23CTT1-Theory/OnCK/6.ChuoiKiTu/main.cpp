#include<iostream>
#include<string.h>
#include<string>
#include<sstream>
using namespace std;


int main() {

	char str[100] = "Nguyen Van A";
	char str1[100] = "Van";

	// cout << strstr(str, str1) << endl;

	string a ="Nguyen Van A";

	string b;
	stringstream ss(a);
	

	while(getline(ss,b, '-')) {
		cout << b << endl;
	}


	return 0;
}