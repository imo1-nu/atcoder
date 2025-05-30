#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<pair<int, int>> edges(N - 1);
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = {u, v};
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> idx(N);
    vector<pair<int, int>> range(N);
    int cnt = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
        range[v].first = cnt;
        idx[v] = cnt++;
        for (int u : G[v]) {
            if (u == p) continue;
            dfs(u, v);
        }
        range[v].second = cnt;
    };
    dfs(0, -1);

    atcoder::fenwick_tree<ll> fw(N);
    for (int i = 0; i < N; i++) {
        fw.add(idx[i], 1);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, w;
            cin >> x >> w;
            x--;
            fw.add(idx[x], w);
        }
        else {
            int y;
            cin >> y;
            y--;
            auto [u, v] = edges[y];
            if (idx[u] > idx[v]) swap(u, v);
            ll sum = fw.sum(0, N);
            ll sub = fw.sum(range[v].first, range[v].second);
            cout << abs(sum - sub * 2) << endl;
        }
    }
}
