#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using Graph = vector<vector<ll>>;
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

            q.push(nv);
        }
    }
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<ll> x(m), y(m), z(m);
    for (ll i = 0; i < m; i++) {
        cin >> x[i] >> y[i] >> z[i];
        x[i]--;
        y[i]--;
        z[i]--;
    }
    
    ll num = 1 << n;
    Graph G(num);
    vector<ll> dist(num, -1);
    for (ll i = 0; i < num; i++) {
        for (ll j = 0; j < m; j++) {
            ll key = (1 << x[j]) + (1 << y[j]) + (1 << z[j]);
            ll to = i ^ key;
            G[i].push_back(to);
        }
    }
    
    ll start = 0;
    for (ll i = 0; i < n; i++) {
        start += a[i] * (1 << i);
    }

    /*for (ll i = 0; i < num; i++) {
        bitset<10> k = i;
        cout << k << endl;
        for (ll j = 0; j < G[i].size(); j++) {
            k = G[i][j];
            cout << k << endl;
        }
        cout << endl;
    }*/
    
    bfs(G, dist, start);
    cout << dist[num - 1] << endl;
}
