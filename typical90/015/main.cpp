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
    
    for (int i = 0; i < N; i++) {
        mint ans = 0;
        for (int j = 1; j < (N - 1) / (i + 1) + 2; j++) {
            ans += P[N - i * (j - 1)] / (P[N - i * (j - 1) - j] * P[j]);
        }
        cout << ans.val() << endl;
    }
    
}
