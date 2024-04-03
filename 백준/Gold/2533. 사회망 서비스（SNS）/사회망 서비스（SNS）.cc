#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int dp[1000001][2];
int visited[1000001];
vector<int> edge[1000000];

void calculate(int x) {
    visited[x] = 1;
    dp[x][0] = 1;
    for (int i = 0; i < edge[x].size(); i++) {
        int child = edge[x][i];
        if (visited[child]) continue;
        calculate(child);
        dp[x][1] += dp[child][0];
        dp[x][0] += min(dp[child][1], dp[child][0]);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int u, v;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    calculate(1);

    cout << min(dp[1][0], dp[1][1]);
    return 0;
}