#include <iostream>
using namespace std;

long long dp[100][21];   // ex) dp[n][num]는 n번째 계산 결과가 num이 나올 경우의 수를 의미 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    cin >> N >> num;
    dp[0][num] = 1;
    for (int i = 1; i < N - 1; i++) {
        cin >> num;
        for (int j = 0; j <= 20; j++) {
            if (dp[i - 1][j] > 0) {     // j가 이전 계산으로 나올 수 있는 결과일 때
                if (j - num >= 0) dp[i][j - num] += dp[i - 1][j];    // num을 빼서 0이상이면 계산 후 기록
                if (j + num <= 20) dp[i][j + num] += dp[i - 1][j];   // num을 더해서 20이하면 계산 후 기록
            }
        }
    }
    cin >> num;
    cout << dp[N - 2][num];  // 0부터 시작하고 마지막 수는 결과로 취급하므로 N-2번째에 num이 나오는 경우가 답

    return 0;
}
