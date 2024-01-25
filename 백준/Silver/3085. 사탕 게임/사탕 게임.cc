#include <iostream>
using namespace std;

char board[50][50];
int max_count = 0;

void change(int y1, int x1, int y2, int x2) {  // 사탕 교환
    int temp = board[y1][x1];
    board[y1][x1] = board[y2][x2];
    board[y2][x2] = temp;
}

void widthSearch(int boardY, int n) {  // 가로로 연결된 최대 사탕 탐색
    if (max_count == n) return;        // 최대 사탕 개수가 n과 같으면 더 진행해도 n이 최대
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        if (board[boardY][i] == board[boardY][i + 1]) {
            count++;
            if (max_count < count) max_count = count;
        }
        else count = 1;
    }
}

void heightSearch(int boardX, int n) { // 세로로 연결된 최대 사탕 탐색
    if (max_count == n) return;
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        if (board[i][boardX] == board[i + 1][boardX]) {
            count++;
            if (max_count < count) max_count = count;
        }
        else count = 1; 
    }
}
  
void firstMax(int n) {                 // 초기 상태에서 최대 연결된 사탕 탐색
    for (int i = 0; i < n; i++) {
        widthSearch(i, n);
        heightSearch(i, n);
    }
}

void changeAndCount(int n) {           // 바뀐 뒤 최대 연결된 사탕 탐색
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            change(i, j, i, j + 1);       // 가로로 교환 (바꾼 사탕 두개가 포함된 세로줄 2줄, 가로줄 1줄만 확인)
            widthSearch(i, n); 
            heightSearch(j, n);
            heightSearch(j + 1, n);
            change(i, j, i, j + 1);       // 원위치
        } 
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            change(i, j, i + 1, j);       // 세로로 교환 (바꾼 사탕 두개가 포함된 가로줄 2줄, 세로줄 1줄만 확인)
            heightSearch(j, n);
            widthSearch(i, n);
            widthSearch(i + 1, n);
            change(i, j, i + 1, j);       // 원위치
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    firstMax(N);       // 교환하지 않은 원래 상태에서 최대값이 나올 수 있음
    changeAndCount(N);
    cout << max_count;

    return 0;
}
