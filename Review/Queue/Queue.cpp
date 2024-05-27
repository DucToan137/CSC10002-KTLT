#include"Queue.h"

void Init(Queue& q) {
	Init(q.l);
}

bool IsEmpty(Queue q) {
	return IsEmpty(q.l);
}

Data DeQueue(Queue& q) {
	return RemoveDataHead(q.l);
}

bool EnQueue(Queue& q, Data info) {
	Node*p=CreateNode(info);
	if (p == nullptr) {
		return false;
	}
	AddTail(q.l, p);
	return true;
}

void PrintQueue(Queue q) {
	PrintList(q.l);
}

void Clear(Queue& q) {
	RemoveList(q.l);
}
