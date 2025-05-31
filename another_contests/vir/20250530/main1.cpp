#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, W;
    cin >> N >> W;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        X[i]--; Y[i]--;
    }
    vector<vector<pair<int, int>>> col(W);
    for (int i = 0; i < N; i++) {
        col[X[i]].emplace_back(Y[i], i);
    }
    for (int i = 0; i < W; i++) {
        sort(col[i].begin(), col[i].end());
    }
    vector<int> T_erace(N, 2e9);
    for (int i = 0; 1; i++) {
        bool ok = true;
        int mxY = -1;
        for (int j = 0; j < W; j++) {
            if (col[j].size() <= i) ok = false;
            else mxY = max(mxY, col[j][i].first);
        }
        if (!ok) break;
        for (int j = 0; j < W; j++) {
            T_erace[col[j][i].second] = mxY + 1;
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int t, a;
        cin >> t >> a;
        a--;
        bool ok = true;
        if (T_erace[a] <= t) ok = false;
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
