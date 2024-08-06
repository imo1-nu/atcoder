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
    ll log = 27;
    ll ans = 0;
    for (ll i = 0; i < log; i++) {
        vector<ll> s(n + 1);
        for (ll j = 1; j <= n; j++) {
            s[j] = s[j - 1] ^ (a[(j - 1)] >> i & 1);
        }
        vector<ll> cnt(2);
        for (ll j = 0; j <= n; j++) {
            cnt[s[j]]++;
        }
        ans += (ll) (1 << i) * cnt[0] * cnt[1];
    }
    for (ll i = 0; i < n; i++) {
        ans -= a[i];
    }
    cout << ans << endl;
}
