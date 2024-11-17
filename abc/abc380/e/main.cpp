#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    map<int, int> mp;
    vector<int> cnt(N + 1);
    mp[0] = 0;
    mp[N + 1] = N + 1;
    for (int i = 1; i <= N; ++i) {
        mp[i] = i;
        cnt[i] = 1;
    }

    for (int i = 0; i < Q; ++i) {
        int t, x, c;
        cin >> t;
        if (t == 1) {
            cin >> x >> c;
            auto it = mp.upper_bound(x);
            it = prev(it);
            auto it2 = prev(it);
            auto it3 = next(it);
            cnt[it->second] -= it3->first - it->first;
            it->second = c;
            cnt[it->second] += it3->first - it->first;

            if (it3->second == c) {
                mp.erase(it3);
            }
            if (it2->second == c) {
                mp.erase(it);
            }
        }
        else {
            cin >> x;
            cout << cnt[x] << endl;
        }
    }
}
