#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> par;
    vector<int> size;
    
    UnionFind(int N) : par(N), size(N) {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }
    
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (size[rx] < size[ry]) {
            par[rx] = ry;
            size[ry] += size[rx];
        }
        else {
            par[ry] = rx;
            size[rx] += size[ry];
        }
    }
    
    bool same(int x, int y) {
        if (root(x) == root(y)) return true;
        return false;
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    vector<int> depth(N, 0);
    vector<bool> odd_roop(N, false);
    vector<vector<int>> G(N);
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int u : G[v]) {
            if (u == p) continue;
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    };
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        u--;
        v--;
        if (t == 1) {
            if (uf.same(u, v)) {
                if ((depth[u] + depth[v]) % 2 == 0) odd_roop[uf.root(u)] = true;
            }
            else {
                if (uf.size[uf.root(u)] < uf.size[uf.root(v)]) {
                    swap(u, v);
                }
                G[u].push_back(v);
                G[v].push_back(u);
                depth[v] = depth[u] + 1;
                dfs(v, u);
                odd_roop[uf.root(u)] = odd_roop[uf.root(u)] || odd_roop[uf.root(v)];
                uf.unite(u, v);
            }
        }
        else {
            if (uf.same(u, v) && ((depth[u] + depth[v]) % 2 == 0 || odd_roop[uf.root(u)])) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
}
