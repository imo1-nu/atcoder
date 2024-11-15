#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

vector<mint> P(1001);

mint comb(int n, int k) {
    if (n < k) return 0;
    return P[n] / (P[k] * P[n - k]);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int K;
    cin >> K;
    vector<int> C(26);
    for (int i = 0; i < 26; i++) {
        cin >> C[i];
    }

    P[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        P[i] = P[i - 1] * i;
    }

    vector<vector<mint>> dp(27, vector<mint>(K + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= 26; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k <= C[i - 1] && k <= j; k++) {
                dp[i][j] += dp[i - 1][j - k] * comb(j, k);
            }
        }
    }

    mint ans = 0;
    for (int i = 1; i <= K; i++) {
        ans += dp[26][i];
    }
    cout << ans.val() << endl;
}
