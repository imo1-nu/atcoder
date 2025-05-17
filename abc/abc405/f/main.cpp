#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
    }
    
    atcoder::fenwick_tree<int> fw_A(2 * N + 1), fw_B(2 * N + 1);
    for (int i = 0; i < M; i++) {
        fw_A.add(A[i], 1);
        fw_B.add(B[i], 1);
    }

    vector<int> zero(2 * N + 1, 2 * N);
    for (int i = 2 * N - 1; i >= 0; i--) {
        if (fw_A.sum(0, i + 1) == fw_B.sum(0, i + 1)) zero[i] = i;
        else zero[i] = zero[i + 1];
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int c, d;
        cin >> c >> d;
        int ans = 0;
        if (zero[c] < d) ans += fw_B.sum(c, zero[c] + 1) - fw_A.sum(c, zero[c] + 1);
        ans += fw_B.sum(c, zero[d] + 1) - fw_A.sum(c, zero[d] + 1);
        cout << ans << endl;
    }
}
