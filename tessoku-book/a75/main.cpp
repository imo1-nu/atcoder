#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<P> dt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> dt[i].second >> dt[i].first;
    }
    sort(dt.begin(), dt.end());

    vector<vector<int>> dp(n + 1, vector<int>(1441));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1440; j++) {
            if (dt[i].first < j || dt[i].second > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - dt[i].second] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i <= 1440; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}
