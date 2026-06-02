#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = unsigned long long;

using mint = atcoder::modint998244353;

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

void solve() {
    ll N, M;
    cin >> N >> M;
    mint ans = 0;
    for (ll d = 10; d / 10 <= N; d *= 10) {
        ll p = M / gcd(d - 1, M);
        mint cnt1, cnt2;
        if (d <= N) cnt1 = d - d / 10;
        else cnt1 = N - d / 10 + 1;
        cnt2 = N / p;
        ans += cnt1 * cnt2;
        if (d == 10000000000000000000ull) break;
    }
    cout << ans.val() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
