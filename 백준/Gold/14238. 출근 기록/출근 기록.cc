#include <iostream>
#include <cstring>
using namespace std;

int len;
int dp[51][51][51][3][3];  // dp[A][B][C][이전 출근][[2일전 출근】
int abc[3];

int calculate(int a, int b, int c, int before, int bbefore) {
    if (a + b + c == len) return 1;
    int &val = dp[a][b][c][before][bbefore]; // int val로 했을 때 시간초과(?)
    if (val != -1) return val;               // 이미 있는 값이면 해당 값 반환
    val = 0;

    if (a < abc[0]) {  // A 횟수가 남았을 때
        val = calculate(a + 1, b, c, 0, before);
        if (val == 1) {
            cout << "A";
            return val;
        }
    }
    if (b < abc[1]) {
        if(before != 1) {  // 1일전 출근이 B가 아니면
            val = calculate(a, b + 1, c, 1, before);
            if (val == 1) {
                cout << "B";
                return val;
            }
        }
    }
    if (c < abc[2]) {
        if(before != 2 && bbefore != 2) {  // 1일전과 2일전 출근이 C가 아니면
            val = calculate(a, b, c + 1, 2, before);
            if (val == 1) {
                cout << "C";
                return val;
            }
        }
    }

    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;
    len = input.size();
    for (int i = 0; i < len; i++) {
        if (input[i] == 'A') abc[0]++;
        else if (input[i] == 'B') abc[1]++;
        else if (input[i] == 'C') abc[2]++;
    }
    if (abc[1] * 2 - 1 > len) cout << -1;       // B가 다 못들어가는 경우
    else if (abc[2] * 3 - 2 > len) cout << -1;  // C가 다 못들어가는 경우
    else {
        memset(dp, -1, sizeof(dp));
        if(!calculate(0, 0, 0, 0, 0)) cout << -1;
    }

    return 0;
}
