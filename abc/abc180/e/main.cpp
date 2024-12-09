#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int dist(int x1, int y1, int z1, int x2, int y2, int z2) {
    return abs(x1 - x2) + abs(y1 - y2) + max(0, z2 - z1);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> X(N), Y(N), Z(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
    }

    vector<vector<int>> dp(1 << N, vector<int>(N, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                dp[i | (1 << j)][j] = min(dp[i | (1 << j)][j], dp[i][k] + dist(X[k], Y[k], Z[k], X[j], Y[j], Z[j]));
            }
        }
    }
    cout << dp[(1 << N) - 1][0] << endl;
}
