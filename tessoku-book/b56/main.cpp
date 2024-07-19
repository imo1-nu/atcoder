#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> h(200001, 0);
vector<ll> h2(200001, 0);
vector<ll> B(200001, 1ll);
ll mod = 2147483647, b = 100ll;
ll n;

ll Ha(ll l, ll r) {
    ll v = h[r + 1] - (h[l] * B[r - l + 1] % mod);
    if (v < 0) v += mod;
    return v;
}

ll Ha2(ll l, ll r) {
    ll a = l;
    l = n - 1 - r;
    r = n - 1 - a;
    ll v = h2[r + 1] - (h2[l] * B[r - l + 1] % mod);
    if (v < 0) v += mod;
    return v;
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll q;
    string s;
    cin >> n >> q >> s;
    string s2(s.rbegin(), s.rend());

    for (ll i = 1; i <= n; i++) {
        B[i] = B[i - 1] * b % mod;
        //cout << B[i] << endl;
    }
    
    for (ll i = 1; i <= n; i++) {
        h[i] = (h[i - 1] * b + (ll)(s[i - 1] - 'a' + 1)) % mod;
        //cout << h[i] << endl;
    }
    for (ll i = 1; i <= n; i++) {
        h2[i] = (h2[i - 1] * b + (ll)(s2[i - 1] - 'a' + 1)) % mod;
        //cout << h[i] << endl;
    }

    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        bool ans = false;
        if (Ha(l, r) == Ha2(l, r)) ans = true;
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
