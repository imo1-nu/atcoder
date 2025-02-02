#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, D;
    cin >> N >> D;
    vector<mint> pow2(2 * N + 1);
    pow2[0] = 1;
    for (int i = 1; i <= 2 * N; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }

    vector<mint> f(N);
    for (int i = 1; i < N - D; i++) {
        f[i] = pow2[D + 1];
    }
}
