#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> P(N), C(N), D(N);
    for (int i = 1; i < N; i++) cin >> P[i];
    for (auto& c : C) cin >> c;
    for (auto& d : D) cin >> d;

    vector<vector<int>> G(N);
    for (int i = 1; i < N; i++) G[P[i] - 1].push_back(i);

    vector<ll> sub(N);
    function<ll(int)> sub_dfs = [&](int u) {
        sub[u] = C[u];
        for (int v : G[u]) sub[u] += sub_dfs(v);
        return sub[u] - D[u];
    };
    sub_dfs(0);

    auto comb = [&](ll n, int m) {
        if (n < m) return mint(0);
        mint res = 1;
        for (int i = 0; i < m; i++) res *= mint(n - i) * mint(i + 1).inv();
        return res;
    };

    function<mint(int)> dfs = [&](int u) {
        mint cur = comb(sub[u], D[u]);
        for (int v : G[u]) cur *= dfs(v);
        return cur;
    };

    cout << dfs(0).val() << endl;
}
