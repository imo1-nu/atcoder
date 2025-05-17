#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s, t;
    cin >> s >> t;

    int slen = s.length(), tlen = t.length();
    if (slen > tlen) {
        swap(s, t);
        swap(slen, tlen);
    }
    vector<vector<int>> dp(slen + 1, vector<int>(tlen + 1));
    
    for (int i = 0; i <= slen; i++) {
        for (int j = 0; j <= tlen; j++) {
            if (i > 0 && j > 0 && s[i - 1] == t[j - 1]) {
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1]});
            }
            else if (i > 0 && j > 0) {
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
            }
            else if (i > 0) {
                dp[i][j] = dp[i - 1][j] + 1;
            }
            else if (j > 0) {
                dp[i][j] = dp[i][j - 1] + 1;
            }
        }
    }
    
    cout << dp[slen][tlen] << endl;
}
