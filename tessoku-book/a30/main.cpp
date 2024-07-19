#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a = 1000000007;

ll func(ll b, ll c) {
    if (c == 1) return b;
    ll d = func(b, c / 2);
    if (c % 2 == 0) return d * d % a;
    else return d * d % a * b % a;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, r;
    cin >> n >> r;
    vector<ll> dp(n + 1, 1);
    for (ll i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] * i % a;
    }
    cout << dp[n] * func(dp[r] * dp[n - r] % a, a - 2) % a << endl;
}
