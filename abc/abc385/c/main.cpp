#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int ans = 1;
    vector<vector<int>> dp(N, vector<int>(N, 1));
    for (int i = 1; i < N; ++i) {
        for (int d = 1; d <= i; ++d) {
            if (H[i - d] == H[i]) {
                dp[i][d] = dp[i - d][d] + 1;
                ans = max(ans, dp[i][d]);
            }
        }
    }
    cout << ans << endl;
}
