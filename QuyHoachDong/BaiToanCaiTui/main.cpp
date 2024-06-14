#include<iostream>
#include<vector>

using namespace std;

// Một cái túi có trọng lượng tối đa là S. Lựa chọn N đồ vật mỗi đồ vật có trọng lượng w[i] và giá trị v[i].
// Xác định tổng giá trị lớn nhất của các đồ vật sao cho trọng lượngS không vượt quá S.


int main() {
    int n = 0;
    int S = 0;
    cin >> n >> S;
    


    vector<int> w(n + 1);
    

    vector<int> v(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }


    vector<vector<int>> dp(n + 1, vector<int>(S + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= S; j++) {

            // Khong lua chon do vat thu i bo vao tui
            dp[i][j] = dp[i - 1][j];

            // Lua chon do vat thu i bo vao tui
            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= S; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Res: " << dp[n][S];

    return 0;
}