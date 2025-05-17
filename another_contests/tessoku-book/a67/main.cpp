#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using Edge = tuple<ll, ll, ll>;

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
};



int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;
    UnionFind t(n);
    vector<Edge> e(m);
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        e[i] = {c, a, b};
    }
    sort(e.begin(), e.end());
    ll ans = 0;
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        c = get<0>(e[i]);
        a = get<1>(e[i]);
        b = get<2>(e[i]);
        if (t.root(a) != t.root(b)) {
            t.unite(a, b);
            ans += c;
        }
    }
    cout << ans << endl;
}
