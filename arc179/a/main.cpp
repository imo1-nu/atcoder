#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n + 1);
    bool zero = true;
    for (ll i = 0; i < n; i++) {
        cin >> x[i];
        if (x[i] != 0) zero = true;
    }
    sort(x.begin(), x.end());
    for (ll i = 0; i < n; i++) {
        y[i + 1] = y[i] + x[i];
    }
    bool ans = false;
    vector<ll> z = x;
    ll M = max((ll)0, y[n]);
    ll m = min((ll)0, y[n]);
    if (k > M) {
        ans = true;
        sort(z.begin(), z.end());
    }
    else if (k <= m) {
        ans = true;
        sort(z.rbegin(), z.rend());
    }
    else { //m < k && k <= M
        //if (zero) ans = true;
        if (y[n] > 0) {
            ans = true;
            sort(z.begin(), z.end());
        }
    }
    if (ans) {
        cout << "Yes" << endl;
        for (ll i = 0; i < n; i++) {
            cout << z[i];
            if (i < n - 1) cout << ' ';
            else cout << endl;
        }
        
    }
    else cout << "No" << endl;
    
}
