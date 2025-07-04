#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S, T;
    cin >> S >> T;
    set<char> V;
    for (auto t : T) V.insert(t);
    bool ans = true;
    for (int i = 0; i < S.length() - 1; i++) {
        if (S[i + 1] >= 'A' && S[i + 1] <= 'Z' && !V.count(S[i])) ans = false;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
