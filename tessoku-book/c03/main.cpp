#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll d, x;
    cin >> d >> x;
    vector<ll> a(d - 1), s(d);
    for (ll i = 0; i < d - 1; i++) {
        cin >> a[i];
    }
    s[0] = x;
    for (int i = 1; i < d; i++) {
        s[i] = s[i - 1] + a[i - 1];
    }
    
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        int b, c;
        cin >> b >> c;
        if (s[b - 1] > s[c - 1]) cout << b;
        else if (s[b - 1] == s[c - 1]) cout << "Same";
        else cout << c;
        cout << endl;
    }
    
}
