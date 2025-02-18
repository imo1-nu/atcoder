#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> edges;
    int ans = 0;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (u > v) swap(u, v);
        if (u == v || edges.count({u, v})) ans++;
        edges.insert({u, v});
    }
    cout << ans << endl;
}
