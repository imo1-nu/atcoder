#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    for (auto& c : C) cin >> c;

    int t, b, l, r;
    for (t = 0; t < H; t++) {
        bool ok = true;
        for (auto c : C[t]) if (c == '#') ok = false;
        if (!ok) break; 
    }
    for (b = H - 1; b >= 0; b--) {
        bool ok = true;
        for (auto c : C[b]) if (c == '#') ok = false;
        if (!ok) break; 
    }
    for (l = 0; l < W; l++) {
        bool ok = true;
        for (int i = 0; i < H; i++) if (C[i][l] == '#') ok = false;
        if (!ok) break; 
    }
    for (r = W - 1; r >= 0; r--) {
        bool ok = true;
        for (int i = 0; i < H; i++) if (C[i][r] == '#') ok = false;
        if (!ok) break; 
    }

    for (int i = t; i <= b; i++) {
        for (int j = l; j <= r; j++) {
            cout << C[i][j];
        }
        cout << endl;
    }
}
