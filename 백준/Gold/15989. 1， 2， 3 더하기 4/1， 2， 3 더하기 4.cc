#include <iostream>
using namespace std;

int dp[10001];

void dpSet() {
    dp[0] = 1;
    for (int i = 1; i <= 3; i++) {
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