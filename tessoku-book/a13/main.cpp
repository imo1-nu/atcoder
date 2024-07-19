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
    
    /*ll r = 0, sum = 0;
    for (ll i = 0; i < n; i++) {
        while (a[r + 1] - a[i] <= k && r + 1 < n) {
            r++;
        }
        sum += r - i;
        //cout << r << endl;
    }*/

    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        sum += lower_bound(a.begin(), a.end(), a[i] + k + 1) - a.begin() - i - 1;
    }
    
    
    cout << sum << endl;
}
