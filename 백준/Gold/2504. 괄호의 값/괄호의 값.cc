#include <iostream>
#include <stack>
#pragma warning (disable:4996)
using namespace std;

string str;
stack<char> bracket;
int res, ans;        // 곱셈이 섞여있어 임시값 계산 후 최종값에 더하는 방식

void calculate() {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {                // '('는 무조건 x2
            bracket.push('(');
            res *= 2;
        }
        else if (str[i] == '[') {           // '['는 무조건 x3
            bracket.push('[');
            res *= 3;
        }
        else if (str[i] == ')') {           // ')'는 계산값을 최종값에 더하고 임시값/2
            if (bracket.empty() || bracket.top() != '(') { // 식이 잘못된 경우
                ans = 0;
                break;
            }
            if (str[i - 1] == '(') ans += res;

            res /= 2;
            bracket.pop();
        }
        else if (str[i] == ']') {           // ']'는 계산값을 최종값에 더하고 임시값/3
            if (bracket.empty() || bracket.top() != '[') { // 식이 잘못된 경우
                ans = 0;
                break;
            }
            if (str[i - 1] == '[') ans += res;

            res /= 3;
            bracket.pop();
        }
    }
}

int main() {
    cin >> str;

    res = 1, ans = 0;
    calculate();

    if (!bracket.empty()) printf("0");   // 스택에 남은게 있으면 오류
    else printf("%d", ans);

    return 0;
}