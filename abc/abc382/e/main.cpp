#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, X;
    cin >> N >> X;
    vector<double> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i] /= 100;
    }

    vector<vector<double>> dp(N + 1, vector<double>(N + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] * (1 - P[i - 1]);
            if (j > 0) dp[i][j] += dp[i - 1][j - 1] * P[i - 1];
        }
    }

    vector<double> ans(X + 1);
    for (int i = 1; i <= X; i++) {
        for (int j = 1; j <= N; j++) {
            ans[i] += ans[max(0, i - j)] * dp[N][j];
        }
        ans[i] += 1;
        ans[i] /= 1 - dp[N][0];
    }
    cout << fixed << setprecision(10) << ans[X] << endl;
}
