#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        G[A[i]].push_back(B[i]);
    }
    int ans = 0;
    vector<bool> visited(N);
    function<void(int)> dfs = [&](int u) {
        if (visited[u]) return;
        visited[u] = true;
        ans++;
        for (auto v : G[u]) dfs(v);
    };
    dfs(0);
    cout << ans << endl;
}
