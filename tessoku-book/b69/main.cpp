#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    ll to; //行き先
    ll cap; //容量
    ll rev; //u→G[u][i].toの逆辺はG[G[u][i].to][G[u][i].rev]
};

struct MaximumFlow {
    ll size;
    vector<bool> used;
    vector<vector<Edge>> G;

    //頂点数Nの残余グラフを準備
    MaximumFlow(ll N) {
        size = N;
        used.resize(N);
        G.resize(N);
    }

    //頂点aからbに向かう，容量上限cの辺を追加
    void add_edge(ll a, ll b, ll c) {
        ll Current_Ga = G[a].size(); //現時点でのG[a]の要素数
        ll Current_Gb = G[b].size(); //現時点でのG[b]の要素数
        G[a].push_back(Edge{b, c, Current_Gb});
        G[b].push_back(Edge{a, 0ll, Current_Ga});
    }

    //深さ優先探索（Fはスタートからposに到達する家庭での残余グラフの辺の容量の最小値）
    //返り値は流しフたローの量（流せない場合は0を返す）
    ll dfs(ll pos, ll goal, ll F) {
        //ゴールに到着：フローを流せる
        if (pos == goal) return F;
        used[pos] = true;

        //探索する
        for (ll i = 0; i < G[pos].size(); i++) {
            //容量0の辺は使えない
            if (G[pos][i].cap == 0) continue;

            //既に訪問した頂点に行っても意味がない
            if (used[G[pos][i].to] == true) continue;

            //目的地までのバスを探す
            ll flow = dfs(G[pos][i].to, goal, min(F, G[pos][i].cap));

            //フローを流せる場合，残余グラフの容量をflowだけ増減させる
            if (flow > 0) {
                G[pos][i].cap -= flow;
                G[G[pos][i].to][G[pos][i].rev].cap += flow;
                return flow;
            }
        }

        //すべての辺を探索しても見つからなかった
        return 0ll;
    }

    //頂点sから頂点sまでの最大フローの総流量を返す
    ll max_flow (ll s, ll t) {
        ll Total_Flow = 0;
        while (true) {
            for (ll i = 0; i < size; i++) used[i] = false;
            ll F = dfs(s, t, 1000000000);

            //フローを流せなくなったら操作終了
            if (F == 0ll) break;
            Total_Flow += F;
        }
        return Total_Flow;
    }
};


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<string> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    MaximumFlow MF(n + 2 + 24);
    for (int i = 0; i < n; i++) {
        MF.add_edge(n + 24, i, 10);
        for (int j = 0; j < 24; j++) {
            if (c[i][j] == '1') {
                MF.add_edge(i, n + j, 1);
            }
        }
    }
    for (int i = 0; i < 24; i++) {
        MF.add_edge(n + i, n + 25, m);
    }
    bool ans = false;
    if (MF.max_flow(n + 24, n + 25) == m * 24) ans = true;
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
