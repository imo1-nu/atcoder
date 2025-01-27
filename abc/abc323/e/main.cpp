#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, X;
    cin >> N >> X;
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    vector<mint> P(X + 1);
    P[0] = 1;
    mint p = 1 / mint(N);
    for (int x = 1; x <= X; x++) {
        for (int t : T) {
            if (x - t >= 0) P[x] += P[x - t] * p;
        }
    }

    mint ans = 0;
    for (int x = max(0, X - T[0] + 1); x <= X; x++) {
        ans += P[x] * p;
    }
    cout << ans.val() << endl;
}
