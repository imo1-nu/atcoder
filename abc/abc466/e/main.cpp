#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<vector<int>> num(N, vector<int>(2));
    for (int i = 0; i < N; i++) cin >> num[i][0] >> num[i][1];

    vector<vector<ll>> dp(N + 1, vector<ll>(K*2 + 1, -LLONG_MAX));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int flip = 0; flip < 2; flip++) {
            for (int k = 0; k + flip <= K*2; k++) {
                dp[i + 1][k + flip] = max(dp[i][k] + num[i][(k + flip) % 2], dp[i + 1][k + flip]);
            }
        }
    }
    ll ans = 0;
    for (int k = 0; k <= K*2; k++) {
        ans = max(dp[N][k], ans);
    }
    cout << ans << endl;
}
