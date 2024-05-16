#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H, W, N, M;
    cin >> H >> W >> N >> M;

    int h, w;
    if (H % (N + 1) == 0) h = H / (N + 1);
    else h = H / (N + 1) + 1;
    if (W % (M + 1) == 0) w = W / (M + 1);
    else w = W / (M + 1) + 1;


    cout << h * w;

    return 0;
}