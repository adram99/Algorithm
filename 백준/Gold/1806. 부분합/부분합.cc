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

    int right = 0, left = 0;
    int min=100000001;
    int count = 0;
    int sum = 0;

    while (left < N) {
        if (sum >= S) {
            if (min > (right - left)) min = (right - left);
            sum -= arr[left];
            left++;
        }
        else if (sum < S && right < N) {
            sum += arr[right];
            right++;
        }
        else if (right == N) break;
    }
    if (min == 100000001) printf("0");
    else printf("%d", min);

    return 0;
}