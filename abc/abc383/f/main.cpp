#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, X, K;
    cin >> N >> X >> K;
    vector<int> P(N), U(N), C(N);
    vector<vector<int>> idx(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> U[i] >> C[i];
        idx[C[i]].push_back(i);
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(X + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= X; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j : idx[i]) {
            for (int k = X; k >= P[j]; k--) {
                dp[i][k] = max(dp[i][k], max(dp[i - 1][k - P[j]] + U[j] + K, dp[i][k - P[j]] + U[j]));
            }
        }
    }

    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
}
