#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;

    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        mp[p] = i;
    }

    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        mp[a] = N + i;
    }

    map<int, int> mp2;
    for (auto [k, v] : mp) {
        mp2[v] = k;
    }

    for (auto [_, v] : mp2) {
        cout << v << " ";
    }
    cout << endl;
}
