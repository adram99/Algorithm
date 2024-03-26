#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int novel;
int prefixsum[501];
int dp[501][501];

void calculate() {
    for (int i = 1; i <= novel; i++)
    {
        for (int j = 1; j <= novel - i; j++)
        {
            dp[j][i + j] = 987654321;
            for (int k = j; k < i + j; k++)
            {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + prefixsum[i + j] - prefixsum[j - 1]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase, file;
    cin >> testcase;
    while (testcase > 0) {
        cin >> novel;
        for (int i = 1; i <= novel; i++) {
            cin >> file;
            prefixsum[i] = prefixsum[i - 1] + file;
        }
        calculate();
        cout << dp[1][novel] << "\n";
        testcase--;
    }

    return 0;
}