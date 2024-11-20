#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> h(200001, 0);
vector<ll> B(200001, 1ll);
ll mod = 2147483647, b = 100ll;
ll Ha(ll l, ll r) {
    ll v = h[r + 1] - (h[l] * B[r - l + 1] % mod);
    if (v < 0) v += mod;
    return v;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q;
    string s;
    cin >> n >> q >> s;

    for (ll i = 1; i <= n; i++) {
        B[i] = B[i - 1] * b % mod;
        //cout << B[i] << endl;
    }
    
    for (ll i = 1; i <= n; i++) {
        h[i] = (h[i - 1] * b + (ll)(s[i - 1] - 'a' + 1)) % mod;
        //cout << h[i] << endl;
    }
    

    for (ll i = 0; i < q; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        bool ans = false;
        if (Ha(a, b) == Ha(c, d)) ans = true;
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
        //cout << Ha(a, b) << ' ' << Ha(c, d) << endl;
    }
    
}
