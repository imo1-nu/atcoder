#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> pos(N);
    iota(pos.begin(), pos.end(), 0);
    vector<int> cnt(N, 1);

    int ans = 0;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int P, H;
            cin >> P >> H;
            P--; H--;
            int p = pos[P];
            if (--cnt[p] == 1) ans--;
            pos[P] = H;
            if (++cnt[H] == 2) ans++;
        }
        else cout << ans << endl;
    }
}
