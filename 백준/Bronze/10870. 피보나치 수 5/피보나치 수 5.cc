#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int memo[20];

// Memoization Fibonacci
int fibo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if(memo[n] != 0) return memo[n];            // 현재 피보나치값이 저장되어 있을 땐 계산없이 저장된 값 불러옴
    return memo[n] = fibo(n - 2) + fibo(n - 1); // 피보나치 값을 저장
}

int main() {
    int checknum;

    scanf("%d", &checknum);

    printf("%d", fibo(checknum));

    return 0;
}
