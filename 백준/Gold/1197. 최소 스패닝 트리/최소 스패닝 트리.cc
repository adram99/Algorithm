#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int parent[10001];                 // 부모 노드가 같은지 판단하는 용도

int find(int x) {
    if (parent[x] == x) return x;
    else return find(parent[x]);   // 부모 노드가 나올때까지 타고 올라감
}

void unionNodes(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);
    parent[yRoot] = xRoot;         // 노드 연결
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E;
    cin >> V >> E;
    for (int i = 0; i <= V; i++) parent[i] = i;    // 아무것도 연결돼있지 않은 상태

    int a, b, c;
    vector<pair<int, pair<int, int>>> graph;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        graph.push_back({ c, {a, b} });
    }
    sort(graph.begin(), graph.end());              // 가중치를 기준으로 오름차순 정렬

    int sum = 0;
    for (int i = 0; i < E; i++) {
        int W = graph[i].first;
        int node1 = graph[i].second.first;
        int node2 = graph[i].second.second;
        if (find(node1) == find(node2)) continue;  // 부모 노드가 같으면 연결돼있다는 뜻, 패스
        else {
            unionNodes(node1, node2);              // 연결 안돼있으면 연결
            sum += W;
        }
    }

    cout << sum;

    return 0;
}