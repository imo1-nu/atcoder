#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<vector<ll>> dp(61, vector<ll> (200009, 0));

ll ans(ll x, ll y) {
    if (y == 0) return x;
    ll i;
    for (i = 61; (1 << i) > y; i--) {}
    return ans(dp[i][x], y - (1 << i));
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 1; i <= n; i++) {
        dp[0][i] = a[i - 1];
    }

    for (ll i = 1; i < 60; i++) {
        for (ll j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    
    // q回操作後の配列を出力
    for (ll j = 1; j <= n; j++) {
        cout << ans(j, q);
        if (j != n) cout << " ";
    }
    cout << endl;
}
