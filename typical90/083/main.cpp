#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, Q;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cin >> Q;
    vector<int> X(Q), Y(Q);
    for (int i = 0; i < Q; i++) {
        cin >> X[i] >> Y[i];
        X[i]--;
    }

    int B = int(sqrt(2 * M));
    vector<int> large;
    for (int i = 0; i < N; i++) {
        if (G[i].size() >= B) {
            large.push_back(i);
        }
    }

    vector<vector<bool>> link(N, vector<bool>(large.size(), false));
    for (int i = 0; i < large.size(); i++) {
        for (int j : G[large[i]]) {
            link[j][i] = true;
        }
        link[large[i]][i] = true;
    }

    vector<int> update(N, -1);
    vector<int> update_large(large.size(), -1);
    for (int i = 0; i < Q; i++) {
        int last = update[X[i]];
        for (int j = 0; j < large.size(); j++) {
            if (link[X[i]][j]) {
                last = max(last, update_large[j]);
            }
        }
        if (last == -1) cout << 1 << endl;
        else cout << Y[last] << endl;

        if (G[X[i]].size() < B) {
            update[X[i]] = i;
            for (int j : G[X[i]]) {
                update[j] = i;
            }
        }
        else {
            int ptr = find(large.begin(), large.end(), X[i]) - large.begin();
            update_large[ptr] = i;
        }
    }
}
