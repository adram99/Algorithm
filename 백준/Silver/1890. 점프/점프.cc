#include <iostream>
using namespace std;

long dp[101][101];   // 현재 칸으로 오기까지의 경로 수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, jump;
    cin >> N;
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> jump;
            if (dp[i][j] == 0 || jump == 0) continue;       // 이전에 들어온 경로가 없거나 점프할 칸 수가 없으면 패스

            if (i + jump < N) dp[i + jump][j] += dp[i][j];  // 아래 방향으로 점프할 칸 수 위치에 현재 칸의 들어온 경로 수를 더함
            if (j + jump < N) dp[i][j + jump] += dp[i][j];  // 오른쪽 방향으로 점프할 칸 수 위치에 현재 칸의 들어온 경로 수를 더함
        }
    }

    cout << dp[N - 1][N - 1];   // 맨 오른쪽 아래 칸의 들어온 경로 수 출력

    return 0;
}
