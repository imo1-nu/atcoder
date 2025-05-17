#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<mint> P(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        P[i] = P[i - 1] * i;
    }
    
    for (int K = 1; K <= N; K++) {
        mint ans = 0;
        for (int r = 1; r <= (N + K - 1) / K; r++) {
            ans += P[N - (K - 1) * (r - 1)] / (P[N - (K - 1) * (r - 1) - r] * P[r]);
        }
        cout << ans.val() << endl;
    }
}
