#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> LR(K);
    for (int i = 0; i < K; i++) {
        cin >> LR[i].first >> LR[i].second;
        LR[i].first--;
    }

    atcoder::fenwick_tree<mint> dp(N + 1);
    dp.add(1, 1);
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < K; j++) {
            int l = max(0, i - LR[j].second);
            int r = i - LR[j].first;
            if (r <= 0) continue;
            dp.add(i, dp.sum(l, r));
        }
    }
    cout << dp.sum(N, N + 1).val() << endl;
}
