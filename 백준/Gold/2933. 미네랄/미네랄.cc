#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int R, C, N, H, h = 987654321;
char cave[101][101];
int link[101][101];
int visited[101][101];
int next_x[4] = { 1, 0, -1, 0 };
int next_y[4] = { 0, -1, 0, 1 };

int depth(int y, int x) {  // 공중에 뜬 미네랄 얼마나 내릴지 확인
    visited[y][x] = 1;
    int high = y;
    while (1) {
        if (high == 0) break;
        if (cave[high - 1][x] == 'x' && link[high - 1][x] == 1) break;
        high--;
    }
    h = min(h, y - high);
    for (int i = 0; i < 4; i++) {
        int ny = y + next_y[i];
        int nx = x + next_x[i];
        if (ny >= R || nx >= C || ny < 0 || nx < 0) continue;
        else if (visited[ny][nx] == 1) continue;
        else if (cave[ny][nx] == 'x') {
            depth(ny, nx);
        }
    }
    return 0;
}

int linkCheck(int y, int x) {
    link[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + next_y[i];
        int nx = x + next_x[i];
        if (ny >= R || nx >= C || ny < 0 || nx < 0) continue;
        else if (link[ny][nx] == 1) continue;
        else if (cave[ny][nx] == 'x') {
            linkCheck(ny, nx);
        }
    }
    return 0;
}

void drop() {
    for (int j = 0; j < C; j++) {
        if (cave[0][j] == 'x' && link[0][j] != 1) {
            linkCheck(0, j);  // 바닥과 연결된 미네랄 체크(그 외에는 공중에 뜬 미네랄)
        }
    }
    int first = 0;
    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (cave[i][j] == 'x' && link[i][j] == 0) {  // 공중에 뜬 미네랄이면
                if (first == 0) {
                    depth(i, j);
                    first = 1;
                    cave[i][j] = '.';
                    cave[i - h][j] = 'x';
                }
                else {
                    cave[i][j] = '.';
                    cave[i - h][j] = 'x';
                }
            }
        }
    }
    h = 987654321;
    memset(link, 0, sizeof(link));
    memset(visited, 0, sizeof(visited));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> R >> C;
    for (int i = R - 1; i >= 0; i--) {
        cin >> input;
        for (int j = 0; j < C; j++) cave[i][j] = input[j];
    }
    cin >> N;
    int turn = 1;
    for (int i = 0; i < N; i++) {
        cin >> H;
        if (turn == 1) {
            for (int j = 0; j < C; j++) {
                if (cave[H - 1][j] == 'x') {
                    cave[H - 1][j] = '.';
                    drop();
                    break;
                }
            }
            turn = 2;
        }
        else if (turn == 2) {
            for (int j = C - 1; j >= 0; j--) {
                if (cave[H - 1][j] == 'x') {
                    cave[H - 1][j] = '.';
                    drop();
                    break;
                }
            }
            turn = 1;
        }
    }

    for (int i = R - 1; i >= 0; i--) {
        for (int j = 0; j < C; j++) {
            cout << cave[i][j];
        }
        cout << "\n";
    }

    return 0;
}