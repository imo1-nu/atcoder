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
    vector<pair<ll, ll>> P(M);
    vector<ll> S(M + 1);
    for (ll i = 0; i < M; i++) {
        cin >> P[i].first;
    }
    for (ll i = 0; i < M; i++) {
        cin >> P[i].second;
    }

    sort(P.begin(), P.end());
    for (ll i = 1; i <= M; i++) {
        if (S[i - 1] < P[i - 1].first - 1) {
            cout << -1 << endl;
            return 0;
        }
        S[i] = S[i - 1] + P[i - 1].second;
    }

    if (S[M] != N) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = N * (N + 1) / 2;
    for (ll i = 0; i < M; i++) {
        ans -= P[i].first * P[i].second;
    }
    cout << ans << endl;
}
