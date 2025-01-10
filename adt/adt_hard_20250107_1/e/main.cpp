#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<vector<mint>> dp(N + 1, vector<mint>(11));
    for (int i = 1; i <= 9; ++i) dp[1][i] = 1;

    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= 9; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
        }
    }

    mint ans = 0;
    for (int i = 1; i <= 9; ++i) ans += dp[N][i];
    cout << ans.val() << endl;
}
