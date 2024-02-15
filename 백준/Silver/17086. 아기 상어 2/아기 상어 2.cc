#include <iostream>
#include <string.h>
#include <queue>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55
#define LL long long
#define INF 2e9

using namespace std;
int N, M;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int moveY[8] = { -1,-1,0,1,1,1,0,-1 };
int moveX[8] = { 0,1,1,1,0,-1,-1,-1 };
int answer = 0;

int BFS(int Y, int X) {
    memset(visited, 0, sizeof(visited));
    queue<pair<pair<int, int>, int> > Q;
    int Cnt = 0;
    visited[Y][X] = true;
    Q.push(make_pair(make_pair(Y, X), Cnt));

    while (!Q.empty()) {
        int CurY = Q.front().first.first;
        int CurX = Q.front().first.second;
        int CurCnt = Q.front().second;
        Q.pop();

        if (MAP[CurY][CurX] == 1) {
            return CurCnt;
        }
        for (int i = 0; i < 8; i++) {
            int nextY = CurY + moveY[i];
            int nextX = CurX + moveX[i];
            if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M) && (!visited[nextY][nextX])) {
                visited[nextY][nextX] = true;
                Q.push(make_pair(make_pair(nextY, nextX), CurCnt + 1));
            }
        }
    };

    return 0;
}

int main() {
    FIRST
        cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 0) {
                answer = max(answer, BFS(i, j));
            }
        }
    }
    cout << answer << "\n";

    return 0;
}