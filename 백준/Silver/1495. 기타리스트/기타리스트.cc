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
        for (int j = 0; j <= M; j++) {   // 볼륨이 0인 경우도 포함
            if (dp[i - 1][j] == 1) {     // 이전 곡에서 나올 수 있는 볼륨
                if (j - vol >= 0) {      // 이전 곡의 볼륨에서 현재 조절 가능한 볼륨만큼 낮출 수 있을 경우
                    dp[i][j - vol] = 1;
                    check = 1;
                }
                if (j + vol <= M) {      // 이전 곡의 볼륨에서 현재 조절 가능한 볼륨만큼 높일 수 있을 경우
                    dp[i][j + vol] = 1;
                    check = 1;
                }
            }
        }
        if (check == 0) {                // 볼륨을 바꾸지 못한 경우 바로 종료
            cout << -1;
            return 0;
        }
    }

    int max_vol = -1;
    for (int i = M; i >= 0; i--) {
        if (dp[N][i] == 1) {             // 마지막 곡의 제일 큰 볼륨값 
            max_vol = i;
            break;
        }
    }
    cout << max_vol; 

    return 0;
}
