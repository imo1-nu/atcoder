#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint1000000007;

vector<mint> P;

mint comb (int n, int k) {
    return P[n] / P[k] / P[n - k];
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;

    K = min(K, N - 1);
    P.resize(N + 1);
    P[0] = 1;
    for (int i = 1; i <= N; i++) {
        P[i] = P[i - 1] * i;
    }

    mint ans = 0;
    for (int i = 0; i <= K; i++) {
        mint c = comb(N - 1, i) * comb(N, i);
        ans += c;
    }
    cout << ans.val() << endl;
}
