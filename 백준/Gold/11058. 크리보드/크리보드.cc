#include <iostream>
#include <algorithm>
using namespace std;

long long dp[101];  // 값들이 배수로 증가함에 따라 int로 감당이 안됨

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    if (N <= 6) cout << N;  // 6번째 까지는 A추가만 하는게 최대
    else {
        for (int i = 0; i <= 6; i++) dp[i] = i;
        for (int i = 7; i <= N; i++) {          // 7번째부터는 복사 하는것이 최대
            for (int j = 3; j < i; j++) {       // 전체 선택, 복사, 붙여넣기 3번은 최소한으로 필요
                dp[i] = max(dp[i], dp[i - j] * (j - 1));
            }
        }
        cout << dp[N];
    }
    return 0;
}
