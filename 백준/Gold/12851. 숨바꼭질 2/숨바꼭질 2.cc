#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int result, cnt;
int visited[100001];

void bfs(int su, int bro) {
    queue<pair<int, int>> q;
    q.push(make_pair(0, su));       // 0초, 수빈의 초기 위치로 시작 

    while (!q.empty()) {
        int time = q.front().first;
        int pos = q.front().second;
        visited[pos] = 1;           // 방문 체크
        q.pop();
        if (pos == bro) {           // 목표 위치 도착하면 시간과 횟수 기록
            result = time;
            cnt++;
        }
        if (visited[bro] == 1 && result < time) {  // 목표 위치에 도착한 기록이 존재하고 탐색중인 시간이 기록된 최소 시간을 넘어가면 탐색 종료
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

    int subin, brother;          // 수빈 위치, 동생 위치
    cin >> subin >> brother;
    
    bfs(subin, brother);
    cout << result << " " << cnt;

    return 0;
}
