#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k;
    cin >> n >> k;
    vector<double> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    double l, r;
    l = 0, r = 1e9;
    vector<ll> ans(n);
    while (l + 1e-6 < r) {
        double mid = (l + r) / 2;
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            ans[i] = (int)(a[i] / mid);
            sum += ans[i];
        }
        if (sum >= k) l = mid;
        else r = mid;
    }
    //cout << l << endl;
    for (ll i = 0; i < n - 1; i++) {
        cout << (int)(a[i] / l) << ' ';
    }
    cout << (int)(a[n - 1] / l) << endl;
    
}
