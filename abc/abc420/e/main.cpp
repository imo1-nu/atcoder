#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    atcoder::dsu d(N);
    vector<int> cnt(N);
    vector<bool> isBlack(N);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if (d.same(u, v)) continue;
            int cnt1 = cnt[d.leader(u)];
            int cnt2 = cnt[d.leader(v)];
            d.merge(u, v);
            cnt[d.leader(u)] = cnt1 + cnt2;
        }
        else if (t == 2) {
            int v;
            cin >> v;
            v--;
            if (isBlack[v]) cnt[d.leader(v)]--;
            else cnt[d.leader(v)]++;
            isBlack[v] = !isBlack[v];
        }
        else {
            int v;
            cin >> v;
            v--;
            if (cnt[d.leader(v)] > 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
