#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count = 0;
    long long A, B;
    cin >> A >> B;

    while (1) {
        if (B == A) {
            cout << count + 1;
            break;
        }
        else if (B < A) {
            cout << -1;
            break;
        }

        if (B % 10 == 1) {
            B = B / 10;
            count++;
        }
        else if (B % 2 == 0) {
            B = B / 2;
            count++;
        }
        else {
            cout << -1;
            break;
        }
    }

    return 0;
}