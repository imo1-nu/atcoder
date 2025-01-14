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

    vector<vector<pair<int, int>>> G(N);
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }

    int Y = 0;
    vector<int> ans, visited(N), lamp(N);
    function<void(int)> dfs = [&](int c) -> void {
        visited[c] = 1;
        for (auto& [d, id] : G[c]) {
            if (visited[d]) continue;
            dfs(d);
            if (lamp[d] == 0 && Y < K) {
                Y -= lamp[d] + lamp[c];
                lamp[d] ^= 1;
                lamp[c] ^= 1;
                Y += lamp[d] + lamp[c];
                ans.push_back(id);
            }
        }
    };
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        dfs(i);
    }

    if (K != Y) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}
