#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, D;
    cin >> N >> D;
    vector<int> X(N);
    for (auto& x : X) cin >> x;
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        bool ok = true;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (abs(X[i] - X[j]) < D) ok = false;
        }
        if (ok) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x + 1 << " ";
    cout << endl;
}
