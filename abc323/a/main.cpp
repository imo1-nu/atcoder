#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int ans = 1;
    for (int i = 1; i < 16; i+=2) {
        if (S[i] == '1') ans = 0;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
