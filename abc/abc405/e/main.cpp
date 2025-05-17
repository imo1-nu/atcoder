#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    vector<mint> P(A + B + C + D + 1), P_inv(A + B + C + D + 1);
    P[0] = 1;
    P_inv[0] = 1;
    for (int i = 1; i <= A + B + C + D; i++) {
        P[i] = P[i - 1] * i;
        P_inv[i] = P[i].inv();
    }
    auto comb = [&](int n, int k) {
        return P[n] * P_inv[k] * P_inv[n - k];
    };

    mint ans = 0;
    for (int ringo_zero = A; ringo_zero <= A + B; ringo_zero++) {
        mint add = comb(ringo_zero - 1, A - 1);
        int x = A + B + C + D - ringo_zero;
        add *= comb(x, C);
        ans += add;
    }
    cout << ans.val() << endl;
}
