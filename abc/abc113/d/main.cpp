#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint1000000007;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, K;
    cin >> H >> W >> K;
    K--;

    vector<vector<mint>> A(W, vector<mint>(W));
    for (int i = 0; i < (1 << (W - 1)); i++) {
        bool ok = true;
        for (int j = 0; j < W - 1; j++) {
            if ((i >> j & 1) && (i >> (j + 1) & 1)) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        for (int j = 0; j < W; j++) {
            if (j > 0 && (i >> (j - 1) & 1)) {
                A[j][j - 1]++;
            }
            else if (j < W - 1 && (i >> j & 1)) {
                A[j][j + 1]++;
            }
            else {
                A[j][j]++;
            }
        }
    }

    vector<vector<mint>> dp(H + 1, vector<mint>(W));
    dp[0][0] = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < W; k++) {
                dp[i + 1][k] += dp[i][j] * A[j][k];
            }
        }
    }
    cout << dp[H][K].val() << endl;
}
