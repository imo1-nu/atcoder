#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(M), B(M), C(M);
    for (ll i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
    }
    vector<ll> E(K);
    for (ll i = 0; i < K; i++) {
        cin >> E[i];
        E[i]--;
    }

    vector<ll> dp(N, 1e18);
    dp[0] = 0;
    for (ll i = 0; i < K; i++) {
        dp[B[E[i]]] = min(dp[B[E[i]]], dp[A[E[i]]] + C[E[i]]);
    }

    if (dp[N-1] == 1e18) {
        cout << -1 << endl;
    }
    else {
        cout << dp[N-1] << endl;
    }
}
