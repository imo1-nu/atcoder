#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    vector<vector<int>> G(N);
    atcoder::scc_graph scc(N);
    vector<bool> is_cycle(N);
    for (int i = 0; i < N; i++) {
        G[A[i]].push_back(i);
        scc.add_edge(A[i], i);
        if (A[i] == i) is_cycle[i] = true;

    }
    auto sccs = scc.scc();
    for (auto &v : sccs) {
        if (v.size() > 1) {
            for (int i : v) {
                is_cycle[i] = true;
            }
        }
    }

    vector<vector<mint>> dp(N, vector<mint>(M, 1));
    auto dfs = [&](auto &dfs, int i) -> void {
        for (int j : G[i]) {
            if (is_cycle[j]) continue;
            dfs(dfs, j);
            mint sum = 0;
            for (int k = 0; k < M; k++) {
                sum += dp[j][k];
                dp[i][k] *= sum;
            }
        }
    };
    
    mint ans = 1;
    for (auto &v : sccs) {
        if (!is_cycle[v[0]]) continue;
        vector<mint> prod(M, 1);
        for (int i : v) {
            dfs(dfs, i);
            for (int j = 0; j < M; j++) {
                prod[j] *= dp[i][j];
            }
        }
        mint sum = 0;
        for (int i = 0; i < M; i++) {
            sum += prod[i];
        }
        ans *= sum;
    }
    cout << ans.val() << endl;
}
