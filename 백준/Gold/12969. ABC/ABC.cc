#include <iostream>
using namespace std;

bool dp[31][31][31][450];
char arr[32];

int N, K;

bool solve(int n, int a, int b, int k)
{
    if (n == N) {
        if (K == k) return true;
        else return false;
    }

    if (dp[n][a][b][k]) return false;
    dp[n][a][b][k] = true;

    arr[n] = 'A';
    if (solve(n + 1, a + 1, b, k)) return true;

    arr[n] = 'B';
    if (solve(n + 1, a, b + 1, k + a)) return true;

    arr[n] = 'C';
    if (solve(n + 1, a, b, k + a + b)) return true;

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    if (solve(0, 0, 0, 0)) cout << arr;
    else cout << -1;
    return 0;
}