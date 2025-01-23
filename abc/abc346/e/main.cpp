#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, M;
    cin >> H >> W >> M;
    vector<tuple<int, int, int>> Q(M);
    for (int i = 0; i < M; i++) {
        int t, a, x;
        cin >> t >> a >> x;
        Q[i] = {t, a - 1, x};
    }
    reverse(Q.begin(), Q.end());

    vector<bool> f(H), g(W);
    int hc = H, wc = W;
    vector<ll> cnt(200001);
    for (auto [t, a, x] : Q) {
        if (t == 1) {
            if (!f[a]) {
                f[a] = true;
                hc--;
                cnt[x] += wc;
            }
        } else {
            if (!g[a]) {
                g[a] = true;
                wc--;
                cnt[x] += hc;
            }
        }
    }
    cnt[0] += (ll)hc * wc;
    vector<pair<int, ll>> ans;
    for (int i = 0; i <= 200000; i++) {
        if (cnt[i] > 0) ans.push_back({i, cnt[i]});
    }
    cout << ans.size() << endl;
    for (auto [i, c] : ans) {
        cout << i << ' ' << c << endl;
    }
}
