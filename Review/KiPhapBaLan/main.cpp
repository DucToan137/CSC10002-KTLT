#include<iostream>
#include"Stack.h"
#include<string.h>

#pragma warning(disable : 4996)

using namespace std;


bool isOperand(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

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

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

char *Reverse(char *str) {
	char *result = new char[100];
	Stack s;
	Init(s);

	int i = 0;
	int j = 0;
	while (str[i] != '\0') {
		Data d;
		d.x = str[i];
		Push(s, d);
		i++;
	}
	while (!IsEmpty(s)) {
		Data d = Pop(s);
		result[j++] = d.x;
	}
	result[j] = '\0';
	return result;
}

char* reverse(const char* str) {
	int len = strlen(str);
	char* result = new char[len + 1];
	for (int i = 0; i < len; i++) {
		result[i] = str[len - 1 - i];
	}
	result[len] = '\0';
	return result;
}

char* InfixToPrefix(char* infix) {
	char* prefix = new char[100];
	char* tmp = reverse(infix);
	Stack s;
	Init(s);

	int i = 0;
	int j = 0;

	while (tmp[i] != '\0')
	{
		if (isOperand(tmp[i])) {
			prefix[j++] = tmp[i];
		}
		else if (tmp[i] == ')') {
			Data val;
			val.x = ')';
			Push(s, val);
		}
		else if (tmp[i] == '(') {
			while (!IsEmpty(s) && s.l.pHead->info.x != ')')
			{
				Data val = Pop(s);
				prefix[j++] = val.x;
			}
			if (!IsEmpty(s))
			{
				Pop(s);
			}
		}
		else if (isOperator(tmp[i])) {
			while (!IsEmpty(s) && precedence(tmp[i]) <= precedence(s.l.pHead->info.x)) {
				Data val = Pop(s);
				prefix[j++] = val.x;
			}
			Data val;
			val.x = tmp[i];
			Push(s, val);
		}
		i++;
	}
	while (!IsEmpty(s)) {
		Data d = Pop(s);
		prefix[j++] = d.x;
	}
	prefix[j] = '\0';
	char *result = Reverse(prefix);

	delete[] tmp;
	delete[] prefix;

	return result;
}



int main() {
	
	//char infix[] = "A  *B   +   C*( (D-E)+F)/G"; // ==> +*AB/*C+-DEFG
	char infix[] = "1 + 2 * (3 - 4)";
	//char* infix = new char[100];
	char* result = new char[100];
	char* postfix = new char[100];

	//cin >> infix;


	cout << InfixToPrefix(infix);




	

	return 0;
}