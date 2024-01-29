#include <iostream>
#include <queue>
using namespace std;

int map[26][26];
int visited[26][26];
int cnt;
priority_queue<int> house;

int nx[4] = { 0, 0, -1, 1 };
int ny[4] = { 1, -1, 0, 0 };

void dfs(int y, int x, int max) {
    cnt++;
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int next_x = x + nx[i];
        int next_y = y + ny[i];
        if (next_x < 0 || next_x >= max || next_y < 0 || next_y >= max) continue;
        if (map[next_y][next_x] == 1 && visited[next_y][next_x] != 1) dfs(next_y, next_x, max);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = str[j] - '0';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                cnt = 0;
                dfs(i, j, N);
                house.push(-cnt);
            }
        }
    }
    int size = house.size();
    cout << size << "\n";
    for (int i = 0; i < size; i++) {
        cout << -(house.top()) << "\n";
        house.pop();
    }
    return 0;
}