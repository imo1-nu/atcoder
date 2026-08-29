#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> color(N, -1);
    vector<int> ans;
    function<bool(int)> dfs = [&](int u) {
        // for (auto x : ans) cout << x + 1 << ' ';
        // cout << endl;
        for (auto v : G[u]) {
            if (color[u] == color[v]) {
                // cout << "find!" << endl;
                int start = 0, end = ans.size();
                for (int i = 0; i < end; i++) {
                    if (ans[i] == v) start = i;
                }
                cout << end - start << endl;
                for (int i = start; i < end; i++) {
                    cout << ans[i] + 1 << ' ';
                }
                cout << endl;
                return true;
            }
            else if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                ans.push_back(v);
                bool ok = dfs(v);
                if (ok) return true;
                ans.pop_back();
            }
        }
        return false;
    };

    for (int i = 0; i < N; i++) {
        if (color[i] != -1) continue;
        color[i] = 0;
        ans.push_back(i);
        if (dfs(i)) return;
    }
    cout << -1 << endl;
    return;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) solve();
}
