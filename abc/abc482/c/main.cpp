#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// https://github.com/imo1-nu/atcoder/tree/main/lib

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, N, Q;
    cin >> H >> W >> N >> Q;
    vector<int> R(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> R[i] >> C[i];
    }
    sort(R.begin(), R.end());
    sort(C.begin(), C.end());

    while (Q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            int l = lower_bound(R.begin(), R.end(), a) - R.begin();
            int r = upper_bound(R.begin(), R.end(), b) - R.begin();
            cout << r - l << endl;
        }
        else {
            int l = lower_bound(C.begin(), C.end(), a) - R.begin();
            int r = upper_bound(C.begin(), C.end(), b) - R.begin();
            cout << r - l << endl;
        }
    }
}
