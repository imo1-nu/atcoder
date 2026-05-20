#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<int> X(3);
    for (auto& x : X) cin >> x;
    int sum = X[0] + X[1] + X[2];
    vector<mint> P(sum + 1), Pinv(sum + 1);
    P[0] = 1;
    Pinv[0] = 1;
    for (int i = 1; i <= sum; i++) {
        P[i] = P[i - 1] * i;
        Pinv[i] = P[i].inv();
    }

    auto comb = [&](int x, int y) {
        if (x < y) return mint(0);
        return P[x] * Pinv[x - y] * Pinv[y];
    };

    mint ans = 0;
    for (int i = 1; i <= X[1]; i++) {
        ans += comb(X[1] + 1, i) * comb(X[0] - 1, i - 1) * comb(X[2] + X[1] - i, X[1] - i);
    }
    cout << ans.val() << endl;
}
