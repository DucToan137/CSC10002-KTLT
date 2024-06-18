#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.length();
	s = "x" + s;

	// F[i][j] = F[i+1][j-1] && (s[i] == s[j])
	vector<vector<bool>> F(n + 1, vector<bool>(n + 1, false));

	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		cout << F[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	
	for(int i = 1; i <= n; i++) { // Xau con co do dai la 1
		F[i][i] = true;
	}

	int res = 1;

	for (int len = 2; len <= n; len++) {
		// Xet cac xau con co do dai tu 2 den n
		for (int i = 1; i <= n - len + 1; i++) {
			int j = i + len - 1;
			// F[i][j] : co do dai la len

			if (len == 2 && s[i] == s[j]) {
				F[i][j] = true;
			}
			else
			{
				F[i][j] = F[i + 1][j - 1] && (s[i] == s[j]);
			}
			if(F[i][j]) {
				res = max(res, len);
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << F[i][j] << " ";
		}
		cout << endl;
	}

	cout << res << "\n";
	

	return 0;
}