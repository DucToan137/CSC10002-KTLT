#include<iostream>

using namespace std;

struct Node {
	int val;
	Node* pNext;
};

struct List {
	Node* pHead;
	Node* pTail;
};

// 1.Tạo node
Node* createNode(int val) {
	Node* pNode = new Node;
	pNode->val = val;
	pNode->pNext = nullptr;

	return pNode;
}

// 2.Khởi tạo dslk 
void init(List* l) {
	l->pHead = nullptr;
	l->pTail = nullptr;
}

// 3.Kiểm tra ds rỗng
bool isEmpty(List* l) {
	if (l->pHead == nullptr) {
		return true;
	}
	return false;
}

// 4.Tìm node có chỉ số i
Node* chiSoNode(List* l, int i) {
	Node* temp = l->pHead;

	int idx = 0;
	while (temp != nullptr) {
		if (idx == i) {
			return temp;
		}
		++idx;
		temp = temp->pNext;
	}

	return nullptr;
}

// 5.Xác định vị trí node p
int viTriNode(List* l, Node* p) {
	Node* temp = l->pHead;
	int idx = 0;

	while (temp != nullptr) {
		if (temp == p) {
			return idx;
		}
		++idx;
		temp = temp->pNext;
	}
	return -1;
}

// 6.Chèn đầu
void addHead(List* l, int val) {
	Node* pNode = createNode(val);

	if (l->pHead == nullptr) {
		l->pHead = l->pTail = pNode;
		return;
	}

	pNode->pNext = l->pHead;
	l->pHead = pNode;
}

// 7.Chèn cuối
void addTail(List* l, int val) {
	Node* pNode = createNode(val);

	if (l->pHead == nullptr) {
		l->pHead = l->pTail = nullptr;
	}

	l->pTail->pNext = pNode;
	l->pTail = pNode;
	
}

// 8.Chèn trước 1 node
void addBeforeNode(List* l, Node* p, int val) {
	Node* pNode = createNode(val);

	if (l->pHead == nullptr) {
		l->pHead = l->pTail = pNode;
	}

	if (p == l->pHead) {
		addHead(l, val);
		return;
	}

	Node* temp = l->pHead;
	while (temp != nullptr) {
		if (temp->pNext == p) {
			pNode->pNext = temp->pNext;
			temp->pNext = pNode;
			break;
		}
		temp = temp->pNext;
	}

	return;
}

// 9.Chèn sau 1 node
void addAfterNode(List* l, Node* p, int val) {
	Node* pNode = createNode(val);

	if (p == l->pTail) {
		addTail(l, val);
	}

	Node* temp = l->pHead;

	while (temp != nullptr) {
		if (temp == p) {
			pNode->pNext = temp->pNext;
			temp->pNext = pNode;
		}
		temp = temp->pNext;
	}

	return;
}

// 10.Hủy đầu
void deleteHead(List* l) {
	if (l->pHead == nullptr) {
		return;
	}

	Node* temp = l->pHead;
	l->pHead = l->pHead->pNext;
	delete temp;
}

// 11.Hủy cuối
void deleteTail(List* l) {
	if (l->pHead == nullptr) {
		return;
	}

	Node* temp = l->pHead;
	while (temp != nullptr) {
		if (temp->pNext == l->pTail) {
			temp->pNext = nullptr;
			delete l->pTail;
			l->pTail = temp;
		}
		temp = temp->pNext;
	}
}

// 12.Hủy sau 1 node
void deleteAfterNode(List* l, Node* p) {
	if (l->pHead == nullptr || p == l->pTail) {
		return;
	}

	Node* temp = l->pHead;
	while (temp!=nullptr) {
		if (temp == p) {

			if (temp->pNext == l->pTail) {
				deleteTail(l);
				return;
			}
			else {
				
				Node* node = temp->pNext;
				temp->pNext = temp->pNext->pNext;
				delete node;
				return;
			}
		}
		temp = temp->pNext;
	}
}

// 13.Hủy trước 1 node
void deleteBeforeNode(List* l, Node* p) {
	if (l->pHead == nullptr) {
		return;
	}

	if (l->pHead->pNext == p) {
		deleteHead(l);
		return;
	}

	Node* temp = l->pHead;
	while (temp != nullptr) {
		if (temp->pNext->pNext == p && temp->pNext != nullptr) {

			Node* node = temp->pNext;
			temp->pNext = node->pNext;
			delete node;
			return;

		}
		temp = temp->pNext;
	}

}

// 14.Hủy toàn bộ
void clearList(List* l) {
	while (l->pHead != nullptr) {
		deleteHead(l);
	}
}

// 15.In dslk
void print(List* l) {
	Node* temp = l->pHead;
	while (temp != nullptr) {
		cout << temp->val << " ";
		temp = temp->pNext;
	}
	cout << "\n";
}

// STACK

struct Stack {
	Node* top;
};

void init(Stack& s) {
	s.top = nullptr;
}

bool isEmpty(Stack s) {
	if (s.top == nullptr) {
		return true;
	}
	return false;
}

void push(Stack& s, int val) {
	Node* pNode = createNode(val);
	pNode->pNext = s.top;
	s.top = pNode;
}

void pop(Stack& s) {
	Node* temp = s.top;
	s.top = s.top->pNext;
	delete temp;
}

int Top(Stack s) {
	return s.top->val;
}

void clear(Stack& s) {
	while (!isEmpty(s)) {
		pop(s);
	}
}

int main() {

	List* l = new List;
	init(l);

	addHead(l, 1);
	addHead(l, 2);
	addHead(l, 3);
	addHead(l, 4);
	addHead(l, 5);

	cout << "Danh sach\n";
	print(l);

	/*cout << "Xoa dau\n";
	deleteHead(l);
	print(l);*/

	/*cout << "Xoa cuoi\n";
	deleteTail(l);
	print(l);*/

	/*cout << "Xoa sau node\n";
	deleteAfterNode(l, l->pHead);
	print(l);*/

	cout << "Xoa truoc node\n";
	deleteBeforeNode(l, l->pTail);
	print(l);

	/*cout << "Xoa toan bo\n";
	clearList(l);
	print(l);*/

	cout << "Chen truoc node\n";
	addBeforeNode(l, l->pTail, 6);
	print(l);
	cout << "Chen sau node\n";
	addAfterNode(l, l->pHead, 6);

	/*Node* p = chiSoNode(l, 2);
	cout << p->val << endl;
	int idx = viTriNode(l, p);
	cout << idx << endl;*/

	//addTail(l, 6);
	print(l);

	return 0;
}