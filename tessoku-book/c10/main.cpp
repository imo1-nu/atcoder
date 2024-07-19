#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1000000007;

ll myPow(ll a, ll b) {
    if (b == 0) return 1ll;
    ll c = myPow(a, b / 2);
    if (b % 2 == 0) return c * c % mod;
    return c * c % mod * a % mod;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll w;
    cin >> w;

    ll ans = 12ll;
    ans = ans * myPow(7ll, w - 1) % mod;
    cout << ans << endl;
}
