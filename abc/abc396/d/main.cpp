#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, ll>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    vector<bool> used(N);
    ll ans = 1ll << 61;
    ll cur = 0;
    function<void(int)> dfs = [&](int u) {
        if (u == N - 1) {
            ans = min(ans, cur);
            return;
        }
        used[u] = true;
        for (auto [v, w] : G[u]) {
            if (used[v]) continue;
            else {
                cur ^= w;
                dfs(v);
                cur ^= w;
            }
        }
        used[u] = false;
    };
    dfs(0);
    cout << ans << '\n';
}
