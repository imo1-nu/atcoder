#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        X[i]--;
        Y[i]--;
    }
    vector<set<int>> SX(H + 1), SY(W + 1);
    for (int i = 0; i < N; i++) {
        SX[X[i]].insert(Y[i]);
        SY[Y[i]].insert(X[i]);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int t, idx;
        cin >> t >> idx;
        idx--;
        if (t == 1) {
            for (auto y : SX[idx]) SY[y].erase(idx);
            cout << SX[idx].size() << endl;
            SX[idx].clear();
        }
        else {
            for (auto x : SY[idx]) SX[x].erase(idx);
            cout << SY[idx].size() << endl;
            SY[idx].clear();
        }
    }
}
