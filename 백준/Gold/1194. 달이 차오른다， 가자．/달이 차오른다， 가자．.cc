#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct pos {
    int y, x, cnt, key;
};

int N, M;
char map[51][51];
bool visited[51][51][64];
int next_x[4] = { 1, 0, -1, 0 };
int next_y[4] = { 0, -1, 0, 1 };
queue<pos> q;

bool check(char abc, int key) {
    if ((key & (1 << (abc - 'A'))) != 0) return 1;
    else return 0;
}

int calculate(int sy, int sx) {
    q.push({ sy, sx, 0, 0 });
    int y, x, cnt, key;
    while (!q.empty()) {
        y = q.front().y;
        x = q.front().x;
        cnt = q.front().cnt;
        key = q.front().key;
        q.pop();
        visited[y][x][key] = 1;

        if (map[y][x] == '1') return cnt;

        for (int i = 0; i < 4; i++) {
            int ny = y + next_y[i];
            int nx = x + next_x[i];
            if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                if (map[ny][nx] == '#') continue;
                if (map[ny][nx] == '.' || map[ny][nx] == '0' || map[ny][nx] == '1') {
                    if (visited[ny][nx][key] == 0) {
                        visited[ny][nx][key] = 1;
                        q.push({ ny, nx, cnt + 1, key });
                    }
                }
                else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'f') {
                    int get_key = key | (1 << (map[ny][nx] - 'a'));
                    if (visited[ny][nx][get_key] == 0) {
                        visited[ny][nx][get_key] = 1;
                        q.push({ ny, nx, cnt + 1, get_key });
                    }
                }
                else if ('A' <= map[ny][nx] && map[ny][nx] <= 'F') {
                    if (check(map[ny][nx], key) == 1 && visited[ny][nx][key] == 0) {
                        visited[ny][nx][key] = 1;
                        q.push({ ny, nx, cnt + 1, key });
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int start_x, start_y;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == '0') {
                start_x = j;
                start_y = i;
            }
        }
    }

    cout << calculate(start_y, start_x);

    return 0;
}