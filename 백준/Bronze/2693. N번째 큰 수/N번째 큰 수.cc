#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int arr[10];

int main() {
    int testcase;

    scanf("%d", &testcase);

    while (testcase > 0) {
        for (int i = 0; i < 10; i++) {
            scanf("%d", &arr[i]);
        }

        sort(arr, arr + 10);             // algorithm 헤더 sort함수. 오름차순 정렬
        printf("%d\n", arr[7]);          // 뒤에서 3번째로 큰 수(전체 수 10일 때)

        testcase--;
    }
    return 0;
}