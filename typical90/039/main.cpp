#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll ans = 0;

void dfs(int u, int par, vector<vector<int>>& G, vector<int>& dp) {
    dp[u] = 1;
    for (int v : G[u]) {
        if (v != par) {
            dfs(v, u, G, dp);
            dp[u] += dp[v];
        }
    }
    ans += dp[u] * (G.size() - dp[u]);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N - 1), B(N - 1);
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    vector<int> dp(N);
    dfs(0, -1, G, dp);
    cout << ans << '\n';
}
