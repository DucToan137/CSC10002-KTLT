#pragma once
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

//1
int CompareData(Data a, Data b);
//2
void Init(LinkedList& list);
//3
bool IsEmpty(LinkedList list);
//4
void PrintList(LinkedList list);
//5
Node* CreateNode(Data info);
//6
Node* GetNodePointer(LinkedList list, Data info);
//7
Node* GetNodePointer(LinkedList list, int index);
//8
int GetNodeIndex(LinkedList list, Node* p);
//9
Node* GetPreviousNodePointer(LinkedList list, Node* p);
//10
void AddHead(LinkedList& list, Node* p);
//11
void AddHead(LinkedList& list, Data info);
//12
void AddTail(LinkedList& list, Node* p);
//13
void AddTail(LinkedList& list, Data info);
//14
void AddAfter(LinkedList& list, Node* q, Node* p);
//15
void AddAfter(LinkedList& list, Node* q, Data info);
//16
void AddBefore(LinkedList& list, Node* q, Node* p);
//17
void AddBefore(LinkedList& list, Node* q, Data info);
//18
void AddAscendingList(LinkedList& l, Node* p);
//19
void AddAscendingList(LinkedList& l, Data info);
//20
void RemoveHead(LinkedList& list);
Data RemoveDataHead(LinkedList& list);
//21
void RemoveTail(LinkedList& list);
Data RemoveDataTail(LinkedList& list);
//22
void RemoveAfter(LinkedList& list, Node* q);
Data RemoveDataAfter(LinkedList& list, Node* q);
//23
bool RemoveBefore(LinkedList& list, Data info);
//24
void RemoveList(LinkedList& list);
//25
int RemoveKeys(LinkedList& l, Data k);
//26
void SortList(LinkedList& l);
//27
LinkedList CombineList(const LinkedList& l1, const LinkedList& l2);
//28
void ReverseList(LinkedList& l);
//29
void HoanViNode(LinkedList& l, Node* p, Node* q);

