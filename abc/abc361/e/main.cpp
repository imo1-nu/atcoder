#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    ll ans = 0;
    vector<vector<Edge>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        G[a].push_back(Edge(b, c));
        G[b].push_back(Edge(a, c));
        ans += c * 2;
    }

    ll maxDist = 0;
    int maxVertex = 0;
    function<void(int, int, ll)> treeDFS = [&](int from, int current, ll dist) {
        // 距離と終点を更新
        if (dist > maxDist) {
            maxDist = dist;
            maxVertex = current;
        }

        for (auto [to, cost] : G[current]) {
            // 逆流を防ぐ
            if (to == from) continue;
            treeDFS(current, to, dist + cost);
        }
    };
    treeDFS(-1, 0, 0);
    maxDist = 0;
    treeDFS(-1, maxVertex, 0);
    cout << ans - maxDist << endl;
}
