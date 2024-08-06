#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    if (S[0] != S[1] && S[1] == S[2]) cout << '1' << endl;
    else {
        for (int i = 0; i < S.length(); i++) {
            if (S[i] != S[i + 1]) {
                cout << i + 2 << endl;
                break;
            }
        }
    }
}
