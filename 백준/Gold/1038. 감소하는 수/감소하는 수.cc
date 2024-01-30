#include <iostream>
using namespace std;

long long dec_num[1000001];

long long decreaseNum(int n) {
    if (n <= 10) return n;
    if (n > 1022) return -1;

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