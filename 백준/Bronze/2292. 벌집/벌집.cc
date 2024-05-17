#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int room = 1, layer = 1;
    while (1) {
        if (N <= room) break;
        room += 6 * layer;
        layer++;
    }
    cout << layer;

    return 0;
}