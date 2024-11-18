#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

mint P[200001];

mint comb(int n, int k) {
    return P[n] / P[k] / P[n - k];
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, K;
    cin >> N >> M >> K;

    vector<mint> dp(N + 1);
    dp[1] = M;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] * (M - 1);
    }

    P[0] = 1;
    for (int i = 1; i <= N; i++) {
        P[i] = P[i - 1] * i;
    }

    mint ans = 0;
    for (int k = 0; k <= K; k++) {
        ans += comb(N - 1, k) * dp[N - k];
    }

    cout << ans.val() << endl;
}
