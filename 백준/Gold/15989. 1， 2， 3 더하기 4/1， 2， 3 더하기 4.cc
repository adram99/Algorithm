#include <iostream>
using namespace std;

int dp[10001];  // ex) dp[5]는 5를 1,2,3으로 만드는 방법 수

void dpSet() {
    dp[0] = 1;
    for (int i = 1; i <= 3; i++) {          // 1로만 만드는 방법, 2를 추가한 방법, 3을 추가한 방법을 더해가면서 계산
        for (int j = i; j <= 10000; j++) {
            dp[j] = dp[j - i] + dp[j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, input;
    cin >> T;
    dpSet();
    for (int i = 0; i < T; i++) {
        cin >> input;
        cout << dp[input] << "\n";
    }

    return 0;
}
