#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* pNext;
};

struct Stack {
	Node* top;
};

Node* createNode(int val);

void Init(Stack& s);
void Pop(Stack& s);
void Push(Stack& s, int val);
void setTop(Stack& s, int val);
int Top(Stack s);
bool IsEmpty(Stack s);
void Clear(Stack& s);