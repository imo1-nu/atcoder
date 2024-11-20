#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, D;
    cin >> N >> D;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<ll> dp(1ll << N, 1ll);
    for (ll i = 0; i < (1ll << N); i++) {
        ll sum = 0;
        for (ll j = 0; j < N; j++) {
            if ((i >> j) & 1) {
                sum |= A[j];
            }
        }

        for (ll j = 0; j < D; j++) {
            if (((sum >> j) & 1) == 0) {
                dp[i] *= 2;
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < (1ll << N); i++) {
        ll cnt = 0;
        for (ll j = 0; j < N; j++) {
            if ((i >> j) & 1) {
                cnt++;
            }
        }
        if (cnt % 2 == 0) {
            ans += dp[i];
        }
        else {
            ans -= dp[i];
        }
    }

    cout << ans << endl;
}
