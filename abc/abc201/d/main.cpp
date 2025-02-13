#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }

    vector<vector<int>> dp(H, vector<int>(W));
    unordered_map<char, int> f = {{'+', 1}, {'-', -1}};

    for (int i = H - 1; i >= 0; i--) {
        for (int j = W - 1; j >= 0; j--) {
            if (i == H - 1 && j == W - 1) continue;
            if ((i + j) % 2 == 0) {
                if (i + 1 < H && j + 1 < W) dp[i][j] = max(dp[i + 1][j] + f[A[i + 1][j]], dp[i][j + 1] + f[A[i][j + 1]]);
                else if (i + 1 < H) dp[i][j] = dp[i + 1][j] + f[A[i + 1][j]];
                else dp[i][j] = dp[i][j + 1] + f[A[i][j + 1]];
            } else {
                if (i + 1 < H && j + 1 < W) dp[i][j] = min(dp[i + 1][j] - f[A[i + 1][j]], dp[i][j + 1] - f[A[i][j + 1]]);
                else if (i + 1 < H) dp[i][j] = dp[i + 1][j] - f[A[i + 1][j]];
                else dp[i][j] = dp[i][j + 1] - f[A[i][j + 1]];
            }
        }
    }

    if (dp[0][0] > 0) cout << "Takahashi" << endl;
    else if (dp[0][0] < 0) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
}
