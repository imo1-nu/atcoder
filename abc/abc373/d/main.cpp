#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

struct Edge {
    long long to; //行き先
    long long cost; //辺の長さ
};
using Graph = vector<vector<Edge>>;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
        G[b].push_back({a, -c});
    }

    vector<ll> X(N);
    vector<bool> visited(N, false);
    for (int i = 0; i < N; ++i) {
        if (visited[i]) continue;
        queue<ll> que;
        que.push(i);
        visited[i] = true;
        while (!que.empty()) {
            ll v = que.front();
            que.pop();
            for (auto e : G[v]) {
                if (!visited[e.to]) {
                    visited[e.to] = true;
                    X[e.to] = X[v] + e.cost;
                    que.push(e.to);
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << X[i] << ' ';
    }
    cout << endl;
}
