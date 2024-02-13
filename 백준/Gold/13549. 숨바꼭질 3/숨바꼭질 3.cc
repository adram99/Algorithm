#include <iostream>
#include <queue>
using namespace std;

int visited[100001];

int priority_bfs(int subin, int brother) {
    int time = 0, point = subin;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(time, point));

    while (!pq.empty()) {
        time = pq.top().first;
        point = pq.top().second;
        visited[point] = 1;
        pq.pop();

        if (point == brother) return time;

        if (point * 2 <= 100000 && visited[point * 2] == 0)
            pq.push(make_pair(time, point * 2));
        if (point + 1 <= 100000 && visited[point + 1] == 0)
            pq.push(make_pair(time + 1, point + 1));
        if (point - 1 >= 0 && visited[point - 1] == 0)
            pq.push(make_pair(time + 1, point - 1));
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    cout << priority_bfs(N, K);

    return 0;
}