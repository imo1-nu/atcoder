#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    atcoder::scc_graph g(N);
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (A[u] > A[v]) swap(u, v);
        g.add_edge(u, v);
        if (A[u] < A[v]) G[u].push_back(v);
        else g.add_edge(v, u);
    }
    auto scc = g.scc();

    vector<int> dp(N, -1e9);
    dp[0] = 1;
    for (auto &v : scc) {
        int cnt = -1e9;
        for (int u : v) cnt = max(cnt, dp[u]);
        for (int u : v) {
            dp[u] = cnt;
            for (int to : G[u]) {
                dp[to] = max(dp[to], cnt + 1);
            }
        }
    }
    cout << max(0, dp[N - 1]) << endl;
}
