#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int Q;
    cin >> Q;
    map<int, int> mp;
    for (int i = 0; i < Q; i++) {
        int q, x;
        cin >> q;
        if (q == 1) {
            cin >> x;
            mp[x]++;
        } else if (q == 2) {
            cin >> x;
            mp[x]--;
            if (mp[x] == 0) mp.erase(x);
        } else {
            cout << mp.size() << endl;
        }
    }
    
}
