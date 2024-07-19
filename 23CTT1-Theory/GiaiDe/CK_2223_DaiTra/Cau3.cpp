#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node * createNode(int val){
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

Node * addNode(Node *h, int val){
    Node *newNode = createNode(val);
    if(h == nullptr){
        return newNode;
    }

    Node *current = h;
    while(current->next != nullptr){
        current = current->next;
    }

    current->next = newNode;
    return h;
}



bool isPrime(int n){
    if(n < 2){
        return false;
    }

    for(int i=2;i<n;i++){
        if(n%i == 0){
            return false;
        }
    }

    return true;
}

int countPrime(Node *h){
    if(h==nullptr){
        return 0;
    }

    int countCurrent = 0;
    if(isPrime(h->data)){
        countCurrent = 1;
    }

    int count = countPrime(h->next);
    return count + countCurrent;
}

int main(){


    Node *head = nullptr;
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 4);
    head = addNode(head, 5);
    head = addNode(head, 6);
    head = addNode(head, 7);
    head = addNode(head, 8);
    head = addNode(head, 9);
    head = addNode(head, 10);


    // Node *temp = head;
    //     while(temp != nullptr){
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }

    cout << countPrime(head) << endl;


    return 0;
}