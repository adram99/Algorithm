#include <iostream>
#pragma warning (disable:4996)
using namespace std;

int main() {
    int N, S;
    int arr[100000];

    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int right = 0, left = 0;                                 // 왼쪽 인덱스, 오른쪽 인덱스 (투 포인터)
    int min = 100000001;
    int count = 0;
    int sum = 0;

    while (left < N) {
        if (sum >= S) {                                      // 합이 S와 같거나 클 때
            if (min > (right - left)) min = (right - left);  // 최소 수열 길이 업데이트
            sum -= arr[left];                                
            left++;                                          // 왼쪽 포인터의 수를 빼고 오른쪽으로 이동
        }
        else if (sum < S && right < N) {                     // 합이 S보다 작고, 오른쪽 인덱스가 더 오른쪽으로 이동 가능할 때
            sum += arr[right];                               // 현재 오른쪽 포인터의 수를 더하고 포인터를 오른쪽으로 이동
            right++;
        }
        else if (right == N) break;                          // 오른쪽 포인터가 끝을 넘으면 종료
    }
    if (min == 100000001) printf("0");                       // 최소 길이가 변함이 없으면 다 합해도 S보다 작은 경우
    else printf("%d", min);

    return 0;
}
