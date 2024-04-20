#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string input;
vector<pair<int, int>> xy;
int nextX[4] = { 0, 1, 0, -1 };
int nextY[4] = { 1, 0, -1, 0 };

void tracking() {
    int dir = 0;
    int nowX = 0, nowY = 0;
    xy.push_back(make_pair(nowX, nowY));
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == 'F') {  // 전진
            nowX += nextX[dir];
            nowY += nextY[dir];
            xy.push_back(make_pair(nowX, nowY));
        }
        else if (input[i] == 'B') {  // 후진
            nowX -= nextX[dir];
            nowY -= nextY[dir];
            xy.push_back(make_pair(nowX, nowY));
        }
        else if (input[i] == 'L') {  // 왼쪽 회전
            if (dir == 0) dir = 3;
            else dir--;
        }
        else if (input[i] == 'R') {  // 오른쪽 회전
            if (dir == 3) dir = 0;
            else dir++;
        }
    }
}

void calculate() {
    int min_x = 987654321, min_y = 987654321;
    int max_x = -987654321, max_y = -987654321;
    while (xy.size() > 0) {
        min_x = min(min_x, xy.back().first);
        max_x = max(max_x, xy.back().first);
        min_y = min(min_y, xy.back().second);
        max_y = max(max_y, xy.back().second);
        xy.pop_back();
    }
    cout << (max_x - min_x) * (max_y - min_y) << "\n";  //  딱맞는 직사각형
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> input;
        tracking();
        calculate();
    }

    return 0;
}
