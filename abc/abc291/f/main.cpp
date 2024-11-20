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
    Graph G1(N), G2(N);
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] == '0') continue;
            G1[i].push_back(j + i + 1);
            G2[j + i + 1].push_back(i);
        }
    }

    vector<int> dist1(N, -1), dist2(N, -1);
    bfs(G1, dist1, 0);
    bfs(G2, dist2, N - 1);

    for (int i = 1; i < N - 1; i++) {
        int l = max(0, i - M);
        int ans = 1e9;
        for (int j = l; j < i; j++) {
            if (dist1[j] == -1) continue;
            for (auto x : G1[j]) {
                if (x <= i) continue;
                if (dist2[x] == -1) continue;
                ans = min(ans, dist1[j] + dist2[x] + 1);
            }
        }
        if (ans == 1e9) cout << -1;
        else cout << ans;

        if (i < N - 2) cout << " ";
    }
    cout << endl;
}
