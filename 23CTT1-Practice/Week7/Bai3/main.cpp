#include<iostream>
using namespace std;


struct Node {
	int info;
	Node* pNext;
};

struct LinkedList {
	Node* pHead;
	Node* pTail;
};

Node* CreateNode(const int& value)
{
	Node* p = new Node();
	if (p != NULL)
	{
		p->info = value;
		p->pNext = NULL;
	}
	return p;
}

LinkedList* CreateLinkedList()
{
	LinkedList* ll = new LinkedList();
	if (ll != NULL)
	{
		ll->pHead = ll->pTail = NULL;
	}
	return ll;
}

bool AddNode(LinkedList* dslk, const int& value)
{
	Node* p = CreateNode(value);
	if (p == NULL)
	{
		return false;
	}

	if (dslk->pHead == NULL)
	{
		dslk->pHead = dslk->pTail = p;
		return true;
	}

	dslk->pTail->pNext = p;
	dslk->pTail = p;

	return true;
}

bool InsertNode(LinkedList* dslk, Node* node, const int& value)
{
	Node* p = CreateNode(value);
	if (p == NULL)
	{
		return false;
	}

	Node* temp = NULL;
	for (temp = dslk->pHead; temp != NULL; temp = temp->pNext)
	{
		if (temp == NULL)
		{
			break;
		}
	}

	if (temp == NULL)
	{
		return false;
	}

	p->pNext = node->pNext;
	node->pNext = p;

	return true;
}

int DeleteNode(LinkedList* dslk, const int& value)
{
	int sl = 0;
	Node* pOld = dslk->pHead;
	while (pOld != NULL && pOld->info == value)
	{
		dslk->pHead = pOld->pNext;
		if (pOld == dslk->pTail)
		{
			dslk->pTail = pOld->pNext;
		}
		delete pOld;
		sl++;
		pOld = dslk->pHead;
	}
	for (Node* p = pOld->pNext; p != NULL; p = p->pNext)
	{
		if (p->info == value)
		{
			Node* pTemp = p;
			pOld->pNext = p->pNext;
			p = pOld;
			delete pTemp;
			sl++;
		}
		else
		{
			pOld = p;
		}
	}
	return sl;
}

void DeleteLinkedList(LinkedList* dslk)
{
	Node* p = dslk->pHead;
	while (p != NULL)
	{
		dslk->pHead = p->pNext;
		delete p;
		p = dslk->pHead;
	}
	delete dslk;
}

LinkedList* GenerateLinkedList(const int& slMin, const int& slMax, const int& gtMin, const int& gtMax)
{
	LinkedList* dslk = CreateLinkedList();
	if (dslk == NULL)
	{
		return NULL;
	}

	int sl = slMin + rand() % (slMax - slMin + 1);

	for (int i = 0; i < sl; ++i)
	{
		AddNode(dslk, gtMin + rand() % (gtMax - gtMin + 1));
	}

	return dslk;
}

void PrintList(LinkedList* dslk)
{
	if (dslk->pHead != NULL)
	{
		Node* tmp = dslk->pHead;
		while (tmp != NULL)
		{
			cout << tmp->info << " ";
			tmp = tmp->pNext;
		}
	}
	return;
}

int Max(LinkedList* dslk)
{
	int max = -1;
	if (dslk->pHead != NULL)
	{
		max = dslk->pHead->info;
		Node* tmp = dslk->pHead;
		while (tmp != NULL)
		{
			if (tmp->info > max)
			{
				max = tmp->info;
			}
			tmp = tmp->pNext;
		}
	}
	else
	{
		cout << "Danh sach lien ket rong\n";
	}
	return max;
}

int tinhTong(LinkedList* dslk)
{
	int res = 0;
	if (dslk->pHead != NULL)
	{
		Node* tmp = dslk->pHead;
		while (tmp != NULL)
		{
			res += tmp->info;
			tmp = tmp->pNext;
		}
	}
	return res;
}

int soLuongPhanTuMax(LinkedList* dslk)
{
	int res = 0;
	if (dslk->pHead != NULL)
	{
		int max = Max(dslk);
		Node* tmp = dslk->pHead;
		while (tmp != NULL)
		{
			if (tmp->info == max)
			{
				res++;
			}
			tmp = tmp->pNext;
		}
	}

	return res;
}

void Sort(LinkedList*& dslk)
{
	for (Node* tmp = dslk->pHead; tmp != NULL; tmp = tmp->pNext)
	{
		for (Node* tmp2 = tmp->pNext; tmp2 != NULL; tmp2 = tmp2->pNext)
		{
			if (tmp->info > tmp2->info)
			{
				swap(tmp->info, tmp2->info);
			}
		}
	}
}



int main() {
	LinkedList* list1 = GenerateLinkedList(10, 100, -50, 50);

	cout << "List1: \n";
	PrintList(list1);

	int x = rand() % (10 - (-10) + 1);
	cout << "\nX=" << x << "\n";
	
	LinkedList* list2 = CreateLinkedList();
	LinkedList* list3 = CreateLinkedList();

	Node* tmp = list1->pHead;
	while (tmp != NULL)
	{
		if (tmp->info < x)
		{
			AddNode(list2, tmp->info);
		}
		else
		{
			AddNode(list3, tmp->info);
		}
		tmp = tmp->pNext;
	}

	cout << "List 2(nho hon X):\n";
	PrintList(list2);

	cout << "\nList 3(con lai):\n";
	PrintList(list3);

	return 0;
}