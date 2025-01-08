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
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<ll> C(N);
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        sum += C[i];
    }

    vector<ll> ans(N), sub = C;
    function<void(int, int, int)> dfs = [&](int v, int p, int d) {
        ans[0] += C[v] * d;
        for (int u : G[v]) {
            if (u == p) continue;
            dfs(u, v, d + 1);
            sub[v] += sub[u];
        }
    };
    dfs(0, -1, 0);
    function<void(int, int)> dfs2 = [&](int v, int p) {
        for (int u : G[v]) {
            if (u == p) continue;
            ans[u] = ans[v] + sum - 2 * sub[u];
            dfs2(u, v);
        }
    };
    dfs2(0, -1);

    cout << *min_element(ans.begin(), ans.end()) << endl;
}
