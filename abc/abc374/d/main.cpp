#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(1.0 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2));
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    double S, T;
    cin >> S >> T;

    vector<double> A(2 * N), B(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> A[i + N] >> B[i + N];
    }
    vector<vector<double>> dp(1 << N, vector<double>(2 * N, 1e18));
    for (int i = 0; i < 2 * N; i++) {
        dp[0][i] = dist(0, 0, A[i], B[i]) / S;
    }
    
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < 2 * N; j++) {
            for (int k = 0; k < N; k++) {
                dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + dist(A[j], B[j], A[k + N], B[k + N]) / S + dist(A[k + N], B[k + N], A[k], B[k]) / T);
                dp[i | (1 << k)][k + N] = min(dp[i | (1 << k)][k + N], dp[i][j] + dist(A[j], B[j], A[k], B[k]) / S + dist(A[k], B[k], A[k + N], B[k + N]) / T);
            }
        }
    }

    double ans = 1e18;
    for (int i = 0; i < 2 * N; i++) {
        ans = min(ans, dp[(1 << N) - 1][i]);
    }
    
    printf("%.12lf\n", ans);
}
