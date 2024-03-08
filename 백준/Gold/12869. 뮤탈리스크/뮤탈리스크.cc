#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int scv[3];
int dp[61][61][61];
int myu[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3 ,9}};

int atack(int s, int c, int v)
{
    if (s == 0 && c == 0 && v == 0) return 0;
    if (dp[s][c][v] != -1) return dp[s][c][v];

    dp[s][c][v] = 987654321;
    for(int i = 0; i < 6; i++)
        dp[s][c][v] = min(dp[s][c][v], atack(max(0, s - myu[i][0]), max(0, c - myu[i][1]), max(0, v - myu[i][2])) + 1);

    return dp[s][c][v];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> scv[i];
    memset(dp, -1, sizeof(dp));
    cout << atack(scv[0], scv[1], scv[2]);
    return 0;
}