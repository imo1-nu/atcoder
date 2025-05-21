#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int op(int a, int b) {
    return a + b;
}
int e() {
    return 0;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), P(N * 2, -1);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        P[A[i]] = i;
        P[B[i]] = i;
    }
    atcoder::segtree<int, op, e> seg(N * 2);
    int Q;
    cin >> Q;
    vector<int> C(Q), D(Q);
    vector<vector<int>> G(N * 2);
    for (int i = 0; i < Q; i++) {
        cin >> C[i] >> D[i];
        C[i]--;
        D[i]--;
        G[D[i]].emplace_back(i);
    }

    vector<int> ans(Q);
    for (int i = 0; i < N * 2; i++) {
        if (P[i] != -1) {
            seg.set(i, 1);
            if (B[P[i]] == i) seg.set(A[P[i]], -1);
        }
        for (auto x : G[i]) ans[x] = seg.prod(C[x], D[x] + 1);
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }
}
