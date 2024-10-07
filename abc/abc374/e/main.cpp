#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
        if (P[i] * B[i] > Q[i] * A[i]) {
            swap(A[i], B[i]);
            swap(P[i], Q[i]);
        }
    }

    ll l = 0, r = 1e9 + 1;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        ll sum = 0;
        for (ll i = 0; i < N; i++) {
            ll add = 1e9 + 1;
            for (int j = 0; j < A[i]; j++) {
                if (j * B[i] < m) add = min(add, j * Q[i] + ((m - j * B[i] - 1) / A[i] + 1) * P[i]);
                else add = min(add, j * Q[i]);
            }
            sum += add;
        }

        if (sum > X) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << l << endl;
}
