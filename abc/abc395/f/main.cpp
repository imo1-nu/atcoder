#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, X;
    cin >> N >> X;
    vector<int> U(N), D(N);
    for (int i = 0; i < N; i++) {
        cin >> U[i] >> D[i];
    }
    ll r = 2e9;
    for (int i = 0; i < N; i++) {
        r = min(r, ll(U[i] + D[i]));
    }
    r++;
    ll l = 2;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        vector<pair<int, int>> range(N);
        for (int i = 0; i < N; i++) {
            range[i].first = max(0ll, m - D[i]);
            range[i].second = U[i];
        }
        bool ok = true;
        for (int i = 0; i < N - 1; i++) {
            if (range[i].first - X > range[i + 1].second || range[i].second + X < range[i + 1].first) {
                ok = false;
                break;
            }
            range[i + 1].first = max(range[i + 1].first, range[i].first - X);
            range[i + 1].second = min(range[i + 1].second, range[i].second + X);
        }
        if (ok) l = m;
        else r = m;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += U[i] + D[i] - l;
    }
    cout << ans << endl;
}
