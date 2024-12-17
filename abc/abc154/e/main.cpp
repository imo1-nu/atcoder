#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string N;
    int K;
    cin >> N >> K;
    int n = N.length();

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(K + 1, vector<ll>(2)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= K; ++j) {
            for (int k = 0; k < 2; ++k) {
                int c = N[i - 1] - '0';
                for (int d = 0; d <= 9; ++d) {
                    if (d > c && k == 0) break;

                    int nj = j + (d != 0);
                    if (nj > K) continue;
                    int nk = k;
                    if (d < c) nk = 1;
                    dp[i][nj][nk] += dp[i - 1][j][k];
                }
            }
        }
    }
    cout << dp[n][K][0] + dp[n][K][1] << endl;
}
