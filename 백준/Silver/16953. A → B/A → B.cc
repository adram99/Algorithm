#include <iostream>
using namespace std;

// dfs, bfs를 쓰지 않고 반대로 계산하는 풀이

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count = 0;
    long long A, B;
    cin >> A >> B;

    while (1) {
        if (B == A) {           // 답이 나오면 횟수+1 출력
            cout << count + 1;
            break;
        }
        else if (B < A) {       // 계산중 값이 넘어가면 -1 출력
            cout << -1;
            break;
        }

        if (B % 10 == 1) {      // 끝자리가 1이면 2로 안나눠지므로 무조건 1을 뺌
            B = B / 10;
            count++;
        }
        else if (B % 2 == 0) {  // 2로 나눠지면 나누기 2
            B = B / 2;
            count++;
        }
        else {                  // 끝자리가 1이 아닌 홀수가 나오면 더이상 계산이 안되므로 -1 출력
            cout << -1;
            break;
        }
    }

    return 0;
}
