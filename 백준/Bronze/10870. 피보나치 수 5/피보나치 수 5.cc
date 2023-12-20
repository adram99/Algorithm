#include <iostream>
#pragma warning(disable:4996)

int memo[20];

// Memoization Fibonacci
int fibo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if(memo[n] != 0) return memo[n];
    return memo[n] = fibo(n - 2) + fibo(n - 1); // 피보나치 값을 저장
}

int main() {
    int checknum;

    scanf("%d", &checknum);

    printf("%d", fibo(checknum));

    return 0;
}