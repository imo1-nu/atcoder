#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k;
vector<int> a(50), b(50);

int score(int l, int r) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (l <= a[i] && r >= b[i]) cnt++;
    }
    return cnt;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1000000));
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 0; l <= j - 1; l++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][l] + score(l + 1, j));
            }
        }
    }
    cout << dp[k][n] << endl;
}
