#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

#define INF 1e9

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        --A, --B;
        dist[A][B] = C;
    }
    for (int i = 0; i < N; ++i) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<vector<int>> dp(1 << N, vector<int>(N, INF));
    for (int i = 0; i < N; ++i) {
        dp[1 << i][i] = 0;
    }
    for (int i = 1; i < (1 << N); ++i) {
        for (int j = 0; j < N; ++j) {
            if (dp[i][j] == INF) continue;
            if (!(i >> j & 1)) continue;
            for (int k = 0; k < N; ++k) {
                if (dist[j][k] == INF) continue;
                if (i >> k & 1) continue;
                dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + dist[j][k]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < N; ++i) {
        ans = min(ans, dp[(1 << N) - 1][i]);
    }
    if (ans == INF) cout << "No" << endl;
    else cout << ans << endl;
}
