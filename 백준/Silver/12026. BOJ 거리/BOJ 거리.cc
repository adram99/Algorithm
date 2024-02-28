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
    reset(N);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (S[j] == 'B' && S[i] != 'O') continue;
            else if (S[j] == 'O' && S[i] != 'J') continue;
            else if (S[j] == 'J' && S[i] != 'B') continue;
            else jump[i] = min(jump[i], jump[j] + (i - j) * (i - j));
        }
    }
    if (jump[N - 1] == 987654321) cout << -1;
    else cout << jump[N - 1];

    return 0;
}