#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string X;
    ll M;
    cin >> X >> M;

    if (X.size() == 1) {
        cout << (X[0] - '0' <= M) << endl;
        return 0;
    }
    
    ll d = 0, r = 2e18;
    for (ll i = 0; i < X.size(); i++) {
        d = max(d, (ll)(X[i] - '0'));
    }
    ll l = d;

    while (l + 1ll < r) {
        ll m = (l + r) / 2;
        ll v = 0;
        for (ll i = 0; i < X.size(); i++) {
            if (v > (M - (X[i] - '0')) / m) {
                v = M + 1ll;
                break;
            }
            v = v * m + (X[i] - '0');
        }
        if (v <= M) {
            l = m;
        }
        else {
            r = m;
        }
    }

    cout << l - d << endl;
}
