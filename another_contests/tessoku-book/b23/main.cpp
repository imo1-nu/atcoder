#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(1.0 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2));
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    vector<vector<double>> dp(1 << n, vector<double>(n, 1e10));
    dp[0][0] = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + dist(x[j], y[j], x[k], y[k]));
            }
        }
    }
    printf("%.12lf\n", dp[(1 << n) - 1][0]);
}
