#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint1000000007;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }
    vector<vector<vector<mint>>> dp(H + 1, vector<vector<mint>>(W + 1, vector<mint>(4)));
    dp[1][1][0] = 1;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (S[i - 1][j - 1] == '#') continue;
            dp[i][j][1] += dp[i][j - 1][0] + dp[i][j - 1][1];
            dp[i][j][2] += dp[i - 1][j][0] + dp[i - 1][j][2];
            dp[i][j][3] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][3];
            dp[i][j][0] += dp[i][j][1] + dp[i][j][2] + dp[i][j][3];
        }
    }
    cout << dp[H][W][0].val() << endl;
}
