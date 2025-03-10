#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> X(M), Y(M), Z(M);
    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--; Y[i]--;
    }
    vector<vector<vector<pair<int, bool>>>> G(30, vector<vector<pair<int, bool>>>(N));
    for (int bit = 0; bit < 30; bit++) {
        for (int i = 0; i < M; i++) {
            if ((Z[i] >> bit) & 1) { // 異なる色
                G[bit][X[i]].emplace_back(Y[i], true);
                G[bit][Y[i]].emplace_back(X[i], true);
            }
            else { // 同じ色
                G[bit][X[i]].emplace_back(Y[i], false);
                G[bit][Y[i]].emplace_back(X[i], false);
            }
        }
    }
    vector<int> A(N);
    vector<int> renketsu;
    for (int bit = 0; bit < 30; bit++) {
        vector<int> colars(N, -1);
        function<void(int, int)> dfs = [&](int u, int color) {
            colars[u] = color;
            renketsu.push_back(u);
            A[u] |= color << bit;
            for (auto [v, c] : G[bit][u]) {
                if (colars[v] == -1) {
                    dfs(v, c ^ color);
                }
                else if (colars[v] != (c ^ color)) {
                    cout << "-1" << '\n';
                    exit(0);
                }
            }
        };
        for (int i = 0; i < N; i++) {
            if (colars[i] == -1) {
                renketsu = vector<int>();
                dfs(i, 0);
                int cnt = 0;
                for (int u : renketsu) {
                    if (colars[u] == 1) cnt++;
                }
                if (cnt * 2 > (int)renketsu.size()) {
                    for (int u : renketsu) {
                        A[u] ^= 1 << bit;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << '\n';
}
