#include<iostream>
#include"LinkedList.h"



struct Stack{
	LinkedList l;
};


void Init(Stack& s);
Data Pop(Stack& s);
bool Push(Stack& s, Data info);
void PrintStack(Stack s);
void Clear(Stack& s);