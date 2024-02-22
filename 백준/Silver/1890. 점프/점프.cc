#include <iostream>
using namespace std;

long dp[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, jump;
    cin >> N;
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> jump;
            if (dp[i][j] == 0 || jump == 0) continue;

            if (i + jump < N) dp[i + jump][j] += dp[i][j];
            if (j + jump < N) dp[i][j + jump] += dp[i][j];
        }
    }

    cout << dp[N - 1][N - 1];

    return 0;
}