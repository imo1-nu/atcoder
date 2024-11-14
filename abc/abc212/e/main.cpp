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
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<vector<mint>> dp(K+1, vector<mint>(N));
    dp[0][0] = 1;
    for (int k = 1; k <= K; k++) {
        mint sum = 0;
        for (int i = 0; i < N; i++) {
            sum += dp[k-1][i];
        }
        for (int i = 0; i < N; i++) {
            dp[k][i] = sum - dp[k-1][i];
            for (int j : G[i]) {
                dp[k][i] -= dp[k-1][j];
            }
        }
    }

    cout << dp[K][0].val() << endl;
}
