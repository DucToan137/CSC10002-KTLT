#include"LinkedList.h"



// 1.So sánh 2 biến kiểu cấu trúc cho trước
int CompareData(Data a, Data b) {
	if (a.x > b.x) {
		return 1;
	}
	else if (a.x < b.x) {
		return -1;
	}
	return 0;
}

// 2.Khởi tạo DSLK
void Init(LinkedList& list) {
	list.pHead = nullptr;
	list.pTail = nullptr;
}

// 3.Kiểm tra DSLK rỗng
bool IsEmpty(LinkedList list) {
	return list.pHead == nullptr;
}

// 4.In ra DSLK
void PrintList(LinkedList list) {
	Node* p = list.pHead;
	while (p != nullptr) {
		cout << p->info.x << " ";
		p = p->pNext;
	}
	cout << endl;
}

// 5.Tạo node
Node* CreateNode(Data info) {
	Node* p = new Node;
	if (p == nullptr) {
		return nullptr;
	}
	p->info = info;
	p->pNext = nullptr;
	return p;
}

// 6.Tìm node đầu tiên trong DSLK có dữ liệu cho trước
Node* GetNodePointer(LinkedList list, Data info) {
	Node* p = list.pHead;
	while (p != nullptr) {
		if (p->info.x == info.x) {
			return p;
		}
		p = p->pNext;
	}
	return nullptr;
}

// 7.Tìm node có chỉ số (bắt đầu từ 0) cho trước
Node* GetNodePointer(LinkedList list, int index) {
	Node* p = list.pHead;
	int count = 0;
	while (p != nullptr) {
		if (count == index) {
			return p;
		}
		count++;
		p = p->pNext;
	}
	return nullptr;
}

// 8.Xác định vị trí của một node cho trước
int GetNodeIndex(LinkedList list, Node* p) {
	Node* q = list.pHead;
	int count = 0;
	while (q != nullptr) {
		if (q == p) {
			return count;
		}
		count++;
		q = q->pNext;
	}
	return -1;
}

// 9.Xác định con trỏ đến node đứng trước node cho trước
Node* GetPreviousNodePointer(LinkedList list, Node* p) {
	Node* q = list.pHead;
	while (q != nullptr) {
		if (q->pNext == p) {
			return q;
		}
		q = q->pNext;
	}
	return nullptr;
}

// 10.Chèn một node cho trước vào đầu
void AddHead(LinkedList& list, Node* p) {
	if (IsEmpty(list)) {
		list.pHead = p;
		list.pTail = p;
	}
	else {
		p->pNext = list.pHead;
		list.pHead = p;
	}
}

// 11.Chén một node có dữ liệu vào đầu
void AddHead(LinkedList& list, Data info) {
	Node* p = CreateNode(info);
	if (p == nullptr) {
		return;
	}
	AddHead(list, p);
}

// 12.Chèn một node cho trước vào cuối
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

// 13.Chèn một node có dữ liệu vào cuối
void AddTail(LinkedList& list, Data info) {
	Node* p = CreateNode(info);
	if (p == nullptr) {
		return;
	}
	AddTail(list, p);
}

// 14.Chèn một node cho trước vào sau một node cho trước
void AddAfter(LinkedList& list, Node* q, Node* p) {
	if (q == nullptr) {
		return;
	}
	if (q == list.pTail) {
		AddTail(list, p);
	}
	else {
		p->pNext = q->pNext;
		q->pNext = p;
	}
}

// 15.Chèn một node có dữ liệu vào sau một node cho trước
void AddAfter(LinkedList& list, Node* q, Data info) {
	Node* p = CreateNode(info);
	if (p == nullptr) {
		return;
	}
	AddAfter(list, q, p);
}

// 16.Chèn một node cho trước vào trước một node cho trước
void AddBefore(LinkedList& list, Node* q, Node* p) {
	if (q == nullptr) {
		return;
	}
	if (q == list.pHead) {
		AddHead(list, p);
	}
	else {
		Node* r = GetPreviousNodePointer(list, q);
		AddAfter(list, r, p);
	}
}

// 17.Chèn một node có dữ liệu vào trước một node cho trước
void AddBefore(LinkedList& list, Node* q, Data info) {
	Node* p = CreateNode(info);
	if (p == nullptr) {
		return;
	}
	AddBefore(list, q, p);
}

// 18.Chèn một node cho trước sao cho DSLK vẫn tăng dần
void AddAscendingList(LinkedList& l, Node* p) {
	if (IsEmpty(l) || CompareData(p->info, l.pHead->info) < 0) {
		AddHead(l, p);
	}
	else if (CompareData(p->info, l.pTail->info) > 0) {
		AddTail(l, p);
	}
	else {
		Node* q = l.pHead;
		while (q != nullptr) {
			if (CompareData(p->info, q->info) < 0) {
				AddBefore(l, q, p);
				break;
			}
			q = q->pNext;
		}
	}
}
// 19.Chèn một node có dữ liệu sao cho DSLK vẫn tăng dần
void AddAscendingList(LinkedList& l, Data info) {
	Node* p = CreateNode(info);
	if (p == nullptr) {
		return;
	}
	AddAscendingList(l, p);
}

// 20.Hàm hủy 1 node đầu DSLK
void RemoveHead(LinkedList& list) {
	if (IsEmpty(list)) {
		return;
	}
	Node* p = list.pHead;
	list.pHead = list.pHead->pNext;
	delete p;
	if (list.pHead == nullptr) {
		list.pTail = nullptr;
	}
}

