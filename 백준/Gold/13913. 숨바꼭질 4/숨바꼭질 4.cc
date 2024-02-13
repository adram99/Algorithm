#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int visited[100001];
int parent[100001];
vector<int> route;

int bfs(int subin, int brother) {
    int time = 0, point = subin;

    queue<pair<int, int>>q;
    q.push(make_pair(time, point));

    while (!q.empty()) {
        time = q.front().first;
        point = q.front().second;
        q.pop();

        if (point == brother) return time;

        if (point * 2 <= 100000 && visited[point * 2] == 0) {
            q.push(make_pair(time + 1, point * 2));
            parent[point * 2] = point;
            visited[point * 2] = 1;
        }
        if (point - 1 >= 0 && visited[point - 1] == 0) {
            q.push(make_pair(time + 1, point - 1));
            parent[point - 1] = point;
            visited[point - 1] = 1;
        }
        if (point + 1 <= 100000 && visited[point + 1] == 0) {
            q.push(make_pair(time + 1, point + 1));
            parent[point + 1] = point;
            visited[point + 1] = 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    cout << bfs(N, K) << "\n";
    
    vector<int> route;
    int index = K;
    while (index != N) {
        route.push_back(index);
        index = parent[index];
    }

    cout << N << " ";
    for (int i = route.size() - 1; i >= 0; i--) {
        cout << route[i] << " ";
    }

    return 0;
}