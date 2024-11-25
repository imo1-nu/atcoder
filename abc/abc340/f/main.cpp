#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

pair<ll, ll> extgcd(ll a, ll b) {
    if (b == 0) return make_pair(1, 0);
    ll x, y;
    tie(y, x) = extgcd(b, a % b);
    y -= a / b * x;
    return make_pair(x, y);
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll X, Y;
    cin >> X >> Y;

    auto [A, B] = extgcd(Y, -X);
    ll g = gcd(max(abs(X), abs(Y)), min(abs(X), abs(Y)));
    if (g > 2) cout << -1 << endl;
    else cout << A * 2 / g << " " << B * 2 / g << endl;
}
