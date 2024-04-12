#include <iostream>
using namespace std;

char signal[5][20001];

int checkNum(int x) {
    //맨 위 가로 3개 확인 (1, 4 걸러냄)
    for (int i = 0; i < 3; i++) {
        if (signal[0][x + i] != '#') {
            for (int j = 0; j < 5; j++) {
                if (signal[j][x] != '#') return 4;
            }
            return 1;
        }
    }
    //세로 위에서 2개 확인(2, 3, 7 걸러냄)
    for (int i = 0; i < 2; i++) {
        if (signal[i][x] != '#') {
            if (signal[i + 1][x] != '#') return 7;
            else if (signal[i + 2][x] != '#') return 3;
            else return 2;
        }
    }
    //세로 아래서 2번째 확인(5, 9 걸러냄)
    if (signal[3][x] != '#') {
        if (signal[1][x + 2] != '#') return 5;
        else return 9;
    }
    //0, 6, 8 확인
    if (signal[1][x + 2] != '#') return 6;
    else {
        if (signal[2][x + 1] != '#') return 0;
        else return 8;
    }
}

void printNum(int n) {
    int i = 0;
    while(i < n / 5) {
        if (signal[0][i] == '#') {
            int print = checkNum(i);
            cout << print;
            if (print == 1) i += 2;
            else i += 4;
        }
        else i++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N / 5; j++) cin >> signal[i][j];
    }
    printNum(N);

    return 0;
}