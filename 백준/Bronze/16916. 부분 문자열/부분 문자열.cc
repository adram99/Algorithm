#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    string S, P;
    cin >> S >> P;
    if (strstr((char*)S.c_str(), (char*)P.c_str()) == NULL)
        cout << 0;
    else
        cout << 1;
    return 0;
}