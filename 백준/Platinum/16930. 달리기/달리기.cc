#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
char gym[1001][1001];
int visited[1001][1001];
int nx[4] = { 1, 0, 0, -1 };
int ny[4] = { 0, -1, 1, 0 };

void bfs(int x1, int y1, int x2, int y2) {
    queue<pair<int, int>> q;
    visited[x1][y1] = 0;
    q.push(make_pair(x1, y1));

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        int cnt = visited[cur_x][cur_y];
        q.pop();

        for (int i = 0; i < 4; i++) {
            for(int j = 1; j <= K; j++) {
                int next_y = cur_y + ny[i] * j;
                int next_x = cur_x + nx[i] * j;
                if (next_y < 0 || next_y >= M || next_x < 0 || next_x >= N) break;
                if (gym[next_x][next_y] == '#' || visited[next_x][next_y] < cnt + 1) break;
                if (visited[next_x][next_y] == cnt + 1) continue;
                if (visited[next_x][next_y] == 987654321) {
                    visited[next_x][next_y] = cnt + 1;
                    if (next_x == x2 && next_y == y2) return;
                    q.push(make_pair(next_x, next_y));
                }
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x1, y1, x2, y2;
    cin >> N >> M >> K;
    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            gym[i][j] = input[j];
            visited[i][j] = 987654321;
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;

    bfs(x1-1, y1-1, x2-1, y2-1);

    if (visited[x2-1][y2-1] == 987654321) cout << -1;
    else cout << visited[x2-1][y2-1];

    return 0;
}