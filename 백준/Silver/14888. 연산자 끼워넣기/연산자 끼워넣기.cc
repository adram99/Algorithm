#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int* num;
int oper[4];
int n, res_max = -1000000001, res_min = 1000000001;

void backtracking(int now_res, int next_index) {
    if (next_index == n) {                       // 계산 완료 후 최대 최소 비교
        res_max = max(res_max, now_res);
        res_min = min(res_min, now_res);
        return;
    }
    if (oper[0] > 0) {                           // +를 선택
        oper[0]--;                               // 연산자를 사용했기 때문에 개수 감소
        backtracking(now_res + num[next_index], next_index + 1);
        oper[0]++;                               // 백트래킹 계산후 반환 받았기 때문에 다시 개수 증가(원래 상태)
    }
    if (oper[1] > 0) {                           // -를 선택
        oper[1]--;
        backtracking(now_res - num[next_index], next_index + 1);
        oper[1]++;
    }
    if (oper[2] > 0) {                           // *를 선택
        oper[2]--;
        backtracking(now_res * num[next_index], next_index + 1);
        oper[2]++;
    }
    if (oper[3] > 0) {                           // /를 선택
        oper[3]--;
        backtracking(now_res / num[next_index], next_index + 1);
        oper[3]++;
    }
}

int main() {
    scanf("%d", &n);
    num = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &oper[i]);
    }

    backtracking(num[0], 1);

    printf("%d\n%d", res_max, res_min);

    return 0;
}
