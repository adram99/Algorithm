#include <iostream>
#include <vector>
#include <queue>
#pragma warning (disable:4996)
using namespace std;
#define MAX 987654321;

vector<pair<int, int>> graph[1001];     // int,int 형식으로 저장하는 vector를 그래프로 사용 
int dist[1001];                         // 도시마다 도착하기까지 드는 최소 비용을 저장

int dijsktra(int start, int end) {
    dist[start] = 0;                    // 출발지는 비용 0으로 시작
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // 도시, 드는 비용을 넣을 우선순위 큐 선언 (오름차순)
    pq.push({ start, 0 });              // 출발지와 비용 0

    while (!pq.empty()) {
        int curCity = pq.top().first;   // 해당 도시
        int curCost = pq.top().second;  // 해당 도시까지 드는 비용  
        pq.pop();
        if (curCost > dist[curCity]) continue;
        for (int i = 0; i < graph[curCity].size(); i++) {
            int nextCost = graph[curCity][i].second;
            int next = graph[curCity][i].first;

            if (dist[next] <= curCost + nextCost) continue;

            dist[next] = curCost + nextCost;
            pq.push({ dist[next], next });
        }
    }
    return dist[end];
}

int main() {
    int N, M;
    int start, end, cost;
    int start_want, end_want;

    for (int i = 0; i < 1001; i++) dist[i] = MAX;  // 도시별 드는 최소 요금을 저장하기 위해 처음은 큰 값으로 초기화

    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &start, &end, &cost);
        graph[start].push_back({ end, cost });     // 주어진 정보로 그래프 생성
    }
    scanf("%d %d", &start_want, &end_want);
    printf("%d", dijsktra(start_want, end_want)); 

    return 0;
}
