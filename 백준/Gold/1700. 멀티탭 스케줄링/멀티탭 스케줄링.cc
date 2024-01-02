#include <iostream>
#pragma warning (disable:4996)
using namespace std;

int main() {
    int N, K;
    int hole[100];
    int nearby[100];
    int use[100];

    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        hole[i] = 0;
    }

    for (int i = 0; i < K; i++) {
        scanf("%d", &use[i]);
    }

    int count = 0;
    for (int i = 0; i < K; i++) {
        int already = 0;
        for (int j = 0; j < N; j++) {
            if (hole[j] == use[i]) {
                already = 1;
                break;
            }
        }
        if (already == 1) continue;


        int empty = 0;
        for (int j = 0; j < N; j++) {
            if (hole[j] == 0) {
                empty = 1;
                hole[j] = use[i];
                break;
            }
        }
        if (empty == 1) continue;
        

        for (int j = 0; j < N; j++) {
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