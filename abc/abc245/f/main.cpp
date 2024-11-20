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
    vector<vector<int>> G(N);
    vector<int> cnt(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[v].push_back(u);
        cnt[u]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (cnt[i] == 0) {
            q.push(i);
        }
    }

    int ans = N;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        ans--;
        for (int u : G[v]) {
            cnt[u]--;
            if (cnt[u] == 0) {
                q.push(u);
            }
        }
    }

    cout << ans << endl;
}