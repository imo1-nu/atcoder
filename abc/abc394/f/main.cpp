#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 0;
    function<int(int, int)> dfs = [&](int u, int p) -> int {
        vector<int> ch;
        for (int v : G[u]) {
            if (v == p) continue;
            int t = dfs(v, u);
            ch.push_back(t);
            ans = max(ans, t);
        }
        sort(ch.rbegin(), ch.rend());
        if (ch.size() >= 4) ans = max(ans, 1 + ch[0] + ch[1] + ch[2] + ch[3]);
        if (ch.size() >= 3) return 1 + ch[0] + ch[1] + ch[2];
        return 0;
    };
    dfs(0, -1);
    if (ans == 0) cout << -1 << endl;
    else cout << 3 * ans + 2 << endl;
}
