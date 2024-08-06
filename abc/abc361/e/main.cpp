#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    ll to; //行き先
    ll cost; //辺の長さ
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, ll>;



int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    Graph g(n);
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[--a].push_back(Edge{--b, c});
        g[b].push_back(Edge{a, c});
        ans += 2 * c;
    }
    
}
