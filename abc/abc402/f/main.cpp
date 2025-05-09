#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    vector<ll> pow2(2 * N);
    pow2[0] = 1;
    for (int i = 1; i < 2 * N; i++) {
        pow2[i] = pow2[i - 1] * 2 % M;
    }

    vector<vector<ll>> A(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            A[i][j] *= pow2[2 * N - i - j - 2];
            A[i][j] %= M;
        }
    }
}
