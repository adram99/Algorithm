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
        int cur_city = pq.top().first;   // 해당 도시
        int cur_cost = pq.top().second;  // 해당 도시까지 드는 비용  
        pq.pop();                        // 큐에선 제거
        if (cur_cost > dist[cur_city]) continue;             // 현재 저장된 최소비용보다 클 경우 패스
        for (int i = 0; i < graph[cur_city].size(); i++) {   // 해당 도시와 연결된 다른 도시들과 비용 확인
            int next_cost = graph[cur_city][i].second;
            int next_city = graph[cur_city][i].first;

            if (dist[next_city] <= cur_cost + next_cost) continue;  // 현재 도시를 거쳐 연결된 도시로 가는 비용이 더 크면 패스

            dist[next_city] = cur_cost + next_cost;          // 지금 도시를 거쳐가는 비용이 더 작으면 업데이트
            pq.push({ dist[next_city], next_city });         // 더 작은 비용이 들어간 정보로 큐 push
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
