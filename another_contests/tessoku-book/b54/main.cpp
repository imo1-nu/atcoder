#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    map<ll, ll> m;
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m[a]++;
    }
    
    ll ans;
    for (auto [key, value] : m) {
        ans += value * (value - 1) / 2;
    }
    
    cout << ans << endl;
}
