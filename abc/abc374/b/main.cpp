#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S, T;
    cin >> S >> T;
    int i;
    for (i = 0; i < S.length() && i < T.length(); i++) {
        if (S[i] != T[i]) {
            break;
        }
    }
    if (i == S.length() && i == T.length()) {
        cout << 0 << endl;
    } else {
        cout << i + 1 << endl;
    }
}
