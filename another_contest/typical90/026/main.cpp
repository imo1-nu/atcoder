#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void dfs (int v, vector<vector<int>> &G, vector<int> &depth) {
    for (int u : G[v]) {
        if (depth[u] == -1) {
            depth[u] = depth[v] + 1;
            dfs(u, G, depth);
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> depth(N, -1);
    depth[0] = 0;
    dfs(0, G, depth);
    vector<int> odd, even;
    for (int i = 0; i < N; i++) {
        if (depth[i] % 2 == 0) even.push_back(i);
        else odd.push_back(i);
    }
    if (odd.size() < even.size()) {
        for (int i = 0; i < N / 2; i++) {
            if (i > 0) cout << " ";
            cout << even[i] + 1;
        }
    }
    else {
        for (int i = 0; i < N / 2; i++) {
            if (i > 0) cout << " ";
            cout << odd[i] + 1;
        }
    }
    cout << endl;
}
