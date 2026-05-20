#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    ll ans = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != 'C') continue;
        ans += min(i + 1, (int)S.length() - i);
    }
    cout << ans << endl;
}
