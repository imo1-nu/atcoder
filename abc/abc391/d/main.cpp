#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, W;
    cin >> N >> W;
    vector<vector<pair<int, int>>> B(W);
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        X--;
        B[X].emplace_back(Y, i);
    }
    for (int i = 0; i < W; i++) {
        sort(B[i].rbegin(), B[i].rend());
    }

    vector<int> ans(N, 2e9);
    while (1) {
        bool ok = true;
        int t = 0;
        for (int j = 0; j < W; j++) {
            if (B[j].empty()) {
                ok = false;
                break;
            }
            t = max(t, B[j].back().first);
        }
        if (!ok) break;
        else {
            for (int j = 0; j < W; j++) {
                ans[B[j].back().second] = t;
                B[j].pop_back();
            }
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int t, a;
        cin >> t >> a;
        a--;
        if (ans[a] > t) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
