#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
    vector<ll> par;
    vector<ll> size;
    
    UnionFind(ll N) : par(N), size(N) {
        for(ll i = 0; i < N; i++) par[i] = i;
    }
    
    ll root(ll x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(ll x, ll y) {
        ll rx = root(x);
        ll ry = root(y);
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
    
    bool same(ll x, ll y) {
        if (root(x) == root(y)) return true;
        return false;
    }
};


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> edge(q, vector<ll>(4));
    for (ll i = 0; i < q; i++) {
        cin >> edge[i][1] >> edge[i][2] >> edge[i][0];
        edge[i][3] = n + i;
        edge[i][1]--; edge[i][2]--;
    }
    sort(edge.begin(), edge.end());
    UnionFind uf(n + q);
    set<ll> st;
    for (ll i = 0; i < n - 1; i++) {
        st.insert(i);
    }
    
    ll ans = 0;
    for (ll i = 0; i < q; i++) {
        uf.unite(edge[i][1], edge[i][3]);
        ans += edge[i][0];
        auto itr = st.lower_bound(edge[i][1]);
        while (*itr < edge[i][2] && itr != st.end()) {
            uf.unite(*itr, *itr + 1);
            ans += edge[i][0];
            st.erase(itr);
            itr = st.lower_bound(edge[i][1]);
        }
    }
    
    if (st.empty()) cout << ans << endl;
    else cout << -1 << endl;
}
