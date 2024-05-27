#include<iostream>

using namespace std;

void MoveDisk(int n, int src, int des) {
	cout << "Di chuyen dia " << n << " tu coc " << src << " sang coc " << des << "\n";
}

void Tower(int n, int col1, int col2, int col3)
{
	if (n > 0)
	{
		Tower(n-1, col1, col3, col2);
		MoveDisk(n,col1, col3);
		Tower(n-1, col2, col1, col3);
	}
}

int main() {
	cout << "De quy thap Ha Noi\n";
	cout << "Nhap so luong dia: ";
	
	int n;
	cin >> n;

	Tower(n, 1, 2, 3);

	return 0;
}