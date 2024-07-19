#include<iostream>
#include<vector>
using namespace std;


int main() {

	int n;
	int S;

	cin >> n;
	cin >> S;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<bool>dp(S + 1, false);

	dp[0] = true;

	for(int i = 0; i < n; i++) {
		for (int j = S; j >= a[i]; j--) {
			if (dp[j - a[i]] == true) {
				dp[j] = true;
			}
		}
	}

	if(dp[S]==true) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}