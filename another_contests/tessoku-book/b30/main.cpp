#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1000000007;

ll myPow(ll a, ll b) {
    if (b == 1) return a;
    ll c = myPow(a, b / 2);
    if (b % 2 == 0) return c * c % mod;
    return c * c % mod * a % mod;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w;
    cin >> h >> w;

    ll a = 1;
    ll b = 1;
    for (ll i = w; i <= h + w - 2; i++) {
        a = a * i % mod;
    }
    for (ll i = 1; i <= h - 1; i++) {
        b = b * i % mod;
    }

    ll ans = a * myPow(b, mod - 2) % mod;
    cout << ans << endl;
}
