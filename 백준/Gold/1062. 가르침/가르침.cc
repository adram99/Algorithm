#include <iostream>
#include <algorithm>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

int abc[26] = { 0, }; // 알파벳 조합 체크용
char word[50][16];    // 주어진 단어
int max_words = 0;    // 읽어지는 단어의 최대 개수

int readable(int N) {                           // 조합된 알파벳(체크된 abc[])로 읽을 수 있는 단어 확인
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

int dfs(int choose, int index, int N, int K) {  // dfs로 알파벳 조합
    if (choose >= K) {
        return readable(N);
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

    cin >> N >> K;

    abc['a' - 'a'] = 1;      // a, c, i, n, t는 무조건 나오므로 미리 체크
    abc['c' - 'a'] = 1;
    abc['i' - 'a'] = 1;
    abc['n' - 'a'] = 1;
    abc['t' - 'a'] = 1;

    K -= 5;                  // dfs에서 a,c,i,n,t를 제외하고 조합하기 위해 K - 5

    for (int i = 0; i < N; i++) {
        cin >> word[i];
    }

    if (K < 0) {             // a,c,i,n,t를 뺀 K값이 0 이하면 읽을 수 있는 단어 없음
        cout << 0;
        return 0;
    }
    else if (K >= 21) {      // a,c,i,n,t를 뺀 K값이 21 이상이면 모든 단어 다 읽기 가능
        cout << N;
        return 0;
    }

    if (K == 0) {            // a,c,i,n,t를 뺀 K값이 0이면 a,c,i,n,t만 포함된 단어만 읽음
        cout << readable(N);
        return 0;
    }

    cout << dfs(0, 0, N, K);

    return 0;
}