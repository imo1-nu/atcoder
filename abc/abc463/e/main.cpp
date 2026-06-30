#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

struct Edge {
    int to; //行き先
    int cost; //辺の長さ
};
using Graph = vector<vector<Edge>>;
using P = pair<int, ll>;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, Y;
    cin >> N >> M >> Y;
    Graph G(N + 2);
    for (int i = 0; i < M; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        G[u].push_back({v, t});
        G[v].push_back({u, t});
    }
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        G[i].push_back({N, x});
        G[N + 1].push_back({i, x});
    }
    G[N].push_back({N + 1, Y});

    vector<ll> dist(N + 2, INF);
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[0] = 0;
    pq.push({dist[0], 0});
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (auto &e : G[v]) {
            if (dist[e.to] <= dist[v] + e.cost) continue;
            dist[e.to] = dist[v] + e.cost;
            pq.emplace(dist[e.to], e.to);
        }
    }
    for (int i = 1; i < N; i++) cout << dist[i] << ' ';
    cout << endl;
}
