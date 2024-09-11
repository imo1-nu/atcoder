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
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    ll l = 0, r = 1;
    ll ans = N;
    while (l < N - 1) {
        ll d = A[l + 1] - A[l];
        while (r < N && A[r] - A[r - 1] == d) r++;
        ans += (r - l) * (r - l - 1) / 2;
        l = r - 1;
    }
    cout << ans << endl;
}
