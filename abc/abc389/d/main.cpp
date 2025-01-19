#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll R;
    cin >> R;
    ll ans = 0;
    for (ll i = 1; i < R; i++) {
        ll mx = sqrt(R * R - (i + 0.5) * (i + 0.5)) - 0.5;
        ans += mx + 1;
    }
    cout << ans * 4 + 1 << endl;
}
