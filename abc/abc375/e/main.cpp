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
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<int> S(N + 1);
    for (int i = 1; i <= N; i++) {
        S[i] = S[i - 1] + B[i - 1];
    }

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(S[N] / 3 + 1, vector<int>(S[N] / 3 + 1, 1e9)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S[N] / 3; j++) {
            for (int k = 0; k <= S[N] / 3; k++) {
                if (j - B[i - 1] >= 0) {
                    if (A[i - 1] == 1) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - B[i - 1]][k]);
                    } else {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - B[i - 1]][k] + 1);
                    }
                }

                if (k - B[i - 1] >= 0) {
                    if (A[i - 1] == 2) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - B[i - 1]]);
                    } else {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - B[i - 1]] + 1);
                    }
                }

                if (A[i - 1] == 3) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                } else {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + 1);
                }
            }
        }
    }
    
    if (S[N] % 3 == 0 && dp[N][S[N] / 3][S[N] / 3] < 1e9) {
        cout << dp[N][S[N] / 3][S[N] / 3] << endl;
    } else {
        cout << -1 << endl;
    }
}
