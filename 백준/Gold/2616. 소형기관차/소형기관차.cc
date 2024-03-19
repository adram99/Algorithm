#include <iostream>
#include <algorithm>
using namespace std;

int dp[4][50001]; // ex) dp[i][j]는 i번째 소형 차량이 j번째 객차까지 고려했을때 최대 승객의 수를 의미
int sum[50001];   // ex) sum[i]는 i번째 차량까지의 손님의 합을 의미

void DP(int t, int m) {
    for (int i = 1; i <= 3; i++) {
        for (int j = i * m; j <= t; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + sum[j] - sum[j - m]);  // 누적합에서 누작합을 빼면 해당 범위의 합을 쉽게 구할 수 있음
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
        sum[i] = sum[i - 1] + people;    // 입력 받으면서 누적합 기록
    }
    cin >> mini;

    DP(train, mini);
    cout << dp[3][train];

    return 0;
}
