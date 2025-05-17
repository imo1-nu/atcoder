#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint1000000007;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(6));
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < 6; j++) {
            cin >> A[i][j];
        }
    }

    mint ans = 0;
    vector<mint> dp(N);
    for (ll i = 0; i < 6; i++) {
        dp[0] += A[0][i];
    }
    for (ll i = 1; i < N; i++) {
        mint sum = 0;
        for (ll j = 0; j < 6; j++) {
            sum += A[i][j];
        }
        dp[i] = sum * dp[i-1];
    }
    cout << dp[N-1].val() << endl;
}
