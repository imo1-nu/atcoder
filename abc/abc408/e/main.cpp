#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[i] = {w, u, v};
    }
    int ans = (1 << 30) - 1;
    for (int k = 29; k >= 0; k--) {
        ans ^= (1 << k);
        atcoder::dsu d(N);
        for (auto [w, u, v] : edges) {
            if ((ans | w) == ans) d.merge(u, v);
        }
        if (!d.same(0, N - 1)) ans ^= (1 << k);
    }
    cout << ans << endl;
}
