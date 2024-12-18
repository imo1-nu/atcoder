#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        A[a][b]++;
    }

    vector<vector<int>> dp(H + 1, vector<int>(W + 1));

    ll ans = 0;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (A[i - 1][j - 1] > 0) continue;
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            ans += dp[i][j];
        }
    }
    cout << ans << endl;
}
