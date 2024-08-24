#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll dfs(int v, int par, vector<vector<int>> &G, vector<ll> &V)
{
    ll cnt = 0;
    for (int u : G[v]) {
        if (u == par) continue;
        cnt += dfs(u, v, G, V);
    }
    if (cnt == 0 && V[v]) cnt = 1ll;
    else if (cnt > 0) cnt++;
    return cnt;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<vector<int>> G(N);
    vector<int> A(N), B(N);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    vector<ll> V(N);
    for (int i = 0; i < K; i++) {
        int v;
        cin >> v;
        V[--v] = 1ll;
    }
    for (int i = 0; i < N; i++) {
        if (V[i]) {
            cout << dfs(i, -1, G, V) << endl;
            break;
        }
    }
}