Data RemoveDataHead(LinkedList& list) {
	if (IsEmpty(list)) {
		return { 0 };
	}
	Node* p = list.pHead;
	list.pHead = list.pHead->pNext;
	Data info = { p->info };
	delete p;
	if (list.pHead == nullptr) {
		list.pTail = nullptr;
	}
	return info;
}

// 21.Hàm hủy 1 node cuối DSLK
void RemoveTail(LinkedList& list) {
	if (IsEmpty(list)) {
		return;
	}
	Node* p = list.pHead;
	Node* q = nullptr;
	while (p != list.pTail) {
		q = p;
		p = p->pNext;
	}
	if (q == nullptr) {
		RemoveHead(list);
	}
	else {
		q->pNext = nullptr;
		delete p;
		list.pTail = q;
	}
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

// 22.Hàm hủy 1 node đúng sau 1 node cho trước trong DSLK
void RemoveAfter(LinkedList& list, Node* q) {
	if (q == nullptr || q == list.pTail) {
		return;
	}
	Node* p = q->pNext;
	q->pNext = p->pNext;
	delete p;
	if (q->pNext == nullptr) {
		list.pTail = q;
	}
}

Data RemoveDataAfter(LinkedList& list, Node* q) {
	if (q == nullptr || q == list.pTail) {
		return { 0 };
	}
	Node* p = q->pNext;
	q->pNext = p->pNext;
	Data info = { p->info };
	delete p;
	if (q->pNext == nullptr) {
		list.pTail = q;
	}
	return info;
}

// 23.Hàm hủy 1 node có dữ liệu đứng trước 1 node trong DSLK 
bool RemoveBefore(LinkedList& list, Data info) {
	Node* q = GetNodePointer(list, info);
	if (q == nullptr || q == list.pHead) {
		return false;
	}
	Node* p = GetPreviousNodePointer(list, q);
	if (p == nullptr) {
		return false;
	}
	if (p == list.pHead) {
		RemoveHead(list);
	}
	else {
		RemoveAfter(list, p);
	}
	return true;
}

// 24.Hàm hủy toàn bộ DSLK
void RemoveList(LinkedList& list) {
	while (!IsEmpty(list)) {
		RemoveHead(list);
	}
}

// 25.Hàm xóa tất cả có node có khóa k cho trước
int RemoveKeys(LinkedList& l, Data k) {
	Node* p = l.pHead;
	Node* q = nullptr;
	int count = 0;
	while (p != nullptr) {
		if (p->info.x == k.x) {
			count++;
			if (q == nullptr) {
				RemoveHead(l);
				p = l.pHead;
			}
			else {
				RemoveAfter(l, q);
				p = q->pNext;
			}
		}
		else {
			q = p;
			p = p->pNext;
		}
	}
	return count;
}

// 26.Hàm sắp xếp DSLK theo thuật toán hoán đổi trực tiếp
void SortList(LinkedList& l) {
	Node* p = l.pHead;
	while (p != nullptr) {
		Node* q = p->pNext;
		while (q != nullptr) {
			if (CompareData(p->info, q->info) > 0) {
				Data temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
			q = q->pNext;
		}
		p = p->pNext;
	}
}

// 27.Hàm gộp 2 DSLK cho trước thành 1 DSLK đảm bảo thứ tự tăng dần
LinkedList CombineList(const LinkedList& l1, const LinkedList& l2) {
	LinkedList l;
	Init(l);
	Node* p = l1.pHead;
	while (p != nullptr) {
		AddAscendingList(l, p->info);
		p = p->pNext;
	}
	p = l2.pHead;
	while (p != nullptr) {
		AddAscendingList(l, p->info);
		p = p->pNext;
	}
	return l;
}

// 28.Hàm đảo DSLK
void ReverseList(LinkedList& l) {
	Node* p = l.pHead;
	Node* q = nullptr;
	while (p != nullptr) {
		Node* r = p->pNext;
		p->pNext = q;
		q = p;
		p = r;
	}
	l.pTail = l.pHead;
	l.pHead = q;
}

// 29.Hàm hoán vị 2 node trên DSLK
void HoanViNode(LinkedList& l, Node* p, Node* q) {
	if (p == q) {
		return;
	}
	if (p == nullptr || q == nullptr) {
		return;
	}
	if (p->pNext == q) {
		Node* r = GetPreviousNodePointer(l, p);
		if (r == nullptr) {
			l.pHead = q;
		}
		else {
			r->pNext = q;
		}
		p->pNext = q->pNext;
		q->pNext = p;
		if (p->pNext == nullptr) {
			l.pTail = p;
		}
	}
	else if (q->pNext == p) {
		Node* r = GetPreviousNodePointer(l, q);
		if (r == nullptr) {
			l.pHead = p;
		}
		else {
			r->pNext = p;
		}
		q->pNext = p->pNext;
		p->pNext = q;
		if (q->pNext == nullptr) {
			l.pTail = q;
		}
	}
	else {
		Node* r = GetPreviousNodePointer(l, p);
		Node* s = GetPreviousNodePointer(l, q);
		if (r == nullptr) {
			l.pHead = q;
		}
		else {
			r->pNext = q;
		}
		if (s == nullptr) {
			l.pHead = p;
		}
		else {
			s->pNext = p;
		}
		Node* temp = p->pNext;
		p->pNext = q->pNext;
		q->pNext = temp;
	}
}
