#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, P, Q;
    cin >> N >> P >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < i; j++) {
            for (ll k = 0; k < j; k++) {
                for (ll l = 0; l < k; l++) {
                    for (ll m = 0; m < l; m++) {
                        if ((A[i] * A[j] % P * A[k] % P * A[l] % P * A[m] % P) % P == Q) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
}
