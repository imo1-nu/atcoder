#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> S(H, vector<bool>(W));
    ll ans = 0;
    function<void(int, int)> dfs = [&](int i, int j) {
        if (i == H) {
            ll sum = 0;
            for (int x = 0; x < H; x++) {
                for (int y = 0; y < W; y++) {
                    if (!S[x][y]) {
                        sum ^= A[x][y];
                    }
                }
            }
            ans = max(ans, sum);
            return;
        }
        if (j == W) {
            dfs(i + 1, 0);
            return;
        }
        if (S[i][j]) {
            dfs(i, j + 1);
            return;
        }
        
        if (!S[i][j + 1] && j + 1 < W) {
            S[i][j] = true;
            S[i][j + 1] = true;
            dfs(i, j + 1);
            S[i][j] = false;
            S[i][j + 1] = false;
        }
        if (i + 1 < H) {
            S[i][j] = true;
            S[i + 1][j] = true;
            dfs(i, j + 1);
            S[i][j] = false;
            S[i + 1][j] = false;
        }
        dfs(i, j + 1);
    };
    dfs(0, 0);
    cout << ans << endl;
}
