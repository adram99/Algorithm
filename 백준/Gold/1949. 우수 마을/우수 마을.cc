#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int dp[10001][2];   // dp[n][1] : n마을이 우수마을일 때 최댓값, dp[n][0] : 우수마을이 아닐 때 최댓값
int people[10001];
int visited[10001];
vector<int> road[10001];

void calculate(int town) {
    visited[town] = 1;

    dp[town][0] = 0;
    dp[town][1] = people[town];

    for (int next : road[town]) {
        if (!visited[next]) {
            calculate(next);
            dp[town][0] += max(dp[next][0], dp[next][1]);  // 우수마을이 아니면 다음 마을이 우수마을 이거나 우수마을이 아님
            dp[town][1] += dp[next][0];                    // 우수마을이라면 다음마을은 반드시 우수마을이 아님
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> people[i];
    int a, b;
    for (int i = 1; i <= N - 1; i++)
    {
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }

    calculate(1);
    cout << max(dp[1][0], dp[1][1]);

    return 0;
}
