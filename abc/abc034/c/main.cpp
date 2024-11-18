#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint1000000007;

mint w, h, P[200001];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int W, H;
    cin >> W >> H;
    w = W;
    h = H;
    P[0] = 1;
    for (int i = 1; i <= W + H - 2; ++i) {
        P[i] = P[i - 1] * i;
    }

    mint ans = P[W + H - 2] / (P[W - 1] * P[H - 1]);
    cout << ans.val() << endl;
}
