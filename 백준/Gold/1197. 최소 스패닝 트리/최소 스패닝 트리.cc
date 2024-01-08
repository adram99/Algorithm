#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int parent[10001];

int find(int x) {
    if (parent[x] == x) return x;
    else return find(parent[x]);
}

void unionNodes(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);
    parent[yRoot] = xRoot;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i <= V; i++) parent[i] = i;

    int a, b, c;
    vector<pair<int, pair<int, int>>> graph;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph.push_back({c, {a, b}});
    }
    sort(graph.begin(), graph.end());
    
    int sum = 0;
    for (int i = 0; i < E; i++) {
        int W = graph[i].first;
        int node1 = graph[i].second.first;
        int node2 = graph[i].second.second;
        if (find(node1) == find(node2)) continue;
        else {
            unionNodes(node1, node2);
            sum += W;
        }
    }

    printf("%d", sum);

    return 0;
}