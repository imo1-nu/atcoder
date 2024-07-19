#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll L, R;
    cin >> L >> R;
    ll now = L;
    vector<ll> l, r;
    while (now < R) {
        if (now == 0) {
            ll i;
            for (i = 1; i <= R; i *= 2);
            l.push_back(0);
            r.push_back(i / 2);
            now = i / 2;
            //cout << now << endl;
            continue;
        }

        ll a = now;
        ll cnt = 0;

        ll ad = 1;

        while (a % 2 == 0 && now + ad * 2 <= R) {
            a /= 2;
            ad *= 2;
        }
        l.push_back(now);
        r.push_back(now + ad);
        now += ad;
        //cout << now << endl;
    }

    cout << l.size() << endl;
    for (int i = 0; i < l.size(); i++) cout << l[i] << ' ' << r[i] << endl;
}
