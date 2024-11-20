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
    
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> item(M);
    for (int i = 0; i < M; i++) {
        int c, l, r;
        cin >> c >> l >> r;
        l--;
        item[i] = make_tuple(c, l, r);
    }
    sort(item.begin(), item.end());
    UnionFind uf(N + 1);
    ll ans = 0;
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        if (uf.same(get<1>(item[i]), get<2>(item[i]))) continue;
        uf.unite(get<1>(item[i]), get<2>(item[i]));
        ans += get<0>(item[i]);
        cnt++;
    }
    if (cnt != N) cout << -1 << endl;
    else cout << ans << endl;
}
