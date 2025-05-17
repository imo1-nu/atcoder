#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    cout << "? " << 1 << ' ' << N << endl;
    int x;
    cin >> x;
    int len = N - x;
    int L = 1, R = N;
    int ng = len, ok = N;
    while (ng + 1 < ok) {
        int mid = (ng + ok) / 2;
        cout << "? " << L << ' ' << mid << endl;
        int x;
        cin >> x;
        if (x < mid - L) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    R = ok;
    L = R - len;
    cout << "! " << L << ' ' << R << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
