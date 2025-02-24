#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll modPow(ll a, ll b, ll mod) {
    if (b == 0) return 1ll;
    ll c = modPow(a, b / 2, mod);
    if (b % 2 == 0) return c * c % mod;
    return c * c % mod * a % mod;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, K, M;
    cin >> N >> K >> M;
    ll mod = 998244353;
    K %= mod - 1;
    M %= mod;
    if (M == 0) {
        cout << 0 << '\n';
        return 0;
    }
    ll r = modPow(K, N, mod - 1);
    ll ans = modPow(M, r, mod);
    cout << ans << '\n';
}
