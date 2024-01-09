#include <stdio.h>
#pragma warning(disable:4996)

int main() {

    int n, k;
    int divisor_cnt = 0;

    scanf("%d %d", &n, &k); // 입력

    int i;
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {            // 약수 확인
            divisor_cnt++;           // 작은순부터 약수 번호 증가
            if (divisor_cnt == k) {
                printf("%d", i);
                break;               // k번째로 작은 약수 확인 -> 종료
            }
        }
        if (i == n) printf("0");     // k번째 약수 존재X
    }

    return 0;
}