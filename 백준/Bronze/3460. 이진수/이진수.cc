#include <stdio.h>
#pragma warning(disable:4996)

int main() {
    int testcase, num;

    scanf("%d", &testcase);

    while (testcase > 0) {
        int one_checker = 0;
        scanf("%d", &num);
        while (num != 0) {                                // 2진수로 변환하면서 1위치 찾기
            if (num % 2 == 1) printf("%d ", one_checker); // 1위치 출력(낮은 위치부터)

            num /= 2;                                     // 다음 자리 계산
            one_checker++;
        }
        printf("\n");
        testcase--;
    }
    return 0;
}