#include <iostream>
using namespace std;

int arr[2001];
int palindrom[2001][2001];

void check(int n) {
    for (int i = 1; i <= n; i++) palindrom[i][i] = 1;

    for (int i = 1; i <= n - 1; i++) {
        if (arr[i] == arr[i + 1]) palindrom[i][i + 1] = 1;
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 2; j <= n; j++) {
            if (arr[i] == arr[j] && palindrom[i + 1][j - 1] == 1) palindrom[i][j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    check(N);

    int S, E;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> S >> E; 
        cout << palindrom[S][E] << "\n";
    }

    return 0;
}