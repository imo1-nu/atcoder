#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int X, Q;
    cin >> X >> Q;
    multiset<int> S1, S2;
    S1.insert(X);
    while (Q--) {
        int a, b;
        cin >> a >> b;
        S1.insert(a);
        S2.insert(b);

        while (*S1.rbegin() > *S2.begin()) {
            int x = *S1.rbegin();
            int y = *S2.begin();
            S1.erase(S1.find(x));
            S2.insert(x);
            S1.insert(y);
            S2.erase(S2.find(y));
        }

        // cout << "S1: ";
        // for (auto x : S1) cout << x << ' ';
        // cout << endl;

        // cout << "S2: ";
        // for (auto x : S2) cout << x << ' ';
        // cout << endl;

        cout << *S1.rbegin() << endl;
    }
}
