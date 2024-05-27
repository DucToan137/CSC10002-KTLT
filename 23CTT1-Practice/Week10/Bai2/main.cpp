#include<iostream>

using namespace std;

bool isPalidrome(int l, int r, char* s)
{
	if (l >= r)
	{
		return true;
	}
	if (s[l] != s[r])
	{
		return false;
	}
	return isPalidrome(l + 1, r - 1, s);
}




int main() {

	char s[] = "abcdacba";
	if (isPalidrome(0, 7, s))
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}


	return 0;
}