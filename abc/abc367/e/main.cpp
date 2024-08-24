#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<vector<ll>> dp(60, vector<ll> (200001, 0ll));

ll ans(ll x, ll y) {
    if (y == 0) return x;
    ll i;
    for (i = 60; (1ll << i) > y; i--) {}
    return ans(dp[i][x], y - (1ll << i));
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, K;
    cin >> N >> K;
    vector<ll> X(N), A(N);
    for (ll i = 0; i < N; i++) {
        cin >> X[i];
        X[i]--;
    }
    for (ll i = 0; i < N; i++) cin >> A[i];

    for (ll i = 0; i < N; i++) {
        dp[0][i] = X[i];
    }

    for (ll i = 1; i < 60; i++) {
        for (ll j = 0; j < N; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    for (ll i = 0; i < N; i++) {
        cout << A[ans(i, K)];
        if (i < N - 1) cout << " ";
        else cout << endl;
    }
}
