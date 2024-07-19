#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll func(ll n) {
    if (n < 3) return 0;
    ll ans = 1;
    for (int i = 0; i < 3; i++) {
        ans *= (n - i);
    }
    return ans / 6ll;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<ll> cnt(101);
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        cnt[a]++;
    }

    ll ans = 0;
    for (ll i = 1; i <= 100; i++) {
        ans += func(cnt[i]);
    }
    cout << ans << endl;
}
