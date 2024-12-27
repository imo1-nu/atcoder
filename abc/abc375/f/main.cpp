#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<tuple<ll, int, int>> R(M);
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        R[i] = {C, A - 1, B - 1};
    }

    vector<tuple<int, int, int>> query;
    vector<bool> used(M, true);
    for (int i = 0; i < Q; i++) {
        int t, x, y;
        cin >> t >> x;
        x--;
        if (t == 1) {
            query.push_back({t, x, -1});
            used[x] = false;
        }
        else {
            cin >> y;
            y--;
            query.push_back({t, x, y});
        }
    }

    vector<vector<ll>> dist(N, vector<ll>(N, 1e18));
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        if (used[i]) {
            auto [C, A, B] = R[i];
            dist[A][B] = dist[B][A] = C;
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<ll> ans;
    while (Q--) {
        auto [t, x, y] = query[Q];
        if (t == 1) {
            auto [C, A, B] = R[x];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][A] + C + dist[B][j]);
                    dist[i][j] = min(dist[i][j], dist[i][B] + C + dist[A][j]);
                }
            }
        }
        else {
            ll d = dist[x][y];
            if (d == 1e18) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(d);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto a : ans) {
        cout << a << endl;
    }
}
