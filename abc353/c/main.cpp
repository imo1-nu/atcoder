#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll C = 100000000;
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) cin >> A[i];
    ll ans = 0;
    sort(A.begin(), A.end());
    for (ll i = 0; i < N; i++) {
        ans += A[i] * (N - 1);

        ll l = i, r = N;
        while (l + 1 < r) {
            ll mid = (l + r) / 2;
            if (A[i] + A[mid] < C) l = mid;
            else r = mid;
        }
        ans -=  (N - r) * C;
    }

    cout << ans << endl;
}
