#include<iostream>

using namespace std;

struct Node {
	int val;
	Node* pNext;
};

Node* createNode(int val) {
	Node* pNode = new Node;

	pNode->val = val;
	pNode->pNext = nullptr;

	return pNode;
}

struct Stack {
	Node* top;
};

void init(Stack& s) {
	s.top = nullptr;
}

bool isEmpty(Stack s) {
	if (s.top == nullptr) {
		return true;
	}
	return false;
}

void push(Stack& s, int val) {
	Node* pNode = createNode(val);
	pNode->pNext = s.top;
	s.top = pNode;
}

void pop(Stack& s) {
	Node* temp = s.top;
	s.top = s.top->pNext;
	delete temp;
}

int Top(Stack s) {
	return s.top->val;
}

void clear(Stack& s) {
	while (!isEmpty(s)) {
		pop(s);
	}
}

void print(Stack s) {
	Node* temp = s.top;
	while (temp != nullptr) {
		cout << temp->val << " ";
		temp = temp->pNext;
	}
	cout << "\n";
}

int main() {

	Stack s;
	init(s);

	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	push(s, 5);

	print(s);
	pop(s);

	print(s);

	return 0;
}