#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    set<int> S;
    atcoder::dsu d(N);
    for (int i = 0; i < N; i++) {
        S.insert(i);
        for (auto v : G[i]) {
            S.insert(v);
            if (i > v) d.merge(i, v);
        }
        if (d.size(0) == i + 1) cout << S.size() - i - 1 << endl;
        else cout << -1 << endl;
    }
}
