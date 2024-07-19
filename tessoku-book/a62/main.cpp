#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using Graph = vector<vector<int>>;
vector<bool> b(100000, false);
Graph g(100000);

void dfs(int s) {
    b[s] = true;
    for (int i = 0; i < g[s].size(); i++) {
        int t = g[s][i];
        if (!b[t]) {
            dfs(t);
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }

    dfs(0);

    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (!b[i]) ans = false;
    }

    if (ans) cout << "The graph is connected." << endl;
    else cout << "The graph is not connected." << endl;
    
    
}
