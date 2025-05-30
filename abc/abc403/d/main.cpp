#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, D;
    cin >> N >> D;
    int M = 1000000;
    vector<int> cnt(M + 1);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    if (D == 0) {
        for (auto c : cnt) if (c > 0) ans++;
        cout << N - ans << endl;
        return 0;
    }

    for (int d = 0; d < D; d++) {
        vector<int> B;
        for (int i = d; i <= M; i += D) {
            B.push_back(cnt[i]);
        }
        int K = B.size();
        vector<int> dp = B;
        dp[0] = B[0];
        if (K > 1) dp[1] = max(dp[0], dp[1]);
        for (int i = 2; i < K; i++) {
            dp[i] = max({dp[i], dp[i - 1], dp[i - 2] + B[i]});
        }
        ans += dp[K - 1];
    }
    cout << N - ans << endl;
}
