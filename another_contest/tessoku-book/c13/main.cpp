#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1000000007;

ll myPow(ll a, ll b) {
    if (b == 0) return 1ll;
    ll c = myPow(a, b / 2);
    if (b % 2 == 0) return c * c % mod;
    return c * c % mod * a % mod;
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, p;
    cin >> n >> p;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        ll b;
        cin >> b;
        a[i] = b % mod;
    }
    map<ll, ll> count;
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (p == 0) {
                ans += i;
            }
        }
        else {
            ll inv = p * myPow(a[i], mod - 2) % mod;
            ans += count[inv];
        }
        count[a[i]]++;
    }
    cout << ans << endl;
    
    /*sort(a.begin(), a.end());
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (p == 0) {
                ans += n - 1 - i;
            }
            continue;
        }
        ll inv = (p * myPow(a[i], mod - 2)) % mod;
        auto itr1 = lower_bound(a.begin(), a.end(), inv);
        auto itr2 = lower_bound(a.begin(), a.end(), inv + 1);
        if (i < itr1 - a.begin()) ans += itr2 - itr1;
        else if (i < itr2 - a.begin()) ans += itr2 - a.begin() - 1 - i;
    }
    cout << ans << endl;*/
}
