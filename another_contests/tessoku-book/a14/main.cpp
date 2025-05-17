#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n), c(n), d(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<ll> e(n * n);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            e[i * n + j] = a[i] + b[j];
        }
    }
    
    for (ll i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> d[i];
    }
    vector<ll> f(n * n);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            f[i * n + j] = c[i] + d[j];
        }
    }
    sort(f.begin(), f.end());

    bool ans = false;
    for (ll i = 0; i < n * n; i++) {
        ll key = k - e[i];
        if (binary_search(f.begin(), f.end(), key)) ans = true;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    
}
