#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans(ll x, ll y, vector<vector<ll>>& dp) {
    if (y == 0) return x;
    ll i;
    for (i = 30; (1 << i) > y; i--) {}
    return ans(dp[i][x], y - (1 << i), dp);
    
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(31, vector<ll>(n + 1));
    for (ll i = 1; i <= n; i++) {
        dp[0][i] = i;
    }

    vector<ll> pow10(6, 1ll);
    for (ll i = 1; i < 6; i++) {
        pow10[i] = pow10[i - 1] * 10;
    }

    for (ll i = 0; i <= n; i++) {
        ll a = 0;
        for (ll j = 0; j < 6; j++) {
            a += i / pow10[j] % 10;
        }
        dp[0][i] = i - a;
        //cout << i << ' ' << dp[0][i] << endl;
    }
    
    
    
    for (ll i = 1; i < 31; i++) {
        for (ll j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    
    for (ll i = 1; i <= n; i++) {
        cout << ans(i, k, dp) << endl;
    }
    
}
