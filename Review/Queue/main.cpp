#include<iostream>
#include"Queue.h"

using namespace std;

int main() {

	Queue q;
	Init(q);

	Data a = { 1 };
	EnQueue(q, a);
	Data b = { 2 };
	EnQueue(q, b);
	Data c = { 3 };
	EnQueue(q, c);
	Data d = { 4 };
	EnQueue(q, d);

	PrintQueue(q);

	DeQueue(q);
	PrintQueue(q);

	Clear(q);
	PrintQueue(q);


	return 0;
}