#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<pair<char, int>>> G(H + 1, vector<pair<char, int>>(W + 1, {'A', -1}));
    for (int i = 0; i < Q; i++) {
        int r, c;
        char x;
        cin >> r >> c >> x;
        r--; c--;
        G[r][c] = {x, i};
    }

    for (int i = H - 1; i >= 0; i--) {
        for (int j = W - 1; j >= 0; j--) {
            if (G[i][j].second < G[i + 1][j].second) G[i][j] = G[i + 1][j];
            if (G[i][j].second < G[i][j + 1].second) G[i][j] = G[i][j + 1];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << G[i][j].first;
        }
        cout << endl;
    }
}
