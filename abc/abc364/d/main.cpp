#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), b(q), k(q);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < q; i++) {
        cin >> b[i] >> k[i];
    }
    sort(a.begin(), a.end());
    for (ll i = 0; i < q; i++) {
        ll d1 = 200000000, d2 = -1;
        while (d1 - d2 > 1) {
            ll m = (d1 + d2) / 2;
            ll l = lower_bound(a.begin(), a.end(), b[i] - m) - a.begin();
            ll r = upper_bound(a.begin(), a.end(), b[i] + m) - a.begin();
            if (r - l >= k[i]) {
                d1 = m;
            } else {
                d2 = m;
            }
        }
        cout << d1 << endl;
    }
    
}
