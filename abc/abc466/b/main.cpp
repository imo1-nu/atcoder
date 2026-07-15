#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int c, s;
        cin >> c >> s;
        mp[c] = max(mp[c], s);
    }
    for (int i = 1; i <= M; i++) {
        cout << (mp[i] ? mp[i] : -1) << ' ';
    }
    cout << endl;
}
