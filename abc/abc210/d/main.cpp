#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll H, W, C;
    cin >> H >> W >> C;
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A[i][j];
        }
    }

    vector<vector<ll>> dp1(H + 1, vector<ll>(W + 1, 1e18));
    vector<vector<ll>> dp2(H + 1, vector<ll>(W + 1, 1e18));
    dp1[0][0] = 1e18;
    dp2[0][0] = 1e18;
    ll ans = 1e18;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans = min(ans, A[i][j] + dp1[i][j]);
            dp1[i + 1][j] = min(dp1[i + 1][j], min(dp1[i][j], A[i][j]) + C);
            dp1[i][j + 1] = min(dp1[i][j + 1], min(dp1[i][j], A[i][j]) + C);
        }
    }

    for (int i = 0; i < H; i++) {
        reverse(A[i].begin(), A[i].end());
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans = min(ans, A[i][j] + dp2[i][j]);
            dp2[i + 1][j] = min(dp2[i + 1][j], min(dp2[i][j], A[i][j]) + C);
            dp2[i][j + 1] = min(dp2[i][j + 1], min(dp2[i][j], A[i][j]) + C);
        }
    }

    cout << ans << endl;
}