#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, M;
    cin >> N >> M;
    vector<ll> P(N);
    for (ll i = 0; i < N; i++) {
        cin >> P[i];
    }
    sort(P.begin(), P.end());

    ll l = 0; ll r = M + 1;
    ll ans = 0;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        ll cnt = 0;
        ll sum = 0;
        for (ll i = 0; i < N; i++) {
            ll x = (m / P[i] + 1) / 2;
            if (x == 0) break;
            cnt += x;
            if (x > M / x || x * x > M / P[i]) {
                sum = M + 1;
                break;
            }
            sum += x * x * P[i];
            if (sum > M) {
                break;
            }
        }
        if (sum <= M) {
            ll tuika = M - sum;
            for (ll i = 0; i < N; i++) {
                if ((m + 1) % P[i] == 0 && ((m + 1) / P[i]) % 2 == 1 && tuika >= m + 1) {
                    tuika -= m + 1;
                    cnt++;
                }
            }
            l = m;
            ans = max(ans, cnt);
        }
        else {
            r = m;
        }
    }
    cout << ans << endl;
}
