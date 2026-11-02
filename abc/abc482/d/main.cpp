#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// https://github.com/imo1-nu/atcoder/tree/main/lib

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> X(N);
    for (auto& x : X) cin >> x;

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    cout << (X[N - 1] - X[0] + 1) / 2 << endl;
    for (int i = 1; i < N - 1; i++) {
        int l = max((X[i] - X[0]) / 2, (X[N - 1] - X[i - 1]) / 2);
        int r = max((X[i + 1] - X[0]) / 2, (X[N - 1] - X[i]) / 2);
        cout << min(l, r) << endl;
    }
    cout << (X[N - 1] - X[0] + 1) / 2 << endl;
}
