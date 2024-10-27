#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll N;
ll dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
ll dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
bool canmove(ll x, ll y) {
    if (0 <= x && x < N && 0 <= y && y < N) return true;
    else return false;
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll M;
    cin >> N >> M;
    set<pair<ll, ll>> st;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        st.insert({a, b});
        for (ll j = 0; j < 8; ++j) {
            ll nx = a + dx[j];
            ll ny = b + dy[j];
            if (canmove(nx, ny)) st.insert({nx, ny});
        }
    }

    ll ans = N * N - st.size();
    cout << ans << endl;
}
