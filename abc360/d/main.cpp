#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<ll> x(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<pair<ll, char>> ants(n);
    for (ll i = 0; i < n; i++) {
        ants[i].first = x[i];
        ants[i].second = s[i];
    }
    sort(ants.begin(), ants.end());
    
    vector<ll> gyaku;
    for (int i = 0; i < n; i++) {
        if (ants[i].second == '0') {
            gyaku.push_back(ants[i].first);
        }
    }
    ll gsize = gyaku.size();
    ll ans = 0;
    ll l = 0, r = 0;
    for (ll i = 0; i < n; i++) {
        if (ants[i].second == '0') continue;
        while (gyaku[l] < ants[i].first && l < gsize) l++;
        while (gyaku[r] <= ants[i].first + 2 * t && r < gsize) r++;
        ans += r - l;
        //cout << i << ' ' << r - l << endl;
    }
    cout << ans << endl;
}
