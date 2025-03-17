#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<set<int>> G(N * K);
    for (int i = 0; i < N * K - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < N * K; i++) {
        pq.emplace(G[i].size(), i);
    }
    atcoder::dsu D(N * K);
    vector<bool> deleted(N * K);
    vector<int> cnt(N * K, 1);
    while (!pq.empty()) {
        auto [_, u] = pq.top();
        pq.pop();
        if (deleted[u]) continue;
        deleted[u] = true;

        if (G[u].size() == 0) continue;
        int v = *G[u].begin();
        G[v].erase(u);
        pq.emplace(G[v].size(), v);

        int x = cnt[D.leader(u)];
        int y = cnt[D.leader(v)];
        if (x >= K) continue;
        D.merge(u, v);
        cnt[D.leader(u)] = x + y;
        if (y == 1) continue;
        deleted[v] = true;
        for (int w : G[v]) {
            G[w].erase(v);
            pq.emplace(G[w].size(), w);
        }
    }

    bool ok = true;
    for (auto v : D.groups()) {
        if (v.size() != K) {
            ok = false;
            break;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
