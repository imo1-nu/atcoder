#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long;

#define mod 998244353ll

ll func(ll a, ll b) {
    if (b == 0) return 1;
    ll c = func(a, b / 2);
    if (b % 2 == 0) return c * c % mod;
    else return c * c % mod * a % mod;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    ll k;
    for (k = 1; k <= n; k *= 10) {}
    k %= mod;
    ll p = n % mod;

    ll ans = p * (func(k, n) - 1) % mod * func(k - 1, mod - 2) % mod;
    
    cout << ans << endl;

    //cout << func(2, 2) << endl;
}
