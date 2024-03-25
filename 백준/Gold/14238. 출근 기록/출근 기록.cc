#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define MAX 51
using namespace std;
 
string str;
int dp[MAX][MAX][MAX][3][3];
int cnt[3];
int N;
 
int dfs(int a, int b, int c, int pre1, int pre2) {
    if (a + b + c == N) return 1;
    int &ret = dp[a][b][c][pre1][pre2];
    if (ret != -1) return ret;
    ret = 0;
 
    if (a < cnt[0]) {
        ret = dfs(a + 1, b, c, 0, pre1);
        if (ret == 1) {
            cout << 'A';
            return ret;
        }
    }
 
    if (b < cnt[1]) {
        if (pre1 != 1) {
            ret = dfs(a, b + 1, c, 1, pre1);
            if (ret == 1) {
                cout << 'B';
                return ret;
            }
        }
    }
 
    if (c < cnt[2]) {
        if (pre1 != 2 && pre2 != 2) {
            ret = dfs(a, b, c + 1, 2, pre1);
            if (ret == 1) {
                cout << 'C';
                return ret;
            }
        }
    }
 
    return ret;
}
 
void func() {
    memset(dp, -1, sizeof(dp));
    if (!dfs(0, 0, 0, 0, 0)) cout << "-1\n";
}
 
void init() {
    N = str.size();
    for (int i = 0; i < N; i++) {
        cnt[str[i] - 'A']++;
    }
}
 
void input() {
    cin >> str;
    init();
}
 
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
 
    input();
    func();
 
    return 0;
}