#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int main() {
    int numcase, num, min, max;
    min = 1000000;
    max = -1000000;

    cin >> numcase;

    while (numcase > 0) {
        cin >> num;
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
        numcase--;
    }

    printf("%d %d", min, max);
    return 0;
}