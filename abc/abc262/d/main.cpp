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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    mint ans = 0;
    for (int i = 1; i <= N; i++) {
        vector<vector<vector<mint>>> dp(N + 1, vector<vector<mint>>(i + 1, vector<mint>(i)));
        dp[0][0][0] = 1;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k <= i; k++) {
                for (int l = 0; l < i; l++) {
                    dp[j + 1][k][l] += dp[j][k][l];
                    if (k + 1 <= i) {
                        dp[j + 1][k + 1][(l + A[j]) % i] += dp[j][k][l];
                    }
                }
            }
        }
        ans += dp[N][i][0];
    }
    cout << ans.val() << endl;
}
