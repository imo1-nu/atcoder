#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), F(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < N; i++) {
        cin >> F[i];
    }
    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<ll>());

    ll l = -1, r = 1e18;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        ll cnt = 0;
        for (ll i = 0; i < N; i++) {
            if (A[i] * F[i] > m) {
                cnt += A[i] - m / F[i];
            }
        }
        if (cnt <= K) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << endl;
}
