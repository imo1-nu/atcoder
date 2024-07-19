#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, h, w;
    cin >> n >> h >> w;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= a[i];
        ans ^= b[i];
    }
    if (ans) cout << "First" << endl;
    else cout << "Second" << endl;
    
}
