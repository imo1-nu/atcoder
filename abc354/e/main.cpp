#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (ll i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<vector<bool>> canpair(N, vector<bool>(N, false));
    vector<ll> pairnum(N, 0);
    for (ll i = 0; i < N; i++) {
        for (ll j = i + 1; j < N; j++) {
            if (A[i] == A[j] || B[i] == B[j]) {
                canpair[i][j] = true;
                canpair[j][i] = true;
                pairnum[i]++;
                pairnum[j]++;
            }
        }
    }
}
