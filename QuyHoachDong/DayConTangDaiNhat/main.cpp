#include<iostream>
#include<vector>

using namespace std;

#define MAX 1000
#define inf 1000000000

void input(int& n, int a[MAX + 3]) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

vector<int> DayConTangDaiNhat(int a[MAX+3], int n) {
	vector<int> res;

	int dp[MAX + 3];
	int vet[MAX + 3];


	a[0] = -inf;
	a[n+1] = inf;

	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; i <= n + 1; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] < a[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				vet[i] = j;
			}
		}
	}

	cout << dp[n + 1] - 2 << endl;

	for (int i = n + 1; i > 0; i = vet[i]) {
		res.push_back(a[i]);
	}

	res.erase(res.begin());

	reverse(res.begin(), res.end());

	return res;
}

int main() {


	
	/*int a[12] = {4, 1, 3, 7, 8, 5, 6, 2, 7, 4, 10, 6};

	vector<int> res = DayConTangDaiNhat(a,12);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}*/



	// Tìm độ dài dãy con tăng dài nhất
	// O(n^2)
	// L[i] la do dai day con tang dai nhat ket thuc tai chi so i
	// L[i] = max(L[i], L[j] + 1) voi j < i va a[j] < a[i]
	// L[0] = 1

	int n;
	cin >> n;

	vector<int> a(n);

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> L(n, 1);

	for (int i = 0; i < n; i++) {
		// L[i] : L[j]
		// duyet qua tung phan tu truoc chi so i
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				L[i] = max(L[i], L[j] + 1);
			}
		}
	}

	cout << *max_element(L.begin(), L.end()) << endl;

	return 0;
}