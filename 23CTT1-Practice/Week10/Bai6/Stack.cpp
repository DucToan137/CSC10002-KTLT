#include"Stack.h"

Node* createNode(int val) 
{
	Node* p = new Node;
	if (p == nullptr) 
	{
		return nullptr;
	}

	p->data = val;
	p->pNext = nullptr;
	return p;
}

void Init(Stack& s) 
{
	s.top = nullptr;
}

void Pop(Stack& s) 
{
	if (IsEmpty(s)) 
	{
		return;
	}
	Node* deleteNode = s.top;
	s.top = s.top->pNext;
	delete deleteNode;
	deleteNode = nullptr;
}

void Push(Stack& s, int val) {
	Node* node = createNode(val);
	if (s.top == nullptr) {
		s.top = node;
	}
	else {
		node->pNext = s.top;
		s.top = node;
	}
}

int Top(Stack s) {
	if (s.top == nullptr) {
		return -1;
	}
	return s.top->data;
}

bool IsEmpty(Stack s) {
	if (s.top == nullptr) {
		return true;
	}
	return false;
}

void Clear(Stack& s) {
	while (!IsEmpty(s)) {
		Pop(s);
	}
}


void setTop(Stack& s, int val) {
	if (s.top == nullptr) {
		return;
	}
	s.top->data = val;
}