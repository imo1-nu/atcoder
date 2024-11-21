#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<ll> cnt(40);
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < 40; j++) {
            if (A[i] >> j & 1) {
                cnt[j]++;
            }
        }
    }

    vector<vector<ll>> dp(41, vector<ll>(2, -1));
    dp[40][1] = 0;
    for (ll i = 39; i >= 0; i--) {
        ll bit = 1ll << i;
        if (dp[i + 1][0] >= 0) dp[i][0] = max(dp[i][0], dp[i + 1][0] + bit * max(cnt[i], N - cnt[i]));
        if (dp[i + 1][1] >= 0) {
            if (K >> i & 1) {
                dp[i][0] = max(dp[i][0], dp[i + 1][1] + bit * cnt[i]);
                dp[i][1] = max(dp[i][1], dp[i + 1][1] + bit * (N - cnt[i]));
            }
            else {
                dp[i][1] = max(dp[i][1], dp[i + 1][1] + bit * cnt[i]);
            }
        }
    }

    cout << max(dp[0][0], dp[0][1]) << endl;
}
