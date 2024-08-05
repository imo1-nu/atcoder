#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    if (s[0] == 'R') dp[1][2] = 1;
    if (s[0] == 'S') dp[1][0] = 1;
    if (s[0] == 'P') dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i - 1] == 'R') {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        }
        if (s[i - 1] == 'S') {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + 1;
        }
        if (s[i - 1] == 'P') {
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}
