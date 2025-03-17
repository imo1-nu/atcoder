#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    for (ll i = 1; i * i * i <= N; i++) {
        if (N % i != 0) continue;
        ll j = N / i;
        ll k = j - i * i;
        if (k % 3 != 0) continue;
        k /= 3;
        double r = sqrt(i * i + 4 * k);
        if (r == ll(r) && (i + ll(r)) % 2 == 0) {
            ll x = (i + ll(r)) / 2;
            ll y = (ll(r) - i) / 2;
            if (x > 0 && y > 0) {
                cout << x << " " << y << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}
