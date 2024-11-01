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

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> T(Q), X(Q), Y(Q), V(Q);
    for (int i = 0; i < Q; i++) {
        cin >> T[i] >> X[i] >> Y[i] >> V[i];
        X[i]--; Y[i]--;
    }

    vector<int> sum(N - 1);
    for (int i = 0; i < Q; i++) {
        if (T[i] == 0) {
            sum[X[i]] = V[i];
        }
    }

    vector<ll> potential(N);
    for (int i = 0; i < N - 1; i++) {
        potential[i + 1] = sum[i] - potential[i];
    }

    UnionFind uf(N);
    for (int i = 0; i < Q; i++) {
        if (T[i] == 0) {
            uf.unite(X[i], Y[i]);
        }
        else {
            if (!uf.same(X[i], Y[i])) {
                cout << "Ambiguous" << endl;
            }
            else if ((X[i] + Y[i]) % 2 == 0) {
                cout << potential[Y[i]] - potential[X[i]] + V[i] << endl;
            }
            else {
                cout << potential[Y[i]] + potential[X[i]] - V[i] << endl;
            }
        }
    }
}
