#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> par;
    vector<int> size;
    
    UnionFind(int N) : par(N), size(N) {
        for(int i = 0; i < N; i++) par[i] = i;
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


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    vector<set<int>> SET(N);
    for (int i = 0; i < N; i++) {
        SET[i].insert(i);
    }
    
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if (uf.same(u, v)) continue;

            int p1 = uf.root(u);
            int p2 = uf.root(v);
            uf.unite(u, v);
            if (uf.root(u) != p1) swap(p1, p2);
            SET[p1].merge(SET[p2]);
            if (SET[p1].size() > 10) {
                auto it = SET[p1].end();
                advance(it, -11);
                SET[p1].erase(SET[p1].begin(), it);
            }
        }
        else {
            int v, k;
            cin >> v >> k;
            v--; k--;
            int p = uf.root(v);
            if (k < SET[p].size()) {
                auto it = SET[p].end();
                advance(it, - k - 1);
                cout << *it + 1 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
}
