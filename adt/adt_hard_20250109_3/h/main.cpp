#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(M), B(M) ,C(M), E(K);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--, B[i]--;
    }
    for (int i = 0; i < K; i++) {
        cin >> E[i];
        E[i]--;
    }

    vector<ll> dist(N, 1e18);
    dist[0] = 0;
    for (int i = 0; i < K; i++) {
        dist[B[E[i]]] = min(dist[B[E[i]]], dist[A[E[i]]] + C[E[i]]);
    }

    if (dist[N - 1] == 1e18) cout << -1 << endl;
    else cout << dist[N - 1] << endl;
}
