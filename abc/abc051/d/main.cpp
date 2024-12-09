#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), C(M);
    vector<vector<int>> dist(N, vector<int>(N, 1e9));
    for (int i = 0; i < N; i++) dist[i][i] = 0;
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
        dist[A[i]][B[i]] = dist[B[i]][A[i]] = C[i];
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = M;
    for (int i = 0; i < M; i++) {
        if (C[i] == dist[A[i]][B[i]]) ans--;
    }
    cout << ans << endl;
}
