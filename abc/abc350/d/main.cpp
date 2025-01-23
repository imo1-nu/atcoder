#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
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

    vector<bool> seen(N, false);
    queue<int> q;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (seen[i] == true) continue;
        seen[i] = true;
        q.push(i);
        ll cnt = 1;
        while (!q.empty()) {
            int j = q.front();
            q.pop();
            for (int k : G[j]) {
                if (seen[k] == true) continue;
                seen[k] = true;
                q.push(k);
                cnt++;
            }
        }
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans - M << endl;
}
