#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 1000000007;
ll B;
ll LOG = 60;

vector<vector<int>> dp(LOG, vector<int> (1000, 0));

ll ans(ll N) {
    if (N == 0) return 0;
    ll i;
    for (i = 60; (1 << i) > N; i--) {}
    return dp[i][N] + ans(N - (1 << i));
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, K;
    cin >> N >> B >> K;
    vector<ll> C(K);
    for (int i = 0; i < K; i++) {
        cin >> C[i];
    }

    for (ll i = 0; i < K; i++) {
        dp[0][C[i]]++;
    }

    for (ll i = 1; i < LOG; i++) {
        for (ll j = 0; j < B; j++) {
            for (ll k = 0; k < B; k++) {
                dp[i][j] += dp[i - 1][j + k] * dp[i - 1][(j - k + B) % B];
            }
        }
    }

    cout << ans(N) << endl;
}
