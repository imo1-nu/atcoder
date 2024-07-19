#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll grundy(ll a) {
    if (a % 5 <= 1) return 0;
    if (a % 5 <= 3) return 1;
    return 2;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= grundy(a[i]);
    }
    if (ans) cout << "First" << endl;
    else cout << "Second" << endl;
    
}
