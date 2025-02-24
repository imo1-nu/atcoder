#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M, K;
    cin >> N >> M >> K;
    vector<mint> P(N + 1);
    P[0] = 1;
    mint inv = mint(M).inv();
    for (int i = 0; i < K; i++) {
        vector<mint> NP(N + 1);
        for (int x = 0; x < N; x++) {
            mint p = P[x] * inv;
            for (int dx = 1; dx <= M; dx++) {
                if (x + dx <= N) NP[x + dx] += p;
                else NP[2 * N - (x + dx)] += p;
            }
        }
        NP[N] += P[N];
        P = NP;
    }
    cout << P[N].val() << '\n';
}
