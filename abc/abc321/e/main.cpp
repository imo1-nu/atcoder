#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<ll> pow2(61);

void solve() {
    ll N, X, K;
    cin >> N >> X >> K;

    auto f = [&](ll x, ll d) {
        if (d > 60 || x > N / pow2[d]) return 0ll;
        return min(pow2[d], N - x * pow2[d] + 1);
    };

    ll ans = f(X, K);
    while (X > 1 && K >= 1) {
        ll par = X / 2;
        ll other = par * 2;
        if (X == other) other++;
        if (K == 1) ans++;
        else ans += f(other, K - 2);
        X = par;
        K--;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    pow2[0] = 1;
    for (int i = 1; i <= 60; i++) pow2[i] = pow2[i - 1] * 2;
    while (T--) solve();
}
