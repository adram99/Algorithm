#include<iostream>
#include<vector>
using namespace std;

int ans;
int match[6][3]; // 경기 결과 (승 무 패)
int game[6][3];
vector<pair<int, int>> team;

int check() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            if (match[i][j] != game[i][j]) return 0;
        }
    } return 1;
}

void solution(int cnt) { // 6C2 = 15
    if (ans) return;  // 이미 가능한 결과, 더 볼 필요 없음
    if (cnt == 15) {
        if (check()) ans = 1; // 하나라도 일치하는 경우
        return;
    }

    int t1 = team[cnt].first;
    int t2 = team[cnt].second;

    // 승 패
    game[t1][0]++; game[t2][2]++;
    solution(cnt + 1);
    game[t1][0]--; game[t2][2]--;

    // 무승부
    game[t1][1]++; game[t2][1]++;
    solution(cnt + 1);
    game[t1][1]--; game[t2][1]--;

    // 패 승
    game[t1][2]++; game[t2][0]++;
    solution(cnt + 1);
    game[t1][2]--; game[t2][0]--;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int team1 = 0; team1 < 6; team1++) {
        for (int team2 = team1 + 1; team2 < 6; team2++)
            team.push_back({ team1, team2 });
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 3; k++) cin >> match[j][k];
        }
        ans = 0;
        solution(0);
        cout << ans << " ";
    }
}
