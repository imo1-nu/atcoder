#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include<bits/stdc++.h>

using namespace std;

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
    
    int n, q;
    cin >> n >> q;
    UnionFind t(n);
    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        b--;
        c--;
        if (a == 1) {
            t.unite(b, c);
        }
        else {
            if (t.root(b) == t.root(c)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
}
