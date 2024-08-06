#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), s(n + 1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (ll i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }

    ll l = 0, r = 2e14 + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        auto itr = lower_bound(a.begin(), a.end(), mid);
        ll cnt = a.end() - itr;
        ll sum = cnt * mid + s[n - cnt];
        if (sum > m) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (l == 2e14) cout << "infinite" << endl;
    else cout << l << endl;
}
