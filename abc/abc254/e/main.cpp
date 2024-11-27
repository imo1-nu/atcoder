#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using Graph = vector<vector<int>>;
int bfs(Graph &G, vector<int> &dist, int start, int k) { //G, distを用意する
    //初期条件
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    vector<int> used = {start};

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (dist[v] == k) break;

        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; //発見済みの点はスルー

            dist[nv] = dist[v] + 1; //したい処理に応じて変更
            used.push_back(nv);
            q.push(nv);
        }
    }

    int res = 0;
    for (auto i : used) {
        res += i + 1;
        dist[i] = -1;
    }
    return res;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int Q;
    cin >> Q;
    vector<int> dist(N, -1);
    while (Q--) {
        int x, k;
        cin >> x >> k;
        x--;
        cout << bfs(G, dist, x, k) << endl;
    }
}
