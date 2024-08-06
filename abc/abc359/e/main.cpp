#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<ll> h(n + 1);
    h[0] = (1ll << 60);
    for (ll i = 1; i <= n; i++) {
        cin >> h[i];
    }
    
    stack<pair<ll, ll>> st;
    vector<ll> ans(n + 1);
    for (ll i = 1; i <= n; i++) {
        st.push({i - 1, h[i - 1]});
        while (!st.empty()) {
            if (st.top().second <= h[i]) st.pop();
            else break;
        }
        ans[i] = ans[st.top().first] + h[i] * (i - st.top().first);
    }
    
    for (ll i = 1; i <= n; i++) {
        if (i >= 2) cout << ' ';
        cout << ans[i] + 1;
    }
    cout << endl;
    
}
