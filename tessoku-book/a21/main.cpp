#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<ll> p(n), a(n);
    for (ll i = 0; i < n; i++) {
        cin >> p[i] >> a[i];
        p[i]--;
    }
    
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));

    for (ll i = 0; i <= n; i++) {
        for (ll j = n; j - i > -1; j--) {
            if (i - 1 >= 0) dp[i][j] = dp[i - 1][j];
            if (j + 1 <= n && dp[i][j] < dp[i][j + 1]) dp[i][j] = dp[i][j + 1];
            if (i - 1 >= 0 && i <= p[i - 1] && p[i - 1] < j) dp[i][j] = dp[i - 1][j] + a[i - 1];
            if (j + 1 <= n && i <= p[j] && p[j] < j && dp[i][j] < dp[i][j + 1] + a[j]) dp[i][j] = dp[i][j + 1] + a[j];
        }
    }
    
    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        ans = max(ans, dp[i][i]);
    }
    cout << ans << endl;

    /*for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= n; j++) {
            cout << dp[i][j];
            if (j < n) cout << ' ';
            else cout << endl;
        }
    }*/
    
}
