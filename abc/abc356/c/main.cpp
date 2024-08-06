#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> c(m);
    vector<char> r(m);
    vector<ll> a(m);
    for (ll i = 0; i < m; i++) {
        cin >> c[i];
        for (ll j = 0; j < c[i]; j++) {
            ll A, b;
            cin >> A;
            b = 1 << (A - 1);
            a[i] += b;
        }
        cin >> r[i];
    }

    ll ans = 0;
    for (ll i = 0; i < (1 << n); i++) {
        bool e = true;
        for (ll j = 0; j < m; j++) {
            bitset<30> d = i & a[j];
            if (d.count() >= k && r[j] == 'x' || d.count() < k && r[j] == 'o') e = false;
        }
        if (e) ans++;
    }
    
    cout << ans << endl;
}
