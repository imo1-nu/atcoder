#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q;
    cin >> n >> q;
    vector<int> a(n), s(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    
    vector<ll> ans(q);
    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        ans[i] = s[r] - s[l - 1];
    }

    for (ll i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    
    
}
