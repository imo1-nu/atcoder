#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k, l;
vector<ll> a(100002);

bool check(ll score) {
    ll cnt = 0;
    ll len = 0;
    for (ll i = 0; i < n; i++) {
        len += a[i + 1] - a[i];
        if (len >= score && l - a[i + 1] >= score) {
            cnt++;
            len = 0;
        }
    }
    if (cnt >= k) return true;
    return false;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> l >> k;
    a[n + 1] = l;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll L = 1, R = l;
    while (L + 1 < R) {
        ll mid = (L + R) / 2;
        if (check(mid)) L = mid;
        else R = mid;
    }
    cout << L << endl;
}