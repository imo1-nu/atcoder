#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    ll X, Y, K;
    cin >> X >> Y >> K;

    vector<int> x, y;
    for (ll d = 1; 1; d *= K) {
        if (X == 0) break;
        x.push_back((X / d) % K);
        if (X / K < d) break;
    }
    for (ll d = 1; 1; d *= K) {
        if (Y == 0) break;
        y.push_back((Y / d) % K);
        if (Y / K < d) break;
    }
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    // for (auto i : x) cout << i << ' ';
    // cout << endl;
    // for (auto i : y) cout << i << ' ';
    // cout << endl;

    int cnt = 0;
    for (int i = 0; i < min(x.size(), y.size()); i++) {
        if (x[i] == y[i]) cnt++;
        else break;
    }
    int ans = x.size() + y.size() - cnt * 2;
    cout << ans << endl;
    // cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) solve();
}
