#include<iostream>

using namespace std;

bool isPalidrome(int l, int r, char* s)
{
	
	while (l < r)
	{
		if (s[l] != s[r])
			return false;
		l++;
		r--;
	}
}

int main() {

	char s[] = "aababbaa";
	if (isPalidrome(0, strlen(s) - 1, s)) {
		cout << "yes\n";
	}
	else {
		cout << "no\n";
	}

	return 0;
}