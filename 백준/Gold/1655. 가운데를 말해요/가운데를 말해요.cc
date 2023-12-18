#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int>> leftheap; // 왼쪽 최대 확인용 힙(중간값 포함)
priority_queue<int, vector<int>, greater<int>> rightheap; // 오른쪽 최소 확인용 힙

int main() {
    int count, num; // count : 숫자 개수, num : 숫자

    scanf("%d", &count);

    while (count > 0) {
        scanf("%d", &num);

        // 힙에 저장
        if (leftheap.empty() && rightheap.empty()) // 시작(힙에 저장된 값이 없을 때)
            leftheap.push(num);
        else if (leftheap.size() == rightheap.size()) // 왼쪽 오른쪽 힙에 들어있는 숫자 개수가 같을때 왼쪽 우선
            leftheap.push(num);
        else rightheap.push(num);

        // 왼쪽 힙 최대값 < 오른쪽 힙 최소값  조건 유지
        if (!leftheap.empty() && !rightheap.empty()) {
            if (leftheap.top() > rightheap.top()) {
                int left_top, right_top;

                left_top = leftheap.top();
                right_top = rightheap.top();

                leftheap.pop();
                rightheap.pop();

                leftheap.push(right_top);
                rightheap.push(left_top);
            }
        }

        printf("%d\n", leftheap.top()); // 중간값 출력
        count--; // 다음
    }
    return 0;
}