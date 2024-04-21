#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
char map[12][6] = { 0 };
int next_x[4] = { 1, 0, -1, 0 };
int next_y[4] = { 0, -1, 0, 1 };

int puyoCheck() {  // 4개 이상 연결된 뿌요 터뜨리기
    int is_pop = 0;
    int visited[12][6] = { 0 };
    vector<pair<int, int>> pop_puyo_vec;
    for (int row = 0; row < 12; row++) {
        for (int col = 0; col < 6; col++) {
            if (visited[row][col]) continue;
            else visited[row][col] = 1;

            if (map[row][col] == '.') continue;

            vector<pair<int, int>> dfs_vec;
            stack<pair<int, int>> puyo_stack;
            puyo_stack.push({ row , col });
            dfs_vec.push_back({ row , col });
            while (!puyo_stack.empty()) {
                int y_node = puyo_stack.top().first;
                int x_node = puyo_stack.top().second;
                puyo_stack.pop();

                for (int i = 0; i < 4; i++) {
                    int y = y_node + next_y[i];
                    int x = x_node + next_x[i];

                    if (y < 0 || y >= 12) continue;
                    if (x < 0 || x >= 6) continue;
                    if (visited[y][x]) continue;

                    if (map[y][x] == map[row][col]) {
                        dfs_vec.push_back({ y , x });
                        puyo_stack.push({ y , x });
                        visited[y][x] = 1;
                    }
                }
            }

            if (dfs_vec.size() >= 4) {
                for (auto dfs_each : dfs_vec)
                    pop_puyo_vec.push_back(dfs_each);
                is_pop = 1;
            }
        }
    }

    for (auto pop_puyo : pop_puyo_vec)
        map[pop_puyo.first][pop_puyo.second] = '.';

    return is_pop;
}

void drop() {  // 중력
    for (int col = 0; col < 6; col++) {
        int row_top = 11;
        for (int row = 11; row >= 0; row--) {
            if (map[row][col] == '.') continue;
            if (row_top != row) {
                map[row_top][col] = map[row][col];
                map[row][col] = '.';
            }
            row_top--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    for (int i = 0; i < 12; i++) {
        cin >> input;
        for (int j = 0; j < 6; j++) {
            map[i][j] = input[j];
        }
    }

    int answer = 0;
    while (puyoCheck()) {
        drop();
        answer++;
    }
    cout << answer;

    return 0;
}
