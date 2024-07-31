#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(x + 1, 1e5)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0][0] = 0;
        for (int j = 1; j <= i; j++) {
            for (int k = 0; k <= x; k++) {
                if (i > j) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                if (k >= a[i - 1]) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k - a[i - 1]] + b[i - 1]);
                }
            }
        }
    }

    for (int j = n; j >= 0; j--) {
        for (int k = 0; k <= x; k++) {
            if (dp[n][j][k] <= y) {
                cout << min(j + 1, n) << endl;
                return 0;
            }
        }
    }
}
