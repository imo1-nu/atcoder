#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> C(N);
    vector<vector<int>> G(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int, int>> q;
    q.push({0, N - 1});
    dist[0][N - 1] = 0;
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        for (int x : G[u]) {
            for (int y : G[v]) {
                if (dist[x][y] != -1) continue;
                if (C[x] == C[y]) continue;
                dist[x][y] = dist[u][v] + 1;
                q.push({x, y});
            }
        }
    }
    cout << dist[N - 1][0] << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) solve();
}
