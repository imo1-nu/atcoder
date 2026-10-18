#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    ll ans = 0;
    for (ll i = 1; i * i * i < N; i++) {
        for (int len = 3; len < 20; len++) {
            ll ok = 0, ng = 1e9;
            while (ng - ok > 1) {
                ll mid = (ok + ng) / 2;
                ll cnt = i;
                bool over = false;
                for (int j = 1; j < len; j++) {
                    if (cnt <= N / (i + j * mid)) cnt *= (i + j * mid);
                    else over = true;
                }
                if (over) ng = mid;
                else ok = mid;
            }
            if (ok == 0) break;
            ans += ok;
        }
    }
    cout << ans << endl;
}
