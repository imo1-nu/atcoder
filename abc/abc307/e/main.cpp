#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    vector<vector<mint>> dp(1000001, vector<mint>(2));
    dp[1][1] = M;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] * (M - 2) + dp[i - 1][1] * (M - 1);
        dp[i][1] = dp[i - 1][0];
    }
    cout << dp[N][0].val() << endl;
}
