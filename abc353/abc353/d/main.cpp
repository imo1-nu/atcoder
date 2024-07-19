#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll C = 998244353;
    
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) cin >> A[i];
    vector<ll> B(N);
    for (ll i = 0; i < N; i++) {
        ll a = 10, j;
        for (j = 1; a <= A[i]; j++) {
            a *= 10;
        }
        B[i] = a;
    }



    vector<ll> D(N, 0);
    for (ll i = N - 2; i > -1; i--) {
        D[i] = (D[i + 1] + B[i + 1]) % C;
    }

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        ans = (ans + (A[i] * i) % C) % C;
        ans = (ans + (A[i] * D[i]) % C) % C;
    }

    cout << ans << endl;
}
