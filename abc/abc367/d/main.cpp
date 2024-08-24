#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll M;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N >> M;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) cin >> A[i];
    vector<ll> S(N + 1);
    for (ll i = 1; i <= N ; i++) S[i] = (S[i - 1] + A[i - 1]) % M;

    ll ans = 0;
    vector<ll> cnt(M);
    
    for (ll i = 1; i <= N; i++) {
        ans += cnt[S[i]];
        ans += cnt[(S[i] - S[N] + M) % M];
        cnt[S[i]]++;
    }
    
    cout << ans << endl;
}
