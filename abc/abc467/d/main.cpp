#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    ll px, py, qx, qy, rx, ry, sx, sy;
    cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
    if ((px - qx) * (ry - sy) == (py - qy) * (rx - sx)) {
        if ((px + qx - rx - sx) * (px - qx) + (py + qy - ry - sy) * (py - qy) == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "Yes" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) solve();
}
