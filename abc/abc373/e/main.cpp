#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<pair<ll, int>> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i].first;
        P[i].second = i;
    }
    sort(P.begin(), P.end());
    vector<ll> S(N + 1);
    for (int i = 1; i <= N; ++i) {
        S[i] = S[i - 1] + P[i - 1].first;
    }

    if (N == M) {
        for (int i = 0; i < N; ++i) {
            cout << 0 << ' ';
        }
        cout << endl;
        return 0;
    }

    vector<ll> ans(N);
    for (int i = 0; i < N; ++i) {
        ll l = -1, r = K - S[N] + 1;
        while (l + 1 < r) {
            ll m = (l + r) / 2;
            ll bd = P[i].first + m + 1;
            int idx1 = N - M;
            if (i >= N - M) idx1--;
            int idx2 = lower_bound(P.begin(), P.end(), make_pair(bd, 0)) - P.begin();
            ll cnt = 0;
            if (idx1 < idx2) cnt += bd * (idx2 - idx1) - (S[idx2] - S[idx1]);
            if (idx1 <= i && i < idx2) cnt--;
            else cnt += m;
            if (cnt <= K - S[N]) {
                l = m;
            } else {
                r = m;
            }
        }
        if (r == K - S[N] + 1) ans[P[i].second] = -1;
        else ans[P[i].second] = r;
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
