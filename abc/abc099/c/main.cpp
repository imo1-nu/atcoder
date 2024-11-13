#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<int> dn;

void bfs(vector<ll> &dist, ll start) { //G, distを用意する
    //初期条件
    dist[start] = 0;
    queue<ll> q;
    q.push(start);

    while (!q.empty()) {
        ll v = q.front();
        q.pop();

        for (ll n : dn) {
            ll nv = v - n;
            if (nv < 0) continue;
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
    
    int N;
    cin >> N;
    dn.push_back(1);
    for (int i = 6; i <= 100000; i *= 6) dn.push_back(i);
    for (int i = 9; i <= 100000; i *= 9) dn.push_back(i);

    vector<ll> dist(100001, -1);
    bfs(dist, N);
    cout << dist[0] << endl;
}
