#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    vector<ll> B(N);
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (ll i = 1; i < N; i++) {
        B[i] = A[i] - A[i - 1];
        ans += abs(B[i]);
    }

    for (int i = 0; i < Q; i++) {
        int L, R, V;
        cin >> L >> R >> V;
        L--; R--;
        ll before = abs(B[L]) + abs(B[R + 1]);

        if (L > 0) B[L] += V;
        if (R < N - 1) B[R + 1] -= V;
        ll after = abs(B[L]) + abs(B[R + 1]);
        
        ans += after - before;
        cout << ans << endl;
    }
}
