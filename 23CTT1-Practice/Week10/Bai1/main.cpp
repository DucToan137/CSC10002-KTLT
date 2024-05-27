#include<iostream>

using namespace std;

// 1. S(n) = 1 + 2 + 3 + ... + n
int S1(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return S1(n - 1) + n;
}

// 2. S(n) = 1 + 1/2 + 1/3 + ... + 1/n
double S2(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return S2(n-1) + 1.0 / n;
}

// 3. T(n) = n!
int T(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return T(n - 1) * n;
}

// 4. T(n) = x^n
int T2(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	return T2(x, n - 1) * x;
}

// 6. Fibonacci
// a. f(0) = f(1) = 1
// b. f(n) = f(n-1) + f(n-2), n>1
int Fibonacci(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// 7. x(n), y(n)
// a. x(0) = 1
// b. y(0) = 0
// c. x(n) = x(n-1) + y(n-1)
// d. y(n) = 3*x(n-1) + 2*y(n-1)
int yn(int n);
int xn(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return xn(n - 1) + yn(n - 1);
}

int yn(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return 3*xn(n-1) + 2*yn(n - 1);
}

// 8. C(n,k) = n, k = 1
// C(n, k) = 1, n = k
// C(n, k) = C(n, k-1) + C(n-1, k -1), 1<k<n
int Ckn(int n, int k)
{
	if (k == 1)
	{
		return n;
	}
	if (n == k)
	{
		return 1;
	}
	return Ckn(n, k - 1) + Ckn(n - 1, k - 1);
}

int main() {

	int n = 5;
	cout << S1(n) << endl;
	cout << S2(n) << endl;
	cout << T(n) << endl;
	cout << T2(2, n) << endl;
	cout << Fibonacci(n) << endl;
	cout << Ckn(5, 2) << endl;
	

	return 0;
}