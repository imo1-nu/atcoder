#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    ll N = S.size();
    vector<vector<ll>> A(26, vector<ll>(N));
    for (ll i = 0; i < N; i++) {
        A[S[i] - 'A'][i] = 1;
    }
    vector<vector<ll>> B(26, vector<ll>(N + 1));
    for (ll i = 0; i < 26; i++) {
        for (ll j = 1; j <= N; j++) {
            B[i][j] = B[i][j - 1] + A[i][j - 1];
        }
    }
    
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        for (ll k = 0; k < 26; k++) {
            ans += B[k][i] * (B[k][N] - B[k][i + 1]);
        }
    }
    
    cout << ans << endl;
}
