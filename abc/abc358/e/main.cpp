#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mod 998244353

ll myPlus(ll a, ll b) {
    return (a + b) % mod;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll k, num = 26;
    vector<ll> c(num);
    cin >> k;
    for (int i = 0; i < num; i++) {
        cin >> c[i];
    }
    
    vector<vector<ll>> dp(26, vector<ll> (k + 1, 0));
    for (int i = 0; i <= c[i] && i <= k; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < 26; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        
        for (int j = 1; j <= c[i] && j <= k; j++) {
            dp[i][j] = myPlus(dp[i][j - 1], 1ll);
        }
        
    }
    
    
}
