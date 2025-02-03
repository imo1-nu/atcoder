#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.rbegin(), A.rend());
    vector<ll> S(N + 1);
    for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i - 1];

    ll l = 1, r = 1e18 / K;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        int idx = lower_bound(A.begin(), A.end(), m, greater<ll>()) - A.begin();
        if ((K - idx) * m <= (S[N] - S[idx])) l = m;
        else r = m;
    }
    cout << l << endl;
}
