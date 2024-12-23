#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    int N = S.size();
    vector<int> cnt(26);
    for (char c : S) {
        cnt[c - 'a']++;
    }

    vector<mint> P(N + 1);
    vector<mint> invP(N + 1);
    P[0] = 1;
    invP[0] = 1;
    for (int i = 1; i <= N; i++) {
        P[i] = P[i - 1] * i;
        invP[i] = P[i].inv();
    }
    auto comb = [&](int n, int k) {
        return P[n] * invP[k] * invP[n - k];
    };

    vector<mint> dp(N + 1);
    dp[0] = 1;
    for (int i = 0; i < 26; i++) {
        vector<mint> ndp(N + 1);
        for (int j = 0; j <= cnt[i]; j++) {
            for (int k = j; k <= N; k++) {
                ndp[k] += dp[k - j] * comb(k, j);
            }
        }
        dp = ndp;
    }

    mint ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += dp[i];
    }
    cout << ans.val() << endl;
}
