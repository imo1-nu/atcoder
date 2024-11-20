#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int b;
            cin >> b;
            a[i] += b * (1 << j);
        }
    }

    vector<vector<int>> dp(m + 1, vector<int> (1 << n, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            int s = j | a[i];
            dp[i + 1][s] = min(dp[i + 1][s], dp[i][j] + 1);
        }
    }
    
    if (dp[m][(1 << n) - 1] != 1e9) cout << dp[m][(1 << n) - 1] << endl;
    else cout << -1 << endl;
    /*for (int i = 0; i <= m; i++) {
        for (int j = 0; j < 1 << n; j++) {
            cout << dp[i][j];
            if (j < (1 << n) - 1) cout << ' ';
            else cout << endl;
        }
        
    }*/
    
}
