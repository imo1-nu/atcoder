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
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<vector<int>> IDX(20);
    for (int i = 0; i < N; i++) {
        IDX[A[i]].push_back(i);
    }

    vector<int> dp(1 << 20, 1e9);
    dp[0] = 0;
    for (int i = 0; i < (1 << 20); i++) {
        if (dp[i] == -1) {
            continue;
        }
        for (int j = 0; j < 20; j++) {
            if (i >> j & 1) {
                continue;
            }
            int ni = i | (1 << j);
            int idx1 = lower_bound(IDX[j].begin(), IDX[j].end(), dp[i]) - IDX[j].begin();
            if (idx1 + 1 >= IDX[j].size()) {
                continue;
            }
            int idx2 = IDX[j][idx1 + 1];
            dp[ni] = min(dp[ni], idx2 + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << 20); i++) {
        if (dp[i] == 1e9) {
            continue;
        }
        int cnt = __builtin_popcount(i);
        ans = max(ans, cnt);
    }

    cout << ans * 2 << endl;
}
