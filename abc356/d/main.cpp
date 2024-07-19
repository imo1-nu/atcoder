#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m;
    cin >> n;
    cin >> m;
    ll ans = 0;
    vector<ll> cnt(64, 0);
    ll a1 = 1;
    for (ll i = 1; i < 62; i++) {
        cnt[i] = n / (a1 << i) * (a1 << (i - 1));
        ll a = n % (a1 << i);
        ll b = a - (a1 << (i - 1)) + 1;
        if (b > 0) cnt[i] += b;
    }

    for (ll i = 1; i < 62; i++) {
        ll b = (a1 << (i - 1)) & m;
        if (b != 0) ans = (ans + cnt[i]) % 998244353;
    }
    cout << ans << endl;

}
