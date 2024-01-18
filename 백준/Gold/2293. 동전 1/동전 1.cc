#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[10001];
    for (int i = 0; i < 10001; i++) dp[i] = 0;
    int n, k, coin;
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> coin;
        for (int j = coin; j <= k; j++) {
            dp[j] += dp[j - coin];
        }
    }
    cout << dp[k];
    return 0;
}