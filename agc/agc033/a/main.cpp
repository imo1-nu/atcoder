#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> dx = {0, 0, -1, 1};
vector<ll> dy = {-1, 1, 0, 0};
ll H, W;

bool canmove(ll x, ll y) {
    if (0 <= x && x < H && 0 <= y && y < W) return true;
    else return false;
}



queue<ll> q;

using Graph = vector<vector<ll>>;
ll bfs(Graph G, vector<ll> &dist, ll start) { //G, distを用意する
    //初期条件
    ll max = 0;

    while (!q.empty()) {
        ll v = q.front();
        q.pop();

        for (ll nv : G[v]) {
            if (dist[nv] != -1) continue; //発見済みの点はスルー

            dist[nv] = dist[v] + 1; //したい処理に応じて変更
            q.push(nv);
            if (dist[nv] > max) max = dist[nv];

            //q.push(nv);
        }
    }

    return max;
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> H >> W;

    vector<string> A(H);
    for (ll i = 0; i < H; i++) {
        cin >> A[i];
    }

    Graph G(H * W);
    vector<ll> dist(H * W, -1);
    ll start = -1;
    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                dist[i * W + j] = 0;
                if (start == -1) start = i * W + j;
                q.push(i * W + j);
            }

            for (ll k = 0; k < 4; k++) {
                if (canmove(i + dx[k], j + dy[k])) G[i * W + j].push_back((i + dx[k]) * W + j + dy[k]);
            }
            
        }
    }
    ll ans = 0;
    ans = bfs(G, dist, start);
    cout << ans << endl;
}
