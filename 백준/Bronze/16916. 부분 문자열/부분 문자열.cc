#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> pi;   // 일치하는 접두사, 접미사 개수

void checkPi(string s) {
    int pi_size = s.size();
    pi.resize(pi_size, 0);
    for (int i = 1, match = 0; i < pi_size; i++) {
        while ((match > 0) && (s[i] != s[match])) match = pi[match - 1];
        if (s[i] == s[match]) pi[i] = ++match;
    }
}

int kmp(string s, string p) {   // KMP 알고리즘 : 문자열 탐색 알고리즘
    int res = 0;
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == p.size() - 1) {
                res = 1;
                break;
            }
            else j++;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S, P;
    cin >> S >> P;

    checkPi(P);

    cout << kmp(S, P);

    return 0;
}
