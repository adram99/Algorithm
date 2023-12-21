#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// gcd : greatest common divisor = 최대공약수
// lcm : largest common multiple = 최소공배수

int findGCD(int num1, int num2) {            // 유클리드 호제법으로 gcd찾기
    if (num1 < num2) {                       // mod전 순서 조정
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    int val;
    while (num2 != 0) {
        val = num1 % num2;
        num1 = num2;
        num2 = val;
    }
    return num1;
}

int main() {
    int num1, num2;

    scanf("%d %d", &num1, &num2);

    int gcd = findGCD(num1, num2);
    printf("%d\n", gcd);
    printf("%d", ((num1 * num2) / gcd));    // 최소공배수 = 두 수의 곱 / 두 수의 최대공약수
    
    return 0;
}