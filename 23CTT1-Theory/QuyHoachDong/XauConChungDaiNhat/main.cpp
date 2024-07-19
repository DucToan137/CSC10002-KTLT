#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string X;
	string Y;

	getline(cin, X);
	getline(cin, Y);

	// neu muon xet tu X[1] -> X[n] va Y[1] -> Y[m]
	// thi can cong vao dau xau X, Y 1 ki tu
	// X = " " + X;
	// Y = " " + Y;

	int n = X.size();
	int m = Y.size();

	vector<vector<int>> F(n + 1, vector<int>(m + 1, 0));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				F[i][j] = 0;
			}
			else
			{
				if (X[i - 1] == Y[j - 1]) {
					F[i][j] = F[i - 1][j - 1] + 1;
				}
				else {
					F[i][j] = max(F[i][j - 1], F[i - 1][j]);
				}
			}
		}
	}

	for(int i=0;i<= n; i++) {
		for(int j = 0; j <= m; j++) {
			cout << F[i][j] << " ";
		}
		cout << endl;
	}

	cout << F[n][m] << endl;

	return 0;
}