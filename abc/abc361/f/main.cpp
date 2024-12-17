#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> pfact(ll x) {
    vector<ll> res;
    for (ll i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            res.push_back(i);
            x /= i;   
        }
    }
    if (x != 1) res.push_back(x);
    return res;
}

ll safe_pow(ll a, ll b) {
    ll res = 1;
    for (int i = 0; i < b; ++i) {
        if (res > LLONG_MAX / a) return LLONG_MAX;
        res *= a;
    }
    return res;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;

    ll ans = 1;
    for (int b= 2; b < 60; ++b) {
        ll l = 1, r = 2e9;
        while (l + 1 < r) {
            ll m = (l + r) / 2;
            if (safe_pow(m, b) <= N) l = m;
            else r = m;
        }

        vector<ll> pf = pfact(b);
        bool same = false;
        for (ll i = 1; i < (ll)pf.size(); ++i) {
            if (pf[i] == pf[i - 1]) {
                same = true;
                break;
            }
        }
        if (same) continue;
        if (pf.size() % 2 == 1) ans += l - 1;
        else ans -= l - 1;
    }
    cout << ans << endl;
}
