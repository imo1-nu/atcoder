#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

ll N, L, R;
vector<ll> par(1 << 20, -1);

//using Graph = vector<vector<ll>>;
void bfs(Graph G, vector<ll> &dist, ll start) { //G, distを用意する
    //初期条件
    dist[start] = 0;
    queue<ll> q;
    q.push(start);

    while (!q.empty()) {
        ll v = q.front();
        q.pop();

        for (ll nv : G[v]) {
            if (dist[nv] != -1) continue; //発見済みの点はスルー

            dist[nv] = dist[v] + 1; //したい処理に応じて変更
            par[nv] = v;


            q.push(nv);
        }
    }
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> L >> R;
    vector<vector<pair<ll, ll>>> p(1 << N + 1, vector<pair<ll, ll>>(1 << N, {-1, -1}));

    vector<vector<ll>> G(1 << N + 1);
    for (ll i = 0; i <= 1 << N; i++) {

        for (ll j = 0; j <= N; j++) {
            ll k = 1 << j;
            if (i != 0) {
                G[i].push_back(i - k);
                p[i][i - k] = {j, (i - k) / k};
            }
            if (i + k <= 1 << N) {
                G[i].push_back(i + k);
                p[i][i + k] = {j, i / k};
            }

            ll e = i & k;
            if (e != 0) break;
        }
    }

    /*for (ll i = 0; i <= 1 << N; i++) {
        for (ll nv : G[i]) {
            cout << i << ' ' << nv << endl;
        }
        cout << endl;
    }*/
    

    vector<ll> dist(1 << N + 1, -1);
    bfs(G, dist, L);

    ll v = R + 1;
    while (v != L) {
        cout << v << '>' << par[v] << endl;
        v = par[v];
    }
    


    v = R + 1;
    ll ans = 0;
    while (v != L) {
        ll a, b;
        a = p[par[v]][v].first;
        b = p[par[v]][v].second;
        cout << '?' << ' ' << a << ' ' << b << endl;
        ll c;
        cin >> c;
        if (par[v] > v) ans = (ans - c + 100) % 100;
        else ans = (ans + c + 100) % 100;
        v = par[v];
    }
    cout << ans << endl;
}
