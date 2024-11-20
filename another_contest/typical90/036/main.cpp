#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(N), Y(N);
    ll X_min = 1e18, X_max = -1e18, Y_min = 1e18, Y_max = -1e18;
    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        X[i] = x - y;
        Y[i] = x + y;
        X_min = min(X_min, X[i]);
        X_max = max(X_max, X[i]);
        Y_min = min(Y_min, Y[i]);
        Y_max = max(Y_max, Y[i]);
    }

    for (ll i = 0; i < Q; i++) {
        ll q;
        cin >> q;
        q--;
        ll ans = max({abs(X[q] - X_min), abs(X[q] - X_max), abs(Y[q] - Y_min), abs(Y[q] - Y_max)});
        cout << ans << endl;
    }
}
