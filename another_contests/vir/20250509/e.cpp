#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using P = pair<ll, int>;

const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    X--; Y--;
    vector<int> A(M), B(M), T(M), K(M);
    vector<vector<tuple<int, int, int>>> G(N);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> T[i] >> K[i];
        A[i]--; B[i]--;
        G[A[i]].emplace_back(B[i], T[i], K[i]);
        G[B[i]].emplace_back(A[i], T[i], K[i]);
    }

    vector<ll> d(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    d[X] = 0;
    pq.emplace(d[X], X);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (d[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            int to = get<0>(e);
            int t = get<1>(e);
            int k = get<2>(e);
            ll start = d[v] - d[v] % k;
            if (d[v] % k != 0) start += k;
            if (d[to] > start + t) {  // 最短距離候補なら priority_queue に追加
                d[to] =  start + t;
                pq.emplace(d[to], to);
            }
        }
    }

    if (d[Y] == INF) cout << -1 << endl;
    else cout << d[Y] << endl;
}
