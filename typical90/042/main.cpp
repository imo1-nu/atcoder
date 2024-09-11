#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll mod = 1000000007;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll K;
    cin >> K;
    vector<ll> dp(K+1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= K; i++) {
        ll B = min(i, 9ll);
        for (ll j = 1; j <= B; j++) {
            dp[i] += dp[i-j];
            dp[i] %= mod;
        }
    }
    if (K % 9 != 0) dp[K] = 0;
    cout << dp[K] << endl;
}
