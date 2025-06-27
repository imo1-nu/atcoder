#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int op (int a, int b) {
    return max(a, b);
}
int e() {
    return -1e9;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;

    auto solve = [&]() {
        int N;
        string S;
        cin >> N >> S;
        vector<int> cnt1_l(N + 1);
        for (int i = 1; i <= N; i++) {
            cnt1_l[i] = cnt1_l[i - 1] + (S[i - 1] == '1');
        }
        vector<int> A(N + 1);
        for (int i = 0; i <= N; i++) {
            A[i] = 2 * cnt1_l[i] - i;
        }
        atcoder::segtree<int, op, e> seg(A);
        int ans = N;
        for (int l = 0; l <= N; l++) {
            int cnt = seg.prod(l, N + 1) - A[l];
            ans = min(ans, cnt1_l[N] - cnt);
        }
        cout << ans << endl;
    };

    while (T--) {
        solve();
    }
}
