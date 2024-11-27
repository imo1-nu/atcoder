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
    vector<ll> S(N - 1), X(M);
    for (ll i = 0; i < N - 1; i++) {
        cin >> S[i];
    }
    for (ll i = 0; i < M; i++) {
        cin >> X[i];
    }

    vector<ll> A(N);
    for (ll i = 1; i < N; i++) {
        A[i] = S[i - 1] - A[i - 1];
    }

    map<ll, ll> mp;
    ll k = 1;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            mp[k * (X[j] - A[i])]++;
        }
        k *= -1;
    }

    ll ans = 0;
    for (auto [k, v] : mp) {
        ans = max(ans, v);
    }
    cout << ans << endl;
}
