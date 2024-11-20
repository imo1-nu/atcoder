#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using Graph = vector<vector<int>>;
void bfs(Graph G, vector<int> &dist, int start) { //G, distを用意する
    //初期条件
    dist[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; //発見済みの点はスルー

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
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        for (int j = 0; j < A[i]; j++) {
            int x;
            cin >> x;
            x--;
            G[i].push_back(N + x);
            G[N + x].push_back(i);
        }
    }

    vector<int> dist(N + M, -1);
    bfs(G, dist, N);
    cout << dist[N + M - 1] / 2 - 1 << endl;
}
