#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    long long N, X;
    cin >> N >> X;
    vector<ll> total(N + 1), p(N + 1);
    total[0] = 1;
    p[0] = 1;
    for (int i = 1; i <= N; i++) {
        total[i] = 2 * total[i - 1] + 3;
        p[i] = 2 * p[i - 1] + 1;
    }

    function<ll(ll, ll)> f = [&](ll n, ll x) {
        if (x <= 0) return 0ll;
        if (n == 0) return 1ll;
        if (x >= total[n]) return p[n];
        return f(n - 1, x - 1) + f(0, x - total[n - 1] - 1) + f(n - 1, x - total[n - 1] - 2);
    };
    cout << f(N, X) << endl;
}
