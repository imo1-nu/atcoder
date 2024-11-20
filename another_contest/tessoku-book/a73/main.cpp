#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    long long to; //行き先
    long long cost; //辺の長さ
};
using Graph = vector<vector<Edge>>;
using P = pair<long, ll>;
const long long INF = 1LL << 60;

/* dijkstra(G,s,d)
    入力：グラフ G, 開始点 s, 距離を格納する d
    計算量：O(|E|log|V|)
    副作用：d が書き換えられる
*/
void dijkstra(const Graph &G, ll s, vector<long long> &d) {
    ll N = G.size();
    d.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    d[s] = 0;
    pq.emplace(d[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        ll v = p.second;
        if (d[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            if (d[e.to] > d[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                d[e.to] = d[v] + e.cost;
                pq.emplace(d[e.to], e.to);
            }
        }
    }
}


int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m), c(m), d(m);
    
    Graph g(n);
    vector<ll> dist;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
        c[i] *= 10000;
        if (d[i] == 1) c[i]--;
        g[a[i]].push_back(Edge{b[i], c[i]});
        g[b[i]].push_back(Edge{a[i], c[i]});
    }
    
    dijkstra(g, 0, dist);
    ll ans = (dist[n - 1] + 9999) / 10000;
    ll ans2 = ans * 10000 - dist[n - 1];
    cout << ans << ' ' << ans2 << endl;
}