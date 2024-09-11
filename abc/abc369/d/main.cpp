#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll inf = 1e18;
    vector<pair<ll, ll>> dp(N + 1, make_pair(-inf, -inf));
    dp[0].second = 0;
    for (ll i = 1; i <= N; i++) {
        dp[i].first = max(dp[i - 1].first, dp[i - 1].second + A[i - 1]);
        dp[i].second = max(dp[i - 1].second, dp[i - 1].first + 2ll * A[i - 1]);
    }
    
    cout << max(dp[N].first, dp[N].second) << endl;
}
