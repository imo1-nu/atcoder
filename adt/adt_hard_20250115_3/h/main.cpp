#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, K;
    cin >> N >> M >> K;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.emplace_back(w, u, v);
    }
    sort(edges.begin(), edges.end());

    vector<int> cnt(N);
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        a--;
        cnt[a]++;
    }
    for (int i = 0; i < K; i++) {
        int b;
        cin >> b;
        b--;
        cnt[b]--;
    }

    ll ans = 0;
    atcoder::dsu d(N);
    for (auto [w, u, v] : edges) {
        if (d.same(u, v)) continue;
        int cnt_u = cnt[d.leader(u)];
        int cnt_v = cnt[d.leader(v)];
        d.merge(u, v);
        if (cnt_u / abs(cnt_u) * cnt_v < 0) {
            ll mn = min(abs(cnt_u), abs(cnt_v));
            ans += mn * w;
        }
        cnt[d.leader(u)] = cnt_u + cnt_v;
    }
    cout << ans << endl;
}
