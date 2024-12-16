#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<ll> sub(N, 1), ans(N);
    function<void(int, int, int)> dfs = [&](int i, int p, int d) {
        ans[0] += d;
        for (int j : G[i]) {
            if (j == p) continue;
            dfs(j, i, d + 1);
            sub[i] += sub[j];
        }
    }; dfs(0, -1, 0);
    function<void(int, int)> dfs2 = [&](int i, int p) {
        for (int j : G[i]) {
            if (j == p) continue;
            ans[j] = ans[i] - 2 * sub[j] + N;
            dfs2(j, i);
        }
    }; dfs2(0, -1);
    
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << endl;
    }
}
