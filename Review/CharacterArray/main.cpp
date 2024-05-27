#include<iostream>

using namespace std;

void DeleteSpace(char* str) {
	char *result = new char[strlen(str)+1];
	int i = 0;
	int j = 0;
	while (str[i] != '\0') {
		if (str[i] != ' ') {
			result[j++] = str[i];
		}
		i++;
	}
	result[j] = '\0';
	cout << result << endl;
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

int main() {

	char str[] = "A * B + C * ((D - E) + F) / G          ";
	DeleteSpace(str);

	return 0;
}