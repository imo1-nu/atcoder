#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int s = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '.') s = i + 1;
    }
    cout << S.substr(s) << endl;
}
