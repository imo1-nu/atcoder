#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 998244353;

ll myPow(ll a, ll b) {
    if (b == 0ll) return 1ll;
    ll c = myPow(a, b / 2ll);
    if (b % 2ll == 0ll) return c * c % mod;
    return c * c % mod * a % mod;
}

ll modinv(ll a) {
    return myPow(a, mod - 2);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    ll a = (n * n % mod - 2ll * n % mod + mod) % mod * modinv(n * n % mod) % mod;
    ll b = 2ll * modinv(n * n % mod) % mod;
    ll d = 1ll;
    for (ll i = 0; i < k; i++) {
        d = (a * d % mod + b) % mod;
    }
    ll sum = (n + 2ll) % mod * modinv(2ll) % mod;
    cout << (d + sum * (1 - d + mod) % mod) % mod << endl;
}
