#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    while (cin >> n && n != 0) {
        vector<vector<int>> a(n, vector<int>(n));
        for (auto& v : a) for (auto& x : v) cin >> x;

        // perm: 0..n-1 の順列で、隣り合う値の差が常に floor(n/2) 以上になるもの。
        // これを行・列それぞれに独立に適用すると、元のグリッドで上下左右に
        // 隣接していたマスは新しいグリッドでマンハッタン距離 floor(n/2) 以上になる。
        vector<int> perm(n);
        if (n % 2 == 0) {
            int h = n / 2;
            for (int t = 0; t < h; t++) {
                perm[2 * t] = h - 1 - t;
                perm[2 * t + 1] = n - 1 - t;
            }
        } else {
            int step = (n - 1) / 2;
            for (int k = 0; k < n; k++) perm[k] = (k * step) % n;
        }

        vector<int> inv(n);
        for (int k = 0; k < n; k++) inv[perm[k]] = k;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[inv[i]][inv[j]] << " \n"[j == n - 1];
            }
        }
    }
}
