#include <iostream>
#include <algorithm>
using namespace std;

int dp[1500001];  // ex) dp[3]은 3일까지 얻을 수 있는 최대 이익

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int days, profit, res = 0;   // 걸리는 시간, 이익, 결괏값(최대 이익)
    int cur_max = 0;
    for (int i = 0; i < N; i++) {
        cin >> days >> profit;
        cur_max = max(cur_max, dp[i]);
        if (i + days <= N) {
            dp[i + days] = max(dp[i + days], cur_max + profit);
            res = max(res, dp[i + days]);
        }
    }
    cout << res;
    return 0;
}
