#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<tuple<int, int, int, int>> edges(M + Q);
    for (int i = 0; i < M + Q; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        edges[i] = {c, u, v, i - M};
    }
    sort(edges.begin(), edges.end());

    atcoder::dsu d(N);
    vector<bool> ans(Q);
    for (auto e : edges) {
        int c, u, v, i;
        tie(c, u, v, i) = e;
        if (i < 0) {
            d.merge(u, v);
        }
        else {
            ans[i] = !d.same(u, v);
        }
    }

    for (int i = 0; i < Q; ++i) {
        if (ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
