#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    vector<ll> sa(n + 1), sb(n + 1);
    for (ll i = 1; i <= n; i++) {
        sa[i] = sa[i - 1] + a[i - 1];
        sb[i] = sb[i - 1] + b[i - 1];
    }
    auto itr1 = upper_bound(sa.begin(), sa.end(), x);
    auto itr2 = upper_bound(sb.begin(), sb.end(), y);
    ll ans = min(itr1 - sa.begin(), itr2 - sb.begin());
    ans = min(ans, n);
    cout << ans << endl;
}
