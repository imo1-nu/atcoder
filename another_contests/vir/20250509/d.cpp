#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    map<ll, ll> f;
    function<ll(ll)> culc = [&](ll n) {
        if (n == 0) return 1ll;
        ll res = 0ll;
        if (f.count(n / 2)) res += f[n / 2];
        else res += culc(n / 2);
        if (f.count(n / 3)) res += f[n / 3];
        else res += culc(n / 3);
        f[n] = res;
        return res;
    };
    
    cout << culc(N) << endl;
}
