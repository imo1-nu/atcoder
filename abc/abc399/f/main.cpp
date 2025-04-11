#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<mint> A(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i] = a;
    }

    vector<mint> P(K + 1), P_inv(K + 1);
    P[0] = 1;
    P_inv[0] = 1;
    for (int i = 1; i <= K; i++) {
        P[i] = P[i - 1] * i;
        P_inv[i] = P_inv[i - 1] / i;
    }
    auto comb = [&](int n, int k) {
        return P[n] * P_inv[k] * P_inv[n - k];
    };

    vector<vector<mint>> S(N + 1, vector<mint>(K + 1));
    S[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        S[i][0] = 1;
        S[i][1] = S[i - 1][1] + A[i - 1];
    }
    for (int k = 2; k <= K; k++) {
        for (int i = 1; i <= N; i++) {
            S[i][k] = S[i][k - 1] * S[i][1];
        }
    }

    mint ans = 0;
    for (int k = 0; k <= K; k++) {
        mint add = 0, s = 0;
        for (int r = 1; r <= N; r++) {
            if (k % 2 == 0) s += S[r - 1][k];
            else s -= S[r - 1][k];
            add += S[r][K - k] * s;
        }
        ans += comb(K, k) * add;
    }
    cout << ans.val() << '\n';
}
