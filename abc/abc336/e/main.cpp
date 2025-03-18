#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string N;
    cin >> N;
    ll ans = 0;
    for (int s = 1; s <= 9 * 14; s++) {
        vector<vector<vector<vector<ll>>>> dp(N.size() + 1, vector<vector<vector<ll>>>(s + 1, vector<vector<ll>>(s, vector<ll>(2))));
        dp[0][0][0][1] = 1;
        for (int d = 0; d < N.size(); d++) {
            for (int i = 0; i <= s; i++) {
                for (int j = 0; j < s; j++) {
                    for (int k = 0; k < 2; k++) {
                        for (int t = 0; t < 10; t++) {
                            if (i + t > s) continue;
                            if (k == 1 && N[d] - '0' < t) continue;
                            if (k == 1 && N[d] - '0' == t) dp[d + 1][i + t][(j * 10 + t) % s][1] += dp[d][i][j][k];
                            else dp[d + 1][i + t][(j * 10 + t) % s][0] += dp[d][i][j][k];
                        }
                    }
                }
            }
        }
        ans += dp[N.size()][s][0][0] + dp[N.size()][s][0][1];
    }
    cout << ans << '\n';
}
