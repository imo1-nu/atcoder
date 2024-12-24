#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> X(M), Y(M);
    for (int i = 0; i < M; ++i) {
        cin >> X[i] >> Y[i];
        --X[i], --Y[i];
    }

    vector<mint> dp(N + K);
    dp[K] = 1;
    for (int i = K; i > 0; --i) {
        dp[i - 1] = dp[i + N - 1];
        vector<pair<int, mint>> add;
        for (int j = 0; j < M; ++j) {
            add.push_back({i + Y[j] - 1, dp[i + X[j]]});
        }
        for (auto [j, v] : add) {
            dp[j] += v;
        }
    }

    mint ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += dp[i];
    }
    cout << ans.val() << endl;
}
