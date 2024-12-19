#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

struct Edge {
    int to; //行き先
    int cost; //辺の長さ
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
    
    int N, M, K;
    cin >> N >> M >> K;
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    vector<pair<int, int>> E;
    for (int i = 0; i < K; ++i) {
        int c, t;
        cin >> c >> t;
        c--;
        E.push_back({t, c});
    }
    E.push_back({0, 0});
    sort(E.begin(), E.end());

    vector<int> dp(K + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < K; ++i) {
        if (dp[i] == -1) continue;
        vector<ll> d;
        dijkstra(G, E[i].second, d);
        for (int j = i + 1; j <= K; ++j) {
            if (E[j].first - E[i].first < d[E[j].second]) continue;
            dp[j] = max(dp[j], dp[i] + 1);
        }
    }

    int ans = 0;
    for (int i = 1; i <= K; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}
