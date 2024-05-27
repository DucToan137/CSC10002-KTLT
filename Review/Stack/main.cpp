#include<iostream>
#include"Stack.h"

using namespace std;

int main() {

	Stack s;
	Init(s);

	Data a = { 1 };
	Push(s, a);
	Data b = { 2 };
	Push(s, b);
	Data c = { 3 };
	Push(s, c);
	Data d = { 4 };
	Push(s, d);

	PrintStack(s);

	Pop(s);
	PrintStack(s);

	Clear(s);
	PrintStack(s);


	return 0;
}