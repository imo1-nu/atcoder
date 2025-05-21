#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;

    auto solve = [&]() {
        ll N, K;
        cin >> N >> K;

        vector<vector<pair<mint, mint>>> dp(60, vector<pair<mint, mint>>(60));
        ll cnt = 0, sum = 0;
        for (int i = 0; i < 60; i++) {
            if ((N >> (59 - i) & 1)) {
                dp[i][cnt] = {1, sum};
                cnt++;
                sum += 1ll << (59 - i);
            }
            for (int j = 0; j <= i; j++) {
                if (i == 0) continue;
                dp[i][j].first += dp[i - 1][j].first;
                dp[i][j].second += dp[i - 1][j].second;
                if (j > 0) {
                    dp[i][j].first += dp[i - 1][j - 1].first;
                    dp[i][j].second += dp[i - 1][j - 1].second + (1ll << (59 - i)) * dp[i - 1][j - 1].first;
                }
            }
        }
        if (cnt == K) dp[59][K].second += N;
        cout << dp[59][K].second.val() << '\n';
    };

    while (T--) {
        solve();
    }
}
