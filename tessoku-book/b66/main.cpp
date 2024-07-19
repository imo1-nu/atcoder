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
    
    int n, m, q;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    cin >> q;
    vector<int> Qtype(q), x(q), u(q), v(q);
    vector<bool> canceled(m);
    for (int i = 0; i < q; i++) {
        cin >> Qtype[i];
        if (Qtype[i] == 1) {
            cin >> x[i];
            x[i]--;
            canceled[x[i]] = true;
        }
        else {
            cin >> u[i] >> v[i];
            u[i]--;
            v[i]--;
        }
    }

    UnionFind tree(n);
    for (int i = 0; i < m; i++) {
        if (!canceled[i]) tree.unite(a[i], b[i]);
    }
    
    stack<bool> ans;
    for (int i = q - 1; i >= 0; i--) {
        if (Qtype[i] == 1) tree.unite(a[x[i]], b[x[i]]);
        else {
            if (tree.same(u[i], v[i])) {
                ans.push(true);
            }
            else ans.push(false);
        }
    }
    
    while (!ans.empty()) {
        if (ans.top()) cout << "Yes" << endl;
        else cout << "No" << endl;
        ans.pop();
    }
}
