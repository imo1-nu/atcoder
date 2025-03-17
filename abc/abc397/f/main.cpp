#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int op(int a, int b) { return max(a, b); }
int e() { return -1e9; }
int mapping(int f, int x) { return f + x; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<int> L(N), R(N);
    unordered_set<int> S;
    for (int i = 1; i < N; i++) {
        S.insert(A[i - 1]);
        L[i] = S.size();
    }
    S.clear();
    for (int i = N - 1; i > 0; i--) {
        S.insert(A[i]);
        R[i] = S.size();
    }

    atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> seg(N);
    vector<int> X(N), last(N, -1);
    seg.set(0, 0);
    for (int i = 1; i < N; i++) {
        seg.apply(last[A[i - 1]] + 1, i, 1);
        X[i] = seg.prod(0, i);
        seg.set(i, L[i]);
        last[A[i - 1]] = i - 1;
    }
    int ans = 0;
    for (int i = 1; i < N; i++) {
        ans = max(ans, X[i] + R[i]);
    }
    cout << ans << endl;
}
