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
    vector<pair<ll, ll>> B(N);
    for (ll i = 0; i < N; i++) {
        cin >> B[i].first;
    }
    for (ll i = 0; i < N; i++) {
        cin >> B[i].second;
    }
    sort(B.begin(), B.end());
    vector<ll> S(N + 1);
    for (ll i = 0; i < N; i++) {
        S[i + 1] = S[i] + B[i].second;
    }
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        A[i] = B[i].first;
    }

    ll Q;
    cin >> Q;
    for (ll i = 0; i < Q; i++) {
        ll L, R;
        cin >> L >> R;
        ll l = lower_bound(A.begin(), A.end(), L) - A.begin();
        ll r = upper_bound(A.begin(), A.end(), R) - A.begin();
        cout << S[r] - S[l] << endl;
    }
    
}
