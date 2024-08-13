#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    if (A < B) swap(A, B);
    if (A < C) swap(A, C);
    if (B < C) swap(B, C);

    ll ans = 10000;
    ll x, y;
    ll d = extGCD(B, C, x, y);
    for (ll i = 0; i * A <= N; i++) {
        if ((N - i * A) % d == 0) {
            ll j = (N - i * A) / d * x;
            ll k = (N - i * A) / d * y;
            if (k >= 0) {
                ll t = k / (B / d);
                j += t * C / d;
                k -= t * B / d;
            }
            else {
                ll t = -k / (B / d) + (k % (B / d) != 0);
                j -= t * C / d;
                k += t * B / d;
            }
            if (j >= 0) {
                ans = min(ans, i + j + k);
            }
        }
    }
    cout << ans << endl;
}
