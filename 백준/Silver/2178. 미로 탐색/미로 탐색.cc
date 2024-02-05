#include <iostream>
#include <queue>
using namespace std;

int maze[101][101];
int visited[10001];

int nx[4] = { 0, 0, -1, 1 };
int ny[4] = { 1, -1, 0, 0 };

int BFS(int n, int m) {
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + nx[i];
            int next_y = y + ny[i];

            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || maze[next_y][next_x] == 0) continue;

            if (maze[next_y][next_x] == 1)
            {
                maze[next_y][next_x] = maze[y][x] + 1;
                q.push({next_y, next_x});
            }
        }
    }

    return maze[n - 1][m - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;
    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            maze[i][j] = input[j] - '0';
        }
    }

    cout << BFS(N, M);

    return 0;
}