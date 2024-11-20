#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll Pow8[20];
ll Pow9[20];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string N;
    ll K;
    cin >> N >> K;

    Pow8[0] = 1;
    Pow9[0] = 1;
    ll N8 = 0;
    for (ll i = 0; i < 20; i++) {
        if (i > 0) {
            Pow8[i] = Pow8[i - 1] * 8ll;
            Pow9[i] = Pow9[i - 1] * 9ll;
        }
    }

    for (ll i = N.size() - 1; i >= 0; i--) {
        N8 += (N[i] - '0') * Pow8[N.size() - i - 1];
    }

    ll N9 = N8;
    for (ll i = 0; i < K; i++) {
        N8 = 0;
        for (ll j = 0; j < 20; j++) {
            ll a = N9 / Pow9[j] % 9ll;
            if (a == 8ll) a = 5;
            N8 += a * Pow8[j];
        }
        N9 = N8;
    }

    bool flag = false;
    for (ll i = 19; i >= 0; i--) {
        if (N8 / Pow8[i] % 8ll != 0ll) flag = true;
        if (flag) cout << N8 / Pow8[i] % 8ll;
    }
    if (!flag) cout << 0;
    cout << endl;
}
