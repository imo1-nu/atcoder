#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using Graph = vector<vector<ll>>;
void bfs(Graph G, vector<ll> &dist, ll start) { //G, distを用意する
    //初期条件
    dist[start] = 0;
    queue<ll> q;
    q.push(start);

    while (!q.empty()) {
        ll v = q.front();
        q.pop();

        for (ll nv : G[v]) {
            if (dist[nv] != -2) continue; //発見済みの点はスルー

            dist[nv] = dist[v] + 1; //したい処理に応じて変更

            q.push(nv);
        }
    }
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    Graph G(N + M);
    for (int i = 0; i < M; i++) {
        int k, r;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> r;
            r--;
            G[N + i].push_back(r);
            G[r].push_back(N + i);
        }
    }
    vector<ll> dist(N + M, -2);
    bfs(G, dist, 0);
    for (int i = 0; i < N; i++) {
        cout << dist[i] / 2 << endl;
    }
}
