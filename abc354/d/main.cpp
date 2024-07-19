#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll func(ll C, ll D) {
    vector<ll> xcnt(4, C / 4), ycnt(2, D / 2);
    for (ll i = 0; i < 4; i++) {
        if (C % 4 > i) xcnt[i]++;
    }
    if (D % 2 == 1) ycnt[0]++;

    vector<vector<ll>> cnt(4, vector<ll>(2));

    for (ll i = 0; i < 4; i++) {
        for (ll j = 0; j < 2; j++) {
            cnt[i][j] = xcnt[i] * ycnt[j];
            //cout << cnt[i][j] << endl;
        }
    }

    vector<vector<ll>> s =
    {
        {2, 1},
        {1, 2},
        {0, 1},
        {1, 0}
    };

    ll ans = 0;

    for (ll i = 0; i < 4; i++) {
        for (ll j = 0; j < 2; j++) {
            ans += cnt[i][j] * s[i][j];
        }
    }

    return ans;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll max = 1000000000;
    
    ll A, B, C, D, A1, B1;
    cin >> A1 >> B1 >> C >> D;

    A = (A1 + max) % 4;
    B = (B1 + max) % 2;
    C = C - A1 + A;
    D = D - B1 + B;

    cout << func(C, D) + func(A, B) - func(C, B) - func(A, D) << endl;
    //func(C, D);
}
