#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, K;
    cin >> H >> K;
    vector<vector<mint>> dp(H + 1, vector<mint>(K + 1, 0));
    vector<vector<mint>> p(H + 1, vector<mint>(K + 1, 0));
    p[H][0] = 1;
    mint H_inv = mint(H).inv();
    for (int k = 0; k < K; k++) {
        for (int h = max(H - k, 0); h <= H; h++) {
            if (h > 0 && k < K) {
                dp[h - 1][k + 1] += (dp[h][k] + p[h][k]) * h * H_inv;
                p[h - 1][k + 1] += p[h][k] * h * H_inv;
            }
            if (h < H) {
                dp[h + 1][k] += (dp[h][k] + p[h][k]) * (H - h) * H_inv;
                p[h + 1][k] += p[h][k] * (H - h) * H_inv;
            }
        }
    }
    mint ans = 0;
    for (int h = 0; h <= H; h++) {
        ans += dp[h][K];
    }
    cout << ans.val() << endl;
}
