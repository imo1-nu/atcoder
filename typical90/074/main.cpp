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
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        A[i] = c - 'a';
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ans += A[i] * (1ll << i);
    }
    cout << ans << endl;
}
