#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int N, M;
int map[51][51];
int visited[51][51];
int ny[8] = { -1,-1,0,1,1,1,0,-1 };  // 아래 방향부터 시계 반대 방향으로 8방향
int nx[8] = { 0,1,1,1,0,-1,-1,-1 };
int answer = 0;

struct Info {
    int y;
    int x;
    int cnt;
};

int bfs(int y, int x) {
    memset(visited, 0, sizeof(visited));
    queue<Info> q;
    int Cnt = 0;
    visited[y][x] = 1;
    q.push({ y, x, 0 });

    while (!q.empty()) {
        int cur_y = q.front().y;
        int cur_x = q.front().x;
        int cur_cnt = q.front().cnt;
        q.pop();

        if (map[cur_y][cur_x] == 1) return cur_cnt;  // 탐색중 처음 1(상어)이 발견되면 최소 거리(안전 거리)

        for (int i = 0; i < 8; i++) {
            int next_y = cur_y + ny[i];
            int next_x = cur_x + nx[i];
            if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;  // 주어진 범위를 벗어나면 스킵
            if (visited[next_y][next_x] != 1) {
                visited[next_y][next_x] = 1;
                q.push({next_y, next_x, cur_cnt + 1});
            }
        }
    };

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max_ans = -1;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                int ans = bfs(i, j);
                if (max_ans < ans) max_ans = ans;  // 탐색한 최소거리 중 최대만 저장
            }
        }
    }
    cout << max_ans;

    return 0;
}
