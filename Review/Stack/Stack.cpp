#include"Stack.h"


void Init(Stack& s) {
	Init(s.l);
}

bool IsEmpty(Stack s) {
	return IsEmpty(s.l);
}

Data Pop(Stack& s) {
	Data info;
	if (!IsEmpty(s)) {
		info = RemoveDataHead(s.l);
	}
	return info;
}

bool Push(Stack& s, Data info) {
	Node* p = CreateNode(info);
	if (p == NULL) {
		return false;
	}
	AddHead(s.l, p);
	return true;
}

void PrintStack(Stack s) {
	PrintList(s.l);
}

void Clear(Stack& s) {
	RemoveList(s.l);
}