#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<int> ord(N);
    for (int i = 0; i < N; i++) {
        ord[i] = i;
    }
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return (A[i] - 1) * B[j] < (A[j] - 1) * B[i];
    });
    
    vector<vector<ll>> dp(N + 1, vector<ll>(K + 1, -1e9));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        int k = min(i, K);
        for (int j = 0; j <= k; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] * (A[ord[i - 1]]) + B[ord[i - 1]]);
            }
        }
    }
    cout << dp[N][K] << endl;
}
