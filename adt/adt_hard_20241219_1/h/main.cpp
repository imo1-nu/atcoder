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
    vector<int> in(N);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        G[A].push_back(B);
        in[B]++;
    }

    vector<int> ans(N);
    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        if (q.size() != 1) {
            cout << "No" << endl;
            return 0;
        }
        int v = q.front();
        q.pop();
        ans[v] = ++cnt;
        for (int u : G[v]) {
            in[u]--;
            if (in[u] == 0) {
                q.push(u);
            }
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
