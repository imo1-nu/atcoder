#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

#define INF 1e9

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        G[B].push_back(A);
        if (A != 0) G[A].push_back(B);
    }

    auto bfs = [&](int s) -> vector<int> {
        vector<int> dist(N + 1, INF);
        queue<int> que;
        dist[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int u : G[v]) {
                if (dist[u] != INF) continue;
                dist[u] = dist[v] + 1;
                que.push(u);
            }
        }
        return dist;
    };
    auto dist1 = bfs(1);
    auto distN = bfs(N);

    for (int i = 1; i <= N; ++i) {
        vector<int> dist(4);
        dist[0] = dist1[N];
        dist[1] = dist1[i] + distN[0];
        dist[2] = dist1[0] + distN[i];
        dist[3] = dist1[0] + distN[0];
        int ans = *min_element(dist.begin(), dist.end());
        if (ans == INF) cout << -1 << ' ';
        else cout << ans << ' ';
    }
    cout << endl;
}
