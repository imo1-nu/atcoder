#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// https://github.com/imo1-nu/atcoder/tree/main/lib

struct T {
    int from;
    int to;
    int cost;
};

struct Edge {
    int to; //行き先
    int cost; //辺の長さ
};

using Graph = vector<vector<Edge>>;
using P = pair<int, int>;
using mint = atcoder::modint998244353;

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

    vector<mint> ans(N);
    vector<bool> used(N);
    priority_queue<T, vector<T>, greater<T>> pq;
    while (!pq.empty()) {
        T p = pq.top();
        pq.pop();
        int v = p.to;
        if (used[v]) continue;
        used[v] = true;
        ans[v] = ans[p.from] * 10 + p.cost;
        for (auto &e : G[v]) {
            if (!used[e.to]) pq.emplace(v, e.to, e.cost);
        }
    }
}
