#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> S(N + 1);
    S[0] = 0;
    for (int i = 0; i < N; ++i) {
        S[i + 1] = S[i] + A[i];
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        cout << S[r + 1] - S[l] << '\n';
    }
    
}
