#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<map<int, int>> diff(N + 1);
    while (Q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        diff[l][x]++;
        diff[r][x]--;
    }

    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        for (auto [k, v] : diff[i]) {
            mp[k] += v;
            if (mp[k] == 0) mp.erase(k);
        }
        cout << mp.size() << ' ';
    }
    cout << endl;
}
