#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int visited[1001];

void DFS(int n, int v) {
    visited[v] = 1;
    cout << v << " ";

    for (int i = 1; i <= n; i++) {
        if (map[v][i] == 1 && visited[i] == 0) {
            DFS(n, i);
        }
    }
}

void BFS(int n, int v) {
    visited[v] = 1;
    cout << v << " ";
    queue<int> q;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (map[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                cout << i << " ";
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    DFS(N, V);
    cout << '\n';

    for (int i = 1; i <= N; i++) visited[i] = 0;

    BFS(N, V);

    return 0;
}