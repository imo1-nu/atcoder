#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> c(a[n - 1] + 1, 0);
    for (ll i = 0; i < n; i++) {
        c[a[i]]++;
    }

    ll ans = - n - c[a[0]] * (c[a[0]] - 1) / 2;
    for (ll i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) continue;
        ans -= c[a[i]] * (c[a[i]] - 1) / 2;
    }
    

    for (ll i = 1; i <= a[n - 1]; i++) {
        c[i] += c[i - 1];
        //cout << c[i];
        //if (i < a[n - 1]) cout << ' ';
        //else cout << endl;
    }

    ll m = a[n - 1];
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        ll b, f = a[i] - 1;
        if (i > 0) {
            if (a[i] == a[i - 1]) {
                ans += cnt;
                continue;
            }
        }
        cnt = 0;
        for (ll j = 1; f <= m; j++) {
            cnt += (c[min(a[n - 1], f + a[i])] - c[f]) * j;
            f += a[i];
        }
        ans += cnt;
    }
    cout << ans << endl;
}
