#include <iostream>
using namespace std;

long long dp[100][21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    cin >> N >> num;
    dp[0][num] = 1;
    for (int i = 1; i < N - 1; i++) {
        cin >> num;
        for (int j = 0; j <= 20; j++) {
            if (dp[i - 1][j] > 0) {
                if (j - num >= 0) dp[i][j - num] += dp[i - 1][j];
                if (j + num <= 20) dp[i][j + num] += dp[i - 1][j];
            }
        }
    }
    cin >> num;
    cout << dp[N - 2][num];

    return 0;
}