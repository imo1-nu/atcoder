#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll Sqrt(ll x) {
    ll l = 0, r = 1e9 + 1;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (m * m <= x) l = m;
        else r = m;
    }
    return l;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;

    ll ans = 0;
    for (int i = 1; (1ll << i) <= N; i++) {
        ll add = Sqrt(N / (1ll << i));
        if (add % 2 == 1) add++;
        add /= 2;
        ans += add;
    }
    cout << ans << endl;
}
