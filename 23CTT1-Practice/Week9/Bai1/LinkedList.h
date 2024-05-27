#pragma once
#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* pNext;
};

struct LinkedList {
	Node* pHead;
	Node* pTail;
};

void init(LinkedList& list);
Node* createNode(int data);
void addTail(LinkedList& list, int val);
void addHead(LinkedList& list, int val);
void printList(LinkedList list);
int soLuongPhanTu(LinkedList l);
void chiaDSLK(LinkedList l, LinkedList& l1, LinkedList& l2);
void chiaDSLKTheoNode(LinkedList l, LinkedList& l1, LinkedList& l2, Node* p);
