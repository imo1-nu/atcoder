#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<ll> K(N);
    for (ll i = 0; i < N; i++) {
        cin >> K[i];
    }
    ll ans = 1e18;
    for (ll i = 0; i < (1 << N); i++) {
        ll a = 0, b = 0;
        for (ll j = 0; j < N; j++) {
            if (i & (1 << j)) {
                a += K[j];
            } else {
                b += K[j];
            }
        }
        ans = min(ans, max(a, b));
    }
    cout << ans << endl;
}
