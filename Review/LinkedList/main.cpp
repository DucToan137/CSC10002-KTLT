#include<iostream>
#include"LinkedList.h"

using namespace std;

int main() {

    LinkedList list;
    Init(list);

    Data data1 = { 1 };
    Data data2 = { 2 };
    Data data3 = { 3 };
    Data data4 = { 4 };

    Node* node1 = CreateNode(data1);
    Node* node2 = CreateNode(data2);
    Node* node3 = CreateNode(data3);
    Node* node4 = CreateNode(data4);

    // Test AddHead
    cout << "Them dau\n";
    AddHead(list, node1);
    PrintList(list); // Expected: 1 -> NULL

    // Test AddTail
    cout << "Them cuoi\n";
    AddTail(list, node2);
    PrintList(list); // Expected: 1 -> 2 -> NULL

    // Test AddAfter
    cout << "Them sau\n";
    AddAfter(list, node1, node3);
    PrintList(list); // Expected: 1 -> 3 -> 2 -> NULL

    // Test AddBefore
    cout <<"Them truoc\n";
    AddBefore(list, node3, node4);
    PrintList(list); // Expected: 1 -> 4 -> 3 -> 2 -> NULL

    // Test RemoveHead
    cout << "Xoa dau\n";
    RemoveHead(list);
    PrintList(list); // Expected: 4 -> 3 -> 2 -> NULL

    // Test RemoveTail
    cout << "Xoa cuoi\n";
    RemoveTail(list);
    PrintList(list); // Expected: 4 -> 3 -> NULL

    // Test HoanViNode (swap node 4 and node 3)
    cout << "Hoan vi node\n";
    HoanViNode(list, node4, node3);
    PrintList(list); // Expected: 3 -> 4 -> NULL

    // Test AddAscendingList
    cout << "Them vao DS da sap xep\n";
    Data data5 = { 5 };
    Data data6 = { 0 };
    AddAscendingList(list, data5);
    AddAscendingList(list, data6);
    PrintList(list); // Expected: 0 -> 3 -> 4 -> 5 -> NULL

    // Test SortList
    cout << "Sap xep\n";
    SortList(list);
    PrintList(list); // Expected: 0 -> 3 -> 4 -> 5 -> NULL (already sorted)

    // Test ReverseList
    cout << "Dao nguoc\n";
    ReverseList(list);
    PrintList(list); // Expected: 5 -> 4 -> 3 -> 0 -> NULL

    // Test CombineList
    cout << "Ghep 2 DS\n";
    LinkedList list2;
    Init(list2);
    AddHead(list2, CreateNode({ 6 }));
    AddTail(list2, CreateNode({ 7 }));
    LinkedList combinedList = CombineList(list, list2);
    PrintList(combinedList); // Expected: 5 -> 4 -> 3 -> 0 -> 6 -> 7 -> NULL

    // Clear lists
    RemoveList(list);
    RemoveList(list2);
    RemoveList(combinedList);
	

	return 0;
}