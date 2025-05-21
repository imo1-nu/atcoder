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
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll K10 = 1;
    for (int i = 0; i < K; i++) {
        K10 *= 10;
    }

    ll ans = 1;
    for (int i = 0; i < N; i++) {
        if (ans < (K10 + A[i] - 1) / A[i]) ans *= A[i];
        else ans = 1;
    }
    cout << ans << endl;
}
