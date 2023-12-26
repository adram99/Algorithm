#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int main() {
    int H, W, sum = 0;
    int left_max = 0, right_max = 0;
    int* block;

    scanf("%d %d", &H, &W);
    block = new int[W];
    for (int i = 0; i < W; i++) {
        scanf("%d", &block[i]);
    }

    for (int i = 0; i < W; i++) {
        if (i == 0 || i == W-1) continue;

        int side = i;
        left_max = 0;
        for (side; side >= 0; side--) {            // 현재 블록 기준으로 왼편의 최대 블록
            left_max = max(block[side], left_max);
        }

        right_max = 0;
        for (side = i; side < W; side++) {         // 현재 블록 기준으로 오른편의 최대 블록
            right_max = max(block[side], right_max);
        }

        if (min(right_max, left_max) - block[i] > 0) {    // 현재 블록 보다 높은 블록이 양쪽으로 있어야함
            sum += (min(right_max, left_max) - block[i]); // 현재 블록 - 양옆 최대 블록 중 작은 블록
        }
    }

    printf("%d", sum);

    return 0;
}