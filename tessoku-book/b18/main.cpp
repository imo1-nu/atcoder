#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = -1;
    vector<vector<ll>> dp(n + 1, vector<ll>(s + 1, -1));
    dp[0][0] = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j < s; j++) {
            if (dp[i - 1][j] == -1) continue;

            dp[i][j] = dp[i - 1][j];
            if (j + a[i - 1] <= s) dp[i][j + a[i - 1]] = dp[i - 1][j] + (1ll << (i - 1));
            if (j + a[i - 1] == s) {
                ans = dp[i][s];
                break;
            }
        }
        if (ans > 0) break;
    }
    
    if (ans == -1) cout << -1 << endl;
    if (ans > 0) {
        bitset<61> b = ans;
        ll cnt = b.count();
        ll ncnt = 0;
        cout << cnt << endl;
        for (ll i = 0; i < 61; i++) {
            if (b.test(i)) {
                cout << i + 1;
                ncnt++;
                if (ncnt < cnt) cout << ' ';
                else cout << endl;
            }
        }
    }
    
}
