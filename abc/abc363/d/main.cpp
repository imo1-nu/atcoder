#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1000000007;

ll myPow(ll a, ll b) {
    if (b == 0) return 1ll;
    ll c = myPow(a, b / 2);
    if (b % 2 == 0) return c * c % mod;
    return c * c % mod * a % mod;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    ll kmax = 36;
    vector<ll> keta(kmax);
    keta[0] = 10;
    keta[1] = 9;
    for (ll i = 2; i < kmax; i++) {
        if (i % 2 == 1) keta[i] = keta[i - 1];
        else keta[i] = keta[i - 1] * 10;
        //cout << keta[i] << endl;
    }
    vector<ll> keta2(kmax + 1);
    for (ll i = 1; i < kmax + 1; i++) {
        keta2[i] = keta2[i - 1] + keta[i - 1];
        //cout << keta2[i] << endl;
    }
    //cout << keta2[35] << endl;
    ll nketa;
    for (ll i = 0; i < kmax + 1; i++) {
        if (n <= keta2[i]) {
            nketa = i;
            break;
        }
    }
    ll ans;
    string s, s_inv;
    //cout << nketa << endl;
    if (nketa % 2ll == 0ll) {
        ans = n - keta2[nketa - 1ll] - 1 + myPow(10ll, nketa / 2 - 1);
        s = to_string(ans);
        s_inv = s;
        reverse(s_inv.begin(), s_inv.end());
        cout << s << s_inv << endl;
    }
    else {
        ll a = (n - keta2[nketa - 1ll] - 1ll) % 10ll;
        if (nketa != 1ll) {
            ans = (n - keta2[nketa - 1ll] - 1ll) / 10ll + myPow(10ll, nketa / 2 - 1);
            s = to_string(ans);
            s_inv = s;
            reverse(s_inv.begin(), s_inv.end());
            cout << s << a << s_inv << endl;
        }
        else cout << a << endl;
    }
}
