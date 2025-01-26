#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, X;
    cin >> N >> X;
    vector<vector<pair<int, int>>> V(3);
    for (int i = 0; i < N; i++) {
        int v, a, c;
        cin >> v >> a >> c;
        v--;
        V[v].emplace_back(a, c);
    }

    vector<vector<int>> dp(3, vector<int>(X + 1));
    for (int i = 0; i < 3; i++) {
        for (auto [a, c] : V[i]) {
            for (int j = X; j >= c; j--) {
                dp[i][j] = max(dp[i][j], dp[i][j - c] + a);
            }
        }
    }

    int l = 0, r = 1e9 + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        vector<int> idx(3);
        vector<int> dp2(X + 1);
        for (int i = 0; i < 3; i++) {
            idx[i] = lower_bound(dp[i].begin(), dp[i].end(), m) - dp[i].begin();
        }
        if (idx[0] + idx[1] + idx[2] > X) r = m;
        else l = m;
    }
    cout << l << endl;
}
