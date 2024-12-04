#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<double> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    vector<vector<double>> dp(N + 1, vector<double>(N + 1, -1e8));
    dp[0][1] = -1e8;
    for (int i = 1; i <= N; i++) {
        dp[i][1] = max(dp[i - 1][1], P[i - 1] - 1200);
    }

    vector<double> sum(N + 1);
    for (int i = 1; i <= N; i++) {
        sum[i] = sum[i - 1] + pow(0.9, i - 1);
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= i; j++) {
            double tmp = dp[i - 1][j - 1] + 1200 / sqrt(j - 1);
            tmp *= sum[j - 1] / sum[j] * 0.9;
            tmp += P[i - 1] / sum[j];
            tmp -= 1200 / sqrt(j);
            dp[i][j] = max(dp[i - 1][j], tmp);
        }
    }

    double ans = -1e8;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dp[N][i]);
    }
    cout << fixed << setprecision(10) << ans << endl;
}
