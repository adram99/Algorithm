#include <iostream>
using namespace std;

long long dec_num[1000001];

long long decreaseNum(int n) {
    if (n <= 10) return n;      // 한자리 수와 10은 자기 자신이 곧 n번째 수  
    if (n > 1022) return -1;    // 계산 결과 1022 이상은 존재X (9876543210을 초과하는 수 중에서는 존재X)

    int index = 0;
    for (int i = 0; i < 10; i++) {
        dec_num[i] = i;
        index++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < dec_num[i] % 10; j++) {
            dec_num[index] = dec_num[i] * 10 + j;
            index++;
        }
    }

    if (dec_num[n] == 0) return -1;
    else return dec_num[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    cout << decreaseNum(N);

    return 0;
}
