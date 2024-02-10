#include <iostream>
using namespace std;

int map[101][101];
int visited[101][101];
int N, M, K, cnt;

int nx[4] = { 0, 0, -1, 1 };
int ny[4] = { 1, -1, 0, 0 };

void dfs(int y, int x) {
    cnt++;
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int next_x = x + nx[i];
        int next_y = y + ny[i];

        if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N) continue;  // 범위를 벗어난 탐색은 스킵
        else if (map[next_y][next_x] == 1 && visited[next_y][next_x] != 1) dfs(next_y, next_x);  // 연결된 1값을 탐색
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max = 0;
    int x, y;
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        map[x-1][y-1] = 1;        // map[0][0]을 좌표 (1,1)로 간주. 답을 구하는 것에는 영향 X
    }
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                cnt = 0;
                dfs(i, j);
                if (cnt > max) max = cnt;               // 가장 큰 탐색 값만 확인
            }
        }
    }

    cout << max;
    return 0;
}
