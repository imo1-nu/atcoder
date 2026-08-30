#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (auto& a : A) {
        cin >> a;
        a %= K;
    }

    vector<int> sum(N + 1);
    for (int i = 1; i <= N; i++) sum[i] = (sum[i - 1] + A[i - 1]) % K;
    vector<int> dp(N + 1);
    set<int> can = {0};
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1];
        if (can.count(sum[i])) {
            dp[i]++;
            can.clear();
        }
        can.insert(sum[i]);
    }
    
    cout << dp[N] << endl;
}
