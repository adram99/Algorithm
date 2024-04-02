#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int testcase;
    cin >> testcase;

    while (testcase--) {
        int N, K, W;
        int build_time[1001];
        cin >> N >> K;
        for (int i = 1; i <= N; i++) cin >> build_time[i];

        vector<int> seq[1001];
        queue<int> q;
        int inDeg[1001] = { 0, };
        int max_time[1001];

        int x, y;
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            seq[x].push_back(y);
            inDeg[y]++;
        }
        cin >> W;

        for (int i = 1; i <= N; i++) {
            if (inDeg[i] == 0) q.push(i);
            max_time[i] = build_time[i];
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            int next;
            for (int i = 0; i < seq[cur].size(); i++) {
                next = seq[cur][i];
                inDeg[next]--;
                max_time[next] = max(max_time[next], max_time[cur] + build_time[next]);

                if (inDeg[next] == 0) q.push(next);
            }
        }

        cout << max_time[W] << '\n';
    }

    return 0;
}
