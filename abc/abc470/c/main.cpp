#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    set<int> nonzero;
    int ans = 0;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            x--;
            ans ^= A[x];
            A[x]++;
            ans ^= A[x];
            nonzero.insert(x);
        }
        else {
            vector<int> del;
            for (auto x : nonzero) {
                ans ^= A[x];
                A[x]--;
                ans ^= A[x];
                del.push_back(x);
            }
            for (auto x : del) {
                if (A[x] == 0) nonzero.erase(x);
            }
        }
        cout << ans << endl;
    }
}
