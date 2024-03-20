#include <iostream>
#include <vector>
using namespace std;

vector<int> net[101]; // 그래프를 그리기 위한 2차원 벡터
int link[101];        // 방문 확인
int cnt;

void dfs(int start) {
    cnt++;
    link[start] = 1;  // 방문 체크

    for (int i = 0; i < net[start].size(); i++) {
        if (link[net[start][i]] == 0) dfs(net[start][i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int coms, links;
    int a, b;

    cin >> coms >> links;
    for (int i = 0; i < links; i++) {
        cin >> a >> b;
        net[a].push_back(b);   // a와 b가 연결되면 net[a] = b, net[b] = a 둘다 체크
        net[b].push_back(a);
    }

    dfs(1);
    cout << cnt-1;
    return 0;
}
