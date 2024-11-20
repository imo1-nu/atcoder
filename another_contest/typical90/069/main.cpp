#include <bits/stdc++.h>
#include <atcoder/all>
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
    
    ll N, K;
    cin >> N >> K;
    ll ans = K;
    if (N == 1) {
        cout << K << endl;
        return 0;
    }

    ans = ans * (K - 1) % mod;
    ll a = myPow(K - 2, N - 2);
    ans = ans * a % mod;
    cout << ans << endl;
}
