#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int Q;
    cin >> Q;
    int maxA = 1000000;
    vector<int> v(maxA + 1);
    for (int i = 2; i <= maxA; i++) {
        if (v[i]) continue;
        for (int j = i; j <= maxA; j += i) {
            v[j]++;
        }
    }
    set<ll> S;
    for (ll i = 2; i <= maxA; i++) {
        if (v[i] == 2) S.insert(i * i);
    }
    while (Q--) {
        ll A;
        cin >> A;
        auto it = S.upper_bound(A);
        it--;
        cout << *it << endl;
    }
}