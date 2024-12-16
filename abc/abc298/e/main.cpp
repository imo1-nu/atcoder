#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, A, B, P, Q;
    cin >> N >> A >> B >> P >> Q;
    mint p =  1 / mint(P);
    mint q = 1 / mint(Q);

    vector<vector<mint>> dp1(N + 1, vector<mint>(N + 1));
    vector<vector<mint>> dp2(N + 1, vector<mint>(N + 1));
    dp1[0][A] = 1;
    dp2[0][B] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            for (int k = 1; k <= P; ++k) {
                dp1[i + 1][min(N, j + k)] += dp1[i][j] * p;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            for (int k = 1; k <= Q; ++k) {
                dp2[i + 1][min(N, j + k)] += dp2[i][j] * q;
            }
        }
    }

    vector<mint> S(N + 1);
    S[N] = dp2[N][N];
    for (int i = N - 1; i >= 0; --i) {
        S[i] = S[i + 1] + dp2[i][N];
    }

    mint ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += dp1[i][N] * S[i];
    }
    cout << ans.val() << endl;
}
