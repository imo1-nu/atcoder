#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> A[i];
    }
    vector<vector<int>> dp(2 * N, vector<int>(2 * N, 1e9));
    for (int i = 0; i < 2 * N - 1; i++) {
        dp[i][i + 1] = abs(A[i] - A[i + 1]);
    }

    for (int len = 3; len <= 2 * N - 1; len += 2) {
        for (int l = 0; l < 2 * N - len; l++) {
            int r = l + len;
            dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + abs(A[l] - A[r]));
            for (int m = l + 1; m + 1 < r; m++) {
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
            }
        }
    }
    cout << dp[0][2 * N - 1] << endl;
}
