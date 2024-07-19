#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 998244353;

bool kaibun(ll s, ll k) {
    for (ll i = 0; i < k / 2; i++) {
        if (((s >> i) % 2) != ((s >> (k - 1 - i)) % 2)) return false;
    }
    return true;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k;
    string s;
    cin >> n >> k >> s;

    vector<vector<ll>> dp(n + 1, vector<ll>(1ll << (k - 1)));
    dp[0][0] = 1;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < (1 << (k - 1)); j++) {
            for (ll l = 0; l < 2; l++) {
                if (s[i] == '?' || s[i] == 'A' + l) {
                    int j2 = (j << 1) | l;
                    bool ok = true;
                    if (i < k - 1) {
                        ok = false;
                    }
                    if (!kaibun(j2, k)) ok = false;
                    if (!ok) {
                        j2 &= ~(1 << (k - 1));
                        dp[i + 1][j2] += dp[i][j];
                        dp[i + 1][j2] %= mod;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < (1 << (k - 1)); i++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;
}
