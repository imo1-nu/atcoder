#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint1000000007;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    int N = S.size();
    vector<mint> dp(13);
    dp[0] = 1;
    for (auto c : S) {
        vector<mint> next(13);
        if (c == '?') {
            for (int i = 0; i < 13; ++i) {
                for (int j = 0; j < 10; ++j) {
                    next[(i * 10 + j) % 13] += dp[i];
                }
            }
        } else {
            int d = c - '0';
            for (int i = 0; i < 13; ++i) {
                next[(i * 10 + d) % 13] += dp[i];
            }
        }
        dp = next;
    }
    cout << dp[5].val() << endl;
}
