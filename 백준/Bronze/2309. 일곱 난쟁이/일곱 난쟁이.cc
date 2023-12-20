#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main() {
    int dwarves[9];
    int faker1 = 0 , faker2 = 0;
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        scanf("%d", &dwarves[i]);
        sum += dwarves[i];         // 9난쟁이 합
    }

    sort(dwarves, dwarves+9);      // 오름차순 정렬 (algorithm헤더 sort함수)

    for (int i = 0; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (sum - (dwarves[i] + dwarves[j]) == 100) {  // 임의의 두 난장이를 뺐을 때 100이면 조건 성립
                faker1 = i;
                faker2 = j;
                i = 9;
                break;
            }
        }
    }

    for (int i = 0; i < 9; i++) {                  // 걸러낸 난쟁이 제외 모두 출력
        if (i == faker1 || i == faker2) continue;

        printf("%d\n", dwarves[i]);
    }

    return 0;
}