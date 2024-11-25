#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int N;
vector<ll> X, Y, P;
vector<bool> used;
vector<vector<pair<ll, int>>> dist;

void bfs(int start, ll S) { //G, distを用意する
    //初期条件
    used[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (auto p : dist[v]) {
            if (used[p.second]) continue; //発見済みの点はスルー
            if (p.first > P[v] * S) break; //距離がSを超えたら終了

            q.push(p.second);
            used[p.second] = true;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    X.resize(N);
    Y.resize(N);
    P.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> P[i];
    }

    dist.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            dist[i].push_back({abs(X[i] - X[j]) + abs(Y[i] - Y[j]), j});
        }
    }
    for (int i = 0; i < N; i++) {
        sort(dist[i].begin(), dist[i].end());
    }

    ll l = 0, r = 4e9;
    while (l + 1 < r) {
        ll S = (l + r) / 2;
        bool ok = false;
        for (int i = 0; i < N; i++) {
            used.assign(N, false);
            bfs(i, S);
            for (int j = 0; j < N; j++) {
                if (!used[j]) {
                    break;
                }
                if (j == N - 1) {
                    ok = true;
                }
            }
        }
        if (ok) {
            r = S;
        } else {
            l = S;
        }
    }
    cout << r << endl;
}
