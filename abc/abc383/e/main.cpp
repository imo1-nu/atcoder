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
    vector<tuple<ll, int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end());

    vector<int> A(K), B(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < K; i++) {
        cin >> B[i];
        B[i]--;
    }

    atcoder::dsu d(N);
    vector<ll> cnt(N);
    for (int i = 0; i < K; i++) {
        cnt[A[i]]++;
        cnt[B[i]]--;
    }

    ll ans = 0;
    for (int i = 0; i < M; i++) {
        auto [w, u, v] = edges[i];
        if (d.same(u, v)) continue;
        ll cnt1 = cnt[d.leader(u)];
        ll cnt2 = cnt[d.leader(v)];
        d.merge(u, v);
        cnt[d.leader(u)] = cnt1 + cnt2;
        if (cnt1 * cnt2 < 0) ans += w * min(abs(cnt1), abs(cnt2));
    }
    cout << ans << endl;
}
