#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// https://github.com/imo1-nu/atcoder/tree/main/lib

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int Q;
    cin >> Q;
    map<string, int> mp;
    while (Q--) {
        string s;
        cin >> s;
        if (!mp.count(s)) mp[s] = mp.size() + 1;
        cout << mp[s] << endl;
    }
}
