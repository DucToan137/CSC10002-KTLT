#include"LinkedList.h"

void init(LinkedList& list) {
	list.pHead = list.pTail = NULL;
}

Node* createNode(int data) {
	Node* p = new Node;
	if (p == NULL) {
		return NULL;
	}
	p->data = data;
	p->pNext = NULL;
	return p;
}

void addTail(LinkedList& list, int val) {
	Node* p = createNode(val);

	if (list.pHead == NULL) {
		list.pHead = list.pTail = p;
	}
	else {
		list.pTail->pNext = p;
		list.pTail = p;
	}
}

void addHead(LinkedList& list, int val) {
	Node* p = createNode(val);

	if (list.pHead == NULL) {
		list.pHead = list.pTail = p;
	}
	else {
		p->pNext = list.pHead;
		list.pHead = p;
	}
}

void printList(LinkedList list) {
	Node* p = list.pHead;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->pNext;
	}
}

int soLuongPhanTu(LinkedList l)
{
	if (l.pHead == NULL)
	{
		return 0;
	}
	int dem = 0;
	Node* tmp = l.pHead;
	while (tmp != NULL)
	{
		dem++;
		tmp = tmp->pNext;
	}
	return dem;
}

void chiaDSLK(LinkedList l, LinkedList& l1, LinkedList& l2)
{
	if (l.pHead == NULL)
	{
		return;
	}

	int dem = soLuongPhanTu(l);
	int i = 0;
	Node* tmp = l.pHead;

	while (tmp != NULL)
	{
		if (i > dem / 2)
		{
			addTail(l2, tmp->data);
		}
		else
		{
			addTail(l1, tmp->data);
		}
		i++;
		tmp = tmp->pNext;
	}
}

void chiaDSLKTheoNode(LinkedList l, LinkedList& l1, LinkedList& l2, Node* p)
{
	if (l.pHead == NULL)
	{
		return;
	}

	int flag = 0;
	int i = 0;
	Node* tmp = l.pHead;
	while (tmp != NULL)
	{
		if (tmp->data == p->data)
		{
			flag = 1;
			break;
		}
		++i;
		tmp = tmp->pNext;
	}

	if (flag == 0)
	{
		return;
	}

	int j = 0;
	tmp = l.pHead;

	while (tmp != NULL)
	{
		if (j >= i)
		{
			addTail(l2, tmp->data);
		}
		else
		{
			addTail(l1, tmp->data);
		}
		tmp = tmp->pNext;
		++j;

	}
}
