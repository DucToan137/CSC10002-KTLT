#include<iostream>
using namespace std;


struct Stack {
	struct Node {
		int key;
		Node* pNext;
	};
	int size;
	Node* top;

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
		top = nullptr;
		size = 0;
	}

	int front()
	{
		if (size <= 0)
			return -1;
		return top->key;
	}

	bool Push(int data)
	{
		Node* node = createNode(data);
		if (top == nullptr)
			top = node;
		else
		{
			node->pNext = top;
			top = node;
		}
		size++;
		return true;
	}

	bool IsEmpty()
	{
		if (top == nullptr) return true;
		return false;
	}

	void Pop()
	{
		if (size <= 0)
			return;
		Node* tmp = top;
		top = top->pNext;
		delete tmp;
		size--;
	}

	void Clear()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}
	void print()
	{
		if (IsEmpty())
		{
			cout << "\nStack rong" << endl;
			return;
		}
		while (!IsEmpty())
		{
			cout << front() << " ";
			Pop();
		}
	}
};


int main() {


	Stack s;
	s.Init();

	s.Push(1);
	s.Push(2);
	s.Push(3);

	cout << "Cac phan tu cua Stack: \n";
	s.print();

	s.Clear();
	cout << "\nStack sau khi goi ham Clear(): ";
	s.print();


	return 0;
}