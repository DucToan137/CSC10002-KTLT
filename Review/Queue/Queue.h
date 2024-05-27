#include"LinkedList.h"

struct Queue {
	LinkedList l;
};

void Init(Queue& q);
bool IsEmpty(Queue q);
Data DeQueue(Queue& q);
bool EnQueue(Queue& q, Data info);
void PrintQueue(Queue q);
void Clear(Queue& q);