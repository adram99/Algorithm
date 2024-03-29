#include <iostream>
using namespace std;

int N;

void findPrime(int num, int cnt) {
    int p_check = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            p_check = 0;
            return;
        }
    }
    if (cnt == N && p_check == 1) {
        cout << num << "\n";
        return;
    }

    for (int i = 1; i <= 9; i++) findPrime(num * 10 + i, cnt + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    findPrime(2, 1);
    findPrime(3, 1);
    findPrime(5, 1);
    findPrime(7, 1);

    return 0;
}