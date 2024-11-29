#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, M;
    cin >> N >> M;

    vector<vector<ll>> dist(N, vector<ll>(N, 1e18));
    for (ll i = 0; i < M; i++) {
        ll u, v, l;
        cin >> u >> v >> l;
        u--; v--;
        dist[u][v] = dist[v][u] = l;
    }

    for (ll i = 0; i < N; i++) {
        dist[i][i] = 0;
    }

    for (ll k = 1; k < N; k++) {
        for (ll i = 1; i < N; i++) {
            for (ll j = 1; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ll ans = 1e18;
    for (ll i = 1; i < N; i++) {
        for (ll j = i + 1; j < N; j++) {
            ll d = dist[0][i] + dist[i][j] + dist[j][0];
            ans = min(ans, d);
        }
    }

    if (ans == 1e18) cout << -1 << endl;
    else cout << ans << endl;
}
