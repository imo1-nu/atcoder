#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll Q;
    cin >> Q;
    queue<ll> que;
    ll T = 0;
    for (ll i = 0; i < Q; i++) {
        ll q, t, h;
        cin >> q;
        if (q == 1) {
            que.push(T);
        }
        else if (q == 2) {
            cin >> t;
            T += t;
        }
        else if (q == 3) {
            cin >> h;
            ll cnt = 0;
            while (T - que.front() >= h && !que.empty()) {
                que.pop();
                cnt++;
            }
            cout << cnt << endl;
        }
    }
}
