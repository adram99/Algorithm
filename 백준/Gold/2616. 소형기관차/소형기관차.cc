#include <iostream>
#include <algorithm>
using namespace std;

int dp[4][50001]; 
int sum[50001];   // ex) sum[i]는 i번째 차량까지의 손님의 합

void DP(int t, int m) {
    for (int i = 1; i <= 3; i++) {
        for (int j = i * m; j <= t; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + sum[j] - sum[j - m]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int train, mini, people;
    cin >> train;
    for (int i = 1; i <= train; i++) {
        cin >> people;
        sum[i] = sum[i - 1] + people;
    }
    cin >> mini;

    DP(train, mini);
    cout << dp[3][train];

    return 0;
}
