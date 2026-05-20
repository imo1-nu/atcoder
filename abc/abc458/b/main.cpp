#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W;
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int ans = 4;
            if (i == 0) ans--;
            if (i == H - 1) ans--;
            if (j == 0) ans--;
            if (j == W - 1) ans--;
            cout << ans << ' ';
        }
        cout << endl;
    }
}
