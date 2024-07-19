#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            ll z = k - i - j;
            if (z > 0 && z <= n) ans++;
        }
    }
    
    cout << ans << endl;
}
