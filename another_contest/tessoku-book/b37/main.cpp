#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll myPow(ll a, ll b) {
    if (b == 0) return 1;
    ll c = myPow(a, b / 2);
    if (b % 2 == 0) return c * c;
    return c * c * a;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;

    ll ans = 0;
    for (ll i = 0; i < 15; i++) {
        ll a = myPow(10, i);
        ll digit = n / a % 10ll;
        for (ll j = 1; j < 10; j++) {
            if (j < digit) ans += (n / (a * 10ll) * a + a) * j;
            else if (j == digit) ans += (n / (a * 10ll) * a + n % a + 1ll) * j;
            else ans += n / (a * 10ll) * a * j;
        }
    }
    
    cout << ans << endl;
}
