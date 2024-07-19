#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using Graph = vector<vector<ll>>;
void bfs(Graph G, vector<ll> &dist, ll start) { //G, distを用意する
    //初期条件
    dist[start] = 0;
    stack<ll> s;
    s.push(start);

    while (!s.empty()) {
        ll v = s.top();
        s.pop();

        for (ll nv : G[v]) {
            if (dist[nv] != -1) continue; //発見済みの点はスルー

            dist[nv] = dist[v] + 1; //したい処理に応じて変更

            s.push(nv);
        }
    }
}