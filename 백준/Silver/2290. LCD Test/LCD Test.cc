#include <iostream>
#include <string>
using namespace std;

void lcd(int s, string num) {
    for (int i = 1; i <= (s * 2 + 3); i++) {
        for (int j = 0; j < num.size(); j++) {
            int now = num[j] - 48;     // 현재 숫자
            if (i == 1) {   // 맨 위 가로
                cout << " ";
                if (now == 0 || now == 2 || now == 3 || now == 5 || now == 6 || now == 7 || now == 8 || now == 9) {
                    for (int k = 0; k < s; k++) cout << "-";
                }
                else for (int k = 0; k < s; k++) cout << " ";
                cout << "  ";
            }
            else if (i > 1 && i <= s + 1) {
                if (now == 0 || now == 4 || now == 8 || now == 9) {
                    cout << "|";
                    for (int k = 0; k < s; k++) cout << " ";
                    cout << "|";
                }
                else if (now == 1 || now == 2 || now == 3 || now == 7) {
                    cout << " ";
                    for (int k = 0; k < s; k++) cout << " ";
                    cout << "|";
                }
                else if (now == 5 || now == 6) {
                    cout << "|";
                    for (int k = 0; k < s; k++) cout << " ";
                    cout << " ";
                }
                cout << " "; 
            }
            else if (i == s + 2) {   // 중간 가로
                cout << " ";
                if (now == 2 || now == 3 || now == 4 || now == 5 || now == 6 || now == 8 || now == 9) {
                    for (int k = 0; k < s; k++) cout << "-";
                }
                else for (int k = 0; k < s; k++) cout << " ";
                cout << "  ";
            }
            else if (i > s + 2 && i <= s * 2 + 2) {
                if (now == 0 || now == 6 || now == 8) {
                    cout << "|";
                    for (int k = 0; k < s; k++) cout << " ";
                    cout << "|";
                }
                else if (now == 1 || now == 3 || now == 4 || now == 5 || now == 7 || now == 9) {
                    cout << " ";
                    for (int k = 0; k < s; k++) cout << " ";
                    cout << "|";
                }
                else if (now == 2) {
                    cout << "|";
                    for (int k = 0; k < s; k++) cout << " ";
                    cout << " ";
                }
                cout << " ";
            }
            else if (i == s * 2 + 3) {   // 맨 아래 가로
                cout << " ";
                if (now == 0 || now == 2 || now == 3 || now == 5 || now == 6 || now == 8 || now == 9) {
                    for (int k = 0; k < s; k++) cout << "-";
                }
                else for (int k = 0; k < s; k++) cout << " ";
                cout << "  ";
            }
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S;
    string number;
    cin >> S >> number;
    
    lcd(S, number);

    return 0;
}
