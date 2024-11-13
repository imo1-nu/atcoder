#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll LCP(const string &s, const string &t) {
    ll n = min(s.size(), t.size());
    for (ll i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            return i;
        }
    }
    return n;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<string> S(N);
    for (ll i = 0; i < N; i++) {
        cin >> S[i];
    }

    vector<pair<string, ll>> P(N);
    for (ll i = 0; i < N; i++) {
        P[i] = {S[i], i};
    }
    sort(P.begin(), P.end());

    vector<ll> ans(N);
    for (ll i = 0; i < N - 1; i++) {
        ans[P[i].second] = max(ans[P[i].second], LCP(P[i].first, P[i + 1].first));
        ans[P[i + 1].second] = LCP(P[i].first, P[i + 1].first);
    }

    for (ll i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}
