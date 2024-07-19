#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll mod = 1000000007;
    
    ll n, w, L, R;
    cin >> n >> w >> L >> R;
    vector<ll> x(n + 2);
    for (ll i = 1; i <= n; i++) {
        cin >> x[i];
    }
    x[n + 1] = w;
    
    vector<ll> dp(n + 2), sdp(n + 3);
    dp[0] = 1;
    sdp[1] = 1;
    for (ll i = 1; i <= n + 1; i++) {
        int min = lower_bound(x.begin(), x.end(), x[i] - R) - x.begin();
        auto max = lower_bound(x.begin(), x.end(), x[i] - L + 1) - x.begin();
        max--;

        dp[i] = (sdp[max + 1] - sdp[min] + mod) % mod;
        sdp[i + 1] = (sdp[i] + dp[i]) % mod;
    }
    
    cout << dp[n + 1] << endl;
}
