#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;

    vector<bool> is_prime(1000000, true);
    is_prime[0] = false;
    is_prime[1] = false;
    vector<ll> P;
    for (ll i = 2; i < 1000000; i++) {
        if (!is_prime[i]) continue;
        P.push_back(i);
        for (ll j = i * i; j < 1000000; j *= i) {
            is_prime[j] = false;
        }
    }
    int ans = 0;
    for (ll p : P) {
        ll x = p;
        while (N % x == 0) {
            // cout << N << " / " << x << " = " << N / x << endl;
            N /= x;
            ans++;
            if (x > N / p) break;
            x *= p;
        }
        while (N % p == 0) N /= p;
    }
    if (N != 1) ans++;
    cout << ans << endl;
}
