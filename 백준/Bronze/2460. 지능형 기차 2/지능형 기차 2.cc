#include <iostream>
#pragma warning(disable:4996)
using namespace std;

const int station = 10;

int main() {
    int outnum, innum, sum, max;
    sum = 0;
    max = 0;

    for (int i = 0; i < station; i++) {
        scanf("%d %d", &outnum, &innum);
        sum -= outnum;                   // 내릴 때 확인
        if (sum > max) {
            max = sum;
        }
        sum += innum;                    // 탈 때 확인
        if (sum > max) {
            max = sum;
        }
        
    }
    printf("%d", max);
    return 0;
}
