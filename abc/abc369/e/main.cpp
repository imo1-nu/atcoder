#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

struct Edge {
    int from;
    int to;
    ll cost;
    Edge(int from, int to, ll cost) : from(from), to(to), cost(cost) {}
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<Edge> G;
    vector<vector<ll>> dist(N, vector<ll>(N, 1e18));
    for (int i = 0; i < M; i++) {
        int u, v;
        ll t;
        cin >> u >> v >> t;
        u--; v--;
        G.push_back(Edge(u, v, t));
        dist[u][v] = min(dist[u][v], (ll)t);
        dist[v][u] = min(dist[v][u], (ll)t);
    }

    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int K;
        cin >> K;
        vector<int> B(K);
        for (int j = 0; j < K; j++) {
            cin >> B[j];
            B[j]--;
        }
        sort(B.begin(), B.end());

        ll ans = 1e18;
        do {
            for (int i = 0; i < (1 << K); i++) {
                bitset<5> bs(i);
                queue<int> q;
                q.push(0);
                ll sum = 0;
                for (int i = 0; i < K; i++) {
                    if (bs[i]) {
                        q.push(G[B[i]].from);
                        q.push(G[B[i]].to);
                    }
                    else {
                        q.push(G[B[i]].to);
                        q.push(G[B[i]].from);
                    }
                    sum += G[B[i]].cost;
                }
                q.push(N - 1);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    int v = q.front();
                    q.pop();
                    sum += dist[u][v];
                }
                ans = min(ans, sum);
            }
        } while (next_permutation(B.begin(), B.end()));

        cout << ans << endl;
    }
}
