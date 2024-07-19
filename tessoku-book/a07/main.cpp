#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll d, n;
    cin >> d >> n;
    vector<ll> lcnt(d + 1), rcnt(d + 1);
    for (ll i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        lcnt[l]++;
        rcnt[r]++;
    }

    vector<ll> dp(d + 1);
    for (ll i = 0; i < d; i++) {
        dp[i + 1] = dp[i] + lcnt[i + 1] - rcnt[i];
        cout << dp[i + 1] << endl;
    }
    
}
