#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S;
    cin >> N >> S;
    vector<vector<int>> dp(N + 1, vector<int>(7 + 1));
    string T = "atcoder";
    int mod = 1000000007;
    dp[0][0] = 1;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 7; j++) {
            if (i > 0)dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
            if (i > 0 && j > 0 && S[i - 1] == T[j - 1]) {
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[N][7] << endl;
}
