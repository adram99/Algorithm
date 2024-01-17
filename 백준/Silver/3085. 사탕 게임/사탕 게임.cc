#include <iostream>
using namespace std;

char board[50][50];
int max_count = 0;

void change(int y1, int x1, int y2, int x2) {
    int temp = board[y1][x1];
    board[y1][x1] = board[y2][x2];
    board[y2][x2] = temp;
}

void widthSearch(int boardY, int n) { 
    if (max_count == n) return;
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        if (board[boardY][i] == board[boardY][i + 1]) {
            count++;
            if (max_count < count) max_count = count;
        }
        else count = 1;
    }
}

void heightSearch(int boardX, int n) {
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

void firstMax(int n) {
    for (int i = 0; i < n; i++) {
        widthSearch(i, n);
        heightSearch(i, n);
    }
}

void afterChangeMax(char dir, int boardY, int boardX, int n) {
    if (dir == 'w') {
        /*widthSearch(boardY, n);
        heightSearch(boardX, n);
        heightSearch(boardX + 1, n);*/
        firstMax(n);
    }
    else if (dir == 'h') {
        /*heightSearch(boardX, n);
        widthSearch(boardY, n);
        widthSearch(boardY + 1, n);*/
        firstMax(n);
    }
}

void changeAndCount(int n) {
    char temp, change_dir;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            change(i, j, i, j + 1);
            change_dir = 'w';
            afterChangeMax(change_dir, i, j, n);
            change(i, j, i, j + 1);
        } 
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            change(i, j, i + 1, j);
            change_dir = 'h';
            afterChangeMax(change_dir, i, j, n);
            change(i, j, i + 1, j);
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

    firstMax(N);
    changeAndCount(N);
    cout << max_count;

    return 0;
}