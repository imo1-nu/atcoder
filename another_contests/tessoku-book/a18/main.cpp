#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
    dp[0][0] = true;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j <= s; j++) {
            if (dp[i][j]) {
                dp[i + 1][j] = true;
                if (j + a[i] <= s) dp[i + 1][j + a[i]] = true;
            }
        }
    }
    if (dp[n][s]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
