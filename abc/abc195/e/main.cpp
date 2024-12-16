#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S, X;
    cin >> N >> S >> X;

    vector<vector<bool>> dp(N + 1, vector<bool>(7));
    dp[N][0] = true;
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j < 7; ++j) {
            if (X[i] == 'T') {
                dp[i][j] = dp[i + 1][j * 10 % 7] || dp[i + 1][(j * 10 + (S[i] - '0')) % 7];
            }
            else {
                dp[i][j] = dp[i + 1][j * 10 % 7] && dp[i + 1][(j * 10 + (S[i] - '0')) % 7];
            }
        }
    }

    if (dp[0][0]) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
}
