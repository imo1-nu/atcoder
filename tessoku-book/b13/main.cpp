#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), s(n + 1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i - 1];
    }
    

    ll ans = 0;
    auto end = s.end();
    for (int i = 1; i <= n; i++) {
        auto l_bound = lower_bound(s.begin(), s.end(), k + 1 + s[i - 1]);
        if (l_bound <= end) {
            ans += l_bound - s.begin() - i;
        }
    }
    cout << ans << endl;
}
