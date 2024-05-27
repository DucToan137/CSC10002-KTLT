#include<iostream>
using namespace std;

struct Node {
	int info;
	Node* pNext;
};

struct List {
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

List* CreateList()
{
	List* ll = new List();
	if (ll != NULL)
	{
		ll->pHead = ll->pTail = NULL;
	}
	return ll;
}

bool AddNode(List* dslk, const int& value)
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

bool InsertNode(List* dslk, Node* node, const int& value)
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

int DeleteNode(List* dslk, const int& value)
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

void DeleteList(List* dslk)
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

List* GenerateList(const int& slMin, const int& slMax, const int& gtMin, const int& gtMax)
{
	List* dslk = CreateList();
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

void PrintList(List* dslk)
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

int CompareData(int a, int b)
{
	if (a == b)
		return 0;
	if (a < b)
		return 1;
	return -1;
}

// Hàm tìm node đầu tiên trong DSLK cho trước có dữ liệu từ trước
// Đầu vào: DSLK (l), dữ liệu của node cần tìm (info)
// Đầu ra: Con trỏ đến node tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, int info)
{
	Node* p = l.pHead;
	if (p == NULL)
	{
		return p;
	}
	while (p != NULL && CompareData(p->info, info) != 0)
	{
		p = p->pNext;
	}
	return p;
}

// Hàm tìm node có chỉ số(bắt đầu từ 0) cho trước
// Đầu vào: DSLK (l), chỉ số của node cần lấy (index)
// Đầu ra: Con trỏ đến node tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer1(List l, int index)
{
	Node* p = l.pHead;
	int i = 0;
	while (p != NULL && i < index)
	{
		p = p->pNext;
		++i;
	}
	return p;
}

// Hàm xác định vị trí của một node cho trước trong DSLK cho trước
// Đầu vào: DSLK (l), con trỏ đến node cần xác định vị trí (pNode)
// Đầu ra: Thứ tự của node cho trước (trả về -1 nếu node này không có trong DSLK)
int GetNodeIndex(List l, Node* pNode)
{
	if (l.pHead == NULL)
	{
		return -1;
	}
	Node* p = l.pHead;
	int i = 0;
	while (p != NULL)
	{
		if (p == pNode)
			return i;
		p = p->pNext;
		++i;
	}
	return -1;
}

// Hàm xác định con trỏ dên node đứng trước của một node cho trước trong DSLK
// Đầu vào: DSLK (l), con trỏ đến node cho trước (pNode)
// Đầu ra: Con trỏ đến node tìm dươc (trả về NULL nếu không tìm ra được)
Node* GetPreviousNodePointer(List l, Node* pNode)
{
	Node* p = l.pHead;
	Node* pOld = NULL;
	while (p != NULL)
	{
		if (p == pNode)
			return pOld;
		pOld = p;
		p = p->pNext;
	}
	return NULL;
}

// Hàm chén một node cho trước vào đầu DSLK
// Đầu vào: Tham chiếu đến DSLKK (l), con trỏ đến node cần chèn (pNewNode)
// Đầu ra: Không có
void AddHead(List& l, Node* pNewNode)
{
	pNewNode->pNext = l.pHead;
	l.pHead = pNewNode;
	if (l.pTail == NULL)
		l.pTail = l.pHead;
}

// Hàm chèn một node có dữ liệu cho trước vào đầu DSLK
// Đầu vào: Tham chiếu đến DSLK (l), dữ liệu của node cần chèn (info)
// Đầu ra: Con trỏ đến node được chèn (trả về NULL nếu không chèn được)
Node* AddHead(List& l, int info)
{
	Node* p = CreateNode(info);
	if (p != NULL)
		AddHead(l, p);
	return p;
}

// Hàm chèn một node cho trước vào cuối DSLK
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến node cần chèn (pNewNode)
// Đầu ra: Không có
void AddTail(List& l, Node* pNewNode)
{
	if (l.pTail == NULL)
	{
		l.pHead = pNewNode;
		l.pTail = pNewNode;
		l.pTail->pNext = NULL;
	}
	else
	{
		l.pTail->pNext = pNewNode;
		l.pTail = pNewNode;
	}
}

// Hàm chèn một node có dữ liệu cho trước vào cuối DSLK
// Đầu vào: Tham chiếu đến DSLK (l), dữ liệu của node cần chèn (info)
// Đầu ra: Con trỏ đến node được chèn (trả về NULL nếu không chèn được)
Node* AddTail(List& l, int info)
{
	Node* p = CreateNode(info);
	if (p != NULL)
		AddTail(l, p);
	return p;
}

// Hàm chèn một node cho trước vào sau một node khác cho trước
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến node cho trước (q), con trỏ đến 
// node cần chèn (pNewNode)
// Đầu ra: Không có
void AddAfter(List& l, Node* q, Node* pNewNode)
{
	Node* p = l.pHead;
	if (p == NULL || q == NULL)
		return;
	while (p != NULL)
	{
		if (p == q)
			break;
	}
	if (p == NULL)
		return;
	p = q->pNext;
	q->pNext = pNewNode;
	p->pNext = p;
	if (p == NULL)
		l.pTail = pNewNode;
}

// Hàm chèn một node có dữ liệu cho trước vào sau một node cho trước
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến node cho trước (q), dữ liệu của
// node cần chèn (info)
// Đầu ra: Con trỏ đến node được chèn (trả về NULL nếu không chèn được)
Node* AddAfter(List& l, Node* q, int info)
{
	if (q == NULL)
		return NULL;
	Node* p = CreateNode(info);
	if (p != NULL)
	{
		AddAfter(l, p, q);
	}
	if (q->pNext != p)
		return NULL;
	return p;
}

// Hàm chèn một node cho trước vào trước một node khác cho trước
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến node cho trước (q), con trỏ đến
// node cần chèn (pNewNode)
// Đầu ra: Không có
void AddBefore(List& l, Node* q, Node* pNewNode)
{
	if (q == NULL || pNewNode == NULL)
		return;
	if (q == l.pHead)
	{
		pNewNode->pNext = l.pHead;
		l.pHead = pNewNode;
		return;
	}
	Node* p = GetPreviousNodePointer(l, q);
	if (p == NULL)
		return;
	p->pNext = pNewNode;
	pNewNode->pNext = q;
}

// Hàm chèn một node có dữ liệu cho trước vào trước một node khác cho trước
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến node cho trước (q), dữ liệu của
// node cần chèn (info)
// Đầu ra: Con trỏ đến node được chèn (trả về NULL nếu không chèn được)
Node* AddBefore(List& l, Node* q, int info)
{
	if (q == NULL)
		return NULL;
	Node* p = CreateNode(info);
	if (p != NULL)
	{
		AddBefore(l, q, p);
		if (p->pNext != q)
			return NULL;
	}
	return p;
}

// Hàm chèn một node cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến node cần chèn (pNewNode)
// Đầu ra: Không có
void AddAscendingList(List& l, Node* pNewNode)
{
	if (pNewNode == NULL)
		return;
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (CompareData(p->info, pNewNode->info) > -1)
		{
			AddBefore(l, p, pNewNode);
			return;
		}
	}
	if (p == NULL && l.pTail != NULL)
	{
		l.pTail->pNext = pNewNode;
		l.pTail = pNewNode;
	}
}

// Hàm chèn một node có dữ liệu cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu ra: Tham chiếu đến DSLK (l), dữ liệu của node cần chèn (info)
// ĐẦu ra: Con trỏ đến node được chèn (trả về NULL nếu không chèn được)
Node* AddAscendingList(List& l, int info)
{
	Node* p = CreateNode(info);
	if (p != NULL)
	{
		AddAscendingList(l, p);
	}
	return p;
}

// Hàm hủy một node đầu DSLK
// Đầu vòa Tham chiếu đến DSLK (l)
// Đầu ra: Dữ liệu của node bị xóa
int RemoveHead(List& l)
{
	int kq = -1;
	if (l.pHead == NULL)
		return kq;
	Node* p = l.pHead;
	l.pHead = l.pHead->pNext;
	if (l.pHead == NULL)
		l.pTail = NULL;
	kq = p->info;
	delete p;
	return kq;
}

// Hàm hủy một node cuối DSLK
// Đầu vào: Tham chiếu đến DSLK (l)
// Đầu ra: Dữ liệu của node bị xóa
int RemoveTail(List& l)
{
	int kq = -1;
	if (l.pTail == NULL)
		return kq;
	Node* p = GetPreviousNodePointer(l, l.pTail);
	kq = l.pTail->info;
	delete l.pTail;
	l.pTail = p;
	if (p == NULL)
		l.pHead = p;
	return kq;
}

// Hàm hủy một node đứng sau một node cho trước trong DSLK
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến node cho trước (q)
// Đầu ra: Không có
int RemoveAfter(List& l, Node* q)
{
	if (q == NULL)
		return RemoveHead(l);
	int kq;
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (p == q)
			break;
		p = p->pNext;
	}
	if (p != NULL)
	{
		p = q->pNext;
		if (p != NULL)
		{
			q->pNext = q->pNext;
			kq = p->info;
			delete p;
			if (q->pNext == NULL)
				l.pTail = q;
		}
	}
	return kq;
}

