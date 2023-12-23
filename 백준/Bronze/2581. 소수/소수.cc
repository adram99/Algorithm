#include <iostream>
#pragma warning (disable:4996)
using namespace std;

int main() {
    int start, end, sum, min;
    sum = 0;
    min = 0;

    scanf("%d %d", &start, &end);

    for (int i = start; i <= end; i++) {
        int checker = 0;                    // 소수면 0, 아니면 1
        if (i == 1) continue;               // 1은 소수X
        for (int j = 2; j * j <= i; j++) {  // 약수가 있는지 확인(에라토스테네스의 체)
            if (i % j == 0) {
                checker = 1;
                break;
            }
        }
        if (checker == 0) {                 // 현재 수(i)가 소수일 때
            if (min == 0) min = i;
            sum += i;
        }
    }
    
    if(sum == 0 && min == 0) printf("-1");
    else printf("%d\n%d", sum, min);

    return 0;
}
