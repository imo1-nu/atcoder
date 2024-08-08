#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<ll> D(N), C(N), S(N);
    for (ll i = 0; i < N; i++) {
        cin >> D[i] >> C[i] >> S[i];
    }
    vector<ll> dp(5001);
    vector<vector<ll>> T(5001);
    for (ll i = 0; i < N; i++) {
        T[D[i]].push_back(i);
    }
    for (ll i = 1; i <= 5000; i++) {
        dp[i] = dp[i - 1];
        for (ll j = 0; j < T[i].size(); j++) {
            for (ll k = D[T[i][j]] - C[T[i][j]]; k >= 0; k--) {
                dp[k + C[T[i][j]]] = max(dp[k + C[T[i][j]]], dp[k] + S[T[i][j]]);
            }
        }
    }
    cout << dp[5000] << endl;
}
