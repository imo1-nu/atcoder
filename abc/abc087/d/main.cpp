#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using Graph = vector<vector<pair<int, int>>>;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int L, R, D;
        cin >> L >> R >> D;
        L--; R--;
        G[L].push_back({R, D});
        G[R].push_back({L, -D});
    }

    bool ans = true;

    vector<bool> visited(N);
    vector<int> pos(N, 0);

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        pos[i] = 0;
        visited[i] = true;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto [nv, d] : G[v]) {
                if (visited[nv]) {
                    if (pos[nv] != pos[v] + d) {
                        ans = false;
                        break;
                    }
                }
                else {
                    pos[nv] = pos[v] + d;
                    visited[nv] = true;
                    q.push(nv);
                }
            }
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
