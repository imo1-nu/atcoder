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
    vector<double> X(N + M + 1), Y(N + M + 1);
    for (int i = 0; i < N + M; i++) {
        cin >> X[i] >> Y[i];
    }
    X[N + M] = 0;
    Y[N + M] = 0;

    vector<double> pow2(M + 1);
    pow2[0] = 1;
    for (int i = 1; i <= M; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }

    vector<vector<double>> dp(1 << (N + M + 1), vector<double>(N + M + 1, 1e18));
    dp[0][N + M] = 0;
    for (int i = 0; i < (1 << (N + M + 1)); i++) {
        int cnt = 0;
        for (int j = N; j < N + M; j++) {
            if (i >> j & 1) cnt++;
        }
        for (int j = 0; j < N + M + 1; j++) {
            for (int k = 0; k < N + M + 1; k++) {
                dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + sqrt((X[j] - X[k]) * (X[j] - X[k]) + (Y[j] - Y[k]) * (Y[j] - Y[k])) / pow2[cnt]);
            }
        }
    }

    double ans = 1e18;
    for (int i = 0; i < (1 << M); i++) {
        ans = min(ans, dp[(1 << N) - 1 + (i << N) + (1 << (N + M))][N + M]);
    }
    
    printf("%.12lf\n", ans);
}
