#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N1;
    cin >> N1;
    vector<vector<int>> G1(N1);
    for (int i = 0; i < N1 - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }
    int N2;
    cin >> N2;
    vector<vector<int>> G2(N2);
    for (int i = 0; i < N2 - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G2[u].push_back(v);
        G2[v].push_back(u);
    }

    int maxDist = 0;
    int maxVertex = 0;
    function<void(int, int, int, vector<vector<int>>&)> treeDFS = [&](int from, int current, int dist, vector<vector<int>>& G) {
        // 距離と終点を更新
        if (dist > maxDist) {
            maxDist = dist;
            maxVertex = current;
        }

        for (auto to : G[current]) {
            // 逆流を防ぐ
            if (to == from) continue;
            treeDFS(current, to, dist + 1, G);
        }
    };
    treeDFS(-1, 0, 0, G1);
    int a = maxVertex;
    maxDist = 0;
    treeDFS(-1, a, 0, G1);
    int b = maxVertex;
    maxDist = 0;
    treeDFS(-1, 0, 0, G2);
    int c = maxVertex;
    maxDist = 0;
    treeDFS(-1, c, 0, G2);
    int d = maxVertex;

    function<void(int, int, vector<int>&, vector<vector<int>>&)> dfs = [&](int from, int current, vector<int>& dist, vector<vector<int>>& G) {
        for (auto to : G[current]) {
            if (to == from) continue;
            dist[to] = dist[current] + 1;
            dfs(current, to, dist, G);
        }
    };
    vector<int> dista(N1), distb(N1), distc(N2), distd(N2);
    dfs(-1, a, dista, G1);
    dfs(-1, b, distb, G1);
    dfs(-1, c, distc, G2);
    dfs(-1, d, distd, G2);
    vector<int> dist1(N1);
    vector<int> dist2(N2);
    for (int i = 0; i < N1; i++) {
        dist1[i] = max(dista[i], distb[i]);
    }
    for (int i = 0; i < N2; i++) {
        dist2[i] = max(distc[i], distd[i]);
    }
    sort(dist1.begin(), dist1.end());
    sort(dist2.begin(), dist2.end());
    vector<ll> S(N2 + 1);
    for (int i = 1; i <= N2; i++) {
        S[i] = S[i - 1] + dist2[i - 1];
    }
    ll D = max(dista[b], distc[d]);
    ll ans = 0;
    for (ll d : dist1) {
        int idx = lower_bound(dist2.begin(), dist2.end(), D - d - 1) - dist2.begin();
        ans += D * idx + S[N2] - S[idx] + (ll)(d + 1) * (N2 - idx);
    }
    cout << ans << endl;
}
