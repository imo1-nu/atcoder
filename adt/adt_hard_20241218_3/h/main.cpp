#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    mint ans = 1;
    int n, m;
    vector<bool> used(N);
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int u : G[v]) {
            m++;
            if (u == p) continue;
            if (used[u]) continue;
            used[u] = true;
            n++;
            dfs(u, v);
        }
    };

    for (int i = 0; i < N; ++i) {
        if (used[i]) continue;
        n = 1, m = 0;
        used[i] = true;
        dfs(i, -1);
        if (n == m / 2) ans *= 2;
        else ans = 0;
    }
    cout << ans.val() << endl;
}
