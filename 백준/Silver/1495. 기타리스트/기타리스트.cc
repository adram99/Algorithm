#include <iostream>
using namespace std;

int dp[51][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, S, M, vol;
    cin >> N >> S >> M;

    dp[0][S] = 1;
    for (int i = 1; i <= N; i++) {
        cin >> vol;
        int check = 0;
        for (int j = 0; j <= M; j++) {
            if (dp[i - 1][j] == 1) {
                if (j - vol >= 0) {
                    dp[i][j - vol] = 1;
                    check = 1;
                }
                if (j + vol <= M) {
                    dp[i][j + vol] = 1;
                    check = 1;
                }
            }
        }
        if (check == 0) {
            cout << -1;
            return 0;
        }
    }

    int max_vol = -1;
    for (int i = M; i >= 0; i--) {
        if (dp[N][i] == 1) {
            max_vol = i;
            break;
        }
    }
    cout << max_vol; 

    return 0;
}