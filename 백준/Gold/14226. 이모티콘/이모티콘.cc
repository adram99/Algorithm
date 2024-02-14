#include <iostream>
#include <queue>
using namespace std;

int visited[1001][1001];  // visited[이모티콘 수][클립보드]
struct Info {
    int i_time;
    int i_clip;
    int i_pos;
};

int bfs(int s) {
    int time = 0, clip = 0, pos = 1;
    queue<Info> q;
    q.push({ 0, 0, 1 });
    visited[1][0] = 1;

    while (!q.empty()) {
        time = q.front().i_time;
        clip = q.front().i_clip;
        pos = q.front().i_pos;
        q.pop();

        if (pos == s) return time;

        if (pos - 1 >= 2 && visited[pos - 1][clip] != 1) {
            q.push({ time + 1, clip, pos - 1 });
            visited[pos - 1][clip] = 1;
        }
        if (pos + clip <= 1000 && visited[pos + clip][clip] != 1) {
            q.push({ time + 1, clip, pos + clip });
            visited[pos + clip][clip] = 1;
        }
        clip = pos;
        q.push({ time + 1, clip, pos });
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S;
    cin >> S;
    cout << bfs(S);

    return 0;
}