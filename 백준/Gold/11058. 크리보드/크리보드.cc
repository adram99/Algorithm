#include <iostream>
#include <algorithm>
using namespace std;

long long dp[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    if (N <= 6) cout << N;
    else {
        for (int i = 0; i <= 6; i++) dp[i] = i;
        for (int i = 7; i <= N; i++) {
            for (int j = 3; j < i; j++) {
                dp[i] = max(dp[i], dp[i - j] * (j - 1));
            }
        }
        cout << dp[N];
    }
    return 0;
}