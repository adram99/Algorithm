#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int jump[1001];

void reset(int n) {
    for (int i = 1; i <= n; i++) jump[i] = 987654321;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    reset(N);      // 최댓값(987654321)으로 초기화
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (S[j] == 'B' && S[i] != 'O') continue;      // 앞의 위치(j)가 B인데 뒤의 위치(i)가 O가 아니면 패스
            else if (S[j] == 'O' && S[i] != 'J') continue;
            else if (S[j] == 'J' && S[i] != 'B') continue;
            else jump[i] = min(jump[i], jump[j] + (i - j) * (i - j));
        }
    }
    if (jump[N - 1] == 987654321) cout << -1;   // 목표에 도달하지 못했을 경우 
    else cout << jump[N - 1];

    return 0;
}
