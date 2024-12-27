#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    vector<int> ans(N);
    vector<vector<int>> group;
    vector<bool> used(N);
    for (int i = 0; i < N; i++) {
        if (used[i]) continue;
        vector<int> g;
        for (int j = i; !used[j]; j = P[j]) {
            g.push_back(j);
            used[j] = true;
        }
        group.push_back(g);
    }

    for (auto g : group) {
        int sz = g.size();
        int shift = atcoder::pow_mod(2, K, sz);
        for (int i = 0; i < sz; i++) {
            ans[g[i]] = g[(i + shift) % sz];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] + 1 << ' ';
    }
    cout << endl;
}
