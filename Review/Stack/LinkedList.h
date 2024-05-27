#include<iostream>

using namespace std;

struct Data {
	int x;
};

struct Node {
	Data info;
	Node* pNext;
};

struct LinkedList {
	Node* pHead;
	Node* pTail;
};

Node* CreateNode(Data info);
void Init(LinkedList& l);
bool IsEmpty(LinkedList l);
void AddHead(LinkedList& l, Node* p);
void RemoveHead(LinkedList& l);
Data RemoveDataHead(LinkedList& list);
void RemoveList(LinkedList& l);
void PrintList(LinkedList l);

