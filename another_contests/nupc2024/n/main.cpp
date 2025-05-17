#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<vector<int>> G(N);
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans = 0;
    int cnt;
    ll sum;
    vector<bool> visited(N, false);
    function<void(int, int)> dfs = [&](int v, int p) {
        if (sum * A[v] > K || visited[v]) return;
        cnt++;
        sum *= A[v];
        ans = max(ans, cnt - 1);
        visited[v] = true;
        for (int u : G[v]) {
            if (u == p) continue;
            dfs(u, v);
        }
        cnt--;
        sum /= A[v];
        visited[v] = false;
    };
    for (int i = 0; i < N; i++) {
        cnt = 0;
        sum = 1;
        dfs(i, -1);
    }
    cout << ans << endl;
}
