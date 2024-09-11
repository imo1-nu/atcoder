#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

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
    vector<ll> S(N + 1);
    for (ll i = 1; i <= N; i++) {
        S[i] = S[i - 1] + A[i - 1];
    }

    vector<mint> dp(N + 1);
    map<ll, mint> mp;
    mp[0] = 1;
    dp[0] = 1;
    mint all = 1;
    for (ll i = 1; i <= N; i++) {
        dp[i] = all - mp[S[i] - K];
        mp[S[i]] += dp[i];
        all += dp[i];
    }
    cout << dp[N].val() << endl;
}
