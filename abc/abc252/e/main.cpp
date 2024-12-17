#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

struct Edge {
    int to; //行き先
    int cost; //辺の長さ
    int id; //辺の番号
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, int>;
const long long INF = 1LL << 60;

/* dijkstra(G,s,d)
    入力：グラフ G, 開始点 s, 距離を格納する d
    計算量: O(|E|log|V|)
    副作用: d が書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<ll> &d, vector<int> &idx) {
    int N = G.size();
    d.resize(N, INF);
    idx.resize(N, -1);
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
                idx[e.to] = e.id;
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
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        G[u].push_back({v, c, i});
        G[v].push_back({u, c, i});
    }

    vector<ll> d;
    vector<int> idx;
    dijkstra(G, 0, d, idx);
    for (int i = 1; i < N; ++i) {
        cout << idx[i] + 1 << ' ';
    }
    cout << endl;
}
