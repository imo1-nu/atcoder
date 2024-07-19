#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> dp(30, vector<int> (100001, 0));

int ans(int x, int y) {
    if (y == 0) return x;
    int i;
    for (i = 30; (1 << i) > y; i--) {}
    return ans(dp[i][x], y - (1 << i));
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[0][i] = a[i - 1];
    }

    for (int i = 1; i < 30; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << ans(x, y) << endl;
    }
}
