#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(2, 0)); //dp[i][0]左からi番目の最小
    for (int i = 0; i < n; i++) {
        dp[i][0] = a[i];
        dp[i][1] = a[i];
    }
    
    for (int i = n - 2; i > -1; i--) {
        for (int j = 0; j <= i; j++) {
            int t = dp[j][0];
            dp[j][0] = max(dp[j][1], dp[j + 1][1]);
            dp[j][1] = min(t, dp[j + 1][0]);
        }
    }
    cout << dp[0][0] << endl;
}
