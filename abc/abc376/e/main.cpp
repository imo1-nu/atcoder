#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> P(N);

    for (ll i = 0; i < N; i++) {
        cin >> P[i].first;
    }
    for (ll i = 0; i < N; i++) {
        cin >> P[i].second;
    }
    sort(P.begin(), P.end());

    priority_queue<ll> pq;
    vector<ll> dp(N + 1);
    for (ll i = 0; i < K; i++) {
        pq.push(P[i].second);
        dp[K] += P[i].second;
    }

    for (ll i = K; i < N; i++) {
        pq.push(P[i].second);
        dp[i + 1] = dp[i] + P[i].second;
        
        // 一番大きい値を取り除く
        dp[i + 1] -= pq.top();
        pq.pop();
    }

    ll ans = 1e18;
    for (ll i = K; i <= N; i++) {
        ans = min(ans, dp[i] * P[i - 1].first);
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll T;
    cin >> T;
    for (ll i = 0; i < T; i++) {
        solve();
    }
}
