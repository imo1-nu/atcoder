#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> S(100001);
    for (int i = 0; i < N; i++) {
        int t, x, a;
        cin >> t >> x >> a;
        S[t].emplace_back(x, a);
    }
    vector<ll> dp(5, -1e18);
    dp[0] = 0;
    for (int t = 1; t <= 100000; t++) {
        auto dp2 = dp;
        for (int i = 0; i < 5; i++) {
            for (int j = max(0, i - 1); j <= min(4, i + 1); j++) {
                dp2[i] = max(dp2[i], dp[j]);
            }
        }
        for (auto [x, a] : S[t]) {
            dp2[x] += a;
        }
        dp = dp2;
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}
