#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int R, C, K;
    cin >> R >> C >> K;
    vector<vector<int>> V(R, vector<int>(C));
    for (int i = 0; i < K; ++i) {
        int r, c, v;
        cin >> r >> c >> v;
        --r; --c;
        V[r][c] = v;
    }

    vector<vector<vector<ll>>> dp(R + 1, vector<vector<ll>>(C + 1, vector<ll>(4)));
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            for (int k = 0; k < 4; k++) {
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][k]);
                dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
            }
            for (int k = 3; k >= 1; k--) {
                dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + V[i - 1][j - 1]);
            }
        }
    }
    cout << *max_element(dp[R][C].begin(), dp[R][C].end()) << endl;
}
