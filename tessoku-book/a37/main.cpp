#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m, b;
    cin >> n >> m >> b;
    vector<ll> a(n), c(m);
    ll ans = b * n * m;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i] * m;
    }
    for (ll i = 0; i < m; i++) {
        cin >> c[i];
        ans += c[i] * n;
    }
    cout << ans << endl;
}
