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
    vector<pair<ll, ll>> dp(n + 1);
    dp[0] = {0, 0};
    for (ll i = 1; i <= n; i++) {
        dp[i].first = max(dp[i - 1].first, dp[i - 1].second);
        dp[i].second = dp[i - 1].first + a[i - 1];
    }
    cout << max(dp[n].first, dp[n].second) << endl;
}
