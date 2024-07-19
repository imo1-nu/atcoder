#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll al = 0, bl = 0, ans = 0;
    while (al < n && bl < m) {
        if (b[bl] <= a[al]) {
            ans += a[al];
            bl++;
            al++;
        }
        else al++;
    }
    if (bl < m) cout << -1 << endl;
    else cout << ans << endl;
}
