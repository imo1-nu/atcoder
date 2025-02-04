#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

struct Edge {
    long long to; //行き先
    long long cost; //辺の長さ
};
using Graph = vector<vector<Edge>>;
using P = pair<int, int>;
const int INF = 1e9;

/* dijkstra(G,s,d)
    入力：グラフ G, 開始点 s, 距離を格納する d
    計算量: O(|E|log|V|)
    副作用: d が書き換えられる
*/
void dijkstra(const Graph &G, int s) {
    int N = G.size();
    vector<int> d(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    pq.emplace(0, s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (d[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        if (v == s && d[s] != INF) {
            cout << d[s] << endl;
            return;
        }
        for (auto &e : G[v]) {
            if (d[e.to] > p.first + e.cost) {  // 最短距離候補なら priority_queue に追加
                d[e.to] = p.first + e.cost;
                pq.emplace(d[e.to], e.to);
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
    }
    for (int i = 0; i < N; i++) dijkstra(G, i);
}
