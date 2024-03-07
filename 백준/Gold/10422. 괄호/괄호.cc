#include<iostream>
using namespace std;

long long dp[5001];

long long recur(int len) {
    if (len == 0)
        return 1;

    if (dp[len] > 0) return dp[len];

    for (int i = 2; i <= len; i += 2)
    {
        dp[len] += (recur(i - 2) * recur(len - i));
        dp[len] %= 1000000007;
    }

    return dp[len];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, L;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> L;
        if (L % 2 != 0) cout << 0 << '\n';
        else cout << recur(L) << '\n';
    }

    return 0;
}