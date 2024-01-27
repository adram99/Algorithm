#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[10001];
    int n, k, coin;
    cin >> n >> k;
    dp[0] = 0;      // 0원을 만들기 위한 최소 동전 개수는 0개
    for (int i = 1; i <= k; i++) dp[i] = 10001;  // 최소값 저장을 위해 초기값은 최대값
    for (int i = 0; i < n; i++) {
        cin >> coin;
        for (int j = coin; j <= k; j++) {
            if(dp[j] > dp[j - coin] + 1) dp[j] = dp[j - coin] + 1;  // 점화식
        }
    }
    if (dp[k] == 10001) cout << -1;
    else cout << dp[k];

    return 0;
}
