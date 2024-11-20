#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, W;
    cin >> n >> W;
    vector<ll> w(n), v(n);
    for (ll i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    
    ll dp[n + 1][W + 1];
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= W; j++) {
            dp[i][j] = 0;
        }
        
    }
    
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= W; j++) {
            if (dp[i + 1][j] < dp[i][j]) dp[i + 1][j] = dp[i][j];
            ll nw = j + w[i];
            if (nw <= W && dp[i + 1][nw] < dp[i][j] + v[i]) dp[i + 1][nw] = dp[i][j] + v[i];
        }
    }
    cout << dp[n][W] << endl;
    
}
