#include<iostream>
#include"LinkedList.h"

using namespace std;




int main() {

	LinkedList l;
	init(l);

	LinkedList l1;
	init(l1);

	LinkedList l2;
	init(l2);

	addTail(l, 1);
	addTail(l, 2);
	addTail(l, 3);
	addTail(l, 4);
	addTail(l, 5);

	chiaDSLK(l, l1, l2);
	cout << "1a\n";
	cout << "Danh sach ban dau:\n";
	printList(l);
	cout << "\nDanh sach 1:\n";
	printList(l1);
	cout << "\nDanh sach 2:\n";
	printList(l2);

	//// 1b

	cout << "\n\n1b";
	init(l1);
	init(l2);
	int n = 0;
	cout << "\nNhap gia tri node lam moc: ";
	cin >> n;

	Node* p = createNode(n);
	chiaDSLKTheoNode(l, l1, l2, p);



	cout << "Danh sach ban dau:\n";
	printList(l);
	cout << "\nDanh sach 1:\n";
	printList(l1);
	cout << "\nDanh sach 2:\n";
	printList(l2);
	

	

	return 0;
}