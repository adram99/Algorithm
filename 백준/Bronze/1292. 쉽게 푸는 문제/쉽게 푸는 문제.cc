#include <iostream>
#pragma warning (disable:4996)
using namespace std;

int main() {
    int start, end, sum;
    sum = 0;

    scanf("%d %d", &start, &end);

    int num = 1;                              // 현재 수
    int count = 1;                            // 현재 수열 번호
    while (count <= end) {                    // 끝 지점까지만 수열 
        for (int i = 0; i < num; i++) {       // 현재 수(num) 만큼 수열 반복
            if (count >= start) sum += num;
            count++;
            if (count > end) break;           // 끝 지점 넘어가면 계산할 필요X
        }
        num++;
    }

    printf("%d", sum);

    return 0;
}
