#include<iostream>

using namespace std;

struct Node {
	int info;
	Node* pNext;
};

struct Stack {
	Node* top;
};

Node* createNode(int info);

void Init(Stack& stack);
void Pop(Stack& stack);
void Push(Stack& stack, int info);
bool IsEmpty(Stack stack);
void Clear(Stack& stack);