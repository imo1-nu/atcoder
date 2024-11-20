#include <bits/stdc++.h>
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
        else return false;
    }
};


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    UnionFind tree(n);
    vector<vector<int>> edge(m, vector<int>(3));
    int ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> edge[i][1] >> edge[i][2] >> edge[i][0];
        edge[i][1]--;
        edge[i][2]--;
    }
    sort(edge.rbegin(), edge.rend());
    for (int i = 0; i < m; i++) {
        if (!tree.same(edge[i][1], edge[i][2])) {
            tree.unite(edge[i][1], edge[i][2]);
            ans += edge[i][0];
        }
    }
    
    cout << ans << endl;
}
