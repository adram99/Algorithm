#include <iostream>
#include <algorithm>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

int abc[26] = { 0, };
char word[50][16];
int max_words = 0;

int readable(int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        int check = 1;
        for (int j = 4; j < strlen(word[i]); j++) {
            if (abc[word[i][j] - 'a'] == 0) {
                check = 0;
                break;
            }
        }
        if (check == 1) count++;
    }
    if (count > max_words) max_words = count;
    return max_words;
}

int dfs(int choose, int index, int N, int K) {
    if (choose >= K) {
        max_words = readable(N);
        return max_words;
    }
    for (int i = index; i < 26; i++) {
        if (abc[i] == 0) {
            abc[i] = 1;
            dfs(choose + 1, i, N, K);
            abc[i] = 0;
        }
    }
    return max_words;
}

int main() {
    int N, K;

    scanf("%d %d", &N, &K);

    abc['a' - 'a'] = 1;
    abc['c' - 'a'] = 1;
    abc['i' - 'a'] = 1;
    abc['n' - 'a'] = 1;
    abc['t' - 'a'] = 1;

    K -= 5;

    for (int i = 0; i < N; i++) {
        scanf("%s", &word[i]);
    }

    if (K < 0) {
        printf("0");
        return 0;
    }
    else if (K >= 21) {
        printf("%d", N);
        return 0;
    }

    if (K == 0) {
        printf("%d", readable(N));
        return 0;
    }

    printf("%d", dfs(0, 0, N, K));

    return 0;
}