#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(Y + 1, 1e9)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= Y; ++k) {
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
                if (k + B[i] <= Y) dp[i + 1][j + 1][k + B[i]] = min(dp[i + 1][j + 1][k + B[i]], dp[i][j][k] + A[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= Y; ++j) {
            if (dp[N][i][j] <= X) {
                ans = min(N, max(ans, i + 1));
            }
        }
    }
    cout << ans << endl;
}
