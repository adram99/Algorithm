#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[10001];  // 주어진 동전들로 n원을 만드는 경우의 수
    for (int i = 0; i < 10001; i++) dp[i] = 0;
    int n, k, coin;
    cin >> n >> k;
    dp[0] = 1;      // 주어진 동전들로 0원을 만드는 경우의 수는 1가지
    for (int i = 0; i < n; i++) {
        cin >> coin;
        for (int j = coin; j <= k; j++) {  // 새로 입력된 동전 값부터 k원까지 경우의 수 업데이트
            dp[j] += dp[j - coin];         // 점화식
        }
    }
    cout << dp[k];
    return 0;
}
