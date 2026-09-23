#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S, T;
    cin >> S;
    for (int i = 0; i < 2 * S.length() - 1; i++) {
        if (i % 2 == 0) T.push_back(S[i / 2]);
        else T.push_back('o');
    }
    cout << T << endl;
}
