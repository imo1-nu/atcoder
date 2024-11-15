#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<vector<vector<mint>>> dp(N + 1, vector<vector<mint>>(1 << 10, vector<mint>(11)));
    dp[0][0][10] = 1;
    for (int i = 1; i <= N; i++) {
        int c = S[i - 1] - 'A';
        for (int bit = 0; bit < (1 << 10); bit++) {
            for (int j = 0; j <= 10; j++) {
                dp[i][bit][j] += dp[i - 1][bit][j];
                if (j == c) {
                    dp[i][bit][j] += dp[i - 1][bit][j];
                }
                if ((bit & (1 << c)) == 0 && j != c) {
                    dp[i][bit | (1 << c)][c] += dp[i - 1][bit][j];
                }
            }
        }
    }

    mint ans = 0;
    for (int bit = 0; bit < (1 << 10); bit++) {
        for (int j = 0; j < 10; j++) {
            ans += dp[N][bit][j];
        }
    }
    cout << ans.val() << endl;
}
