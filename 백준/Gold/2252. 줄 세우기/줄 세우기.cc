#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 32001

vector<int> graph[MAX];
int indegree[MAX];
int res[MAX];

void lineUp(int n) {
    queue<int> zero;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) zero.push(i);
    }
    if (zero.empty()) return;
    for (int i = 1; i <= n; i++) {
        int zero_node = zero.front();
        zero.pop();
        res[i] = zero_node;

        for (int i = 0; i < graph[zero_node].size(); i++) {
            int node = graph[zero_node][i];
            indegree[node]--;
            if (indegree[node] == 0) zero.push(node);
        }
    }

}

int main() {
    int N, M;
    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    lineUp(N);

    for (int i = 1; i <= N; i++) {
        cout << res[i] << " ";
    }

    return 0;
}
