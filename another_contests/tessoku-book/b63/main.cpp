#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using Pair = pair<ll, ll>;
vector<string> s(50);
vector<ll> dx = {0, 0, -1, 1, -1, -1, 1, 1};
vector<ll> dy = {-1, 1, 0, 0, -1, 1, 1, -1};
ll H, W;

bool canmove(ll x, ll y) {
    if (0 <= x && x < H && 0 <= y && y < W) return true;
    else return false;
}


void bfs(vector<vector<ll>> &dist, ll sy, ll sx) { //G, distを用意する
    //初期条件
    dist[sy][sx] = 0;
    queue<Pair> q;
    q.push({sy, sx});

    while (!q.empty()) {
        Pair v = q.front();
        q.pop();

        for (ll i = 0; i < 4; i++) {
            ll y = v.first + dy[i];
            ll x = v.second + dx[i];
            if (dist[y][x] != -1 || s[y][x] == '#') continue; //発見済みの点はスルー

            dist[y][x] = dist[v.first][v.second] + 1; //したい処理に応じて変更

            q.push({y, x});
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll R, C, sy, sx, gy, gx;
    cin >> R >> C >> sy >> sx >> gy >> gx;
    for (ll i = 0; i < R; i++) cin >> s[i];
    vector<vector<ll>> dist(R, vector<ll>(C, -1));
    bfs(dist, sy - 1, sx - 1);
    cout << dist[gy - 1][gx - 1] << endl;
}
