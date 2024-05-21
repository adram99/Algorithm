#include <iostream>
using namespace std;

string input;
int check[26], max_check;
char abc;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;

    int index;
    for (int i = 0; i < input.size(); i++) {
        abc = input[i];
        index = abc - 'A';
        if (index < 32) check[index]++;
        else check[index - 32]++;
    }

    int cnt = 1, max_index = 0;
    for (int i = 0; i < 26; i++) {
        if (max_check == check[i]) cnt++;
        if (max_check < check[i]) {
            max_check = check[i];
            max_index = i;
            cnt = 1;
        }
    }
    
    if (cnt > 1) cout << "?";
    else cout << (char)(max_index + 'A');

    return 0;
}