#include <iostream>
#include <cstring>
using namespace std;

long long dp[51][51][51][51];
int mod = 1000000007;

long long calculate(int s, int a, int b, int c) {
    if (s == 0) {  // 곡 분배를 다 했을 때
        if (a == 0 && b == 0 && c == 0) return 1; // a, b, c가 모두 분배됨
        else return 0;
    }

    long long result = dp[s][a][b][c];
    if (result != -1) return result;
    result = 0;

    // 7가지 경우가 전부
    result += calculate(s - 1, a - 1, b, c);
    result += calculate(s - 1, a, b - 1, c);
    result += calculate(s - 1, a, b, c - 1);
    result += calculate(s - 1, a - 1, b - 1, c);
    result += calculate(s - 1, a - 1, b, c - 1);
    result += calculate(s - 1, a, b - 1, c - 1);
    result += calculate(s - 1, a - 1, b - 1, c - 1);

    dp[s][a][b][c] = result % mod; // 메모이제이션

    return result % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, a, b, c;
    cin >> s >> a >> b >> c;
    if (a + b + c < s || a > s || b > s || c > s) cout << 0;  // 곡 분배를 다 못하거나 곡이 모자라는 경우
    else {
        memset(dp, -1, sizeof(dp));                           // dp 계산 중 0이 나올 수 있음을 감안하여 초가값을 -1로 초기화
        cout << calculate(s, a, b, c);
    }

    return 0;
}
