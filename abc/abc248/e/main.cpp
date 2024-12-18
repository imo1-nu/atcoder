#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    if (K == 1) {
        cout << "Infinity" << endl;
        return 0;
    }

    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }

    map<tuple<ll, ll, ll>, int> mp;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            ll a = Y[i] - Y[j];
            ll b = X[j] - X[i];
            ll c = X[i] * Y[j] - X[j] * Y[i];
            ll g = gcd(gcd(abs(a), abs(b)), abs(c));
            a /= g;
            b /= g;
            c /= g;
            if (a < 0 || (a == 0 && b < 0)) {
                a *= -1;
                b *= -1;
                c *= -1;
            }
            mp[{a, b, c}]++;
        }
    }

    int comb = K * (K - 1) / 2;
    ll ans = 0;
    for (auto [k, v] : mp) {
        if (v >= comb) ans++;
    }
    cout << ans << endl;
}
