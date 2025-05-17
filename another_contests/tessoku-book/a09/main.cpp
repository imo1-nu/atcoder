#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w, n;
    cin >> h >> w >> n;
    vector<vector<ll>> g(h + 1, vector<ll>(w + 1, 0));
    vector<vector<ll>> s(h + 1, vector<ll>(w + 1, 0));
    for (ll i = 0; i < n; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        g[a][b]++;
        g[c + 1][b]--;
        g[a][d + 1]--;
        g[c + 1][d + 1]++;
    }

    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + g[i][j];
            cout << s[i + 1][j + 1];
            if (j < w - 1) cout << ' ';
            else cout << endl;
        }
    }
    
}
