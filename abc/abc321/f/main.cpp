#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int Q, K;
    cin >> Q >> K;
    vector<mint> dp(K + 1);
    dp[0] = 1;
    while (Q--) {
        char t;
        int x;
        cin >> t >> x;
        if (t == '+') {
            for (int i = K; i >= x; i--) {
                dp[i] += dp[i - x];
            }
        }
        else {
            for (int i = x; i <= K; i++) {
                dp[i] -= dp[i - x];
            }
        }
        cout << dp[K].val() << endl;
    }
}
