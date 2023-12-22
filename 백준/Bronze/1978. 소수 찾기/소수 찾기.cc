#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int findPrimeNumber(int num) {
    if (num < 2) return 0;           // 2보다 작은 정수는 소수X
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return 0;  // 1과 본인을 제외하고 약수가 있으면 소수X
    }
    return 1;                        // 1과 본인을 제외하고 약수가 없으면 소수O
}

int main() {
    int testcase, num, count;
    count = 0;

    scanf("%d", &testcase);

    while (testcase > 0) {
        scanf("%d", &num);

        if (findPrimeNumber(num)) count++;

        testcase--;
    }

    printf("%d", count);

    return 0;
}