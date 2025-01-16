#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll f (ll a, ll d, ll n) {
    return n * (2 * a + (n + 1) * d) / 2;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    vector<ll> S1(N + 1), S2(N + 1);
    ll ans = X[0];
    for (int i = 1; i <= N; i++) {
        S1[i] = S1[i - 1] + X[i - 1] * Y[i - 1];
        S2[i] = S2[i - 1] + f(S1[i - 1], X[i - 1], Y[i - 1]);
        ans = max(ans, S2[i]);
        if (S1[i - 1] > 0 && S1[i] < 0) {
            ll d = -S1[i - 1] / X[i - 1];
            ans = max(ans, S2[i - 1] + f(S1[i - 1], X[i - 1], d));
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) solve();
}
