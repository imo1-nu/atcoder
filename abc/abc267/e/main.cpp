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
    vector<ll> S(N);
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        S[u] += A[v];
        S[v] += A[u];
    }

    vector<bool> erased(N);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i < N; i++) {
        pq.push({S[i], i});
    }

    ll ans = 0;
    while (!pq.empty()) {
        auto [s, u] = pq.top();
        pq.pop();
        if (erased[u]) continue;
        erased[u] = true;
        ans = max(ans, s);
        for (int v : G[u]) {
            if (erased[v]) continue;
            S[v] -= A[u];
            pq.push({S[v], v});
        }
    }
    cout << ans << endl;
}
