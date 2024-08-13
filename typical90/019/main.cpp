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
    vector<ll> A(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> A[i];
    }
    vector<vector<ll>> dp(2 * N, vector<ll>(2 * N, 1e9));
    for (int i = 0; i < 2 * N - 1; i++) {
        dp[i][i + 1] = abs(A[i] - A[i + 1]);
    }
    
    for (int K = 3; K < 2 * N; K += 2) {
        for (int L = 0; L < 2 * N - K; L++) {
            int R = L + K;
            dp[L][R] = abs(A[L] - A[R]) + dp[L + 1][R - 1];
            for (int M = L; M < R; M++) {
                dp[L][R] = min(dp[L][R], dp[L][M] + dp[M + 1][R]);
            }
        }
    }
    cout << dp[0][2 * N - 1] << endl;
}
