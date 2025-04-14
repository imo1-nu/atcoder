#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[v].push_back(u);
    }
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        sort(G[i].begin(), G[i].end());
        if (G[i].size() > 0) {
            A[G[i][0]]++;
            A[i]--;
        }
    }
    vector<int> ans(N + 1);
    for (int i = 1; i <= N; i++) {
        ans[i] = ans[i - 1] + A[i - 1];
    }

    atcoder::dsu dsu(N);
    for (int i = 0; i < N; i++) {
        for (auto e : G[i]) {
            dsu.merge(i, e);
        }
        if (dsu.size(0) == i + 1) cout << ans[i + 1] << '\n';
        else cout << -1 << '\n';
    }
}
