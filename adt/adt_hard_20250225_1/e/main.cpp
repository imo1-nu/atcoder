#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    ll ans = 1;
    for (ll i = 1; i * i * i <= N; i++) {
        ll K = i * i * i;
        string s = to_string(K);
        bool ok = true;
        for (int j = 0; j < s.size() / 2; j++) {
            if (s[j] != s[s.size() - 1 - j]) {
                ok = false;
                break;
            }
        }
        if (ok) ans = K;
    }
    cout << ans << '\n';
}
