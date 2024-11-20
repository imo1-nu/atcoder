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
    vector<ll> X(N), Y(N);
    for (ll i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    ll Xmid = X[N / 2], Ymid = Y[N / 2];
    ll ans = 0;
    for (ll i = 0; i < N; ++i) {
        ans += abs(X[i] - Xmid) + abs(Y[i] - Ymid);
    }
    cout << ans << endl;
}
