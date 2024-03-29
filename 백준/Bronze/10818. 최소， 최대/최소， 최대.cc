#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numcase, num, min = 1000000, max = -1000000;

    cin >> numcase;

    while (numcase > 0) {
        cin >> num;
        if (num < min) min = num;
        if (num > max) max = num;
        numcase--;
    }

    cout << min << " " << max;
    return 0;
}