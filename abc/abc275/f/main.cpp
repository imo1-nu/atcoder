#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int INF = 1e9;

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, INF));
    dp[0][0] = 0;
    for (int j = 0; j <= M; ++j) {
        int premin = dp[0][j];
        for (int i = 1; i <= N; ++i) {
            if (j >= A[i - 1]) dp[i][j] = dp[i - 1][j - A[i - 1]];
            dp[i][j] = min(dp[i][j], premin + 1);
            premin = min(premin, dp[i][j]);
        }
    }

    for (int j = 1; j <= M; ++j) {
        if (dp[N][j] == INF) cout << -1 << endl;
        else cout << dp[N][j] << endl;
    }
}
