#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint1000000007;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(Q), Y(Q), Z(Q), W(Q);
    for (ll i = 0; i < Q; ++i) {
        cin >> X[i] >> Y[i] >> Z[i] >> W[i];
        X[i]--; Y[i]--; Z[i]--;
    }

    mint ans = 1;
    for (ll i = 0; i < 60; i++) {
        mint cnt = 0;
        vector<ll> w(Q);
        for (ll j = 0; j < Q; j++) {
            w[j] = (W[j] / (1ll << i)) % 2ll;
        }
        for (ll j = 0; j < (1ll << N); j++) {
            vector<ll> bit(N);
            for (ll k = 0; k < N; k++) {
                bit[k] = (j / (1 << k)) % 2;
            }

            bool flag = true;
            for (ll k = 0; k < Q; k++) {
                if (((bit[X[k]] | bit[Y[k]]) | bit[Z[k]]) != w[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cnt += (mint)1;
            }
        }
        ans *= cnt;
    }

    cout << ans.val() << endl;
}