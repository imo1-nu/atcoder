#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for (auto [k, v] : mp) {
        if (v % 2 == 0) continue;
        ans += k;
    }
    cout << ans << endl;
}
