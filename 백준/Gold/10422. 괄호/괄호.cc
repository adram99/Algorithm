#include<iostream>
using namespace std;

long long dp[5001];  // ex) dp[i]는 길이가 i인 문자열에서 올바른 괄호의 경우의 수

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
        if (L % 2 != 0) cout << 0 << '\n';  // 길이가 짝수면 올바른 괄호 문자열을 만들 수 없음
        else cout << recur(L) << '\n';
    }

    return 0;
}
