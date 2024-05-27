#include"LinkedList.h"



Node* CreateNode(Data info) {
	Node* p = new Node;
	if (p == nullptr) {
		return nullptr;
	}
	p->info = info;
	p->pNext = nullptr;
	return p;
}

void Init(LinkedList& l) {
	l.pHead = nullptr;
	l.pTail = nullptr;
}

bool IsEmpty(LinkedList l) {
	return l.pHead == nullptr;

}

void AddHead(LinkedList& l, Node* p) {
	if (IsEmpty(l)) {
		l.pHead = p;
		l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void AddTail(LinkedList& list, Node* p) {
	if (IsEmpty(list)) {
		list.pHead = p;
		list.pTail = p;
	}
	else {
		list.pTail->pNext = p;
		list.pTail = p;
	}
}

void RemoveHead(LinkedList& l) {
	if (IsEmpty(l)) {
		return;
	}
	Node* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
	if (l.pHead == nullptr) {
		l.pTail = nullptr;
	}
}

Data RemoveDataHead(LinkedList& l) {
	if (IsEmpty(l)) {
		return { 0 };
	}
	Node* p = l.pHead;
	l.pHead = l.pHead->pNext;
	Data info = { p->info };
	delete p;
	if (l.pHead == nullptr) {
		l.pTail = nullptr;
	}
	return info;
}

Data RemoveDataTail(LinkedList& list) {
	if (IsEmpty(list)) {
		return { 0 };
	}
	Node* p = list.pHead;
	Node* q = nullptr;
	while (p != list.pTail) {
		q = p;
		p = p->pNext;
	}
	if (q == nullptr) {
		return RemoveDataHead(list);
	}
	else {
		q->pNext = nullptr;
		Data info = { p->info };
		delete p;
		list.pTail = q;
		return info;
	}
}

void RemoveList(LinkedList& l) {
	while (!IsEmpty(l)) {
		RemoveHead(l);
	}
}

void PrintList(LinkedList l) {
	Node* p = l.pHead;
	while (p != nullptr) {
		cout << p->info.x << " ";
		p = p->pNext;
	}
	cout << endl;
}