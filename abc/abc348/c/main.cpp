#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    //vector<priority_queue<ll, vector<ll>, greater<ll>>> q(1000000000);
    vector<ll> A(N);
    vector<ll> C(N);
    map<ll, ll> m;
    ll max = 1000000000;
    for (ll i = 0; i < N; i++) {
        cin >> A[i] >> C[i];
        if (m[C[i]] == 0 || A[i] < m[C[i]]) m[C[i]] = A[i];
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        if (m[C[i]] > ans) ans = m[C[i]]; 
    }

    cout << ans << endl;
}
