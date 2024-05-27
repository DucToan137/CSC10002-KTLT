#include<iostream>
#include"Stack.h"

using namespace std;

// Kiểm tra phải toán hạng không
bool isOperand(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}
// Kiểm tra độ ưu tiên
int precedence(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}
	if (c == '*' || c == '/') {
		return 2;
	}
	if (c == '^') {
		return 3;
	}
	return 0;
}

// Kiểm tra phải toán tử không
bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

char* InfixToPosfix(char* infix) {
	char* postfix = new char[100];
	char* result = new char[100];
	Stack s;
	Init(s);

	int i = 0;
	int j = 0;

	while (infix[i] != '\0') {
		if (isOperand(infix[i])) {
			postfix[j++] = infix[i];
		}
		else if (infix[i] == '(') {
			Data d;
			d.x = '(';
			Push(s, d);
		}
		else if (infix[i] == ')') {
			while (!IsEmpty(s) && s.l.pHead->info.x != '(') {
				Data d = Pop(s);
				postfix[j++] = d.x;
			}
			if (!IsEmpty(s)) {
				Pop(s);
			}
		}
		else if (isOperator(infix[i])) {
			while (!IsEmpty(s) && precedence(infix[i]) <= precedence(s.l.pHead->info.x)) {
				Data d = Pop(s);
				postfix[j++] = d.x;
			}
			Data d;
			d.x = infix[i];
			Push(s, d);
		}
		i++;
	}
	while (!IsEmpty(s)) {
		Data d = Pop(s);
		postfix[j++] = d.x;
	}
	postfix[j] = '\0';

	strcpy_s(result, 100, postfix);
	return result;
}

char* PostfixToInfix(char* postfix) {
	char* infix = new char[100];
	Stack s;
	Init(s);

	int i = 0;
	int j = 0;

	while (postfix[i] != '\0') {
		if (isOperand(postfix[i])) {
			Data d;
			d.x = postfix[i];
			Push(s, d);
		}
		else if (isOperator(postfix[i])) {
			Data d;
			d.x = postfix[i];
			Node* p = CreateNode(d);
			Node* op2 = p;
			op2 = s.l.pHead;
			Pop(s);
			Node* op1 = p;
			op1 = s.l.pHead;
			Pop(s);
			d.x = '(';
			Push(s, d);
			Node* p1 = CreateNode(op1->info);
			Node* p2 = CreateNode(d);
			Node* p3 = CreateNode(op2->info);
			p2->pNext = p1;
			p1->pNext = p3;
			s.l.pHead = p2;
		}
		i++;
	}
	Node* p = s.l.pHead;
	while (p != NULL) {
		infix[j++] = p->info.x;
		p = p->pNext;
	}
	infix[j] = '\0';
	return infix;
}


int main() {

	//char infix[] = "A     * B + C * ((D - E) + F)/G"; // ==> AB*CDE-F+*G/+
	char infix[] = "12 + 2 * (3 - 4)";
	char result[] = "AB*CDE-F+*G/+";
	//char* infix = new char[100];

	char* postfix = new char[100];
	cout << InfixToPosfix(infix) << endl;
	//cout << PostfixToInfix(result) << endl;

	return 0;
}