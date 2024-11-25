#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

struct Edge {
    int to; //行き先
    long long cost; //辺の長さ
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, int>;
const long long INF = 1LL << 60;

/* dijkstra(G,s,d)
    入力：グラフ G, 開始点 s, 距離を格納する d
    計算量: O(|E|log|V|)
    副作用: d が書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<ll> &d) {
    int N = G.size();
    d.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    d[s] = 0;
    pq.emplace(d[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
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

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<ll> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    Graph G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (H[u] < H[v]) swap(u, v);
        G[u].push_back({v, 0});
        G[v].push_back({u, H[u] - H[v]});
    }

    vector<ll> d;
    dijkstra(G, 0, d);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, H[0] - H[i] - d[i]);
    }
    cout << ans << endl;
}
