#include<iostream>
#include<vector>

using namespace std;

// void print(int price[], int n, int m){
//     vector<int> w(n+1);
//     vector<int> v(n+1);
//     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
//     for(int i = 1;i<=n;i++){
//         for(int j = 1; j <= m;j++){
//             dp[i][j] = dp[i-1][j];
//             if(j>=w[i]){
//                 dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
//             }
//         }
//     }
// }

const int max_n = 100;
const int max_m = 100;

void print(int price[], int n, int m){
    int dp[max_n][max_m];

    for(int i = 0; i<= n; i++){
        for(int j = 0; j<=m;j++){
            if(i==0 || j ==0){
                dp[i][j] = 0;
                continue;
            }

            int first = dp[i-1][j];

            int currentPriceIdx = i + 1;
            int second = 0;
            if(j - price[currentPriceIdx] >= 0){
                second = dp[i-1][j - price[currentPriceIdx]] + price[currentPriceIdx];
            }

            dp[i][j] = max(first, second);
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[n][m] << endl;
}

void print2(int price[], int n, int m) {
    // Muốn thử tất cả trường hợp có hoặc không có món hàng
    // 000000000
    // 111111111
    int all = 1;
    for (int i = 0; i < n; i++) {
        all *= 2;
    }
    cout << all << "\n";
    vector<vector<int>> solutions;
    int maxSum = 0;
    // 00000100
    // 00000001
    for (int i = 0; i < all; i++) {
        int sum = 0;
        vector<int> solution;
        for (int j = 0; j < n; j++) {
            bool isOn = (1 << j) & i;
            if (isOn) {
                sum += price[j];
                solution.push_back(j);
            }
            // cout << i << " " << j << "\n";
            // cout <<  isOn << " ";
        }
        // cout << "\n";
        if (sum <= m) {
            if (sum > maxSum) {
                maxSum = sum;
                solutions.clear();
                solutions.push_back(solution);
                // cout << "pushBack1";
            }
            else if (sum == maxSum) {
                if (!solutions.empty() && solutions.back().size() < solution.size()) {
                    solutions.clear();
                }
                if (solutions.empty() || solutions.back().size() == solution.size()) {
                    solutions.push_back(solution);
                }
                // cout << "pushBack2";
            }
        }
    }
    // cout << "sdfsdfsdf";
    for (int i = 0; i < solutions.size(); i++) {
        for (int j = 0; j < solutions[i].size(); j++) {
            cout << solutions[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){

    int price[] = {5,7,1,8,1,2};
    int n = 6;
    int m = 10;
    //cout << "hello world";
    print(price, n, m);
    print2(price, n, m);
    return 0;
}