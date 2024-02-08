#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int result, cnt;
int visited[100001];

void bfs(int su, int bro) {
    queue<pair<int, int>> q;
    q.push(make_pair(0, su));

    while (!q.empty()) {
        int time = q.front().first;
        int pos = q.front().second;
        visited[pos] = 1;
        q.pop();
        if (pos == bro) {
            result = time;
            cnt++;
        }
        if (visited[bro] == 1 && result < time) {
            return;
        }
        if (pos - 1 >= 0 && visited[pos - 1] == 0) q.push(make_pair(time + 1, pos - 1));
        if (pos + 1 <= 100000 && visited[pos + 1] == 0) q.push(make_pair(time + 1, pos + 1));
        if (pos * 2 <= 100000 && visited[pos * 2] == 0) q.push(make_pair(time + 1, pos * 2));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int subin, brother;
    cin >> subin >> brother;
    
    bfs(subin, brother);
    cout << result << " " << cnt;

    return 0;
}