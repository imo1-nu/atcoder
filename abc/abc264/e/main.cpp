#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, E;
    cin >> N >> M >> E;

    vector<int> U(E), V(E);
    for (int i = 0; i < E; i++) {
        cin >> U[i] >> V[i];
        U[i]--; V[i]--;
    }

    int Q;
    cin >> Q;
    vector<int> X(Q);
    for (int i = 0; i < Q; i++) {
        cin >> X[i];
        X[i]--;
    }

    vector<bool> is_deleted(E);
    for (int i = 0; i < Q; i++) {
        is_deleted[X[i]] = true;
    }

    atcoder::dsu dsu(N + M);
    vector<bool> is_connected(N + M);
    int cur = 0;
    for (int i = N; i < N + M; i++) {
        is_connected[i] = true;
    }
    for (int i = 0; i < E; i++) {
        if (is_deleted[i] || dsu.same(U[i], V[i])) continue;
        bool f1 = is_connected[dsu.leader(U[i])];
        bool f2 = is_connected[dsu.leader(V[i])];
        if (!f1 && f2) cur += dsu.size(U[i]);
        if (f1 && !f2) cur += dsu.size(V[i]);
        is_connected[dsu.merge(U[i], V[i])] = f1 || f2;
    }

    vector<int> ans;
    for (int i = Q - 1; i >= 0; i--) {
        int x = X[i];
        ans.push_back(cur);
        if (dsu.same(U[x], V[x])) continue;
        bool f1 = is_connected[dsu.leader(U[x])];
        bool f2 = is_connected[dsu.leader(V[x])];
        if (!f1 && f2) cur += dsu.size(U[x]);
        if (f1 && !f2) cur += dsu.size(V[x]);
        is_connected[dsu.merge(U[x], V[x])] = f1 || f2;
    }
    reverse(ans.begin(), ans.end());
    for (int a : ans) {
        cout << a << endl;
    }
}
