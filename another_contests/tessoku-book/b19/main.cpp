#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(100001, 1 << 30));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 100000; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i - 1] >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
        }
    }
    
    int ans = 0;
    for (int i = 100000; i >= 0; i--) {
        if (dp[n][i] <= W) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
