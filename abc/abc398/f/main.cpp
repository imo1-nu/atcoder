#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<ll> h1(500001, 0);
vector<ll> h2(500001, 0);
vector<ll> B(500001, 1ll);
ll mod = 2147483647, b = 100ll;
ll Ha1(ll l, ll r) { // [l, r) 0-indexed
    ll v = h1[r] - (h1[l] * B[r - l] % mod);
    if (v < 0) v += mod;
    return v;
}

ll Ha2(ll l, ll r) { // [l, r) 0-indexed
    ll v = h2[r] - (h2[l] * B[r - l] % mod);
    if (v < 0) v += mod;
    return v;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string S;
    cin >> S;
    ll N = S.length();
    string T = S;
    reverse(T.begin(), T.end());

    for (ll i = 1; i <= N; i++) {
        B[i] = B[i - 1] * b % mod;
        h1[i] = (h1[i - 1] * b + (ll)(S[i - 1] - 'A' + 1)) % mod;
        h2[i] = (h2[i - 1] * b + (ll)(T[i - 1] - 'A' + 1)) % mod;
    }

    for (int i = 0; i < N; i++) {
        if (Ha1(i, N) == Ha2(0, N - i)) {
            string ans = S + T.substr(N - i);
            cout << ans << endl;
            return 0;
        }
    }
}
