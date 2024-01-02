#include <iostream>
#pragma warning (disable:4996)
using namespace std;

int main() {
    int N, K;
    int hole[100];                      // 구멍
    int nearby[100];                    // 같은 용품을 다시 사용하기까지 기다리는 시간
    int use[100];                       // 사용할 용품

    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        hole[i] = 0;
    }

    for (int i = 0; i < K; i++) {
        scanf("%d", &use[i]);
    }

    int count = 0;                      // 플러그 빼는 횟수(= 용품 교체 횟수)
    for (int i = 0; i < K; i++) {
        int already = 0;                // 이미 꼽힌 용품인지 확인
        for (int j = 0; j < N; j++) {
            if (hole[j] == use[i]) {
                already = 1;
                break;
            }
        }
        if (already == 1) continue;


        int empty = 0;                  // 구멍이 비었는지 확인
        for (int j = 0; j < N; j++) {
            if (hole[j] == 0) {
                empty = 1;
                hole[j] = use[i];
                break;
            }
        }
        if (empty == 1) continue;
        

        for (int j = 0; j < N; j++) {   // 다음 사용이 없거나 가장 길게 기다려야하는 용품 확인
            int next = 0;
            for (int k = i+1; k < K; k++) {
                if (hole[j] == use[k]) break;
                next++;
            }
            nearby[j] = next;
        }
        int change = 0;
        for (int j = 0; j < N; j++) {
            if (nearby[change] < nearby[j]) change = j;
        }
        hole[change] = use[i];
        count++;                     
    }
    printf("%d", count);
    return 0;
}
