#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        --A[i];
    }
    vector<vector<int>> inv(N);
    atcoder::scc_graph g(N);
    for (int i = 0; i < N; ++i) {
        inv[A[i]].push_back(i);
        g.add_edge(i, A[i]);
    }
    auto scc = g.scc();

    vector<int> cnt(N);
    for (int i = 0; i < scc.size(); ++i) {
        for (int j = 0; j < scc[i].size(); ++j) {
            cnt[scc[i][j]] = scc[i].size();
        }
    }

    function<void(int, int)> dfs = [&](int v, int p) {
        for (int u : inv[v]) {
            if (u == p || u == v || cnt[u] > 1) continue;
            cnt[u] += cnt[v];
            dfs(u, v);
        }
    };

    for (int i = scc.size() - 1; i >= 0; --i) {
        for (int j = 0; j < scc[i].size(); ++j) {
            dfs(scc[i][j], -1);
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += cnt[i];
    }
    cout << ans << endl;
}
