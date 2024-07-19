#include<iostream>

using namespace std;

struct Node {
	int val;
	Node* pNext;
};

struct Queue {
	Node* front;
	Node* rear;
};

void init(Queue& q) {
	q.front = q.rear = nullptr;
}

bool isEmpty(Queue q) {
	if (q.front == nullptr) {
		return true;
	}
	return false;
}

Node* createNode(int val) {
	Node* pNode = new Node;

	pNode->val = val;
	pNode->pNext = nullptr;

	return pNode;
}

void enQueue(Queue& q, int val) {
	Node* pNode = createNode(val);

	if(isEmpty(q)) {
		q.front = q.rear = pNode;
		return;
	}

	q.rear->pNext = pNode;
	q.rear = pNode;
}

void deQueue(Queue& q) {
	
	Node*temp = q.front;
	q.front = q.front->pNext;
	delete temp;
}

int Front(Queue& q) {
	return q.front->val;
}

void clear(Queue& q) {
	while (!isEmpty(q))
	{
		deQueue(q);
	}
}

void print(Queue q) {
	Node* temp = q.front;

	while(temp != nullptr) {
		cout << temp->val << " ";
		temp = temp->pNext;
	}
	cout << "\n";
}


int main() {

	Queue q;
	init(q);

	enQueue(q, 1);
	enQueue(q, 2);
	enQueue(q, 3);
	enQueue(q, 4);
	enQueue(q, 5);

	// print(q);

	deQueue(q);
	print(q);

	return 0;
}