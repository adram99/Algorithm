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
            for(int j = 1; j <= K; j++) {       // 방향별로 1~K칸 탐색하며 cnt+1 기록
                int next_y = cur_y + ny[i] * j;
                int next_x = cur_x + nx[i] * j;
                if (next_y < 0 || next_y >= M || next_x < 0 || next_x >= N) break;          // 범위 넘어가면 스킵
                if (gym[next_x][next_y] == '#' || visited[next_x][next_y] < cnt + 1) break; // #(벽)이거나 이미 기록된 값이 더 작으면 다른 방향 탐색
                if (visited[next_x][next_y] == cnt + 1) continue;                           // 이미 기록된 값이 같으면 이어서 탐색
                if (visited[next_x][next_y] == 987654321) {  // 첫 방문
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

    bfs(x1-1, y1-1, x2-1, y2-1);  // 배열은 0부터 계산하므로 각각 -1

    if (visited[x2-1][y2-1] == 987654321) cout << -1;  // 도달 못했으면 -1
    else cout << visited[x2-1][y2-1];

    return 0;
}
