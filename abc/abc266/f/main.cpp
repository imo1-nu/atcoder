#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<vector<int>> G;
vector<int> root;

void dfs(int v, int p) {
    root[v] = root[p];
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    G.resize(N);
    vector<int> deg(N);
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }
    vector<bool> is_cycle(N, true);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        is_cycle[v] = false;
        for (int u : G[v]) {
            deg[u]--;
            if (deg[u] == 1) {
                q.push(u);
            }
        }
    }

    root.resize(N, -1);
    for (int i = 0; i < N; i++) {
        if (is_cycle[i]) {
            root[i] = i;
            for (int u : G[i]) {
                if (!is_cycle[u]) {
                    dfs(u, i);
                }
            }
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        bool ans = root[x] == root[y];
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
