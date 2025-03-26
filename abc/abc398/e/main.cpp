#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> U(N - 1), V(N - 1);
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        cin >> U[i] >> V[i];
        U[i]--; V[i]--;
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }

    vector<int> depth(N, -1);
    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto v : G[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    };
    depth[0] = 0;
    dfs(0, -1);
    vector<int> odd, even;
    for (int i = 0; i < N; i++) {
        if (depth[i] % 2 == 0) even.push_back(i);
        else odd.push_back(i);
    }
    set<pair<int, int>> S;
    for (auto i : even) {
        for (auto j : odd) {
            if (i < j) S.insert({i, j});
            else S.insert({j, i});
        }
    }
    for (int i = 0; i < N - 1; i++) {
        S.erase({U[i], V[i]});
    }

    int Q = S.size();
    if (Q % 2 == 1) cout << "First" << endl;
    else cout << "Second" << endl;

    while (1) {
        if (Q % 2 == 1) {
            auto p = *S.begin();
            S.erase(S.begin());
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }
        else {
            int i, j;
            cin >> i >> j;
            if (i == -1 && j == -1) break;
            i--; j--;
            S.erase({i, j});
        }
        Q--;
    }
}
