#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int min_cnt = 987654321;
char board[21][21];

int next_x[4] = { 1, 0, -1, 0 };
int next_y[4] = { 0, 1, 0, -1 };

int out_check(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= M) return 1;
    else return 0;
}

void dfs(int y1, int x1, int y2, int x2, int cnt) {
    if (cnt > 10) return;
    if (cnt >= min_cnt) return;

    if (out_check(y1, x1) && out_check(y2, x2)) return;

    if (out_check(y1, x1) && !out_check(y2, x2)) {
        min_cnt = min(min_cnt, cnt);
        return;
    }
    if (!out_check(y1, x1) && out_check(y2, x2)) {
        min_cnt = min(min_cnt, cnt);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny1 = y1 + next_y[i];
        int nx1 = x1 + next_x[i];
        int ny2 = y2 + next_y[i];
        int nx2 = x2 + next_x[i];

        if (board[ny1][nx1] == '#') {
            ny1 = y1;
            nx1 = x1;
        }
        if (board[ny2][nx2] == '#') {
            ny2 = y2;
            nx2 = x2;
        }
        dfs(ny1, nx1, ny2, nx2, cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int o1x, o1y, o2x, o2y;
    int coin_check = 0;
    string input;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            board[i][j] = input[j];
            if (input[j] == 'o' && coin_check == 0) {
                coin_check++;
                o1y = i;
                o1x = j;
            }
            else if (input[j] == 'o' && coin_check == 1) {
                o2y = i;
                o2x = j;
            }
        }
    }

    dfs(o1y, o1x, o2y, o2x, 0);

    if (min_cnt == 987654321) cout << -1;
    else cout << min_cnt;

    return 0;
}