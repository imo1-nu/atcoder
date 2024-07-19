#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    set<ll> s;
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll a, x;
        cin >> a >>  x;
        if (a == 1) {
            s.insert(x);
            s.insert(-x);
        }
        else {
            ll x1, x2;
            auto itr1 = s.lower_bound(x);
            if (itr1 == s.end()) x1 = 1000000000000ll;
            else x1 = *itr1;
            auto itr2 = s.lower_bound(-x);
            if (itr2 == s.end()) x2 = -1000000000000ll;
            else x2 = -*itr2;
            ll ans = min(x1 - x, x - x2);
            if (ans >= 100000000000ll) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
    
}
