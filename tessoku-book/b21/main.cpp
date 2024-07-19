#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    string s = "aa";
    cin >> n >> s;
    string rev(s.rbegin(), s.rend());
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max({dp[i - 1][j - 1] + (s[i - 1] == rev[j - 1]), dp[i][j - 1], dp[i - 1][j]});
        }
    }
    cout << dp[n][n] << endl;
}