// Hàm hủy một node có dữ liệu cho trước trong DSLK
// Đầu vào: Tham chiếu đến DSLK (l), dữ liệu của node cần xía (info)
// Đầu ra: Tìm thấy node có dữ liệu info hay không (true/false)
bool RemoveNode(List& l, int info)
{
	Node* p = GetNodePointer(l, info);
	if (p == NULL)
		return false;
	Node* q = GetPreviousNodePointer(l, p);
	if (q == NULL)
	{
		l.pHead = p->pNext;
		delete p;
		if (l.pHead == NULL)
			l.pTail = l.pHead;
		return true;
	}
	q->pNext = p->pNext;
	delete p;
	if (q->pNext == NULL)
		l.pTail = q;
	return true;
}

void SortASC(List* l)
{
	for (Node* tmp = l->pHead; tmp != NULL; tmp = tmp->pNext)
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

void SortDESC(List* l)
{
	for (Node* tmp = l->pHead; tmp != NULL; tmp = tmp->pNext)
	{
		for (Node* tmp2 = tmp->pNext; tmp2 != NULL; tmp2 = tmp2->pNext)
		{
			if (tmp->info < tmp2->info)
			{
				swap(tmp->info, tmp2->info);
			}
		}
	}
}



int main() {
	List* l = GenerateList(10, 100, -50, 50);
	SortASC(l);
	cout << "Danh sach lien ket tang dan:\n";
	PrintList(l);
	cout << "\nDanh sach lien ket giam dan:\n";
	SortDESC(l);
	PrintList(l);
	

	return 0;
}