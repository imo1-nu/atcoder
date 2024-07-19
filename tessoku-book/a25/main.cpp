#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (ll i = 0; i < h; i++) {
        cin >> s[i];
    }
    
    vector<vector<ll>> dp(h, vector<ll> (w, 0));
    dp[0][0] = 1;

    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            if (i - 1 > -1) {
                if (s[i - 1][j] != '#') dp[i][j] += dp[i - 1][j];
            }
            if (j - 1 > -1) {
                if (s[i][j - 1] != '#') dp[i][j] += dp[i][j - 1];
            }
        }
    }
    
    cout << dp[h - 1][w - 1] << endl;
}
