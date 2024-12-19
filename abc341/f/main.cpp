#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> W(N);
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
    }
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<pair<int, int>> P(N);
    for (int i = 0; i < N; ++i) {
        P[i] = {W[i], i};
    }
    sort(P.begin(), P.end());

    vector<int> ans(N);
    for (int i = 0; i < N; ++i) {
        int v = P[i].second;
        vector<vector<int>> dp(G[v].size() + 1, vector<int>(W[v], 0));
        for (int i = 1; i <= (int)G[v].size(); ++i) {
            int u = G[v][i - 1];
            for (int j = 0; j < W[v]; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= W[u]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - W[u]] + ans[u]);
                }
            }
        }
        for (int j = 0; j < W[v]; ++j) {
            ans[v] = max(ans[v], dp[G[v].size()][j]);
        }
        ans[v]++;
    }

    ll res = 0;
    for (int i = 0; i < N; ++i) {
        res += A[i] * ans[i];
    }
    cout << res << endl;
}
