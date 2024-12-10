#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            edges.emplace_back(A[i][j], i, j);
        }
    }
    sort(edges.rbegin(), edges.rend());

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ans += A[i][j];
        }
    }
    int INF = 1e9 + 1;
    for (auto [c, u, v] : edges) {
        for (int i = 0; i < N; i++) {
            if (i == u || i == v || A[u][i] == INF || A[i][v] == INF) continue;
            if (A[u][i] + A[i][v] < A[u][v]) {
                cout << -1 << endl;
                return 0;
            }
            if (A[u][i] + A[i][v] == A[u][v]) {
                ans -= c;
                A[u][v] = INF;
                A[v][u] = INF;
                break;
            }
        }
    }
    cout << ans << endl;
}
