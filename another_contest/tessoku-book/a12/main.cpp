#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l = 0, r = 1e9;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            sum += mid / a[i];
        }
        if (sum < k) l = mid;
        else r = mid;
    }
    cout << r << endl;
}
