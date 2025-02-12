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

    mint ans = 0;
    for (int d = 0; d < N; d++) {
        mint f1, f2;
        if (d + D < N) f1 = pow2[D + 1];
        else f1 = 0;

        if (2 * (N - 1 - d) < D || D == 1) f2 = 0;
        else if (d + D < N) f2 = pow2[D - 1] * (D - 1);
        else f2 = pow2[D - 1] * (2 * N - 2 * d - D - 1);
        
        ans += pow2[d] * (f1 + f2);
    }
    cout << ans.val() << endl;
}
