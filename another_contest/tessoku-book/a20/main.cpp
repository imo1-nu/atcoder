#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s, t;
    cin >> s >> t;

    vector<vector<int>> g(s.length(), vector<int>(t.length(), 0));
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < t.length(); j++) {
            if (s[i] == t[j]) g[i][j]++;
        }
    }
    
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= t.length(); j++) {
            dp[i][j] = dp[i - 1][j - 1] + g[i - 1][j - 1];
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            /*cout << dp[i][j];
            if (j < t.length()) cout << ' ';
            else cout << endl;*/
        }
    }

    cout << dp[s.length()][t.length()] << endl;

}
