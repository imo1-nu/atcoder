#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll myPow(ll a, ll b) {
    if (b == 0) return 1ll;
    ll c = myPow(a, b / 2);
    if (b % 2 == 0) return c * c;
    return c * c * a;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;

    ll N2 = (ll)sqrt(N);
    vector<bool> isPrime(N2 + 1, true);
    vector<ll> primes;
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= N2; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= N2; j += i) {
                isPrime[j] = false;
            }
        }
    }

    ll ans = 0;
    for (auto p : primes) {
        if (myPow(p, 8) > N) break;
        ans++;
    }

    for (ll i = 0; i < (ll)primes.size(); i++) {
        for (ll j = i + 1; j < (ll)primes.size(); j++) {
            if (myPow(primes[i], 2) > N / myPow(primes[j], 2)) {
                break;
            }
            ans++;
        }
    }

    cout << ans << endl;
}
