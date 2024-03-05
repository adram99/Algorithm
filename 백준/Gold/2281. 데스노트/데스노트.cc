#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dp[1001];
int input[1001];

void reset(int size, int value) {
    for (int i = 0; i <= size; i++) dp[i] = value;
}

int DP(int step) {
    if (dp[step] < 987654321) return dp[step];

    int remain = m - input[step];
    for (int i = step + 1; i <= n && remain >= 0; i++) {
        if (i == n) {
            dp[step] = 0;
            break;
        }
        dp[step] = min(dp[step], remain * remain + DP(i));
        remain -= input[i] + 1;
    }
    return dp[step];
}

int main()
{
    cin >> n >> m;
    reset(n, 987654321);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    dp[n - 1] = 0;
    cout << DP(0);

    return 0;
}