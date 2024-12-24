#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll RandInt(ll L, ll R) { // [L, R]
    return L + rand() % (R - L + 1);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    ll mod = (1ll << 61) - 1;
    vector<int> hash(N + 1);
    for (int i = 1; i <= N; ++i) {
        hash[i] = RandInt(1, mod - 1);
    }

    vector<ll> cumA(N + 1), cumB(N + 1);
    for (int i = 1; i <= N; ++i) {
        cumA[i] = (cumA[i - 1] + hash[A[i - 1]]) % mod;
        cumB[i] = (cumB[i - 1] + hash[B[i - 1]]) % mod;
    }

    while (Q--) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        if (cumA[r] - cumA[l - 1] == cumB[R] - cumB[L - 1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
