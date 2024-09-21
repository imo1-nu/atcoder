#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<ll>> idx(N);
    for (ll i = 0; i < N; i++) {
        idx[i].push_back(-1);
    }
    
    for (ll i = 0; i < N; i++) {
        idx[A[i]-1].push_back(i);
    }

    for (ll i = 0; i < N; i++) {
        idx[i].push_back(N);
    }
    
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ans += N * (N + 1) / 2;
        for (ll j = 1; j < idx[i].size(); j++) {
            ll n = idx[i][j] - idx[i][j-1] - 1;
            ans -= n * (n + 1) / 2;
        }
    }
    cout << ans << endl;
}
