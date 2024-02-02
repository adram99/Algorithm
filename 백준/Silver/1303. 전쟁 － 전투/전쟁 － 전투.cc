#include <iostream>
using namespace std;

char field[101][101];
int visited[101][101];
int N, M, cnt;

int nx[4] = { 0, 0, -1, 1 };
int ny[4] = { 1, -1, 0, 0 };

void dfs(int y, int x, char team) {
    cnt++;
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int next_x = x + nx[i];
        int next_y = y + ny[i];
        if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
        if (field[next_y][next_x] == team && visited[next_y][next_x] != 1) dfs(next_y, next_x, team);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum[2] = { 0, 0 }; // sum[0] = B team, sum[1] = W team

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
        {
            field[i][j] = str[j];
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (field[i][j] != 0 && visited[i][j] == 0) {
                cnt = 0;
                if (field[i][j] == 'B') {
                    dfs(i, j, 'B');
                    sum[0] += cnt * cnt;
                }
                else if (field[i][j] == 'W') {
                    dfs(i, j, 'W');
                    sum[1] += cnt * cnt;
                }
            }
        }
    }
    cout << sum[1] << " " << sum[0];
    return 0;
}