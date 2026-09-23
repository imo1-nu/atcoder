#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int min_op(int a, int b) {return min(a, b);}

int max_op(int a, int b) {return max(a, b);}

int min_e() {return INT_MAX;}

int max_e() {return INT_MIN;}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> P(N), P_inv(N);
    for (auto& p : P) {
        cin >> p;
        p--;
    }
    for (int i = 0; i < N; i++) P_inv[P[i]] = i;

    atcoder::segtree<int, min_op, min_e> min_seg(P);
    atcoder::segtree<int, max_op, max_e> max_seg(P);

    while (M--) {
        int l, r;
        cin >> l >> r;
        l--;
        int mn = min_seg.prod(l, r);
        int mx = max_seg.prod(l, r);
        swap(P[P_inv[mn]], P[P_inv[mx]]);
        swap(P_inv[mn], P_inv[mx]);
        min_seg.set(P_inv[mn], mn);
        min_seg.set(P_inv[mx], mx);
        max_seg.set(P_inv[mn], mn);
        max_seg.set(P_inv[mx], mx);
    }
    for (auto p : P) cout << p + 1 << ' ';
    cout << endl;
}
