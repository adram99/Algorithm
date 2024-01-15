#include <iostream>
#include <vector>
#include <queue>
#pragma warning (disable:4996)
using namespace std;
#define MAX 987654321;

vector<pair<int, int>> graph[1001];
int dist[1001];

int dijsktra(int start, int end) {
    dist[start] = 0;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, start });
    while (!pq.empty()) {
        int curCost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (curCost > dist[cur])continue;
        for (int i = 0; i < graph[cur].size(); i++) {
            int nextCost = graph[cur][i].second;
            int next = graph[cur][i].first;
            if (dist[next] <= curCost + nextCost) continue;
            dist[next] = curCost + nextCost;
            pq.push({ dist[next],next });
        }
    }
    return dist[end];
}

int main() {
    int N, M;
    int start, end, cost;
    int start_want, end_want;

    for (int i = 0; i < 1001; i++) dist[i] = MAX;

    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &start, &end, &cost);
        graph[start].push_back({ end, cost });
    }
    scanf("%d %d", &start_want, &end_want);
    printf("%d", dijsktra(start_want, end_want));

    return 0;
}