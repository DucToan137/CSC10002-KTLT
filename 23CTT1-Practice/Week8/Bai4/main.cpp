#include<iostream>
using namespace std;


struct Queue {
	struct Node {
		int key;
		Node* pNext;
	};
	int size;
	Node* pHead;
	Node* pTail;

	Node* createNode(int data)
	{
		Node* p = new Node;
		if (!p) return nullptr;
		p->key = data;
		p->pNext = nullptr;
		return p;
	}

	void Init()
	{
		pHead = pTail = nullptr;
		size = 0;
	}

	bool Push(int data)
	{
		Node* node = createNode(data);
		if (!pHead)
			pHead = pTail = node;
		else
		{
			pTail->pNext = node;
			pTail = node;
		}
		size++;
		return true;
	}

	int Front()
	{
		if (size <= 0)
		{
			return -1;
		}
		return pTail->key;
	}

	bool IsEmpty()
	{
		if (pHead == nullptr)
		{
			return true;
		}
		return false;
	}

	void Pop()
	{
		if (size <= 0) return;
		pHead = pHead->pNext;
		size--;
	}

	void Clear()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	void Print()
	{
		if (IsEmpty())
			cout << "Queue rong " << endl;
		else
		{
			while (!IsEmpty())
			{
				cout << pHead->key << " ";
				Pop();
			}
		}
	}
};

int main() {

	Queue q;
	q.Init();

	q.Push(1);
	q.Push(2);
	q.Push(3);

	cout << "Cac phan tu cua Queue: \n";
	q.Print();

	q.Clear();
	cout << "\nQueue sau khi goi ham Clear()\n";
	q.Print();
	

	return 0;
}