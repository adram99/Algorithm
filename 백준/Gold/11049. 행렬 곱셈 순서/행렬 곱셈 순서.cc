#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> input_mat[501];
int dp[501][501];
pair<int, int> dp_mat[501][501];

int sum(int dx, int mid, int dy) {
    return dp_mat[dx][mid].first * dp_mat[dx][mid].second * dp_mat[mid + 1][dy].second;
}

void calculate(int n) {
    for (int i = 1; i < n; i++) {
        for (int x = 1; x + i <= n; x++) {
            int y = x + i;
            dp[x][y] = 987654321;
            for (int mid = x; mid < y; mid++) {
                dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum(x, mid, y));
            }
            dp_mat[x][y].first = input_mat[x].first;
            dp_mat[x][y].second = input_mat[y].second;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> input_mat[i].first >> input_mat[i].second;
        dp_mat[i][i] = input_mat[i];
    }
    calculate(N);

    cout << dp[1][N];
    return 0;
}